// Original FR08 function at 0040831a

void __fastcall fr08_40831a(int *param_1)

{
  undefined4 *puVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  int local_c;
  int *local_8;
  
  if (*(char *)(param_1 + 0x13) == '\0') {
    iVar4 = 0;
    if (0 < *param_1) {
      iVar7 = 0;
      do {
        iVar4 = iVar4 + 1;
        puVar1 = (undefined4 *)(iVar7 + 0xc + param_1[0xd]);
        iVar7 = iVar7 + 0x2c;
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
      } while (iVar4 < *param_1);
    }
    local_8 = (int *)param_1[0xe];
    local_c = 0;
    if (0 < param_1[1]) {
      pfVar8 = (float *)(local_8 + 5);
      do {
        iVar4 = param_1[0xd];
        pfVar5 = (float *)(*local_8 * 0x2c + iVar4);
        pfVar3 = (float *)((int)pfVar8[-4] * 0x2c + iVar4);
        local_24 = *pfVar5 - *pfVar3;
        local_20 = pfVar5[1] - pfVar3[1];
        local_1c = pfVar5[2] - pfVar3[2];
        iVar6 = (int)pfVar8[-4] * 0x2c;
        iVar7 = (int)pfVar8[-3] * 0x2c;
        local_18 = *(float *)(iVar6 + iVar4) - *(float *)(iVar7 + iVar4);
        local_14 = *(float *)(iVar6 + 4 + iVar4) - *(float *)(iVar7 + 4 + iVar4);
        local_10 = *(float *)(iVar6 + 8 + iVar4) - *(float *)(iVar7 + 8 + iVar4);
        fr08_408d27();
        fr08_408d27();
        pfVar3 = pfVar8 + -2;
        fr08_404a89(&local_24,&local_18);
        fr08_408d27();
        iVar7 = param_1[0xd];
        iVar6 = *local_8 * 0x2c;
        *(float *)(iVar6 + 0xc + iVar7) = *pfVar3 + *(float *)(iVar6 + 0xc + iVar7);
        iVar4 = iVar6 + 0xc + iVar7;
        *(float *)(iVar4 + 4) = *(float *)(iVar6 + 0x10 + iVar7) + pfVar8[-1];
        *(float *)(iVar4 + 8) = *(float *)(iVar4 + 8) + *pfVar8;
        iVar7 = param_1[0xd];
        iVar6 = (int)pfVar8[-4] * 0x2c;
        *(float *)(iVar6 + 0xc + iVar7) = *(float *)(iVar6 + 0xc + iVar7) + *pfVar3;
        iVar4 = iVar6 + 0xc + iVar7;
        *(float *)(iVar4 + 4) = *(float *)(iVar6 + 0x10 + iVar7) + pfVar8[-1];
        *(float *)(iVar4 + 8) = *(float *)(iVar4 + 8) + *pfVar8;
        iVar7 = param_1[0xd];
        iVar6 = (int)pfVar8[-3] * 0x2c;
        *(float *)(iVar6 + 0xc + iVar7) = *(float *)(iVar6 + 0xc + iVar7) + *pfVar3;
        iVar4 = iVar6 + 0xc + iVar7;
        *(float *)(iVar4 + 4) = *(float *)(iVar6 + 0x10 + iVar7) + pfVar8[-1];
        fVar2 = *pfVar8;
        local_8 = local_8 + 7;
        pfVar8 = pfVar8 + 7;
        local_c = local_c + 1;
        *(float *)(iVar4 + 8) = *(float *)(iVar4 + 8) + fVar2;
      } while (local_c < param_1[1]);
    }
    iVar4 = 0;
    if (0 < *param_1) {
      do {
        fr08_408d27();
        iVar4 = iVar4 + 1;
      } while (iVar4 < *param_1);
    }
    *(undefined *)(param_1 + 0x13) = 1;
  }
  return;
}

