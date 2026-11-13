// Original FR08 function at 00409bd8

void FUN_00409bd8(void)

{
  code *pcVar1;
  int iVar2;
  code **ppcVar3;
  code *local_48 [4];
  undefined *local_38;
  undefined4 local_2c;
  undefined *local_24;
  undefined local_20 [28];
  
  PTR_IMAGE_DOS_HEADER_00594314 = (undefined *)(*DAT_00444078)(0);
  ppcVar3 = local_48;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppcVar3 = (code *)0x0;
    ppcVar3 = ppcVar3 + 1;
  }
  local_48[1] = FUN_00409ccb;
  local_24 = &DAT_0045ac08;
  local_38 = PTR_IMAGE_DOS_HEADER_00594314;
  local_2c = (*DAT_00444008)(4);
  (*DAT_004440a4)(local_48);
  (*DAT_0044408c)(0,&DAT_0045ac08,&DAT_0045ac00,0xcf0000,0x80000000,0,800,600,0,0,
                  PTR_IMAGE_DOS_HEADER_00594314,0);
  (*DAT_004440d4)(DAT_00594328,5);
  DAT_0059432d = 1;
  fr08_40105b();
  DAT_0059432c = 1;
  DAT_0059432d = 0;
  (*DAT_004440d0)(DAT_00594328);
  (*DAT_004440cc)(DAT_00594328,0,0);
  pcVar1 = DAT_004440ac;
  while( true ) {
    iVar2 = (*pcVar1)(local_20,0,0,0);
    if (iVar2 == 0) break;
    (*DAT_004440b0)(local_20);
    (*DAT_004440b4)(local_20);
  }
  (*DAT_0044406c)(0);
  return;
}

