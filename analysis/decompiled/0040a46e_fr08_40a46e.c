// Original FR08 function at 0040a46e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

unkbyte10 fr08_40a46e(void)

{
  float10 fVar1;
  float10 in_ST0;
  float10 fVar2;
  unkbyte10 Var3;
  float10 fVar4;
  
  fVar4 = in_ST0 * (float10)_DAT_0040a404;
  fVar1 = (float10)1;
  fVar2 = (float10)f2xm1(fVar4 - (fVar4 / fVar1) * fVar1);
  Var3 = fscale(fVar2 + fVar1,fVar4);
  return Var3;
}

