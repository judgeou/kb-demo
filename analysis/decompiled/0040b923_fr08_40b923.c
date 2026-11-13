// Original FR08 function at 0040b923

undefined8 __fastcall
fr08_40b923(undefined4 param_1_00,undefined4 param_2_00,int param_1,uint param_2)

{
  undefined4 in_EAX;
  uint extraout_ECX;
  uint uVar1;
  int iVar2;
  int extraout_EDX;
  int extraout_EDX_00;
  char cVar3;
  ushort in_FPUControlWord;
  
  DAT_00715bc4 = in_FPUControlWord & 0xf0ff | 0x3f;
  DAT_00726f90 = param_2;
  DAT_00726f98 = param_1;
  DAT_00715c04 = in_FPUControlWord;
  while (DAT_00726f90 != 0) {
    uVar1 = DAT_00726f90;
    if (DAT_00715d14 < DAT_00726f90) {
      uVar1 = DAT_00715d14;
    }
    if (uVar1 != 0) {
      fr08_40ba10();
      uVar1 = extraout_ECX;
    }
    DAT_00726f90 = DAT_00726f90 - uVar1;
    DAT_00726f98 = DAT_00726f98 + uVar1 * 8;
    DAT_00715d14 = DAT_00715d14 - uVar1;
    if (DAT_00715d14 == 0) {
      iVar2 = 0;
      DAT_00715d14 = 0;
      do {
        if (-1 < (int)(&DAT_00715c14)[iVar2]) {
          fr08_40ad06();
          if ((&DAT_00716b40)[iVar2 * 0x7c] == 0) {
            (&DAT_00715c14)[extraout_EDX] = 0xffffffff;
            iVar2 = extraout_EDX;
          }
          else {
            fr08_40af88();
            iVar2 = extraout_EDX_00;
          }
        }
        iVar2 = iVar2 + 1;
      } while ((char)iVar2 != '\x10');
      cVar3 = '\0';
      do {
        fr08_40b67b();
        cVar3 = cVar3 + '\x01';
      } while (cVar3 != '\x10');
      fr08_40b7b2();
      DAT_00715d14 = 0x100;
    }
  }
  return CONCAT44(param_2_00,in_EAX);
}

