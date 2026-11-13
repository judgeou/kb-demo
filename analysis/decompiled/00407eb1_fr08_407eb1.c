// Original FR08 function at 00407eb1

void fr08_407eb1(undefined4 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_c4 [10];
  undefined local_9c [40];
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68 [7];
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40 [12];
  float local_10;
  float local_c;
  float local_8;
  
  puVar3 = param_1;
  puVar4 = local_68;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = local_40;
  puVar4 = local_c4;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  local_10 = *(float *)(param_2 + 0x1c);
  local_c = *(float *)(param_2 + 0x20);
  local_8 = *(float *)(param_2 + 0x24);
  fr08_408d82(local_c4);
  local_4c = local_10 + local_4c;
  local_48 = local_48 + local_c;
  local_44 = local_44 + local_8;
  fr08_408f2c(local_c4,param_2 + 0x28);
  iVar2 = 0;
  if (0 < (int)param_1[0x19]) {
    puVar3 = param_1 + 0x1a;
    do {
      fr08_407eb1(*puVar3,local_68);
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < (int)param_1[0x19]);
  }
  DAT_00591ee0 = 0;
  if (param_1[0x16] != 0) {
    local_74 = 0;
    local_70 = 0;
    local_6c = 0;
    fr08_408e20();
    puVar3 = local_68;
    puVar4 = &DAT_005292f8;
    for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    cVar1 = fr08_401812(param_1[0x18],local_68);
    if (cVar1 != '\0') {
      iVar2 = 0;
      DAT_00591ee0 = 0;
      do {
        fr08_407a97(param_1[0x16],local_9c,iVar2);
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x20);
      fr08_401d97();
    }
  }
  iVar2 = 0;
  if (0 < (int)param_1[0x3a]) {
    do {
      fr08_407cb7();
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[0x3a]);
  }
  return;
}

