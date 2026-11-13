// Original FR08 function at 004087e5

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 fr08_4087e5(int param_1,float param_2)

{
  int iVar1;
  short *psVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  float10 fVar6;
  ulonglong local_c;
  
  iVar1 = *(int *)(param_1 + 0x10);
  local_c._0_4_ = (int)(longlong)ROUND(param_2 * _DAT_004441d8);
  if (1 < iVar1) {
    psVar2 = *(short **)(param_1 + 0xc);
    if ((int)local_c <= *psVar2) {
      return (float10)*(float *)(psVar2 + 2);
    }
    if (psVar2[iVar1 * 0xc + -0xc] <= (int)local_c) {
      return (float10)*(float *)(psVar2 + iVar1 * 0xc + -10);
    }
    iVar4 = 0;
    psVar3 = psVar2;
    if (0 < iVar1 + -1) {
      do {
        if ((int)local_c < psVar3[0xc]) {
          uVar5 = (uint)psVar2[iVar4 * 0xc];
          if (uVar5 == (int)psVar2[(iVar4 * 3 + 3) * 4]) {
            return (float10)*(float *)(psVar2 + iVar4 * 0xc + 2);
          }
          local_c = (ulonglong)uVar5;
          fVar6 = ((float10)(param_2 * _DAT_004441d8) - (float10)local_c) /
                  (float10)((int)psVar2[(iVar4 * 3 + 3) * 4] - uVar5);
          return ((fVar6 * (float10)*(float *)(psVar2 + iVar4 * 0xc + 10) +
                  (float10)*(float *)(psVar2 + iVar4 * 0xc + 8)) * fVar6 +
                 (float10)*(float *)(psVar2 + iVar4 * 0xc + 6)) * fVar6 +
                 (float10)*(float *)(psVar2 + iVar4 * 0xc + 4);
        }
        iVar4 = iVar4 + 1;
        psVar3 = psVar3 + 0xc;
      } while (iVar4 < iVar1 + -1);
    }
  }
  return (float10)_DAT_004440e8;
}

