// Original FR08 function at 0040b872

undefined8 __fastcall fr08_40b872(undefined4 param_1_00,undefined4 param_2,undefined4 param_1)

{
  undefined4 in_EAX;
  int iVar1;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined *puVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_00715c08;
  for (iVar1 = 0x11388; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  DAT_00715c08 = param_1;
  do {
    fr08_40acb3();
    (&DAT_00715c10)[extraout_ECX] = 0xffffffff;
  } while (extraout_ECX != 1);
  iVar1 = 0;
  puVar2 = &DAT_00718cd8;
  do {
    (&DAT_00715c9b)[iVar1 * 8] = 0x7f;
    *(undefined **)(puVar2 + 0x44) = &DAT_006d43c4 + iVar1 * 0x4000;
    *(int *)(puVar2 + 0x48) = iVar1 * 0x4000 + 0x6d63c4;
    *(undefined4 *)(puVar2 + 0x4c) = 0x7ff;
    fr08_40b561();
    puVar2 = puVar2 + 0x78;
    iVar1 = extraout_ECX_00 + 1;
  } while ((char)iVar1 != '\x10');
  fr08_40b2c2();
  DAT_00726f44 = &DAT_006943c4;
  DAT_00726f48 = &DAT_006b43c4;
  DAT_00726f4c = 0x7fff;
  fr08_40b0a6();
  fr08_40b785();
  return CONCAT44(param_2,in_EAX);
}

