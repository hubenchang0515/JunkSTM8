/*
*************************************************************
*@ File : stm8s_flash.c
*@ Author : www.kurukurumi.com
*@ E-mail : hubenchang0515@outlook.com
*@ version : v1.1.1
*@ Date : 2016-5-12
*************************************************************
*
*     This file is about flash and eeprom.
*
*     This library is used to tell readers how to build a 
* library of STM8.Everybody can use these source to do 
* anything.AUTHOR WILL NOT BEAR THE BLAME OF ANY DAMAGES
* CREATED BY THIS LIBRARY.
*************************************************************
*/

#include <stm8s_flash.h>

uint8_t FLASH_ProgramUnlock(void)
{
	FLASH->PUKR = PMASS1;
	FLASH->PUKR = PMASS2;
	asm("nop");
	asm("nop");
	asm("nop");
	if(FLASH->IAPSR & (1<<1))
		return 1;
	else
		return 0;
}

uint8_t FLASH_EepromUnlock(void)
{
	FLASH->DUKR = DMASS1;
	FLASH->DUKR = DMASS2;
	asm("nop");
	asm("nop");
	asm("nop");
	if(FLASH->IAPSR & (1<<3))
		return 1;
	else
		return 0;
}
