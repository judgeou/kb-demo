// Original FR08 function at 00405a46

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00405a46(float **param_1)

{
  float *pfVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  float fVar8;
  float fVar9;
  float *pfVar10;
  float *pfVar11;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined8 local_28;
  float local_20;
  float local_1c;
  float local_18;
  float *local_14;
  uint local_10;
  float local_c;
  float local_8;
  
  if (param_1[4] != (float *)0x0) {
    param_1[4] = (float *)0x0;
    (*(code *)param_1[1][6])(param_1[1]);
    pfVar11 = param_1[9];
    local_14 = pfVar11;
    fr08_405dc0();
    fVar8 = param_1[1][9];
    pfVar11[0x19] = 1.401298e-45;
    pfVar11[0x1a] = fVar8;
    pfVar1 = param_1[7];
    local_18 = (float)((uint)pfVar1 & 3);
    local_10 = (int)pfVar1 >> 6 & 3;
    pfVar10 = *param_1;
    local_20 = (float)((int)pfVar1 >> 4 & 3);
    local_c = *pfVar10;
    local_28._0_4_ = (int)(longlong)ROUND(pfVar10[1]);
    iVar6 = (int)local_28;
    param_1 = (float **)(int)local_28;
    local_34 = pfVar10[2];
    local_30 = pfVar10[3];
    local_2c = pfVar10[4];
    local_1c = pfVar10[5];
    local_8 = DAT_005292f8;
    local_28 = CONCAT44(pfVar10[6],(int)local_28);
    if (DAT_005292f8 == _DAT_004440e8) {
      local_8 = 1.0;
    }
    if (local_10 != 0) {
      local_40 = _DAT_00529314 - local_34;
      local_3c = _DAT_00529318 - local_30;
      local_38 = _DAT_0052931c - local_2c;
      fr08_408dd1();
      if (((local_38 < _DAT_004441b4) && (_DAT_004441b0 < local_38)) &&
         (bVar2 = local_38 < _DAT_004440e8, local_38 = _DAT_004441b4, bVar2)) {
        local_38 = _DAT_004441b0;
      }
      local_34 = (local_40 * local_8) / local_38;
      local_30 = -((local_3c * local_8) / local_38);
      if (local_10 == 1) {
        local_2c = 1.0;
      }
      else {
        local_2c = (local_38 / local_8) * _DAT_004441ac;
        if (local_10 == 2) {
          fVar9 = local_34 - pfVar11[0x37c];
          local_48 = local_30 - pfVar11[0x37d];
          fVar8 = pfVar11[0x37e];
          pfVar11[0x37c] = local_34;
          pfVar11[0x37d] = local_30;
          pfVar11[0x37e] = local_2c;
          fr08_4040e8((double)((local_2c - fVar8) * local_1c));
          local_34 = local_34 - fVar9;
          local_30 = local_30 - local_48;
          pfVar11 = local_14;
        }
      }
    }
    fr08_4040e8((double)local_c);
    if (iVar6 < 1) {
      param_1 = (float **)1;
    }
    if (7 < (int)param_1) {
      param_1 = (float **)7;
    }
    local_8 = 0.0;
    local_1c = 1.0;
    if (0 < (int)param_1) {
      pfVar10 = pfVar11 + 0x4f;
      local_48 = 0.0;
      fVar8 = (float)((int)pfVar1 >> 2 & 3);
      do {
        fVar9 = fVar8;
        if (local_8 == (float)((int)param_1 + -1)) {
          fVar9 = local_20;
        }
        local_10 = 0;
        local_44 = local_1c;
        local_14 = &local_48;
        do {
          fr08_405d5c();
          pfVar7 = local_14;
          pfVar10[5] = (float)((-(uint)(local_10 != 0) & 2) + 1);
          *pfVar10 = fVar9;
          fVar5 = _DAT_004440f0;
          fVar8 = local_2c * *local_14;
          fVar3 = (local_34 * local_14[-2] - _DAT_004440f0) + fVar8 + _DAT_004440f0;
          fVar4 = ((local_34 * local_14[-2] + _DAT_004440f0) - fVar8) + _DAT_004440f0;
          pfVar1 = local_14 + -2;
          local_14 = (float *)((local_30 * *pfVar1 - _DAT_004440f0) + fVar8 + _DAT_004440f0);
          local_c = ((local_30 * *pfVar1 + _DAT_004440f0) - fVar8) + _DAT_004440f0;
          if (local_8 == (float)((int)param_1 + -1)) {
            fVar3 = fVar3 + local_28._4_4_;
            local_14 = (float *)((float)local_14 + local_28._4_4_);
            fVar4 = fVar4 - local_28._4_4_;
            local_c = local_c - local_28._4_4_;
          }
          pfVar10[-0x12] = fVar3;
          pfVar10[-0x11] = fVar4;
          pfVar10[-0x10] = fVar4;
          pfVar10[-0xf] = fVar3;
          pfVar10[-10] = (float)local_14;
          pfVar10[-9] = (float)local_14;
          pfVar10[-8] = local_c;
          pfVar10[-7] = local_c;
          pfVar10[-0x14] = local_18;
          pfVar10[-0x13] = 0.0;
          local_10 = local_10 + 1;
          pfVar10[-2] = -NAN;
          pfVar10 = pfVar10 + 0x1a;
          local_14 = pfVar7 + 1;
        } while ((int)local_10 < 2);
        local_8 = (float)((int)local_8 + 1);
        local_1c = local_1c * fVar5;
        fVar8 = local_18;
        local_18 = fVar9;
      } while ((int)local_8 < (int)param_1);
    }
    pfVar11[0x3a] = (float)((int)param_1 * 2);
  }
  return;
}

