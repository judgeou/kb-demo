// Original FR08 function at 00403b0b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403b0b(int *param_1)

{
  float *pfVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  float *pfVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  char cVar12;
  float10 fVar13;
  undefined local_118 [40];
  undefined4 local_f0 [10];
  undefined4 local_c8 [10];
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  uint local_88;
  undefined8 local_84;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  uint local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float fStack_1c;
  float *local_18;
  float local_14;
  float local_10;
  float local_c;
  float *local_8;
  
  if (param_1[4] == 0) {
    return;
  }
  param_1[4] = 0;
  (**(code **)(param_1[1] + 0x18))(param_1[1]);
  local_88 = param_1[7];
  uVar6 = local_88 & 3;
  uVar9 = local_88 & 0xe0;
  fStack_1c = (float)(local_88 & 3);
  local_64 = local_88 & 0xf0;
  if (local_64 == 0x30) {
    iVar7 = *param_1;
    local_70 = *(float *)(iVar7 + 0x24);
    local_6c = *(float *)(iVar7 + 0x28);
    local_68 = *(float *)(iVar7 + 0x2c);
    local_7c = *(float *)(iVar7 + 0x30);
    local_78 = *(float *)(iVar7 + 0x34);
    local_74 = *(float *)(iVar7 + 0x38);
  }
  else if (uVar9 == 0x40) {
    fr08_404107(param_1,9,local_118,&local_a0);
  }
  fr08_404107(param_1,0,local_c8,&local_2c);
  uVar2 = param_1[5];
  piVar3 = (int *)param_1[9];
  if ((uVar2 & 2) != 0) {
    uVar4 = *(undefined4 *)(param_1[1] + 0x24);
    if ((uVar2 & 1) != 0) {
      fr08_408005(0,0,0,0,1);
      *(undefined4 *)piVar3[0x11] = uVar4;
      puVar8 = local_c8;
      puVar10 = (undefined4 *)(piVar3[0x11] + 0x10);
      for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      iVar7 = piVar3[0x11];
      *(float *)(iVar7 + 4) = local_2c;
      *(float *)(iVar7 + 8) = local_28;
      *(float *)(iVar7 + 0xc) = local_24;
      return;
    }
    param_1 = (int *)0x0;
    if (piVar3[3] < 1) {
      return;
    }
    local_8 = (float *)0x0;
    do {
      puVar8 = (undefined4 *)(piVar3[0x11] + 0x10 + (int)local_8);
      puVar10 = local_f0;
      for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      fr08_408f2c(local_f0,local_c8);
      iVar7 = (int)local_8;
      fr08_408d82();
      param_1 = (int *)((int)param_1 + 1);
      pfVar5 = (float *)(piVar3[0x11] + 4 + iVar7);
      local_8 = (float *)(iVar7 + 0x38);
      *pfVar5 = local_2c + *(float *)(piVar3[0x11] + 4 + iVar7);
      pfVar5[1] = local_28 + pfVar5[1];
      pfVar5[2] = local_24 + pfVar5[2];
    } while ((int)param_1 < piVar3[3]);
    return;
  }
  if ((uVar2 & 1) != 0) {
    fr08_408268();
  }
  if (uVar9 == 0x40) {
    pfVar5 = (float *)(piVar3[0xd] + 4);
    local_3c = *pfVar5;
    local_8 = (float *)local_3c;
    if (*piVar3 < 2) goto LAB_00403d4b;
    iVar7 = *piVar3 + -1;
    do {
      pfVar1 = pfVar5 + 0xb;
      pfVar5 = pfVar5 + 0xb;
      if ((float)local_8 < *pfVar1) {
        local_8 = (float *)*pfVar5;
      }
      if (*pfVar5 < local_3c) {
        local_3c = *pfVar5;
      }
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  iVar7 = 0;
  if (uVar9 == 0) {
    iVar11 = 0;
    fStack_1c = 0.0;
    if (0 < piVar3[2]) {
      do {
        *(int *)(piVar3[0x10] + 0x10 + iVar7) = param_1[10];
        *(uint *)(piVar3[0x10] + 0x14 + iVar7) = (uint)(byte)(&DAT_0052a350)[param_1[10]];
        if ((float)_DAT_00444140 < *(float *)(*param_1 + 0x24)) {
          local_84 = (ulonglong)ROUND(*(float *)(*param_1 + 0x24));
          *(undefined4 *)(piVar3[0x10] + 0x14 + iVar7) = (undefined4)local_84;
        }
        *(uint *)(piVar3[0x10] + 0x18 + iVar7) = uVar6;
        *(undefined4 *)(piVar3[0x10] + 0x24 + iVar7) = 0;
        iVar11 = iVar11 + 1;
        iVar7 = iVar7 + 0x28;
      } while (iVar11 < piVar3[2]);
    }
  }
LAB_00403d4b:
  pfVar5 = (float *)piVar3[0xd];
  param_1 = (int *)0x0;
  local_18 = pfVar5;
  if (0 < *piVar3) {
    local_84 = CONCAT44(fStack_1c,(undefined4)local_84) & 0x3ffffffff;
    do {
      local_18 = pfVar5;
      if (local_84._4_4_ == 1) {
        cVar12 = *(char *)(pfVar5 + 9);
LAB_00403d7c:
        if (cVar12 != '\0') goto LAB_00403d84;
        goto LAB_00403f2f;
      }
      if (local_84._4_4_ == 2) {
        cVar12 = *(char *)(pfVar5 + 9) == '\0';
        goto LAB_00403d7c;
      }
LAB_00403d84:
      if (local_64 == 0) {
        local_14 = pfVar5[7];
        local_10 = pfVar5[8];
        local_c = 0.0;
LAB_00403fc0:
        fr08_408d82();
        local_14 = local_2c + local_14;
        local_10 = local_28 + local_10;
        local_c = local_24 + local_c;
        if ((local_88 & 8) != 0) {
          local_14 = local_14 - (float)(int)(longlong)ROUND(local_14);
          local_20 = (float)(longlong)ROUND(local_10);
          fStack_1c = local_20;
          local_10 = local_10 - (float)(int)local_20;
        }
        pfVar5[7] = local_14;
        pfVar5[8] = local_10;
        local_18 = pfVar5;
      }
      else {
        if (local_64 == 0x10) {
          local_14 = *pfVar5;
          local_10 = pfVar5[1];
          local_c = pfVar5[2];
          goto LAB_00403fc0;
        }
        if (local_64 == 0x20) {
          local_14 = *pfVar5;
          local_10 = pfVar5[1];
          local_c = pfVar5[2];
          fr08_408d82();
          local_14 = local_2c + local_14;
          local_10 = local_28 + local_10;
          local_c = local_24 + local_c;
          *local_18 = local_14;
          local_18[1] = local_10;
          local_18[2] = local_c;
        }
        else if (local_64 == 0x30) {
          local_14 = *pfVar5 - local_70;
          local_10 = pfVar5[1] - local_6c;
          local_c = pfVar5[2] - local_68;
          local_94 = local_14 / local_7c;
          local_90 = local_10 / local_78;
          local_8c = local_c / local_74;
          fVar13 = (float10)fr08_408d06();
          fStack_1c = (float)fVar13;
          if (fVar13 < (float10)_DAT_004440ec) {
            fr08_408d82();
            local_14 = local_2c + local_14 + local_70;
            local_10 = local_28 + local_10 + local_6c;
            local_c = local_24 + local_c + local_68;
            fr08_4040e8((double)fStack_1c);
            pfVar5 = &local_14;
            goto LAB_00403f27;
          }
        }
        else if (local_64 == 0x40) {
          local_60 = *pfVar5;
          local_5c = pfVar5[1];
          local_58 = pfVar5[2];
          local_54 = local_60;
          local_50 = local_5c;
          local_4c = local_58;
          fr08_408d82();
          local_60 = local_60 + local_2c;
          local_5c = local_5c + local_28;
          local_58 = local_58 + local_24;
          fr08_408d82();
          local_54 = local_a0 + local_54;
          local_50 = local_50 + local_9c;
          local_4c = local_4c + local_98;
          fStack_1c = (local_18[1] - (float)local_8) / (local_3c - (float)local_8);
          *local_18 = 0.0;
          local_18[1] = 0.0;
          local_18[2] = 0.0;
          fr08_4038f6(&local_60,(double)fStack_1c);
          pfVar5 = &local_54;
LAB_00403f27:
          fr08_4038f6(pfVar5,(double)(1.0 - fStack_1c));
        }
      }
LAB_00403f2f:
      pfVar5 = local_18 + 0xb;
      param_1 = (int *)((int)param_1 + 1);
      local_18 = pfVar5;
    } while ((int)param_1 < *piVar3);
  }
  if (local_64 == 0x20) {
    param_1 = (int *)0x0;
    if (0 < piVar3[7]) {
      pfVar5 = (float *)(piVar3[0xf] + 0x14);
      do {
        local_48 = pfVar5[2];
        local_44 = pfVar5[3];
        local_40 = pfVar5[4];
        local_38 = pfVar5[2] + pfVar5[-1];
        local_34 = pfVar5[3] + *pfVar5;
        local_30 = pfVar5[1] + pfVar5[4];
        local_8 = pfVar5;
        fr08_408d82();
        fr08_408d82();
        param_1 = (int *)((int)param_1 + 1);
        local_8[2] = local_48 + local_2c;
        local_8[3] = local_44 + local_28;
        local_8[4] = local_40 + local_24;
        local_8[-1] = (local_38 + local_2c) - (local_48 + local_2c);
        *local_8 = (local_34 + local_28) - (local_44 + local_28);
        pfVar5 = local_8 + 0xe;
        local_8[1] = (local_30 + local_24) - (local_40 + local_24);
      } while ((int)param_1 < piVar3[7]);
    }
  }
  return;
}

