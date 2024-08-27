/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 20/3/2024            *********************/
/****  SWC    : SPI Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SPI_u8_SPCR_Reg       *((volatile u8 *)0x2D)
#define SPI_u8_SPSR_Reg       *((volatile u8 *)0x2E)
#define SPI_u8_SPDR_Reg       *((volatile u8 *)0x2F)


                                 //SPI2X SPR1 SPR0 SCK Frequency
#define DividedBy_2      0b00    //  1    0     0    fosc/2
#define DividedBy_8      0b01    //  1    0     1    fosc/8  
#define DividedBy_32     0b10    //  1    1     0    fosc/32 
#define DividedBy_4      0b00    //  0    0     0    fosc/4
#define DividedBy_16     0b01    //  0    0     1    fosc/16      
#define DividedBy_64     0b10    //  0    1     0    fosc/64  
#define DividedBy_128    0b11    //  0    1     1    fosc/128 
  
#define NormalSpeed      0                               
#define DoubleSpeed      1

#define Setup     1 
#define Sample    0 

#define Falling  1 
#define Rising   0

#define LSB  1
#define MSB  0

#define Master   1          
#define Slave    0 

#endif