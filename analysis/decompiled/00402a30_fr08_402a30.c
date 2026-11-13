// Original FR08 function at 00402a30

void fr08_402a30(int param_1,uint param_2)

{
  if (*(int *)(param_1 + 4) != 0) {
    fr08_402a30(*(int *)(param_1 + 4),param_2);
  }
  if (*(int *)(param_1 + 8) != 0) {
    fr08_402a30(*(int *)(param_1 + 8),param_2);
  }
  if (((*(uint *)(param_1 + 0x14) & param_2) == param_2) && (*(int *)(param_1 + 0x24) != 0)) {
    if (*(int *)(param_1 + 0x20) == 1) {
      fr08_409b8d(*(int *)(param_1 + 0x24));
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    else if (*(int *)(param_1 + 0x20) == 2) {
      fr08_40859c();
    }
  }
  return;
}

