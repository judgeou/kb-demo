// Original FR08 function at 00402ae7

void fr08_402ae7(int param_1)

{
  int iVar1;
  
  iVar1 = (&DAT_00529350)[param_1 * 4];
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) != 0)) {
    (**(code **)(iVar1 + 0x18))(iVar1);
  }
  *(undefined4 *)(&DAT_0052935c + param_1 * 0x10) = 0;
  return;
}

