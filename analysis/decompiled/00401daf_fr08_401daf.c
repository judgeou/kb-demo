// Original FR08 function at 00401daf

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_401daf(void)

{
  (**(code **)(*DAT_0049303c + 0x3c))(DAT_0049303c,0,0,0,0);
  _DAT_00594330 = Original_DemoTimeMilliseconds();
  return;
}

