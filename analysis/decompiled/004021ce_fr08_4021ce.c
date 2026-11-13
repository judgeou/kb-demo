// Original FR08 function at 004021ce

void fr08_4021ce(undefined4 *param_1)

{
  char unaff_retaddr;
  
  (**(code **)(**(int **)*param_1 + 0x30))(*(int **)*param_1);
  (**(code **)(**(int **)param_1[3] + 0x30))(*(int **)param_1[3]);
  if (unaff_retaddr != '\0') {
    fr08_4021fb(param_1,1);
  }
  return;
}

