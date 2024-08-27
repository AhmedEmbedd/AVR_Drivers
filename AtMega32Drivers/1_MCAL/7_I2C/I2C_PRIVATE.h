/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 15/4/2024            *********************/
/****  SWC    : TWI Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


#define TWI_u8_TWDR_Reg       *((volatile u8 *)0x23)
#define TWI_u8_TWAR_Reg       *((volatile u8 *)0x22)
#define TWI_u8_TWSR_Reg       *((volatile u8 *)0x21)
#define TWI_u8_TWBR_Reg       *((volatile u8 *)0x20)
#define TWI_u8_TWCR_Reg       *((volatile u8 *)0x56)


#define TWCR_TWINT		7	/*interrupt flag*/
#define TWCR_TWEA		6	/*Acknowledge Bit*/
#define TWCR_TWSTA		5	/*START Condition Bit*/
#define TWCR_TWSTO		4	/*STOP Condition Bit*/
#define TWCR_TWWC		3	/*Write Collision Flag*/
#define TWCR_TWEN		2	/*TWI Enable Bit*/
#define TWCR_TWIE		0	/*TWI Interrupt Enable*/


#endif