// Original FR08 function at 004017f3

void fr08_4017f3(void)

{
  fr08_408c76();
  DAT_004cb048 = DAT_004cb048 + 1;
  if (DAT_004cb048 == 0) {
    DAT_004cb048 = 1;
  }
  DAT_0045ac10 = 0;
  return;
}

