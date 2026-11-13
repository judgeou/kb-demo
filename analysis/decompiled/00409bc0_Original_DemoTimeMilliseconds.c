// Original FR08 function at 00409bc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Original_DemoTimeMilliseconds(void)

{
  int iVar1;
  
  iVar1 = Original_DSoundTimeBytes();
  return (int)(((longlong)(iVar1 - _DAT_00592df0) * 1000) / 0x2b110);
}

