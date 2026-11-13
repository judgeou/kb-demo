// Original FR08 function at 0040a935

undefined8 __fastcall fr08_40a935(undefined4 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  undefined4 in_EAX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + 0x14) = 0;
  *(undefined4 *)(unaff_EBP + 0x24) = 0;
  uVar1 = rdtsc();
  *(int *)(unaff_EBP + 0x20) = (int)uVar1;
  return CONCAT44(param_2,in_EAX);
}

