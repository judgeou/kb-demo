// Original FR08 function at 0040b0c1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40b0c1(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 in_EAX;
  int unaff_EBP;
  float *unaff_ESI;
  float10 fVar2;
  
  fVar1 = (*unaff_ESI - _DAT_0040a420) * _DAT_0040a40c;
  fVar1 = fVar1 + fVar1;
  *(float *)(unaff_EBP + 0x30) = fVar1;
  *(float *)(unaff_EBP + 0x2c) = 1.0 - ABS(fVar1);
  fVar1 = (unaff_ESI[1] - _DAT_0040a420) * _DAT_0040a40c;
  *(float *)(unaff_EBP + 0x28) = fVar1 + fVar1;
  fVar1 = ((float)*(int *)(unaff_EBP + 8) - _DAT_0040a440) * _DAT_0040a40c;
  *(int *)(unaff_EBP + 0x10) = (int)ROUND(unaff_ESI[2] * fVar1);
  *(int *)(unaff_EBP + 0x14) = (int)ROUND(unaff_ESI[3] * fVar1);
  fVar2 = (float10)fr08_40a464();
  *(int *)(unaff_EBP + 0x1c) = (int)ROUND(fVar2 * (float10)_DAT_0040a460);
  *(int *)(unaff_EBP + 0x24) = (int)ROUND(unaff_ESI[5] * _DAT_0040a40c * _DAT_0040a440);
  *(int *)(unaff_EBP + 0x20) =
       (int)ROUND((unaff_ESI[6] - _DAT_0040a420) * _DAT_0040a40c * _DAT_0040a408);
  *(int *)(unaff_EBP + 0x20) = *(int *)(unaff_EBP + 0x20) << 1;
  return CONCAT44(param_2,in_EAX);
}

