
// LVN replaced 0 arithmetic instructions
#include "../../classir.h"
void test1(int &x){
virtual_reg vr0;
virtual_reg vr1;
virtual_reg vr2;
virtual_reg vr3;
virtual_reg vr4;
virtual_reg vr5;
virtual_reg vr6;
virtual_reg vr7;
virtual_reg vr8;

virtual_reg vr4_5;
virtual_reg vr8_9;
virtual_reg vr6_7;
virtual_reg vr5_6;
virtual_reg vr0_1;
virtual_reg vr1_2;
virtual_reg vr2_3;
virtual_reg vr3_4;
virtual_reg vr7_8;
vr8_9 = vr8;
vr7_8 = vr7;
vr0_1 = vr0;
vr6_7 = vr6;
vr5_6 = vr5;
vr4_5 = vr4;
vr3_4 = vr3;
vr2_3 = vr2;
vr1_2 = vr1;
vr0_1 = int2vr(100);
vr1_2 = int2vr(1);
vr2_3 = int2vr(1);
vr3_4 = addi(vr1_2,vr2_3);
vr4_5 = int2vr(5);
vr5_6 = multi(vr3_4,vr4_5);
vr6_7 = int2vr(10);
vr7_8 = divi(vr5_6,vr6_7);
vr8_9 = addi(vr0_1,vr7_8);
x = vr2int(vr8_9);
vr0 = vr0_1;
vr1 = vr1_2;
vr2 = vr2_3;
vr3 = vr3_4;
vr4 = vr4_5;
vr5 = vr5_6;
vr6 = vr6_7;
vr7 = vr7_8;
vr8 = vr8_9;
return;
}
        
