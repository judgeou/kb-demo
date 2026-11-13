// Original FR08 function at 00408caa

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_408caa(int param_1)

{
  if (param_1 == 0x61) {
    _DAT_00591eec = _DAT_00591eec - _DAT_00444190;
  }
  else if (param_1 == 0x66) {
    DAT_005922f0 = (uint)(DAT_005922f0 == 0);
    DAT_00591ee8 = Original_DemoTimeMilliseconds();
  }
  else if (param_1 == 0x72) {
    fr08_4088b7();
  }
  else if (param_1 == 0x73) {
    _DAT_00591eec = _DAT_00591eec + _DAT_00444190;
  }
  return;
}

