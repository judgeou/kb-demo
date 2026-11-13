// Original FR08 function at 0040a6d1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40a6d1(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int unaff_EBP;
  int unaff_ESI;
  float10 fVar1;
  
  fVar1 = (float10)fr08_40a46e();
  *(float *)(unaff_EBP + 0xc) = (float)fVar1;
  fVar1 = (float10)fr08_40a464();
  *(float *)(unaff_EBP + 0x10) = (float)((float10)1 - fVar1);
  *(undefined4 *)(unaff_EBP + 0x14) = *(undefined4 *)(unaff_ESI + 8);
  fVar1 = (float10)fr08_40a46e();
  *(float *)(unaff_EBP + 0x18) = (float)fVar1;
  fVar1 = (float10)fr08_40a464();
  *(float *)(unaff_EBP + 0x1c) = (float)((float10)1 - fVar1);
  *(float *)(unaff_EBP + 0x20) = *(float *)(unaff_ESI + 0x14) * _DAT_0040a40c;
  return CONCAT44(param_2,in_EAX);
}

