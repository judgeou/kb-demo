// Original FR08 function at 0040be84

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 fr08_40be84(void)

{
  float fVar1;
  undefined4 in_stack_00000014;
  undefined4 in_stack_0000001c;
  
  fr08_40b2d0();
  fr08_40b0c1();
  fVar1 = (_DAT_00719480 + 1.0) * _DAT_0040a40c;
  _DAT_00726f78 = fVar1 * fVar1;
  fVar1 = (_DAT_00719484 + 1.0) * _DAT_0040a40c;
  DAT_00726f84 = fVar1 * fVar1;
  return CONCAT44(in_stack_00000014,in_stack_0000001c);
}

