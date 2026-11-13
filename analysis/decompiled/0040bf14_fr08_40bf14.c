// Original FR08 function at 0040bf14

undefined8 __fastcall fr08_40bf14(undefined4 param_1_00,undefined4 param_2,undefined4 *param_1)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00719488;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return CONCAT44(param_2,in_EAX);
}

