// Original FR08 function at 00406de3

void __fastcall FUN_00406de3(undefined4 param_1,code *param_2)

{
  int extraout_ECX;
  undefined4 *puVar1;
  int unaff_EBP;
  undefined8 uVar2;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -4);
  do {
    uVar2 = (*param_2)();
    param_2 = (code *)((ulonglong)uVar2 >> 0x20);
    *puVar1 = (int)uVar2;
    puVar1 = puVar1 + 1;
  } while (extraout_ECX != 1);
  return;
}

