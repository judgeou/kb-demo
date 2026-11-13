// Original FR08 function at 0040bbac

undefined8 __fastcall fr08_40bbac(undefined4 param_1_00,undefined4 param_2,byte *param_1)

{
  byte bVar1;
  undefined4 in_EAX;
  ushort in_FPUControlWord;
  
  DAT_00715bc4 = in_FPUControlWord & 0xf0ff | 0x3f;
  DAT_00715c04 = in_FPUControlWord;
  do {
    bVar1 = *param_1;
    if ((bVar1 & 0x80) != 0) {
      if (bVar1 == 0xfd) {
LAB_0040bbe1:
        return CONCAT44(param_2,in_EAX);
      }
      param_1 = param_1 + 1;
      DAT_00715c0c = (uint)bVar1;
    }
    if ((DAT_00715c0c >> 4 & 8) == 0) goto LAB_0040bbe1;
    (*(code *)(&PTR_LAB_0040bb8c)[DAT_00715c0c >> 4 & 7])();
  } while( true );
}

