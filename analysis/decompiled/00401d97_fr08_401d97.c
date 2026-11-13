// Original FR08 function at 00401d97

void fr08_401d97(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_0049303c + 0x8c))(DAT_0049303c);
  if (iVar1 < 0) {
    fr08_401000();
    return;
  }
  return;
}

