/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 10/2/2024            *********************/
/****  SWC    : DIO Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

/*includes*/
/*lib*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util_delay.h>

/*MCAL*/
#include "DIO_INTERFACE.h"

/*HAL*/
#include "Motor_Configuration.h"
#include "Motor_Interface.h"
#include "Motor_private.h"

const u8  Motor_u8Volt ;

if (motor_type==DC_MOTOR)
{ u8 Error_state =STD_TYPES_TRUE ;

/************************````   DC   ````****************************/
   void Motor_VoidMOtorRotation(u8 Copy_u8Rotation)
   {
        switch (Copy_u8Rotation)
   {

       case Clockwise :
       DIO_u8SetPinValue(motor_PORT ,motor_vcc_pin ,DIO_U8_PIN_HIGH);
       DIO_u8SetPinValue(motor_PORT ,motor_ground_pin ,DIO_U8_PIN_LOW);
       break;
       case CounterClockwise :
       DIO_u8SetPinValue(motor_PORT ,motor_vcc_pin ,DIO_U8_PIN_LOW);
       DIO_u8SetPinValue(motor_PORT ,motor_ground_pin ,DIO_U8_PIN_HIGH);
       break;
       default:Error_state =STD_TYPES_FALSE ; break;
   }
   }
   /********************************************************/
      void Motor_VoidMOtorSpeed(u8 Copy_u8Freqency, u8 Copy_u8Rotation);
   {
       switch (Copy_u8Rotation) 
       {
       Motor_u8Volt =  (Copy_u8Freqency* motor_max_volt)/motor_max_freqency ;
       case Clockwise :
       DIO_u8SetPinValue(motor_PORT ,motor_vcc_pin ,Motor_u8Volt);
       DIO_u8SetPinValue(motor_PORT ,motor_ground_pin ,DIO_U8_PIN_LOW);
       break;
       case CounterClockwise :
       DIO_u8SetPinValue(motor_PORT ,motor_vcc_pin ,DIO_U8_PIN_LOW);
       DIO_u8SetPinValue(motor_PORT ,motor_ground_pin ,Motor_u8Volt);
       break;
       }
   } 
}
   
/************************````   DC   ````****************************/
/************````   UNIPOLE_STEPPER_MOTOR_4_COILS   ````*************/
  else if ((UNIPOLE_STEPPER_MOTOR_4_COILS)||(UNIPOLE_STEPPER_MOTOR_2_COILS)||(PIPOLE_STEPPER_MOTOR_2_COILS))
{
    void Motor_VoidMOtorRotation(u8 Copy_u8Rotation);
    {
        switch (Copy_u8Rotation)
        {
        case Clockwise:
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
          DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
          DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
          break;
          /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
        case CounterClockwise:
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_HIGH);
        _delay_ms(delay);
          break;
        default:Error_state =STD_TYPES_FALSE
            break;
        }

    } 
    /**********************************************/
    void Motor_VoidMOtorAngle(u8 Copy_u8Rotation ,u8 Copy_u8Angle);
    {
        if ((Copy_u8Angle>360)||(Copy_u8Angle < motor_StrideAngle))
        {
            Error_state =STD_TYPES_FALSE ;
        }
        
        switch (Copy_u8Rotation)
        { u8 No_Of_Steps=(Copy_u8Angle)/(2*motor_StrideAngle);
        case Clockwise:
        for(u8 i=0;i<No_Of_Steps;i++)
        {
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
          DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOWLOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOWLOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
          DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
          break;
        }
          /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
        case CounterClockwise:
        for(u8 i=0;i<No_Of_Steps;i++)
        {
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_HIGH);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_HIGH);
        _delay_ms(delay);
          break;
        default:Error_state =STD_TYPES_FALSE ;
            break;
        }
    }
    }
    /**********************************************/
    void Motor_VoidMOtorSpeed(u8 Copy_u8Rotation,u8 Copy_u8Freqency)
    {
        if ( Copy_u8Freqency>motor_max_freqency)
        {
           Error_state =STD_TYPES_FALSE ;
        }
        
        Motor_u8Volt =  (Copy_u8Freqency* motor_max_volt)/motor_max_freqency ;
        switch (Copy_u8Rotation)
        {
        case Clockwise:
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,Motor_u8Volt);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,Motor_u8Volt);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
          DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,Motor_u8Volt);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
          DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,Motor_u8Volt);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
          break;
          /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
        case CounterClockwise:
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,Motor_u8Volt);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,Motor_u8Volt);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,Motor_u8Volt);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        _delay_ms(delay);
        DIO_u8SetPinValue(motor_coil1_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil1_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil2_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil3_ground_PORT,motor_coil1_ground_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_vcc_PORT,motor_coil1_vcc_pin,DIO_U8_PIN_LOW);
        DIO_u8SetPinValue(motor_coil4_ground_PORT,motor_coil1_ground_pin,Motor_u8Volt);
        _delay_ms(delay);
          break;
        default:Error_state =STD_TYPES_FALSE
            break;
        }

    } 
}
else
    Error_state =STD_TYPES_FALSE;







