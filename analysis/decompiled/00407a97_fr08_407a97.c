// Original FR08 function at 00407a97

void fr08_407a97(float *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 local_74 [10];
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40 [10];
  float local_18;
  float local_14;
  float local_10;
  int local_c;
  undefined4 *local_8;
  
  iVar2 = (int)param_1;
  if ((param_1 != (float *)0x0) &&
     ((*(uint *)((int)param_1 + 0x28) & 1 << ((byte)param_3 & 0x1f)) != 0)) {
    fr08_40831a();
    puVar6 = *(undefined4 **)((int)param_1 + 0x3c);
    puVar7 = (undefined4 *)(&DAT_005917e0 + DAT_00591ee0 * 0x38);
    for (uVar4 = (uint)(*(int *)((int)param_1 + 0x1c) * 0x38) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined *)puVar7 = *(undefined *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    DAT_00591ee0 = DAT_00591ee0 + *(int *)((int)param_1 + 0x1c);
    local_8 = *(undefined4 **)((int)param_1 + 0x44);
    local_c = 0;
    if (0 < *(int *)((int)param_1 + 0xc)) {
      param_1 = (float *)(local_8 + 1);
      do {
        puVar6 = param_2;
        puVar7 = local_74;
        for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        local_18 = (float)param_2[10];
        local_14 = (float)param_2[0xb];
        local_10 = (float)param_2[0xc];
        puVar6 = param_2;
        puVar7 = local_40;
        for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        fr08_408f2c(param_1 + 3,local_40);
        local_4c = *param_1;
        local_48 = param_1[1];
        local_44 = param_1[2];
        fr08_408d82(local_40);
        local_4c = local_18 + local_4c;
        local_48 = local_48 + local_14;
        local_44 = local_44 + local_10;
        fr08_407a97(*local_8,local_74,param_3);
        local_8 = local_8 + 0xe;
        param_1 = param_1 + 0xe;
        local_c = local_c + 1;
      } while (local_c < *(int *)(iVar2 + 0xc));
    }
    fr08_401cd3(param_2,0);
    fr08_4023e5(&DAT_005917e0,DAT_00591ee0);
    local_c = 0;
    if (0 < *(int *)(iVar2 + 8)) {
      param_1 = (float *)0x0;
      do {
        iVar5 = *(int *)(iVar2 + 0x40) + (int)param_1;
        if (*(int *)(iVar5 + 0x24) != 0) {
          fr08_401cd3(param_2,*(int *)(iVar5 + 0x24));
        }
        if (*(int *)(iVar5 + 0x14) == param_3) {
          iVar1 = *(int *)(iVar5 + 0x10);
          if (*(char *)(iVar2 + 0x24) == '\0') {
            if (iVar1 == 0) {
              uVar8 = 0;
            }
            else {
              uVar8 = (&DAT_0058385c)[iVar1];
            }
            fr08_4017ab(uVar8);
            if (*(int *)(iVar5 + 0x18) != 0) {
              fr08_4017e4(*(int *)(iVar5 + 0x18));
            }
            if (((*(int *)(iVar5 + 0x1c) == 0) || (*(int *)(iVar5 + 0x20) != DAT_004cb048)) ||
               (cVar3 = fr08_4021fb(*(int *)(iVar5 + 0x1c),1), cVar3 == '\0')) {
              uVar8 = fr08_402073(*(undefined4 *)(iVar5 + 4),*(int *)(iVar5 + 0xc) * 3,0);
              *(undefined4 *)(iVar5 + 0x1c) = uVar8;
              *(int *)(iVar5 + 0x20) = DAT_004cb048;
              fr08_4076ed(iVar2,iVar5,0);
              fr08_4021ce(uVar8,1);
            }
          }
          else {
            if (iVar1 == 0) {
              uVar8 = 0;
            }
            else {
              uVar8 = (&DAT_0058385c)[iVar1];
            }
            fr08_4017ab(uVar8);
            if (*(int *)(iVar5 + 0x18) != 0) {
              fr08_4017e4(*(int *)(iVar5 + 0x18));
            }
            fr08_4021fb(*(undefined4 *)(iVar5 + 0x1c),1);
          }
          if (*(int *)(iVar5 + 0x24) != 0) {
            fr08_401cd3(param_2,0);
          }
        }
        local_c = local_c + 1;
        param_1 = (float *)((int)param_1 + 0x28);
      } while (local_c < *(int *)(iVar2 + 8));
    }
    DAT_00591ee0 = DAT_00591ee0 - *(int *)(iVar2 + 0x1c);
  }
  return;
}

