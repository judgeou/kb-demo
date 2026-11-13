// Original FR08 function at 00405e21

int fr08_405e21(int param_1)

{
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0xff < param_1) {
    param_1 = 0xff;
  }
  return param_1;
}

