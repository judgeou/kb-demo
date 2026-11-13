// Original FR08 function at 00407cb7

void __fastcall fr08_407cb7(int *param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  short *psVar3;
  char cVar4;
  float *pfVar5;
  float *pfVar6;
  short sVar7;
  undefined4 local_bc [21];
  undefined4 local_68;
  undefined local_64 [40];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  int local_10;
  float *local_c;
  float local_8;
  
  if ((DAT_00493034 != 0) || ((param_1[0x14] == 0 && (*param_1 == 0)))) {
    local_30 = (float)param_1[0x15] - (float)param_1[0x17];
    local_2c = (float)param_1[0x16] - (float)param_1[0x18];
    local_28 = (float)param_1[0x17] + (float)param_1[0x15];
    local_1c = (float)param_1[0x16] + (float)param_1[0x18];
    local_24 = local_2c;
    local_20 = local_28;
    local_18 = local_30;
    local_14 = local_1c;
    local_8 = local_1c;
    fr08_40100b();
    local_68 = 0;
    local_bc[0] = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    fr08_408e20();
    cVar4 = fr08_401812(param_1[0x14],local_bc);
    if (cVar4 != '\0') {
      fr08_401cd3(local_64,0);
      *(undefined *)(&DAT_0058385c)[param_1[0x19]] = 0;
      *(undefined *)((&DAT_0058385c)[param_1[0x19]] + 1) = 0;
      if (*param_1 != 0) {
        *(char *)(&DAT_0058385c)[param_1[0x19]] = *(char *)param_1 + -0x11;
      }
      if (param_1[1] != 0) {
        *(char *)((&DAT_0058385c)[param_1[0x19]] + 1) = *(char *)(param_1 + 1) + -0x11;
      }
      fr08_4017ab((&DAT_0058385c)[param_1[0x19]]);
      fr08_4023e5(0,0);
      local_10 = fr08_402073(4,6,1);
      pfVar6 = *(float **)(local_10 + 0x30);
      uVar2 = *(undefined4 *)(local_10 + 4);
      psVar3 = *(short **)(local_10 + 0x34);
      local_8 = 5.605194e-45;
      pfVar5 = (float *)(param_1 + 10);
      local_c = &local_2c;
      do {
        *pfVar6 = local_c[-1];
        pfVar1 = local_c + 2;
        pfVar6[1] = *local_c;
        pfVar6[2] = 1.0;
        pfVar6[3] = (float)param_1[0x12];
        pfVar6[4] = (float)param_1[0x13];
        pfVar6[5] = pfVar5[-8];
        pfVar6[6] = *pfVar5;
        pfVar6[7] = pfVar5[-4];
        pfVar6[8] = pfVar5[4];
        pfVar6 = pfVar6 + 9;
        local_8 = (float)((int)local_8 + -1);
        pfVar5 = pfVar5 + 1;
        local_c = pfVar1;
      } while (local_8 != 0.0);
      sVar7 = (short)uVar2;
      *psVar3 = sVar7;
      psVar3[1] = sVar7 + 2;
      psVar3[2] = sVar7 + 1;
      psVar3[3] = sVar7;
      psVar3[4] = sVar7 + 3;
      psVar3[5] = sVar7 + 2;
      fr08_4021ce(local_10,1);
      fr08_401d97();
    }
  }
  return;
}

