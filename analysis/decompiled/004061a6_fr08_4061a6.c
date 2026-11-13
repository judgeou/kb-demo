// Original FR08 function at 004061a6

undefined fr08_4061a6(int param_1,uint param_2,uint param_3)

{
  return *(undefined *)
          (*(int *)(param_1 + 0x24) + ((param_3 & 0xff) * 0x100 + (param_2 & 0xff)) * 4);
}

