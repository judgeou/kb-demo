// Original FR08 function at 0040b0a6

undefined8 __fastcall fr08_40b0a6(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  int *unaff_EBP;
  undefined4 *puVar3;
  
  unaff_EBP[3] = 0;
  unaff_EBP[6] = 0;
  iVar1 = *unaff_EBP;
  iVar2 = unaff_EBP[2];
  puVar3 = (undefined4 *)unaff_EBP[1];
  do {
    *puVar3 = 0;
    *(undefined4 *)(iVar1 + iVar2 * 4) = 0;
    iVar2 = iVar2 + -1;
    puVar3 = puVar3 + 1;
  } while (-1 < iVar2);
  return CONCAT44(param_2,in_EAX);
}

