// Original FR08 function at 0040a98b

undefined8 __fastcall fr08_40a98b(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + 8) != 0) {
    *(undefined4 *)(unaff_EBP + 0x14) = *(undefined4 *)(unaff_EBP + 0x18);
    *(undefined4 *)(unaff_EBP + 0x24) = 0xffffffff;
  }
  return CONCAT44(param_2,in_EAX);
}

