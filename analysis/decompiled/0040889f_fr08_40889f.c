// Original FR08 function at 0040889f

void fr08_40889f(int param_1,undefined4 param_2)

{
  **(undefined4 **)(param_1 + 4) = param_2;
  fr08_402b54(*(undefined4 *)(param_1 + 8));
  return;
}

