// Original FR08 function at 00406feb

void __fastcall FUN_00406feb(undefined4 param_1,code *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int extraout_ECX;
  code *extraout_EDX;
  int unaff_EBP;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined8 in_MM6;
  
  puVar5 = *(undefined4 **)(unaff_EBP + 8);
  do {
    uVar6 = (*param_2)();
    uVar6 = paddsw(uVar6,in_MM6);
    uVar6 = psubusw(uVar6,in_MM6);
    sVar1 = (short)uVar6;
    sVar2 = (short)((ulonglong)uVar6 >> 0x10);
    sVar3 = (short)((ulonglong)uVar6 >> 0x20);
    sVar4 = (short)((ulonglong)uVar6 >> 0x30);
    *puVar5 = CONCAT13((0 < sVar4) * (sVar4 < 0xff) * (char)((ulonglong)uVar6 >> 0x30) -
                       (0xff < sVar4),
                       CONCAT12((0 < sVar3) * (sVar3 < 0xff) * (char)((ulonglong)uVar6 >> 0x20) -
                                (0xff < sVar3),
                                CONCAT11((0 < sVar2) * (sVar2 < 0xff) *
                                         (char)((ulonglong)uVar6 >> 0x10) - (0xff < sVar2),
                                         (0 < sVar1) * (sVar1 < 0xff) * (char)uVar6 - (0xff < sVar1)
                                        )));
    puVar5 = puVar5 + 1;
    param_2 = extraout_EDX;
  } while (extraout_ECX != 1);
  return;
}

