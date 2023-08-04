
// LVN replaced 0 arithmetic instructions
#include "../../classir.h"
void test2(float &f0,float &f1){
virtual_reg vr0;
virtual_reg vr1;
virtual_reg vr2;
virtual_reg vr3;
virtual_reg vr4;
virtual_reg vr5;
virtual_reg _new_name0;
virtual_reg _new_name1;
virtual_reg vr1_2;
virtual_reg vr5_9;
virtual_reg vr2_4;
virtual_reg vr0_1;
virtual_reg vr4_7;
virtual_reg vr3_5;
virtual_reg _new_name1_6;
virtual_reg _new_name0_3;
virtual_reg _new_name0_8;
vr5_9 = vr5;
vr4_7 = vr4;
_new_name1_6 = _new_name1;
_new_name0_3 = _new_name0;
vr3_5 = vr3;
vr2_4 = vr2;
vr1_2 = vr1;
vr0_1 = vr0;
vr0_1 = float2vr(f0);
vr1_2 = vr_float2int(vr0_1);
_new_name0_3 = vr1_2;
vr2_4 = float2vr(f1);
vr3_5 = vr_float2int(vr2_4);
_new_name1_6 = vr3_5;
vr4_7 = addi(_new_name0_3,_new_name1_6);
_new_name0_8 = vr4_7;
vr5_9 = vr_int2float(_new_name0_8);
f0 = vr2float(vr5_9);
vr0 = vr0_1;
vr1 = vr1_2;
_new_name0 = _new_name0_8;
vr2 = vr2_4;
vr3 = vr3_5;
_new_name1 = _new_name1_6;
vr4 = vr4_7;
vr5 = vr5_9;
return;
}
        
