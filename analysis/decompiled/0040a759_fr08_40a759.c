// Original FR08 function at 0040a759

undefined8 __fastcall fr08_40a759(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  float *unaff_EBP;
  
  (**(code **)(&DAT_0040a745 + (int)unaff_EBP[1] * 4))();
  *unaff_EBP = unaff_EBP[2] * unaff_EBP[8];
  return CONCAT44(param_2,in_EAX);
}

