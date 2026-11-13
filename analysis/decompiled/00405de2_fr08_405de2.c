// Original FR08 function at 00405de2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint fr08_405de2(float *param_1,int param_2)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_c;
  
  uVar3 = 0xff;
  if (0 < param_2) {
    do {
      fVar1 = *param_1;
      param_1 = param_1 + 1;
      local_c = (undefined4)(longlong)ROUND(fVar1 * _DAT_004441a0);
      uVar2 = fr08_405e21(local_c);
      uVar3 = uVar3 << 8 | uVar2;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return uVar3;
}

