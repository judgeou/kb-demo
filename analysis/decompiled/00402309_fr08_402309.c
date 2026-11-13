// Original FR08 function at 00402309

void fr08_402309(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = 0;
  do {
    iVar1 = (&DAT_004cb040)[iVar4];
    if (((&DAT_004cb04c)[iVar4] != iVar1) && (iVar1 != -1)) {
      fr08_40172c(iVar4,iVar1);
      (&DAT_004cb04c)[iVar4] = (&DAT_004cb040)[iVar4];
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  uVar3 = 0;
  do {
    uVar2 = (&DAT_004cbe70)[uVar3];
    if (((&DAT_004cc274)[uVar3] != uVar2) && (uVar2 != 0xffffffff)) {
      (&DAT_004cc274)[uVar3] = uVar2;
      if ((uVar3 == 0xcb) || (uVar3 == 0xeb)) {
        uVar2 = uVar2 & 0xf | (uVar2 & 0xf0) << 0xc;
      }
      if (uVar3 < 0xc0) {
        if (0xdf < uVar3) goto LAB_004023aa;
LAB_004023c5:
        (**(code **)(*DAT_0049303c + 200))(DAT_0049303c,uVar3,uVar2);
      }
      else {
        if (uVar3 < 0xe1) {
          iVar4 = uVar3 - 0xc0;
          iVar1 = *DAT_0049303c;
          uVar5 = 0;
        }
        else {
LAB_004023aa:
          if (0x100 < uVar3) goto LAB_004023c5;
          iVar4 = uVar3 - 0xe0;
          iVar1 = *DAT_0049303c;
          uVar5 = 1;
        }
        (**(code **)(iVar1 + 0xfc))(DAT_0049303c,uVar5,iVar4,uVar2);
      }
    }
    uVar3 = uVar3 + 1;
    if (0xfe < (int)uVar3) {
      return;
    }
  } while( true );
}

