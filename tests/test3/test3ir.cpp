
// LVN replaced 0 arithmetic instructions
#include "../../classir.h"
void test2(int &x,int &y){
virtual_reg vr0;
virtual_reg vr1;
virtual_reg vr2;
virtual_reg vr3;
virtual_reg vr4;
virtual_reg vr5;
virtual_reg vr6;

virtual_reg vr6_7;
virtual_reg vr3_4;
virtual_reg vr2_3;
virtual_reg vr4_5;
virtual_reg vr0_1;
virtual_reg vr1_2;
virtual_reg vr5_6;
vr0_1 = int2vr(1);
vr1_2 = int2vr(0);
vr0 = vr0_1;
vr1 = vr1_2;
beq(vr0,vr1,label0);
vr3_4 = vr3;
vr2_3 = vr2;
vr2_3 = int2vr(1);
x = vr2int(vr2_3);
vr3_4 = int2vr(1);
y = vr2int(vr3_4);
vr2 = vr2_3;
vr3 = vr3_4;
branch(label1);
label0:
vr6_7 = vr6;
vr5_6 = vr5;
vr4_5 = vr4;
vr4_5 = int2vr(5);
x = vr2int(vr4_5);
vr5_6 = float2vr(5.0);
vr6_7 = vr_float2int(vr5_6);
y = vr2int(vr6_7);
vr4 = vr4_5;
vr5 = vr5_6;
vr6 = vr6_7;
label1:
return;
}
        
