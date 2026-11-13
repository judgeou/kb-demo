// Original FR08 function at 00408b25

void fr08_408b25(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  fr08_4099e3(&DAT_0040bf30,DAT_00594328);
  fr08_409b10();
  fr08_402556();
  fr08_4085c5();
  iVar6 = 1;
  if (1 < DAT_004e4ad8) {
    piVar4 = &DAT_00529368;
    iVar7 = iVar6;
    do {
      fr08_402ab5(iVar7);
      fr08_402ae7(iVar7);
      iVar1 = piVar4[-2];
      if ((*(code **)(iVar1 + 0x18) != FUN_00406c1d) || (*(int *)(iVar1 + 0x1c) != 0x19)) {
        iVar2 = *piVar4;
        iVar3 = 0;
        do {
          *(undefined *)(iVar3 + iVar2 + 3) = 0xff;
          iVar3 = iVar3 + 4;
        } while (iVar3 < 0x40000);
      }
      fr08_401558(iVar7,*piVar4);
      fr08_402a30(iVar1,5);
      iVar7 = iVar7 + 1;
      piVar4 = piVar4 + 4;
    } while (iVar7 < DAT_004e4ad8);
  }
  fr08_402a86();
  if (1 < DAT_005272e8) {
    puVar5 = &DAT_0052a468;
    iVar7 = iVar6;
    do {
      fr08_402993(*puVar5,puVar5 + 1,0);
      iVar7 = iVar7 + 1;
      puVar5 = puVar5 + 4;
    } while (iVar7 < DAT_005272e8);
  }
  if (1 < DAT_005272e8) {
    puVar5 = &DAT_0052a46c;
    iVar7 = iVar6;
    do {
      iVar1 = puVar5[-1];
      *puVar5 = *(undefined4 *)(iVar1 + 0x20);
      puVar5[1] = *(undefined4 *)(iVar1 + 0x24);
      (**(code **)(iVar1 + 0x18))(iVar1);
      puVar5[2] = 0;
      fr08_407e7d(puVar5[1]);
      fr08_402a30(iVar1,0xd);
      fr08_409e00(10);
      iVar7 = iVar7 + 1;
      puVar5 = puVar5 + 4;
    } while (iVar7 < DAT_005272e8);
  }
  if (1 < DAT_005272e8) {
    puVar5 = &DAT_0052a468;
    do {
      fr08_402a30(*puVar5,9);
      iVar6 = iVar6 + 1;
      puVar5 = puVar5 + 4;
    } while (iVar6 < DAT_005272e8);
  }
  fr08_409ac2(1000);
  fr08_409bcb(0x4b0);
  fr08_409b36();
  thunk_FUN_0040a1c9();
  fr08_4099e3(&DAT_00415637,DAT_00594328);
  fr08_4088b7();
  return;
}

