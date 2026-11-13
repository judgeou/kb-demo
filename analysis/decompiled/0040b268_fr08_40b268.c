// Original FR08 function at 0040b268

undefined8 __fastcall fr08_40b268(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int extraout_ECX;
  undefined4 extraout_EDX;
  int unaff_EBP;
  float *pfVar1;
  float10 fVar2;
  float10 extraout_ST1;
  
  if (*(int *)(unaff_EBP + 0x30) != 0) {
    pfVar1 = (float *)&DAT_007153c4;
    do {
      fVar2 = (float10)fr08_40b157();
      *pfVar1 = (float)fVar2;
      pfVar1[1] = (float)extraout_ST1;
      pfVar1 = pfVar1 + 2;
    } while (extraout_ECX != 1);
    *(undefined4 *)(unaff_EBP + 0xc) = extraout_EDX;
  }
  return CONCAT44(param_2,in_EAX);
}

