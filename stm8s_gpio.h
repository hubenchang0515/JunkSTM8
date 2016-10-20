/*
*************************************************************
*@ File : stm8s_gpio.h
*@ Author : www.kurukurumi.com
*@ E-mail : hubenchang0515@outlook.com
*@ version : v1.1.1
*@ Date : 2016-5-12
*************************************************************
*
*     This file defined the enumerates,macros and declared
* functions about GPIO.
*     This library is used to tell readers how to build a 
* library of STM8.Everybody can use these source to do 
* anything.AUTHOR WILL NOT BEAR THE BLAME OF ANY DAMAGES
* CREATED BY THIS LIBRARY.
*************************************************************
*/

#ifndef __STM8S_GPIO_H__
#define __STM8S_GPIO_H__

#include <stm8s.h>

#define PA ((GPIO_Registers*) 0x5000)
#define PB ((GPIO_Registers*) 0x5005)
#define PC ((GPIO_Registers*) 0x500A)
#define PD ((GPIO_Registers*) 0x500F)
#define PE ((GPIO_Registers*) 0x5014)
#define PF ((GPIO_Registers*) 0x5019)
#define PG ((GPIO_Registers*) 0x501E)
#define PH ((GPIO_Registers*) 0x5023)
#define PI ((GPIO_Registers*) 0x5028)

/* The modes of GPIO */
typedef enum GPIOMode
{
    //give low 3 bits to DDR(bit2) CR1(bit1) CR2(bit0)
    GPIO_Mode_In_Floating       = 0x00,  
    GPIO_Mode_In_PullUp         = 0x02,
    GPIO_Mode_In_Floating_Int   = 0x01,
    GPIO_Mode_In_PullUp_Int     = 0x03,
    GPIO_Mode_Out_OpenDrain     = 0x04,
    GPIO_Mode_Out_PushPull      = 0x06,
}GPIOMode;

/* Pins of GPIO */
#define Pin0 0x01
#define Pin1 0x02
#define Pin2 0x04
#define Pin3 0x08
#define Pin4 0x10
#define Pin5 0x20
#define Pin6 0x40
#define Pin7 0x80
#define PinAll 0xff


/* Functions Declaration */
void GPIO_SetMode(GPIO_Registers* Px,uint8_t Pins,GPIOMode Mode);
static inline void GPIO_Write(GPIO_Registers* Px,uint8_t Value);
static inline void GPIO_WriteBits(GPIO_Registers* Px,uint8_t Pins,uint8_t Value);
static inline void GPIO_SetBits(GPIO_Registers* Px,uint8_t Pins);
static inline void GPIO_ResetBits(GPIO_Registers* Px,uint8_t Pins);
static inline uint8_t GPIO_Read(GPIO_Registers* Px);
static inline uint8_t GPIO_ReadBit(GPIO_Registers* Px,uint8_t Pin);


/*static inline functions*/
/* Write the 8bits gpio */
static inline void GPIO_Write(GPIO_Registers* Px,uint8_t Value)
{
	Px->ODR = Value;
}

/* Write the bits you want to write */
/* Can use or(|) to conflate more than one pin */
static inline void GPIO_WriteBits(GPIO_Registers* Px,uint8_t Pins,uint8_t Value)
{
    if(Value == 0)
    {
        Px->ODR &= ~Pins;
    }
    else
    {
        Px->ODR |= Pins;
    }
}

/* Set the pins high */
/* Can use or(|) to conflate more than one pin */
static inline void GPIO_SetBits(GPIO_Registers* Px,uint8_t Pins)
{
	Px->ODR |= Pins;
}

/* Set the pins low */
/* Can use or(|) to conflate more than one pin */
static inline void GPIO_ResetBits(GPIO_Registers* Px,uint8_t Pins)
{
	Px->ODR &= ~Pins;
}

/* Read the 8bits gpio */
static inline uint8_t GPIO_Read(GPIO_Registers* Px)
{
	return Px->IDR;
}

/* Read only one pin of gpio */
static inline uint8_t GPIO_ReadBit(GPIO_Registers* Px,uint8_t Pin)
{
	return (Px->IDR & Pin) != 0;
}


#endif