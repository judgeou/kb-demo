// Original FR08 function at 00408d82

void __thiscall fr08_408d82(float *param_1_00,float *param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *param_1_00;
  fVar2 = param_1_00[1];
  *param_1_00 = fVar1 * *param_1 + param_1[6] * param_1_00[2] + fVar2 * param_1[3];
  param_1_00[1] = param_1[7] * param_1_00[2] + fVar1 * param_1[1] + fVar2 * param_1[4];
  param_1_00[2] = param_1[8] * param_1_00[2] + fVar1 * param_1[2] + fVar2 * param_1[5];
  return;
}

