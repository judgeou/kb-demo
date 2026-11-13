// Original FR08 function at 0040b700

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall fr08_40b700(int param_1)

{
  float fVar1;
  int in_EAX;
  uint uVar2;
  undefined4 uVar3;
  float fVar4;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 in_stack_0000001c;
  
  if (in_EAX == 0) {
    fVar4 = *(float *)(unaff_EBP + 4);
  }
  else {
    if (7 < (byte)in_EAX) goto LAB_0040b773;
    fVar4 = (float)(uint)(byte)(&DAT_00715c94)[unaff_EBX * 8 + in_EAX];
  }
  fVar1 = ((float)(uint)*(byte *)(unaff_EDI + 1) - _DAT_0040a420) * _DAT_0040a40c;
  uVar2 = (uint)(byte)(*(char *)(unaff_EDI + 2) - 0x34);
  _DAT_00715bc4 = (fVar1 + fVar1) * fVar4 + *(float *)(unaff_ESI + uVar2 * 4);
  fVar4 = _DAT_00715bc4;
  if ((int)_DAT_00715bc4 < 0) {
    fVar4 = 0.0;
  }
  if (0x43000000 < (uint)fVar4) {
    fVar4 = 128.0;
  }
  *(float *)(unaff_ESI + uVar2 * 4) = fVar4;
LAB_0040b773:
  if (param_1 != 1) {
    uVar3 = FUN_0040b6e5();
    return uVar3;
  }
  fr08_40b574();
  return in_stack_0000001c;
}

