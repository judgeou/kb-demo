// Original FR08 function at 00402b89

void fr08_402b89(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 1;
  if (1 < DAT_005272e8) {
    puVar2 = &DAT_0052a474;
    do {
      iVar1 = puVar2[-3];
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) != 0)) {
        (**(code **)(iVar1 + 0x18))(iVar1);
      }
      *puVar2 = 0;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 4;
    } while (iVar3 < DAT_005272e8);
  }
  return;
}

