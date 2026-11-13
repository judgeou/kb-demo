// Original FR08 function at 00401f0c

undefined * fr08_401f0c(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_0045ac48;
  iVar2 = 3;
  while (puVar3[0xc] != '\0') {
    if (((byte)puVar3[0xe] == param_1) && (param_2 <= *(int *)(puVar3 + 8) - *(int *)(puVar3 + 4)))
    {
      return puVar3;
    }
    puVar3 = puVar3 + 0x10;
    iVar2 = iVar2 + 1;
    if (0x3f < iVar2) {
      fr08_409b4a(s_ran_out_of_static_vertex_index_b_0045ab00);
      return (undefined *)0x0;
    }
  }
  puVar3[0xd] = 0;
  puVar3[0xc] = 1;
  puVar3[0xe] = (char)param_1;
  piVar1 = DAT_0049303c;
  if (param_1 == 1) {
    *(undefined4 *)(puVar3 + 8) = 0xc000;
    iVar2 = (**(code **)(*piVar1 + 0x60))(piVar1,0x18000,8,0x65,1,puVar3);
  }
  else {
    *(undefined4 *)(puVar3 + 8) = 0x4000;
    iVar2 = (**(code **)(*piVar1 + 0x5c))(piVar1,0x90000,8,0x152,1,puVar3);
  }
  if (-1 < iVar2) {
    return puVar3;
  }
  fr08_401000();
  return puVar3;
}

