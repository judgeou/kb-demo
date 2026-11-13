// Original FR08 function at 00401faa

undefined4 * fr08_401faa(int param_1,int param_2,undefined param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int **ppiVar3;
  int **ppiVar4;
  int iVar5;
  int iVar6;
  
  ppiVar3 = (int **)fr08_401f0c(1,param_2);
  ppiVar4 = (int **)fr08_401f0c(0,param_1);
  iVar6 = DAT_0049302c * 0x38;
  DAT_0049302c = DAT_0049302c + 1;
  (&DAT_0049305c)[iVar6] = param_3;
  *(int ***)(&DAT_00493040 + iVar6) = ppiVar4;
  piVar1 = ppiVar4[1];
  *(int *)(&DAT_00493048 + iVar6) = param_1;
  *(int **)(&DAT_00493044 + iVar6) = piVar1;
  *(int ***)(&DAT_0049304c + iVar6) = ppiVar3;
  *(int **)(&DAT_00493050 + iVar6) = ppiVar3[1];
  *(int *)(&DAT_00493054 + iVar6) = param_2;
  uVar2 = DAT_004cbe5c;
  *(undefined4 *)(&DAT_00493060 + iVar6) = 0;
  *(undefined4 *)(&DAT_00493058 + iVar6) = uVar2;
  *(undefined4 *)(&DAT_00493064 + iVar6) = 0;
  *(undefined4 *)(&DAT_00493068 + iVar6) = 0;
  *(undefined4 *)(&DAT_0049306c + iVar6) = 0;
  ppiVar4[1] = (int *)((int)ppiVar4[1] + param_1);
  ppiVar3[1] = (int *)((int)ppiVar3[1] + param_2);
  iVar5 = (**(code **)(**ppiVar4 + 0x2c))
                    (*ppiVar4,*(int *)(&DAT_00493044 + iVar6) * 0x24,param_1 * 0x24,iVar6 + 0x493070
                     ,0);
  if (iVar5 < 0) {
    fr08_401000();
  }
  iVar5 = (**(code **)(**ppiVar3 + 0x2c))
                    (*ppiVar3,*(int *)(&DAT_00493050 + iVar6) << 1,param_2 * 2,iVar6 + 0x493074,0);
  if (iVar5 < 0) {
    fr08_401000();
  }
  return (undefined4 *)(&DAT_00493040 + iVar6);
}

