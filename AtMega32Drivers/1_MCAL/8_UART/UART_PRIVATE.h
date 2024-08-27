/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 18/3/2024             *********************/
/****  SWC    : UART Driver          *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define UART_u8_UDR_Reg       *((volatile u8 *)0x2C)
#define UART_u8_UCSRA_Reg     *((volatile u8 *)0x2B)
#define UART_u8_UCSRB_Reg     *((volatile u8 *)0x2A)
#define UART_u8_UCSRC_Reg     *((volatile u8 *)0x40)
#define UART_u8_UBRRH_Reg     *((volatile u8 *)0x40)
#define UART_u8_UBRRL_Reg     *((volatile u8 *)0x29)

#endif