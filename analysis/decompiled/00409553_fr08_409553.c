// Original FR08 function at 00409553

void fr08_409553(uint param_1,uint *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 < param_4) {
    iVar1 = fr08_409585(param_3,param_4);
    uVar2 = iVar1 + DAT_005923b4;
    *param_2 = uVar2;
    if (uVar2 < DAT_005923b8) {
      DAT_005923b8 = uVar2;
    }
  }
  return;
}

