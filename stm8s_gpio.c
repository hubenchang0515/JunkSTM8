/*
*************************************************************
*@ File : stm8s_gpio.c
*@ Author : www.kurukurumi.com
*@ E-mail : hubenchang0515@outlook.com
*@ version : v1.1.1
*@ Date : 2016-5-12
*************************************************************
*
*     This file defined the functions about GPIO.
*     This library is used to tell readers how to build a 
* library of STM8.Everybody can use these source to do 
* anything.AUTHOR WILL NOT BEAR THE BLAME OF ANY DAMAGES
* CREATED BY THIS LIBRARY.
*************************************************************
*/

#include <stm8s_gpio.h>

void GPIO_SetMode(GPIO_Registers* Px,uint8_t Pins,GPIOMode Mode)
{
    if((Mode & 0x01) == 0x01)
    {
        Px->CR2 |= Pins;
    }
    else
    {
        Px->CR2 &= ~Pins;
    }
    
    if((Mode & 0x02) == 0x02)
    {
        Px->CR1 |= Pins;
    }
    else
    {
        Px->CR1 &= ~Pins;
    }
    
    if((Mode & 0x04) == 0x04)
    {
        Px->DDR |= Pins;
    }
    else
    {
        Px->DDR &= ~Pins;
    }
}
/* Other functions are inline.*/
/* They are defined in stm8s_gpio.h */
