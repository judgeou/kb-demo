// Original FR08 function at 0040a8a6

float10 fr08_40a8a6(void)

{
  float *unaff_ESI;
  float10 in_ST0;
  float10 in_ST1;
  float10 in_ST2;
  float10 fVar1;
  float10 in_ST3;
  float10 fVar2;
  
  fVar2 = in_ST0 * in_ST2 + in_ST1;
  fVar1 = (((float10)*unaff_ESI - in_ST0 * in_ST3) - fVar2) * in_ST2 + in_ST0;
  return ((float10)*unaff_ESI - fVar1 * in_ST3) - (fVar1 * in_ST2 + fVar2);
}

