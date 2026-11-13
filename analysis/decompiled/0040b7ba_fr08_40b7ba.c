// Original FR08 function at 0040b7ba

undefined8 __fastcall fr08_40b7ba(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 in_EAX;
  int *unaff_EBP;
  float *unaff_ESI;
  
  iVar2 = *unaff_EBP;
  do {
    fVar1 = *unaff_ESI;
    fVar3 = (float)unaff_EBP[0xf] * (float)unaff_EBP[1] + (float)unaff_EBP[0xe];
    fVar4 = (float)unaff_EBP[0xf] * (float)unaff_EBP[2];
    unaff_EBP[0xe] = (int)fVar3;
    fVar4 = (fVar4 - fVar3) * (float)unaff_EBP[1] + fVar4;
    unaff_EBP[0xf] = (int)fVar4;
    if (iVar2 == 0) {
      fVar3 = fVar4;
    }
    fVar4 = (float)unaff_EBP[0x11] * (float)unaff_EBP[4] + (float)unaff_EBP[0x10];
    unaff_EBP[0x10] = (int)fVar4;
    fVar4 = (fVar1 - fVar4) * (float)unaff_EBP[4] + (float)unaff_EBP[0x11] * (float)unaff_EBP[5];
    unaff_EBP[0x11] = (int)fVar4;
    fVar5 = (float)unaff_EBP[0x13] * (float)unaff_EBP[7] + (float)unaff_EBP[0x12];
    unaff_EBP[0x12] = (int)fVar5;
    fVar5 = (fVar1 - fVar5) * (float)unaff_EBP[7] + (float)unaff_EBP[0x13] * (float)unaff_EBP[8];
    unaff_EBP[0x13] = (int)fVar5;
    fVar6 = (float)unaff_EBP[0x15] * (float)unaff_EBP[10] + (float)unaff_EBP[0x14];
    unaff_EBP[0x14] = (int)fVar6;
    fVar6 = (fVar1 - fVar6) * (float)unaff_EBP[10] + (float)unaff_EBP[0x15] * (float)unaff_EBP[0xb];
    unaff_EBP[0x15] = (int)fVar6;
    fVar1 = fVar1 * (float)unaff_EBP[0xd] +
            fVar6 * (float)unaff_EBP[0xc] +
            fVar5 * (float)unaff_EBP[9] + fVar4 * (float)unaff_EBP[6] + fVar3 * (float)unaff_EBP[3];
    *unaff_ESI = fVar1;
    unaff_ESI[1] = fVar1;
    unaff_ESI = unaff_ESI + 2;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return CONCAT44(param_2,in_EAX);
}

