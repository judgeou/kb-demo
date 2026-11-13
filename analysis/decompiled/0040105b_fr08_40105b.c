// Original FR08 function at 0040105b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_40105b(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int local_80 [5];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  int *local_c;
  char local_5;
  
  local_34 = 0x47;
  local_30 = 0x4b;
  local_2c = 0x4d;
  local_28 = 0x50;
  local_24 = 0;
  local_4c = 0x16;
  local_48 = 0x15;
  local_44 = 0x17;
  local_40 = 0x19;
  local_3c = 0x18;
  local_38 = 0;
  local_20 = 0x15;
  local_1c = 0x19;
  local_18 = 0;
  DAT_00493030 = (int *)FUN_0044340e(0x78);
  if (DAT_00493030 == (int *)0x0) {
    fr08_409b4a(s_could_not_open_D3d_8_0045aae8);
  }
  local_c = &local_4c;
  iVar2 = 0x16;
  do {
    iVar1 = iVar2;
    local_14 = iVar1;
    iVar2 = (**(code **)(*DAT_00493030 + 0x28))(DAT_00493030,0,1,iVar1,1,1,iVar1);
    if (-1 < iVar2) break;
    local_c = local_c + 1;
    iVar2 = *local_c;
  } while (*local_c != 0);
  local_10 = &local_34;
  iVar2 = 0x47;
  do {
    local_c = (int *)iVar2;
    iVar2 = (**(code **)(*DAT_00493030 + 0x28))(DAT_00493030,0,1,iVar1,2,1,iVar2);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*DAT_00493030 + 0x30))(DAT_00493030,0,1,iVar1,iVar1,local_c);
      if (-1 < iVar2) break;
    }
    local_10 = local_10 + 1;
    iVar2 = *local_10;
  } while (iVar2 != 0);
  local_10 = &local_20;
  iVar2 = 0x15;
  do {
    DAT_0045b020 = iVar2;
    iVar2 = (**(code **)(*DAT_00493030 + 0x28))(DAT_00493030,0,1,iVar1,1,3,iVar2);
    if (-1 < iVar2) break;
    local_10 = local_10 + 1;
    iVar2 = *local_10;
  } while (iVar2 != 0);
  piVar4 = local_80;
  for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  local_6c = 2;
  local_80[3] = 2;
  local_80[2] = local_14;
  local_5c = (int)local_c;
  local_64 = 0;
  local_68 = DAT_00594328;
  local_80[0] = 800;
  local_80[1] = 600;
  local_50 = 1;
  local_60 = 1;
  iVar2 = (**(code **)(*DAT_00493030 + 0x3c))
                    (DAT_00493030,0,1,DAT_00594328,0x40,local_80,&DAT_0049303c);
  if (iVar2 < 0) {
    iVar2 = (**(code **)(*DAT_00493030 + 0x3c))
                      (DAT_00493030,0,1,DAT_00594328,0x20,local_80,&DAT_0049303c);
    if (iVar2 < 0) {
      fr08_401000();
    }
  }
  (*DAT_004440c8)(0);
  DAT_004cb048 = 0;
  DAT_0049302c = 0;
  DAT_0045ac10 = 0;
  puVar3 = &DAT_0045ac1c;
  do {
    *(undefined *)(puVar3 + 2) = 0;
    *puVar3 = 0;
    *(undefined *)((int)puVar3 + 9) = 0;
    puVar3 = puVar3 + 4;
  } while ((int)puVar3 < 0x45b01c);
  DAT_0045ac34 = 1;
  DAT_0045ac36 = 1;
  DAT_0045ac30 = 0xc000;
  DAT_0045ac35 = 1;
  DAT_0045ac24 = 1;
  DAT_0045ac26 = 0;
  DAT_0045ac20 = 0x2000;
  DAT_0045ac25 = 1;
  DAT_0045ac44 = 1;
  DAT_0045ac46 = 0;
  DAT_0045ac40 = 0x1000;
  DAT_0045ac45 = 1;
  iVar2 = (**(code **)(*DAT_0049303c + 0x60))(DAT_0049303c,0x18000,0x200,0x65,0,&DAT_0045ac28);
  if (iVar2 < 0) {
    fr08_401000();
  }
  iVar2 = (**(code **)(*DAT_0049303c + 0x5c))
                    (DAT_0049303c,DAT_0045ac20 * 0x24,0x200,0x152,0,&DAT_0045ac18);
  if (iVar2 < 0) {
    fr08_401000();
  }
  iVar2 = (**(code **)(*DAT_0049303c + 0x5c))
                    (DAT_0049303c,DAT_0045ac40 * 0x24,0x200,0x2c2,0,&DAT_0045ac38);
  if (iVar2 < 0) {
    fr08_401000();
  }
  iVar2 = (**(code **)(*DAT_0049303c + 0x80))(DAT_0049303c,&DAT_00493038);
  if (iVar2 < 0) {
    fr08_401000();
  }
  iVar2 = (**(code **)(*DAT_0049303c + 0x84))(DAT_0049303c,&DAT_004cc270);
  if (iVar2 < 0) {
    fr08_401000();
  }
  local_5 = '\x01';
  puVar3 = &DAT_004cbe60;
  do {
    piVar4 = DAT_0049303c;
    if (local_5 == '\0') goto LAB_0040139b;
    *puVar3 = 0;
    iVar2 = (**(code **)(*piVar4 + 0x50))(piVar4,0x200,0x200,1,1,local_14,0,puVar3);
    if (iVar2 < 0) {
      local_5 = '\0';
    }
    puVar3 = puVar3 + 1;
  } while ((int)puVar3 < 0x4cbe6c);
  if (local_5 == '\0') {
LAB_0040139b:
    DAT_004cbe60 = 0;
    _DAT_004cbe64 = 0;
  }
  else {
    iVar2 = (**(code **)(*DAT_0049303c + 0x68))(DAT_0049303c,0x200,0x200,local_c,0,&DAT_004cbe58);
    if (iVar2 < 0) {
      fr08_401000();
    }
  }
  DAT_00493034 = (int)local_5;
  puVar3 = &DAT_004cbe70;
  for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xffffffff;
    puVar3 = puVar3 + 1;
  }
  puVar3 = &DAT_004cc274;
  for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xffffffff;
    puVar3 = puVar3 + 1;
  }
  DAT_004cb040 = 0xffffffff;
  DAT_004cb044 = 0xffffffff;
  DAT_004cb04c = 0xffffffff;
  DAT_004cb050 = 0xffffffff;
  fr08_408b25();
  return;
}

