// Original FR08 function at 0040b317

undefined8 __fastcall fr08_40b317(int param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 in_EAX;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float *unaff_EBP;
  float *pfVar9;
  float *unaff_EDI;
  
  pfVar9 = (float *)&DAT_007147c4;
  fVar1 = unaff_EBP[7];
  do {
    fVar3 = *pfVar9 * unaff_EBP[6];
    pfVar9 = pfVar9 + 1;
    fVar4 = unaff_EBP[8];
    fVar2 = ((unaff_EBP[(int)fVar4 + 0x1c] * *unaff_EBP + fVar3) - unaff_EBP[0x14]) * fVar1 +
            unaff_EBP[0x14];
    unaff_EBP[0x14] = fVar2;
    unaff_EBP[(int)fVar4 + 0x1c] = fVar2;
    fVar4 = (float)((int)fVar4 + 1);
    if (SUB42(fVar4,0) == 0x51d) {
      fVar4 = 0.0;
    }
    unaff_EBP[8] = fVar4;
    fVar4 = unaff_EBP[9];
    fVar8 = ((unaff_EBP[(int)fVar4 + 0x539] * unaff_EBP[1] - fVar3) - unaff_EBP[0x15]) * fVar1 +
            unaff_EBP[0x15];
    unaff_EBP[0x15] = fVar8;
    unaff_EBP[(int)fVar4 + 0x539] = fVar8;
    fVar4 = (float)((int)fVar4 + 1);
    if (SUB42(fVar4,0) == 0x663) {
      fVar4 = 0.0;
    }
    unaff_EBP[9] = fVar4;
    fVar4 = unaff_EBP[10];
    fVar6 = ((unaff_EBP[(int)fVar4 + 0xb9c] * unaff_EBP[2] + fVar3) - unaff_EBP[0x16]) * fVar1 +
            unaff_EBP[0x16];
    unaff_EBP[0x16] = fVar6;
    unaff_EBP[(int)fVar4 + 0xb9c] = fVar6;
    fVar4 = (float)((int)fVar4 + 1);
    if (SUB42(fVar4,0) == 0x713) {
      fVar4 = 0.0;
    }
    unaff_EBP[10] = fVar4;
    fVar4 = unaff_EBP[0xb];
    fVar7 = ((unaff_EBP[(int)fVar4 + 0x12af] * unaff_EBP[3] - fVar3) - unaff_EBP[0x17]) * fVar1 +
            unaff_EBP[0x17];
    unaff_EBP[0x17] = fVar7;
    unaff_EBP[(int)fVar4 + 0x12af] = fVar7;
    fVar4 = (float)((int)fVar4 + 1);
    if (SUB42(fVar4,0) == 0x786) {
      fVar4 = 0.0;
    }
    unaff_EBP[0xb] = fVar4;
    fVar5 = unaff_EBP[0xc];
    fVar4 = unaff_EBP[(int)fVar5 + 0x1a35];
    fVar2 = fVar4 * unaff_EBP[4] + fVar7 + fVar6 + fVar8 + fVar2;
    unaff_EBP[(int)fVar5 + 0x1a35] = fVar2;
    fVar5 = (float)((int)fVar5 + 1);
    if (SUB41(fVar5,0) == -0x24) {
      fVar5 = 0.0;
    }
    unaff_EBP[0xc] = fVar5;
    fVar6 = unaff_EBP[0xd];
    fVar8 = unaff_EBP[(int)fVar6 + 0x1b11];
    fVar4 = fVar8 * unaff_EBP[5] + (fVar4 - fVar2 * unaff_EBP[4]);
    unaff_EBP[(int)fVar6 + 0x1b11] = fVar4;
    fVar6 = (float)((int)fVar6 + 1);
    if (SUB41(fVar6,0) == 'J') {
      fVar6 = 0.0;
    }
    unaff_EBP[0xd] = fVar6;
    *unaff_EDI = (fVar8 - fVar4 * unaff_EBP[5]) + *unaff_EDI;
    fVar4 = unaff_EBP[0xe];
    fVar2 = ((unaff_EBP[(int)fVar4 + 0x1b5b] * *unaff_EBP + fVar3) - unaff_EBP[0x18]) * fVar1 +
            unaff_EBP[0x18];
    unaff_EBP[0x18] = fVar2;
    unaff_EBP[(int)fVar4 + 0x1b5b] = fVar2;
    fVar4 = (float)((int)fVar4 + 1);
    if (SUB42(fVar4,0) == 0x52f) {
      fVar4 = 0.0;
    }
    unaff_EBP[0xe] = fVar4;
    fVar4 = unaff_EBP[0xf];
    fVar8 = ((unaff_EBP[(int)fVar4 + 0x208a] * unaff_EBP[1] - fVar3) - unaff_EBP[0x19]) * fVar1 +
            unaff_EBP[0x19];
    unaff_EBP[0x19] = fVar8;
    unaff_EBP[(int)fVar4 + 0x208a] = fVar8;
    fVar4 = (float)((int)fVar4 + 1);
    if (SUB42(fVar4,0) == 0x65f) {
      fVar4 = 0.0;
    }
    unaff_EBP[0xf] = fVar4;
    fVar4 = unaff_EBP[0x10];
    fVar6 = ((unaff_EBP[(int)fVar4 + 0x26e9] * unaff_EBP[2] + fVar3) - unaff_EBP[0x1a]) * fVar1 +
            unaff_EBP[0x1a];
    unaff_EBP[0x1a] = fVar6;
    unaff_EBP[(int)fVar4 + 0x26e9] = fVar6;
    fVar4 = (float)((int)fVar4 + 1);
    if (SUB42(fVar4,0) == 0x729) {
      fVar4 = 0.0;
    }
    unaff_EBP[0x10] = fVar4;
    fVar4 = unaff_EBP[0x11];
    fVar3 = ((unaff_EBP[(int)fVar4 + 0x2e12] * unaff_EBP[3] - fVar3) - unaff_EBP[0x1b]) * fVar1 +
            unaff_EBP[0x1b];
    unaff_EBP[0x1b] = fVar3;
    unaff_EBP[(int)fVar4 + 0x2e12] = fVar3;
    fVar4 = (float)((int)fVar4 + 1);
    if (SUB42(fVar4,0) == 0x76d) {
      fVar4 = 0.0;
    }
    unaff_EBP[0x11] = fVar4;
    fVar7 = unaff_EBP[0x12];
    fVar4 = unaff_EBP[(int)fVar7 + 0x357f];
    fVar3 = fVar4 * unaff_EBP[4] + fVar3 + fVar6 + fVar8 + fVar2;
    unaff_EBP[(int)fVar7 + 0x357f] = fVar3;
    fVar7 = (float)((int)fVar7 + 1);
    if (SUB41(fVar7,0) == -0x33) {
      fVar7 = 0.0;
    }
    unaff_EBP[0x12] = fVar7;
    fVar8 = unaff_EBP[0x13];
    fVar2 = unaff_EBP[(int)fVar8 + 0x364c];
    fVar4 = fVar2 * unaff_EBP[5] + (fVar4 - fVar3 * unaff_EBP[4]);
    unaff_EBP[(int)fVar8 + 0x364c] = fVar4;
    fVar8 = (float)((int)fVar8 + 1);
    if (SUB41(fVar8,0) == 'M') {
      fVar8 = 0.0;
    }
    unaff_EBP[0x13] = fVar8;
    unaff_EDI[1] = (fVar2 - fVar4 * unaff_EBP[5]) + unaff_EDI[1];
    unaff_EDI = unaff_EDI + 2;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return CONCAT44(param_2,in_EAX);
}

