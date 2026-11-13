// Original FR08 function at 00408d27

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall fr08_408d27(float *param_1)

{
  float fVar1;
  
  fVar1 = param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1;
  if ((float)_DAT_00444200 < fVar1) {
    fVar1 = (float)_DAT_00444128 / SQRT(fVar1);
    *param_1 = *param_1 * fVar1;
    param_1[1] = param_1[1] * fVar1;
    param_1[2] = param_1[2] * fVar1;
    return;
  }
  *param_1 = 1.0;
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  return;
}

