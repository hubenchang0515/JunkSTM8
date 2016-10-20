/*
*************************************************************
*@ File : stm8s_clock.h
*@ Author : www.kurukurumi.com
*@ E-mail : hubenchang0515@outlook.com
*@ version : v1.1.1
*@ Date : 2016-5-12
*************************************************************
*
*     This file was used to clock uart functions.
*     This library is used to tell readers how to build a 
* library of STM8.Everybody can use these source to do 
* anything.AUTHOR WILL NOT BEAR THE BLAME OF ANY DAMAGES
* CREATED BY THIS LIBRARY.
*************************************************************
*/

#ifndef __STM8S_CLOCK_H__
#define __STM8S_CLOCK_H__

#include <stm8s.h>
#include <stm8s_userconfig.h>

/* Registers */
#define CLOCK ((CLOCK_Registers*)0x0050c0)

/* Clock Frequency KHz */
#define HSI_FREQUENCY 16000000
#define LSI_FREQUENCY 128000

typedef enum CLOCKType
{
	HSI = 0xe1,
	LSI = 0xd2,
	HSE = 0xb4,
}CLOCKType;

uint8_t CLOCK_Switch(CLOCKType choice);

#endif