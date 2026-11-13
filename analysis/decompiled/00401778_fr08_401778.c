// Original FR08 function at 00401778

void fr08_401778(byte *param_1)

{
  byte bVar1;
  
  DAT_004cb040 = (uint)*param_1;
  DAT_004cb044 = (uint)param_1[1];
  while( true ) {
    bVar1 = param_1[2];
    if (bVar1 == 0) break;
    (&DAT_004cbe70)[bVar1] = (uint)param_1[3];
    param_1 = param_1 + 2;
  }
  return;
}

