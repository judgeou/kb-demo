// Original FR08 function at 00406ee5

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406ee5(int *param_1)

{
  float fVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  float *pfVar6;
  undefined2 *puVar7;
  int extraout_ECX;
  int iVar8;
  code *pcVar9;
  code *extraout_EDX;
  undefined4 *puVar10;
  undefined8 uVar11;
  unkbyte10 in_ST5;
  unkbyte10 Var12;
  undefined *puVar13;
  int iVar14;
  undefined8 local_2c;
  undefined8 local_14;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar13 = &stack0xfffffffc;
  if (param_1[4] != 0) {
    param_1[4] = 0;
    fr08_409e00(1);
    iVar14 = param_1[1];
    (**(code **)(iVar14 + 0x18))(iVar14);
    local_8 = *(undefined4 *)(param_1[1] + 0x24);
    local_c = 0x10000;
    puVar10 = (undefined4 *)param_1[9];
    pfVar6 = (float *)(*param_1 + 0xc);
    iVar8 = 2;
    puVar7 = (undefined2 *)((int)&local_2c + 2);
    do {
      local_14._0_2_ = (undefined2)(longlong)ROUND(pfVar6[2] * _DAT_00444148);
      puVar7[-1] = (undefined2)local_14;
      local_14._0_2_ = (undefined2)(longlong)ROUND(pfVar6[1] * _DAT_00444148);
      *puVar7 = (undefined2)local_14;
      fVar1 = *pfVar6;
      pfVar6 = pfVar6 + -3;
      iVar8 = iVar8 + -1;
      local_14._0_2_ = (undefined2)(longlong)ROUND(fVar1 * _DAT_00444148);
      puVar7[1] = (undefined2)local_14;
      puVar7[2] = 0;
      puVar7 = puVar7 + -4;
    } while (iVar8 != 0);
    local_14 = CONCAT44(param_1[7],(int)(longlong)ROUND(fVar1 * _DAT_00444148));
    Var12 = CONCAT82((longlong)
                     (CONCAT73((int7)(CONCAT64((int6)(CONCAT55((int5)(CONCAT46((int)(CONCAT37((int3)
                                                  (CONCAT28((short)((unkuint10)in_ST5 >> 0x40),
                                                            0x80808080) >> 0x38),0x80000080808080)
                                                  >> 0x30),0x80808080) >> 0x28),0x8080808080) >>
                                                  0x20),0x808080) >> 0x18),0x808080) >> 0x10),0x80);
    pcVar9 = (code *)&LAB_00406fac;
    if (param_1[7] != 0) {
      psllw(local_2c,4);
      FUN_00406feb(iVar14);
      return;
    }
    do {
      uVar11 = (*pcVar9)(puVar13);
      uVar11 = paddsw(uVar11,(longlong)Var12);
      uVar11 = psubusw(uVar11,(longlong)Var12);
      sVar2 = (short)uVar11;
      sVar3 = (short)((ulonglong)uVar11 >> 0x10);
      sVar4 = (short)((ulonglong)uVar11 >> 0x20);
      sVar5 = (short)((ulonglong)uVar11 >> 0x30);
      *puVar10 = CONCAT13((0 < sVar5) * (sVar5 < 0xff) * (char)((ulonglong)uVar11 >> 0x30) -
                          (0xff < sVar5),
                          CONCAT12((0 < sVar4) * (sVar4 < 0xff) * (char)((ulonglong)uVar11 >> 0x20)
                                   - (0xff < sVar4),
                                   CONCAT11((0 < sVar3) * (sVar3 < 0xff) *
                                            (char)((ulonglong)uVar11 >> 0x10) - (0xff < sVar3),
                                            (0 < sVar2) * (sVar2 < 0xff) * (char)uVar11 -
                                            (0xff < sVar2))));
      puVar10 = puVar10 + 1;
      pcVar9 = extraout_EDX;
    } while (extraout_ECX != 1);
  }
  return;
}

