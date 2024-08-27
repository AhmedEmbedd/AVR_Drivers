/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 18/3/2024             *********************/
/****  SWC    : UART Driver          *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H
void UART_VoidInit(void);
void UART_VoidSendByte(u8 data);
u8   UART_u8ReceiveByte(u8 * Copy_pu8RecByte) ;
#endif