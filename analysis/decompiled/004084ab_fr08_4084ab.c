// Original FR08 function at 004084ab

void __thiscall fr08_4084ab(int *param_1_00,int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float10 fVar5;
  int local_8;
  
  if (param_4 < 2) {
    param_4 = 2;
  }
  if (0x100 < param_4) {
    param_4 = 0x100;
  }
  fr08_408268(param_1);
  param_1_00[0xc] = param_4;
  if (param_1_00[0x12] != 0) {
    fr08_409b8d(param_1_00[0x12]);
  }
  iVar1 = fr08_409b9f(*param_1_00 * param_4 * 0x2c);
  local_8 = 0;
  param_1_00[0x12] = iVar1;
  if (0 < param_4) {
    do {
      for (puVar3 = *(undefined4 **)(&DAT_005282f4 + param_3 * 4); puVar3 != (undefined4 *)0x0;
          puVar3 = (undefined4 *)*puVar3) {
        fVar5 = (float10)fr08_4087e5(puVar3,(float)local_8 / (float)(param_4 + -1));
        fr08_40889f(puVar3,(float)fVar5);
      }
      if (*(int *)(param_2 + 0x10) != 0) {
        (**(code **)(param_2 + 0x18))(param_2);
      }
      fr08_40831a();
      puVar3 = *(undefined4 **)(param_1 + 0x34);
      puVar4 = (undefined4 *)(*param_1_00 * local_8 * 0x2c + param_1_00[0x12]);
      for (uVar2 = (uint)(*param_1_00 * 0x2c) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      local_8 = local_8 + 1;
      for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(undefined *)puVar4 = *(undefined *)puVar3;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
    } while (local_8 < param_4);
  }
  return;
}

