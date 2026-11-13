// Original FR08 function at 004095a5

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_4095a5(void)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  byte *pbVar9;
  uint *local_18;
  int local_14;
  uint *local_10;
  uint local_8;
  
  iVar6 = DAT_005923b8;
  if (DAT_005923b0 != '\0') {
    for (DAT_005923e0 = DAT_005923e0 + (DAT_005923b8 - DAT_005923b4); DAT_00592e00 <= DAT_005923e0;
        DAT_005923e0 = DAT_005923e0 - DAT_00592e00) {
      DAT_005923dc = DAT_005923dc + 1;
    }
    uVar5 = (DAT_005923cc << 2) / DAT_005923d0;
    for (; uVar5 <= DAT_005923dc; DAT_005923dc = DAT_005923dc - uVar5) {
      _DAT_005923d8 = _DAT_005923d8 + 1;
    }
    DAT_005923b8 = -1;
    local_8 = 0xffffffff;
    DAT_005923b4 = iVar6;
    pbVar9 = &DAT_00593314;
    if ((DAT_005923c4 < DAT_00592e10) && (iVar6 == DAT_005923c0)) {
      DAT_005923c8 = *(int *)(DAT_00592e10 * 3 + DAT_005923bc + DAT_005923c4 * 4) * 0x1b9;
      DAT_005923cc = (uint)*(byte *)(DAT_00592e10 * 7 + DAT_005923bc + DAT_005923c4);
      DAT_005923d0 = (uint)*(byte *)(DAT_005923bc + DAT_00592e10 * 8 + DAT_005923c4);
      _DAT_005923d4 = (uint)*(byte *)(DAT_005923bc + DAT_00592e10 * 9 + DAT_005923c4);
      DAT_005923c4 = DAT_005923c4 + 1;
      fr08_4098cb(DAT_005923c4,&DAT_005923c0,DAT_005923bc + DAT_005923c4,DAT_00592e10);
    }
    fr08_4098ee(DAT_005923c4,&DAT_005923c0,DAT_00592e10);
    bVar3 = 0;
    local_18 = &DAT_00592e1c;
    piVar8 = &DAT_005923f4;
    do {
      if (local_18[-2] != 0) {
        uVar5 = *local_18;
        if (((uint)piVar8[1] < uVar5) && (DAT_005923b4 == piVar8[2])) {
          bVar4 = bVar3 | 0xc0;
          if (local_8 != bVar4) {
            *pbVar9 = bVar4;
            pbVar9 = pbVar9 + 1;
            local_8 = (uint)bVar4;
          }
          iVar6 = *piVar8;
          *(char *)(piVar8 + 3) = *(char *)(piVar8 + 3) + *(char *)(uVar5 + iVar6 + uVar5 * 2);
          *pbVar9 = *(byte *)(piVar8 + 3);
          iVar1 = piVar8[1];
          pbVar9 = pbVar9 + 1;
          iVar6 = iVar6 + 1;
          piVar8[1] = iVar1 + 1;
          *piVar8 = iVar6;
          fr08_4098cb(iVar1 + 1,piVar8 + 2,iVar6,uVar5);
        }
        fr08_4098ee(piVar8[1],piVar8 + 2,*local_18);
        local_14 = 0;
        local_10 = local_18 + 4;
        piVar7 = piVar8 + 9;
        do {
          uVar5 = *local_10;
          if (((uint)piVar7[1] < uVar5) && (DAT_005923b4 == *piVar7)) {
            bVar4 = bVar3 | 0xb0;
            if (local_8 != bVar4) {
              *pbVar9 = bVar4;
              pbVar9 = pbVar9 + 1;
              local_8 = (uint)bVar4;
            }
            *pbVar9 = (char)local_14 + 1;
            iVar6 = piVar7[-1];
            *(char *)(piVar7 + 2) = *(char *)(piVar7 + 2) + *(char *)(uVar5 + iVar6 + uVar5 * 2);
            pbVar9[1] = *(byte *)(piVar7 + 2);
            iVar1 = piVar7[1];
            pbVar9 = pbVar9 + 2;
            iVar6 = iVar6 + 1;
            piVar7[1] = iVar1 + 1;
            piVar7[-1] = iVar6;
            fr08_4098cb(iVar1 + 1,piVar7,iVar6,uVar5);
          }
          fr08_4098ee(piVar7[1],piVar7,*local_10);
          local_14 = local_14 + 1;
          local_10 = local_10 + 2;
          piVar7 = piVar7 + 4;
        } while (local_14 < 7);
        if (((uint)piVar8[5] < local_18[2]) && (DAT_005923b4 == piVar8[6])) {
          bVar4 = bVar3 | 0xe0;
          if (local_8 != bVar4) {
            *pbVar9 = bVar4;
            pbVar9 = pbVar9 + 1;
            local_8 = (uint)bVar4;
          }
          uVar5 = *local_18;
          iVar6 = piVar8[4];
          uVar2 = local_18[2];
          *(char *)(piVar8 + 7) = *(char *)(piVar8 + 7) + *(char *)(uVar5 + iVar6 + uVar5 * 2);
          *pbVar9 = *(byte *)(piVar8 + 7);
          *(char *)((int)piVar8 + 0x1d) =
               *(char *)((int)piVar8 + 0x1d) + *(char *)(iVar6 + uVar5 * 4);
          pbVar9[1] = *(byte *)((int)piVar8 + 0x1d);
          iVar1 = piVar8[5];
          pbVar9 = pbVar9 + 2;
          piVar8[5] = iVar1 + 1;
          piVar8[4] = iVar6 + 1;
          fr08_4098cb(iVar1 + 1,piVar8 + 6,iVar6 + 1,uVar2);
        }
        fr08_4098ee(piVar8[5],piVar8 + 6,local_18[2]);
        while ((uVar5 = local_18[-2], (uint)piVar8[-3] < uVar5 && (DAT_005923b4 == piVar8[-2]))) {
          bVar4 = bVar3 | 0x90;
          if (local_8 != bVar4) {
            *pbVar9 = bVar4;
            pbVar9 = pbVar9 + 1;
            local_8 = (uint)bVar4;
          }
          iVar6 = piVar8[-4];
          *(char *)(piVar8 + -1) = *(char *)(piVar8 + -1) + *(char *)(uVar5 + iVar6 + uVar5 * 2);
          *pbVar9 = *(byte *)(piVar8 + -1);
          *(char *)((int)piVar8 + -3) = *(char *)((int)piVar8 + -3) + *(char *)(iVar6 + uVar5 * 4);
          pbVar9[1] = *(byte *)((int)piVar8 + -3);
          iVar1 = piVar8[-3];
          pbVar9 = pbVar9 + 2;
          piVar8[-3] = iVar1 + 1;
          piVar8[-4] = iVar6 + 1;
          fr08_4098cb(iVar1 + 1,piVar8 + -2,iVar6 + 1,uVar5);
        }
        fr08_4098ee(piVar8[-3],piVar8 + -2,local_18[-2]);
      }
      bVar3 = bVar3 + 1;
      local_18 = local_18 + 0x14;
      piVar8 = piVar8 + 0x28;
    } while ((int)local_18 < 0x59331c);
    *pbVar9 = 0xfd;
    fr08_40bbac(&DAT_00593314);
    if (DAT_005923b8 == -1) {
      DAT_005923b0 = '\0';
    }
  }
  return;
}

