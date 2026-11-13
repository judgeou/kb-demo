// Original FR08 function at 0040b228

undefined8 __fastcall fr08_40b228(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int extraout_ECX;
  undefined4 extraout_EDX;
  int unaff_EBP;
  float *unaff_EDI;
  float10 fVar1;
  float10 extraout_ST1;
  
  if (*(int *)(unaff_EBP + 0x30) != 0) {
    do {
      fVar1 = (float10)fr08_40b157();
      *unaff_EDI = (float)(fVar1 + (float10)*unaff_EDI);
      unaff_EDI[1] = (float)(extraout_ST1 + (float10)unaff_EDI[1]);
      unaff_EDI = unaff_EDI + 2;
    } while (extraout_ECX != 1);
    *(undefined4 *)(unaff_EBP + 0xc) = extraout_EDX;
  }
  return CONCAT44(param_2,in_EAX);
}

