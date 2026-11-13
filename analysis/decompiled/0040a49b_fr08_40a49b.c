// Original FR08 function at 0040a49b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_40a49b(void)

{
  int unaff_EBP;
  float10 fVar1;
  
  fVar1 = (float10)fr08_40a464();
  *(float *)(unaff_EBP + 0x20) = (float)fVar1;
  fVar1 = (float10)fr08_40a46e();
  *(int *)(unaff_EBP + 8) = (int)ROUND(fVar1 * (float10)_DAT_0040a45c);
  return;
}

