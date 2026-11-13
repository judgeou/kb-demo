// Original FR08 function at 0040569e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040569e(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined4 uVar13;
  uint uVar14;
  
  if (param_1[4] != 0) {
    param_1[4] = 0;
    (**(code **)(param_1[1] + 0x18))(param_1[1]);
    puVar4 = (undefined4 *)param_1[9];
    uVar13 = *(undefined4 *)(param_1[1] + 0x24);
    fr08_405dc0();
    puVar4[0x16] = uVar13;
    puVar5 = (undefined4 *)*param_1;
    puVar4[3] = *puVar5;
    fVar12 = (float)_DAT_00444118;
    puVar4[4] = puVar5[1];
    puVar4[5] = puVar5[2];
    puVar4[6] = puVar5[3];
    fVar6 = (float)puVar5[4];
    fVar7 = (float)puVar5[5];
    fVar8 = (float)puVar5[6];
    fVar9 = (float)puVar5[7];
    fVar10 = (float)puVar5[8];
    fVar11 = (float)puVar5[9];
    fVar1 = (float)puVar5[10];
    fVar2 = (float)puVar5[0xb];
    fVar3 = (float)puVar5[0xc];
    *puVar4 = puVar5[0xd];
    puVar4[0x15] = param_1[7] >> 2 & 3;
    uVar13 = fr08_405e3b();
    puVar4[0x14] = uVar13;
    puVar4[7] = fVar6;
    puVar4[1] = 0x44fa0000;
    puVar4[8] = fVar7;
    puVar4[2] = 0x3dcccccd;
    puVar4[9] = fVar8;
    puVar4[0x18] = param_1[7] >> 4 & 3;
    if (DAT_00493034 == 0) {
      puVar4[0x18] = 0;
    }
    uVar14 = param_1[7] & 3;
    if (uVar14 == 0) {
      fr08_408d27();
      fr08_408e51();
    }
    else if (uVar14 == 1) {
      fr08_408ea3((double)(fVar1 * fVar12),(double)(fVar2 * fVar12),(double)(fVar3 * fVar12));
      fr08_408d82();
      puVar4[7] = fVar6 + fVar9;
      puVar4[8] = fVar7 + fVar10;
      puVar4[9] = fVar8 + fVar11;
    }
    else if (uVar14 == 2) {
      fr08_408ea3((double)(fVar1 * fVar12),(double)(fVar2 * fVar12),(double)(fVar3 * fVar12));
    }
  }
  return;
}

