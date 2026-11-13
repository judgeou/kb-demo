// Original FR08 function at 0040100b

void __fastcall fr08_40100b(undefined4 *param_1)

{
  param_1[1] = 0x44fa0000;
  param_1[2] = 0x3dcccccd;
  *param_1 = 0x3f800000;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x3f800000;
  param_1[6] = 0x3f800000;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  fr08_408e20();
  param_1[0x14] = 0xff000000;
  param_1[0x15] = 3;
  return;
}

