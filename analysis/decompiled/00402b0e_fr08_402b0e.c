// Original FR08 function at 00402b0e

void fr08_402b0e(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if ((*(int *)(param_1 + 0x10) == 0) && (*(undefined4 *)(param_1 + 0x10) = 1, 0 < DAT_005282ec)) {
    piVar2 = &DAT_0052b460;
    do {
      if ((piVar2[-1] == param_1) || (*piVar2 == param_1)) {
        fr08_402b54(piVar2 + -2);
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0xb;
    } while (iVar1 < DAT_005282ec);
  }
  return;
}

