// Original FR08 function at 00402556

void fr08_402556(void)

{
  ushort uVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int **ppiVar8;
  undefined4 *puVar9;
  int iVar10;
  byte *pbVar11;
  byte **ppbVar12;
  float *pfVar13;
  undefined4 *puVar14;
  int iVar15;
  bool bVar16;
  float10 fVar17;
  undefined4 *local_10;
  int local_c;
  int *local_8;
  
  bVar16 = DAT_00445010 != '\0';
  puVar14 = &DAT_0052b458;
  for (iVar5 = 0x16000; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  DAT_00583458 = 0;
  DAT_005282ec = 0;
  local_c = 0;
  piVar6 = (int *)&DAT_00445010;
  puVar14 = &DAT_004e72e0;
  if (bVar16) {
    puVar9 = &DAT_0052b48c;
    piVar7 = piVar6;
    do {
      piVar6 = piVar7 + 3;
      puVar9[-2] = puVar14;
      puVar14 = puVar14 + *(byte *)(piVar7 + 1);
      if (*(short *)(piVar7 + 2) != 0) {
        puVar9[-1] = &DAT_0052b484 + (*(short *)(piVar7 + 2) + local_c) * 0xb;
      }
      if (*(short *)((int)piVar7 + 10) != 0) {
        *puVar9 = &DAT_0052b484 + (*(short *)((int)piVar7 + 10) + local_c) * 0xb;
      }
      puVar9[1] = 0;
      puVar9[3] = (int)(char)*(byte *)((int)piVar7 + 2);
      puVar9[4] = *(undefined4 *)((uint)*(byte *)piVar7 * 4 + 0x45ab28);
      puVar9[5] = (uint)*(byte *)((int)piVar7 + 1);
      puVar9[8] = (uint)*(byte *)((int)piVar7 + 5);
      puVar9[6] = (uint)*(byte *)((int)piVar7 + 3);
      if (*(byte *)((int)piVar7 + 3) == 1) {
        DAT_00583458 = DAT_00583458 + 1;
      }
      puVar9[2] = 1;
      puVar9 = puVar9 + 0xb;
      DAT_005282ec = DAT_005282ec + 1;
      local_c = local_c + 1;
      piVar7 = piVar6;
      local_10 = puVar14;
    } while (*(byte *)piVar6 != 0);
  }
  DAT_005272e8 = 1;
  DAT_004e4ad8 = 1;
  while( true ) {
    iVar5 = DAT_004e4ad8;
    piVar6 = piVar6 + 1;
    if (*piVar6 == 0) break;
    DAT_004e4ad8 = DAT_004e4ad8 + 1;
    (&DAT_00529350)[iVar5 * 4] = &DAT_0052b458 + *piVar6 * 0xb;
    (&DAT_00529354)[iVar5 * 4] = 1;
  }
  while( true ) {
    iVar5 = piVar6[1];
    if (iVar5 == 0) break;
    iVar10 = DAT_005272e8 * 0x10;
    DAT_005272e8 = DAT_005272e8 + 1;
    *(undefined4 **)(iVar10 + 0x52a458) = &DAT_0052b458 + iVar5 * 0xb;
    *(undefined4 *)(iVar10 + 0x52a45c) = 2;
    piVar6 = piVar6 + 1;
  }
  DAT_00583458 = DAT_00583458 + -10 + DAT_005272e8 * 10;
  iVar5 = 0;
  DAT_0052a454 = 0;
  DAT_0052a450 = piVar6 + 2;
  for (local_8 = DAT_0052a450; *local_8 != 0x1010101; local_8 = local_8 + 4) {
    DAT_0052a454 = DAT_0052a454 + 1;
  }
  local_8 = local_8 + 1;
  DAT_005272e0 = 0;
  bVar4 = *(byte *)local_8;
  while (bVar4 != 0xff) {
    if (bVar4 == 0) {
      puVar14 = (undefined4 *)(&DAT_005282f4 + (uint)*(ushort *)((int)local_8 + 2) * 4);
    }
    else {
      DAT_005272e0 = iVar5 + 1;
      puVar14 = &DAT_004ccad8 + iVar5 * 6;
      *local_10 = puVar14;
      *puVar14 = 0;
      (&DAT_004ccae8)[iVar5 * 6] = (uint)*(byte *)local_8;
      uVar1 = *(ushort *)((int)local_8 + 2);
      (&DAT_004ccae0)[iVar5 * 6] = &DAT_0052b458 + (uint)uVar1 * 0xb;
      (&DAT_004ccadc)[iVar5 * 6] =
           (&DAT_0052b458)[(uint)uVar1 * 0xb] + (*(byte *)((int)local_8 + 1) & 0x3f) * 4;
      (&DAT_004ccaec)[iVar5 * 6] = (uint)(*(byte *)((int)local_8 + 1) >> 6);
      iVar5 = DAT_005272e0;
    }
    local_8 = local_8 + 1;
    local_10 = puVar14;
    bVar4 = *(byte *)local_8;
  }
  DAT_004ccad0 = local_8[1];
  local_8 = local_8 + 2;
  DAT_005282f0 = fr08_409b9f(DAT_004ccad0 * 0x18);
  iVar5 = 0;
  if (0 < DAT_004ccad0) {
    iVar10 = 0;
    do {
      *(int *)(iVar10 + 4 + DAT_005282f0) = *local_8 << 8;
      local_8 = (int *)((int)local_8 + 3);
      iVar5 = iVar5 + 1;
      iVar10 = iVar10 + 0x18;
    } while (iVar5 < DAT_004ccad0);
  }
  iVar5 = 0;
  if (0 < DAT_004ccad0) {
    iVar10 = 0;
    do {
      *(undefined2 *)(iVar10 + DAT_005282f0) = *(undefined2 *)local_8;
      iVar10 = iVar10 + 0x18;
      local_8 = (int *)((int)local_8 + 2);
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_004ccad0);
  }
  iVar5 = 0;
  if (0 < DAT_005272e0) {
    piVar6 = &DAT_004ccae8;
    iVar10 = DAT_005272e0;
    do {
      piVar6[-1] = DAT_005282f0 + iVar5 * 0x18;
      iVar5 = iVar5 + *piVar6;
      piVar6 = piVar6 + 6;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  bVar4 = *(byte *)local_8;
  if (bVar4 != 0xff) {
    pbVar11 = &DAT_0052a350;
    ppbVar12 = (byte **)&DAT_0058385c;
    do {
      *pbVar11 = bVar4;
      *ppbVar12 = (byte *)((int)local_8 + 1);
      pbVar11 = pbVar11 + 1;
      ppbVar12 = ppbVar12 + 1;
      pbVar3 = (byte *)((int)local_8 + 1);
      do {
        pbVar2 = pbVar3;
        pbVar3 = pbVar2 + 2;
      } while (*pbVar3 != 0);
      local_8 = (int *)(pbVar2 + 3);
      bVar4 = *(byte *)local_8;
    } while (bVar4 != 0xff);
  }
  pfVar13 = (float *)&DAT_004e72e0;
  local_8 = (int *)((int)local_8 + 2);
  while (*(byte *)local_8 != 0xff) {
    fVar17 = (float10)fr08_4028cc(&local_8);
    *pfVar13 = (float)fVar17;
    pfVar13 = pfVar13 + 1;
  }
  local_8 = local_8 + 1;
  if (*(byte *)local_8 != 0) {
    ppiVar8 = (int **)&DAT_0058345c;
    do {
      *ppiVar8 = local_8;
      ppiVar8 = ppiVar8 + 1;
      do {
        bVar4 = *(byte *)local_8;
        local_8 = (int *)((int)local_8 + 1);
      } while (bVar4 != 0);
    } while (*(byte *)local_8 != 0);
  }
  iVar5 = 0;
  iVar10 = 0xff00ff;
  piVar6 = &DAT_005272f8;
  iVar15 = 0x100;
  do {
    piVar6[-2] = iVar5;
    piVar6[-3] = iVar5;
    *piVar6 = iVar10;
    piVar6[-1] = iVar10;
    iVar5 = iVar5 + 0x10001;
    iVar10 = iVar10 + -0x10001;
    piVar6 = piVar6 + 4;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  DAT_005272e4 = fr08_409b9f(0x40000);
  return;
}

