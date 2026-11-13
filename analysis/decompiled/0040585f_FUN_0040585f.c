// Original FR08 function at 0040585f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040585f(float **param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  uint uVar7;
  float fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  
  if (param_1[4] != (float *)0x0) {
    param_1[4] = (float *)0x0;
    if (param_1[1] != (float *)0x0) {
      (*(code *)param_1[1][6])();
    }
    pfVar5 = param_1[9];
    fr08_405dc0();
    uVar7 = (uint)param_1[7] & 0xf0;
    if (uVar7 == 0) {
      fVar8 = param_1[1][9];
      pfVar5[0x19] = 1.401298e-45;
      pfVar5[0x1a] = fVar8;
    }
    else if (uVar7 == 0x10) {
      (*(code *)param_1[2][6])();
      pfVar5[0x1a] = param_1[1][9];
      fVar8 = param_1[2][9];
      pfVar5[0x19] = 2.802597e-45;
      pfVar5[0x1b] = fVar8;
    }
    else if (uVar7 == 0x20) {
      if (param_1[1] != (float *)0x0) {
        fVar8 = param_1[1][9];
        pfVar5[0x19] = 1.401298e-45;
        pfVar5[0x1a] = fVar8;
      }
      fr08_405d5c();
      pfVar5[0x54] = 1.401298e-45;
      pfVar5[0x3b] = (float)((uint)param_1[7] & 3);
      pfVar5[0x4f] = (float)((int)param_1[7] >> 2 & 3);
      pfVar5[0x50] = **param_1;
      pfVar5[0x51] = (*param_1)[1];
      pfVar5[0x52] = (*param_1)[2];
      pfVar5[0x53] = (*param_1)[3];
      fVar8 = (float)fr08_405e49(*param_1 + 4);
      pfVar5[0x4d] = fVar8;
      if (((uint)fVar8 & 0xff000000) < 0xfe000000) {
        pfVar5[0x54] = 2.802597e-45;
      }
      pfVar5[0x3a] = 1.401298e-45;
    }
    else if (uVar7 == 0x30) {
      fVar8 = param_1[1][9];
      pfVar5[0x19] = 1.401298e-45;
      pfVar5[0x1a] = fVar8;
      pfVar6 = *param_1;
      fVar8 = pfVar6[1];
      fVar1 = pfVar6[2];
      fVar2 = pfVar6[3];
      fVar3 = pfVar6[4];
      fVar4 = pfVar6[5];
      fVar9 = (float10)pfVar6[6];
      fVar10 = (float10)pfVar6[7];
      fVar11 = (float10)fcos(fVar10);
      pfVar5[7] = (float)(fVar9 * (float10)*pfVar6 * fVar11);
      fVar12 = (float10)fcos(fVar10 * (float10)_DAT_004441a8);
      pfVar5[8] = (float)(fVar9 * (float10)fVar8 * fVar12);
      fVar10 = (float10)fcos(fVar10 * (float10)_DAT_004441a4);
      pfVar5[9] = (float)(fVar9 * (float10)fVar1 * fVar10);
      fr08_408ea3((double)(fVar9 * (float10)fVar2 * (float10)(double)fVar11),
                  (double)(fVar9 * (float10)fVar3 * (float10)(double)fVar12),
                  (double)(fVar9 * (float10)fVar4 * fVar10));
    }
  }
  return;
}

