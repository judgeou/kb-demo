// Original FR08 function at 00402b54

void fr08_402b54(int param_1)

{
  int iVar1;
  
  while( true ) {
    if (*(int *)(param_1 + 0x10) != 0) {
      return;
    }
    fr08_402b0e(param_1);
    if ((*(byte *)(param_1 + 0x14) & 3) != 0) break;
    iVar1 = *(int *)(param_1 + 4);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) == 0)) {
      fr08_402b54(iVar1);
    }
    param_1 = *(int *)(param_1 + 8);
    if (param_1 == 0) {
      return;
    }
  }
  return;
}

