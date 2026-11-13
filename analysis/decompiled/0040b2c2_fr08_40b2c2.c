// Original FR08 function at 0040b2c2

undefined8 __fastcall fr08_40b2c2(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int iVar1;
  undefined *unaff_EBP;
  
  for (iVar1 = 0xda64; iVar1 != 0; iVar1 = iVar1 + -1) {
    *unaff_EBP = 0;
    unaff_EBP = unaff_EBP + 1;
  }
  return CONCAT44(param_2,in_EAX);
}

