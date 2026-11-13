// Original FR08 function at 0040a064

undefined8 __fastcall FUN_0040a064(uint param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 in_EAX;
  int iVar2;
  int unaff_EBX;
  float *unaff_ESI;
  undefined2 *unaff_EDI;
  
  param_1 = param_1 >> 1;
  do {
    fVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    *(int *)(unaff_EBX + 0x4c) = (int)ROUND(fVar1 * *(float *)(unaff_EBX + 0x14));
    iVar2 = *(int *)(unaff_EBX + 0x4c);
    if (0x7f58 < iVar2) {
      iVar2 = 0x7f58;
    }
    if (iVar2 < -0x7f58) {
      iVar2 = -0x7f58;
    }
    *unaff_EDI = (short)iVar2;
    param_1 = param_1 - 1;
    unaff_EDI = unaff_EDI + 1;
  } while (param_1 != 0);
  return CONCAT44(param_2,in_EAX);
}

