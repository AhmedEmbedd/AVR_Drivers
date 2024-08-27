/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 8/2/2024             *********************/
/****  SWC    : KPD Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/
/************************Includes**************************/

#define F_CPU  1000000UL
#include <util/delay.h>
/*Lib*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "DIO_INTERFACE.h"
/*HAL*/
#include "KPD_CONFIGURATION.h"
#include "KPD_INTERFACE.h"
#include "KPD_PRIVATE.h"
/*Array For Keys*/
const u8 KPD_Au8Keys[4] [4] = KPD_Patern ;
/*Array For Rows*/
const u8 KPD_Au8Rows[4] ={KPD_U8_ROW0,KPD_U8_ROW1,KPD_U8_ROW2,KPD_U8_ROW3} ;
/*Array For Coulums*/
const u8 KPD_Au8Coulums[4] ={KPD_U8_COULUM0,KPD_U8_COULUM1,KPD_U8_COULUM2,KPD_U8_COULUM3} ;

u8 KPD_u8GetKeyState (u8 *  Copy_pu8UsedKey)
{
/*set bits dierictios in DIO configuration file 
four bit output (for rows)
four bit input (for coulums)
active pull up ressistance

rows     PA0=1  PA1=1  PA2=1  PA3=1
coulums  (PA4  PA5  PA6  PA7) pull up  */

  u8  local_u8ErrorState = STD_TYPES_OK ;
  u8  Local_u8PinValue  = 0 ;
  u8  Local_u8Flag   = 0 ;
 if(Copy_pu8UsedKey== NULL)
 {
	 local_u8ErrorState = STD_TYPES_NOK;
 }
for(u8 Local_u8row = 0 ; Local_u8row <4 ;Local_u8row++)
{
     DIO_u8SetPinValue( KPD_U8_PORT ,KPD_Au8Rows[Local_u8row]  ,DIO_U8_LOW) ;

    for(u8 Local_u8Coulum=0 ;Local_u8Coulum<4 ;Local_u8Coulum++)
    {
    	DIO_u8GetPinValue (KPD_U8_PORT , KPD_Au8Coulums[Local_u8Coulum] , &Local_u8PinValue ) ;
        if(Local_u8PinValue==DIO_U8_LOW )
        {  
            _delay_ms (20) ;
            DIO_u8GetPinValue (KPD_U8_PORT ,KPD_Au8Coulums[Local_u8Coulum] ,&Local_u8PinValue ) ;
            while (Local_u8PinValue==DIO_U8_LOW)
            {
            	DIO_u8GetPinValue (KPD_U8_PORT ,KPD_Au8Coulums[Local_u8Coulum] ,&Local_u8PinValue ) ;
            }

             * Copy_pu8UsedKey = KPD_Au8Keys[Local_u8row] [Local_u8Coulum] ;
             Local_u8Flag =1 ;
             break;
        }

   } 

         DIO_u8SetPinValue(KPD_U8_PORT ,KPD_Au8Rows[Local_u8row]  ,DIO_U8_HIGH) ;
         if (Local_u8Flag ==1)
    {
       break;
    }
}



return local_u8ErrorState ;

}

