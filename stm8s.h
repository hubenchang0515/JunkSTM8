/*
*************************************************************
*@ File : stm8s.h
*@ Author : www.kurukurumi.com
*@ E-mail : hubenchang0515@outlook.com
*@ version : v1.1.1
*@ Date : 2016-5-12
*************************************************************
*
*     This file has defined all structures about registers, 
* every files of this library has included this file.
*
*     This library is used to tell readers how to build a 
* library of STM8.Everybody can use these source to do 
* anything.AUTHOR WILL NOT BEAR THE BLAME OF ANY DAMAGES
* CREATED BY THIS LIBRARY.
*************************************************************
*/

#ifndef __STM8S_H__
#define __STM8S_H__

#include <stdint.h>
#include <stm8s_userconfig.h>

/* Set and Reset bits of byte */
#define Bit0 0x01
#define Bit1 0x02
#define Bit2 0x04
#define Bit3 0x08
#define Bit4 0x10
#define Bit5 0x20
#define Bit6 0x40
#define Bit7 0x80
#define BitAll 0xff

static inline void Byte_SetBits(uint8_t* m,uint8_t bits)
{
    *m |= bits;
}

static inline void Byte_ResetBits(uint8_t* m,uint8_t bits)
{
    *m &= ~bits;
}

/* The registers of gpio*/
typedef struct GPIO_Registers
{
    union
    {
        uint8_t ODR;//Output Data Register
        struct
        {
            uint8_t ODR0 : 1; 
            uint8_t ODR1 : 1;
            uint8_t ODR2 : 1;
            uint8_t ODR3 : 1;
            uint8_t ODR4 : 1;
            uint8_t ODR5 : 1;
            uint8_t ODR6 : 1;
            uint8_t ODR7 : 1;
        };
    };
    union
    {
        uint8_t IDR;//Input Data Register
        struct
        {
            uint8_t IDR0 : 1; 
            uint8_t IDR1 : 1;
            uint8_t IDR2 : 1;
            uint8_t IDR3 : 1;
            uint8_t IDR4 : 1;
            uint8_t IDR5 : 1;
            uint8_t IDR6 : 1;
            uint8_t IDR7 : 1;
        };
    };
    union
    {
        uint8_t DDR;//Data Directuon Regisetr
        struct
        {
            uint8_t DDR0 : 1; 
            uint8_t DDR1 : 1;
            uint8_t DDR2 : 1;
            uint8_t DDR3 : 1;
            uint8_t DDR4 : 1;
            uint8_t DDR5 : 1;
            uint8_t DDR6 : 1;
            uint8_t DDR7 : 1;
        };
    };
    union
    {
        uint8_t CR1;//Control Register 1
        struct
        {
            uint8_t CR10 : 1; 
            uint8_t CR11 : 1;
            uint8_t CR12 : 1;
            uint8_t CR13 : 1;
            uint8_t CR14 : 1;
            uint8_t CR15 : 1;
            uint8_t CR16 : 1;
            uint8_t CR17 : 1;
        };
    };
    union
    {
        uint8_t CR2;//Control Register 2
        struct
        {
            uint8_t CR20 : 1; 
            uint8_t CR21 : 1;
            uint8_t CR22 : 1;
            uint8_t CR23 : 1;
            uint8_t CR24 : 1;
            uint8_t CR25 : 1;
            uint8_t CR26 : 1;
            uint8_t CR27 : 1;
        };
    };
}GPIO_Registers;

/* The register of interrupt priority */
typedef struct ITC_Registers
{
    union
    {
        uint8_t SPR1;
        struct
        {
            uint8_t TLI : 2;
            uint8_t AWU : 2;
            uint8_t CLK : 2;
            uint8_t EXTI0 : 2;
        };
    };
    union
    {
        uint8_t SPR2;
        struct
        {
            uint8_t EXIT1 : 2;
            uint8_t EXTI2 : 2;
            uint8_t EXIT3 : 2;
            uint8_t EXIT4 : 2;
        };
    };
    union
    {
        uint8_t SPR3;
        struct
        {
            uint8_t CAN_RX : 2;//Receive
            uint8_t CAN_TX : 2;//Transmit
            uint8_t SPI : 2;
            uint8_t TIM1_UOUTB : 2;//Update Overflow Underflow Trigger Break
        };
    };
    union
    {
        uint8_t SPR4;
        struct
        {
            uint8_t TIM1_CC : 2;//Capture Compare
            uint8_t TIM2_UO : 2;//Update Overflow
            uint8_t TIM2_CC : 2;//Capture Compare
            uint8_t TIM3_UO : 2;//Update Overflow
        };
    };
    union
    {
        uint8_t SPR5;
        struct
        {
            uint8_t TIM3_CC : 2;//Capture Compare
            uint8_t UART1_TX : 2;//Transmit
            uint8_t UART1_RX : 2;//Receive
            uint8_t I2C : 2;
        };
    };
    union
    {
        uint8_t SPR6;
        struct
        {
            uint8_t UART23_TX : 2;//Transmit
            uint8_t UART23_RX : 2;//Receive
            uint8_t ADC : 2;
            uint8_t TIM4_UO : 2;//Update Overflow
        };
    };
    union
    {
        uint8_t SPR7;
        struct
        {
            uint8_t FLASH : 2;
            uint8_t INT25 : 2;//unused
            uint8_t INT26 : 2;//unused
            uint8_t INT27 : 2;//unused
        };
    };
    union
    {
        uint8_t SPR8;
        struct
        {
            uint8_t INT28 : 2;//unused
            uint8_t INT29 : 2;//unused
            uint8_t RESERVED : 4;//reserved
            
        };
    };
    
}ITC_Registers;

