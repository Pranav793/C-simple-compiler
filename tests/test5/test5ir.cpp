
// LVN replaced 0 arithmetic instructions
#include "../../classir.h"
void test5(int &x,int &y){
virtual_reg vr0;
virtual_reg vr1;
virtual_reg _new_name0;
virtual_reg _new_name1;
virtual_reg _new_name0_2;
virtual_reg vr0_1;
virtual_reg vr1_3;
virtual_reg _new_name1_4;
_new_name0_2 = _new_name0;
_new_name1_4 = _new_name1;
vr1_3 = vr1;
vr0_1 = vr0;
vr0_1 = int2vr(5);
_new_name0_2 = vr0_1;
vr1_3 = int2vr(6);
_new_name1_4 = vr1_3;
x = vr2int(_new_name1_4);
y = vr2int(_new_name0_2);
vr0 = vr0_1;
_new_name0 = _new_name0_2;
vr1 = vr1_3;
_new_name1 = _new_name1_4;
return;
}
        
