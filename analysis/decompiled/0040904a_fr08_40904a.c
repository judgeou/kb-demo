// Original FR08 function at 0040904a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fr08_40904a(void)

{
  char cVar1;
  int iVar2;
  float fVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  int local_8;
  
  if (DAT_005923a4 == (char *)0x0) {
    DAT_005923a4 = (&PTR_s__ll_>a0_0045ab90)[DAT_005923a8];
  }
  if (DAT_0045aba4 <= DAT_0045aba0) {
    if (DAT_005923ac == 0) {
      for (; cVar1 = *DAT_005923a4, cVar1 != '\0'; DAT_005923a4 = DAT_005923a4 + 1) {
        if (cVar1 == '!') goto LAB_0040915d;
        if (cVar1 == '=') {
          DAT_005923a4 = DAT_005923a4 + 1;
          DAT_005923ac = 10;
          goto LAB_0040915d;
        }
        if (cVar1 != '>') {
          if (cVar1 != '_') {
            DAT_0045aba4 = DAT_0045aba8;
            DAT_0045aba0 = 1;
            pcVar6 = &DAT_00444208;
            pcVar4 = DAT_005923a4;
            do {
              if ((*pcVar6 == *pcVar4) && (pcVar6[1] == pcVar4[1])) {
                fr08_4092bc(pcVar6,DAT_005923a0);
                pcVar4 = DAT_005923a4;
              }
              pcVar6 = pcVar6 + 0x15;
            } while ((int)pcVar6 < 0x444343);
            DAT_005923a0 = 1 - DAT_005923a0;
            DAT_0045aba8 = 2;
            DAT_005923a4 = pcVar4 + 2;
          }
          goto LAB_0040915d;
        }
        DAT_0045aba8 = DAT_0045aba8 + 10;
      }
      DAT_005923a4 = (&PTR_s__ll_>a0_0045ab90)[DAT_005923a8];
      DAT_0045aba8 = 1;
    }
LAB_0040915d:
    local_8 = DAT_0045aba4;
    if (DAT_0045aba4 < DAT_0045aba0) goto LAB_00409167;
  }
  local_8 = DAT_0045aba0;
LAB_00409167:
  iVar5 = DAT_005923a0 * 0x38;
  fVar3 = (float)local_8 / (float)DAT_0045aba4;
  iVar2 = DAT_005923a0 * -0x38;
  _DAT_00592368 = *(undefined4 *)(&DAT_00592330 + iVar2);
  _DAT_0059236c =
       (*(float *)(iVar2 + 0x592334) - *(float *)(&DAT_005922fc + iVar5)) * fVar3 +
       *(float *)(&DAT_005922fc + iVar5);
  _DAT_00592370 =
       (*(float *)(iVar2 + 0x592338) - *(float *)(&DAT_00592300 + iVar5)) * fVar3 +
       *(float *)(&DAT_00592300 + iVar5);
  _DAT_00592374 =
       (*(float *)(iVar2 + 0x59233c) - *(float *)(&DAT_00592304 + iVar5)) * fVar3 +
       *(float *)(&DAT_00592304 + iVar5);
  _DAT_00592378 =
       (*(float *)(iVar2 + 0x592340) - *(float *)(&DAT_00592308 + iVar5)) * fVar3 +
       *(float *)(&DAT_00592308 + iVar5);
  _DAT_0059237c =
       (*(float *)(iVar2 + 0x592344) - *(float *)(&DAT_0059230c + iVar5)) * fVar3 +
       *(float *)(&DAT_0059230c + iVar5);
  _DAT_00592380 =
       (*(float *)(iVar2 + 0x592348) - *(float *)(&DAT_00592310 + iVar5)) * fVar3 +
       *(float *)(&DAT_00592310 + iVar5);
  _DAT_00592384 =
       (*(float *)(iVar2 + 0x59234c) - *(float *)(&DAT_00592314 + iVar5)) * fVar3 +
       *(float *)(&DAT_00592314 + iVar5);
  _DAT_00592388 =
       (*(float *)(iVar2 + 0x592350) - *(float *)(&DAT_00592318 + iVar5)) * fVar3 +
       *(float *)(&DAT_00592318 + iVar5);
  _DAT_0059238c =
       (*(float *)(iVar2 + 0x592354) - *(float *)(&DAT_0059231c + iVar5)) * fVar3 +
       *(float *)(&DAT_0059231c + iVar5);
  _DAT_00592390 =
       (*(float *)(iVar2 + 0x592358) - *(float *)(&DAT_00592320 + iVar5)) * fVar3 +
       *(float *)(&DAT_00592320 + iVar5);
  _DAT_00592394 =
       (*(float *)(iVar2 + 0x59235c) - *(float *)(&DAT_00592324 + iVar5)) * fVar3 +
       *(float *)(&DAT_00592324 + iVar5);
  _DAT_00592398 =
       (*(float *)(iVar2 + 0x592360) - *(float *)(&DAT_00592328 + iVar5)) * fVar3 +
       *(float *)(&DAT_00592328 + iVar5);
  _DAT_0059239c =
       (*(float *)(iVar2 + 0x592364) - *(float *)(&DAT_0059232c + iVar5)) * fVar3 +
       *(float *)(&DAT_0059232c + iVar5);
  fr08_4093b0(2);
  DAT_0045aba0 = DAT_0045aba0 + 1;
  if (DAT_005923ac != 0) {
    DAT_005923ac = DAT_005923ac + -1;
  }
  return;
}

