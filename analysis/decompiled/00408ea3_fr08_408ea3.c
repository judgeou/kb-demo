// Original FR08 function at 00408ea3

void __thiscall
fr08_408ea3(float *param_1_00,undefined4 param_1,undefined4 param_3_00,double param_2,double param_3
           )

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar2 = (float10)fcos((float10)(double)CONCAT44(param_3_00,param_1));
  fVar3 = (float10)fcos((float10)param_2);
  fVar4 = (float10)fcos((float10)param_3);
  fVar5 = (float10)fsin((float10)(double)CONCAT44(param_3_00,param_1));
  fVar1 = (float)fVar5;
  fVar5 = (float10)fsin((float10)param_2);
  fVar6 = (float10)fsin((float10)param_3);
  *param_1_00 = (float)(fVar4 * fVar2 - fVar6 * fVar5 * (float10)fVar1);
  param_1_00[1] = (float)-(fVar6 * fVar3);
  param_1_00[2] = (float)((float10)fVar1 * fVar4 + fVar6 * fVar5 * fVar2);
  param_1_00[3] = (float)(fVar6 * fVar2 + fVar5 * (float10)fVar1 * fVar4);
  param_1_00[4] = (float)(fVar4 * fVar3);
  param_1_00[5] = (float)(fVar6 * (float10)fVar1 - fVar5 * fVar4 * fVar2);
  param_1_00[6] = (float)-((float10)fVar1 * fVar3);
  param_1_00[7] = (float)fVar5;
  param_1_00[8] = (float)(fVar3 * fVar2);
  return;
}

