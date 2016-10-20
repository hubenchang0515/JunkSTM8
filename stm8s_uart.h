/*
*************************************************************
*@ File : stm8s_uart.h
*@ Author : www.kurukurumi.com
*@ E-mail : hubenchang0515@outlook.com
*@ version : v1.1.1
*@ Date : 2016-5-12
*************************************************************
*
*     This file was used to define uart functions.
*     This library is used to tell readers how to build a 
* library of STM8.Everybody can use these source to do 
* anything.AUTHOR WILL NOT BEAR THE BLAME OF ANY DAMAGES
* CREATED BY THIS LIBRARY.
*************************************************************
*/

#ifndef __STM8S_UART_H__
#define __STM8S_UART_H__

#include <stm8s.h>

#define UART1 ((UART1_Registers*)0x005230)
#define UART2 ((UART2_Registers*)0x005240)
#define UART3 ((UART3_Registers*)0x005240)

typedef enum UARTLength
{
	UARTLength_8 = 8,
	UARTLength_9 = 9,
}UARTLength;

typedef enum UARTParity
{
	UARTParity_No,
	UARTParity_Odd,
	UARTParity_Even,
}UARTParity;

typedef enum UARTStop
{
	UARTStop_1,
	UARTStop_1p5,
	UARTStop_2,
}UARTStop;

typedef struct UARTMode
{
	uint32_t BaudRate;
	UARTLength Length;
	UARTParity Parity;
	UARTStop Stop;
}UARTMode;

void UART1_SetMode(UARTMode* mode);
void UART1_Transmit(uint16_t value);
uint16_t UART1_Receive(void);

void UART2_SetMode(UARTMode* mode);
void UART2_Transmit(uint16_t value);
uint16_t UART2_Receive(void);

void UART3_SetMode(UARTMode* mode);
void UART3_Transmit(uint16_t value);
uint16_t UART3_Receive(void);

int16_t UART1_printf(const char* str,...);
int16_t UART2_printf(const char* str,...);
int16_t UART3_printf(const char* str,...);

#endif