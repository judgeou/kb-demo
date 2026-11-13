// Original FR08 function at 00408634

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall fr08_408634(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  int iVar12;
  int iVar13;
  float local_30;
  int local_8;
  
  fVar11 = _DAT_00444180;
  local_8 = *(int *)(param_1 + 0x14);
  iVar12 = 0;
  if (*(int *)(param_1 + 0x10) != 1 && -1 < *(int *)(param_1 + 0x10) + -1) {
    do {
      iVar6 = *(int *)(param_1 + 0xc);
      iVar13 = iVar12 * 0x18;
      fVar3 = *(float *)(iVar6 + 4 + iVar13);
      iVar2 = iVar6 + iVar13;
      fVar7 = (float)(int)*(short *)(iVar6 + iVar13);
      iVar1 = iVar12 + 1;
      fVar4 = *(float *)(iVar2 + 0x1c);
      fVar8 = (float)(int)*(short *)(iVar6 + iVar1 * 0x18);
      if (iVar12 == 0) {
        local_30 = fVar3;
        if (local_8 == 2) {
          local_30 = fVar3 - (fVar4 - fVar3);
        }
        fVar9 = fVar7 - (fVar8 - fVar7);
      }
      else {
        local_30 = *(float *)(iVar2 + -0x14);
        fVar9 = (float)(int)*(short *)(iVar2 + -0x18);
      }
      if (iVar12 == *(int *)(param_1 + 0x10) + -2) {
        fVar5 = fVar4;
        if (local_8 == 2) {
          fVar5 = (fVar4 - fVar3) + fVar4;
        }
        fVar10 = (fVar8 - fVar7) + fVar8;
      }
      else {
        fVar5 = *(float *)(iVar2 + 0x34);
        fVar10 = (float)(int)*(short *)(iVar6 + (iVar12 * 3 + 6) * 8);
      }
      if (fVar8 < fVar7 + (float)_DAT_004441f0) {
        local_8 = 0;
      }
      iVar12 = *(int *)(param_1 + 0x14);
      if (iVar12 == 0) {
        *(float *)(iVar2 + 8) = fVar3;
        *(float *)(iVar13 + 0xc + *(int *)(param_1 + 0xc)) = fVar4 - fVar3;
        *(undefined4 *)(iVar13 + 0x10 + *(int *)(param_1 + 0xc)) = 0;
        *(undefined4 *)(iVar13 + 0x14 + *(int *)(param_1 + 0xc)) = 0;
      }
      else if ((0 < iVar12) && (iVar12 < 3)) {
        fVar9 = (fVar4 - local_30) / (_DAT_004440ec - (fVar9 - fVar7) / (fVar8 - fVar7));
        fVar7 = (fVar5 - fVar3) / ((fVar10 - fVar7) / (fVar8 - fVar7));
        *(float *)(iVar2 + 8) = fVar3;
        *(float *)(iVar13 + 0xc + *(int *)(param_1 + 0xc)) = fVar9;
        *(float *)(iVar13 + 0x10 + *(int *)(param_1 + 0xc)) =
             ((fVar4 * _DAT_004441e8 - fVar3 * _DAT_004441e8) - fVar9 * fVar11) - fVar7;
        *(float *)(iVar13 + 0x14 + *(int *)(param_1 + 0xc)) =
             (fVar3 * fVar11 - fVar4 * fVar11) + fVar7 + fVar9;
      }
      iVar12 = iVar1;
    } while (iVar1 < *(int *)(param_1 + 0x10) + -1);
  }
  return;
}

