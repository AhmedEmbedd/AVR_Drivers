/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 2/2/2024             *********************/
/****  SWC    : DIO Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H




#define DIO_u8_PORTA_Reg   *((volatile u8 *)0x3B)
#define DIO_u8_DDRA_Reg    *((volatile u8 *)0x3A)
#define DIO_u8_PINA_Reg    *((volatile u8 *)0x39)

#define DIO_u8_PORTB_Reg   *((volatile u8 *)0x38)
#define DIO_u8_DDRB_Reg    *((volatile u8 *)0x37)
#define DIO_u8_PINB_Reg    *((volatile u8 *)0x36)

#define DIO_u8_PORTC_Reg   *((volatile u8 *)0x35)
#define DIO_u8_DDRC_Reg    *((volatile u8 *)0x34)
#define DIO_u8_PINC_Reg    *((volatile u8 *)0x33)

#define DIO_u8_PORTD_Reg   *((volatile u8 *)0x32)
#define DIO_u8_DDRD_Reg    *((volatile u8 *)0x31)
#define DIO_u8_PIND_Reg    *((volatile u8 *)0x30)
/*************** Initial Setup For Pins ********************/
#define DIO_PIN_INITIAL_INPUT            0
#define DIO_PIN_INITIAL_OUTPUT           1
#define DIO_PIN_INITIAL_HIGH             1
#define DIO_PIN_INITIAL_LOW              0
#define DIO_PIN_INITIAL_INPUT_FLOAT      0
#define DIO_PIN_INITIAL_INPUT_PULLUP     1

#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)           Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)      0b##b7##b6##b5##b4##b3##b2##b1##b0

#define NULL   0X0

#define  STD_TYPES_OK         1
#define  STD_TYPES_NOK        0

#endif
