
// LVN replaced 0 arithmetic instructions
#include "../../classir.h"
void test4(float &x){
virtual_reg vr0;
virtual_reg vr1;
virtual_reg vr2;
virtual_reg vr3;
virtual_reg vr4;
virtual_reg vr5;
virtual_reg vr6;
virtual_reg vr7;
virtual_reg vr8;
virtual_reg _new_name0;
virtual_reg vr1_3;
virtual_reg vr5_7;
virtual_reg vr6_8;
virtual_reg vr8_6;
virtual_reg vr7_10;
virtual_reg _new_name0_13;
virtual_reg _new_name0_5;
virtual_reg vr0_1;
virtual_reg vr3_11;
virtual_reg vr2_4;
virtual_reg vr4_12;
virtual_reg _new_name0_2;
virtual_reg _new_name0_9;
vr0_1 = vr0;
vr0_1 = int2vr(0);
_new_name0_2 = vr0_1;
vr0 = vr0_1;
_new_name0 = _new_name0_2;
label0:
vr1_3 = vr1;
_new_name0_5 = _new_name0;
vr1_3 = int2vr(1024);
vr2_4 = lti(_new_name0_5,vr1_3);
vr8_6 = int2vr(0);
vr1 = vr1_3;
vr2 = vr2_4;
vr8 = vr8_6;
beq(vr2,vr8,label1);
vr4_12 = vr4;
vr3_11 = vr3;
vr7_10 = vr7;
vr6_8 = vr6;
vr5_7 = vr5;
_new_name0_9 = _new_name0;
vr5_7 = float2vr(x);
vr6_8 = vr_int2float(_new_name0_9);
vr7_10 = addf(vr5_7,vr6_8);
x = vr2float(vr7_10);
vr3_11 = int2vr(1);
vr4_12 = addi(_new_name0_9,vr3_11);
_new_name0_13 = vr4_12;
vr5 = vr5_7;
vr6 = vr6_8;
vr7 = vr7_10;
vr3 = vr3_11;
vr4 = vr4_12;
_new_name0 = _new_name0_13;
branch(label0);
label1:
return;
}
        
