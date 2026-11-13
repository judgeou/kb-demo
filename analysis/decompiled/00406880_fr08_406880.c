// Original FR08 function at 00406880

void fr08_406880(undefined4 *param_1,undefined4 *param_2,int param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_5 & 0x30) == 0x20) {
    puVar3 = param_2 + (param_3 - param_4);
    for (iVar2 = param_4; puVar4 = param_2, iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = *puVar3;
      puVar3 = puVar3 + 1;
      param_1 = param_1 + 1;
    }
    for (; param_3 != 0; param_3 = param_3 + -1) {
      *param_1 = *puVar4;
      puVar4 = puVar4 + 1;
      param_1 = param_1 + 1;
    }
    for (; param_4 != 0; param_4 = param_4 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  else {
    iVar2 = param_4;
    if ((param_5 & 0x30) == 0x10) {
      uVar1 = *param_2;
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        *param_1 = uVar1;
        param_1 = param_1 + 1;
      }
      while (param_3 = param_3 + -1, param_3 != 0) {
        *param_1 = *param_2;
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
      }
      for (; param_4 != 0; param_4 = param_4 + -1) {
        *param_1 = uVar1;
        param_1 = param_1 + 1;
      }
      *param_1 = uVar1;
    }
    else {
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        *param_1 = 0;
        param_1 = param_1 + 1;
      }
      for (; param_3 != 0; param_3 = param_3 + -1) {
        *param_1 = *param_2;
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
      }
      for (; param_4 != 0; param_4 = param_4 + -1) {
        *param_1 = 0;
        param_1 = param_1 + 1;
      }
    }
  }
  return;
}

