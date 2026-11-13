// Original FR08 function at 0040ba10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40ba10(int param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 in_EAX;
  int iVar4;
  int iVar5;
  int extraout_EDX;
  float *pfVar6;
  undefined4 *puVar7;
  
  pfVar6 = DAT_00726f98;
  DAT_00726f94 = param_1;
  for (iVar4 = param_1 << 1; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar6 = 0.0;
    pfVar6 = pfVar6 + 1;
  }
  puVar7 = &DAT_007147c4;
  for (iVar4 = DAT_00726f94; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  puVar7 = &DAT_00714bc4;
  for (iVar4 = DAT_00726f94; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  iVar4 = 0;
  do {
    iVar5 = 0;
    while (iVar4 != (&DAT_00715c14)[iVar5]) {
      iVar5 = iVar5 + 1;
      if ((char)iVar5 == '\x10') goto LAB_0040baca;
    }
    puVar7 = &DAT_007153c4;
    for (iVar5 = DAT_00726f94 << 1; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    iVar5 = 0;
    do {
      if (iVar4 == (&DAT_00715c14)[iVar5]) {
        fr08_40ad4d();
        iVar5 = extraout_EDX;
      }
      iVar5 = iVar5 + 1;
    } while ((char)iVar5 != '\x10');
    if ((char)iVar4 == '\x0f') {
      fr08_40b7ba();
    }
    fr08_40b5cc();
LAB_0040baca:
    iVar4 = iVar4 + 1;
    if ((char)iVar4 == '\x10') {
      fr08_40b317();
      fr08_40b228();
      fVar3 = DAT_00726f84;
      iVar4 = DAT_00726f94;
      pfVar6 = DAT_00726f98;
      do {
        fVar2 = *pfVar6 - _DAT_00726f7c;
        _DAT_00726f7c = fVar2 * _DAT_00726f78 + _DAT_00726f7c;
        fVar1 = pfVar6[1] - _DAT_00726f80;
        _DAT_00726f80 = fVar1 * _DAT_00726f78 + _DAT_00726f80;
        if (fVar3 != 1.0) {
          fVar2 = (fVar2 - _DAT_00726f88) * DAT_00726f84 + _DAT_00726f88;
          fVar1 = (fVar1 - _DAT_00726f8c) * DAT_00726f84 + _DAT_00726f8c;
          _DAT_00726f8c = fVar1;
          _DAT_00726f88 = fVar2;
        }
        *pfVar6 = fVar2;
        pfVar6[1] = fVar1;
        pfVar6 = pfVar6 + 2;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      return CONCAT44(param_2,in_EAX);
    }
  } while( true );
}

