// Original FR08 function at 0040172c

void fr08_40172c(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 < 0) {
    if (param_2 < 0xf0) {
      return;
    }
  }
  else if (param_2 < 0xf0) {
    uVar2 = (&DAT_004cc684)[param_2];
    iVar1 = *DAT_0049303c;
    goto LAB_0040176a;
  }
  if (0xf2 < param_2) {
    return;
  }
  uVar2 = *(undefined4 *)(&DAT_004cbaa0 + param_2 * 4);
  iVar1 = *DAT_0049303c;
LAB_0040176a:
  (**(code **)(iVar1 + 0xf4))(DAT_0049303c,param_1,uVar2);
  return;
}

