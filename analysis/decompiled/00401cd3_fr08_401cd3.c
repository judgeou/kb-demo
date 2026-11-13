// Original FR08 function at 00401cd3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_401cd3(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_44 [10];
  float local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_1c = (float)param_1[10];
  uStack_18 = param_1[0xb];
  uStack_14 = param_1[0xc];
  puVar2 = param_1;
  puVar3 = local_44;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if (param_2 != 0) {
    puVar2 = &DAT_004cca70;
    puVar3 = local_44;
    for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    if (param_2 == 2) {
      local_10 = (float)param_1[10] - _DAT_004cca64;
      local_c = (float)param_1[0xb] - _DAT_004cca68;
      local_8 = (float)param_1[0xc] - _DAT_004cca6c;
      fr08_408dd1(local_44);
      fr08_409036((local_8 * _DAT_004440f4) / DAT_004cca48);
    }
  }
  puVar2 = local_44;
  puVar3 = &DAT_004ccaa8;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_004cc678 = local_1c;
  DAT_004cc67c = uStack_18;
  DAT_0045b01c = param_2;
  DAT_004cc680 = uStack_14;
  fr08_4016ad(local_44,&local_1c,0x100);
  return;
}

