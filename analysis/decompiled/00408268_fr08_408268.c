// Original FR08 function at 00408268

void __thiscall fr08_408268(int param_1_00,int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  fr08_408005(*param_1,param_1[1],param_1[6],param_1[2],param_1[3]);
  puVar3 = (undefined4 *)param_1[0xd];
  puVar4 = *(undefined4 **)(param_1_00 + 0x34);
  for (uVar1 = (uint)(*param_1 * 0x2c) >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined *)puVar4 = *(undefined *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  puVar3 = (undefined4 *)param_1[0xe];
  puVar4 = *(undefined4 **)(param_1_00 + 0x38);
  for (uVar1 = (uint)(param_1[1] * 0x1c) >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined *)puVar4 = *(undefined *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  puVar3 = (undefined4 *)param_1[0xf];
  puVar4 = *(undefined4 **)(param_1_00 + 0x3c);
  for (uVar1 = (uint)(param_1[7] * 0x38) >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined *)puVar4 = *(undefined *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  puVar3 = (undefined4 *)param_1[0x10];
  puVar4 = *(undefined4 **)(param_1_00 + 0x40);
  for (uVar1 = (uint)(param_1[2] * 0x28) >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined *)puVar4 = *(undefined *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  puVar3 = (undefined4 *)param_1[0x11];
  puVar4 = *(undefined4 **)(param_1_00 + 0x44);
  for (uVar1 = (uint)(param_1[3] * 0x38) >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined *)puVar4 = *(undefined *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  *(undefined *)(param_1_00 + 0x4c) = *(undefined *)(param_1 + 0x13);
  *(int *)(param_1_00 + 0x1c) = param_1[7];
  return;
}

