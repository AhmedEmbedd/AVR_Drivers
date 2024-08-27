/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 19/2/2024            *********************/
/****  SWC    : EXTI Driver          *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h "
 
#include "EXIT_INTERFACE.h" 
#include "EXIT_CONFIGURATION.h" 
#include "EXIT_PRIVATE.h" 

/*Global Pointer To A funcation*/
static  void (*EXTI_ApfEXTI[3]) (void) {NULL,NULL,NULL};



u8 EXTI_U8EXTIEnable  (u8 Copy_u8EXTIIndex , u8 Copy_u8EXTIEdge);
{
	u8 ErrorState = STD_TYPES_OK ;
	
	switch (Copy_u8EXTIIndex)
	{  
     	/******************INT0***********************/
		case EXTI_U8_INT0:
		switch (Copy_u8EXTIEdge)
		{
			case EXTI_U8_RISING_EDGE :
			CLR_BIT(EXTI_U8_MCUCR,0);
			CLR_BIT(EXTI_U8_MCUCR,1);
			/*enable INT0*/
			SET_BIT (EXTI_U8_GICR,6);
			break;
			
			case EXTI_U8_FALLING_EDGE :
			CLR_BIT(EXTI_U8_MCUCR,0);
			SET_BIT(EXTI_U8_MCUCR,1);
			/*enable INT0*/
			SET_BIT (EXTI_U8_GICR,6);			
			break;
			
			case EXTI_U8_ANY_LOGICAL_CHANGE :
			SET_BIT(EXTI_U8_MCUCR,0);
			CLR_BIT(EXTI_U8_MCUCR,1);
			/*enable INT0*/
			SET_BIT (EXTI_U8_GICR,6);
		    break;
			
			case EXTI_U8_LOW_LEVEL :
			SET_BIT(EXTI_U8_MCUCR,0);
			SET_BIT(EXTI_U8_MCUCR,1);
			/*enable INT0*/
			SET_BIT (EXTI_U8_GICR,6);
			break;
      
            default :
            ErrorState = STD_TYPES_NOK;
			break ;

	    }break;
		/******************INT0***********************/
     	/******************INT1***********************/
		case EXTI_U8_INT1:
		switch (Copy_u8EXTIIndex)
		{
			case EXTI_U8_RISING_EDGE :
			CLR_BIT(EXTI_U8_MCUCR,0);
			CLR_BIT(EXTI_U8_MCUCR,1);
			/*enable INT1*/
			SET_BIT (EXTI_U8_GICR,7);
			break;
			
			case EXTI_U8_FALLING_EDGE :
			CLR_BIT(EXTI_U8_MCUCR,0);
			SET_BIT(EXTI_U8_MCUCR,1);
            /*enable INT1*/
			SET_BIT (EXTI_U8_GICR,7);
			break;
			
			case EXTI_U8_ANY_LOGICAL_CHANGE :
			SET_BIT(EXTI_U8_MCUCR,0);
			CLR_BIT(EXTI_U8_MCUCR,1);
			/*enable INT1*/
			SET_BIT (EXTI_U8_GICR,7);
		    break;
			
			case EXTI_U8_LOW_LEVEL :
			SET_BIT(EXTI_U8_MCUCR,0);
			SET_BIT(EXTI_U8_MCUCR,1);
			/*enable INT1*/
			SET_BIT (EXTI_U8_GICR,7);
			break;	

            default :
            ErrorState = STD_TYPES_NOK;
			break ;
			
	    }break;
		/******************INT1***********************/
      	/******************INT2***********************/
		case EXTI_U8_INT2:
		switch (Copy_u8EXTIIndex)
		{
			case EXTI_U8_RISING_EDGE :
			SET_BIT(EXTI_U8_MCUCSR,6);
			/*enable INT2*/
			SET_BIT (EXTI_U8_GICR,5);
			break;
			
			case EXTI_U8_FALLING_EDGE :
			CLR_BIT(EXTI_U8_MCUCSR,6);
            /*enable INT2*/
			SET_BIT (EXTI_U8_GICR,5);
			break;

            default :
            ErrorState = STD_TYPES_NOK;
			
		/******************INT2***********************/				
	    }break;

        default :
           ErrorState = STD_TYPES_NOK;

	}
	
	
	
	
	return ErrorState ;
}

u8 EXTI_U8EXTIDisable (u8 Copy_u8EXTIIndex );
{  
    u8 ErrorState = STD_TYPES_OK ;
	
	switch (Copy_u8EXTIIndex )
	{
		case EXTI_U8_INT0: CLR_BIT (EXTI_U8_GICR,6); break;
		case EXTI_U8_INT1: CLR_BIT (EXTI_U8_GICR,7); break;
		case EXTI_U8_INT2: CLR_BIT (EXTI_U8_GICR,5); break;
		default :  ErrorState = STD_TYPES_NOK;     break;
	}
		return ErrorState ;   
}

u8 EXTI_U8SetCallBack (u8 Copy_u8EXTIIndex,void (*Copy_pf) (void))
{
	u8 ErrorState =STD_TYPES_OK;
	if (Copy_u8EXTIIndex<=EXTI_U8_INT2 &&Copy_u8EXTIIndex!=NULL)
	{
		EXTI_ApfEXTI[Copy_u8EXTIIndex]=Copy_pf;
	}
	else
	{
		ErrorState =STD_TYPES_NOK;
	}
	return ErrorState ;
}

/*Proto Type For ISR Of EXTI0*/
void __vector_1(void)         __attribute__(signal));
void __vector_1(void)
{   
    if(EXTI_ApfEXTI[EXTI_U8_INT0]!=NULL)
	{
	EXTI_ApfEXTI[EXTI_U8_INT0] ();
	}
}
/*Proto Type For ISR Of EXTI1*/
void __vector_2(void)         __attribute__(signal));
void __vector_2(void)
{
    if(EXTI_ApfEXTI[EXTI_U8_INT1]!=NULL)
	{
	EXTI_ApfEXTI[EXTI_U8_INT1] ();
	}
}
/*Proto Type For ISR Of EXTI2*/
void __vector_3(void)         __attribute__(signal));
void __vector_3(void)
{
    if(EXTI_ApfEXTI[EXTI_U8_INT2]!=NULL)
	{
	EXTI_ApfEXTI[EXTI_U8_INT2] ();
	}
}



