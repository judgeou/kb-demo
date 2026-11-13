// Original FR08 function at 0040a4d2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40a4d2(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 in_EAX;
  int *unaff_EBP;
  float *unaff_ESI;
  
  *unaff_EBP = (int)ROUND(*unaff_ESI);
  unaff_EBP[0x11] =
       (int)((unaff_ESI[2] - _DAT_0040a420) * _DAT_0040a40c + (unaff_ESI[1] - _DAT_0040a420));
  fr08_40a49b();
  fVar1 = unaff_ESI[4] * _DAT_0040a40c;
  unaff_EBP[0xb] = (int)fVar1;
  unaff_EBP[0xc] = (int)(fVar1 * _DAT_0040a410);
  fVar2 = _DAT_0040a404;
  fVar1 = unaff_ESI[3] * _DAT_0040a40c;
  unaff_EBP[3] = (int)ROUND(fVar1 * _DAT_0040a408);
  unaff_EBP[3] = unaff_EBP[3] << 1;
  fVar3 = _DAT_0040a404;
  unaff_EBP[9] = (int)(1.0 - SQRT(fVar1));
  unaff_EBP[4] = (int)(fVar3 / fVar1);
  unaff_EBP[5] = (int)(-1.0 - fVar3 / fVar1);
  fVar1 = -(fVar2 / (1.0 - fVar1));
  unaff_EBP[6] = (int)fVar1;
  unaff_EBP[7] = (int)(-(fVar1 + fVar1) - 1.0);
  return CONCAT44(param_2,in_EAX);
}

