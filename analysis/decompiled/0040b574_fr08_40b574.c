// Original FR08 function at 0040b574

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40b574(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 in_EAX;
  float *unaff_EBP;
  float *unaff_ESI;
  
  fVar1 = *unaff_ESI * _DAT_0040a40c * _DAT_0040a454;
  *unaff_EBP = fVar1;
  unaff_EBP[1] = unaff_ESI[1] * _DAT_0040a40c * _DAT_0040a458 * fVar1;
  unaff_EBP[2] = unaff_ESI[2] * _DAT_0040a40c * _DAT_0040a458 * fVar1;
  unaff_EBP[3] = (float)(int)ROUND(unaff_ESI[3]);
  fr08_40aa93();
  fr08_40b0c1();
  return CONCAT44(param_2,in_EAX);
}

