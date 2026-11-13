// Original FR08 function at 00409ccb

undefined4 FUN_00409ccb(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined local_44 [64];
  
  DAT_00594328 = param_1;
  if (param_2 == 2) {
    fr08_4013e6();
    (*DAT_004440a0)(0);
  }
  else if (param_2 == 0xf) {
    (*DAT_00444098)(param_1,local_44);
    (*DAT_0044409c)(param_1,local_44);
    if (DAT_0059432c != '\0') {
      fr08_4017f3();
      (*DAT_004440cc)(param_1,0,0);
    }
  }
  else {
    if (param_2 != 0x10) {
      if (param_2 != 0x102) {
        uVar1 = (*DAT_004440a8)(param_1,param_2,param_3,param_4);
        return uVar1;
      }
      if (param_3 != 0x1b) {
        fr08_408caa(param_3);
        return 0;
      }
      fr08_409b36();
    }
    (*DAT_00444094)(DAT_00594328);
  }
  return 0;
}

