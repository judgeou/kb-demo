// Original FR08 function at 00402ab5

void fr08_402ab5(int param_1)

{
  int iVar1;
  
  iVar1 = (&DAT_00529350)[param_1 * 4];
  if (iVar1 != 0) {
    fr08_402993(iVar1,&DAT_00529354 + param_1 * 4,0);
    (&DAT_00529354)[param_1 * 4] = *(undefined4 *)(iVar1 + 0x20);
    (&DAT_00529358)[param_1 * 4] = *(undefined4 *)(iVar1 + 0x24);
  }
  return;
}

