// Original FR08 function at 00409d6e

void fr08_409d6e(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  short sVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  iVar4 = fr08_402073(4,6,1);
  puVar8 = *(undefined4 **)(iVar4 + 0x30);
  uVar2 = *(undefined4 *)(iVar4 + 4);
  psVar3 = *(short **)(iVar4 + 0x34);
  uVar5 = 0;
  puVar9 = puVar8;
  for (iVar6 = 0x24; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  do {
    if ((uVar5 & 2) == 0) {
      uVar1 = param_1[2];
    }
    else {
      uVar1 = *param_1;
    }
    *puVar8 = uVar1;
    uVar5 = uVar5 + 1;
    if ((uVar5 & 2) == 0) {
      uVar1 = param_1[3];
    }
    else {
      uVar1 = param_1[1];
    }
    puVar8[1] = uVar1;
    puVar8[3] = param_2;
    puVar8[2] = 0x3f800000;
    puVar8 = puVar8 + 9;
  } while ((int)uVar5 < 4);
  sVar7 = (short)uVar2;
  *psVar3 = sVar7;
  psVar3[1] = sVar7 + 1;
  psVar3[2] = sVar7 + 2;
  psVar3[3] = sVar7;
  psVar3[4] = sVar7 + 2;
  psVar3[5] = sVar7 + 3;
  fr08_4021ce(iVar4,1);
  return;
}

