// Original FR08 function at 00407e7d

void fr08_407e7d(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0x58) != 0) {
    fr08_407605(*(int *)(param_1 + 0x58));
  }
  if (0 < *(int *)(param_1 + 100)) {
    puVar2 = (undefined4 *)(param_1 + 0x68);
    do {
      fr08_407e7d(*puVar2);
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < *(int *)(param_1 + 100));
  }
  return;
}

