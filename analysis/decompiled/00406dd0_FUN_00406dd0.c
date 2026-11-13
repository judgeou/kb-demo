// Original FR08 function at 00406dd0

uint FUN_00406dd0(void)

{
  int unaff_ESI;
  int unaff_EDI;
  
  return *(uint *)(unaff_ESI + -4) & 0xffffff | *(int *)(unaff_EDI + -4) << 0x18;
}

