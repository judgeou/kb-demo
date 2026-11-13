// Original FR08 function at 004041e8

void FUN_004041e8(int *param_1)

{
  int *piVar1;
  uint uVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  float *pfVar8;
  int *piVar9;
  int *piVar10;
  undefined4 *puVar11;
  float *pfVar12;
  int *piVar13;
  undefined4 local_e0 [10];
  undefined local_b8 [40];
  undefined4 local_90 [10];
  undefined8 local_68;
  undefined4 *local_60;
  int *local_5c;
  int *local_58;
  float local_54;
  float local_50;
  float local_4c;
  int *local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  int *local_2c;
  int local_28;
  int local_24;
  int local_20;
  float *local_1c;
  int local_18;
  float local_14;
  float local_10;
  float local_c;
  float *local_8;
  
  if (param_1[4] != 0) {
    param_1[4] = 0;
    (**(code **)(param_1[1] + 0x18))(param_1[1]);
    local_28 = param_1[9];
    piVar1 = *(int **)(param_1[1] + 0x24);
    uVar2 = param_1[7];
    local_68 = (ulonglong)ROUND(*(float *)(*param_1 + 0x24));
    local_18 = (int)local_68;
    fr08_404107(param_1,0,local_b8,&local_54);
    iVar6 = local_28;
    local_68 = CONCAT44(uVar2,(int)local_68) & 0x4ffffffff;
    if ((uVar2 & 4) != 0) {
      local_18 = local_18 + 1;
    }
    if ((*(byte *)(param_1 + 5) & 2) == 0) {
      fr08_408005(*piVar1 * local_18,piVar1[1] * local_18,piVar1[7] * local_18,piVar1[2] * local_18,
                  0);
      local_8 = *(float **)(iVar6 + 0x34);
      local_48 = *(int **)(iVar6 + 0x38);
      local_14 = 0.0;
      local_5c = *(int **)(iVar6 + 0x40);
      local_10 = 0.0;
      local_20 = 0;
      local_c = 0.0;
      fr08_408e20();
      local_24 = 0;
      if (0 < local_18) {
        do {
          local_58 = (int *)piVar1[0xe];
          local_2c = (int *)piVar1[0x10];
          if (local_68._4_4_ == 0) {
            param_1 = (int *)0x0;
            pfVar4 = (float *)piVar1[0xd];
            if (0 < *piVar1) {
              do {
                pfVar12 = local_8;
                local_1c = pfVar4 + 0xb;
                pfVar8 = local_8;
                for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
                  *pfVar8 = *pfVar4;
                  pfVar4 = pfVar4 + 1;
                  pfVar8 = pfVar8 + 1;
                }
                fr08_408d82(local_90);
                *pfVar12 = local_14 + *pfVar12;
                param_1 = (int *)((int)param_1 + 1);
                local_8 = pfVar12 + 0xb;
                pfVar12[1] = local_10 + pfVar12[1];
                pfVar12[2] = local_c + pfVar12[2];
                pfVar4 = local_1c;
              } while ((int)param_1 < *piVar1);
            }
            param_1 = (int *)0x0;
            if (0 < piVar1[7]) {
              local_1c = (float *)0x0;
              do {
                puVar7 = (undefined4 *)((int)local_1c + piVar1[0xf]);
                local_60 = (undefined4 *)fr08_4081fd();
                puVar11 = local_60;
                for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
                  *puVar11 = *puVar7;
                  puVar7 = puVar7 + 1;
                  puVar11 = puVar11 + 1;
                }
                local_38 = (float)local_60[7];
                local_34 = (float)local_60[8];
                local_30 = (float)local_60[9];
                local_44 = local_38 + (float)local_60[4];
                local_40 = local_34 + (float)local_60[5];
                local_3c = local_30 + (float)local_60[6];
                fr08_408d82(local_90);
                local_38 = local_38 + local_14;
                local_34 = local_34 + local_10;
                local_30 = local_30 + local_c;
                fr08_408d82(local_90);
                local_44 = local_44 + local_14;
                param_1 = (int *)((int)param_1 + 1);
                local_1c = local_1c + 0xe;
                local_40 = local_40 + local_10;
                local_3c = local_3c + local_c;
                local_60[7] = local_38;
                local_60[8] = local_34;
                local_60[9] = local_30;
                local_60[4] = local_44 - local_38;
                local_60[5] = local_40 - local_34;
                local_60[6] = local_3c - local_30;
              } while ((int)param_1 < piVar1[7]);
            }
            local_14 = local_54 + local_14;
            fVar3 = local_10 + local_50;
            puVar7 = local_90;
            puVar11 = local_e0;
            for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
              *puVar11 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar11 = puVar11 + 1;
            }
            local_c = local_c + local_4c;
            local_10 = fVar3;
            fr08_408f2c(local_b8,local_e0);
            fr08_408d82(local_b8);
          }
          else if (local_24 == 0) {
            iVar6 = 0;
            pfVar4 = (float *)piVar1[0xd];
            if (0 < *piVar1) {
              do {
                pfVar12 = local_8;
                local_8 = local_8 + 0xb;
                iVar6 = iVar6 + 1;
                pfVar8 = pfVar4;
                for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
                  *pfVar12 = *pfVar8;
                  pfVar8 = pfVar8 + 1;
                  pfVar12 = pfVar12 + 1;
                }
                pfVar4 = pfVar4 + 0xb;
              } while (iVar6 < *piVar1);
            }
          }
          else {
            param_1 = (int *)0x0;
            pfVar4 = local_8 + *piVar1 * -0xb;
            if (0 < *piVar1) {
              do {
                pfVar12 = local_8;
                local_1c = pfVar4 + 0xb;
                pfVar8 = local_8;
                for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
                  *pfVar8 = *pfVar4;
                  pfVar4 = pfVar4 + 1;
                  pfVar8 = pfVar8 + 1;
                }
                fr08_408d82(local_b8);
                *pfVar12 = local_54 + *pfVar12;
                param_1 = (int *)((int)param_1 + 1);
                local_8 = pfVar12 + 0xb;
                pfVar12[1] = local_50 + pfVar12[1];
                pfVar12[2] = local_4c + pfVar12[2];
                pfVar4 = local_1c;
              } while ((int)param_1 < *piVar1);
            }
          }
          iVar6 = 0;
          if (0 < piVar1[1]) {
            do {
              piVar9 = local_58;
              piVar10 = local_48;
              for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
                *piVar10 = *piVar9;
                piVar9 = piVar9 + 1;
                piVar10 = piVar10 + 1;
              }
              *local_48 = *local_48 + local_20;
              local_48[1] = local_48[1] + local_20;
              local_48[2] = local_48[2] + local_20;
              iVar6 = iVar6 + 1;
              local_48 = local_48 + 7;
              local_58 = local_58 + 7;
            } while (iVar6 < piVar1[1]);
          }
          iVar6 = 0;
          if (0 < piVar1[2]) {
            do {
              piVar9 = local_5c;
              piVar10 = local_2c;
              piVar13 = local_5c;
              for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
                *piVar13 = *piVar10;
                piVar10 = piVar10 + 1;
                piVar13 = piVar13 + 1;
              }
              *local_5c = *piVar1 * local_24 + *local_2c;
              iVar6 = iVar6 + 1;
              local_5c = local_5c + 10;
              piVar9[2] = piVar1[1] * local_24 + local_2c[2];
              local_2c = local_2c + 10;
            } while (iVar6 < piVar1[2]);
          }
          local_20 = local_20 + *piVar1;
          local_24 = local_24 + 1;
        } while (local_24 < local_18);
      }
    }
    else {
      local_14 = 0.0;
      local_10 = 0.0;
      local_c = 0.0;
      fr08_408e20();
      iVar6 = local_28;
      fr08_408005(0,0,0,0,local_18);
      if (0 < local_18) {
        local_20 = local_18;
        param_1 = (int *)0x0;
        do {
          *(int **)(*(int *)(iVar6 + 0x44) + (int)param_1) = piVar1;
          puVar7 = local_90;
          puVar11 = (undefined4 *)(*(int *)(iVar6 + 0x44) + 0x10 + (int)param_1);
          for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar11 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar11 = puVar11 + 1;
          }
          pfVar4 = (float *)(*(int *)(local_28 + 0x44) + 4 + (int)param_1);
          *pfVar4 = local_14;
          pfVar4[1] = local_10;
          pfVar4[2] = local_c;
          local_14 = local_54 + local_14;
          fVar3 = local_10 + local_50;
          puVar7 = local_90;
          puVar11 = local_e0;
          for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar11 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar11 = puVar11 + 1;
          }
          local_c = local_c + local_4c;
          local_10 = fVar3;
          fr08_408f2c(local_b8,local_e0);
          fr08_408d82(local_b8);
          param_1 = (int *)((int)param_1 + 0x38);
          local_20 = local_20 + -1;
          iVar6 = local_28;
        } while (local_20 != 0);
      }
    }
  }
  return;
}

