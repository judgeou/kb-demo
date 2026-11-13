// Original FR08 function at 00402073

undefined4 * fr08_402073(int *param_1,int param_2,char param_3)

{
  int iVar1;
  int **ppiVar2;
  int iVar3;
  
  iVar3 = DAT_0045ac10 * 0x38;
  DAT_0045ac10 = DAT_0045ac10 + 1;
  ppiVar2 = (int **)&DAT_0045ac38;
  if (param_3 == '\0') {
    ppiVar2 = (int **)&DAT_0045ac18;
  }
  if (((int)ppiVar2[1] + (int)param_1 < (int)ppiVar2[2]) && (DAT_0045ac2c + param_2 < DAT_0045ac30))
  {
    *(int **)(&DAT_0045b02c + iVar3) = ppiVar2[1];
    *(int *)(&DAT_0045b038 + iVar3) = DAT_0045ac2c;
    iVar1 = (**(code **)(**ppiVar2 + 0x2c))
                      (*ppiVar2,*(int *)(&DAT_0045b02c + iVar3) * 0x24,(int)param_1 * 0x24,
                       iVar3 + 0x45b058,0x1000);
    if (iVar1 < 0) {
      fr08_401000();
    }
    iVar1 = (**(code **)(*DAT_0045ac28 + 0x2c))
                      (DAT_0045ac28,*(int *)(&DAT_0045b038 + iVar3) << 1,param_2 * 2,
                       iVar3 + 0x45b05c,0x1000);
    if (iVar1 < 0) {
      fr08_401000();
    }
    ppiVar2[1] = (int *)((int)ppiVar2[1] + (int)param_1);
    DAT_0045ac2c = DAT_0045ac2c + param_2;
  }
  else {
    *(undefined4 *)(&DAT_0045b02c + iVar3) = 0;
    *(undefined4 *)(&DAT_0045b038 + iVar3) = 0;
    iVar1 = (**(code **)(**ppiVar2 + 0x2c))(*ppiVar2,0,(int)param_1 * 0x24,iVar3 + 0x45b058,0x2000);
    if (iVar1 < 0) {
      fr08_401000();
    }
    iVar1 = (**(code **)(*DAT_0045ac28 + 0x2c))(DAT_0045ac28,0,param_2 * 2,iVar3 + 0x45b05c,0x2000);
    if (iVar1 < 0) {
      fr08_401000();
    }
    DAT_004cbe5c = DAT_004cbe5c + 1;
    ppiVar2[1] = param_1;
    DAT_0045ac2c = param_2;
  }
  *(int ***)(&DAT_0045b028 + iVar3) = ppiVar2;
  (&DAT_0045b044)[iVar3] = param_3;
  *(undefined4 *)(&DAT_0045b048 + iVar3) = 0;
  *(int **)(&DAT_0045b030 + iVar3) = param_1;
  *(int ***)(&DAT_0045b034 + iVar3) = &DAT_0045ac28;
  *(int *)(&DAT_0045b03c + iVar3) = param_2;
  *(int *)(&DAT_0045b040 + iVar3) = DAT_004cbe5c;
  *(undefined4 *)(&DAT_0045b04c + iVar3) = 0;
  *(undefined4 *)(&DAT_0045b050 + iVar3) = 0;
  *(undefined4 *)(&DAT_0045b054 + iVar3) = 0;
  return (undefined4 *)(&DAT_0045b028 + iVar3);
}

