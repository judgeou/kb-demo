// Original FR08 function at 00402993

void fr08_402993(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    *(undefined4 *)(param_1 + 0xc) = param_3;
    if (*(int *)(param_1 + 4) != 0) {
      fr08_402993(*(int *)(param_1 + 4),param_1 + 0x20,param_1);
    }
    if (*(int *)(param_1 + 8) != 0) {
      fr08_402993(*(int *)(param_1 + 8),param_1 + 0x20,param_1);
    }
    if ((*(byte *)(param_1 + 0x14) & 1) == 0) {
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x20);
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x24);
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if (iVar1 != 1) {
        if (iVar1 == 2) {
          uVar2 = fr08_409b9f(0x50);
          *(undefined4 *)(param_1 + 0x24) = uVar2;
          fr08_407fd1();
          *(int *)(*(int *)(param_1 + 0x24) + 0x20) = param_1;
          return;
        }
        if (iVar1 != 3) {
          return;
        }
        uVar2 = fr08_409b9f(0xe14);
        *(undefined4 *)(param_1 + 0x24) = uVar2;
        fr08_405dc0();
        return;
      }
      uVar2 = fr08_409b9f(0x100000);
    }
    *(undefined4 *)(param_1 + 0x24) = uVar2;
  }
  return;
}

