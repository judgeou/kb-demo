// Original FR08 function at 00404647

void FUN_00404647(float **param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  float *pfVar13;
  float *pfVar14;
  undefined4 *puVar15;
  int *piVar16;
  int *piVar17;
  undefined4 *puVar18;
  int *piVar19;
  undefined auStack_8c [40];
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float local_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float local_2c;
  float local_28;
  int iStack_24;
  float *local_20;
  float *local_1c;
  int *piStack_18;
  int *local_14;
  float *local_10;
  int *piStack_c;
  int local_8;
  
  if (param_1[4] != (float *)0x0) {
    param_1[4] = (float *)0x0;
    (*(code *)param_1[1][6])(param_1[1]);
    local_20 = param_1[9];
    piVar17 = (int *)param_1[1][9];
    local_10 = param_1[7];
    if (piVar17[2] == 1) {
      iVar4 = 0;
      if (0 < *piVar17) {
        iVar8 = 0;
        do {
          *(undefined *)(iVar8 + 0x25 + piVar17[0xd]) = 0;
          iVar4 = iVar4 + 1;
          iVar8 = iVar8 + 0x2c;
        } while (iVar4 < *piVar17);
      }
      local_14 = (int *)piVar17[0xe];
      local_8 = 0;
      local_30 = 0.0;
      local_2c = 0.0;
      local_28 = 0.0;
      if (0 < piVar17[1]) {
        do {
          if (*(char *)((int)local_14 + 0x1a) == '\0') {
            bVar7 = 1;
            piVar5 = local_14;
          }
          else {
            pfVar13 = (float *)(*local_14 * 0x2c + piVar17[0xd]);
            local_1c = (float *)0x2;
            pfVar14 = (float *)(local_14[1] * 0x2c + piVar17[0xd]);
            fStack_3c = *pfVar14;
            fStack_38 = pfVar14[1];
            fStack_34 = pfVar14[2];
            local_48 = *pfVar13 - fStack_3c;
            pfVar14 = (float *)(local_14[2] * 0x2c + piVar17[0xd]);
            fStack_44 = pfVar13[1] - fStack_38;
            fStack_40 = pfVar13[2] - fStack_34;
            fStack_54 = *pfVar14 - fStack_3c;
            fStack_50 = pfVar14[1] - fStack_38;
            fStack_4c = pfVar14[2] - fStack_34;
            fr08_408d27();
            fr08_408d27();
            fr08_404a89(&fStack_54,&local_48);
            fr08_408d27();
            local_30 = fStack_3c + local_30;
            local_2c = local_2c + fStack_38;
            local_28 = local_28 + fStack_34;
            piVar5 = local_14;
            bVar7 = (byte)local_1c;
          }
          pbVar1 = (byte *)(*piVar5 * 0x2c + 0x25 + piVar17[0xd]);
          *pbVar1 = *pbVar1 | bVar7;
          local_14 = piVar5 + 7;
          pbVar1 = (byte *)(piVar5[1] * 0x2c + 0x25 + piVar17[0xd]);
          *pbVar1 = *pbVar1 | bVar7;
          pbVar1 = (byte *)(piVar5[2] * 0x2c + 0x25 + piVar17[0xd]);
          *pbVar1 = *pbVar1 | bVar7;
          local_8 = local_8 + 1;
        } while (local_8 < piVar17[1]);
      }
      if (((uint)local_10 & 0x10) == 0) {
        fr08_404107(param_1,0,auStack_8c,&fStack_64);
      }
      else {
        fr08_408e20();
        fr08_408d27();
        fr08_4040e8((double)**param_1);
        fStack_64 = local_30;
        fStack_60 = local_2c;
        fStack_5c = local_28;
      }
      pfVar13 = local_20;
      iVar4 = *piVar17;
      local_8 = 0;
      if (0 < iVar4) {
        piVar5 = (int *)(piVar17[0xd] + 0x28);
        iVar8 = iVar4;
        do {
          if (*(char *)((int)piVar5 + -3) == '\x03') {
            iVar11 = local_8 + iVar4;
            local_8 = local_8 + 1;
            *piVar5 = iVar11;
          }
          else {
            *piVar5 = -1;
          }
          piVar5 = piVar5 + 0xb;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      local_1c = (float *)piVar17[1];
      local_14 = (int *)piVar17[0xe];
      piStack_18 = (int *)0x0;
      pfVar14 = local_1c;
      if (0 < (int)local_1c) {
        do {
          local_10 = pfVar14;
          if (*(char *)((int)local_14 + 0x1a) != '\0') {
            iVar8 = piVar17[0xd];
            param_1 = (float **)0x0;
            piStack_c = local_14;
            do {
              if ((*(int *)(*piStack_c * 0x2c + 0x28 + iVar8) != -1) &&
                 (iVar8 = piVar17[0xd],
                 *(int *)(local_14[((int)param_1 + 1) % 3] * 0x2c + 0x28 + iVar8) != -1)) {
                piStack_18 = (int *)((int)piStack_18 + 2);
              }
              param_1 = (float **)((int)param_1 + 1);
              piStack_c = piStack_c + 1;
            } while ((int)param_1 < 3);
          }
          local_14 = local_14 + 7;
          local_10 = (float *)((int)local_10 + -1);
          pfVar14 = local_10;
        } while (local_10 != (float *)0x0);
      }
      iStack_24 = iVar4;
      fr08_408005(local_8 + iVar4,(int)piStack_18 + (int)local_1c,0,1,0);
      pfVar14 = local_20;
      puVar12 = (undefined4 *)piVar17[0xd];
      puVar6 = (undefined4 *)pfVar13[0xd];
      for (uVar9 = (uint)(iVar4 * 0x2c) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar6 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined *)puVar6 = *(undefined *)puVar12;
        puVar12 = (undefined4 *)((int)puVar12 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      local_10 = (float *)((int)local_1c * 0x1c);
      puVar12 = (undefined4 *)piVar17[0xe];
      puVar6 = (undefined4 *)local_20[0xe];
      for (uVar9 = (uint)local_10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar6 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined *)puVar6 = *(undefined *)puVar12;
        puVar12 = (undefined4 *)((int)puVar12 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      puVar12 = (undefined4 *)local_20[0xd];
      puVar6 = puVar12 + iVar4 * 0xb;
      if (0 < iStack_24) {
        param_1 = (float **)iStack_24;
        do {
          if (*(char *)((int)puVar12 + 0x25) == '\x03') {
            puVar15 = puVar12;
            puVar18 = puVar6;
            for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar18 = *puVar15;
              puVar15 = puVar15 + 1;
              puVar18 = puVar18 + 1;
            }
            puVar6 = puVar6 + 0xb;
            *(undefined *)((int)puVar12 + 0x25) = 1;
          }
          puVar12 = puVar12 + 0xb;
          param_1 = (float **)((int)param_1 + -1);
        } while (param_1 != (float **)0x0);
      }
      pfVar13 = (float *)local_20[0xd];
      iVar4 = 0;
      if (0 < (int)*local_20) {
        do {
          if ((*(byte *)((int)pfVar13 + 0x25) & 2) != 0) {
            fr08_408d82();
            *pfVar13 = fStack_64 + *pfVar13;
            pfVar13[1] = fStack_60 + pfVar13[1];
            pfVar13[2] = fStack_5c + pfVar13[2];
          }
          *(undefined *)((int)pfVar13 + 0x25) = 0;
          pfVar13 = pfVar13 + 0xb;
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)*pfVar14);
      }
      piVar5 = (int *)pfVar14[0xe];
      piVar17 = (int *)((int)piVar5 + (int)local_10);
      if (0 < (int)local_1c) {
        local_8 = 0;
        local_20 = local_1c;
        piStack_18 = piVar17;
        do {
          if (*(char *)((int)piVar5 + 0x1a) != '\0') {
            iVar4 = 0;
            param_1 = (float **)piVar5;
            do {
              iVar4 = iVar4 + 1;
              iVar8 = (int)*param_1;
              iVar11 = *(int *)(iVar8 * 0x2c + 0x28 + (int)pfVar14[0xd]);
              iVar2 = piVar5[iVar4 % 3];
              iVar3 = *(int *)(iVar2 * 0x2c + 0x28 + (int)pfVar14[0xd]);
              if ((iVar11 != -1) && (iVar3 != -1)) {
                *(undefined *)((int)piVar17 + 0x1a) = 0;
                piVar16 = piVar17;
                piVar19 = piVar17 + 7;
                for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
                  *piVar19 = *piVar16;
                  piVar16 = piVar16 + 1;
                  piVar19 = piVar19 + 1;
                }
                piStack_18[1] = iVar2;
                *piStack_18 = iVar8;
                piStack_18[2] = iVar3;
                piVar17[7] = iVar8;
                piStack_18[8] = iVar3;
                piStack_18[9] = iVar11;
                piVar17 = piStack_18 + 0xe;
                piStack_18 = piVar17;
              }
              param_1 = param_1 + 1;
            } while (iVar4 < 3);
            param_1 = (float **)0x0;
            piStack_c = piVar5;
            do {
              iVar4 = *(int *)(*piStack_c * 0x2c + 0x28 + (int)pfVar14[0xd]);
              if (iVar4 != -1) {
                *(int *)((int)pfVar14[0xe] + (local_8 + (int)param_1) * 4) = iVar4;
              }
              param_1 = (float **)((int)param_1 + 1);
              piStack_c = piStack_c + 1;
            } while ((int)param_1 < 3);
          }
          local_8 = local_8 + 7;
          piVar5 = piVar5 + 7;
          local_20 = (float *)((int)local_20 + -1);
        } while (local_20 != (float *)0x0);
      }
      *(float *)((int)pfVar14[0x10] + 0xc) = pfVar14[1];
      *(float *)((int)pfVar14[0x10] + 4) = *pfVar14;
    }
  }
  return;
}

