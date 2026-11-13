// Original FR08 function at 0040a031

float10 fr08_40a031(double param_1,double param_2)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar2 = (float10)1.442695040888963 *
          (float10)0.6931471805599453 * (float10)param_1 * (float10)param_2;
  fVar1 = ROUND(fVar2);
  fVar2 = (float10)f2xm1(fVar2 - fVar1);
  fVar1 = (float10)fscale((float10)1 + fVar2,fVar1);
  return (float10)(float)fVar1;
}

