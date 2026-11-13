// Original FR08 function at 004076ed

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_4076ed(int *param_1,int *param_2,char param_3)

{
  float fVar1;
  byte bVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  short *psVar9;
  float *pfVar10;
  short *psVar11;
  int iVar12;
  float *pfVar13;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  uint local_c;
  uint uStack_8;
  
  iVar3 = param_2[7];
  if (param_1[0xc] == 0) {
    iVar12 = param_2[1];
    pfVar10 = (float *)(*param_2 * 0x2c + param_1[0xd]);
    pfVar8 = *(float **)(iVar3 + 0x30);
    if (param_3 == '\0') {
      if (0 < iVar12) {
        do {
          *pfVar8 = *pfVar10;
          pfVar8[1] = pfVar10[1];
          pfVar8[2] = pfVar10[2];
          pfVar8[3] = pfVar10[3];
          pfVar8[4] = pfVar10[4];
          pfVar8[5] = pfVar10[5];
          pfVar8[6] = pfVar10[6];
          pfVar13 = pfVar10 + 8;
          pfVar8[7] = pfVar10[7];
          pfVar10 = pfVar10 + 0xb;
          pfVar8[8] = *pfVar13;
          pfVar8 = pfVar8 + 9;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
    }
    else {
      local_1c = *pfVar10;
      local_18 = pfVar10[1];
      local_14 = pfVar10[2];
      _param_3 = iVar12;
      local_10 = local_1c;
      fVar4 = local_18;
      fVar1 = local_14;
      if (0 < iVar12) {
        do {
          if (*pfVar10 < local_1c) {
            local_1c = *pfVar10;
          }
          if (local_10 < *pfVar10) {
            local_10 = *pfVar10;
          }
          pfVar13 = pfVar10 + 1;
          if (pfVar10[1] < local_18) {
            local_18 = *pfVar13;
          }
          if (fVar4 < *pfVar13) {
            fVar4 = *pfVar13;
          }
          if (pfVar10[2] < local_14) {
            local_14 = pfVar10[2];
          }
          if (fVar1 < pfVar10[2]) {
            fVar1 = pfVar10[2];
          }
          *pfVar8 = *pfVar10;
          pfVar8[1] = *pfVar13;
          pfVar8[2] = pfVar10[2];
          pfVar8[3] = pfVar10[3];
          pfVar8[4] = pfVar10[4];
          pfVar8[5] = pfVar10[5];
          pfVar8[6] = pfVar10[6];
          pfVar13 = pfVar10 + 8;
          pfVar8[7] = pfVar10[7];
          pfVar10 = pfVar10 + 0xb;
          pfVar8[8] = *pfVar13;
          pfVar8 = pfVar8 + 9;
          _param_3 = _param_3 + -1;
        } while (_param_3 != 0);
      }
      fVar5 = _DAT_004440f0;
      fVar6 = (local_1c + local_10) * _DAT_004440f0;
      *(float *)(iVar3 + 0x24) = fVar6;
      fVar7 = (local_18 + fVar4) * fVar5;
      *(float *)(iVar3 + 0x28) = fVar7;
      fVar5 = (local_14 + fVar1) * fVar5;
      *(float *)(iVar3 + 0x2c) = fVar5;
      local_10 = local_10 - fVar6;
      fVar4 = fVar4 - fVar7;
      fVar1 = fVar1 - fVar5;
      *(float *)(iVar3 + 0x20) = SQRT(local_10 * local_10 + fVar4 * fVar4 + fVar1 * fVar1);
    }
  }
  else {
    fVar1 = (float)param_1[0xb];
    if (fVar1 <= _DAT_004440e8) {
      fVar1 = 0.0;
    }
    iVar12 = param_1[0xc] + -1;
    local_c = (uint)(longlong)ROUND((float)iVar12 * fVar1 * _DAT_0044410c);
    fVar4 = (float)(local_c & 0xffff) * (float)_DAT_004441e0;
    fVar1 = 1.0 - fVar4;
    pfVar10 = (float *)(((((int)local_c / 0x10000) % iVar12) * *param_1 + *param_2) * 0x2c +
                       param_1[0x12]);
    _param_3 = param_2[1];
    pfVar8 = *(float **)(iVar3 + 0x30);
    pfVar13 = pfVar10 + *param_1 * 0xb;
    if (0 < _param_3) {
      do {
        *pfVar8 = fVar1 * *pfVar10 + fVar4 * *pfVar13;
        pfVar8[1] = fVar4 * pfVar13[1] + fVar1 * pfVar10[1];
        pfVar8[2] = fVar4 * pfVar13[2] + fVar1 * pfVar10[2];
        pfVar8[3] = fVar4 * pfVar13[3] + fVar1 * pfVar10[3];
        pfVar8[4] = fVar4 * pfVar13[4] + fVar1 * pfVar10[4];
        pfVar8[5] = fVar4 * pfVar13[5] + fVar1 * pfVar10[5];
        uStack_8 = (uint)*(byte *)(pfVar10 + 6);
        fVar5 = (float)uStack_8;
        uStack_8 = (uint)*(byte *)(pfVar13 + 6);
        local_c._0_1_ = (undefined)(longlong)ROUND((float)uStack_8 * fVar4 + fVar5 * fVar1);
        *(undefined *)(pfVar8 + 6) = (undefined)local_c;
        uStack_8 = (uint)*(byte *)((int)pfVar10 + 0x19);
        fVar5 = (float)uStack_8;
        uStack_8 = (uint)*(byte *)((int)pfVar13 + 0x19);
        local_c._0_1_ = (undefined)(longlong)ROUND((float)uStack_8 * fVar4 + fVar5 * fVar1);
        *(undefined *)((int)pfVar8 + 0x19) = (undefined)local_c;
        uStack_8 = (uint)*(byte *)((int)pfVar10 + 0x1a);
        fVar5 = (float)uStack_8;
        bVar2 = *(byte *)((int)pfVar13 + 0x1a);
        *(undefined *)((int)pfVar8 + 0x1b) = 0xff;
        uStack_8 = (uint)bVar2;
        local_c._0_1_ = (undefined)(longlong)ROUND((float)uStack_8 * fVar4 + fVar5 * fVar1);
        *(undefined *)((int)pfVar8 + 0x1a) = (undefined)local_c;
        pfVar8[7] = fVar4 * pfVar13[7] + fVar1 * pfVar10[7];
        pfVar8[8] = fVar4 * pfVar13[8] + fVar1 * pfVar10[8];
        pfVar8 = pfVar8 + 9;
        _param_3 = _param_3 + -1;
        pfVar10 = pfVar10 + 0xb;
        pfVar13 = pfVar13 + 0xb;
      } while (_param_3 != 0);
    }
  }
  iVar12 = param_2[3];
  psVar11 = *(short **)(iVar3 + 0x34);
  psVar9 = (short *)(param_2[2] * 0x1c + param_1[0xe]);
  if (0 < iVar12) {
    do {
      *psVar11 = (*psVar9 - *(short *)param_2) + *(short *)(iVar3 + 4);
      psVar11[1] = (psVar9[2] - *(short *)param_2) + *(short *)(iVar3 + 4);
      psVar11[2] = (psVar9[4] - *(short *)param_2) + *(short *)(iVar3 + 4);
      psVar11 = psVar11 + 3;
      iVar12 = iVar12 + -1;
      psVar9 = psVar9 + 0xe;
    } while (iVar12 != 0);
  }
  return;
}

