/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 2/2/2024             *********************/
/****  SWC    : DIO Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/*Macros For PORTS*/
#define DIO_U8_PORTA    0
#define DIO_U8_PORTB    1
#define DIO_U8_PORTC    2 
#define DIO_U8_PORTD    3

/*Macros For PINS*/
#define DIO_U8_PIN0     0
#define DIO_U8_PIN1     1
#define DIO_U8_PIN2     2
#define DIO_U8_PIN3     3
#define DIO_U8_PIN4     4
#define DIO_U8_PIN5     5
#define DIO_U8_PIN6     6
#define DIO_U8_PIN7     7

/*Macros For PIN DIRECTION*/
#define DIO_U8_INPUT    0
#define DIO_U8_OUTPUT   1

/*Macros For PIN STATE*/
#define DIO_U8_HIGH   1
#define DIO_U8_LOW    0

/*Macros For PORT STATE*/

 u8  DIO_u8SetPinDirection (u8 Copy_u8PortId   , u8 Copy_u8PinId ,u8 Copy_u8PinDirection             );

 u8  DIO_u8SetPinValue     (u8 Copy_u8PortId   , u8 Copy_u8PinId ,u8 Copy_u8PinValue                 );

 u8  DIO_u8GetPinValue     (u8 Copy_u8PortId   , u8 Copy_u8PinId ,u8 * Copy_pu8ReturenedPinValue     );

 u8  DIO_u8SetPortDirection (u8 Copy_u8PortId  , u8 Copy_u8PortDirection                             );
 
 u8  DIO_u8SetPort          (u8 Copy_u8PortId  , u8 Copy_u8PortState                                  );

 u8  DIO_u8SetPortValue     (u8 Copy_u8PortId  , u8 Copy_u8PortValue                                 );

 u8  DIO_u8GetPortValue     (u8 Copy_u8PortId  , u8 * Copy_pu8ReturenedPortValue                     );
    

#endif

