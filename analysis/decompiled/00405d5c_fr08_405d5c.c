// Original FR08 function at 00405d5c

void __fastcall fr08_405d5c(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = param_1 + 0x12;
  puVar1 = param_1 + 3;
  iVar3 = 2;
  do {
    puVar1[-1] = 0;
    *puVar1 = 0x3f800000;
    puVar1[1] = 0x3f800000;
    puVar1[2] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0x3f800000;
    puVar1[10] = 0x3f800000;
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
    puVar1 = puVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_1 = 1;
  param_1[0x15] = 0;
  param_1[1] = 0;
  param_1[0x14] = 0;
  param_1[0x16] = 0;
  param_1[0x19] = 0;
  param_1[0x17] = 0x3f800000;
  param_1[0x18] = 0x3f800000;
  return;
}

