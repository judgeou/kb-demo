// Original FR08 function at 00407605

void fr08_407605(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int local_8;
  
  iVar2 = param_1;
  iVar7 = 0;
  if (param_1 != 0) {
    fr08_40831a();
    piVar1 = (int *)(param_1 + 0xc);
    uVar6 = 1;
    param_1 = 0;
    if (0 < *piVar1) {
      iVar3 = *(int *)(iVar2 + 0x44);
      do {
        fr08_407605(*(undefined4 *)(iVar7 + iVar3));
        iVar3 = *(int *)(iVar2 + 0x44);
        piVar1 = (int *)(iVar7 + iVar3);
        iVar7 = iVar7 + 0x38;
        uVar6 = uVar6 | *(uint *)(*piVar1 + 0x28);
        param_1 = param_1 + 1;
      } while (param_1 < *(int *)(iVar2 + 0xc));
    }
    if (((*(byte *)(*(int *)(iVar2 + 0x20) + 0x14) & 8) == 0) || (*(int *)(iVar2 + 0x30) != 0)) {
      iVar7 = *(int *)(iVar2 + 8);
      if (0 < iVar7) {
        puVar5 = (undefined4 *)(*(int *)(iVar2 + 0x40) + 0x14);
        do {
          uVar4 = *puVar5;
          puVar5 = puVar5 + 10;
          uVar6 = uVar6 | 1 << ((byte)uVar4 & 0x1f);
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
    }
    else {
      *(undefined *)(iVar2 + 0x24) = 1;
      local_8 = 0;
      if (0 < *(int *)(iVar2 + 8)) {
        param_1 = 0;
        do {
          iVar7 = param_1 + *(int *)(iVar2 + 0x40);
          uVar6 = uVar6 | 1 << ((byte)*(undefined4 *)(iVar7 + 0x14) & 0x1f);
          if (*(int *)(iVar7 + 0x1c) == 0) {
            uVar4 = fr08_401faa(*(undefined4 *)(iVar7 + 4),*(int *)(iVar7 + 0xc) * 3,0);
            *(undefined4 *)(iVar7 + 0x20) = 0;
            *(undefined4 *)(iVar7 + 0x1c) = uVar4;
            fr08_4076ed(iVar2,iVar7,1);
            fr08_4021ce(uVar4,0);
          }
          local_8 = local_8 + 1;
          param_1 = param_1 + 0x28;
        } while (local_8 < *(int *)(iVar2 + 8));
      }
    }
    *(uint *)(iVar2 + 0x28) = uVar6;
  }
  return;
}

