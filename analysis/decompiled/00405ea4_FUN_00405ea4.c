// Original FR08 function at 00405ea4

void FUN_00405ea4(float **param_1)

{
  float *pfVar1;
  float **ppfVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int local_2c;
  int local_24;
  int local_20;
  int local_c;
  int local_8;
  
  ppfVar2 = param_1;
  if (param_1[4] != (float *)0x0) {
    param_1[4] = (float *)0x0;
    fr08_409e00(1);
    pfVar1 = *param_1;
    local_2c = (int)(longlong)ROUND(*pfVar1);
    local_24 = local_2c;
    local_2c = (int)(longlong)ROUND(pfVar1[1]);
    local_c = local_2c;
    fr08_409ffe(pfVar1[2]);
    cVar3 = fr08_409fa2(0x7f);
    fr08_406173(param_1,0,0,cVar3 + '@');
    iVar11 = 0x80;
    do {
      iVar10 = 0;
      if (local_c == 0) {
        local_c = 1;
      }
      do {
        param_1 = (float **)0x0;
        local_8 = iVar11;
        do {
          if (local_24 < 1) {
            iVar5 = fr08_4061a6(ppfVar2,param_1,iVar10);
            iVar6 = fr08_4061a6(ppfVar2,local_8 + iVar11,iVar10);
            iVar4 = iVar10 + iVar11 * 2;
            iVar7 = fr08_4061a6(ppfVar2,param_1,iVar4);
            fr08_4061a6(ppfVar2,local_8 + iVar11,iVar4);
            iVar4 = local_c / 2;
            iVar8 = fr08_409fa2(local_c);
            uVar9 = fr08_405e21(iVar8 + ((iVar6 + iVar5) / 2 - iVar4));
            fr08_406173(ppfVar2,local_8,iVar10,uVar9);
            iVar8 = fr08_409fa2(local_c);
            uVar9 = fr08_405e21(iVar8 + ((iVar7 + iVar5) / 2 - iVar4));
            fr08_406173(ppfVar2,param_1,iVar10 + iVar11,uVar9);
            iVar5 = fr08_409fa2(local_c);
            cVar3 = fr08_405e21(iVar5 + ((iVar7 + iVar6) / 2 - iVar4));
            iVar4 = local_8;
          }
          else {
            cVar3 = fr08_409fa2(0x7f);
            fr08_406173(ppfVar2,local_8,iVar10,cVar3 + '@');
            cVar3 = fr08_409fa2(0x7f);
            fr08_406173(ppfVar2,param_1,iVar10 + iVar11,cVar3 + '@');
            cVar3 = fr08_409fa2(0x7f);
            fr08_406173(ppfVar2,local_8,iVar10 + iVar11,cVar3 + '@');
            cVar3 = fr08_409fa2(0x7f);
            fr08_406173(ppfVar2,local_8,iVar10 + iVar11 * 2,cVar3 + '@');
            cVar3 = fr08_409fa2(0x7f);
            cVar3 = cVar3 + '@';
            iVar4 = local_8 + iVar11;
          }
          fr08_406173(ppfVar2,iVar4,iVar10 + iVar11,cVar3);
          iVar4 = iVar11 * 2;
          param_1 = (float **)((int)param_1 + iVar4);
          local_8 = local_8 + iVar4;
        } while ((int)param_1 < 0x100);
        iVar10 = iVar10 + iVar4;
      } while (iVar10 < 0x100);
      if (local_24 < 1) {
        local_c = local_c / 2;
      }
      else {
        local_20 = 0;
        do {
          param_1 = (float **)0x0;
          iVar10 = local_20 + iVar11 * 2;
          local_8 = iVar11;
          do {
            iVar4 = fr08_4061a6(ppfVar2,param_1,local_20 + iVar11);
            iVar5 = fr08_4061a6(ppfVar2,local_8,local_20);
            iVar6 = fr08_4061a6(ppfVar2,local_8 + iVar11,local_20 + iVar11);
            iVar7 = fr08_4061a6(ppfVar2,local_8,iVar10);
            iVar8 = fr08_409fa2(local_c);
            uVar9 = fr08_405e21(iVar8 + ((iVar7 + iVar6 + iVar5 + iVar4) / 4 - local_c / 2));
            fr08_406173(ppfVar2,local_8,local_20 + iVar11,uVar9);
            param_1 = (float **)((int)param_1 + iVar11 * 2);
            local_8 = local_8 + iVar11 * 2;
          } while ((int)param_1 < 0x100);
          local_20 = iVar10;
        } while (iVar10 < 0x100);
      }
      local_24 = local_24 + -1;
      iVar11 = iVar11 / 2;
    } while (0 < iVar11);
  }
  return;
}

