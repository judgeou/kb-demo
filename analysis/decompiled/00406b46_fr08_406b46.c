// Original FR08 function at 00406b46

void fr08_406b46(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = param_2;
  param_2 = (undefined4 *)0x100;
  do {
    iVar4 = 0x100;
    puVar2 = puVar3;
    do {
      uVar1 = *puVar2;
      puVar2 = puVar2 + 0x100;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    puVar3 = puVar3 + 1;
    param_2 = (undefined4 *)((int)param_2 + -1);
  } while (param_2 != (undefined4 *)0x0);
  return;
}

