// Original FR08 function at 004068e9

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_4068e9(int param_1,int *param_2,float param_3,uint param_4)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined *puVar10;
  float10 fVar11;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int iStack_10;
  int local_c;
  int local_8;
  
  local_14 = (uint)(longlong)ROUND((float)param_2 * _DAT_00444148);
  iVar7 = (int)local_14 >> 8;
  uVar8 = param_4 & 0xf;
  if (uVar8 == 0) {
    DAT_0058f7dc = local_14 & 0xff;
    if (0 < iVar7) {
      puVar9 = &DAT_0058f7dc;
      for (iVar3 = iVar7; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar9 = 0x100;
        puVar9 = puVar9 + 1;
      }
    }
LAB_004069c3:
    if (0 < iVar7) {
      puVar4 = &DAT_0058f7dc;
      puVar9 = (undefined4 *)(&DAT_0058f7d8 + iVar7 * 8);
      iVar3 = iVar7;
      do {
        uVar1 = *puVar4;
        puVar4 = puVar4 + 1;
        *puVar9 = uVar1;
        puVar9 = puVar9 + -1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  else if (uVar8 == 2) {
    if (0 < iVar7) {
      puVar9 = &DAT_0058f7dc;
      fVar2 = (float)(iVar7 * iVar7) * _DAT_00444110;
      iVar3 = iVar7;
      param_2 = (int *)iVar7;
      do {
        iVar3 = iVar3 + -1;
        fVar11 = (float10)fr08_40a00a((double)(((float)(iVar3 * iVar3) * _DAT_00444120) / fVar2));
        local_14 = (uint)(longlong)ROUND(fVar11 * (float10)_DAT_004441b8);
        *puVar9 = local_14;
        puVar9 = puVar9 + 1;
        param_2 = (int *)((int)param_2 + -1);
      } while (param_2 != (int *)0x0);
      goto LAB_004069c3;
    }
  }
  else if (0 < iVar7) {
    piVar5 = (int *)&DAT_0058f7dc;
    param_2 = (int *)0x10000;
    local_8 = iVar7;
    do {
      *piVar5 = (int)param_2 / (int)local_14;
      piVar5 = piVar5 + 1;
      local_8 = local_8 + -1;
      param_2 = (int *)((int)param_2 + 0x10000);
    } while (local_8 != 0);
    goto LAB_004069c3;
  }
  if (uVar8 == 3) {
    if (0 < iVar7) {
      puVar9 = &DAT_0058f7dc;
      for (iVar3 = iVar7; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      goto LAB_004069f6;
    }
  }
  else {
LAB_004069f6:
    if ((uVar8 == 4) && (0 < iVar7)) {
      puVar9 = &DAT_0058f7dc + iVar7;
      for (iVar3 = iVar7; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
    }
  }
  iVar3 = iVar7 * 2;
  param_2 = (int *)0x0;
  if (0 < iVar3) {
    piVar5 = (int *)&DAT_0058f7dc;
    do {
      param_2 = (int *)((int)param_2 + *piVar5);
      piVar5 = piVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (param_2 != (int *)0x0) goto LAB_00406a30;
  }
  param_2 = (int *)0x1;
LAB_00406a30:
  iVar3 = iVar7 * 2;
  local_14 = (uint)(longlong)ROUND((param_3 * _DAT_0044410c) / (float)(int)param_2);
  if (0 < iVar3) {
    piVar5 = (int *)&DAT_0058f7dc;
    do {
      *piVar5 = *piVar5 * local_14;
      piVar5 = piVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  local_8 = (int)&DAT_005907dd - param_1;
  iStack_10 = 0x100;
  do {
    fr08_406880(&DAT_005907dc,param_1,0x100,iVar7,param_4);
    puVar10 = (undefined *)(param_1 + 1);
    local_c = 0x100;
    do {
      param_2 = (int *)&DAT_0058f7dc;
      local_18 = 0;
      local_1c = 0;
      local_20 = 0;
      param_3 = (float)(iVar7 * 2);
      pbVar6 = puVar10 + local_8;
      do {
        iVar3 = *param_2;
        local_20 = local_20 + (uint)pbVar6[-2] * iVar3;
        local_1c = local_1c + (uint)pbVar6[-1] * iVar3;
        local_18 = local_18 + (uint)*pbVar6 * iVar3;
        pbVar6 = pbVar6 + 4;
        param_3 = (float)((int)param_3 + -1);
        param_2 = param_2 + 1;
      } while (0 < (int)param_3);
      *(undefined4 *)(puVar10 + -1) = 0xffffffff;
      if (local_20 < 0x1000000) {
        puVar10[-1] = (char)(local_20 / 0x10000);
      }
      if (local_1c < 0x1000000) {
        *puVar10 = (char)(local_1c / 0x10000);
      }
      if (local_18 < 0x1000000) {
        puVar10[1] = (char)(local_18 / 0x10000);
      }
      puVar10 = puVar10 + 4;
      local_c = local_c + -1;
    } while (local_c != 0);
    param_1 = param_1 + 0x400;
    local_8 = local_8 + -0x400;
    iStack_10 = iStack_10 + -1;
  } while (iStack_10 != 0);
  return;
}

