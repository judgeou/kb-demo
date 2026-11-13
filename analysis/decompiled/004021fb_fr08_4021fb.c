// Original FR08 function at 004021fb

undefined4 fr08_4021fb(int *param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = param_1;
  if (0 < param_2) {
    do {
      if ((*(char *)(*piVar2 + 0xd) != '\0') && (piVar2[6] != DAT_004cbe5c)) {
        return 0;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 0xe;
    } while (iVar3 < param_2);
  }
  if (0 < param_2) {
    do {
      if ((param_1[2] != 0) && (cVar1 = fr08_401dcb(param_1), cVar1 != '\0')) {
        if (*(char *)(param_1 + 7) != '\0') {
          (**(code **)(*DAT_0049303c + 0x130))(DAT_0049303c,0x2c2);
        }
        fr08_402309();
        iVar3 = (**(code **)(*DAT_0049303c + 0x154))(DAT_0049303c,*(undefined4 *)param_1[3],0);
        if (iVar3 < 0) {
          fr08_401000();
        }
        iVar3 = (**(code **)(*DAT_0049303c + 0x14c))(DAT_0049303c,0,*(undefined4 *)*param_1,0x24);
        if (iVar3 < 0) {
          fr08_401000();
        }
        iVar3 = (**(code **)(*DAT_0049303c + 0x11c))
                          (DAT_0049303c,4,param_1[1],param_1[2],param_1[4],param_1[5] / 3);
        if (iVar3 < 0) {
          fr08_401000();
        }
        if (*(char *)(param_1 + 7) != '\0') {
          (**(code **)(*DAT_0049303c + 0x130))(DAT_0049303c,0x152);
        }
      }
      param_1 = param_1 + 0xe;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return 1;
}

