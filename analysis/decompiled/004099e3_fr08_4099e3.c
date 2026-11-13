// Original FR08 function at 004099e3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_4099e3(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  DAT_00592e00 = *param_1;
  DAT_00592e04 = DAT_00592e00 * 10000;
  _DAT_00592e08 = param_1[1];
  DAT_00592e10 = param_1[2];
  DAT_00592e0c = param_1 + 3;
  piVar3 = (int *)((int)DAT_00592e0c + DAT_00592e10 * 10);
  piVar2 = &DAT_00592e1c;
  do {
    iVar1 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar2[-2] = iVar1;
    if (iVar1 != 0) {
      piVar2[-1] = (int)piVar3;
      piVar3 = (int *)((int)piVar3 + iVar1 * 5);
      iVar5 = 7;
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar2[1] = (int)piVar3;
      *piVar2 = iVar1;
      piVar3 = piVar3 + iVar1;
      iVar1 = *piVar3;
      piVar2[3] = (int)(piVar3 + 1);
      piVar3 = (int *)((int)(piVar3 + 1) + iVar1 * 5);
      piVar2[2] = iVar1;
      piVar4 = piVar2 + 4;
      do {
        iVar1 = *piVar3;
        *piVar4 = iVar1;
        piVar4[1] = (int)(piVar3 + 1);
        piVar4 = piVar4 + 2;
        iVar5 = iVar5 + -1;
        piVar3 = piVar3 + 1 + iVar1;
      } while (iVar5 != 0);
    }
    piVar2 = piVar2 + 0x14;
  } while ((int)piVar2 < 0x59331c);
  DAT_00592dfc = piVar3 + 1;
  DAT_00592df8 = *piVar3 + 4 + (int)DAT_00592dfc;
  fr08_40940b();
  DAT_00592de8 = 0;
  DAT_00592de4 = 0;
  DAT_005923b0 = 0;
  DAT_005923b1 = 1;
  fr08_40a092(FUN_0040990e,param_2);
  fr08_40a381(0x3f800000);
  return;
}

