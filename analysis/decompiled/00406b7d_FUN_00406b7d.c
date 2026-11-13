// Original FR08 function at 00406b7d

void FUN_00406b7d(undefined4 *param_1)

{
  if (param_1[4] != 0) {
    param_1[4] = 0;
    fr08_409e00(1);
    (**(code **)(param_1[1] + 0x18))(param_1[1]);
    if ((param_1[7] & 0xc0) == 0) {
      fr08_4068e9(param_1[9],*(undefined4 *)*param_1,((undefined4 *)*param_1)[1],param_1[7]);
    }
    else {
      fr08_406b46(DAT_005272e4,param_1[9]);
      fr08_4068e9(DAT_005272e4,*(undefined4 *)*param_1,((undefined4 *)*param_1)[1],param_1[7]);
      fr08_406b46(param_1[9],DAT_005272e4);
    }
    if ((param_1[7] & 0x80) != 0) {
      fr08_4068e9(param_1[9],*(undefined4 *)*param_1,((undefined4 *)*param_1)[1],param_1[7]);
    }
  }
  return;
}

