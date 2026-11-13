// Original FR08 function at 00402c5c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402c5c(float *param_1,float *param_2)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar1 = _DAT_004440e8;
  fVar2 = (float10)_DAT_00444118;
  if ((_DAT_004440e8 < param_2[3]) && (_DAT_004440e8 < param_2[1])) {
    fVar3 = (float10)fsin((float10)param_2[5] * fVar2 + (float10)*param_1 * (float10)param_2[3]);
    param_1[1] = (float)(fVar3 * (float10)param_2[1] + (float10)param_1[1]);
    if (fVar1 < param_2[7]) {
      fVar3 = (float10)fsin((float10)*param_1 * (float10)param_2[3] +
                            ((float10)param_2[5] + (float10)_DAT_00444110) * fVar2);
      param_1[7] = (float)(fVar3 * (float10)param_2[7] + (float10)param_1[7]);
    }
  }
  if ((fVar1 < param_2[4]) && (fVar1 < param_2[2])) {
    fVar3 = (float10)fsin((float10)param_2[6] * fVar2 + (float10)param_1[2] * (float10)param_2[4]);
    param_1[1] = (float)(fVar3 * (float10)param_2[2] + (float10)param_1[1]);
    if (fVar1 < param_2[7]) {
      fVar2 = (float10)fsin((float10)param_1[2] * (float10)param_2[4] +
                            ((float10)param_2[6] + (float10)_DAT_00444110) * fVar2);
      param_1[8] = (float)(fVar2 * (float10)param_2[7] + (float10)param_1[8]);
    }
  }
  if (fVar1 < *param_2) {
    fVar2 = (float10)fr08_409fda(*param_2);
    *param_1 = (float)(fVar2 + (float10)*param_1);
    fVar2 = (float10)fr08_409fda(*param_2);
    param_1[1] = (float)(fVar2 + (float10)param_1[1]);
    fVar2 = (float10)fr08_409fda(*param_2);
    param_1[2] = (float)(fVar2 + (float10)param_1[2]);
  }
  return;
}

