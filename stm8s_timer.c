/*
*************************************************************
*@ File : stm8s_timer.c
*@ Author : www.kurukurumi.com
*@ E-mail : hubenchang0515@outlook.com
*@ version : v1.1.1
*@ Date : 2016-5-12
*************************************************************
*
*     This file was used to define timer functions.
*     This library is used to tell readers how to build a 
* library of STM8.Everybody can use these source to do 
* anything.AUTHOR WILL NOT BEAR THE BLAME OF ANY DAMAGES
* CREATED BY THIS LIBRARY.
*************************************************************
*/

#include <stm8s_timer.h>

extern uint32_t FMASTER;
static uint16_t division = 1;
static uint32_t FCOUNT = 2000000;


/* To count the FCOUNT */
static inline void TIM1_updateFCOUNT(void)
{
	FCOUNT = FMASTER/division;
}


void TIM1_SetDivision(uint16_t div)
{
	division = div;
	TIM1->PSCRH = (division-1)/0xff;
	TIM1->PSCRL = (division-1)%0xff;
}
#include <stm8s_uart.h>
/* To set the time how long will TIM1 interrupt*/
void TIM1_SetTime(uint16_t us)
{
	TIM1_updateFCOUNT();
	uint16_t period = (FCOUNT*us/1000000);
	TIM1->ARRH = period/0xff;
	TIM1->ARRL = period%0xff;
}

/* Enable the TIM1 interrupr and start count */
void TIM1_Start(void)
{
	TIM1->IER |= 1;
	TIM1->CR1 |= 1;
}

/* Clear TIM1 interrupt flag */
void TIM1_Clear(void)
{
	TIM1->SR1 = 0;
}
