// Original FR08 function at 00405566

void FUN_00405566(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (param_1[4] != 0) {
    param_1[4] = 0;
    (**(code **)(param_1[1] + 0x18))(param_1[1]);
    iVar2 = param_1[9];
    if ((*(byte *)(param_1 + 5) & 1) != 0) {
      if ((*(byte *)(*(int *)(iVar2 + 0x20) + 0x14) & 2) == 0) {
        fr08_408268(*(undefined4 *)(param_1[1] + 0x24));
      }
      else {
        fr08_408005(0,0,0,0,1);
        **(undefined4 **)(iVar2 + 0x44) = *(undefined4 *)(param_1[1] + 0x24);
        iVar2 = *(int *)(iVar2 + 0x44);
        *(undefined4 *)(iVar2 + 4) = 0;
        *(undefined4 *)(iVar2 + 8) = 0;
        *(undefined4 *)(iVar2 + 0xc) = 0;
        fr08_408e20();
      }
    }
    puVar3 = (undefined4 *)fr08_4081fd();
    puVar3[1] = *(undefined4 *)*param_1;
    puVar3[2] = *(undefined4 *)(*param_1 + 4);
    puVar3[3] = *(undefined4 *)(*param_1 + 8);
    puVar1 = puVar3 + 4;
    *puVar1 = *(undefined4 *)(*param_1 + 0xc);
    puVar3[5] = *(undefined4 *)(*param_1 + 0x10);
    puVar3[6] = *(undefined4 *)(*param_1 + 0x14);
    iVar2 = param_1[7];
    if (iVar2 == 1) {
      *puVar3 = 2;
      puVar3[0xb] = *(undefined4 *)(*param_1 + 0x18);
    }
    else {
      if (iVar2 == 2) {
        puVar3[7] = *puVar1;
        puVar3[8] = puVar3[5];
        *puVar3 = 3;
        puVar3[9] = puVar3[6];
        *puVar1 = 0;
        puVar3[5] = 0;
        puVar3[6] = 0;
        puVar3[0xb] = *(undefined4 *)(*param_1 + 0x18);
        uVar4 = *(undefined4 *)(*param_1 + 0x1c);
      }
      else {
        if (iVar2 != 3) {
          return;
        }
        *puVar3 = 4;
        puVar3[7] = *(undefined4 *)(*param_1 + 0x18);
        puVar3[8] = *(undefined4 *)(*param_1 + 0x1c);
        puVar3[9] = *(undefined4 *)(*param_1 + 0x20);
        puVar3[10] = *(undefined4 *)(*param_1 + 0x24);
        puVar3[0xb] = *(undefined4 *)(*param_1 + 0x28);
        puVar3[0xc] = *(undefined4 *)(*param_1 + 0x2c);
        uVar4 = *(undefined4 *)(*param_1 + 0x30);
      }
      puVar3[0xd] = uVar4;
    }
  }
  return;
}

