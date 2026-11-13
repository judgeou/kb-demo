// Original FR08 function at 0040b67b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 fr08_40b67b(void)

{
  float *pfVar1;
  char cVar2;
  float fVar3;
  byte bVar4;
  undefined4 in_EAX;
  undefined4 uVar5;
  int iVar6;
  float fVar7;
  int unaff_EBX;
  float *pfVar8;
  int iVar9;
  
  iVar9 = *(int *)(DAT_00715c08 + (uint)(byte)(&DAT_00715c94)[unaff_EBX * 8] * 4) + DAT_00715c08;
  pfVar1 = (float *)(&DAT_00718918 + unaff_EBX * 0x3c);
  iVar6 = 0x34;
  pfVar8 = pfVar1;
  do {
    _DAT_00715bc4 = (float)(uint)*(byte *)(iVar9 + iVar6);
    *pfVar8 = (float)(int)_DAT_00715bc4;
    pfVar8 = pfVar8 + 1;
    iVar6 = iVar6 + 1;
  } while ((char)iVar6 != 'C');
  cVar2 = *(char *)(iVar9 + 0x44);
  if (cVar2 == '\0') {
    uVar5 = FUN_0040b77e();
    return uVar5;
  }
  if ((0x33 < *(byte *)(iVar9 + 0x47)) && (*(byte *)(iVar9 + 0x47) < 0x43)) {
    bVar4 = *(byte *)(iVar9 + 0x45);
    if (bVar4 == 0) {
      fVar7 = *(float *)(unaff_EBX * 0x78 + 0x718cdc);
    }
    else {
      if (7 < bVar4) goto LAB_0040b773;
      fVar7 = (float)(uint)(byte)(&DAT_00715c94)[unaff_EBX * 8 + (uint)bVar4];
    }
    fVar3 = ((float)(uint)*(byte *)(iVar9 + 0x46) - _DAT_0040a420) * _DAT_0040a40c;
    bVar4 = *(char *)(iVar9 + 0x47) - 0x34;
    _DAT_00715bc4 = (fVar3 + fVar3) * fVar7 + pfVar1[bVar4];
    fVar7 = _DAT_00715bc4;
    if ((int)_DAT_00715bc4 < 0) {
      fVar7 = 0.0;
    }
    if (0x43000000 < (uint)fVar7) {
      fVar7 = 128.0;
    }
    pfVar1[bVar4] = fVar7;
  }
LAB_0040b773:
  if (cVar2 == '\x01') {
    fr08_40b574();
    return in_EAX;
  }
  uVar5 = FUN_0040b6e5();
  return uVar5;
}

