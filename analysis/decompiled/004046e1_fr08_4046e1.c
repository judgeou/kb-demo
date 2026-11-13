// Original FR08 function at 004046e1

void fr08_4046e1(void)

{
  int *piVar1;
  byte *pbVar2;
  float **ppfVar3;
  undefined4 uVar4;
  int *in_EAX;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int *unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined4 *puVar13;
  undefined4 *puVar14;
  float *pfVar15;
  undefined4 *unaff_EDI;
  undefined4 *puVar16;
  
  do {
    *unaff_EDI = *unaff_ESI;
    puVar13 = (undefined4 *)(in_EAX[1] * 0x2c + unaff_EBX[0xd]);
    *(undefined4 *)(unaff_EBP + -0x38) = *puVar13;
    *(undefined4 *)(unaff_EBP + -0x34) = puVar13[1];
    *(undefined4 *)(unaff_EBP + -0x30) = puVar13[2];
    puVar13 = (undefined4 *)(in_EAX[2] * 0x2c + unaff_EBX[0xd]);
    *(undefined4 *)(unaff_EBP + -0x50) = *puVar13;
    *(undefined4 *)(unaff_EBP + -0x4c) = puVar13[1];
    *(undefined4 *)(unaff_EBP + -0x48) = puVar13[2];
    *(float *)(unaff_EBP + -0x44) = *(float *)(unaff_EBP + -0x44) - *(float *)(unaff_EBP + -0x38);
    *(float *)(unaff_EBP + -0x40) = *(float *)(unaff_EBP + -0x40) - *(float *)(unaff_EBP + -0x34);
    *(float *)(unaff_EBP + -0x3c) = *(float *)(unaff_EBP + -0x3c) - *(float *)(unaff_EBP + -0x30);
    *(float *)(unaff_EBP + -0x50) = *(float *)(unaff_EBP + -0x50) - *(float *)(unaff_EBP + -0x38);
    *(float *)(unaff_EBP + -0x4c) = *(float *)(unaff_EBP + -0x4c) - *(float *)(unaff_EBP + -0x34);
    *(float *)(unaff_EBP + -0x48) = *(float *)(unaff_EBP + -0x48) - *(float *)(unaff_EBP + -0x30);
    fr08_408d27();
    fr08_408d27();
    fr08_404a89(unaff_EBP + -0x50,unaff_EBP + -0x44);
    fr08_408d27();
    bVar8 = *(byte *)(unaff_EBP + -0x18);
    ppfVar3 = *(float ***)(unaff_EBP + 8);
    *(float *)(unaff_EBP + -0x2c) = *(float *)(unaff_EBP + -0x38) + *(float *)(unaff_EBP + -0x2c);
    *(float *)(unaff_EBP + -0x28) = *(float *)(unaff_EBP + -0x28) + *(float *)(unaff_EBP + -0x34);
    *(float *)(unaff_EBP + -0x24) = *(float *)(unaff_EBP + -0x24) + *(float *)(unaff_EBP + -0x30);
    piVar5 = *(int **)(unaff_EBP + -0x10);
    while( true ) {
      pbVar2 = (byte *)(*piVar5 * 0x2c + 0x25 + unaff_EBX[0xd]);
      *pbVar2 = *pbVar2 | bVar8;
      in_EAX = piVar5 + 7;
      pbVar2 = (byte *)(piVar5[1] * 0x2c + 0x25 + unaff_EBX[0xd]);
      *pbVar2 = *pbVar2 | bVar8;
      *(int **)(unaff_EBP + -0x10) = in_EAX;
      pbVar2 = (byte *)(piVar5[2] * 0x2c + 0x25 + unaff_EBX[0xd]);
      *pbVar2 = *pbVar2 | bVar8;
      *(int *)(unaff_EBP + -4) = *(int *)(unaff_EBP + -4) + 1;
      if (unaff_EBX[1] <= *(int *)(unaff_EBP + -4)) {
        if ((*(byte *)(unaff_EBP + -0xc) & 0x10) == 0) {
          fr08_404107(ppfVar3,0,unaff_EBP + -0x88,unaff_EBP + -0x60);
        }
        else {
          fr08_408e20();
          fr08_408d27();
          fr08_4040e8((double)**ppfVar3);
          *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x2c);
          *(undefined4 *)(unaff_EBP + -0x5c) = *(undefined4 *)(unaff_EBP + -0x28);
          *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0x24);
        }
        iVar11 = *unaff_EBX;
        iVar9 = unaff_EBX[0xd];
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(int *)(unaff_EBP + -0x20) = iVar11;
        if (0 < iVar11) {
          piVar5 = (int *)(iVar9 + 0x28);
          iVar9 = iVar11;
          do {
            if (*(char *)((int)piVar5 + -3) == '\x03') {
              iVar12 = *(int *)(unaff_EBP + -4);
              *(int *)(unaff_EBP + -4) = *(int *)(unaff_EBP + -4) + 1;
              *piVar5 = iVar12 + iVar11;
            }
            else {
              *piVar5 = -1;
            }
            piVar5 = piVar5 + 0xb;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        iVar9 = unaff_EBX[1];
        iVar12 = unaff_EBX[0xe];
        *(int *)(unaff_EBP + -0x10) = iVar12;
        *(int *)(unaff_EBP + -0x18) = iVar9;
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        if (0 < iVar9) {
          *(int *)(unaff_EBP + -0xc) = iVar9;
          do {
            if (*(char *)(iVar12 + 0x1a) != '\0') {
              iVar6 = unaff_EBX[0xd];
              *(undefined4 *)(unaff_EBP + 8) = 0;
              *(int *)(unaff_EBP + -8) = iVar12;
              do {
                if (*(int *)(**(int **)(unaff_EBP + -8) * 0x2c + 0x28 + iVar6) != -1) {
                  iVar12 = *(int *)(unaff_EBP + -0x10);
                  iVar6 = unaff_EBX[0xd];
                  if (*(int *)(*(int *)(iVar12 + ((*(int *)(unaff_EBP + 8) + 1) % 3) * 4) * 0x2c +
                               0x28 + iVar6) != -1) {
                    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 2;
                  }
                }
                *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
                *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + 4;
              } while (*(int *)(unaff_EBP + 8) < 3);
            }
            iVar12 = iVar12 + 0x1c;
            piVar5 = (int *)(unaff_EBP + -0xc);
            *piVar5 = *piVar5 + -1;
            *(int *)(unaff_EBP + -0x10) = iVar12;
          } while (*piVar5 != 0);
        }
        iVar12 = *(int *)(unaff_EBP + -0x1c);
        fr08_408005(*(int *)(unaff_EBP + -4) + iVar11,*(int *)(unaff_EBP + -0x14) + iVar9,0,1,0);
        puVar13 = (undefined4 *)unaff_EBX[0xd];
        puVar7 = *(undefined4 **)(iVar12 + 0x34);
        for (uVar10 = (uint)(iVar11 * 0x2c) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar7 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar7 = puVar7 + 1;
        }
        for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
          *(undefined *)puVar7 = *(undefined *)puVar13;
          puVar13 = (undefined4 *)((int)puVar13 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        puVar13 = (undefined4 *)unaff_EBX[0xe];
        uVar10 = *(int *)(unaff_EBP + -0x18) * 0x1c;
        piVar5 = *(int **)(unaff_EBP + -0x1c);
        *(uint *)(unaff_EBP + -0xc) = uVar10;
        puVar7 = (undefined4 *)piVar5[0xe];
        for (uVar10 = uVar10 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar7 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar7 = puVar7 + 1;
        }
        for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
          *(undefined *)puVar7 = *(undefined *)puVar13;
          puVar13 = (undefined4 *)((int)puVar13 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        puVar13 = (undefined4 *)piVar5[0xd];
        puVar7 = puVar13 + iVar11 * 0xb;
        if (0 < *(int *)(unaff_EBP + -0x20)) {
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + -0x20);
          do {
            if (*(char *)((int)puVar13 + 0x25) == '\x03') {
              puVar14 = puVar13;
              puVar16 = puVar7;
              for (iVar11 = 0xb; iVar11 != 0; iVar11 = iVar11 + -1) {
                *puVar16 = *puVar14;
                puVar14 = puVar14 + 1;
                puVar16 = puVar16 + 1;
              }
              puVar7 = puVar7 + 0xb;
              *(undefined *)((int)puVar13 + 0x25) = 1;
            }
            puVar13 = puVar13 + 0xb;
            piVar1 = (int *)(unaff_EBP + 8);
            *piVar1 = *piVar1 + -1;
          } while (*piVar1 != 0);
        }
        pfVar15 = (float *)piVar5[0xd];
        iVar11 = 0;
        if (0 < *piVar5) {
          do {
            if ((*(byte *)((int)pfVar15 + 0x25) & 2) != 0) {
              fr08_408d82();
              *pfVar15 = *(float *)(unaff_EBP + -0x60) + *pfVar15;
              pfVar15[1] = *(float *)(unaff_EBP + -0x5c) + pfVar15[1];
              pfVar15[2] = *(float *)(unaff_EBP + -0x58) + pfVar15[2];
            }
            *(undefined *)((int)pfVar15 + 0x25) = 0;
            pfVar15 = pfVar15 + 0xb;
            iVar11 = iVar11 + 1;
          } while (iVar11 < *piVar5);
        }
        iVar11 = piVar5[0xe];
        *(int *)(unaff_EBP + -0x10) = iVar11;
        puVar13 = (undefined4 *)(iVar11 + *(int *)(unaff_EBP + -0xc));
        *(undefined4 **)(unaff_EBP + -0x14) = puVar13;
        if (0 < *(int *)(unaff_EBP + -0x18)) {
          *(undefined4 *)(unaff_EBP + -4) = 0;
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x18);
          do {
            if (*(char *)(iVar11 + 0x1a) != '\0') {
              iVar9 = 0;
              *(int *)(unaff_EBP + 8) = iVar11;
              do {
                *(int *)(unaff_EBP + -0x54) = iVar9 + 1;
                *(undefined4 *)(unaff_EBP + -0x18) = **(undefined4 **)(unaff_EBP + 8);
                iVar12 = piVar5[0xd];
                iVar6 = *(int *)(*(int *)(unaff_EBP + -0x18) * 0x2c + 0x28 + iVar12);
                *(int *)(unaff_EBP + -8) = iVar6;
                iVar9 = *(int *)(iVar11 + ((iVar9 + 1) % 3) * 4);
                *(int *)(unaff_EBP + -0x20) = iVar9;
                iVar9 = *(int *)(iVar9 * 0x2c + 0x28 + iVar12);
                if ((iVar6 != -1) && (iVar9 != -1)) {
                  *(undefined *)((int)puVar13 + 0x1a) = 0;
                  puVar7 = *(undefined4 **)(unaff_EBP + -0x14);
                  *(undefined4 **)(unaff_EBP + -0xc) = puVar13 + 7;
                  puVar14 = puVar13 + 7;
                  for (iVar11 = 7; iVar11 != 0; iVar11 = iVar11 + -1) {
                    *puVar14 = *puVar13;
                    puVar13 = puVar13 + 1;
                    puVar14 = puVar14 + 1;
                  }
                  uVar4 = *(undefined4 *)(unaff_EBP + -0x18);
                  puVar7[1] = *(undefined4 *)(unaff_EBP + -0x20);
                  puVar13 = *(undefined4 **)(unaff_EBP + -0xc);
                  *puVar7 = uVar4;
                  puVar7[2] = iVar9;
                  *puVar13 = uVar4;
                  uVar4 = *(undefined4 *)(unaff_EBP + -8);
                  puVar7[8] = iVar9;
                  puVar7[9] = uVar4;
                  iVar11 = *(int *)(unaff_EBP + -0x10);
                  puVar13 = puVar7 + 0xe;
                  *(undefined4 **)(unaff_EBP + -0x14) = puVar13;
                }
                iVar9 = *(int *)(unaff_EBP + -0x54);
                *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 4;
              } while (iVar9 < 3);
              *(undefined4 *)(unaff_EBP + 8) = 0;
              *(int *)(unaff_EBP + -8) = iVar11;
              do {
                iVar9 = *(int *)(**(int **)(unaff_EBP + -8) * 0x2c + 0x28 + piVar5[0xd]);
                if (iVar9 != -1) {
                  *(int *)(piVar5[0xe] + (*(int *)(unaff_EBP + -4) + *(int *)(unaff_EBP + 8)) * 4) =
                       iVar9;
                }
                *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
                *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + 4;
              } while (*(int *)(unaff_EBP + 8) < 3);
            }
            *(int *)(unaff_EBP + -4) = *(int *)(unaff_EBP + -4) + 7;
            iVar11 = iVar11 + 0x1c;
            piVar1 = (int *)(unaff_EBP + -0x1c);
            *piVar1 = *piVar1 + -1;
            *(int *)(unaff_EBP + -0x10) = iVar11;
          } while (*piVar1 != 0);
        }
        *(int *)(piVar5[0x10] + 0xc) = piVar5[1];
        *(int *)(piVar5[0x10] + 4) = *piVar5;
        return;
      }
      if (*(char *)((int)piVar5 + 0x36) != '\0') break;
      bVar8 = 1;
      piVar5 = in_EAX;
    }
    puVar13 = (undefined4 *)(*in_EAX * 0x2c + unaff_EBX[0xd]);
    *(undefined4 *)(unaff_EBP + -0x18) = 2;
    *(undefined4 *)(unaff_EBP + -0x44) = *puVar13;
    unaff_EDI = (undefined4 *)(unaff_EBP + -0x3c);
    unaff_ESI = puVar13 + 2;
    *(undefined4 *)(unaff_EBP + -0x40) = puVar13[1];
  } while( true );
}

