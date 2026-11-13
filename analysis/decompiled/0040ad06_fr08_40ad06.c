// Original FR08 function at 0040ad06

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40ad06(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  fr08_40a759();
  fr08_40a759();
  fr08_40a9c2();
  fr08_40a9c2();
  *(float *)(unaff_EBP + 0x10) =
       (*(float *)(unaff_EBP + 0x124) * _DAT_0040a40c - *(float *)(unaff_EBP + 0xc)) * _DAT_0040a41c
  ;
  return CONCAT44(param_2,in_EAX);
}

