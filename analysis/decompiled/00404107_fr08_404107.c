// Original FR08 function at 00404107

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_404107(int *param_1,int param_2,float *param_3,undefined4 *param_4)

{
  float *pfVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *param_1;
  uVar2 = *(undefined4 *)(iVar4 + 0x14 + param_2 * 4);
  uVar3 = *(undefined4 *)(iVar4 + 0x10 + param_2 * 4);
  pfVar1 = (float *)(iVar4 + param_2 * 4);
  *param_4 = *(undefined4 *)(iVar4 + 0xc + param_2 * 4);
  param_4[1] = uVar3;
  param_4[2] = uVar2;
  fr08_408ea3((double)pfVar1[6] * _DAT_00444118,(double)pfVar1[7] * _DAT_00444118,
              (double)pfVar1[8] * _DAT_00444118);
  if ((*(byte *)(param_1 + 7) & 4) == 0) {
    fr08_4040e8((double)*pfVar1);
    fr08_4040e8((double)pfVar1[1]);
    fr08_4040e8((double)pfVar1[2]);
  }
  else {
    *param_3 = *pfVar1 * *param_3;
    param_3[3] = *pfVar1 * param_3[3];
    param_3[6] = *pfVar1 * param_3[6];
    param_3[1] = param_3[1] * pfVar1[1];
    param_3[4] = param_3[4] * pfVar1[1];
    param_3[7] = param_3[7] * pfVar1[1];
    param_3[2] = pfVar1[2] * param_3[2];
    param_3[5] = pfVar1[2] * param_3[5];
    param_3[8] = pfVar1[2] * param_3[8];
  }
  return;
}

