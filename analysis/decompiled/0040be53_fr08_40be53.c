// Original FR08 function at 0040be53

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40be53(undefined4 param_1_00,undefined4 param_2,byte *param_1)

{
  float fVar1;
  undefined4 in_EAX;
  int iVar2;
  float *pfVar3;
  
  pfVar3 = (float *)&DAT_00719458;
  iVar2 = 0xc;
  do {
    _DAT_00715bc4 = (uint)*param_1;
    *pfVar3 = (float)_DAT_00715bc4;
    pfVar3 = pfVar3 + 1;
    iVar2 = iVar2 + -1;
    param_1 = param_1 + 1;
  } while (iVar2 != 0);
  fr08_40b2d0();
  fr08_40b0c1();
  fVar1 = (_DAT_00719480 + 1.0) * _DAT_0040a40c;
  _DAT_00726f78 = fVar1 * fVar1;
  fVar1 = (_DAT_00719484 + 1.0) * _DAT_0040a40c;
  DAT_00726f84 = fVar1 * fVar1;
  return CONCAT44(param_2,in_EAX);
}

