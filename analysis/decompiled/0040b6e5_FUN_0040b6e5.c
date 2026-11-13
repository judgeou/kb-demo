// Original FR08 function at 0040b6e5

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0040b6e5(int param_1)

{
  byte bVar1;
  float fVar2;
  undefined4 uVar3;
  float fVar4;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  byte *unaff_EDI;
  undefined4 in_stack_0000001c;
  
  if ((0x33 < unaff_EDI[2]) && (unaff_EDI[2] < 0x43)) {
    bVar1 = *unaff_EDI;
    if (bVar1 == 0) {
      fVar4 = *(float *)(unaff_EBP + 4);
    }
    else {
      if (7 < bVar1) goto LAB_0040b773;
      fVar4 = (float)(uint)(byte)(&DAT_00715c94)[unaff_EBX * 8 + (uint)bVar1];
    }
    fVar2 = ((float)(uint)unaff_EDI[1] - _DAT_0040a420) * _DAT_0040a40c;
    _DAT_00715bc4 =
         (fVar2 + fVar2) * fVar4 + *(float *)(unaff_ESI + (uint)(byte)(unaff_EDI[2] - 0x34) * 4);
    fVar4 = _DAT_00715bc4;
    if ((int)_DAT_00715bc4 < 0) {
      fVar4 = 0.0;
    }
    if (0x43000000 < (uint)fVar4) {
      fVar4 = 128.0;
    }
    *(float *)(unaff_ESI + (uint)(byte)(unaff_EDI[2] - 0x34) * 4) = fVar4;
  }
LAB_0040b773:
  if (param_1 == 1) {
    fr08_40b574();
    return in_stack_0000001c;
  }
  uVar3 = FUN_0040b6e5();
  return uVar3;
}

