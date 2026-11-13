// Original FR08 function at 00406173

void fr08_406173(int param_1,uint param_2,uint param_3,undefined param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (param_3 & 0xff) * 0x100 + (param_2 & 0xff);
  iVar2 = *(int *)(param_1 + 0x24);
  *(undefined *)(iVar2 + 3 + iVar3 * 4) = 0xff;
  puVar1 = (undefined *)(iVar2 + iVar3 * 4);
  *puVar1 = param_4;
  puVar1[1] = param_4;
  puVar1[2] = param_4;
  return;
}

