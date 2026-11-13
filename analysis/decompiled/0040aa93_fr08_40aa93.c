// Original FR08 function at 0040aa93

undefined8 __fastcall fr08_40aa93(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  uint *unaff_EBP;
  float *unaff_ESI;
  float10 fVar1;
  
  *unaff_EBP = (int)ROUND(*unaff_ESI);
  fVar1 = (float10)fr08_40a46e();
  unaff_EBP[1] = (uint)(float)fVar1;
  (**(code **)(&DAT_0040aa73 + (*unaff_EBP & 0xffffff07) * 4))();
  return CONCAT44(param_2,in_EAX);
}

