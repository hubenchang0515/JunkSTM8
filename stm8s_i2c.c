/*
*************************************************************
*@ File : stm8s_i2c.c
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


#include <stm8s_i2c.h>

static void I2C_delay()
{
	uint8_t i = 10;
	while(i--);
}

/* Keep Evey Function Let SCL to be Low before return. */


int I2C_Init(I2C_Type* I2Cx)
{
	/* Setup the mode of gpio */
	GPIO_SetMode(I2Cx->GPIOx,I2Cx->SCL|I2Cx->SDA, GPIO_Mode_Out_OpenDrain);
	
	/* I2C BUS Initialized */
	GPIO_ResetBits(I2Cx->GPIOx , I2Cx->SCL);
	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SDA);


	/* Reset all */
	I2C_Stop(I2Cx);

	return 1;
}




void I2C_Start(I2C_Type* I2Cx)
{
	/* That SDA is becoming Low from High,when SCL is High,means START. */

	/* Let SDA to Be High */
	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SDA);
	I2C_delay();

	/* Let SCL to be High */
	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SCL);
	I2C_delay();

	/* Let SDA to be Low */
	GPIO_ResetBits(I2Cx->GPIOx , I2Cx->SDA);
	I2C_delay();

	/* Let SCL to be Low */
	GPIO_ResetBits(I2Cx->GPIOx , I2Cx->SCL);
	I2C_delay();

	return;
}





void I2C_Stop(I2C_Type* I2Cx)
{
	/* That SDA is becoming High from Low,when SCL is High,means STOP. */

	/* Let SDA to Be Low */
	GPIO_ResetBits(I2Cx->GPIOx , I2Cx->SDA);
	I2C_delay();

	/* Let SCL to he High */
	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SCL);
	I2C_delay();

	/* Let SDA to be High */
	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SDA);
	I2C_delay();

	/* Let SCL to be Low */
	GPIO_ResetBits(I2Cx->GPIOx , I2Cx->SCL);
	I2C_delay();

	return;
}






void I2C_SendAddress(I2C_Type* I2Cx,uint8_t address,uint8_t WR)
{
	/* High 7 bits of address means the Slave's I2C address. */
	/* Low 1 bit of address means Write(0) or Read(1). */

	uint8_t AddressWithWR = (address<<1) | WR;

	I2C_SendData(I2Cx,AddressWithWR);

	/* To check the Acknowledgement */
	//return I2C_CheckACK(I2Cx);
	return;
}


void I2C_SendData(I2C_Type* I2Cx,uint8_t data)
{

	uint8_t i = 0;

	for(i=0 ; i<8 ; i++)
	{

		if( ( (data<<i) & 0x80) )
			GPIO_SetBits(I2Cx->GPIOx , I2Cx->SDA);
		else
			GPIO_ResetBits(I2Cx->GPIOx , I2Cx->SDA);
		I2C_delay();

		/* Let SCL to he High , SDA send. */
		GPIO_SetBits(I2Cx->GPIOx , I2Cx->SCL);
		I2C_delay();

		/* Let SCL to be Low , SDA could change. */
		GPIO_ResetBits(I2Cx->GPIOx , I2Cx->SCL);
		I2C_delay();
	}

	/* To check the Acknowledgement */
	//return I2C_CheckACK(I2Cx);
	return;
}






int I2C_CheckACK(I2C_Type* I2Cx)
{
	int ACK = 0;

	/* Let SDA to be High */
	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SDA);

	/* Let SCL to he High , SDA send. */
	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SCL);
	I2C_delay();

	/* Read the Acknowledgement */
	ACK = GPIO_ReadBit(I2Cx->GPIOx , I2Cx->SDA);

	/* Let SCL to be Low , SDA could change. */
	GPIO_ResetBits(I2Cx->GPIOx , I2Cx->SCL);
	I2C_delay();

	return ACK;
}






int I2C_WaitACK(I2C_Type* I2Cx,uint32_t timeout)
{
	/* Let SDA to be High */
	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SDA);

	/* Let SCL to he High , SDA send. */
	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SCL);
	I2C_delay();

	/* Read the Acknowledgement */
	while(GPIO_ReadBit(I2Cx->GPIOx , I2Cx->SDA) && timeout--);

	/* Let SCL to be Low , SDA could change. */
	GPIO_ResetBits(I2Cx->GPIOx , I2Cx->SCL);
	I2C_delay();

	return (timeout>0);
}





uint8_t I2C_ReceiveData(I2C_Type* I2Cx)
{
	uint8_t ReceiveData = 0;
	uint8_t i = 8;

	/* Let SDA to be High , To get input */
	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SDA);
	I2C_delay();

	for( i=8 ; i>0 ; i--)
	{
		/* Let SCL to he High , SDA Receive. */
		GPIO_SetBits(I2Cx->GPIOx , I2Cx->SCL);
		I2C_delay();

		ReceiveData <<= 1;
		ReceiveData |= GPIO_ReadBit(I2Cx->GPIOx , I2Cx->SDA);

		/* Let SCL to be Low , SDA could change. */
		GPIO_ResetBits(I2Cx->GPIOx , I2Cx->SCL);
		I2C_delay();
	}

	return ReceiveData;
}







void I2C_SendACK(I2C_Type* I2Cx)
{

	GPIO_ResetBits(I2Cx->GPIOx , I2Cx->SDA);
	I2C_delay();

	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SCL);
	I2C_delay();

	GPIO_ResetBits(I2Cx->GPIOx , I2Cx->SCL);
	I2C_delay();

	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SDA);
	I2C_delay();
}






void I2C_SendNOTACK(I2C_Type* I2Cx)
{

	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SDA);
	I2C_delay();

	GPIO_SetBits(I2Cx->GPIOx , I2Cx->SCL);
	I2C_delay();

	GPIO_ResetBits(I2Cx->GPIOx , I2Cx->SCL);
	I2C_delay();
}




int I2C_CheckBusy(I2C_Type* I2Cx)
{
	return !GPIO_ReadBit(I2Cx->GPIOx , I2Cx->SDA);
}
