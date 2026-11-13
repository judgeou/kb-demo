// Original FR08 function at 00408c76

void fr08_408c76(void)

{
  int iVar1;
  
  iVar1 = Original_DemoTimeMilliseconds();
  fr08_408909();
  if ((DAT_00591ee4 == 0) && (10000 < iVar1)) {
    fr08_409b77();
  }
  fr08_408a5d();
  fr08_401daf();
  thunk_FUN_0040a3ae();
  return;
}

