// Original FR08 function at 0040bee5

undefined8 fr08_40bee5(void)

{
  int *piVar1;
  int in_EAX;
  int unaff_EBX;
  int unaff_EDI;
  undefined4 in_stack_00000014;
  undefined4 in_stack_0000001c;
  
  while( true ) {
    if (-1 < unaff_EBX) {
      piVar1 = (int *)(unaff_EDI + unaff_EBX * 4);
      *piVar1 = *piVar1 + 1;
      *(int *)(unaff_EDI + 0x40) = *(int *)(unaff_EDI + 0x40) + 1;
    }
    in_EAX = in_EAX + 1;
    if ((char)in_EAX == '\x10') break;
    unaff_EBX = (&DAT_00715c14)[in_EAX];
  }
  return CONCAT44(in_stack_00000014,in_stack_0000001c);
}

