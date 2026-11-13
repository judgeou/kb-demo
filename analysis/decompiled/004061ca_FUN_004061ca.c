// Original FR08 function at 004061ca

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004061ca(float **param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  char cVar4;
  char *pcVar5;
  float fVar6;
  float fVar7;
  code *pcVar8;
  float fVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  float fVar13;
  int iVar14;
  float *pfVar15;
  undefined4 *puVar16;
  byte *pbVar17;
  float *pfVar18;
  undefined4 *puVar19;
  float10 fVar20;
  ushort uVar21;
  ushort uVar22;
  ushort uVar23;
  ushort uVar24;
  ushort uVar25;
  ushort uVar26;
  ushort uVar27;
  ushort uVar28;
  unkbyte10 in_ST3;
  unkbyte10 Var29;
  unkbyte10 in_ST4;
  unkbyte10 Var30;
  undefined4 local_e4 [14];
  undefined4 local_ac;
  undefined4 local_a8;
  uint local_a4;
  uint local_a0;
  undefined4 local_9c;
  undefined local_98;
  undefined local_97;
  undefined local_96;
  undefined local_95;
  undefined local_94;
  undefined local_93;
  undefined local_92;
  undefined local_91;
  undefined4 local_90 [8];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined2 local_64;
  undefined2 local_62;
  undefined4 local_60;
  uint local_44;
  float local_40;
  undefined8 local_3c;
  double local_34;
  undefined8 local_2c;
  float local_24;
  float *local_20;
  float *local_1c;
  undefined8 local_18;
  float local_10;
  int local_c;
  int local_8;
  
  if (param_1[4] != (float *)0x0) {
    param_1[4] = (float *)0x0;
    fr08_409e00(1);
    (*(code *)param_1[1][6])(param_1[1]);
    local_20 = param_1[9];
    local_24 = 9.18355e-41;
    local_1c = (float *)param_1[1][9];
    if (local_20 != local_1c) {
      pfVar15 = local_1c;
      pfVar18 = local_20;
      for (iVar14 = 0x10000; iVar14 != 0; iVar14 = iVar14 + -1) {
        *pfVar18 = *pfVar15;
        pfVar15 = pfVar15 + 1;
        pfVar18 = pfVar18 + 1;
      }
    }
    uVar10 = (uint)param_1[7] & 0xf;
    if (uVar10 == 0) {
      local_34 = (double)(longlong)ROUND(**param_1);
      iVar14 = local_34._0_4_;
      uVar11 = fr08_405e3b();
      local_18._0_4_ = uVar11;
      uVar11 = fr08_405e3b();
      local_2c = CONCAT44(local_2c._4_4_,uVar11);
      local_34 = (double)(longlong)ROUND((*param_1)[7]);
      fr08_409ffe();
      Var29 = CONCAT82(CONCAT71((int7)(((unkuint10)
                                        (uint6)(CONCAT55((int5)(((unkuint10)
                                                                 CONCAT31((int3)(((unkuint10)
                                                                                  (ushort)((
                                                  unkuint10)in_ST3 >> 0x40) << 0x40) >> 0x38),
                                                  (char)((uint)local_18 >> 0x18)) << 0x30) >> 0x28),
                                                  CONCAT14((char)((uint)local_18 >> 0x10),
                                                           (uint)local_18)) >> 0x20) << 0x20) >>
                                      0x18),(char)((uint)local_18 >> 8)),
                       (ushort)(byte)(uint)local_18);
      Var30 = CONCAT82(CONCAT71((int7)(((unkuint10)
                                        CONCAT51((int5)(((unkuint10)
                                                         CONCAT31((int3)(((unkuint10)
                                                                          (ushort)((unkuint10)in_ST4
                                                                                  >> 0x40) << 0x40)
                                                                        >> 0x38),
                                                                  (char)(local_2c >> 0x18)) << 0x30)
                                                       >> 0x28),(char)(local_2c >> 0x10)) << 0x20)
                                      >> 0x18),(char)(local_2c >> 8)),(ushort)(byte)local_2c);
      if (0 < iVar14) {
        param_1 = (float **)iVar14;
        do {
          iVar14 = fr08_409fa2();
          iVar12 = fr08_409fa2();
          local_18._4_4_ = local_20 + iVar12 * 0x100 + iVar14;
          iVar14 = fr08_409fa2();
          local_2c = CONCAT44(&DAT_005272ec + iVar14 * 4,(undefined4)local_2c);
          uVar1 = *(undefined8 *)(&DAT_005272ec + iVar14 * 4);
          uVar2 = *(undefined8 *)(&DAT_005272f4 + iVar14 * 4);
          uVar21 = (short)uVar2 * (short)Var30 + (short)uVar1 * (short)Var29;
          uVar23 = (short)((ulonglong)uVar2 >> 0x10) * (short)((unkuint10)Var30 >> 0x10) +
                   (short)((ulonglong)uVar1 >> 0x10) * (short)((unkuint10)Var29 >> 0x10);
          uVar25 = (short)((ulonglong)uVar2 >> 0x20) * (short)((unkuint10)Var30 >> 0x20) +
                   (short)((ulonglong)uVar1 >> 0x20) * (short)((unkuint10)Var29 >> 0x20);
          uVar27 = (short)((ulonglong)uVar2 >> 0x30) * (short)((unkuint10)Var30 >> 0x30) +
                   (short)((ulonglong)uVar1 >> 0x30) * (short)((unkuint10)Var29 >> 0x30);
          uVar22 = uVar21 >> 8;
          uVar24 = uVar23 >> 8;
          uVar26 = uVar25 >> 8;
          uVar28 = uVar27 >> 8;
          *local_18._4_4_ =
               (float)CONCAT13((uVar28 != 0) * (uVar28 < 0xff) * (char)(uVar27 >> 8) -
                               (0xff < uVar28),
                               CONCAT12((uVar26 != 0) * (uVar26 < 0xff) * (char)(uVar25 >> 8) -
                                        (0xff < uVar26),
                                        CONCAT11((uVar24 != 0) * (uVar24 < 0xff) *
                                                 (char)(uVar23 >> 8) - (0xff < uVar24),
                                                 (uVar22 != 0) * (uVar22 < 0xff) *
                                                 (char)(uVar21 >> 8) - (0xff < uVar22))));
          param_1 = (float **)((int)param_1 + -1);
        } while (param_1 != (float **)0x0);
      }
    }
    else if (uVar10 == 1) {
      pfVar15 = *param_1;
      local_34._0_4_ = (int)(longlong)ROUND(*pfVar15 * _DAT_00444148);
      local_8 = local_34._0_4_;
      local_34._0_4_ = (int)(longlong)ROUND(pfVar15[1] * _DAT_00444148);
      iVar14 = local_34._0_4_;
      local_34._0_4_ = (int)(longlong)ROUND(pfVar15[2] * _DAT_00444148);
      local_c = local_34._0_4_;
      local_34 = (double)(longlong)ROUND(pfVar15[3] * _DAT_00444148);
      iVar12 = local_34._0_4_;
      fVar13 = (float)fr08_405e3b();
      if ((local_8 < 0x100) && (iVar14 < 0x100)) {
        if (0x100 < local_c + local_8) {
          local_c = 0x100 - local_8;
        }
        if (0x100 < iVar12 + iVar14) {
          iVar12 = 0x100 - iVar14;
        }
        local_20 = local_20 + iVar14 * 0x100 + local_8;
        if (0 < iVar12) {
          do {
            iVar14 = local_c;
            pfVar15 = local_20;
            if (0 < local_c) {
              for (; iVar14 != 0; iVar14 = iVar14 + -1) {
                *pfVar15 = fVar13;
                pfVar15 = pfVar15 + 1;
              }
            }
            local_20 = local_20 + 0x100;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
      }
    }
    else if (uVar10 == 2) {
      local_3c = CONCAT44(**param_1,(int)local_3c);
      uVar10 = fr08_405e3b();
      pfVar15 = *param_1;
      local_10 = 0.0;
      local_18._0_4_ = (uint)(longlong)ROUND(pfVar15[4] * _DAT_00444148);
      local_c = (uint)local_18;
      local_18._0_4_ = (uint)(longlong)ROUND(pfVar15[5] * _DAT_00444148);
      local_1c = (float *)(uint)local_18;
      local_24 = pfVar15[6];
      local_40 = pfVar15[7];
      local_44 = uVar10 >> 0x10 & 0xff;
      local_34 = (double)local_3c._4_4_;
      local_18 = CONCAT44(uVar10,(uint)local_18) & 0xffffffffff;
      local_2c = CONCAT44(uVar10 >> 8,(undefined4)local_2c) & 0xffffffffff;
      pbVar17 = (byte *)((int)local_20 + 2);
      do {
        local_8 = 0;
        local_3c = CONCAT44((int)local_10 - (int)local_1c,(int)local_3c);
        fVar13 = (float)((int)local_10 - (int)local_1c) * local_24 * _DAT_004441c4;
        local_20 = (float *)(fVar13 * fVar13);
        do {
          local_3c = CONCAT44(local_8 - local_c,(int)local_3c);
          fVar13 = (float)(local_8 - local_c) * local_24 * _DAT_004441c4;
          fVar13 = fVar13 * fVar13 + (float)local_20 + _DAT_004441c0;
          if (fVar13 <= _DAT_004440e8) {
            fVar13 = 0.0;
          }
          if (_DAT_004440ec <= fVar13) {
            fVar13 = 1.0;
          }
          fVar20 = (float10)fr08_40a031((double)fVar13,local_34);
          lVar3 = (longlong)
                  ROUND(((float10)_DAT_00444128 - fVar20) * (float10)local_40 *
                        (float10)_DAT_004441b8);
          local_3c._0_4_ = (int)lVar3;
          if ((int)local_3c < 0) {
            local_3c._0_4_ = 0;
          }
          if (0xfe < (int)local_3c) {
            local_3c._0_4_ = 0xff;
          }
          iVar14 = 0x100 - (int)local_3c;
          pbVar17[-2] = (byte)((uint)pbVar17[-2] * iVar14 + local_44 * (int)local_3c >> 8);
          pbVar17[-1] = (byte)((uint)pbVar17[-1] * iVar14 + local_2c._4_4_ * (int)local_3c >> 8);
          pbVar17[1] = (byte)(uVar10 >> 0x18);
          *pbVar17 = (byte)((uint)*pbVar17 * iVar14 + (int)local_18._4_4_ * (int)local_3c >> 8);
          pbVar17 = pbVar17 + 4;
          local_8 = local_8 + 1;
          local_3c = lVar3;
        } while (local_8 < 0x100);
        local_10 = (float)((int)local_10 + 1);
      } while ((int)local_10 < 0x100);
    }
    else {
      if (uVar10 == 3) {
        pfVar15 = *param_1;
        local_1c = (float *)pfVar15[2];
        local_10 = pfVar15[3];
        local_18 = (ulonglong)ROUND(pfVar15[4]);
        uVar10 = (uint)local_18;
      }
      else {
        if (uVar10 != 5) {
          return;
        }
        local_1c = (float *)**param_1;
        local_10 = (*param_1)[1];
        uVar10 = 0;
      }
      uVar11 = fr08_405e3b();
      local_18 = CONCAT44(local_18._4_4_,uVar11);
      uVar11 = (*DAT_004440c0)();
      local_8 = (*DAT_0044400c)(uVar11);
      local_c = (*DAT_0044403c)(uVar11,0x100,0x100);
      (*DAT_004440c4)(0,uVar11);
      (*DAT_00444038)(local_8,local_c);
      local_70 = 0x28;
      local_6c = 0x100;
      local_68 = 0xffffff00;
      local_64 = 1;
      local_62 = 0x20;
      local_60 = 0;
      (*DAT_00444034)(local_8,local_c,0,0x100,local_20,&local_70,0);
      local_98 = 0;
      local_97 = 0;
      local_96 = 0;
      local_2c._0_4_ = (undefined4)(longlong)ROUND(local_10 * _DAT_004441cc);
      local_93 = 0;
      local_ac = (undefined4)local_2c;
      local_91 = 0;
      local_9c = 0;
      local_95 = 1;
      local_94 = 4;
      local_92 = 4;
      local_2c = (ulonglong)ROUND((float)local_1c * _DAT_00444148);
      local_a8 = (undefined4)local_2c;
      local_a4 = ((uVar10 & 0xffff) * 0xe10) / 0x10000;
      puVar16 = (undefined4 *)s_arial_0045ab88;
      puVar19 = local_90;
      for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar19 = *puVar16;
        puVar16 = puVar16 + 1;
        puVar19 = puVar19 + 1;
      }
      local_a0 = local_a4;
      local_24 = (float)(*DAT_00444024)(&local_ac);
      (*DAT_00444020)(local_8,1);
      uVar10 = (uint)local_18;
      (*DAT_00444028)(local_8,(uint)local_18._2_1_ | (uVar10 & 0xff) << 0x10 | uVar10 & 0xff00);
      (*DAT_00444038)(local_8,local_24);
      pcVar5 = (char *)(&DAT_0058345c)[(int)param_1[10]];
      if (param_1[7] == (float *)0x3) {
        iVar14 = 0;
        cVar4 = *pcVar5;
        while (cVar4 != '\0') {
          iVar14 = iVar14 + 1;
          cVar4 = pcVar5[iVar14];
        }
        local_18._0_4_ = (uint)(longlong)ROUND((*param_1)[1] * _DAT_00444148);
        uVar11 = (uint)local_18;
        local_18 = (ulonglong)ROUND(**param_1 * _DAT_00444148);
        (*DAT_0044402c)(local_8,(uint)local_18,uVar11,0,0,pcVar5,iVar14,0);
      }
      else {
        local_10 = (float)((int)param_1[7] >> 4 & 3);
        puVar16 = (undefined4 *)(&DAT_004e4ae0 + (int)local_10 * 0x600);
        for (iVar14 = 0x180; iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar16 = 0;
          puVar16 = puVar16 + 1;
        }
        puVar16 = (undefined4 *)(&DAT_004e62e0 + (int)local_10 * 0x400);
        for (iVar14 = 0x100; iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar16 = 0;
          puVar16 = puVar16 + 1;
        }
        iVar14 = 0;
        (*DAT_00444030)(local_8,local_e4);
        cVar4 = *pcVar5;
        local_3c = CONCAT44(local_e4[0],(int)local_3c);
        while ((cVar4 != '\0' && (iVar14 < 0x40))) {
          (*DAT_0044401c)(local_8,pcVar5 + iVar14,1,&local_18);
          fVar9 = _DAT_00444108;
          fVar13 = (float)(iVar14 % 8) * _DAT_004441c8;
          fVar7 = (float)(iVar14 / 8) * _DAT_004441c8;
          fVar6 = fVar13 * _DAT_00444108;
          iVar12 = ((int)local_10 * 0x40 + iVar14) * 0x18;
          (&DAT_004e4ae0)[iVar12] = pcVar5[iVar14];
          *(float *)(&DAT_004e4ae4 + iVar12) = fVar6;
          *(float *)(&DAT_004e4ae8 + iVar12) = fVar7 * fVar9;
          *(float *)(&DAT_004e4aec + iVar12) = ((float)(uint)local_18 + fVar13) * fVar9;
          local_1c = (float *)(float)(int)local_3c._4_4_;
          *(float *)(&DAT_004e4af0 + iVar12) = ((float)(int)local_3c._4_4_ + fVar7) * fVar9;
          *(float *)(&DAT_004e4af4 + iVar12) = (float)(uint)local_18 / (float)local_1c;
          *(int *)(&DAT_004e62e0 + ((int)local_10 * 0x100 + (int)pcVar5[iVar14]) * 4) = iVar14;
          local_2c._0_4_ = (undefined4)(longlong)ROUND(fVar7);
          uVar11 = (undefined4)local_2c;
          local_2c = (ulonglong)ROUND(fVar13);
          (*DAT_0044402c)(local_8,(undefined4)local_2c,uVar11,0,0,pcVar5 + iVar14,1,0);
          iVar14 = iVar14 + 1;
          cVar4 = pcVar5[iVar14];
        }
      }
      local_70 = 0x28;
      local_6c = 0x100;
      local_68 = 0xffffff00;
      local_64 = 1;
      local_62 = 0x20;
      local_60 = 0;
      (*DAT_00444018)(local_8,local_c,0,0x100,local_20,&local_70,0);
      (*DAT_00444014)(local_8);
      pcVar8 = DAT_00444010;
      (*DAT_00444010)(local_c);
      (*pcVar8)(local_24);
    }
  }
  return;
}

