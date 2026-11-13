// Original FR08 function at 00406fda

undefined8 FUN_00406fda(void)

{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  undefined8 uVar2;
  undefined8 in_MM2;
  undefined8 in_MM3;
  undefined in_MM7_Ba;
  undefined in_MM7_Bb;
  undefined in_MM7_Bc;
  undefined in_MM7_Bd;
  
  uVar1 = *unaff_ESI;
  uVar2 = psllw(CONCAT62(CONCAT51(CONCAT41((int)(CONCAT35(CONCAT21(CONCAT11(in_MM7_Bd,
                                                                            (char)((uint)uVar1 >>
                                                                                  0x18)),in_MM7_Bc),
                                                          CONCAT14((char)((uint)uVar1 >> 0x10),uVar1
                                                                  )) >> 0x20),in_MM7_Bb),
                                  (char)((uint)uVar1 >> 8)),CONCAT11(in_MM7_Ba,(char)uVar1)),4);
  uVar2 = pmulhw(uVar2,in_MM3);
  uVar2 = paddsw(uVar2,in_MM2);
  return uVar2;
}

