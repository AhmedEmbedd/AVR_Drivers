/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 5/2/2024             *********************/
/****  SWC    : LCD Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

/*Includes*/
/*lib*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include<util/delay.h>
#define F_CPU  1000000UL

/*MCAL*/
#include "DIO_INTERFACE.h"
/*HAL*/
#include "LCD_INTERFACE.h"
#include "LCD_CONFIGURATION.h"
#include "LCD_PRIVATE.h"

void LCD_VoidInti (void) 
{  
  
    /*Delay More Than 30ms*/
    _delay_ms (35);
    /*Funcation Set*/
     if (LCD_MODE ==LCD_4_BIT_MODE)
     { 
        LCD_VoidSendComand(0b00100010);
     }
      LCD_VoidSendComand(0b00111000);
     /*Delay More Than 39us*/
     _delay_us (40);
    /*Desplay On/Off Control*/
    LCD_VoidSendComand(0b00001110);
    /*Delay More Than 39us*/
    _delay_us (40);
    /*Desplay Clear*/
    LCD_VoidSendComand(0b00000001);
    /*Delay More Than 1.53ms*/
    _delay_ms (2);
    /*Entry Mode Set*/
    LCD_VoidSendComand(0b00000110);
  

}

void LCD_VoidSendComand (u8 Copy_u8Com) 

{
	#if LCD_MODE == LCD_8_BIT_MODE

    /*To Send Command */
    /*RS=0*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_RS_PIN,DIO_U8_LOW) ;
    /*RW=0*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_RW_PIN,DIO_U8_LOW) ;
     /*Send Command*/
     DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Com) ;
       /*E=1*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_E_PIN,DIO_U8_HIGH) ;
        _delay_us (1) ;
       /*E=0*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_E_PIN,DIO_U8_LOW) ;

 #elif LCD_MODE ==LCD_4_BIT_MODE

    /*To Send Command */
    /*RS=0*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_RS_PIN,DIO_U8_LOW) ;
    /*RW=0*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_RW_PIN,DIO_U8_LOW) ;
    /*Send HIGH PITS */
     /*BD7*/
    u8 LCD_u8PInValue=DIO_u8GetPinValue(Copy_u8Com,7);
    DIO_u8SetPinValue(LCD_DB7_PORT,LCD_DB7_PIN,LCD_u8PInValue) ;
     /*BD6*/
    u8 LCD_u8PInValue=DIO_u8GetPinValue(Copy_u8Com,6);
    DIO_u8SetPinValue(LCD_DB6_PORT,LCD_DB6_PIN,LCD_u8PInValue) ;
     /*BD5*/
    u8 LCD_u8PInValue=DIO_u8GetPinValue(Copy_u8Com,5);
    DIO_u8SetPinValue(LCD_DB5_PORT,LCD_DB5_PIN,LCD_u8PInValue) ;
     /*BD4*/
    u8 LCD_u8PInValue=DIO_u8GetPinValue(Copy_u8Com,4);
    DIO_u8SetPinValue(LCD_DB4_PORT,LCD_DB4_PIN,LCD_u8PInValue) ;
       /*E=1*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_E_PIN,DIO_U8_HIGH) ;
        _delay_us (1);
       /*E=0*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_E_PIN,DIO_U8_LOW) ;
    /*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
    /*Send LOW PITS */
     /*BD3*/
    u8 LCD_u8PInValue=DIO_u8GetPinValue(Copy_u8Com,3);
    DIO_u8SetPinValue(LCD_DB7_PORT,LCD_DB7_PIN,LCD_u8PInValue) ;
     /*BD2*/
    u8 LCD_u8PInValue=DIO_u8GetPinValue(Copy_u8Com,2);
    DIO_u8SetPinValue(LCD_DB6_PORT,LCD_DB6_PIN,LCD_u8PInValue) ;
     /*BD1*/
    u8 LCD_u8PInValue=DIO_u8GetPinValue(Copy_u8Com,1);
    DIO_u8SetPinValue(LCD_DB5_PORT,LCD_DB5_PIN,LCD_u8PInValue) ;
     /*BD0*/
    u8 LCD_u8PInValue=DIO_u8GetPinValue(Copy_u8Com,0);
    DIO_u8SetPinValue(LCD_DB4_PORT,LCD_DB4_PIN,LCD_u8PInValue) ;
       /*E=1*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_E_PIN,DIO_U8_HIGH) ;
            _delay_us (1);
       /*E=0*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_E_PIN,DIO_U8_LOW) ;

 #endif
}

void LCD_VoidWriteCharcter (u8 Copy_u8Char) 
{
  #if LCD_MODE ==LCD_8_BIT_MODE

    /*To Write Character */
    /*RS=1*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_RS_PIN,DIO_U8_HIGH) ;
    /*RW=0*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_RW_PIN,DIO_U8_LOW) ;
     /*Send Character*/
     DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Char);
       /*E=1*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_E_PIN,DIO_U8_HIGH) ;
       _delay_us (1);
       /*E=0*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_E_PIN,DIO_U8_LOW) ;

#elif  LCD_MODE ==LCD_4_BIT_MODE

      /*To Send Character */
    /*RS=1*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_RS_PIN,DIO_U8_HIGH) ;
    /*RW=0*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_RW_PIN,DIO_U8_LOW) ;
     /*Send HIGH PITS */
     u8 LCD_u8PinValue =0;
     /*BD7*/
    LCD_u8PinValue=GET_BIT (Copy_u8Char,7);
    DIO_u8SetPinValue(LCD_DB7_PORT,LCD_DB7_PIN,LCD_u8PinValue) ;
     /*BD6*/
    LCD_u8PinValue=GET_BIT(Copy_u8Char,6);
    DIO_u8SetPinValue(LCD_DB6_PORT,LCD_DB6_PIN,LCD_u8PinValue) ;
     /*BD5*/
    LCD_u8PinValue=GET_BIT(Copy_u8Char,5);
    DIO_u8SetPinValue(LCD_DB5_PORT,LCD_DB5_PIN,LCD_u8PinValue) ;
     /*BD4*/
    LCD_u8PinValue=GET_BIT(Copy_u8Char,4);
    DIO_u8SetPinValue(LCD_DB4_PORT,LCD_DB4_PIN,LCD_u8PinValue) ;
       /*E=1*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_E_PIN,DIO_U8_HIGH) ;
         _delay_us (1);
       /*E=0*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_E_PIN,DIO_U8_LOW) ;
    /*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
     /*Send LOW PITS */
     /*BD3*/
    LCD_u8PinValue =GET_BIT(Copy_u8Char,3);
    DIO_u8SetPinValue(LCD_DB7_PORT,LCD_DB7_PIN,LCD_u8PinValue) ;
     /*BD2*/
    LCD_u8PinValue=GET_BIT(Copy_u8Char,2);
    DIO_u8SetPinValue(LCD_DB6_PORT,LCD_DB6_PIN,LCD_u8PinValue) ;
     /*BD1*/
    LCD_u8PinValue=GET_BIT(Copy_u8Char,1);
    DIO_u8SetPinValue(LCD_DB5_PORT,LCD_DB5_PIN,LCD_u8PinValue) ;
     /*BD0*/
    LCD_u8PinValue=GET_BIT(Copy_u8Char,0);
    DIO_u8SetPinValue(LCD_DB4_PORT,LCD_DB4_PIN,LCD_u8PinValue) ;
       /*E=1*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_E_PIN,DIO_U8_HIGH) ;
       _delay_us (1);
       /*E=0*/
     DIO_u8SetPinValue(LCD_Control_PORT,LCD_E_PIN,DIO_U8_LOW) ;
 
 #endif

}

