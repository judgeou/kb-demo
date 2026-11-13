// Original FR08 function at 00408aa8

void fr08_408aa8(int param_1)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  
  iVar6 = 0;
  if (0 < DAT_0052a454) {
    pcVar5 = (char *)(DAT_0052a450 + 1);
    iVar3 = DAT_0052a454;
    do {
      if (*pcVar5 == '1') {
        iVar6 = iVar6 + 1;
      }
      pcVar5 = pcVar5 + 0x10;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  uVar4 = fr08_409bc5();
  fr08_409ffe(uVar4);
  iVar6 = fr08_409fa2(iVar6);
  iVar3 = 0;
  if (0 < DAT_0052a454) {
    pcVar5 = (char *)(DAT_0052a450 + 1);
    do {
      if (*pcVar5 == '1') {
        iVar6 = iVar6 + -1;
      }
      if (iVar6 == -1) {
        puVar1 = (undefined2 *)(iVar3 * 0x10 + 2 + DAT_0052a450);
        uVar2 = *puVar1;
        *puVar1 = *(undefined2 *)(param_1 + 2);
        *(undefined *)(param_1 + 1) = 0;
        *(undefined2 *)(param_1 + 2) = uVar2;
        return;
      }
      iVar3 = iVar3 + 1;
      pcVar5 = pcVar5 + 0x10;
    } while (iVar3 < DAT_0052a454);
  }
  return;
}

