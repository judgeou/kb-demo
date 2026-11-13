// Original FR08 function at 004092bc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_4092bc(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  
  param_2 = param_2 * 0x38;
  *(float *)(&DAT_005922f8 + param_2) = (float)(uint)*(byte *)(param_1 + 3);
  fVar2 = _DAT_00444348;
  *(float *)(&DAT_005922fc + param_2) = (float)(uint)*(ushort *)(param_1 + 4) * _DAT_00444348;
  fVar1 = _DAT_00444344;
  *(float *)(&DAT_00592300 + param_2) = (float)(uint)*(byte *)(param_1 + 6) * _DAT_00444344;
  *(float *)(&DAT_00592304 + param_2) = (float)(uint)*(byte *)(param_1 + 7) * fVar1;
  *(float *)(&DAT_00592308 + param_2) = (float)(uint)*(ushort *)(param_1 + 8) * fVar2;
  *(float *)(&DAT_0059230c + param_2) = (float)(uint)*(byte *)(param_1 + 10) * fVar1;
  *(float *)(&DAT_00592310 + param_2) = (float)(uint)*(byte *)(param_1 + 0xb) * fVar1;
  *(float *)(&DAT_00592314 + param_2) = (float)(uint)*(ushort *)(param_1 + 0xc) * fVar2;
  *(float *)(&DAT_00592318 + param_2) = (float)(uint)*(byte *)(param_1 + 0xe) * fVar1;
  *(float *)(&DAT_0059231c + param_2) = (float)(uint)*(byte *)(param_1 + 0xf) * fVar1;
  *(float *)(&DAT_00592320 + param_2) = (float)(uint)*(ushort *)(param_1 + 0x10) * fVar2;
  *(float *)(&DAT_00592324 + param_2) = (float)(uint)*(byte *)(param_1 + 0x12) * fVar1;
  *(float *)(&DAT_00592328 + param_2) = (float)(uint)*(byte *)(param_1 + 0x13) * fVar1;
  *(float *)(&DAT_0059232c + param_2) = (float)(uint)*(byte *)(param_1 + 0x14) * fVar1;
  return;
}

