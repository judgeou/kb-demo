// Original FR08 function at 00406e1a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406e1a(float **param_1)

{
  float **ppfVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  float10 fVar5;
  undefined4 local_41c [257];
  longlong local_18;
  undefined8 local_10;
  float *local_8;
  
  ppfVar1 = param_1;
  if (param_1[4] != (float *)0x0) {
    param_1[4] = (float *)0x0;
    fr08_409e00(1);
    (*(code *)param_1[1][6])(param_1[1]);
    param_1 = (float **)0x0;
    puVar4 = local_41c;
    local_8 = ppfVar1[9];
    local_10._0_4_ = (undefined4)(longlong)ROUND((*ppfVar1)[1] * _DAT_00444148);
    local_10 = CONCAT44((undefined4)local_10,(undefined4)local_10);
    do {
      fVar5 = (float10)fr08_40a031((double)((float)(int)param_1 * _DAT_00444108),(double)**ppfVar1);
      param_1 = (float **)((int)param_1 + 1);
      local_18 = (longlong)ROUND(fVar5 * (float10)_DAT_004441b8);
      *puVar4 = (undefined4)local_18;
      puVar4 = puVar4 + 1;
    } while ((int)param_1 < 0x101);
    iVar3 = 0;
    do {
      iVar2 = fr08_405e21();
      *(undefined *)(iVar3 + (int)local_8) = *(undefined *)(local_41c + iVar2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x40000);
  }
  return;
}

