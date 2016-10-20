/*
*************************************************************
*@ File : stm8s_interrupt.c
*@ Author : www.kurukurumi.com
*@ E-mail : hubenchang0515@outlook.com
*@ version : v1.1.1
*@ Date : 2016-5-12
*************************************************************
*
*     This file was used to define interrupt functions and
* set priority of interrupt.
*     This library is used to tell readers how to build a 
* library of STM8.Everybody can use these source to do 
* anything.AUTHOR WILL NOT BEAR THE BLAME OF ANY DAMAGES
* CREATED BY THIS LIBRARY.
*************************************************************
*/

#include <stm8s_interrupt.h>

/*Set the priority of interrupt */
void Interrupt_SetPriority(InterruptNumber inum,InterruptPriority priority)
{
	uint8_t ITC_SPRx = inum/4;
	uint8_t ITC_SPRbit = inum%4*2;
	switch(ITC_SPRx)
	{
		case 0: ITC->SPR1 |= priority<<ITC_SPRbit;        //将priority为1的位置1
				ITC->SPR1 &= ~(3-priority<<ITC_SPRbit);   //将priority为0的位置0
				break;
		case 1: ITC->SPR2 |= priority<<ITC_SPRbit;             
				ITC->SPR2 &= ~(3-priority<<ITC_SPRbit);     
				break;
		case 2: ITC->SPR3 |= priority<<ITC_SPRbit;             
				ITC->SPR3 &= ~(3-priority<<ITC_SPRbit);     
				break;
		case 3: ITC->SPR4 |= priority<<ITC_SPRbit;             
				ITC->SPR4 &= ~(3-priority<<ITC_SPRbit);     
				break;
		case 4: ITC->SPR5 |= priority<<ITC_SPRbit;             
				ITC->SPR5 &= ~(3-priority<<ITC_SPRbit);     
				break;
		case 5: ITC->SPR6 |= priority<<ITC_SPRbit;             
				ITC->SPR6 &= ~(3-priority<<ITC_SPRbit);     
				break;
		case 6: ITC->SPR7 |= priority<<ITC_SPRbit;             
				ITC->SPR7 &= ~(3-priority<<ITC_SPRbit);     
				break;
		case 7: ITC->SPR8 |= priority<<ITC_SPRbit;             
				ITC->SPR8 &= ~(3-priority<<ITC_SPRbit);     
				break;
	}
}