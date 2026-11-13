// Original FR08 function at 0040a9f1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 fr08_40a9f1(void)

{
  uint in_EAX;
  
  _DAT_00715bc4 = (float)(in_EAX >> 9 | 0x3f800000);
  return (float10)_DAT_00715bc4 - (float10)1;
}

