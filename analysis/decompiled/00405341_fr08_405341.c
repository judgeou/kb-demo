// Original FR08 function at 00405341

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall fr08_405341(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  int *piVar10;
  bool bVar11;
  float10 fVar12;
  float10 fVar13;
  int local_24;
  uint uStack_20;
  int local_18;
  int local_14;
  int local_10;
  float local_c;
  float local_8;
  
  fr08_40831a();
  local_18 = 0;
  if (0 < param_1[7]) {
    local_14 = 0;
    do {
      piVar10 = (int *)(local_14 + param_1[0xf]);
      fr08_408d27();
      pfVar8 = (float *)param_1[0xd];
      local_10 = 0;
      if (0 < *param_1) {
        pfVar9 = pfVar8 + 4;
        do {
          local_8 = 3.587324e-43;
          fVar13 = (float10)1;
          local_c = 1.0;
          if (*piVar10 != 1) {
            if (*piVar10 == 2) {
              local_8 = -((float)piVar10[5] * *pfVar9 +
                         pfVar9[-1] * (float)piVar10[4] + pfVar9[1] * (float)piVar10[6]);
            }
            else {
              fVar1 = *pfVar8;
              fVar2 = (float)piVar10[7];
              fVar3 = pfVar9[-3];
              fVar4 = (float)piVar10[8];
              fVar5 = pfVar9[-2];
              fVar6 = (float)piVar10[9];
              fVar12 = (float10)fr08_408d06();
              if (fVar12 <= (float10)(float)piVar10[0xd]) {
                local_c = (float)(((float10)(float)piVar10[0xd] - fVar12) /
                                 (float10)(float)piVar10[0xd]);
              }
              else {
                local_c = 0.0;
              }
              fr08_408d27();
              local_8 = -((fVar3 - fVar4) * *pfVar9 +
                         (fVar1 - fVar2) * pfVar9[-1] + (fVar5 - fVar6) * pfVar9[1]);
              if (*piVar10 == 4) {
                fVar1 = (fVar1 - fVar2) * (float)piVar10[4] +
                        (fVar3 - fVar4) * (float)piVar10[5] + (fVar5 - fVar6) * (float)piVar10[6];
                if ((float)piVar10[0xc] <= fVar1) {
                  fVar13 = (float10)fr08_40a031((double)((fVar1 - (float)piVar10[0xc]) /
                                                        (1.0 - (float)piVar10[0xc])),
                                                (double)(float)piVar10[10]);
                }
                else {
                  fVar13 = (float10)0;
                }
              }
              else {
                fVar13 = (float10)(float)fVar13;
              }
            }
            if (local_8 < _DAT_004440e8) {
              local_8 = 0.0;
            }
            local_24 = (int)(longlong)
                            ROUND((float10)local_c * (float10)(float)piVar10[0xb] * fVar13 *
                                  (float10)local_8 * (float10)_DAT_00444148);
            local_8 = (float)local_24;
          }
          fVar1 = (float)(int)local_8;
          uStack_20 = (uint)*(byte *)((int)pfVar9 + 10);
          local_24 = (int)(longlong)ROUND(fVar1 * (float)piVar10[1] + (float)uStack_20);
          bVar11 = local_24 < 0;
          local_8 = (float)local_24;
          uStack_20 = (uint)*(byte *)((int)pfVar9 + 9);
          local_24 = (int)(longlong)ROUND(fVar1 * (float)piVar10[2] + (float)uStack_20);
          iVar7 = local_24;
          local_c = (float)local_24;
          uStack_20 = (uint)*(byte *)(pfVar9 + 2);
          local_24 = (int)(longlong)ROUND(fVar1 * (float)piVar10[3] + (float)uStack_20);
          if (bVar11) {
            local_8 = 0.0;
          }
          if (iVar7 < 0) {
            local_c = 0.0;
          }
          if (local_24 < 0) {
            local_24 = 0;
          }
          if (0xff < (int)local_8) {
            local_8 = 3.573311e-43;
          }
          if ((int)local_c < 0x100) {
          }
          else {
            local_c._0_1_ = 0xff;
          }
          if (0xff < local_24) {
            local_24 = 0xff;
          }
          *(char *)(pfVar9 + 2) = (char)local_24;
          *(char *)((int)pfVar9 + 0xb) = (char)local_24;
          *(undefined *)((int)pfVar9 + 9) = local_c._0_1_;
          *(undefined *)((int)pfVar9 + 10) = local_8._0_1_;
          pfVar8 = pfVar8 + 0xb;
          pfVar9 = pfVar9 + 0xb;
          local_10 = local_10 + 1;
        } while (local_10 < *param_1);
      }
      local_18 = local_18 + 1;
      local_14 = local_14 + 0x38;
    } while (local_18 < param_1[7]);
  }
  param_1[7] = 0;
  return;
}

