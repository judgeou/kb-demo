// Original FR08 function at 004013e6

void fr08_4013e6(void)

{
  int *piVar1;
  int **ppiVar2;
  
  if (DAT_0049303c != (int *)0x0) {
    (**(code **)(*DAT_0049303c + 0x7c))(DAT_0049303c,DAT_00493038,DAT_004cc270);
    (**(code **)(*DAT_00493038 + 8))(DAT_00493038);
    (**(code **)(*DAT_004cc270 + 8))(DAT_004cc270);
    ppiVar2 = (int **)&DAT_004cc684;
    do {
      piVar1 = *ppiVar2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      *ppiVar2 = (int *)0x0;
      ppiVar2 = ppiVar2 + 1;
    } while ((int)ppiVar2 < 0x4cca44);
    ppiVar2 = (int **)&DAT_0045ac18;
    do {
      piVar1 = *ppiVar2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      *ppiVar2 = (int *)0x0;
      ppiVar2 = ppiVar2 + 4;
    } while ((int)ppiVar2 < 0x45b018);
    ppiVar2 = (int **)&DAT_004cbe60;
    do {
      piVar1 = *ppiVar2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      *ppiVar2 = (int *)0x0;
      ppiVar2 = ppiVar2 + 1;
    } while ((int)ppiVar2 < 0x4cbe6c);
    if (DAT_004cbe58 != (int *)0x0) {
      (**(code **)(*DAT_004cbe58 + 8))(DAT_004cbe58);
    }
    DAT_004cbe58 = (int *)0x0;
    if (DAT_0049303c != (int *)0x0) {
      (**(code **)(*DAT_0049303c + 8))(DAT_0049303c);
    }
    DAT_0049303c = (int *)0x0;
    if (DAT_00493030 != (int *)0x0) {
      (**(code **)(*DAT_00493030 + 8))(DAT_00493030);
    }
    DAT_00493030 = (int *)0x0;
  }
  return;
}

