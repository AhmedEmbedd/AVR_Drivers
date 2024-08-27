/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 18/3/2024             *********************/
/****  SWC    : UART Driver          *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/
/*includes lib */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*includes mcal */
#include"UART_INTERFACE.h"
#include"UART_CONFIGURATION.h"
#include"UART_PRIVATE.h"

void UART_VoidInit(void)
{    
    /*Normal Speed*/
   CLR_BIT(UART_u8_UCSRA_Reg,1);
    /*disable MPM*/
   CLR_BIT(UART_u8_UCSRA_Reg,0);
   /*Enable TX & RX*/
   SET_BIT(UART_u8_UCSRB_Reg,4);
   SET_BIT(UART_u8_UCSRB_Reg,3);
  // Set BaudRate -> 9600/16 MhZ
   UART_u8_UBRRL_Reg = 102 ;
   UART_u8_UBRRH_Reg = 0   ;
  // Set Frame Format -> 8 data, 1 stop, No Parity
   UART_u8_UCSRC_Reg  = 0x8B;
}

void UART_VoidSendByte(u8 data);
{
  /* Wait until transmission Register  
     UART_u8_UCSRA_Reg ___BIT5 should be Zero
  */
  while((UART_u8_UCSRA_Reg&0x20) == 0x00);
        UART_u8_DDR_Reg = data;
}

u8 UART_u8ReceiveByte(u8 * Copy_pu8RecByte)
{  u8 Local_u8ErrorState=STD_TYPES_OK;
   if(Copy_pu8RecByte==NULL)
   {
	   Local_u8ErrorState=STD_TYPES_NOK;
   }
  // Wait until Reception Complete
  while((UART_u8_UCSRA_Reg&0x80) == 0x00);
  * Copy_pu8RecByte = UART_u8_DDR_Reg;
  /* Clear Flag */
  SET_BIT(UART_u8_UCSRA_Reg,7);
   
   
  return  Local_u8ErrorState;
  
}