// Original FR08 function at 00401558

void fr08_401558(int param_1,undefined4 *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_24;
  undefined4 *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  puVar6 = param_2;
  local_8 = 0x100;
  local_c = 0x100;
  iVar5 = (**(code **)(*DAT_0049303c + 0x50))(DAT_0049303c,0x100,0x100,0,0,DAT_0045b020,1,&local_10)
  ;
  if (iVar5 < 0) {
    fr08_401000();
  }
  param_2 = (undefined4 *)0x0;
  puVar8 = DAT_005272e4;
  for (iVar5 = 0x10000; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar8 = puVar8 + 1;
  }
  while( true ) {
    iVar5 = (**(code **)(*local_10 + 0x40))(local_10,param_2,&local_24,0,0);
    if (iVar5 < 0) {
      fr08_401000();
    }
    iVar5 = local_c;
    local_18 = local_24;
    if (0 < local_c) {
      local_1c = local_c;
      puVar6 = DAT_005272e4;
      puVar8 = local_20;
      do {
        if (DAT_0045b020 == 0x15) {
          puVar9 = puVar6 + 0x100;
          puVar10 = puVar8;
          for (iVar7 = local_8; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar10 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar10 = puVar10 + 1;
          }
        }
        else {
          if (0 < local_8) {
            local_14 = local_8;
            puVar9 = puVar8;
            do {
              pbVar1 = (byte *)((int)puVar6 + 3);
              pbVar2 = (byte *)((int)puVar6 + 2);
              pbVar3 = (byte *)((int)puVar6 + 1);
              bVar4 = *(byte *)puVar6;
              puVar6 = puVar6 + 1;
              *(ushort *)puVar9 =
                   (ushort)((((uint)(*pbVar1 & 0x80) << 1 | (uint)(*pbVar2 & 0xf8)) << 5 |
                            (uint)(*pbVar3 & 0xf8)) << 2) | (ushort)(bVar4 >> 3);
              puVar9 = (undefined4 *)((int)puVar9 + 2);
              local_14 = local_14 + -1;
            } while (local_14 != 0);
          }
          puVar9 = puVar6 + (0x100 - local_8);
        }
        puVar8 = (undefined4 *)((int)puVar8 + local_24);
        local_1c = local_1c + -1;
        puVar6 = puVar9;
      } while (local_1c != 0);
      local_1c = 0;
    }
    (**(code **)(*local_10 + 0x44))(local_10,param_2);
    if ((local_8 < 2) || (iVar5 < 2)) break;
    fr08_4014bb(DAT_005272e4,local_8,iVar5,0x100);
    local_8 = local_8 / 2;
    local_c = iVar5 / 2;
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  (&DAT_004cc684)[param_1] = local_10;
  return;
}

