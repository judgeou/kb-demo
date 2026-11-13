// Original FR08 function at 0040a585

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40a585(int param_1,undefined4 param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  float fVar7;
  undefined4 in_EAX;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint *unaff_EBP;
  int unaff_EDI;
  float10 fVar11;
  
  iVar1 = unaff_EDI + param_1 * 4;
  param_1 = -param_1;
  switch(*unaff_EBP & 7) {
  case 1:
    uVar8 = unaff_EBP[1];
    do {
      iVar9 = 4;
      fVar2 = 0.0;
      do {
        while( true ) {
          unaff_EBP[0xd] = uVar8 >> 9 | 0x3f800000;
          if (uVar8 < unaff_EBP[3]) break;
          uVar8 = uVar8 + unaff_EBP[2];
          fVar2 = (float)unaff_EBP[0xd] * (float)unaff_EBP[6] + (float)unaff_EBP[7] + fVar2;
          iVar9 = iVar9 + -1;
          if (iVar9 == 0) goto LAB_0040a5db;
        }
        uVar8 = uVar8 + unaff_EBP[2];
        fVar2 = (float)unaff_EBP[0xd] * (float)unaff_EBP[4] + (float)unaff_EBP[5] + fVar2;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
LAB_0040a5db:
      *(float *)(iVar1 + param_1 * 4) =
           fVar2 * (float)unaff_EBP[0xc] + *(float *)(iVar1 + param_1 * 4);
      param_1 = param_1 + 1;
    } while (param_1 != 0);
    unaff_EBP[1] = uVar8;
    break;
  case 2:
    uVar8 = unaff_EBP[1];
    do {
      iVar9 = 4;
      fVar2 = 0.0;
      do {
        if (unaff_EBP[3] <= uVar8) {
          fVar2 = fVar2 + 2.0;
        }
        uVar8 = uVar8 + unaff_EBP[2];
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      *(float *)(iVar1 + param_1 * 4) =
           (fVar2 - 4.0) * (float)unaff_EBP[0xc] + *(float *)(iVar1 + param_1 * 4);
      param_1 = param_1 + 1;
    } while (param_1 != 0);
    unaff_EBP[1] = uVar8;
    return CONCAT44(param_2,in_EAX);
  case 3:
    uVar8 = unaff_EBP[1];
    uVar6 = unaff_EBP[2];
    do {
      uVar10 = uVar8 >> 9;
      uVar8 = uVar8 + uVar6 * 4;
      unaff_EBP[0xd] = uVar10 | 0x3f800000;
      fVar11 = (float10)fsin((float10)(float)unaff_EBP[0xd] * (float10)_DAT_0040a418);
      *(float *)(iVar1 + param_1 * 4) =
           (float)(fVar11 * (float10)(float)unaff_EBP[0xb] +
                  (float10)*(float *)(iVar1 + param_1 * 4));
      param_1 = param_1 + 1;
    } while (param_1 != 0);
    unaff_EBP[1] = uVar8;
    return CONCAT44(param_2,in_EAX);
  case 4:
    uVar8 = unaff_EBP[10];
    fVar2 = (float)unaff_EBP[9];
    fVar3 = (float)unaff_EBP[8];
    fVar4 = (float)unaff_EBP[0xe];
    fVar5 = (float)unaff_EBP[0xf];
    do {
      uVar8 = uVar8 * 0x343fd + 0x269ec3;
      unaff_EBP[0xd] = (uVar8 & 0xffff) << 7 | 0x40000000;
      fVar4 = fVar5 * fVar3 + fVar4;
      fVar7 = (((((float)unaff_EBP[0xd] - 1.0) - 1.0) - 1.0) - fVar5) * fVar2 - fVar4;
      fVar5 = fVar7 * fVar3 + fVar5;
      *(float *)(iVar1 + param_1 * 4) =
           (fVar4 + fVar7 + fVar5) * (float)unaff_EBP[0xb] + *(float *)(iVar1 + param_1 * 4);
      param_1 = param_1 + 1;
    } while (param_1 != 0);
    unaff_EBP[0xf] = (uint)fVar5;
    unaff_EBP[0xe] = (uint)fVar4;
    unaff_EBP[10] = uVar8;
    return CONCAT44(param_2,in_EAX);
  }
  return CONCAT44(param_2,in_EAX);
}

