// Original FR08 function at 0040aa60

undefined8 __fastcall fr08_40aa60(undefined4 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  undefined4 in_EAX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + 0x1c) = 0;
  *(undefined4 *)(unaff_EBP + 0x24) = 0;
  *(undefined4 *)(unaff_EBP + 0x28) = 0;
  uVar1 = rdtsc();
  *(int *)(unaff_EBP + 0x2c) = (int)uVar1;
  return CONCAT44(param_2,in_EAX);
}

