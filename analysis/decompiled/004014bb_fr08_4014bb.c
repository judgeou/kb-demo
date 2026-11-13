// Original FR08 function at 004014bb

void fr08_4014bb(byte *param_1,int param_2,int param_3,byte *param_4)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  int local_c;
  int local_8;
  
  local_c = param_3 / 2;
  if (0 < local_c) {
    iVar5 = (int)param_4 * 8;
    iVar8 = (int)param_4 * 4;
    iVar2 = param_2 / 2;
    pbVar7 = param_1;
    do {
      param_4 = param_1;
      pbVar4 = pbVar7 + iVar8;
      pbVar9 = pbVar7 + iVar5;
      local_8 = iVar2;
      if (0 < iVar2) {
        do {
          param_2 = 4;
          do {
            pbVar6 = pbVar7;
            pbVar3 = pbVar4;
            pbVar1 = param_4 + 1;
            param_2 = param_2 + -1;
            *param_4 = (byte)((int)((uint)pbVar3[4] + (uint)pbVar6[4] + (uint)*pbVar3 + 2 +
                                   (uint)*pbVar6) >> 2);
            pbVar4 = pbVar3 + 1;
            pbVar7 = pbVar6 + 1;
            param_4 = pbVar1;
          } while (param_2 != 0);
          pbVar7 = pbVar6 + 5;
          pbVar4 = pbVar3 + 5;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
      local_c = local_c + -1;
      pbVar7 = pbVar9;
      param_1 = param_1 + iVar8;
    } while (local_c != 0);
  }
  return;
}

