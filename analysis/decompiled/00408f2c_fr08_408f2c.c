// Original FR08 function at 00408f2c

void __thiscall fr08_408f2c(float *param_1_00,float *param_1,float *param_2)

{
  *param_1_00 = param_2[6] * param_1[2] + param_1[1] * param_2[3] + *param_1 * *param_2;
  param_1_00[1] = param_2[1] * *param_1 + param_2[7] * param_1[2] + param_1[1] * param_2[4];
  param_1_00[2] = param_2[2] * *param_1 + param_2[8] * param_1[2] + param_1[1] * param_2[5];
  param_1_00[3] = param_1[5] * param_2[6] + param_1[3] * *param_2 + param_1[4] * param_2[3];
  param_1_00[4] = param_1[3] * param_2[1] + param_1[4] * param_2[4] + param_1[5] * param_2[7];
  param_1_00[5] = param_1[3] * param_2[2] + param_1[4] * param_2[5] + param_1[5] * param_2[8];
  param_1_00[6] = param_1[7] * param_2[3] + param_2[6] * param_1[8] + param_1[6] * *param_2;
  param_1_00[7] = param_2[1] * param_1[6] + param_2[4] * param_1[7] + param_2[7] * param_1[8];
  param_1_00[8] = param_2[2] * param_1[6] + param_2[5] * param_1[7] + param_2[8] * param_1[8];
  return;
}

