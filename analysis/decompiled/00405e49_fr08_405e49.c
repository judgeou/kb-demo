// Original FR08 function at 00405e49

uint fr08_405e49(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = fr08_405de2(param_1,4);
  return uVar1 << 0x18 | uVar1 >> 8;
}

