// Original FR08 function at 0040a837

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40a837(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int *unaff_EBP;
  float *unaff_ESI;
  float10 fVar1;
  
  *unaff_EBP = (int)ROUND(*unaff_ESI);
  fVar1 = (float10)fr08_40a464();
  unaff_EBP[2] = (int)(1.0 - unaff_ESI[2] * _DAT_0040a40c);
  unaff_EBP[1] = (int)(float)fVar1;
  return CONCAT44(param_2,in_EAX);
}

