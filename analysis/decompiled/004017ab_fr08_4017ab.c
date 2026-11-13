// Original FR08 function at 004017ab

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_4017ab(int param_1)

{
  if (param_1 != DAT_004ccaa4) {
    fr08_401778(DAT_0058385c);
    if (param_1 != 0) {
      fr08_401778(param_1);
    }
    DAT_004ccaa4 = param_1;
  }
  _DAT_004cc250 = 2;
  _DAT_004cc1d0 = 2;
  return;
}

