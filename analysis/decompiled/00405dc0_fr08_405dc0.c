// Original FR08 function at 00405dc0

void __fastcall fr08_405dc0(int param_1)

{
  fr08_40100b();
  *(undefined4 *)(param_1 + 0x5c) = 1;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  return;
}

