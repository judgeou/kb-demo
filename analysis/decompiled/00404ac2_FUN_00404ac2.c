// Original FR08 function at 00404ac2

void FUN_00404ac2(float **param_1)

{
  float *pfVar1;
  int *piVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  int *piVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int *piVar14;
  undefined4 local_2c;
  int *local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  local_10 = (int *)0x0;
  if (param_1[4] != (float *)0x0) {
    param_1[4] = (float *)0x0;
    (*(code *)param_1[1][6])(param_1[1]);
    pfVar1 = param_1[9];
    piVar2 = (int *)param_1[1][9];
    uVar10 = (uint)param_1[7] & 0xf0;
    if (uVar10 == 0) {
      iVar7 = 0;
      if (0 < *piVar2) {
        puVar9 = &DAT_00583c5c;
        do {
          *puVar9 = 0xffffffff;
          iVar7 = iVar7 + 1;
          puVar9 = puVar9 + 1;
        } while (iVar7 < *piVar2);
      }
      piVar6 = (int *)piVar2[0xe];
      param_1 = (float **)0x0;
      local_8 = 0;
      if (0 < piVar2[1]) {
        do {
          if (*(char *)((int)piVar6 + 0x1a) == '\0') {
            param_1 = (float **)((int)param_1 + 1);
            local_24 = (int *)0x3;
            piVar11 = piVar6;
            do {
              if ((&DAT_00583c5c)[*piVar11] == -1) {
                (&DAT_00583c5c)[*piVar11] = local_10;
                local_10 = (int *)((int)local_10 + 1);
              }
              piVar11 = piVar11 + 1;
              local_24 = (int *)((int)local_24 + -1);
            } while (local_24 != (int *)0x0);
          }
          piVar6 = piVar6 + 7;
          local_8 = local_8 + 1;
        } while (local_8 < piVar2[1]);
      }
      fr08_408005(local_10,param_1,piVar2[6],piVar2[2],0);
      puVar9 = (undefined4 *)piVar2[0xf];
      puVar8 = (undefined4 *)pfVar1[0xf];
      for (uVar10 = (uint)(piVar2[7] * 0x38) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar8 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined *)puVar8 = *(undefined *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      puVar9 = (undefined4 *)piVar2[0x10];
      puVar8 = (undefined4 *)pfVar1[0x10];
      for (uVar10 = (uint)(piVar2[2] * 0x28) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar8 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined *)puVar8 = *(undefined *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      *(undefined *)(pfVar1 + 0x13) = *(undefined *)(piVar2 + 0x13);
      pfVar1[7] = (float)piVar2[7];
      iVar7 = 0;
      if (0 < *piVar2) {
        param_1 = (float **)0x0;
        local_18 = &DAT_00583c5c;
        do {
          if (*local_18 != -1) {
            puVar9 = (undefined4 *)(piVar2[0xd] + (int)param_1);
            puVar8 = (undefined4 *)(*local_18 * 0x2c + (int)pfVar1[0xd]);
            for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar8 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar8 = puVar8 + 1;
            }
          }
          param_1 = (float **)((int)param_1 + 0x2c);
          local_18 = local_18 + 1;
          iVar7 = iVar7 + 1;
        } while (iVar7 < *piVar2);
      }
      local_14 = (int *)piVar2[0xe];
      local_18 = (int *)0x0;
      local_10 = (int *)pfVar1[0xe];
      local_24 = (int *)piVar2[0x10];
      pfVar1[2] = 0.0;
      piVar6 = (int *)pfVar1[0x10];
      local_c = 0;
      if (0 < piVar2[2]) {
        do {
          local_20 = 0;
          bVar4 = false;
          local_8 = 0;
          local_1c = 0x2ee1;
          piVar11 = local_24;
          piVar14 = piVar6;
          for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
            *piVar14 = *piVar11;
            piVar11 = piVar11 + 1;
            piVar14 = piVar14 + 1;
          }
          piVar6[2] = (int)local_18;
          if (0 < piVar6[3]) {
            do {
              if (*(char *)((int)local_14 + 0x1a) == '\0') {
                bVar4 = true;
                piVar11 = local_14;
                piVar14 = local_10;
                for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
                  *piVar14 = *piVar11;
                  piVar11 = piVar11 + 1;
                  piVar14 = piVar14 + 1;
                }
                iVar7 = 3;
                piVar11 = local_10;
                do {
                  iVar5 = (&DAT_00583c5c)[*(int *)(((int)local_14 - (int)local_10) + (int)piVar11)];
                  *piVar11 = iVar5;
                  if (iVar5 < local_1c) {
                    local_1c = iVar5;
                  }
                  if (local_20 < iVar5) {
                    local_20 = iVar5;
                  }
                  piVar11 = piVar11 + 1;
                  iVar7 = iVar7 + -1;
                } while (iVar7 != 0);
                local_10 = local_10 + 7;
                local_18 = (int *)((int)local_18 + 1);
              }
              local_14 = local_14 + 7;
              local_8 = local_8 + 1;
            } while (local_8 < piVar6[3]);
          }
          *piVar6 = local_1c;
          piVar6[1] = (local_20 - local_1c) + 1;
          piVar6[3] = (int)local_18 - piVar6[2];
          if (bVar4) {
            piVar6 = piVar6 + 10;
            pfVar1[2] = (float)((int)pfVar1[2] + 1);
          }
          local_24 = local_24 + 10;
          local_c = local_c + 1;
        } while (local_c < piVar2[2]);
      }
    }
    else if (uVar10 == 0x20) {
      puVar9 = (undefined4 *)piVar2[0x10];
      local_c = 1;
      local_8 = 1;
      puVar8 = puVar9;
      if (1 < piVar2[2]) {
        do {
          if (((puVar8[0xf] == puVar8[5]) && (puVar8[0xe] == puVar8[4])) &&
             (puVar8[0x10] == puVar8[6])) {
            puVar9[3] = puVar9[3] + puVar8[0xd];
            puVar9[1] = puVar9[1] + puVar8[0xb];
          }
          else {
            puVar9 = puVar9 + 10;
            local_c = local_c + 1;
            puVar12 = puVar8 + 10;
            puVar13 = puVar9;
            for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar13 = *puVar12;
              puVar12 = puVar12 + 1;
              puVar13 = puVar13 + 1;
            }
          }
          local_8 = local_8 + 1;
          puVar8 = puVar8 + 10;
        } while (local_8 < piVar2[2]);
      }
      piVar2[2] = local_c;
    }
    else if (uVar10 == 0x30) {
      iVar7 = 0;
      if (0 < (int)pfVar1[2]) {
        iVar5 = 0;
        do {
          iVar7 = iVar7 + 1;
          *(uint *)(iVar5 + 0x24 + (int)pfVar1[0x10]) = (uint)param_1[7] & 3;
          iVar5 = iVar5 + 0x28;
        } while (iVar7 < (int)pfVar1[2]);
      }
    }
    else if (uVar10 == 0x40) {
      local_2c = (undefined4)(longlong)ROUND(**param_1);
      fr08_4084ab(piVar2,param_1[1],param_1[10] + ((uint)param_1[7] & 0xf) * 0x40,local_2c);
      param_1[4] = (float *)0x0;
    }
    else if (uVar10 == 0x50) {
      fr08_408005(0,0,0,0,1);
      *(int **)pfVar1[0x11] = piVar2;
      fVar3 = pfVar1[0x11];
      *(undefined4 *)((int)fVar3 + 4) = 0;
      *(undefined4 *)((int)fVar3 + 8) = 0;
      *(undefined4 *)((int)fVar3 + 0xc) = 0;
      fr08_408e20();
      piVar2[0xb] = (int)**param_1;
    }
    else if ((*(byte *)((int)pfVar1[8] + 0x14) & 2) == 0) {
      fr08_408268(piVar2);
    }
    else {
      fr08_408005(0,0,0,0,1);
      *(int **)pfVar1[0x11] = piVar2;
      fVar3 = pfVar1[0x11];
      *(undefined4 *)((int)fVar3 + 4) = 0;
      *(undefined4 *)((int)fVar3 + 8) = 0;
      *(undefined4 *)((int)fVar3 + 0xc) = 0;
      fr08_408e20();
    }
  }
  return;
}

