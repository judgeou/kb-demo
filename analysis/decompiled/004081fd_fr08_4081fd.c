// Original FR08 function at 004081fd

int __fastcall fr08_4081fd(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (*(int *)(param_1 + 0x1c) == *(int *)(param_1 + 0x18)) {
    iVar4 = *(int *)(param_1 + 0x18) * 2;
    if (iVar4 < 0x10) {
      iVar4 = 0x10;
    }
    puVar1 = (undefined4 *)fr08_409b9f(iVar4 * 0x38);
    puVar5 = *(undefined4 **)(param_1 + 0x3c);
    puVar6 = puVar1;
    for (uVar2 = (uint)(*(int *)(param_1 + 0x1c) * 0x38) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined *)puVar6 = *(undefined *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    fr08_409b8d(*(undefined4 *)(param_1 + 0x3c));
    *(int *)(param_1 + 0x18) = iVar4;
    *(undefined4 **)(param_1 + 0x3c) = puVar1;
  }
  iVar4 = *(int *)(param_1 + 0x1c);
  *(int *)(param_1 + 0x1c) = iVar4 + 1;
  return iVar4 * 0x38 + *(int *)(param_1 + 0x3c);
}

