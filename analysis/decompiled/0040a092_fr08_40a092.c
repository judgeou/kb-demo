// Original FR08 function at 0040a092

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 fr08_40a092(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 in_EAX;
  int **ppiVar3;
  int iVar4;
  int iVar5;
  int **unaff_EBP;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  byte bVar11;
  bool bVar12;
  
  puVar7 = &DAT_00594338;
  for (iVar4 = 0x10008a; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined *)puVar7 = 0;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  DAT_00594344 = param_1;
  DAT_00594340 = (undefined4 *)0x0;
  iVar4 = FUN_00443414(0,&DAT_00594340,0);
  puVar2 = DAT_00594340;
  bVar12 = DAT_00594340 == (undefined4 *)0x0;
  ppiVar3 = unaff_EBP;
  if (!bVar12) {
    puVar7 = (undefined4 *)*DAT_00594340;
    iVar4 = (*(code *)puVar7[6])(DAT_00594340,in_EAX,2);
    bVar12 = iVar4 == 0;
    if (bVar12) {
      ppiVar3 = (int **)&DAT_0059433c;
      iVar4 = (*(code *)puVar7[3])(puVar2,&DAT_0040a3e4,&DAT_0059433c,0);
      bVar12 = iVar4 == 0;
    }
  }
  if (bVar12) {
    iVar4 = (*(code *)puVar7[3])(puVar2,&DAT_0040a3d0,&DAT_00594338,iVar4);
    bVar12 = iVar4 == 0;
  }
  do {
    if (!bVar12) goto LAB_0040a1bd;
    puVar6 = &DAT_0040a3be;
    puVar8 = &DAT_005943b0;
    for (iVar4 = iVar4 + 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    (**(code **)(**ppiVar3 + 0x38))(*ppiVar3,&DAT_005943b0);
    ppiVar3 = DAT_00594338;
    piVar1 = *DAT_00594338;
    iVar4 = (*(code *)piVar1[0xb])
                      (DAT_00594338,0,0,&DAT_00594360,&DAT_00594364,&DAT_00594368,&DAT_0059436c,2);
    bVar12 = iVar4 == 0;
    iVar5 = DAT_00594364;
    puVar9 = DAT_00594360;
  } while (!bVar12);
  for (; iVar4 = DAT_0059436c, puVar10 = DAT_00594368, iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  iVar4 = (*(code *)piVar1[0x13])(ppiVar3,DAT_00594360,DAT_00594364,DAT_00594368,DAT_0059436c);
  if (iVar4 == 0) {
    DAT_005943a8 = 0xfffe0000;
    DAT_005943ac = 0xfffe0000;
    DAT_00594380 = FUN_004433fc(0,0,0,0);
    FUN_004433e4(&DAT_00594388);
    ppiVar3 = (int **)(*(code *)piVar1[0xc])(ppiVar3,0,0,1,1);
    if (ppiVar3 == (int **)0x0) {
      DAT_00594348 = _DAT_0040a060;
      unaff_EBP = ppiVar3;
      DAT_0059435c = FUN_004433d2(0,0,&LAB_0040a212,0,0,&DAT_0059437c);
      FUN_004433de(DAT_0059435c,(int)ppiVar3 + 1);
      bVar11 = 1;
      goto LAB_0040a1c4;
    }
  }
LAB_0040a1bd:
  FUN_0040a1c9();
  bVar11 = 0;
LAB_0040a1c4:
  return CONCAT44(unaff_EBP,-(uint)bVar11);
}

