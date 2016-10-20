/*
*************************************************************
*@ File : stm8s_clock.c
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

#include <stm8s_clock.h>
/*  KHz  */
extern uint32_t FMASTER = HSI_FREQUENCY / 8;

uint8_t CLOCK_Switch(CLOCKType choice)
{
	uint16_t counter = 1000;
	CLOCK->SWCR |= 1<<1;
	CLOCK->SWR = choice;
	while((CLOCK->CMSR != choice) && --counter );
	if(!counter)
		return 0;

	switch(CLOCK->CMSR)
	{
		case HSI: FMASTER = HSI_FREQUENCY/(1<<(CLOCK->CKDIVR>>3));break;
		case LSI: FMASTER = LSI_FREQUENCY;break;
		case HSE: FMASTER = HSE_FREQUENCY;break;
	}
	return 1;
}