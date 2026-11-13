// Original FR08 function at 004085c5

void fr08_4085c5(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < DAT_005272e0) {
    do {
      fr08_408634();
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_005272e0);
  }
  return;
}

