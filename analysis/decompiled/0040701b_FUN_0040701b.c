// Original FR08 function at 0040701b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040701b(float **param_1)

{
  undefined *puVar1;
  float *pfVar2;
  float fVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  uint uVar15;
  float **ppfVar16;
  int iVar17;
  byte bVar18;
  int iVar19;
  undefined *puVar20;
  byte *pbVar21;
  int iVar22;
  int iVar23;
  float10 fVar24;
  float10 fVar25;
  uint local_60;
  byte *local_38;
  uint local_34;
  int local_24;
  int local_1c;
  int local_14;
  byte *local_10;
  uint local_c;
  uint local_8;
  
  ppfVar16 = param_1;
  if (param_1[4] != (float *)0x0) {
    param_1[4] = (float *)0x0;
    fr08_409e00(1);
    (*(code *)param_1[1][6])(param_1[1]);
    pfVar2 = param_1[9];
    fVar3 = param_1[1][9];
    if ((*(byte *)(param_1 + 7) & 1) != 0) {
      (*(code *)param_1[2][6])();
      local_38 = (byte *)param_1[2][9];
    }
    pbVar21 = local_38;
    pfVar4 = param_1[7];
    if (pfVar4 == (float *)0x0) {
      pfVar4 = *param_1;
      puVar20 = (undefined *)((int)pfVar2 + 2);
      local_14 = 0x100;
      fVar24 = (float10)pfVar4[1] * (float10)_DAT_0044410c;
      fVar25 = (float10)fcos((float10)*pfVar4);
      local_1c = (int)(longlong)ROUND(fVar24 * fVar25);
      fVar25 = (float10)fsin((float10)*pfVar4);
      local_60 = (uint)(longlong)ROUND(pfVar4[2] * _DAT_004441d0);
      local_c = local_60;
      local_60 = (uint)(longlong)ROUND(pfVar4[3] * _DAT_004441d0);
      local_34 = local_60;
      do {
        iVar23 = 0x100;
        local_8 = local_c;
        param_1 = (float **)local_34;
        do {
          uVar15 = local_8 >> 0x10;
          local_8 = local_8 + local_1c;
          puVar1 = (undefined *)
                   ((int)fVar3 + (((uint)param_1 >> 0x10 & 0xff) * 0x100 + (uVar15 & 0xff)) * 4);
          puVar20[-2] = *puVar1;
          puVar20[-1] = puVar1[1];
          *puVar20 = puVar1[2];
          param_1 = (float **)((int)param_1 + (int)(longlong)ROUND(fVar24 * fVar25));
          puVar20 = puVar20 + 4;
          iVar23 = iVar23 + -1;
        } while (iVar23 != 0);
        local_34 = local_34 + local_1c;
        local_c = local_c + (int)(longlong)ROUND(-fVar24 * fVar25);
        local_14 = local_14 + -1;
      } while (local_14 != 0);
    }
    else if (pfVar4 == (float *)0x1) {
      pfVar4 = *param_1;
      puVar20 = (undefined *)((int)pfVar2 + 2);
      local_14 = 0;
      local_1c = (int)(longlong)ROUND(*pfVar4 * _DAT_0044410c);
      iVar23 = local_1c;
      local_1c = (int)(longlong)ROUND(pfVar4[1] * _DAT_0044410c);
      iVar17 = local_1c;
      local_1c = (int)(longlong)ROUND(pfVar4[2]);
      fVar5 = pfVar4[3];
      do {
        param_1 = (float **)0x0;
        local_24 = 0;
        local_10 = local_38;
        do {
          iVar19 = ((uint)*local_10 - (uint)local_38[(local_1c + (int)param_1 & 0xffU) * 4]) *
                   iVar23 + local_24;
          local_24 = local_24 + 0x10000;
          iVar22 = (iVar19 / 0x10000 & 0xffU) +
                   ((int)(((uint)*local_10 -
                          (uint)local_10[(int)(pbVar21 +
                                              (((int)(longlong)ROUND(fVar5) + local_14 & 0xffU) *
                                               0x400 - (int)local_38))]) * iVar17 +
                         local_14 * 0x10000) / 0x10000 & 0xffU) * 0x100;
          iVar19 = (int)fVar3 + iVar22 * 4;
          puVar20[-2] = *(undefined *)((int)fVar3 + iVar22 * 4);
          puVar20[-1] = *(undefined *)(iVar19 + 1);
          *puVar20 = *(undefined *)(iVar19 + 2);
          puVar20 = puVar20 + 4;
          param_1 = (float **)((int)param_1 + 1);
          local_10 = local_10 + 4;
        } while (local_24 < 0x1000000);
        local_38 = local_38 + 0x400;
        local_14 = local_14 + 1;
      } while (local_14 < 0x100);
    }
    else if ((1 < (int)pfVar4) && ((int)pfVar4 < 4)) {
      pfVar2 = *param_1;
      local_1c = (int)(longlong)ROUND(*pfVar2 * _DAT_00444148);
      iVar23 = local_1c;
      local_1c = (int)(longlong)ROUND(pfVar2[1] * _DAT_00444148);
      iVar17 = local_1c;
      local_1c = (int)(longlong)ROUND(pfVar2[2] * _DAT_00444148);
      fVar5 = pfVar2[5];
      fVar6 = pfVar2[7];
      fVar10 = pfVar2[3] * _DAT_004441d8;
      fVar11 = pfVar2[4] * _DAT_004441d8;
      fr08_405e3b();
      fr08_405e3b();
      fVar13 = (float)_DAT_00444128 / SQRT(fVar10 * fVar10 + fVar11 * fVar11 + _DAT_0044410c);
      fVar12 = fVar13 * _DAT_00444148;
      fVar7 = (float)local_1c;
      local_10 = local_38;
      iVar19 = 0;
      do {
        param_1 = (float **)0x0;
        pbVar21 = local_10 + ((int)fVar3 - (int)local_38);
        iVar22 = iVar19 + 1;
        fVar8 = (float)(iVar19 - iVar17);
        do {
          fVar9 = (float)((int)param_1 - iVar23);
          fVar14 = (float)_DAT_00444128 / SQRT(fVar9 * fVar9 + fVar8 * fVar8 + fVar7 * fVar7);
          fVar9 = fVar9 * fVar14 * fVar13 * fVar10 +
                  fVar8 * fVar14 * fVar13 * fVar11 + fVar7 * fVar14 * fVar12;
          if (ppfVar16[7] == (float *)0x3) {
            fr08_405e21();
          }
          if (fVar5 <= fVar9) {
            fr08_40a031((double)((fVar9 - fVar5) / (1.0 - fVar5)),(double)fVar6);
          }
          fr08_405e21();
          bVar18 = fr08_405e21();
          pbVar21[2] = bVar18;
          bVar18 = fr08_405e21();
          pbVar21[1] = bVar18;
          bVar18 = fr08_405e21();
          *pbVar21 = bVar18;
          pbVar21 = pbVar21 + 4;
          param_1 = (float **)((int)param_1 + 1);
        } while ((int)param_1 < 0x100);
        local_10 = local_10 + 0x400;
        iVar19 = iVar22;
      } while (iVar22 < 0x100);
    }
  }
  return;
}

