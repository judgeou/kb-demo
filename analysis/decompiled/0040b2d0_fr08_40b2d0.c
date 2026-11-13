// Original FR08 function at 0040b2d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40b2d0(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int extraout_ECX;
  int unaff_EBP;
  int unaff_ESI;
  float10 fVar1;
  
  do {
    fVar1 = (float10)fr08_40a474();
    *(float *)(unaff_EBP + extraout_ECX * 4) = (float)fVar1;
  } while ((char)extraout_ECX != '\x05');
  *(float *)(unaff_EBP + 0x1c) = *(float *)(unaff_ESI + 4) * _DAT_0040a40c;
  *(float *)(unaff_EBP + 0x18) = *(float *)(unaff_ESI + 8) * _DAT_0040a40c;
  return CONCAT44(param_2,in_EAX);
}

