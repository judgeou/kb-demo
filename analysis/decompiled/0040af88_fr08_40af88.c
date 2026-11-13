// Original FR08 function at 0040af88

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40af88(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  float fVar4;
  undefined4 in_EAX;
  uint uVar5;
  int iVar6;
  uint uVar7;
  float fVar8;
  int iVar9;
  
  iVar3 = (&DAT_00715c14)[param_2];
  if (-1 < iVar3) {
    iVar9 = *(int *)(DAT_00715c08 + (uint)(byte)(&DAT_00715c94)[iVar3 * 8] * 4) + DAT_00715c08;
    iVar6 = 0;
    do {
      _DAT_00715bc4 = (float)(uint)*(byte *)(iVar9 + iVar6);
      *(float *)(&DAT_00715d18 + iVar6 * 4 + param_2 * 0xd0) = (float)(int)_DAT_00715bc4;
      iVar6 = iVar6 + 1;
    } while ((char)iVar6 != '4');
    pbVar1 = (byte *)(iVar9 + 0x45);
    for (uVar7 = (uint)*(byte *)(iVar9 + 0x44); uVar7 != 0; uVar7 = uVar7 - 1) {
      bVar2 = *pbVar1;
      if (bVar2 == 0) {
        fVar8 = *(float *)(&DAT_00716a1c + param_2 * 0x1f0);
      }
      else if (bVar2 < 8) {
        fVar8 = (float)(uint)(byte)(&DAT_00715c94)[iVar3 * 8 + (uint)bVar2];
      }
      else {
        fVar8 = *(float *)(&DAT_00716a18 +
                          *(int *)(&DAT_0040af78 + (uint)(bVar2 & 3) * 4) + param_2 * 0x1f0);
      }
      _DAT_00715bc4 = (float)(uint)pbVar1[1];
      fVar4 = ((float)(int)_DAT_00715bc4 - _DAT_0040a420) * _DAT_0040a40c;
      uVar5 = (uint)pbVar1[2];
      if (uVar5 < 0x34) {
        _DAT_00715bc4 =
             (fVar4 + fVar4) * fVar8 + *(float *)(&DAT_00715d18 + uVar5 * 4 + param_2 * 0xd0);
        fVar8 = _DAT_00715bc4;
        if ((int)_DAT_00715bc4 < 0) {
          fVar8 = 0.0;
        }
        if (0x43000000 < (uint)fVar8) {
          fVar8 = 128.0;
        }
        *(float *)(&DAT_00715d18 + uVar5 * 4 + param_2 * 0xd0) = fVar8;
      }
      pbVar1 = pbVar1 + 3;
    }
    fr08_40ae5f();
  }
  return CONCAT44(param_2,in_EAX);
}

