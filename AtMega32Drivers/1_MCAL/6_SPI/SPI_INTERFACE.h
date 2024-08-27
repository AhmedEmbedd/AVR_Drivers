/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 20/3/2024            *********************/
/****  SWC    : SPI Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_VoidInit(void) ;
u8 SPI_u8TransAndRec(u8 Copy_u8TransimettedByte,u8* Copy_pu8RecievedByte);
void SPI_VoidMasterSendByte(u8 Copy_u8DataByte);
void SPI_VoidSlaveSendByte(u8 Copy_u8DataByte);
u8  SPI_u8RecByte(u8* Copy_pu8RecByte);

#endif