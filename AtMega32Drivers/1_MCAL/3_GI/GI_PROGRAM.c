/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 19/2/2024            *********************/
/****  SWC    : GI Driver            *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GI_INTERFACE.h"

#define SREG  ((volatile u8 *) 0X5F )
 
 void GI_VoidEnable (void) 
 {
    SET_BIT(SERG,7);

 }
 void GI_VoidDisable (void) 
 {
    CLR_BIT(SERG,7);
 }
 
