// Original FR08 function at 00401812

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 fr08_401812(int param_1,float *param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  float fVar4;
  float *pfVar5;
  uint uVar6;
  int iVar7;
  float *pfVar8;
  undefined4 *puVar9;
  float *pfVar10;
  undefined4 uVar11;
  float fVar12;
  float local_e8 [5];
  float local_d4;
  float local_c8;
  float local_c4;
  float local_c0;
  undefined4 local_bc;
  float local_b0;
  float local_a8 [10];
  undefined4 local_80 [4];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int *local_3c;
  float local_38;
  float local_34;
  float local_30;
  int *local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  float local_10;
  ulonglong local_c;
  
  pfVar5 = param_2;
  puVar9 = &DAT_004cbe70;
  for (iVar7 = 0x100; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = 0xffffffff;
    puVar9 = puVar9 + 1;
  }
  puVar9 = &DAT_004cc274;
  for (iVar7 = 0x100; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = 0xffffffff;
    puVar9 = puVar9 + 1;
  }
  DAT_004cb040 = 0xffffffff;
  DAT_004cb044 = 0xffffffff;
  DAT_004cb04c = 0xffffffff;
  DAT_004cb050 = 0xffffffff;
  if (param_1 == 0) {
    iVar7 = (**(code **)(*DAT_0049303c + 0x7c))(DAT_0049303c,DAT_00493038,DAT_004cc270);
    if (iVar7 < 0) {
      fr08_401000();
    }
    param_2 = (float *)0x320;
    local_14 = 600;
  }
  else {
    piVar3 = (int *)(&DAT_004cbe5c)[param_1];
    if (piVar3 == (int *)0x0) {
      DAT_004cb040 = 0xffffffff;
      DAT_004cb044 = 0xffffffff;
      DAT_004cb04c = 0xffffffff;
      DAT_004cb050 = 0xffffffff;
      return 0;
    }
    iVar7 = (**(code **)(*piVar3 + 0x3c))(piVar3,0,&local_3c);
    if (iVar7 < 0) {
      fr08_401000();
    }
    iVar7 = (**(code **)(*DAT_0049303c + 0x7c))(DAT_0049303c,local_3c,DAT_004cbe58);
    if (iVar7 < 0) {
      fr08_401000();
    }
    (**(code **)(*local_3c + 8))(local_3c);
    param_2[3] = 0.0;
    param_2 = (float *)0x200;
    local_14 = 0x200;
    pfVar5[4] = 0.0;
    pfVar5[5] = 1.0;
    pfVar5[6] = 1.0;
  }
  local_10 = (float)(int)param_2;
  local_c._0_4_ =
       (int *)(longlong)
              ROUND(((pfVar5[3] + _DAT_004440ec) * _DAT_004440f0 - pfVar5[5] * _DAT_004440f0) *
                    (float)(int)param_2);
  piVar3 = (int *)local_c;
  local_2c = (int *)local_c;
  fVar4 = (float)local_14;
  local_c._0_4_ =
       (int *)(longlong)
              ROUND(((pfVar5[4] + _DAT_004440ec) * _DAT_004440f0 - pfVar5[6] * _DAT_004440f0) *
                    fVar4);
  uVar6 = (uint)(int *)local_c;
  local_28 = (uint)(int *)local_c;
  local_c._0_4_ = (int *)(longlong)ROUND((float)(int)param_2 * pfVar5[5]);
  local_24 = (uint)(int *)local_c;
  uVar1 = (int)(int *)local_c + (int)piVar3;
  local_c._0_4_ = (int *)(longlong)ROUND(fVar4 * pfVar5[6]);
  local_c = CONCAT44(uVar1,(int *)local_c);
  local_1c = 0;
  local_18 = 0x3f800000;
  if ((-1 < (int)uVar1) && (uVar2 = (int)(int *)local_c + uVar6, -1 < (int)uVar2)) {
    if ((int)piVar3 < 0) {
      local_2c = (int *)0x0;
      local_24 = uVar1;
    }
    local_20 = (uint)(int *)local_c;
    if ((int)uVar6 < 0) {
      local_28 = 0;
      local_20 = uVar2;
    }
    if ((int)param_2 < (int)(local_24 + (int)local_2c)) {
      local_24 = (int)param_2 - (int)local_2c;
    }
    if (local_14 < (int)(local_20 + local_28)) {
      local_20 = local_14 - local_28;
    }
    if ((0 < (int)local_24) && (0 < (int)local_20)) {
      iVar7 = (**(code **)(*DAT_0049303c + 0xa0))(DAT_0049303c,&local_2c);
      if (iVar7 < 0) {
        fr08_401000();
      }
      if (pfVar5[0x15] != 0.0) {
        if (pfVar5[0x15] == 4.203895e-45) {
          fVar12 = -1.701412e+38;
          uVar11 = 3;
        }
        else {
          fVar12 = pfVar5[0x14];
          uVar11 = 2;
        }
        iVar7 = (**(code **)(*DAT_0049303c + 0x90))(DAT_0049303c,0,0,uVar11,fVar12,0x3f800000,0);
        if (iVar7 < 0) {
          fr08_401000();
        }
      }
      DAT_004ccaa4 = 0xffffffff;
      iVar7 = (**(code **)(*DAT_0049303c + 0x88))(DAT_0049303c);
      if (iVar7 < 0) {
        fr08_401000();
      }
      puVar9 = local_80;
      for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      local_70 = 0x3f800000;
      local_6c = 0x3f800000;
      local_68 = 0x3f800000;
      local_64 = 0x3f800000;
      local_80[0] = 0x3f800000;
      local_80[1] = 0x3f800000;
      local_80[2] = 0x3f800000;
      local_80[3] = 0x3f800000;
      local_60 = 0x3f800000;
      local_5c = 0x3f800000;
      local_58 = 0x3f800000;
      local_54 = 0x3f800000;
      (**(code **)(*DAT_0049303c + 0xa8))(DAT_0049303c,local_80);
      (**(code **)(*DAT_0049303c + 200))(DAT_0049303c,0x8b,0xffffffff);
      (**(code **)(*DAT_0049303c + 200))(DAT_0049303c,0x93,1);
      (**(code **)(*DAT_0049303c + 200))(DAT_0049303c,0x91,0);
      (**(code **)(*DAT_0049303c + 200))(DAT_0049303c,0x16,3);
      (**(code **)(*DAT_0049303c + 0x130))(DAT_0049303c,0x152);
      pfVar8 = pfVar5;
      pfVar10 = (float *)&DAT_004cca48;
      for (iVar7 = 0x16; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pfVar10 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pfVar10 = pfVar10 + 1;
      }
      pfVar8 = pfVar5 + 10;
      pfVar10 = local_a8;
      for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pfVar10 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pfVar10 = pfVar10 + 1;
      }
      fr08_409011();
      local_38 = pfVar5[7];
      local_34 = pfVar5[8];
      local_30 = pfVar5[9];
      fr08_401cbc();
      fr08_408d82(local_a8);
      fr08_4016ad(local_a8,&local_38,2);
      local_38 = 0.0;
      local_34 = 0.0;
      local_30 = 0.0;
      fr08_408e20();
      fr08_4016ad(local_a8,&local_38,0x10);
      fr08_4016ad(local_a8,&local_38,0x11);
      fVar12 = *pfVar5;
      pfVar8 = local_e8;
      for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pfVar8 = 0.0;
        pfVar8 = pfVar8 + 1;
      }
      if (fVar12 == _DAT_004440e8) {
        local_c = (ulonglong)local_24;
        local_c8 = (float)local_c;
        local_c = (ulonglong)local_20;
        local_e8[0] = (local_c8 / local_10) * pfVar5[5];
        param_2 = (float *)(float)local_c;
        local_d4 = ((float)param_2 / fVar4) * pfVar5[6];
      }
      else {
        local_c = (ulonglong)local_24;
        local_c8 = (float)local_c;
        local_c = (ulonglong)local_20;
        local_e8[0] = (*pfVar5 / (local_c8 / local_10)) * pfVar5[5];
        param_2 = (float *)(float)local_c;
        local_d4 = (local_10 * pfVar5[5] * (*pfVar5 / ((float)param_2 / fVar4)) * pfVar5[6]) /
                   (fVar4 * pfVar5[6]);
      }
      local_c = ZEXT48(local_2c);
      fVar12 = (float)local_c;
      local_c = (ulonglong)local_28;
      local_c8 = ((pfVar5[3] + _DAT_004440ec) * local_10 - (fVar12 + fVar12 + local_c8)) / local_c8;
      local_c4 = -(((pfVar5[4] + _DAT_004440ec) * fVar4 -
                   ((float)local_c + (float)local_c + (float)param_2)) / (float)param_2);
      local_c0 = pfVar5[1] / (pfVar5[1] - pfVar5[2]);
      local_bc = 0x3f800000;
      local_b0 = -(local_c0 * pfVar5[2]);
      (**(code **)(*DAT_0049303c + 0x94))(DAT_0049303c,3,local_e8);
      return 1;
    }
  }
  return 0;
}

