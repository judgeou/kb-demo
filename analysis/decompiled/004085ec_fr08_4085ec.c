// Original FR08 function at 004085ec

void fr08_4085ec(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (-1 < DAT_0052a454 + -1) {
    iVar3 = (DAT_0052a454 + -1) * 0x10;
    iVar1 = DAT_0052a454;
    do {
      for (puVar2 = *(undefined4 **)
                     (&DAT_005282f4 + (uint)*(ushort *)(iVar3 + 2 + DAT_0052a450) * 4);
          puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
        fr08_40889f(puVar2,*(undefined4 *)(puVar2[3] + 4));
      }
      iVar3 = iVar3 + -0x10;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

