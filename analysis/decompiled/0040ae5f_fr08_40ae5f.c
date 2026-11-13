// Original FR08 function at 0040ae5f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40ae5f(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 in_EAX;
  int unaff_EBP;
  float *unaff_ESI;
  
  *(int *)(unaff_EBP + 0x14) = (int)ROUND(unaff_ESI[0x16]);
  *(int *)(unaff_EBP + 0x20) = (int)ROUND(unaff_ESI[0x33]);
  fVar1 = *unaff_ESI * _DAT_0040a40c;
  *(float *)(unaff_EBP + 0x18) = SQRT(1.0 - fVar1);
  *(float *)(unaff_EBP + 0x1c) = SQRT(fVar1);
  fr08_40a4d2();
  fr08_40a4d2();
  fr08_40a4d2();
  fr08_40a6d1();
  fr08_40a6d1();
  fr08_40a837();
  fr08_40a837();
  fr08_40a945();
  fr08_40a945();
  fr08_40aa93();
  return CONCAT44(param_2,in_EAX);
}

