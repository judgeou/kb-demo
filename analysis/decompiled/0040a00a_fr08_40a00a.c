// Original FR08 function at 0040a00a

float10 fr08_40a00a(double param_1)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = ROUND((float10)1.442695040888963 * (float10)param_1);
  fVar2 = (float10)f2xm1((float10)1.442695040888963 * (float10)param_1 - fVar1);
  fVar1 = (float10)fscale((float10)1 + fVar2,fVar1);
  return (float10)(float)fVar1;
}

