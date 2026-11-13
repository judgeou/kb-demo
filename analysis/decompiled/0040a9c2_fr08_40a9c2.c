// Original FR08 function at 0040a9c2

undefined8 __fastcall fr08_40a9c2(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  float fVar1;
  float *unaff_EBP;
  float10 fVar2;
  
  fVar2 = (float10)(**(code **)(&DAT_0040a9a2 + ((uint)unaff_EBP[1] & 0xffffff07) * 4))();
  *unaff_EBP = (float)(fVar2 * (float10)unaff_EBP[7]);
  fVar1 = (float)((int)unaff_EBP[5] + (int)unaff_EBP[4]);
  if ((CARRY4((uint)unaff_EBP[5],(uint)unaff_EBP[4])) && (unaff_EBP[3] != 0.0)) {
    fVar1 = -NAN;
  }
  unaff_EBP[5] = fVar1;
  return CONCAT44(param_2,in_EAX);
}

