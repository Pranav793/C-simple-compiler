
// LVN replaced 0 arithmetic instructions
#include "../../classir.h"
void test0(int &a){
virtual_reg vr0;
virtual_reg vr1;
virtual_reg vr2;

virtual_reg vr1_2;
virtual_reg vr2_3;
virtual_reg vr0_1;
vr2_3 = vr2;
vr1_2 = vr1;
vr0_1 = vr0;
vr0_1 = int2vr(a);
vr1_2 = int2vr(1);
vr2_3 = addi(vr0_1,vr1_2);
a = vr2int(vr2_3);
vr0 = vr0_1;
vr1 = vr1_2;
vr2 = vr2_3;
return;
}
        
