/*
*************************************************************
*@ File : stm8s_exti.h
*@ Author : www.kurukurumi.com
*@ E-mail : hubenchang0515@outlook.com
*@ version : v1.1.1
*@ Date : 2016-5-12
*************************************************************
*
*     This file was used to define exti functions..
*     This library is used to tell readers how to build a 
* library of STM8.Everybody can use these source to do 
* anything.AUTHOR WILL NOT BEAR THE BLAME OF ANY DAMAGES
* CREATED BY THIS LIBRARY.
*************************************************************
*/

#ifndef __STM8S_EXTI_H__
#define __STM8S_EXTI_H__

#include <stm8s.h>
/*
EXTI0 Port A 5Pins PA[6:2]
EXTI0 Port B 8Pins PB[7:0]
EXTI0 Port C 8Pins PC[7:0]
EXTI0 Port D 7Pins PD[6:0]
EXTI0 Port E 8Pins PE[7:0]
*/

#define EXTI ((EXTI_Registers*)0x0050a0)

typedef enum EXTITrigger
{
	FallingEdgeLow = 0,
	RisingEdge,
	FallingEdge,
	DoubleEdge
}EXTITrigger;

typedef enum TLITrigger
{
	TLIRisingEdge = 0,
	TLIFallingEdge,
}TLITrigger;

typedef enum EXTIn
{
	EXTI0 = 0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
}EXTIn;

/* Functions Declaration */
void EXTI_SetTrigger(EXTIn EXTIx,EXTITrigger trigger);
static inline void TLI_SetTrigger(TLITrigger trigger);

/*static inline functions*/
static inline void TLI_SetTrigger(TLITrigger trigger)
{
	EXTI->TLI = trigger;
}

#endif