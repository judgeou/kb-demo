// Original FR08 function at 004098cb

void fr08_4098cb(uint param_1,int *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  if (param_1 < param_4) {
    iVar1 = fr08_409585(param_3,param_4);
    *param_2 = iVar1 + DAT_005923b4;
  }
  return;
}

