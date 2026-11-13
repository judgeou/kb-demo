// Original FR08 function at 00409e00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_409e00(int param_1)

{
  float fVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_bc [20];
  undefined4 local_6c;
  undefined4 local_68;
  undefined local_64 [40];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined local_30 [4];
  int local_2c;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  DAT_00594334 = DAT_00594334 + param_1;
  uVar3 = fr08_409bc5();
  if (((DAT_00594324 + 1000 < uVar3) || (DAT_00583458 <= DAT_00594334 + 1)) &&
     (DAT_0059432d != '\0')) {
    DAT_00594324 = uVar3;
    fr08_40100b();
    local_68 = 3;
    local_6c = 0xff000000;
    local_bc[0] = 0x3d99999a;
    fr08_408e20();
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    fr08_401812(0,local_bc);
    fr08_401cd3(local_64,0);
    fr08_4017ab(0);
    fr08_4023e5(0,0);
    local_14 = -10.24;
    local_10 = -0.75;
    local_c = 10.24;
    local_8 = 0.75;
    fr08_409d6e(&local_14,0xffffffff);
    local_14 = local_14 + _DAT_00444354;
    local_10 = local_10 + _DAT_00444354;
    local_c = local_c - _DAT_00444354;
    local_8 = local_8 - _DAT_00444354;
    fr08_409d6e(&local_14,0xff000000);
    fVar1 = (float)DAT_00594334 / (float)DAT_00583458;
    if (_DAT_004440ec <= fVar1) {
      fVar1 = 1.0;
    }
    local_14 = -10.0;
    local_c = fVar1 * _DAT_00444350 - _DAT_0044434c;
    local_10 = -0.51;
    local_8 = 0.51;
    fr08_409d6e(&local_14,0xffffffff);
    fr08_401d97();
    fr08_401daf();
    pcVar2 = DAT_00444090;
    while (iVar4 = (*pcVar2)(local_30,0,0,0,1), iVar4 != 0) {
      (*DAT_004440b0)(local_30);
      (*DAT_004440b4)(local_30);
      if (local_2c == 0x12) {
        (*DAT_0044406c)(0);
      }
    }
  }
  return;
}

