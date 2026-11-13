// Original FR08 function at 0040500e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040500e(float **param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float *pfVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  undefined4 uVar16;
  undefined4 *puVar17;
  float10 fVar18;
  float10 fVar19;
  float10 fVar20;
  float10 fVar21;
  float10 fVar22;
  float10 fVar23;
  float10 fVar24;
  float10 fVar25;
  float10 fVar26;
  float10 fVar27;
  float10 fVar28;
  undefined local_14;
  int local_8;
  
  if (param_1[4] == (float *)0x0) {
    return;
  }
  param_1[4] = (float *)0x0;
  (*(code *)param_1[1][6])(param_1[1]);
  pfVar7 = param_1[9];
  if ((*(byte *)(param_1 + 5) & 1) != 0) {
    fr08_408268();
  }
  pfVar8 = param_1[7];
  if (pfVar8 != (float *)0x0) {
    if (pfVar8 == (float *)0x1) {
      fr08_405341();
      return;
    }
    if (pfVar8 == (float *)0x2) {
      pfVar8 = *param_1;
      fVar9 = *pfVar8 * _DAT_004441a0;
      fVar10 = pfVar8[1] * _DAT_004441a0;
      fVar11 = pfVar8[2] * _DAT_004441a0;
      fVar12 = pfVar8[3] * _DAT_004441a0;
      fVar13 = pfVar8[4] * _DAT_004441a0;
      fVar14 = pfVar8[5] * _DAT_004441a0;
      fVar1 = pfVar8[8];
      fVar2 = pfVar8[7];
      fVar3 = pfVar8[6];
      fr08_4040e8(_DAT_00444198);
      pfVar8 = *param_1;
      fVar15 = pfVar8[9] * _DAT_00444190;
      fVar4 = pfVar8[10];
      fVar5 = pfVar8[0xb];
      fVar6 = pfVar8[0xc];
      fr08_408ea3((double)pfVar8[0xd] * _DAT_00444118,(double)pfVar8[0xe] * _DAT_00444118,
                  (double)pfVar8[0xf] * _DAT_00444118);
      fr08_4040e8((double)fVar3);
      fr08_4040e8((double)fVar2);
      fr08_4040e8((double)fVar1);
      local_8 = 0;
      param_1 = (float **)pfVar7[0xd];
      if ((int)*pfVar7 < 1) {
        return;
      }
      do {
        fVar1 = (float)*param_1;
        fVar2 = fVar5 + (float)param_1[1];
        fVar3 = fVar6 + (float)param_1[2];
        fr08_408d82();
        fVar18 = (float10)_DAT_00444188;
        fVar19 = (float10)_DAT_00444180;
        fVar20 = (float10)_DAT_00444178;
        fVar21 = (float10)(fVar4 + fVar1);
        fVar22 = (float10)fsin((fVar21 - (float10)fVar3) * (float10)_DAT_00444174);
        fVar23 = (float10)fsin((fVar21 - (float10)fVar2) * (float10)_DAT_00444170);
        fVar24 = (float10)fsin(fVar21 * fVar19 * (float10)_DAT_00444164);
        fVar25 = (float10)fsin(((float10)fVar2 - (float10)fVar3) * (float10)_DAT_00444160);
        fVar26 = (float10)fsin((float10)fVar2 * fVar19 * (float10)_DAT_0044415c);
        fVar27 = (float10)fsin(((float10)fVar2 + fVar21) * (float10)_DAT_00444158);
        fVar28 = (float10)fsin(((float10)fVar3 + (float10)fVar2) * (float10)_DAT_00444154);
        fVar21 = (float10)fsin(((float10)fVar3 + fVar21) * (float10)_DAT_0044415c);
        fVar19 = (float10)fsin((float10)fVar3 * fVar19 * (float10)_DAT_00444150);
        fVar18 = (fVar19 * (float10)_DAT_00444168 + fVar21 * fVar18 + fVar28 * fVar20 +
                 fVar27 * fVar20 + (fVar26 + fVar25) * fVar18 +
                 fVar24 * fVar18 + fVar23 * (float10)_DAT_00444168 + fVar22 * fVar20) *
                 (float10)fVar15 + (float10)_DAT_0044414c;
        if (fVar18 < (float10)_DAT_004440e8) {
          fVar18 = (float10)0;
        }
        if ((float10)_DAT_004441a0 < fVar18) {
          fVar18 = (float10)_DAT_004441a0;
        }
        fVar19 = (float10)_DAT_00444148 - fVar18;
        fVar20 = (float10)_DAT_00444108;
        *(undefined *)((int)param_1 + 0x1b) = 0xff;
        local_8 = local_8 + 1;
        local_14 = (undefined)
                   (longlong)ROUND(((float10)fVar11 * fVar18 + fVar19 * (float10)fVar14) * fVar20);
        *(undefined *)(param_1 + 6) = local_14;
        local_14 = (undefined)
                   (longlong)ROUND(((float10)fVar10 * fVar18 + fVar19 * (float10)fVar13) * fVar20);
        *(undefined *)((int)param_1 + 0x19) = local_14;
        local_14 = (undefined)
                   (longlong)ROUND(((float10)fVar9 * fVar18 + fVar19 * (float10)fVar12) * fVar20);
        *(undefined *)((int)param_1 + 0x1a) = local_14;
        param_1 = param_1 + 0xb;
      } while (local_8 < (int)*pfVar7);
      return;
    }
    if (pfVar8 == (float *)0x3) {
      param_1 = (float **)0x0;
      if ((int)*pfVar7 < 1) {
        return;
      }
      puVar17 = (undefined4 *)((int)pfVar7[0xd] + 0x18);
      do {
        uVar16 = fr08_405e49();
        *puVar17 = uVar16;
        puVar17 = puVar17 + 0xb;
        param_1 = (float **)((int)param_1 + 1);
      } while ((int)param_1 < (int)*pfVar7);
      return;
    }
    if (pfVar8 != (float *)0x4) {
      return;
    }
  }
  param_1 = (float **)0x0;
  if (0 < (int)*pfVar7) {
    puVar17 = (undefined4 *)((int)pfVar7[0xd] + 0x18);
    do {
      uVar16 = fr08_405e3b();
      *puVar17 = uVar16;
      puVar17 = puVar17 + 0xb;
      param_1 = (float **)((int)param_1 + 1);
    } while ((int)param_1 < (int)*pfVar7);
  }
  return;
}