/* The registers of exit */
typedef struct EXTI_Registers
{
    union
    {
        uint8_t CR1;//Control Register 1
        struct
        {
            uint8_t EXTI0 : 2;
            uint8_t EXTI1 : 2;
            uint8_t EXTI2 : 2;
            uint8_t EXTI3 : 2;
        };
    };

    union
    {
        uint8_t CR2;//Control Register 2
        struct
        {
            uint8_t EXTI4 : 2;
            uint8_t TLI : 1;
            uint8_t RESERVED : 5;//reserved
        };
    };

}EXTI_Registers;

/* The registers of uart1 */
typedef struct UART1_Registers
{
    union
    {
        uint8_t SR; //State Register
        struct
        {
            uint8_t PE : 1;     //Parity Check Error
            uint8_t FE : 1;     //Flame Error
            uint8_t NF : 1;     //Noise Flag
            uint8_t OR : 1;     //Overload Error
            uint8_t IDLE : 1;   //Idle
            uint8_t RXNE : 1;   //Reseive Register Not Empty
            uint8_t TC : 1;     //Transmit Complete
            uint8_t TXE : 1;    //Transmit Register Empty
        };
    };

    uint8_t DR;//Data Register
    uint8_t BRR1;//Baudrate
    uint8_t BRR2;
    uint8_t CR1;//Control Register 1
    uint8_t CR2;//Control Register 2
    uint8_t CR3;//Control Register 3
    uint8_t CR4;//Control Register 4
    uint8_t CR5;//Control Register 5
    uint8_t GTR;//Guard Time Register
    uint8_t PSCR;//Prescale Register

}UART1_Registers;

/* The registers of uart2 */
typedef struct UART2_Registers
{
    union
    {
        uint8_t SR; //State Register
        struct
        {
            uint8_t PE : 1;     //Parity Check Error
            uint8_t FE : 1;     //Flame Error
            uint8_t NF : 1;     //Noise Flag
            uint8_t OR : 1;     //Overload Error
            uint8_t IDLE : 1;   //Idle
            uint8_t RXNE : 1;   //Reseive Register Not Empty
            uint8_t TC : 1;     //Transmit Complete
            uint8_t TXE : 1;    //Transmit Register Empty
        };
    };

    uint8_t DR;//Data Register
    uint8_t BRR1;//Baudrate Register
    uint8_t BRR2;
    uint8_t CR1;//Control Register 1
    uint8_t CR2;//Control Register 2
    uint8_t CR3;//Control Register 3
    uint8_t CR4;//Control Register 4
    uint8_t RESERVED;
    uint8_t CR6;//Control Register 5
    uint8_t GTR;//Guard Time Register
    uint8_t PSCR;//Prescale Register

}UART2_Registers;

/* The registers of uart3 */
typedef struct UART3_Registers
{
    union
    {
        uint8_t SR; //State Register
        struct
        {
            uint8_t PE : 1;     //Parity Check Error
            uint8_t FE : 1;     //Flame Error
            uint8_t NF : 1;     //Noise Flag
            uint8_t OR : 1;     //Overload Error
            uint8_t IDLE : 1;   //Idle
            uint8_t RXNE : 1;   //Reseive Register Not Empty
            uint8_t TC : 1;     //Transmit Complete
            uint8_t TXE : 1;    //Transmit Register Empty
        };
    };

    uint8_t DR;//Data Register
    uint8_t BRR1;//Baudrate
    uint8_t BRR2;
    uint8_t CR1;//Control Register 1
    uint8_t CR2;//Control Register 2
    uint8_t CR3;//Control Register 3
    uint8_t CR4;//Control Register 4

}UART3_Registers;

/* The registers of flash */
typedef struct FLASH_Registers
{
    uint8_t CR1;
    uint8_t CR2;
    uint8_t NCR2;
    uint8_t FPR;
    uint8_t NFPR;
    uint8_t IAPSR;
    uint8_t RESERVED1[2];
    uint8_t PUKR;
    uint8_t RESERVED2;
    uint8_t DUKR;
}FLASH_Registers;

/* The registers of clock */
typedef struct CLOCK_Registers
{
    uint8_t ICKR;
    uint8_t ECKR;
    uint8_t RESERVED;
    uint8_t CMSR;
    uint8_t SWR;
    uint8_t SWCR;
    uint8_t CKDIVR;
    uint8_t PCKENR1;
    uint8_t CSSR;
    uint8_t CCOR;
    uint8_t PCKENR2;
    uint8_t CANCCR;
    uint8_t HSITRIMR;
    uint8_t SWIMCCR;
}CLOCK_Registers;


/* The registers of TIM1*/
typedef struct TIM1_Regsters
{
	uint8_t CR1;
	uint8_t CR2;
	uint8_t SMCR;
	uint8_t ETR;
	uint8_t IER;
	uint8_t SR1;
	uint8_t SR2;
	uint8_t EGR;
	uint8_t CCMR1;
	uint8_t CCMR2;
	uint8_t CCMR3;
	uint8_t CCMR4;
	uint8_t CCER1;
	uint8_t CCER2;
	uint8_t CNTRH;
	uint8_t CNTRL;
	uint8_t PSCRH;
	uint8_t PSCRL;
	uint8_t ARRH;
	uint8_t ARRL;
	uint8_t RCR;
	uint8_t CCR1H;
	uint8_t CCR1L;
	uint8_t CCR2H;
	uint8_t CCR2L;
	uint8_t CCR3H;
	uint8_t CCR3L;
	uint8_t CCR4H;
	uint8_t CCR4L;
	uint8_t BKR;
	uint8_t DTR;
	uint8_t IOSR;
}TIM1_Regsters;

#endif