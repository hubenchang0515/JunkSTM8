/*
*************************************************************
*@ File : stm8s_uart.c
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

#include <stm8s_uart.h>

/* At the electrify default time */
/* HSI(16MHz) Scale 8 */
/* f(master) = 2MHz */
extern uint32_t FMASTER;

/* UART1 */
void UART1_SetMode(UARTMode* mode)
{
	UART1_Registers* UART = (UART1_Registers*)UART1;

	/* Set BaudRate */
	uint16_t BaudRate_DIV = (uint16_t)((double)FMASTER/mode->BaudRate+0.5);
	UART->BRR2 = (uint8_t)(BaudRate_DIV & 0x0f)|(uint8_t)((BaudRate_DIV >> 8) & 0xf0);
	UART->BRR1 = (uint8_t)((BaudRate_DIV & 0x0ff0) >> 4);
	
		/* Set Length */
	if(mode->Length == UARTLength_8)
		UART->CR1 &= ~(1<<4);
	else if(mode->Length == UARTLength_9)
		UART->CR1 |= 1<<4;

	/* Set Parity */
	if(mode->Parity == UARTParity_No)
		UART->CR1 &= ~(1<<2);
	else if(mode->Parity == UARTParity_Odd)
	{
		UART->CR1 |= 1<<2;
		UART->CR1 |= 1<<1;
	}
	else if(mode->Parity == UARTParity_Even)
	{
		UART->CR1 |= 1<<2;
		UART->CR1 &= ~(1<<1);
	}

	/* Set Stop */
	if(mode->Stop == UARTStop_1)
		UART->CR3 &= ~(3<<4);
	else if(mode->Stop == UARTStop_1p5)
		UART->CR3 |= 3<<4;
	else if(mode->Stop == UARTStop_2)
	{
		UART->CR3 |= 1<<5;
		UART->CR3 &= ~(1<<4);
	}
	
	UART->CR2 = 0x2c;//Enable
}

void UART1_Transmit(uint16_t value)
{
	UART1_Registers* UART = (UART1_Registers*)UART1;
	while(UART->TXE == 0);

	UART->DR = (uint8_t) value;
	if(value & 0x40 == 0)
		UART->CR1 &= ~(1<<6);
	else
		UART->CR1 |= 1<<6;
}


uint16_t UART1_Receive(void)
{
	UART1_Registers* UART = (UART1_Registers*)UART1;
	uint16_t rValue = 0;
	rValue = UART->DR;
	if(UART->CR1 & 0x10 != 0)
	{
		rValue |= (uint16_t)(UART->CR1 & 0x80)<<1;
	}
	return rValue;
}


/* UART2 */
void UART2_SetMode(UARTMode* mode)
{
	UART2_Registers* UART = (UART2_Registers*)UART2;

	/* Set BaudRate */
	uint16_t BaudRate_DIV = (uint16_t)((double)FMASTER/mode->BaudRate+0.5);
	UART->BRR2 = (uint8_t)(BaudRate_DIV & 0x0f)|(uint8_t)((BaudRate_DIV >> 8) & 0xf0);
	UART->BRR1 = (uint8_t)((BaudRate_DIV & 0x0ff0) >> 4);
	
		/* Set Length */
	if(mode->Length == UARTLength_8)
		UART->CR1 &= ~(1<<4);
	else if(mode->Length == UARTLength_9)
		UART->CR1 |= 1<<4;

	/* Set Parity */
	if(mode->Parity == UARTParity_No)
		UART->CR1 &= ~(1<<2);
	else if(mode->Parity == UARTParity_Odd)
	{
		UART->CR1 |= 1<<2;
		UART->CR1 |= 1<<1;
	}
	else if(mode->Parity == UARTParity_Even)
	{
		UART->CR1 |= 1<<2;
		UART->CR1 &= ~(1<<1);
	}

	/* Set Stop */
	if(mode->Stop == UARTStop_1)
		UART->CR3 &= ~(3<<4);
	else if(mode->Stop == UARTStop_1p5)
		UART->CR3 |= 3<<4;
	else if(mode->Stop == UARTStop_2)
	{
		UART->CR3 |= 1<<5;
		UART->CR3 &= ~(1<<4);
	}
	
	UART->CR2 = 0x2c;//Enable
}

void UART2_Transmit(uint16_t value)
{
	UART2_Registers* UART = (UART2_Registers*)UART2;
	while(UART->TXE == 0);

	UART->DR = (uint8_t) value;
	if(value & 0x40 == 0)
		UART->CR1 &= ~(1<<6);
	else
		UART->CR1 |= 1<<6;
}


