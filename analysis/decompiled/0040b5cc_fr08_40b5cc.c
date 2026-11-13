// Original FR08 function at 0040b5cc

undefined8 __fastcall fr08_40b5cc(undefined4 param_1,undefined4 param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 in_EAX;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar5;
  int iVar6;
  float *unaff_EBP;
  float *pfVar7;
  float *pfVar8;
  
  pfVar7 = (float *)&DAT_007153c4;
  if (unaff_EBP[3] == 0.0) {
    fr08_40ac77();
    fr08_40b268();
    iVar6 = extraout_ECX;
  }
  else {
    fr08_40b268();
    fr08_40ac77();
    iVar6 = extraout_ECX_00;
  }
  if (unaff_EBP[1] != 0.0) {
    pfVar8 = (float *)&DAT_007147c4;
    iVar5 = iVar6;
    do {
      fVar2 = *pfVar7;
      pfVar1 = pfVar7 + 1;
      pfVar7 = pfVar7 + 2;
      *pfVar8 = (fVar2 + *pfVar1) * unaff_EBP[1] + *pfVar8;
      pfVar8 = pfVar8 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  pfVar7 = (float *)&DAT_007153c4;
  if (unaff_EBP[2] != 0.0) {
    pfVar8 = (float *)&DAT_00714bc4;
    iVar5 = iVar6;
    do {
      fVar2 = *pfVar7;
      pfVar1 = pfVar7 + 1;
      pfVar7 = pfVar7 + 2;
      *pfVar8 = (fVar2 + *pfVar1) * unaff_EBP[2] + *pfVar8;
      pfVar8 = pfVar8 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  pfVar7 = (float *)&DAT_007153c4;
  pfVar8 = DAT_00726f98;
  do {
    fVar2 = *pfVar7;
    fVar3 = pfVar7[1];
    fVar4 = *unaff_EBP;
    pfVar7 = pfVar7 + 2;
    *pfVar8 = fVar2 * *unaff_EBP + *pfVar8;
    pfVar8[1] = fVar3 * fVar4 + pfVar8[1];
    pfVar8 = pfVar8 + 2;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return CONCAT44(param_2,in_EAX);
}

