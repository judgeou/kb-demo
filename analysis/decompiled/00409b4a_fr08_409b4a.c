// Original FR08 function at 00409b4a

void fr08_409b4a(undefined4 param_1)

{
  undefined4 unaff_retaddr;
  
  fr08_4013e6();
  (*DAT_00444064)(param_1);
  (*DAT_004440bc)(0,unaff_retaddr,s_fr_08_0045abec,0);
  (*DAT_0044406c)(1);
  return;
}

