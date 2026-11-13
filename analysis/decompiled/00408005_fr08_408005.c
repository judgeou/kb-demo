// Original FR08 function at 00408005

void __thiscall
fr08_408005(int *param_1_00,int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  param_1_00[5] = 0;
  param_1_00[4] = 0;
  param_1_00[7] = 0;
  *(undefined *)(param_1_00 + 0x13) = 0;
  *(undefined *)(param_1_00 + 9) = 0;
  if ((((param_1_00[1] != param_2) || (*param_1_00 != param_1)) || (param_1_00[6] < param_3)) ||
     ((param_1_00[2] != param_4 || (param_1_00[3] != param_5)))) {
    if (param_1_00[0xe] != 0) {
      fr08_409b8d(param_1_00[0xe]);
    }
    if (param_1_00[0xd] != 0) {
      fr08_409b8d(param_1_00[0xd]);
    }
    if (param_1_00[0xf] != 0) {
      fr08_409b8d(param_1_00[0xf]);
    }
    if (param_1_00[0x10] != 0) {
      fr08_409b8d(param_1_00[0x10]);
    }
    if (param_1_00[0x11] != 0) {
      fr08_409b8d(param_1_00[0x11]);
    }
    if ((param_3 != 0) && (param_3 < 0x10)) {
      param_3 = 0x10;
    }
    iVar1 = fr08_409b9f(param_2 * 0x1c);
    param_1_00[0xe] = iVar1;
    iVar1 = fr08_409b9f(param_1 * 0x2c);
    param_1_00[0xd] = iVar1;
    iVar1 = fr08_409b9f(param_3 * 0x38);
    param_1_00[0xf] = iVar1;
    iVar1 = fr08_409b9f(param_4 * 0x28);
    param_1_00[0x10] = iVar1;
    iVar1 = fr08_409b9f(param_5 * 0x38);
    param_1_00[0x11] = iVar1;
    param_1_00[6] = param_3;
    param_1_00[1] = param_2;
    *param_1_00 = param_1;
    param_1_00[2] = param_4;
    param_1_00[3] = param_5;
    if (param_4 != 0) {
      *(undefined4 *)(param_1_00[0x10] + 8) = 0;
      *(int *)(param_1_00[0x10] + 0xc) = param_2;
      *(undefined4 *)param_1_00[0x10] = 0;
      *(int *)(param_1_00[0x10] + 4) = param_1;
      *(undefined4 *)(param_1_00[0x10] + 0x10) = 0;
      *(undefined4 *)(param_1_00[0x10] + 0x14) = 0;
      if (0 < param_4) {
        iVar1 = 0;
        do {
          param_4 = param_4 + -1;
          *(undefined4 *)(iVar1 + 0x1c + param_1_00[0x10]) = 0;
          *(undefined4 *)(iVar1 + 0x20 + param_1_00[0x10]) = 0;
          iVar1 = iVar1 + 0x28;
        } while (param_4 != 0);
      }
    }
    puVar2 = (undefined4 *)param_1_00[0x11];
    if (0 < param_5) {
      puVar3 = puVar2 + 3;
      do {
        *puVar2 = 0;
        puVar3[-2] = 0;
        puVar3[-1] = 0;
        *puVar3 = 0;
        fr08_408e20();
        puVar2 = puVar2 + 0xe;
        puVar3 = puVar3 + 0xe;
        param_5 = param_5 + -1;
      } while (param_5 != 0);
    }
    puVar2 = (undefined4 *)param_1_00[0xd];
    if (0 < param_1) {
      puVar3 = puVar2 + 5;
      do {
        *puVar2 = 0;
        puVar2 = puVar2 + 0xb;
        puVar3[-4] = 0;
        puVar3[-3] = 0;
        puVar3[-2] = 0;
        puVar3[-1] = 0;
        *puVar3 = 0;
        puVar3[1] = 0xffffffff;
        *(undefined *)(puVar3 + 4) = 1;
        puVar3[2] = 0;
        puVar3[3] = 0;
        puVar3 = puVar3 + 0xb;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
    puVar2 = (undefined4 *)param_1_00[0xe];
    if (0 < param_2) {
      puVar3 = puVar2 + 5;
      do {
        puVar3[-2] = 0;
        puVar3[-1] = 0;
        *puVar3 = 0;
        *puVar2 = 0;
        puVar3[-4] = 0;
        puVar3[-3] = 0;
        *(undefined *)((int)puVar3 + 6) = 0;
        puVar2 = puVar2 + 7;
        puVar3 = puVar3 + 7;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
  return;
}

