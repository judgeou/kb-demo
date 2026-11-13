// Original FR08 function at 0040a945

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40a945(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int unaff_EBP;
  float *unaff_ESI;
  float10 fVar1;
  
  *(int *)(unaff_EBP + 4) = (int)ROUND(*unaff_ESI);
  *(int *)(unaff_EBP + 8) = (int)ROUND(unaff_ESI[1]);
  *(int *)(unaff_EBP + 0xc) = (int)ROUND(unaff_ESI[2]);
  fVar1 = (float10)fr08_40a464();
  *(int *)(unaff_EBP + 0x10) = (int)ROUND(fVar1 * (float10)_DAT_0040a408);
  *(int *)(unaff_EBP + 0x18) = (int)ROUND(unaff_ESI[4] * _DAT_0040a40c * _DAT_0040a408);
  *(int *)(unaff_EBP + 0x18) = *(int *)(unaff_EBP + 0x18) << 1;
  *(float *)(unaff_EBP + 0x1c) = unaff_ESI[5];
  return CONCAT44(param_2,in_EAX);
}

