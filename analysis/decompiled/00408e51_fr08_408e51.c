// Original FR08 function at 00408e51

void __thiscall fr08_408e51(int param_1_00,undefined4 *param_1)

{
  *(undefined4 *)(param_1_00 + 0xc) = 0;
  *(undefined4 *)(param_1_00 + 0x10) = 0x3f800000;
  *(undefined4 *)(param_1_00 + 0x14) = 0;
  *(undefined4 *)(param_1_00 + 0x18) = *param_1;
  *(undefined4 *)(param_1_00 + 0x1c) = param_1[1];
  *(undefined4 *)(param_1_00 + 0x20) = param_1[2];
  fr08_408d27();
  fr08_404a89((undefined4 *)(param_1_00 + 0xc),param_1_00 + 0x18);
  fr08_408d27();
  fr08_404a89(param_1_00 + 0x18,param_1_00);
  fr08_408d27();
  return;
}

