// Original FR08 function at 0040a335

void Original_DSoundTimeBytes(void)

{
  int iVar1;
  
  FUN_004433ea(&DAT_00594388);
  (**(code **)(*DAT_00594338 + 0x10))(DAT_00594338,&DAT_005943a0,0);
  FUN_004433f0(&DAT_00594388);
  iVar1 = DAT_005943a0 - DAT_00594378;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x20000;
  }
  if (0x7fff < iVar1) {
    iVar1 = DAT_005943ac - DAT_005943a8;
  }
  DAT_005943ac = iVar1 + DAT_005943a8;
  return;
}

