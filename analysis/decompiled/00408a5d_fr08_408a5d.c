// Original FR08 function at 00408a5d

void fr08_408a5d(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined local_5c [88];
  
  iVar2 = 0;
  if (0 < DAT_00591ee4) {
    piVar3 = &DAT_00591ef0;
    do {
      iVar1 = *piVar3;
      if ((*(int *)(iVar1 + 0x20) == 3) && (*(int *)(iVar1 + 0x24) != 0)) {
        fr08_40100b();
        fr08_407eb1(*(undefined4 *)(iVar1 + 0x24),local_5c);
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < DAT_00591ee4);
  }
  return;
}

