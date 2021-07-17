#ifndef __AD9959_H 
#define __AD9959_H 

#include "stm32f4xx.h"

#define CSR_ADD   0x00   //CSR  Channel Select Register(通道选择寄存器)                1 Bytes
#define FR1_ADD   0x01   //FR1  Function Register 1(功能寄存器1)                       3 Bytes
#define FR2_ADD   0x02   //FR2  Function Register 2(功能寄存器2)                       2 Bytes
#define CFR_ADD   0x03   //CFR  Channel Function Register(通道功能寄存器)              3 Bytes
#define CFTW0_ADD 0x04   //CTW0 Channel Frequency Tuning Word 0(通道频率转换字寄存器)  4 Bytes
#define CPOW0_ADD 0x05   //CPW0 Channel Phase Offset Word 0(通道相位转换字寄存器)      2 Bytes
#define ACR_ADD   0x06   //ACR  Amplitude Control Register(幅度控制寄存器)             3 Bytes
#define LSRR_ADD  0x07   //LSR  Linear Sweep Ramp Rate(通道线性扫描寄存器)             2 Bytes
#define RDW_ADD   0x08   //RDW  LSR Rising Delta Word(通道线性向上扫描寄存器)          4 Bytes
#define FDW_ADD   0x09   //FDW  LSR Falling Delta Word(通道线性向下扫描寄存器)         4 Bytes

//AD9959 Pin macro definition PD0~12
#define SCLK        PGout(6)
#define CS          PGout(4)
#define UPDATE      PGout(2)
#define SDIO0       PGout(7)


#define PS0         PAout(10)
#define PS1         PDout(13)
#define PS2         PGout(3)
#define PS3         PGout(5)

#define SDIO1       PCout(6)
#define SDIO2       PCout(8)
#define SDIO3       PGout(8)
#define AD9959_PWR  PAout(9)
#define RESET       PDout(12)

//Function definition
void Init_AD9959(void);
void delay_9959(uint32_t length);
void InitIO_9959(void);
void InitReset(void);
void IO_Update(void) ;
void WriteData_AD9959(uint8_t RegisterAddress, uint8_t NumberofRegisters, uint8_t *RegisterData,uint8_t temp);
void ReadData_9959(uint8_t RegisterAddress,uint8_t NumberofRegisters,uint8_t *RegisterData);
void Write_frequence(uint8_t Channel,uint32_t Freq);
void Write_Amplitude(uint8_t Channel, uint16_t Ampli);
void Write_Phase(uint8_t Channel,uint16_t Phase);

//IO port operation macro definition
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 

//IO address mapping

//IO address mapping
#define GPIOA_ODR_Addr    (GPIOA_BASE+20)           //0x40020C14
#define GPIOA_IDR_Addr    (GPIOA_BASE+16)           //0x40020C10

//IO address mapping
#define GPIOC_ODR_Addr    (GPIOC_BASE+20)           //0x40020C14
#define GPIOC_IDR_Addr    (GPIOC_BASE+16)           //0x40020C10

#define GPIOD_ODR_Addr    (GPIOD_BASE+20)           //0x40020C14 
#define GPIOD_IDR_Addr    (GPIOD_BASE+16)           //0x40020C10 

//IO address mapping
#define GPIOG_ODR_Addr    (GPIOG_BASE+20)           //0x40020C14
#define GPIOG_IDR_Addr    (GPIOG_BASE+16)           //0x40020C10

//IO port operation, only for a single IO port!
//Ensure that the value of n is less than 16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)       //Output
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)       //Input

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)       //Output
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)       //Input

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)       //Output 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)       //Input 

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)       //Output
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)       //Input

#endif  
