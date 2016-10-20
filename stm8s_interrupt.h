/*
*************************************************************
*@ File : stm8s_interrupt.h
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

#ifndef __STM8S_INTERRUPT_H__
#define __STM8S_INTERRUPT_H__

#include <stm8s.h>

#define ITC ((ITC_Registers*)0x007f70)

/* The number of interrupt */
typedef enum InterruptNumber
{
	INTERRUPT_TRAR = -2,
	INTERRUPT_TLI = 0,
	INTERRUPT_AWU,
	INTERRUPT_CLK,
	INTERRUPT_EXTI0,
	INTERRUPT_EXTI1,
	INTERRUPT_EXTI2,
	INTERRUPT_EXTI3,
	INTERRUPT_EXTI4,
	INTERRUPT_CAN_RX,
	INTERRUPT_CAN_TX,
	INTERRUPT_SPI,
	INTERRUPT_TIM1_UOUTB,
	INTERRUPT_TIM1_CC,
	INTERRUPT_TIM2_UO,
	INTERRUPT_TIM2_CC,
	INTERRUPT_TIM3_UO,
	INTERRUPT_TIM3_CC,
	INTERRUPT_UART1_TX,
	INTERRUPT_UART1_RX,
	INTERRUPT_I2C,
	INTERRUPT_UART23_TX,
	INTERRUPT_UART23_RX,
	INTERRUPT_ADC,
	INTERRUPT_TIM4_UO,
	INTERRUPT_FLASH,
}InterruptNumber;

/* The priority of interrupt */
typedef enum InterruptPriority
{
	PRIORITY_0 = 2,
	PRIORITY_1 = 1,
	PRIORITY_2 = 0,
	PRIORITY_3 = 3,
}InterruptPriority;

/* Functions Declaration */
void Interrupt_SetPriority(InterruptNumber inum,InterruptPriority priority);
static inline void Interrupt_ON(void);
static inline void Interrupt_OFF(void);


/* static inline functions */
static inline void Interrupt_ON(void)
{
	asm("rim");
}

static inline void Interrupt_OFF(void)
{
	asm("sim");
}

/* use Interrupr_Handler to define intrrupr functions */
#define TOSTRING(x) #x
#define Interrupt_Handler(fname,inumber) \
	_Pragma(TOSTRING(vector=inumber+2)) \
	__interrupt void fname(void)
#endif