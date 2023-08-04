import re
import itertools

# perform the local value numbering optimization
def LVN(program):    
    # returns 3 items:

    
    basic_blocks = []
    bb = []
    for instr in program:
        if re.match("beq|bneq|branch", instr) is not None:
            bb.append(instr)
            if bb != []:
                basic_blocks.append(bb)
            bb = []
        elif re.match("label", instr) is not None:
            if bb != []:
                basic_blocks.append(bb)
            bb = []
            bb.append(instr)
        else:
            bb.append(instr)
    basic_blocks.append(bb)

    
    # RE MATCHING STRINGS
    # two ops
    two_op_full_re = "(\S+)=(\S+)\((\S+),(\S+)\)"

    # newname = vr
    nn_eq_vr_full_re = "((_new_name)(\S+))=(vr(\S+));"
    
    # int2vr or float2vr
    if_2vr_full_re = "(\S+)=(int2vr\(|float2vr\()(\S+)(\))"

    # vr_int2float or vr_float2int
    vr_i2ff2i_full_re = "(\S+)=(vr_int2float\(|vr_float2int\()(\S+)(\))"

    # vr2int or vr2float
    vr_2if_full_re = "(\S+)=(vr2float\(|vr2int\()(\S+)(\))"


    # ARRAY RESOURCES
    numbered_blocks = []
    new_required_vrs = []
    global_counter = 1

    def number_block(block):
        new_block = []
        block_dict = dict()
        block_rhs = dict()
        block_lhs = dict()


        def number_lhs(vr):
            nonlocal global_counter

            if vr not in block_dict:
                block_dict[vr] = []
                block_dict[vr].append(global_counter)
            else:
                block_dict[vr].append(global_counter)

            block_lhs[vr] = global_counter

            global_counter += 1 

            ret = vr + "_" + str(block_dict.get(vr)[-1])
            new_required_vrs.append(ret) 

            return ret
            

        def number_rhs(vr):
            nonlocal global_counter

            if vr not in block_dict:
                block_dict[vr] = [] 
                block_dict[vr].append(global_counter)

                global_counter += 1
            
            block_rhs[vr] = block_dict[vr][0]
            ret = vr + "_" + str(block_dict.get(vr)[-1])
            new_required_vrs.append(ret)

            return ret

        for instr in block: 
            instr = instr.replace(" ", "")
            
            two_op_match = re.match(two_op_full_re, instr)

            nn_eq_vr_match = re.match(nn_eq_vr_full_re, instr)
            
            if_2vr_match = re.match(if_2vr_full_re, instr)

            vr_i2ff2i_match = re.match(vr_i2ff2i_full_re, instr)
            
            vr_2if_match = re.match(vr_2if_full_re, instr)

            if two_op_match is not None:
                dest = number_lhs(two_op_match[1])
                op = two_op_match[2]
                r1 = number_rhs(two_op_match[3])
                r2 = number_rhs(two_op_match[4])

                new_instr = dest + " = " + op + "(" + r1 + "," + r2 + ");"
                new_block.append(new_instr)

            elif nn_eq_vr_match is not None:
                dest = number_lhs(nn_eq_vr_match[1])
                r1 = number_rhs(nn_eq_vr_match[4])

                new_instr =  dest + " = " + r1 + ";"
                new_block.append(new_instr)

            elif if_2vr_match is not None:
                dest = number_lhs(if_2vr_match[1])
                op = if_2vr_match[2]
                val = if_2vr_match[3]

                new_instr = dest + " = " + op + val + ");"
                new_block.append(new_instr)

            elif vr_i2ff2i_match is not None:
                dest = number_lhs(vr_i2ff2i_match[1])
                op = vr_i2ff2i_match[2]
                vr = number_rhs(vr_i2ff2i_match[3])

                new_instr = dest + " = " + op + vr + ");"
                new_block.append(new_instr)

            elif vr_2if_match is not None:
                x = vr_2if_match[1]
                op = vr_2if_match[2]
                r1 = number_rhs(vr_2if_match[3])

                new_instr = x + " = " + op + r1 + ");"
                new_block.append(new_instr)

            else:
                new_block.append(instr)

        starts_w_label = re.match("label", block[0]) is not None
        ends_w_branch = re.match("(beq|bneq|branch)", block[-1]) is not None


        for vr in block_rhs:
            start_patch_instr = vr + "_" + str(block_rhs.get(vr)) + " = " + vr + ";"
            if starts_w_label:
                label = new_block[0]
                new_block[0] = start_patch_instr
                new_block.insert(0, label)
            else:
                new_block.insert(0, start_patch_instr)
        for vr in block_lhs:
            end_patch_instr = vr + " = " + vr + "_" + str(block_lhs.get(vr)) + ";"
            if ends_w_branch:
                branch = new_block[-1]
                new_block[-1] = end_patch_instr
                new_block.append(branch)
            else:
                new_block.append(end_patch_instr)

        return new_block

    # NUMBERING AND PATCHING
    for block in basic_blocks:
        new_block = number_block(block)
        numbered_blocks.append(new_block)

    # print(new_required_vrs)
    # for x in numbered_blocks:
    #     print(x)
        
    numbered_program = list(itertools.chain.from_iterable(numbered_blocks))

    # OPTIMIZATION
    replaced_instr_count = 0

    replaced_instr_count, numbered_program = replace_instrs(numbered_program)
    

    # 1. a new program (list of classier instructions)
    # with the LVN optimization applied

    # 2. a list of new variables required (e.g. numbered virtual
    # registers and program variables)

    # 3. a number with how many instructions were replaced    
    return numbered_program,list(set(new_required_vrs)),replaced_instr_count


def replace_instrs(numbered_program):
    lvo_dict = {}
    replaced_instr_count = 0
    new_program = []
    two_op_full_re = "(\S+) = (\S+)\((\S+),(\S+)\)"
    
    for instr in numbered_program:
        if re.match(two_op_full_re, instr) is not None:
            lhs_end_index = instr.index('=')
            lhs = instr[:lhs_end_index].strip()
            rhs = instr[lhs_end_index + 1:-1].strip()
            
            if rhs in lvo_dict:
                instr = lhs + " = " + lvo_dict[rhs] + ";"
                # print("REPLACE")
                replaced_instr_count += 1
            else:
                lvo_dict[rhs] = lhs
            
            new_program.append(instr)
        else:
            new_program.append(instr)
    
    return replaced_instr_count, new_program




