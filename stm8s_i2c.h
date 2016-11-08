/*
*************************************************************
*@ File : stm8s_i2c.h
*@ Author : www.kurukurumi.com
*@ E-mail : hubenchang0515@outlook.com
*@ version : v1.1.1
*@ Date : 2016-5-12
*************************************************************
*
*     This file was about i2c functions.
*     This library is used to tell readers how to build a 
* library of STM8.Everybody can use these source to do 
* anything.AUTHOR WILL NOT BEAR THE BLAME OF ANY DAMAGES
* CREATED BY THIS LIBRARY.
*************************************************************
*/



#ifndef __STM8S_I2C_H__
#define __STM8S_I2C_H__

#include <stm8s_gpio.h>

#define I2C_Write 0x00
#define I2C_Read 0x01

typedef struct I2C_Type
{
	GPIO_Registers* 	GPIOx;
	uint8_t 			SCL;
	uint8_t 			SDA;
}I2C_Type;

int I2C_Init(I2C_Type* I2Cx);
void I2C_Start(I2C_Type* I2Cx);
void I2C_Stop(I2C_Type* I2Cx);
void I2C_SendAddress(I2C_Type* I2Cx,uint8_t address,uint8_t WR);
void I2C_SendData(I2C_Type* I2Cx,uint8_t data);
int I2C_CheckACK(I2C_Type* I2Cx);
int I2C_WaitACK(I2C_Type* I2Cx,uint32_t timeout);
uint8_t I2C_ReceiveData(I2C_Type* I2Cx);
void I2C_SendACK(I2C_Type* I2Cx);
void I2C_SendNOTACK(I2C_Type* I2Cx);

#endif