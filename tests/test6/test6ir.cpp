
// LVN replaced 1 arithmetic instructions
#include "../../classir.h"
void test6(int &x,int &y){
virtual_reg vr0;
virtual_reg vr1;
virtual_reg vr2;
virtual_reg vr3;
virtual_reg _new_name0;
virtual_reg _new_name1;
virtual_reg vr2_5;
virtual_reg vr3_6;
virtual_reg _new_name1_2;
virtual_reg vr1_3;
virtual_reg _new_name0_4;
virtual_reg vr0_1;
vr3_6 = vr3;
vr2_5 = vr2;
_new_name1_2 = _new_name1;
_new_name0_4 = _new_name0;
vr1_3 = vr1;
vr0_1 = vr0;
vr0_1 = int2vr(10);
_new_name1_2 = vr0_1;
vr1_3 = int2vr(10);
_new_name0_4 = vr1_3;
vr2_5 = addi(_new_name0_4,_new_name1_2);
x = vr2int(vr2_5);
vr3_6 = vr2_5;
y = vr2int(vr3_6);
vr0 = vr0_1;
_new_name1 = _new_name1_2;
vr1 = vr1_3;
_new_name0 = _new_name0_4;
vr2 = vr2_5;
vr3 = vr3_6;
return;
}
        
