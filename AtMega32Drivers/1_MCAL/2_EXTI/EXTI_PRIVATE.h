/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 19/2/2024            *********************/
/****  SWC    : EXTI Driver          *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#ifndef EXTI_PRIVATE_h
#define EXTI_PRIVATE_h

#define STD_TYPES_OK       1 
#define STD_TYPES_NOK      0

#define EXTI_U8_MCUCR      *((volatile u8 *)0x55)
#define EXTI_U8_MCUCSR     *((volatile u8 *)0x54)
#define EXTI_U8_GICR       *((volatile u8 *)0x5B)
#define EXTI_U8_GIFR       *((volatile u8 *)0x5A)



#endif