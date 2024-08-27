/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 19/2/2024            *********************/
/****  SWC    : EXTI Driver          *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/
#ifndef EXTI_INTERFACE_h
#define EXTI_INTERFACE_h
/*MACROS FOR EXTI INDEX*/

#define EXTI_U8_INT0                     0
#define EXTI_U8_INT1                     1
#define EXTI_U8_INT2                     2

/*MACROS FOR EXTI EDGE*/ 
#define EXTI_U8_RISING_EDGE              0
#define EXTI_U8_FALLING_EDGE             1 
#define EXTI_U8_ANY_LOGICAL_CHANGE       2
#define EXTI_U8_LOW_LEVEL                3


u8 EXTI_U8EXTIEnable  (u8 Copy_u8EXTIIndex ,u8 Copy_u8EXTIEdge);
u8 EXTI_U8EXTIDisable (u8 Copy_u8EXTIIndex );
u8 EXTI_U8SetCallBack (u8 Copy_u8EXTIIndex,void (*Copy_pf) (void));

#endif