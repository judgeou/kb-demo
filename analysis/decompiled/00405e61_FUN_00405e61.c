// Original FR08 function at 00405e61

void FUN_00405e61(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1[4] != 0) {
    param_1[4] = 0;
    fr08_409e00(1);
    puVar3 = (undefined4 *)param_1[9];
    uVar1 = fr08_405e3b(*param_1);
    for (iVar2 = 0x40000; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}

