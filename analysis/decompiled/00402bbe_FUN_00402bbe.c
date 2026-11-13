// Original FR08 function at 00402bbe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402bbe(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_14;
  code *local_10;
  longlong local_c;
  
  if (param_1[4] != 0) {
    param_1[4] = 0;
    (**(code **)(param_1[1] + 0x18))(param_1[1]);
    piVar1 = *(int **)(param_1[1] + 0x24);
    local_14 = param_1[7] & 1;
    puVar2 = (undefined4 *)*param_1;
    local_34 = *puVar2;
    local_30 = puVar2[2];
    local_2c = puVar2[3];
    local_28 = puVar2[5];
    local_24 = puVar2[6];
    local_20 = puVar2[8];
    local_38 = (float)puVar2[9];
    local_1c = puVar2[10];
    local_10 = FUN_00402c5c;
    local_c = (longlong)ROUND(local_38 * _DAT_0044410c);
    fr08_409ffe((undefined4)local_c);
    iVar3 = piVar1[0xd];
    iVar4 = *piVar1;
    if ((local_14 == 0) && (0 < iVar4)) {
      do {
        (*local_10)(iVar3,&local_38);
        iVar3 = iVar3 + 0x2c;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  return;
}

