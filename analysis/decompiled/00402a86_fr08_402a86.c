// Original FR08 function at 00402a86

void fr08_402a86(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00529354;
  do {
    iVar1 = puVar2[-1];
    if (iVar1 != 0) {
      fr08_402a30(iVar1,1);
      *puVar2 = *(undefined4 *)(iVar1 + 0x20);
      puVar2[1] = *(undefined4 *)(iVar1 + 0x24);
    }
    puVar2 = puVar2 + 4;
  } while ((int)puVar2 < 0x52a354);
  return;
}

