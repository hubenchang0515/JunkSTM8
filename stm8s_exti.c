/*
*************************************************************
*@ File : stm8s_exti.c
*@ Author : www.kurukurumi.com
*@ E-mail : hubenchang0515@outlook.com
*@ version : v1.1.1
*@ Date : 2016-5-12
*************************************************************
*
*     This file was used to define exti functions.
*     This library is used to tell readers how to build a 
* library of STM8.Everybody can use these source to do 
* anything.AUTHOR WILL NOT BEAR THE BLAME OF ANY DAMAGES
* CREATED BY THIS LIBRARY.
*************************************************************
*/

#include <stm8s_exti.h>

void EXTI_SetTrigger(EXTIn EXTIx,EXTITrigger trigger)
{
	switch(EXTIx)
	{
		case EXTI0 : EXTI->EXTI0 = trigger; break;
		case EXTI1 : EXTI->EXTI1 = trigger; break;
		case EXTI2 : EXTI->EXTI2 = trigger; break;
		case EXTI3 : EXTI->EXTI3 = trigger; break;
		case EXTI4 : EXTI->EXTI4 = trigger; break;
	}
}

