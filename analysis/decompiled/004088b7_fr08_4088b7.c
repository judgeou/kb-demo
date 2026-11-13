// Original FR08 function at 004088b7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_4088b7(void)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_0052a454) {
    iVar2 = 0;
    do {
      puVar1 = (ushort *)(iVar2 + 2 + DAT_0052a450);
      *puVar1 = *puVar1 & 0x3fff;
      *(undefined *)(iVar2 + DAT_0052a450) = 0;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x10;
    } while (iVar3 < DAT_0052a454);
  }
  fr08_4085ec();
  fr08_402b89();
  fr08_409b10();
  do {
    iVar3 = Original_DemoTimeMilliseconds();
  } while (iVar3 < 0);
  _DAT_00591eec = 0;
  return;
}

