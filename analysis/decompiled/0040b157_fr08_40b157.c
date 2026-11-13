// Original FR08 function at 0040b157

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall fr08_40b157(undefined4 param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  int *unaff_EBP;
  float10 in_ST0;
  float10 fVar4;
  float10 in_ST1;
  float10 in_ST2;
  float10 in_ST3;
  float10 in_ST4;
  
  lVar2 = (ulonglong)((unaff_EBP[6] + unaff_EBP[8]) * 2 ^ -(uint)(unaff_EBP[6] + unaff_EBP[8] < 0))
          * (ulonglong)(uint)unaff_EBP[9];
  uVar3 = (param_2 - ((int)((ulonglong)lVar2 >> 0x20) + unaff_EBP[5])) - 1U & unaff_EBP[2];
  iVar1 = unaff_EBP[1];
  fVar4 = (float10)*(float *)(iVar1 + uVar3 * 4);
  *(float *)(iVar1 + param_2 * 4) =
       (float)((fVar4 + ((float10)*(float *)(iVar1 + (uVar3 + 1 & unaff_EBP[2]) * 4) - fVar4) *
                        ((float10)_DAT_0040a404 - (float10)(float)((uint)lVar2 >> 9 | 0x3f800000)))
               * in_ST4 + in_ST0);
  lVar2 = (ulonglong)(unaff_EBP[6] << 1 ^ -(uint)(unaff_EBP[6] < 0)) * (ulonglong)(uint)unaff_EBP[9]
  ;
  uVar3 = param_2 - ((int)((ulonglong)lVar2 >> 0x20) + unaff_EBP[4]) & unaff_EBP[2];
  _DAT_00715bc4 = (float)((uint)lVar2 >> 9 | 0x3f800000);
  iVar1 = *unaff_EBP;
  fVar4 = (float10)*(float *)(iVar1 + uVar3 * 4);
  fVar4 = fVar4 + ((float10)*(float *)(iVar1 + (uVar3 + 1 & unaff_EBP[2]) * 4) - fVar4) *
                  ((float10)_DAT_0040a404 - (float10)_DAT_00715bc4);
  *(float *)(iVar1 + param_2 * 4) = (float)(fVar4 * in_ST4 + in_ST1);
  unaff_EBP[6] = unaff_EBP[6] + unaff_EBP[7];
  return in_ST1 * in_ST3 + fVar4 * in_ST2;
}

