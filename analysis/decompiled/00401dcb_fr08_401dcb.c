// Original FR08 function at 00401dcb

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 fr08_401dcb(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined2 uVar6;
  
  if ((DAT_0045b01c == 0) && (*(float *)((int)param_1 + 0x20) != _DAT_004440e8)) {
    fVar1 = *(float *)((int)param_1 + 0x24);
    fVar2 = *(float *)((int)param_1 + 0x28);
    fVar3 = *(float *)((int)param_1 + 0x2c);
    fr08_408d82(&DAT_004ccaa8);
    fVar4 = (DAT_004cc678 + fVar1) - _DAT_004cca64;
    fVar2 = (DAT_004cc67c + fVar2) - _DAT_004cca68;
    fVar3 = (DAT_004cc680 + fVar3) - _DAT_004cca6c;
    fr08_408dd1(&DAT_004cca70);
    fVar1 = *(float *)((int)param_1 + 0x20);
    fVar5 = fVar3 + fVar1;
    if ((_DAT_004cca50 <= fVar5) && (fVar3 - fVar1 <= _DAT_004cca4c)) {
      param_1 = fVar4;
      if (fVar4 < _DAT_004440e8) {
        param_1 = -fVar4;
      }
      if (fVar2 < _DAT_004440e8) {
        fVar2 = -fVar2;
      }
      fVar5 = DAT_004cca48 / fVar5;
      if ((fVar5 * param_1 - fVar1 * fVar5 <= _DAT_004440ec) &&
         (fVar5 * fVar2 - fVar1 * fVar5 <= _DAT_004440ec)) goto LAB_00401eff;
    }
    uVar6 = 0;
  }
  else {
LAB_00401eff:
    uVar6 = 1;
  }
  return uVar6;
}

