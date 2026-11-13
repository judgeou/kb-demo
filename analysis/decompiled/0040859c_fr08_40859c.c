// Original FR08 function at 0040859c

void __fastcall fr08_40859c(int param_1)

{
  if (*(int *)(param_1 + 0x38) != 0) {
    fr08_409b8d(*(int *)(param_1 + 0x38));
  }
  if (*(int *)(param_1 + 0x34) != 0) {
    fr08_409b8d(*(int *)(param_1 + 0x34));
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return;
}

