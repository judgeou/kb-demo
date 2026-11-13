// Original FR08 function at 00409036

void __thiscall fr08_409036(float *param_1_00,float param_1)

{
  int iVar1;
  
  iVar1 = 9;
  do {
    *param_1_00 = param_1 * *param_1_00;
    param_1_00 = param_1_00 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

