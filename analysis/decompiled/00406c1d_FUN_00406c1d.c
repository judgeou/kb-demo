// Original FR08 function at 00406c1d

void FUN_00406c1d(int *param_1)

{
  int iVar1;
  int extraout_ECX;
  code *pcVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  int iVar5;
  
  if (param_1[4] != 0) {
    param_1[4] = 0;
    fr08_409e00(1);
    iVar5 = param_1[1];
    (**(code **)(iVar5 + 0x18))(iVar5);
    (**(code **)(param_1[2] + 0x18))(param_1[2]);
    iVar1 = param_1[7];
    puVar3 = (undefined4 *)param_1[9];
    fr08_405e3b(*param_1);
    fr08_405e3b(*param_1 + 0xc);
    param_1 = (int *)iVar1;
    if (0xf < iVar1) {
      param_1 = (int *)(iVar1 + -0x10);
    }
    uVar4 = psllw(0x80008000800080,8);
    pcVar2 = (code *)&LAB_00406d39;
    if (((((param_1 != (int *)0x0) && (pcVar2 = (code *)&LAB_00406d47, param_1 != (int *)0x1)) &&
         (pcVar2 = (code *)&LAB_00406d55, param_1 != (int *)0x2)) &&
        ((pcVar2 = (code *)&LAB_00406d63, param_1 != (int *)0x3 &&
         (pcVar2 = (code *)&LAB_00406d74, param_1 != (int *)0x4)))) &&
       ((pcVar2 = (code *)&LAB_00406d8a, param_1 != (int *)0x5 &&
        ((pcVar2 = (code *)&LAB_00406da3, param_1 != (int *)0x6 &&
         (pcVar2 = (code *)&LAB_00406d74, param_1 != (int *)0x7)))))) {
      paddusw(uVar4,uVar4);
      pcVar2 = (code *)&DAT_00406d71;
      if (param_1 != (int *)0x8) {
        FUN_00406de3(iVar5);
        return;
      }
    }
    do {
      uVar4 = (*pcVar2)();
      pcVar2 = (code *)((ulonglong)uVar4 >> 0x20);
      *puVar3 = (int)uVar4;
      puVar3 = puVar3 + 1;
    } while (extraout_ECX != 1);
  }
  return;
}

