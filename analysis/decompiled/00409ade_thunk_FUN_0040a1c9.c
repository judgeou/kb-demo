// Original FR08 function at 00409ade

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall thunk_FUN_0040a1c9(undefined4 param_1,undefined4 param_2)

{
  _DAT_00594358 = _DAT_00594358 + 1;
  if (DAT_0059435c != 0) {
    FUN_004433d8(DAT_0059435c,1000);
  }
  FUN_00443402(DAT_00594380);
  FUN_004433f6(&DAT_00594388);
  (*(code *)&LAB_0040a204_1)();
  (*(code *)&LAB_0040a204_1)();
  if (DAT_00594340 != (int *)0x0) {
    (**(code **)(*DAT_00594340 + 8))(DAT_00594340);
  }
  return CONCAT44(&stack0x00000000,param_2);
}

