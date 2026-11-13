// Original FR08 function at 004038f6

void __thiscall fr08_4038f6(float *param_1_00,float *param_1,double param_2)

{
  *param_1_00 = *param_1 * (float)param_2 + *param_1_00;
  param_1_00[1] = param_1[1] * (float)param_2 + param_1_00[1];
  param_1_00[2] = param_1[2] * (float)param_2 + param_1_00[2];
  return;
}

