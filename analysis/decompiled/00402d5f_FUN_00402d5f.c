// Original FR08 function at 00402d5f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402d5f(float **param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float **ppfVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  float *pfVar14;
  uint uVar15;
  char *pcVar16;
  float *pfVar17;
  int iVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  undefined4 local_60;
  float local_5c;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  undefined8 local_4c;
  float local_34;
  float *local_30;
  int local_2c;
  uint local_28;
  float *local_24;
  float local_20;
  char *local_1c;
  int local_18;
  int local_14;
  int local_10;
  float local_c;
  int local_8;
  
  ppfVar9 = param_1;
  if (param_1[4] == (float *)0x0) {
    return;
  }
  pfVar14 = param_1[7];
  pfVar5 = param_1[9];
  local_70 = 0.0;
  local_6c = 0.0;
  local_c = (float)((uint)pfVar14 & 1);
  local_68 = 0.0;
  uVar15 = 1 - (int)local_c;
  local_64 = 0.0;
  param_1[4] = (float *)0x0;
  local_60 = 0;
  uVar12 = (uint)pfVar14 & 0xf0;
  local_5c = 0.0;
  local_58 = 0;
  local_54 = 0.0;
  local_50 = 0;
  if (uVar12 == 0) {
    pfVar14 = *param_1;
    local_4c._0_4_ = (int)(longlong)ROUND(*pfVar14 + _DAT_004440ec);
    param_1 = (float **)(int)local_4c;
    local_4c._0_4_ = (int)(longlong)ROUND(pfVar14[1] + _DAT_004440ec);
    iVar13 = (int)local_4c;
    local_4c = (longlong)ROUND(pfVar14[2] + _DAT_004440ec);
    local_8 = (int)local_4c;
    if ((int)param_1 < 2) {
      param_1 = (float **)2;
    }
    if (iVar13 < 2) {
      iVar13 = 2;
    }
    if ((int)local_4c < 2) {
      local_8 = 2;
    }
    fr08_408005(((iVar13 + (int)param_1) * local_8 + iVar13 * (int)param_1) * 2,
                (iVar13 * 4 + -4) * (local_8 + -1) + ((int)param_1 * 4 + -4) * (iVar13 + -1) +
                (local_8 * 4 + -4) * ((int)param_1 + -1),0,1,0);
    local_70 = _DAT_00444124;
    local_68 = _DAT_00444124;
    local_6c = 0.5;
    local_64 = 1.0;
    local_60 = 0;
    local_5c = 0.0;
    local_58 = 0;
    local_50 = 0;
    local_54 = -1.0;
    fr08_403620(pfVar5,param_1,iVar13,3,&local_70,&local_64,&local_58,uVar15,3);
    local_64 = 0.0;
    local_54 = -1.0;
    local_60 = 0;
    local_5c = 1.0;
    local_58 = 0;
    local_50 = 0;
    fr08_403620(pfVar5,local_8,iVar13,3,&local_70,&local_64,&local_58,local_c,3);
    local_64 = 1.0;
    local_60 = 0;
    local_5c = 0.0;
    local_58 = 0;
    local_54 = 0.0;
    local_50 = 0x3f800000;
    fr08_403620(pfVar5,param_1,local_8,3,&local_70,&local_64,&local_58,local_c,3);
    local_70 = _DAT_004440f0;
    local_6c = _DAT_004440f0;
    local_68 = _DAT_004440f0;
    local_64 = _DAT_00444120;
    local_60 = 0;
    local_5c = 0.0;
    local_58 = 0;
    local_54 = _DAT_00444120;
    local_50 = 0;
    fr08_403620(pfVar5,param_1,iVar13,3,&local_70,&local_64,&local_58,uVar15,3);
    local_64 = 0.0;
    local_60 = 0;
    local_5c = _DAT_00444120;
    local_58 = 0;
    local_54 = _DAT_00444120;
    local_50 = 0;
    fr08_403620(pfVar5,local_8,iVar13,3,&local_70,&local_64,&local_58,local_c,3);
    local_70 = _DAT_00444124;
    local_6c = _DAT_00444124;
    local_68 = _DAT_00444124;
    local_64 = 1.0;
    local_60 = 0;
    uVar20 = 3;
    local_5c = 0.0;
    local_58 = 0;
    local_54 = 0.0;
    uVar19 = 3;
    local_50 = 0x3f800000;
    iVar13 = local_8;
  }
  else if (uVar12 == 0x10) {
    local_24 = *param_1;
    local_4c._0_4_ = (int)(longlong)ROUND(*local_24);
    param_1 = (float **)(int)local_4c;
    local_4c = (longlong)ROUND(local_24[1]);
    if ((int)param_1 < 3) {
      param_1 = (float **)0x3;
    }
    iVar13 = (int)local_4c;
    if ((int)local_4c < 2) {
      iVar13 = 2;
    }
    local_54 = local_24[3];
    local_64 = local_24[2];
    if (((uint)pfVar14 & 2) == 0) {
      if (((uint)pfVar14 & 4) == 0) {
        fr08_408005((iVar13 + 2) * (int)param_1,iVar13 * (int)param_1 * 2 + -4,0,1,0);
        fr08_403620(pfVar5,param_1,iVar13,2,&local_70,&local_64,&local_58,uVar15,2);
        fr08_403620(pfVar5,param_1,1,2,&local_70,&local_64,&local_58,local_c,2);
        uVar20 = 2;
      }
      else {
        iVar18 = (int)param_1 + 1;
        fr08_408005((iVar13 + 2) * iVar18 + -2,
                    ((int)param_1 + -1 + iVar18) * (iVar13 + -1) + -6 + iVar18 * 2,0,1,0);
        fr08_403620(pfVar5,iVar18,iVar13,2,&local_70,&local_64,&local_58,uVar15,3);
        fr08_403620(pfVar5,param_1,1,2,&local_70,&local_64,&local_58,local_c,3);
        uVar20 = 3;
      }
      local_54 = 0.0;
      iVar13 = 1;
    }
    else if (((uint)pfVar14 & 4) == 0) {
      fr08_408005(iVar13 * (int)param_1,(iVar13 + -1) * (int)param_1 * 2,0,1,0);
      uVar20 = 2;
    }
    else {
      iVar18 = (int)param_1 + 1;
      fr08_408005(iVar13 * iVar18,((int)param_1 + -1 + iVar18) * (iVar13 + -1),0,1,0);
      uVar20 = 3;
      param_1 = (float **)iVar18;
    }
    uVar19 = 2;
  }
  else if (uVar12 == 0x20) {
    pfVar14 = *param_1;
    local_4c._0_4_ = (int)(longlong)ROUND(*pfVar14);
    iVar13 = (int)local_4c;
    param_1 = (float **)(int)local_4c;
    local_4c = (longlong)ROUND(pfVar14[1]);
    if (iVar13 < 3) {
      param_1 = (float **)0x3;
    }
    iVar13 = (int)local_4c;
    if ((int)local_4c < 2) {
      iVar13 = 2;
    }
    local_64 = pfVar14[2];
    fr08_408005(iVar13 * (int)param_1,(iVar13 + -1) * (int)param_1 * 2,0,1,0);
    uVar20 = 6;
    uVar19 = 6;
    uVar15 = (uint)local_c;
  }
  else if (uVar12 == 0x30) {
    local_24 = *param_1;
    local_4c._0_4_ = (int)(longlong)ROUND(*local_24);
    param_1 = (float **)(int)local_4c;
    local_4c = (longlong)ROUND(local_24[1]);
    if ((int)param_1 < 3) {
      param_1 = (float **)0x3;
    }
    iVar13 = (int)local_4c;
    if ((int)local_4c < 3) {
      iVar13 = 3;
    }
    local_64 = local_24[2];
    local_54 = local_24[3];
    if (((uint)pfVar14 & 4) == 0) {
      fr08_408005(iVar13 * (int)param_1,iVar13 * (int)param_1 * 2,0,1,0);
      uVar20 = 0;
    }
    else {
      iVar18 = (int)param_1 + 1;
      fr08_408005((iVar13 + 1) * iVar18,((int)param_1 + -1 + iVar18) * iVar13,0,1,0);
      uVar20 = 3;
      iVar13 = iVar13 + 1;
      param_1 = (float **)iVar18;
    }
    uVar19 = 0;
  }
  else {
    if (uVar12 != 0x60) {
      if (uVar12 != 0x70) {
        return;
      }
      pfVar17 = *param_1;
      local_34 = *pfVar17;
      local_24 = (float *)pfVar17[1];
      local_4c._0_4_ = (int)(longlong)ROUND(pfVar17[2]);
      param_1 = (float **)(int)local_4c;
      if ((int)local_4c < 1) {
        param_1 = (float **)0x1;
      }
      if (0x20 < (int)param_1) {
        param_1 = (float **)0x20;
      }
      local_4c._0_4_ = (int)(longlong)ROUND(pfVar17[3]);
      local_8 = (int)local_4c;
      if ((int)local_4c < 1) {
        local_8 = 1;
      }
      if (0x20 < local_8) {
        local_8 = 0x20;
      }
      local_1c = (char *)(&DAT_0058345c)[(int)ppfVar9[10]];
      local_28 = (uint)pfVar14 & 3;
      if (*local_1c == '@') {
        local_1c = s__4sie_sahen_den_neuen__farbrausc_00442333 + 2;
      }
      local_10 = 0;
      for (pcVar16 = local_1c; *pcVar16 != '\0'; pcVar16 = pcVar16 + 1) {
        if ((*pcVar16 != '\n') && (*pcVar16 != '\r')) {
          local_10 = local_10 + 1;
        }
      }
      local_4c._4_4_ = ((int)param_1 + 1) * (local_8 + 1);
      fr08_408005(local_4c._4_4_ * local_10,
                  ((-(uint)(((uint)pfVar14 & 4) != 0) & 2) + 2) * local_10 * local_8 * (int)param_1,
                  0,1,0);
      pfVar14 = (float *)pfVar5[0xd];
      piVar11 = (int *)pfVar5[0xe];
      local_c = 0.0;
      fVar8 = 0.0;
      pfVar17 = pfVar14;
      local_30 = pfVar14;
      if ((*(byte *)(ppfVar9 + 7) & 8) != 0) {
        fVar8 = (float)local_24 * _DAT_004440f0;
      }
      do {
        cVar4 = *local_1c;
        if (cVar4 != '\r') {
          if ((cVar4 == '\n') || (cVar4 == '\0')) {
            if (((*(byte *)(ppfVar9 + 7) & 8) != 0) && (pfVar14 < pfVar17)) {
              fVar1 = local_20 * _DAT_004440f0;
              do {
                *pfVar14 = *pfVar14 - fVar1;
                pfVar14 = pfVar14 + 0xb;
              } while (pfVar14 < pfVar17);
            }
            local_c = 0.0;
            fVar8 = fVar8 - (float)local_24;
            pfVar14 = pfVar17;
            local_30 = pfVar17;
            if (*local_1c == '\0') {
              local_28 = 0;
              if (0 < local_10) {
                local_20 = (float)local_10;
                do {
                  if (0 < local_8) {
                    local_2c = local_8;
                    local_24 = (float *)local_28;
                    do {
                      if (0 < (int)param_1) {
                        local_30 = (float *)param_1;
                        local_1c = (char *)local_24;
                        piVar10 = piVar11;
                        iVar13 = (int)local_24;
                        do {
                          iVar13 = iVar13 + 1;
                          piVar10[2] = iVar13;
                          *piVar10 = (int)local_1c;
                          iVar18 = (int)param_1 + iVar13;
                          piVar10[1] = iVar18;
                          piVar10[7] = iVar13;
                          piVar10[8] = iVar18;
                          piVar10[9] = (int)param_1 + 1 + iVar13;
                          piVar11 = piVar10 + 0xe;
                          if ((*(byte *)(ppfVar9 + 7) & 4) != 0) {
                            piVar10[0xf] = iVar13;
                            *piVar11 = (int)local_1c;
                            piVar10[0x10] = iVar18;
                            piVar10[0x15] = iVar13;
                            piVar10[0x16] = (int)param_1 + 1 + iVar13;
                            piVar10[0x17] = iVar18;
                            piVar11 = piVar10 + 0x1c;
                          }
                          local_1c = (char *)((int)local_1c + 1);
                          local_30 = (float *)((int)local_30 + -1);
                          piVar10 = piVar11;
                        } while (local_30 != (float *)0x0);
                      }
                      local_24 = (float *)((int)local_24 + (int)param_1 + 1);
                      local_2c = local_2c + -1;
                    } while (local_2c != 0);
                  }
                  local_28 = local_28 + local_4c._4_4_;
                  local_20 = (float)((int)local_20 + -1);
                } while (local_20 != 0.0);
              }
              pfVar5[5] = pfVar5[1];
              pfVar5[4] = *pfVar5;
              return;
            }
          }
          else {
            local_18 = 0;
            iVar13 = *(int *)(&DAT_004e62e0 + (local_28 * 0x100 + (int)cVar4) * 4) + local_28 * 0x40
            ;
            fVar1 = *(float *)(&DAT_004e4ae4 + iVar13 * 0x18);
            fVar2 = *(float *)(&DAT_004e4ae8 + iVar13 * 0x18);
            fVar3 = *(float *)(&DAT_004e4af0 + iVar13 * 0x18);
            fVar6 = *(float *)(&DAT_004e4aec + iVar13 * 0x18);
            local_20 = local_34 * *(float *)(&DAT_004e4af4 + iVar13 * 0x18) + local_c;
            if (local_8 != -1 && -1 < local_8 + 1) {
              do {
                local_14 = 0;
                if (0 < (int)param_1 + 1) {
                  pfVar14 = pfVar17;
                  do {
                    fVar7 = (float)local_14;
                    pfVar14[6] = -NAN;
                    pfVar14[1] = (((fVar8 + (float)local_24) - fVar8) * (float)local_18) /
                                 (float)local_8 + fVar8;
                    *pfVar14 = (fVar7 * (local_20 - local_c)) / (float)(int)param_1 + local_c;
                    pfVar14[2] = 0.0;
                    pfVar17 = pfVar14 + 0xb;
                    local_14 = local_14 + 1;
                    pfVar14[7] = ((fVar6 - fVar1) * fVar7) / (float)(int)param_1 + fVar1;
                    pfVar14[8] = ((fVar2 - fVar3) * (float)local_18) / (float)local_8 + fVar3;
                    pfVar14 = pfVar17;
                  } while (local_14 < (int)param_1 + 1);
                }
                local_18 = local_18 + 1;
              } while (local_18 < local_8 + 1);
            }
            local_c = local_20 + (*ppfVar9)[4];
            pfVar14 = local_30;
          }
        }
        local_1c = local_1c + 1;
      } while( true );
    }
    pfVar14 = *param_1;
    local_4c._0_4_ = (int)(longlong)ROUND(*pfVar14 + _DAT_004440ec);
    param_1 = (float **)(int)local_4c;
    iVar18 = (int)local_4c * 2;
    local_4c = (longlong)ROUND(pfVar14[1] + _DAT_004440ec);
    iVar13 = (int)local_4c;
    fr08_408005((int)local_4c * (int)param_1,(iVar18 + -2) * ((int)local_4c + -1),0,1,0);
    uVar20 = 3;
    local_70 = _DAT_00444124;
    local_6c = 0.0;
    local_68 = _DAT_00444124;
    local_64 = 1.0;
    uVar19 = 3;
    local_60 = 0;
    local_5c = 0.0;
    local_58 = 0;
    local_54 = 0.0;
    local_50 = 0x3f800000;
    uVar15 = (uint)local_c;
  }
  fr08_403620(pfVar5,param_1,iVar13,uVar19,&local_70,&local_64,&local_58,uVar15,uVar20);
  return;
}

