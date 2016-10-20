/*
*************************************************************
*@ File : stm8s_flash.h
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

#ifndef __STM8S_FLASH__
#define __STM8S_FLASH__

#include <stm8s.h>

#define FLASH ((FLASH_Registers*)0x00505a)
#define PMASS1 0x56
#define PMASS2 0xae
#define DMASS1 0xae
#define DMASS2 0x56

#define EEPROM_START_ADDRESS 0x004000
#define PROGRAM_START_ADDRESS 0x008080

uint8_t FLASH_ProgramUnlock(void);
uint8_t FLASH_EepromUnlock(void);
static inline void FLASH_ProgramLock(void);
static inline void FLASH_EepromLock(void);

static inline void FLASH_ProgramLock(void)
{
	FLASH->IAPSR &= ~(1<<1);
}

static inline void FLASH_EepromLock(void)
{
	FLASH->IAPSR &= ~(1<<3);
}



#endif