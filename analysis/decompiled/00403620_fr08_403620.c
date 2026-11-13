// Original FR08 function at 00403620

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_403620(int param_1,int param_2,int param_3,int param_4,float *param_5,float *param_6,
                int param_7,int param_8,uint param_9)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float local_30;
  float local_2c;
  float local_28;
  float *local_18;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = param_2;
  if ((param_9 & 1) != 0) {
    local_c = param_2 + -1;
  }
  local_10 = param_3;
  if ((param_9 & 2) != 0) {
    local_10 = param_3 + -1;
  }
  iVar3 = *(int *)(param_1 + 0x10);
  param_9 = 0;
  local_18 = (float *)(iVar3 * 0x2c + *(int *)(param_1 + 0x34));
  *(int *)(param_1 + 0x10) = param_2 * param_3 + iVar3;
  pfVar6 = local_18;
  if (0 < param_3) {
    do {
      local_8 = 0;
      pfVar7 = pfVar6;
      if (0 < param_2) {
        do {
          fVar11 = (float10)local_8 / (float10)local_c;
          if (local_10 == 0) {
            fVar4 = 1.0;
          }
          else {
            fVar4 = (float)param_9 / (float)local_10;
          }
          if (param_4 == 2) {
            fVar13 = (float10)fsin(fVar11 * (float10)_DAT_00444118);
            local_30 = (float)(fVar13 * (float10)*param_6);
            fVar13 = (float10)fcos(fVar11 * (float10)_DAT_00444118);
            local_28 = (float)(fVar13 * (float10)*param_6);
            local_2c = fVar4 * *(float *)(param_7 + 4);
            fVar11 = (float10)_DAT_00444128 - fVar11;
          }
          else if (param_4 == 3) {
            local_30 = *param_5;
            local_2c = param_5[1];
            local_28 = param_5[2];
            fr08_4038f6(param_6,(double)fVar11);
            fr08_4038f6(param_7,(double)fVar4);
            fVar11 = (float10)(float)fVar11;
            pfVar6 = local_18;
          }
          else {
            if (param_4 == 6) {
              fVar12 = (float10)fsin((float10)fVar4 * (float10)_DAT_00444130);
              fVar13 = (float10)fsin(fVar11 * (float10)_DAT_00444118);
              fVar13 = fVar13 * (float10)*param_6 * (float10)(double)fVar12;
              fVar14 = (float10)fcos((float10)fVar4 * (float10)_DAT_00444130);
              fVar14 = fVar14 * (float10)*param_6;
              fVar15 = (float10)fcos(fVar11 * (float10)_DAT_00444118);
              fVar12 = fVar15 * (float10)*param_6 * (float10)(double)fVar12;
            }
            else {
              fVar12 = (float10)fVar4 * (float10)_DAT_00444118 + (float10)_DAT_00444138;
              fVar13 = (float10)fcos(fVar12);
              fVar14 = fVar13 * (float10)*(float *)(param_7 + 4) + (float10)*param_6;
              fVar13 = (float10)fcos(fVar11 * (float10)_DAT_00444118);
              fVar13 = fVar14 * fVar13;
              fVar15 = (float10)fsin(fVar11 * (float10)_DAT_00444118);
              fVar14 = fVar14 * fVar15;
              fVar12 = (float10)fsin(fVar12);
              fVar12 = fVar12 * (float10)*(float *)(param_7 + 4);
            }
            local_2c = (float)fVar14;
            local_30 = (float)fVar13;
            local_28 = (float)fVar12;
          }
          *pfVar6 = local_30;
          pfVar7 = pfVar6 + 0xb;
          pfVar6[1] = local_2c;
          local_8 = local_8 + 1;
          pfVar6[2] = local_28;
          pfVar6[7] = (float)fVar11;
          pfVar6[8] = fVar4;
          pfVar6 = pfVar7;
          local_18 = pfVar7;
        } while (local_8 < param_2);
      }
      param_9 = param_9 + 1;
      pfVar6 = pfVar7;
    } while ((int)param_9 < param_3);
  }
  iVar5 = *(int *)(param_1 + 0x14);
  piVar8 = (int *)(iVar5 * 0x1c + *(int *)(param_1 + 0x38));
  if (local_10 == 0) {
    *(int *)(param_1 + 0x14) = iVar5 + -2 + local_c;
    iVar5 = 2;
    if (2 < local_c) {
      do {
        *piVar8 = iVar3;
        piVar8[param_8 + 1] = iVar5 + -1 + iVar3;
        piVar8[2 - param_8] = iVar5 + iVar3;
        piVar8 = piVar8 + 7;
        iVar5 = iVar5 + 1;
      } while (iVar5 < local_c);
    }
  }
  else {
    *(int *)(param_1 + 0x14) = iVar5 + local_10 * local_c * 2;
    param_9 = 0;
    if (0 < local_10) {
      do {
        local_8 = 0;
        if (0 < local_c) {
          iVar5 = ((int)param_9 % param_3) * param_2;
          iVar9 = ((int)(param_9 + 1) % param_3) * param_2;
          do {
            iVar10 = local_8 % param_2;
            iVar1 = iVar10 + iVar9 + iVar3;
            *piVar8 = iVar1;
            local_8 = local_8 + 1;
            iVar2 = local_8 % param_2 + iVar5 + iVar3;
            piVar8[param_8 + 1] = iVar2;
            piVar8[2 - param_8] = iVar5 + iVar10 + iVar3;
            piVar8[7] = local_8 % param_2 + iVar9 + iVar3;
            piVar8[param_8 + 8] = iVar2;
            (piVar8 + 7)[2 - param_8] = iVar1;
            piVar8 = piVar8 + 0xe;
          } while (local_8 < local_c);
        }
        param_9 = param_9 + 1;
      } while ((int)param_9 < local_10);
    }
  }
  return;
}

