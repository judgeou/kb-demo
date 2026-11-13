// Original FR08 function at 0040ad4d

undefined8 __fastcall fr08_40ad4d(int param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 in_EAX;
  int extraout_ECX;
  int iVar4;
  int extraout_ECX_00;
  char extraout_DL;
  int unaff_EBP;
  float *pfVar5;
  undefined4 *puVar6;
  float *pfVar7;
  
  puVar6 = &DAT_00714fc4;
  for (; param_1 != 0; param_1 = param_1 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  fr08_40a585();
  fr08_40a585();
  fr08_40a585();
  if ((char)*(undefined4 *)(unaff_EBP + 0x14) == '\x02') {
    fr08_40a880();
  }
  fr08_40a880();
  if (extraout_DL != '\0') {
    if (extraout_DL == '\x02') {
      pfVar5 = (float *)&DAT_007143c4;
      pfVar7 = (float *)&DAT_00714fc4;
      iVar4 = extraout_ECX;
      do {
        fVar1 = *pfVar5;
        pfVar5 = pfVar5 + 1;
        *pfVar7 = fVar1 + *pfVar7;
        pfVar7 = pfVar7 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    else {
      fr08_40a880();
    }
  }
  fr08_40ab71();
  pfVar7 = (float *)&DAT_007153c4;
  pfVar5 = (float *)&DAT_00714fc4;
  fVar1 = *(float *)(unaff_EBP + 0xc);
  iVar4 = extraout_ECX_00;
  do {
    fVar3 = *pfVar5 * fVar1;
    fVar1 = fVar1 + *(float *)(unaff_EBP + 0x10);
    fVar2 = *(float *)(unaff_EBP + 0x1c);
    *pfVar7 = fVar3 * *(float *)(unaff_EBP + 0x18) + *pfVar7;
    pfVar7[1] = fVar3 * fVar2 + pfVar7[1];
    pfVar5 = pfVar5 + 1;
    pfVar7 = pfVar7 + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(float *)(unaff_EBP + 0xc) = fVar1;
  return CONCAT44(param_2,in_EAX);
}

