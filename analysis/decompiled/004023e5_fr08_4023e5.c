// Original FR08 function at 004023e5

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_4023e5(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  iVar3 = 0;
  if (0 < DAT_004ccaa0) {
    do {
      (**(code **)(*DAT_0049303c + 0xb8))(DAT_0049303c,iVar3,0);
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_004ccaa0);
  }
  local_8 = 0;
  if (0 < param_2) {
    local_c = &DAT_004cb058;
    do {
      piVar1 = DAT_0049303c;
      local_74 = *(int *)(&DAT_0045aa9c + *param_1 * 4);
      piVar2 = param_1;
      if (local_74 != 0) {
        local_70 = (float)param_1[1] * (float)param_1[0xb];
        local_34 = param_1[4];
        local_30 = param_1[5];
        local_2c = param_1[6];
        local_6c = (float)param_1[2] * (float)param_1[0xb];
        local_68 = (float)param_1[3] * (float)param_1[0xb];
        local_64 = 0x3f800000;
        local_60 = 0;
        local_5c = 0;
        local_58 = 0;
        local_54 = 0;
        local_50 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = 0;
        if (*param_1 == 2) {
          local_28 = 4096.0;
          local_40 = 0;
          local_3c = 0;
          local_38 = 0;
          local_20 = 0x3f800000;
          local_1c = 0.0;
          local_18 = 0.0;
        }
        else {
          local_28 = (float)param_1[0xd] + (float)param_1[0xd];
          local_40 = param_1[7];
          local_3c = param_1[8];
          local_38 = param_1[9];
          local_20 = 0;
          local_1c = 1.0 / (float)param_1[0xd];
          local_18 = local_1c * (float)_DAT_004440f8;
        }
        local_10 = param_1[0xc];
        local_24 = 0x3f800000;
        piVar2 = param_1 + 0xe;
        local_14 = 0;
        piVar4 = local_c;
        for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar4 = *param_1;
          param_1 = param_1 + 1;
          piVar4 = piVar4 + 1;
        }
        (**(code **)(*piVar1 + 0xb0))(piVar1,local_8,&local_74);
        (**(code **)(*DAT_0049303c + 0xb8))(DAT_0049303c,local_8,1);
      }
      local_8 = local_8 + 1;
      local_c = local_c + 0xe;
      param_1 = piVar2;
    } while (local_8 < param_2);
  }
  DAT_004ccaa0 = param_2;
  return;
}

