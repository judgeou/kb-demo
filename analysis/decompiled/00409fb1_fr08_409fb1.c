// Original FR08 function at 00409fb1

uint fr08_409fb1(void)

{
  DAT_0045ac0c = DAT_0045ac0c * 0x343fd + 0x269ec3;
  return DAT_0045ac0c >> 0x10 & 0x7fff;
}

