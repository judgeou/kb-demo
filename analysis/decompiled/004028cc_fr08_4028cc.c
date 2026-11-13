// Original FR08 function at 004028cc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 fr08_4028cc(byte **param_1)

{
  byte *pbVar1;
  byte **ppbVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  float10 fVar7;
  
  ppbVar2 = param_1;
  pbVar1 = *param_1;
  uVar4 = (uint)*pbVar1;
  if (uVar4 == 0) {
    fVar7 = (float10)0;
  }
  else {
    if (uVar4 != 1) {
      if (uVar4 != 2) {
        param_1 = (byte **)0x0;
        if ((uVar4 < 3) || (9 < uVar4)) {
          uVar6 = 0;
        }
        else {
          param_1 = (byte **)0x1;
          uVar6 = uVar4;
        }
        uVar4 = 0xff - uVar4;
        if ((2 < (int)uVar4) && ((int)uVar4 < 10)) {
          param_1 = (byte **)0xffffffff;
          uVar6 = uVar4;
        }
        if (param_1 != (byte **)0x0) {
          fVar7 = (float10)(uint)pbVar1[1];
          if (3 < (int)uVar6) {
            iVar5 = uVar6 - 3;
            do {
              fVar7 = fVar7 * (float10)_DAT_00444100;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          *ppbVar2 = pbVar1 + 2;
          return (float10)(int)param_1 * fVar7;
        }
        param_1 = (byte **)CONCAT13(*pbVar1,CONCAT12(pbVar1[1],CONCAT11(pbVar1[2],pbVar1[3])));
        *ppbVar2 = pbVar1 + 4;
        return (float10)(float)param_1;
      }
      pbVar3 = pbVar1 + 2;
      fVar7 = (float10)(uint)pbVar1[1] * (float10)_DAT_00444108;
      goto LAB_00402909;
    }
    fVar7 = (float10)1;
  }
  pbVar3 = pbVar1 + 1;
LAB_00402909:
  *param_1 = pbVar3;
  return fVar7;
}

