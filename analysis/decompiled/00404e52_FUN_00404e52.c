// Original FR08 function at 00404e52

void FUN_00404e52(float **param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int *piVar9;
  float *pfVar10;
  bool bVar11;
  char cVar12;
  int iVar13;
  float local_28;
  float local_24;
  float local_20;
  float local_10;
  float local_c;
  float local_8;
  
  if (param_1[4] != (float *)0x0) {
    param_1[4] = (float *)0x0;
    (*(code *)param_1[1][6])(param_1[1]);
    pfVar4 = param_1[9];
    if ((*(byte *)(param_1 + 5) & 1) != 0) {
      fr08_408268(param_1[1][9]);
    }
    pfVar5 = param_1[7];
    if (((uint)pfVar5 & 0x10) != 0) {
      pfVar10 = *param_1;
      local_28 = pfVar10[3] + *pfVar10;
      local_24 = pfVar10[4] + pfVar10[1];
      local_20 = pfVar10[5] + pfVar10[2];
      local_10 = pfVar10[3] - *pfVar10;
      local_c = pfVar10[4] - pfVar10[1];
      local_8 = pfVar10[5] - pfVar10[2];
    }
    pfVar10 = (float *)pfVar4[0xd];
    iVar13 = 0;
    if (0 < (int)*pfVar4) {
      do {
        bVar6 = local_10 <= *pfVar10;
        bVar7 = local_c <= pfVar10[1];
        bVar8 = local_8 <= pfVar10[2];
        fVar1 = *pfVar10;
        fVar2 = pfVar10[1];
        fVar3 = pfVar10[2];
        bVar11 = fVar3 <= local_20 &&
                 (fVar2 <= local_24 && (fVar1 <= local_28 && (bVar8 && (bVar7 && bVar6))));
        *(bool *)((int)pfVar10 + 0x25) = bVar11;
        if (pfVar5 == (float *)0x0) {
LAB_00404f68:
          *(undefined *)(pfVar10 + 9) = 1;
        }
        else if (pfVar5 == (float *)0x1) {
LAB_00404f5e:
          *(undefined *)(pfVar10 + 9) = 0;
        }
        else if (pfVar5 == (float *)0x2) {
          *(bool *)(pfVar10 + 9) = *(char *)(pfVar10 + 9) == '\0';
        }
        else if (pfVar5 == (float *)0x10) {
          *(bool *)(pfVar10 + 9) = bVar11;
        }
        else if (pfVar5 == (float *)0x11) {
          if (fVar3 <= local_20 &&
              (fVar2 <= local_24 && (fVar1 <= local_28 && (bVar8 && (bVar7 && bVar6)))))
          goto LAB_00404f68;
        }
        else if ((pfVar5 == (float *)0x12) &&
                (fVar3 <= local_20 &&
                 (fVar2 <= local_24 && (fVar1 <= local_28 && (bVar8 && (bVar7 && bVar6))))))
        goto LAB_00404f5e;
        pfVar10 = pfVar10 + 0xb;
        iVar13 = iVar13 + 1;
      } while (iVar13 < (int)*pfVar4);
    }
    piVar9 = (int *)pfVar4[0xe];
    fVar1 = pfVar4[0xd];
    iVar13 = 0;
    if (0 < (int)pfVar4[1]) {
      do {
        if (((*(char *)(*piVar9 * 0x2c + 0x25 + (int)fVar1) == '\0') ||
            (*(char *)(piVar9[1] * 0x2c + 0x25 + (int)fVar1) == '\0')) ||
           (*(char *)(piVar9[2] * 0x2c + 0x25 + (int)fVar1) == '\0')) {
          cVar12 = '\0';
        }
        else {
          cVar12 = '\x01';
        }
        if (pfVar5 == (float *)0x0) {
LAB_00404fe9:
          *(undefined *)((int)piVar9 + 0x1a) = 1;
        }
        else if (pfVar5 == (float *)0x1) {
LAB_00404fdf:
          *(undefined *)((int)piVar9 + 0x1a) = 0;
        }
        else if (pfVar5 == (float *)0x2) {
          *(bool *)((int)piVar9 + 0x1a) = *(char *)((int)piVar9 + 0x1a) == '\0';
        }
        else if (pfVar5 == (float *)0x10) {
          *(char *)((int)piVar9 + 0x1a) = cVar12;
        }
        else if (pfVar5 == (float *)0x11) {
          if (cVar12 != '\0') goto LAB_00404fe9;
        }
        else if ((pfVar5 == (float *)0x12) && (cVar12 != '\0')) goto LAB_00404fdf;
        piVar9 = piVar9 + 7;
        iVar13 = iVar13 + 1;
      } while (iVar13 < (int)pfVar4[1]);
    }
  }
  return;
}

