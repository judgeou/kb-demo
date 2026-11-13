// Original FR08 function at 0040940b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_40940b(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  int local_10;
  
  DAT_005923b8 = 0xffffffff;
  DAT_005923bc = DAT_00592e0c;
  DAT_005923b4 = 0;
  DAT_005923c4 = 0;
  fr08_409553(0,&DAT_005923c0,DAT_00592e0c,DAT_00592e10);
  puVar7 = &DAT_00592e20;
  puVar6 = &DAT_005923f0;
  do {
    iVar1 = puVar7[-3];
    if (iVar1 != 0) {
      uVar2 = puVar7[-2];
      *(undefined4 *)(puVar6 + -0xc) = uVar2;
      puVar6[1] = 0;
      *puVar6 = 0;
      *(undefined4 *)(puVar6 + -8) = 0;
      fr08_409553(0,puVar6 + -4,uVar2,iVar1);
      uVar2 = puVar7[-1];
      uVar3 = *puVar7;
      *(undefined4 *)(puVar6 + 4) = uVar3;
      puVar6[0x10] = 0;
      *(undefined4 *)(puVar6 + 8) = 0;
      fr08_409553(0,puVar6 + 0xc,uVar3,uVar2);
      uVar2 = puVar7[-1];
      uVar3 = puVar7[2];
      *(undefined4 *)(puVar6 + 0x14) = uVar3;
      puVar6[0x21] = 0;
      puVar6[0x20] = 0;
      *(undefined4 *)(puVar6 + 0x18) = 0;
      fr08_409553(0,puVar6 + 0x1c,uVar3,uVar2);
      puVar5 = puVar7 + 3;
      puVar4 = (undefined4 *)(puVar6 + 0x2c);
      local_10 = 7;
      do {
        uVar2 = puVar5[1];
        uVar3 = *puVar5;
        puVar4[-2] = uVar2;
        *(undefined *)(puVar4 + 1) = 0;
        *puVar4 = 0;
        fr08_409553(0,puVar4 + -1,uVar2,uVar3);
        puVar5 = puVar5 + 2;
        puVar4 = puVar4 + 4;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
    }
    puVar7 = puVar7 + 0x14;
    puVar6 = puVar6 + 0xa0;
  } while ((int)puVar7 < 0x593320);
  DAT_005923c8 = 0xd249020;
  _DAT_005923d4 = 8;
  DAT_005923cc = 4;
  DAT_005923d0 = 4;
  _DAT_005923d8 = 0;
  DAT_005923dc = 0;
  DAT_005923e0 = 0;
  _DAT_00592dec = 0;
  fr08_40b872(DAT_00592df8);
  fr08_40be53(DAT_00592dfc);
  return;
}