void LCD_VoidWriteString (u8 Copy_u8String[] )
{
	u8 i=0;
	while(Copy_u8String[i] !='\0')
	{
    LCD_VoidWriteCharcter (  Copy_u8String[i] ) ;
    i++ ;
	}
}

void LCD_VoidWriteNumber (u8  Copy_u8Number ) 
{
	 u8 reversed = 0;
	 u8 arr[6];
	 u8 i=0;
	    while (Copy_u8Number != 0)
	    {
	        reversed = Copy_u8Number % 10;
	        Copy_u8Number /= 10;

	        reversed=reversed+'0';
	        arr[i]=reversed;
	        i++;
        }
	    for(u8 j=0;j<i;j++)
	    {
        LCD_VoidWriteCharcter (arr[i-j-1]) ;
	    }
}

u8 LCD_u8GoToLocation (u8  Copy_u8Line ,u8  Copy_u8Location) 
{
    
    u8 Error_state = Input_Avalable ;
if (Copy_u8Location>39)
{  
     Error_state = Input_Not_Avalable ;
}
    switch (Copy_u8Line)
    {
    case LCD_U8_LINE1 : LCD_VoidSendComand (0X80 +Copy_u8Location) ; break;
    case LCD_U8_LINE2 : LCD_VoidSendComand (0XC0 +Copy_u8Location) ; break;
}
    return Error_state;
}
u8 LCD_u8MoveDisplay (u8  Copy_u8Dieriction)
{
    u8 Error_state = Input_Avalable ;
    if (Copy_u8Dieriction>LCD_U8_RIGHT)
    {
         Error_state = Input_Not_Avalable ;
    }
        switch (Copy_u8Dieriction)
        {
            case LCD_U8_LEFT   : LCD_VoidSendComand (0B00011000) ; break;
            case LCD_U8_RIGHT  : LCD_VoidSendComand (0B00011100) ; break;
        }
    return Error_state;
}

void LCD_VoidClearLCD(void)
{
    LCD_VoidSendComand (1);
    _delay_ms(1);
}