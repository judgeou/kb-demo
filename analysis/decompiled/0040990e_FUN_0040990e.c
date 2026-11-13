// Original FR08 function at 0040990e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040990e(undefined4 *param_1,uint param_2)

{
  ulonglong uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  if (DAT_005923b0 == '\0') {
    if (DAT_005923b1 == '\0') {
      fr08_40b923(param_1,param_2);
      goto LAB_004099d6;
    }
  }
  else if (DAT_005923b1 == '\0') {
    if (param_2 == 0) {
      return;
    }
    do {
      uVar3 = DAT_00592de8;
      if (param_2 <= DAT_00592de8) {
        uVar3 = param_2;
      }
      if (uVar3 != 0) {
        fr08_40b923(param_1,uVar3);
      }
      param_2 = param_2 - uVar3;
      DAT_00592de8 = DAT_00592de8 - uVar3;
      DAT_00592de4 = DAT_00592de4 + uVar3;
      param_1 = param_1 + uVar3 * 2;
      if (DAT_00592de8 == 0) {
        fr08_4095a5();
        if (DAT_005923b0 == '\0') {
          DAT_00592de8 = 0xffffffff;
        }
        else {
          uVar1 = (ulonglong)(uint)(DAT_005923b8 - DAT_005923b4) * (ulonglong)DAT_005923c8;
          uVar3 = (uint)(uVar1 % (ulonglong)DAT_00592e04);
          bVar4 = CARRY4(_DAT_00592dec,uVar3);
          _DAT_00592dec = _DAT_00592dec + uVar3;
          DAT_00592de8 = (int)(uVar1 / DAT_00592e04) + (uint)bVar4;
        }
      }
    } while (param_2 != 0);
    return;
  }
  for (iVar2 = param_2 << 1; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
LAB_004099d6:
  DAT_00592de4 = DAT_00592de4 + param_2;
  return;
}

