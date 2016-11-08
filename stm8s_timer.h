/*
*************************************************************
*@ File : stm8s_timer.h
*@ Author : www.kurukurumi.com
*@ E-mail : hubenchang0515@outlook.com
*@ version : v1.1.1
*@ Date : 2016-5-12
*************************************************************
*
*     This file defined the enumerates,macros and declared
* functions about TIMER.
*     This library is used to tell readers how to build a 
* library of STM8.Everybody can use these source to do 
* anything.AUTHOR WILL NOT BEAR THE BLAME OF ANY DAMAGES
* CREATED BY THIS LIBRARY.
*************************************************************
*/

#ifndef __STM8S_TIMER_H__
#define __STM8S_TIMER_H__

#include <stm8s.h>

#define TIM1 ((TIM1_Regsters*)0x5250)

void TIM1_SetDivision(uint16_t div);
void TIM1_SetTime(uint16_t ms);
void TIM1_Start(void);
void TIM1_Clear(void);

#endif