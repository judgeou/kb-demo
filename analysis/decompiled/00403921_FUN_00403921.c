// Original FR08 function at 00403921

void FUN_00403921(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    (**(code **)(*(int *)(param_1 + 4) + 0x18))(*(int *)(param_1 + 4));
    (**(code **)(*(int *)(param_1 + 8) + 0x18))(*(int *)(param_1 + 8));
    iVar1 = *(int *)(param_1 + 0x24);
    piVar2 = *(int **)(*(int *)(param_1 + 4) + 0x24);
    piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x24);
    if ((*(byte *)(param_1 + 0x14) & 2) == 0) {
      fr08_408005(*piVar3 + *piVar2,piVar2[1] + piVar3[1],piVar3[7] + piVar2[7],
                  piVar2[2] + piVar3[2],0);
      puVar7 = (undefined4 *)piVar2[0xd];
      puVar8 = *(undefined4 **)(iVar1 + 0x34);
      for (uVar4 = (uint)(*piVar2 * 0x2c) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined *)puVar8 = *(undefined *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      puVar7 = (undefined4 *)piVar3[0xd];
      puVar8 = (undefined4 *)(*piVar2 * 0x2c + *(int *)(iVar1 + 0x34));
      for (uVar4 = (uint)(*piVar3 * 0x2c) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined *)puVar8 = *(undefined *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      puVar7 = (undefined4 *)piVar2[0xe];
      puVar8 = *(undefined4 **)(iVar1 + 0x38);
      for (uVar4 = (uint)(piVar2[1] * 0x1c) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined *)puVar8 = *(undefined *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      puVar7 = (undefined4 *)piVar3[0xe];
      puVar8 = (undefined4 *)(piVar2[1] * 0x1c + *(int *)(iVar1 + 0x38));
      for (uVar4 = (uint)(piVar3[1] * 0x1c) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined *)puVar8 = *(undefined *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      puVar7 = (undefined4 *)piVar2[0xf];
      puVar8 = *(undefined4 **)(iVar1 + 0x3c);
      for (uVar4 = (uint)(piVar2[7] * 0x38) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined *)puVar8 = *(undefined *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      puVar7 = (undefined4 *)piVar3[0xf];
      puVar8 = (undefined4 *)(piVar2[7] * 0x38 + *(int *)(iVar1 + 0x3c));
      for (uVar4 = (uint)(piVar3[7] * 0x38) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined *)puVar8 = *(undefined *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      *(int *)(iVar1 + 0x1c) = piVar3[7] + piVar2[7];
      puVar7 = (undefined4 *)piVar2[0x10];
      puVar8 = *(undefined4 **)(iVar1 + 0x40);
      for (uVar4 = (uint)(piVar2[2] * 0x28) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined *)puVar8 = *(undefined *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      puVar7 = (undefined4 *)piVar3[0x10];
      puVar8 = (undefined4 *)(*(int *)(iVar1 + 0x40) + piVar2[2] * 0x28);
      for (uVar4 = (uint)(piVar3[2] * 0x28) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined *)puVar8 = *(undefined *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      iVar5 = piVar2[1];
      if (iVar5 < *(int *)(iVar1 + 4)) {
        iVar6 = iVar5 * 0x1c;
        do {
          piVar3 = (int *)(*(int *)(iVar1 + 0x38) + iVar6);
          *piVar3 = *piVar3 + *piVar2;
          piVar3 = (int *)(iVar6 + 4 + *(int *)(iVar1 + 0x38));
          *piVar3 = *piVar3 + *piVar2;
          piVar3 = (int *)(iVar6 + 8 + *(int *)(iVar1 + 0x38));
          *piVar3 = *piVar3 + *piVar2;
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0x1c;
        } while (iVar5 < *(int *)(iVar1 + 4));
      }
      iVar5 = piVar2[2];
      if (iVar5 < *(int *)(iVar1 + 8)) {
        iVar6 = iVar5 * 0x28;
        do {
          piVar3 = (int *)(*(int *)(iVar1 + 0x40) + iVar6);
          *piVar3 = *piVar3 + *piVar2;
          piVar3 = (int *)(iVar6 + 8 + *(int *)(iVar1 + 0x40));
          *piVar3 = *piVar3 + piVar2[1];
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0x28;
        } while (iVar5 < *(int *)(iVar1 + 8));
      }
    }
    else {
      fr08_408005(0,0,0,0,2);
      **(int ***)(iVar1 + 0x44) = piVar2;
      *(int **)(*(int *)(iVar1 + 0x44) + 0x38) = piVar3;
    }
  }
  return;
}

