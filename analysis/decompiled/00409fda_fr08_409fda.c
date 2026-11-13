// Original FR08 function at 00409fda

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall fr08_409fda(undefined4 param_1_00,float param_1)

{
  int iVar1;
  
  iVar1 = fr08_409fb1(param_1_00);
  return (float10)(iVar1 * 3 & 0xffff) * (float10)param_1 * (float10)_DAT_004441d4;
}

