// Original FR08 function at 00408909

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_408909(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  float10 fVar10;
  int local_c;
  float local_8;
  
  iVar5 = Original_DemoTimeMilliseconds();
  if (DAT_005922f0 == 0) {
    local_8 = (float)iVar5 * _DAT_004441f8 + _DAT_00591eec;
    if (local_8 <= _DAT_004440e8) {
      local_8 = 0.0;
    }
  }
  else {
    local_8 = ((float)iVar5 * _DAT_004441fc - (float)(DAT_00591ee8 << 2)) * _DAT_004441f8 +
              _DAT_00591eec;
  }
  DAT_00591ee4 = 0;
  local_c = 0;
  pbVar8 = DAT_0052a450;
  if (0 < DAT_0052a454) {
    do {
      if (((*pbVar8 & 1) == 0) && (*(float *)(pbVar8 + 4) <= local_8)) {
        if (pbVar8[1] == 0x31) {
          fr08_408aa8(pbVar8);
        }
        puVar9 = *(undefined4 **)(&DAT_005282f4 + (uint)*(ushort *)(pbVar8 + 2) * 4);
        fVar3 = local_8;
        if (*(float *)(pbVar8 + 8) <= local_8) {
          *pbVar8 = *pbVar8 | 1;
          fVar3 = *(float *)(pbVar8 + 8);
        }
        fVar1 = *(float *)(pbVar8 + 4);
        fVar2 = *(float *)(pbVar8 + 0xc);
        for (; iVar5 = 0, puVar9 != (undefined4 *)0x0; puVar9 = (undefined4 *)*puVar9) {
          fVar10 = (float10)fr08_4087e5(puVar9,(fVar3 - fVar1) / fVar2);
          fr08_40889f(puVar9,(float)fVar10);
          if (((*pbVar8 & 1) == 0) && (iVar4 = puVar9[2], *(int *)(puVar9[2] + 0x20) == 3)) {
            do {
              iVar6 = iVar4;
              iVar4 = *(int *)(iVar6 + 0xc);
            } while (*(int *)(iVar6 + 0xc) != 0);
            if (0 < DAT_00591ee4) {
              piVar7 = &DAT_00591ef0;
              do {
                if (iVar6 == 0) goto LAB_00408a38;
                if (*piVar7 == iVar6) {
                  iVar6 = 0;
                }
                iVar5 = iVar5 + 1;
                piVar7 = piVar7 + 1;
              } while (iVar5 < DAT_00591ee4);
            }
            if (iVar6 != 0) {
              (&DAT_00591ef0)[DAT_00591ee4] = iVar6;
              DAT_00591ee4 = DAT_00591ee4 + 1;
            }
          }
LAB_00408a38:
        }
      }
      local_c = local_c + 1;
      pbVar8 = pbVar8 + 0x10;
    } while (local_c < DAT_0052a454);
  }
  fr08_402b89();
  return;
}

