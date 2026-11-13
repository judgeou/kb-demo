// Original FR08 function at 00404a89

void __thiscall fr08_404a89(float *param_1_00,float *param_1,float *param_2)

{
  *param_1_00 = param_2[2] * param_1[1] - param_1[2] * param_2[1];
  param_1_00[1] = param_1[2] * *param_2 - *param_1 * param_2[2];
  param_1_00[2] = *param_1 * param_2[1] - *param_2 * param_1[1];
  return;
}

