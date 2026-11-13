// Original FR08 function at 0040aef7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall fr08_40aef7(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  int in_EAX;
  int unaff_EBX;
  int *unaff_EBP;
  
  *unaff_EBP = in_EAX;
  fVar1 = (float)*unaff_EBP;
  unaff_EBP[0x19] = (int)fVar1;
  unaff_EBP[0x2b] = (int)fVar1;
  unaff_EBP[0x3d] = (int)fVar1;
  _DAT_00715bc4 = unaff_EBX;
  unaff_EBP[1] = (int)(float)unaff_EBX;
  unaff_EBP[2] = 1;
  unaff_EBP[0x4a] = 1;
  unaff_EBP[0x53] = 1;
  if (unaff_EBP[8] != 0) {
    unaff_EBP[10] = 0;
    unaff_EBP[0x1c] = 0;
    unaff_EBP[0x2e] = 0;
  }
  fr08_40a49b();
  fr08_40a49b();
  fr08_40a49b();
  fr08_40a98b();
  fr08_40a98b();
  return CONCAT44(param_2,in_EAX);
}