uint16_t UART2_Receive(void)
{
	UART2_Registers* UART = (UART2_Registers*)UART2;
	uint16_t rValue = 0;
	rValue = UART->DR;
	if(UART->CR1 & 0x10 != 0)
	{
		rValue |= (uint16_t)(UART->CR1 & 0x80)<<1;
	}
	return rValue;
}



/* UART3 */
void UART3_SetMode(UARTMode* mode)
{
	UART3_Registers* UART = (UART3_Registers*)UART3;

	/* Set BaudRate */
	uint16_t BaudRate_DIV = (uint16_t)((double)FMASTER/mode->BaudRate+0.5);
	UART->BRR2 = (uint8_t)(BaudRate_DIV & 0x0f)|(uint8_t)((BaudRate_DIV >> 8) & 0xf0);
	UART->BRR1 = (uint8_t)((BaudRate_DIV & 0x0ff0) >> 4);
	
		/* Set Length */
	if(mode->Length == UARTLength_8)
		UART->CR1 &= ~(1<<4);
	else if(mode->Length == UARTLength_9)
		UART->CR1 |= 1<<4;

	/* Set Parity */
	if(mode->Parity == UARTParity_No)
		UART->CR1 &= ~(1<<2);
	else if(mode->Parity == UARTParity_Odd)
	{
		UART->CR1 |= 1<<2;
		UART->CR1 |= 1<<1;
	}
	else if(mode->Parity == UARTParity_Even)
	{
		UART->CR1 |= 1<<2;
		UART->CR1 &= ~(1<<1);
	}

	/* Set Stop */
	if(mode->Stop == UARTStop_1)
		UART->CR3 &= ~(3<<4);
	else if(mode->Stop == UARTStop_1p5)
		UART->CR3 |= 3<<4;
	else if(mode->Stop == UARTStop_2)
	{
		UART->CR3 |= 1<<5;
		UART->CR3 &= ~(1<<4);
	}
	
	UART->CR2 = 0x2c;//Enable
}

void UART3_Transmit(uint16_t value)
{
	UART3_Registers* UART = (UART3_Registers*)UART3;
	while(UART->TXE == 0);

	UART->DR = (uint8_t) value;
	if(value & 0x40 == 0)
		UART->CR1 &= ~(1<<6);
	else
		UART->CR1 |= 1<<6;
}


uint16_t UART3_Receive(void)
{
	UART3_Registers* UART = (UART3_Registers*)UART3;
	uint16_t rValue = 0;
	rValue = UART->DR;
	if(UART->CR1 & 0x10 != 0)
	{
		rValue |= (uint16_t)(UART->CR1 & 0x80)<<1;
	}
	return rValue;
}



#include <stdio.h>
#include <stdarg.h>

int16_t UART1_printf(const char* str,...)
{
	char fmtstr[UART_PRINTF_BUFFER_SIZE];
	uint8_t index = 0;
	int16_t TrueLen = 0;
	va_list argList;
	va_start(argList,str);
	TrueLen = vsnprintf(fmtstr,UART_PRINTF_BUFFER_SIZE-1,str,argList);
	va_end(argList);
	if(TrueLen<0)
		return TrueLen;
	fmtstr[TrueLen] = 0;
	for(index=0 ; fmtstr[index]!=0 ; index+=1)
	{
		UART1_Transmit(fmtstr[index]);
	}

	return TrueLen;
}


int16_t UART2_printf(const char* str,...)
{
	char fmtstr[UART_PRINTF_BUFFER_SIZE];
	uint8_t index = 0;
	int16_t TrueLen = 0;
	va_list argList;
	va_start(argList,str);
	TrueLen = vsnprintf(fmtstr,UART_PRINTF_BUFFER_SIZE-1,str,argList);
	va_end(argList);
	if(TrueLen<0)
		return TrueLen;

	fmtstr[TrueLen] = 0;
	for(index=0 ; fmtstr[index]!=0 ; index+=1)
	{
		UART2_Transmit(fmtstr[index]);
	}

	return TrueLen;
}


int16_t UART3_printf(const char* str,...)
{
	char fmtstr[UART_PRINTF_BUFFER_SIZE];
	uint8_t index = 0;
	int16_t TrueLen = 0;
	va_list argList;
	va_start(argList,str);
	TrueLen = vsnprintf(fmtstr,UART_PRINTF_BUFFER_SIZE-1,str,argList);
	va_end(argList);
	if(TrueLen<0)
		return TrueLen;

	fmtstr[TrueLen] = 0;
	for(index=0 ; fmtstr[index]!=0 ; index+=1)
	{
		UART3_Transmit(fmtstr[index]);
	}

	return TrueLen;
}

