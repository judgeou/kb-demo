// Original FR08 function at 0040a880

undefined8 __fastcall fr08_40a880(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  byte *unaff_EBP;
  float10 fVar1;
  float10 extraout_ST1;
  
  fVar1 = (float10)(*(code *)(&PTR_LAB_0040a860)[*unaff_EBP & 7])();
  *(float *)(unaff_EBP + 0x10) = (float)fVar1;
  *(float *)(unaff_EBP + 0xc) = (float)extraout_ST1;
  return CONCAT44(param_2,in_EAX);
}

