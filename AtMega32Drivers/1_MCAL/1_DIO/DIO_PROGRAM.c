/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 2/2/2024             *********************/
/****  SWC    : DIO Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/
/* Lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_INTERFACE.h"
#include "DIO_PRIVATE.h"
#include "DIO_CONFIGURATION.h"

void DIO_voidInitialSetup (void)
{
	DIO_u8_DDRA_Reg = Conc(DIO_u8_PA7_INTIAL_DIRECTION,DIO_u8_PA6_INTIAL_DIRECTION,DIO_u8_PA5_INTIAL_DIRECTION,DIO_u8_PA4_INTIAL_DIRECTION,
						   DIO_u8_PA3_INTIAL_DIRECTION,DIO_u8_PA2_INTIAL_DIRECTION,DIO_u8_PA1_INTIAL_DIRECTION,DIO_u8_PA0_INTIAL_DIRECTION);

	DIO_u8_DDRB_Reg = Conc(DIO_u8_PB7_INTIAL_DIRECTION,DIO_u8_PB6_INTIAL_DIRECTION,DIO_u8_PB5_INTIAL_DIRECTION,DIO_u8_PB4_INTIAL_DIRECTION,
						   DIO_u8_PB3_INTIAL_DIRECTION,DIO_u8_PB2_INTIAL_DIRECTION,DIO_u8_PB1_INTIAL_DIRECTION,DIO_u8_PB0_INTIAL_DIRECTION);

	DIO_u8_DDRC_Reg = Conc(DIO_u8_PC7_INTIAL_DIRECTION,DIO_u8_PC6_INTIAL_DIRECTION,DIO_u8_PC5_INTIAL_DIRECTION,DIO_u8_PC4_INTIAL_DIRECTION,
						   DIO_u8_PC3_INTIAL_DIRECTION,DIO_u8_PC2_INTIAL_DIRECTION,DIO_u8_PC1_INTIAL_DIRECTION,DIO_u8_PC0_INTIAL_DIRECTION);

	DIO_u8_DDRD_Reg = Conc(DIO_u8_PD7_INTIAL_DIRECTION,DIO_u8_PD6_INTIAL_DIRECTION,DIO_u8_PD5_INTIAL_DIRECTION,DIO_u8_PD4_INTIAL_DIRECTION,
						   DIO_u8_PD3_INTIAL_DIRECTION,DIO_u8_PD2_INTIAL_DIRECTION,DIO_u8_PD1_INTIAL_DIRECTION,DIO_u8_PD0_INTIAL_DIRECTION);						   

	DIO_u8_PORTA_Reg = Conc(DIO_u8_PA7_INTIAL_VALUE,DIO_u8_PA6_INTIAL_VALUE,DIO_u8_PA5_INTIAL_VALUE,DIO_u8_PA4_INTIAL_VALUE,
						   DIO_u8_PA3_INTIAL_VALUE,DIO_u8_PA2_INTIAL_VALUE,DIO_u8_PA1_INTIAL_VALUE,DIO_u8_PA0_INTIAL_VALUE);
											                    
	DIO_u8_PORTB_Reg = Conc(DIO_u8_PB7_INTIAL_VALUE,DIO_u8_PB6_INTIAL_VALUE,DIO_u8_PB5_INTIAL_VALUE,DIO_u8_PB4_INTIAL_VALUE,
						   DIO_u8_PB3_INTIAL_VALUE,DIO_u8_PB2_INTIAL_VALUE,DIO_u8_PB1_INTIAL_VALUE,DIO_u8_PB0_INTIAL_VALUE);
											 
	DIO_u8_PORTC_Reg = Conc(DIO_u8_PC7_INTIAL_VALUE,DIO_u8_PC6_INTIAL_VALUE,DIO_u8_PC5_INTIAL_VALUE,DIO_u8_PC4_INTIAL_VALUE,
						   DIO_u8_PC3_INTIAL_VALUE,DIO_u8_PC2_INTIAL_VALUE,DIO_u8_PC1_INTIAL_VALUE,DIO_u8_PC0_INTIAL_VALUE);
											 
	DIO_u8_PORTD_Reg = Conc(DIO_u8_PD7_INTIAL_VALUE,DIO_u8_PD6_INTIAL_VALUE,DIO_u8_PD5_INTIAL_VALUE,DIO_u8_PD4_INTIAL_VALUE,
						   DIO_u8_PD3_INTIAL_VALUE,DIO_u8_PD2_INTIAL_VALUE,DIO_u8_PD1_INTIAL_VALUE,DIO_u8_PD0_INTIAL_VALUE);
}

u8  DIO_u8SetPinDirection (u8 Copy_u8PortId, u8 Copy_u8PinId ,u8 Copy_u8PinDirection)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8PortId <= DIO_U8_PORTD) && (Copy_u8PinId <= DIO_U8_PIN7) && ((Copy_u8PinDirection == DIO_U8_OUTPUT) || (Copy_u8PinDirection == DIO_U8_INPUT)))		
	{
		switch (Copy_u8PortId)
		{
			case DIO_U8_PORTA:
				switch (Copy_u8PinDirection)
				{
					case DIO_U8_OUTPUT:SET_BIT(DIO_u8_DDRA_Reg,Copy_u8PinId);break;
					case DIO_U8_INPUT: CLR_BIT(DIO_u8_DDRA_Reg,Copy_u8PinId);break;
				}
			break;
			case DIO_U8_PORTB:
				switch (Copy_u8PinDirection)
				{
					case DIO_U8_OUTPUT:SET_BIT(DIO_u8_DDRB_Reg,Copy_u8PinId);break;
					case DIO_U8_INPUT: CLR_BIT(DIO_u8_DDRB_Reg,Copy_u8PinId);break;
				}
			break;
			case DIO_U8_PORTC:
				switch (Copy_u8PinDirection)
				{
					case DIO_U8_OUTPUT:SET_BIT(DIO_u8_DDRC_Reg,Copy_u8PinId);break;
					case DIO_U8_INPUT: CLR_BIT(DIO_u8_DDRC_Reg,Copy_u8PinId);break;
				}
			break;
			case DIO_U8_PORTD:
				switch (Copy_u8PinDirection)
				{
					case DIO_U8_OUTPUT:SET_BIT(DIO_u8_DDRD_Reg,Copy_u8PinId);break;
					case DIO_U8_INPUT: CLR_BIT(DIO_u8_DDRD_Reg,Copy_u8PinId);break;
				}
			break;			
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}
u8  DIO_u8SetPinValue     (u8 Copy_u8PortId, u8 Copy_u8PinId ,u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8PinId <= DIO_U8_PIN7)
	{
		switch (Copy_u8PortId)
		{
			case DIO_U8_PORTA:
				switch (Copy_u8PinValue)
				{
					case DIO_U8_HIGH:SET_BIT(DIO_u8_PORTA_Reg,Copy_u8PinId);break;
					case DIO_U8_LOW: CLR_BIT(DIO_u8_PORTA_Reg,Copy_u8PinId);break;
					default : Local_u8ErrorState = STD_TYPES_NOK;
				}
			break;
			case DIO_U8_PORTB:
				switch (Copy_u8PinValue)
				{
					case DIO_U8_HIGH:SET_BIT(DIO_u8_PORTB_Reg,Copy_u8PinId);break;
					case DIO_U8_LOW: CLR_BIT(DIO_u8_PORTB_Reg,Copy_u8PinId);break;
					default : Local_u8ErrorState = STD_TYPES_NOK;
				}		
			break;
			case DIO_U8_PORTC:
				switch (Copy_u8PinValue)
				{
					case DIO_U8_HIGH:SET_BIT(DIO_u8_PORTC_Reg,Copy_u8PinId);break;
					case DIO_U8_LOW: CLR_BIT(DIO_u8_PORTC_Reg,Copy_u8PinId);break;
					default : Local_u8ErrorState = STD_TYPES_NOK;
				}		
			break;
			case DIO_U8_PORTD:
				switch (Copy_u8PinValue)
				{
					case DIO_U8_HIGH:SET_BIT(DIO_u8_PORTD_Reg,Copy_u8PinId);break;
					case DIO_U8_LOW: CLR_BIT(DIO_u8_PORTD_Reg,Copy_u8PinId);break;
					default : Local_u8ErrorState = STD_TYPES_NOK;
				}		
			break;
			default :
				Local_u8ErrorState = STD_TYPES_NOK;
		}
			
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
u8  DIO_u8GetPinValue     (u8 Copy_u8PortId, u8 Copy_u8PinId ,u8 * Copy_pu8ReturnedPinValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8PinValue;
	if((Copy_u8PortId <= DIO_U8_PORTD) && (Copy_u8PinId <= DIO_U8_PIN7) && (Copy_pu8ReturnedPinValue != NULL))
	{
		switch (Copy_u8PortId)
		{
			case DIO_U8_PORTA:
				Local_u8PinValue = GET_BIT(DIO_u8_PINA_Reg,Copy_u8PinId);
				if(Local_u8PinValue == 0)
				{
					*Copy_pu8ReturnedPinValue = DIO_U8_LOW;
				}	
				else
				{
					*Copy_pu8ReturnedPinValue = DIO_U8_HIGH;
				}
			break;
			case DIO_U8_PORTB:
				Local_u8PinValue = GET_BIT(DIO_u8_PINB_Reg,Copy_u8PinId);
				if(Local_u8PinValue == 0)
				{
					*Copy_pu8ReturnedPinValue = DIO_U8_LOW;
				}	
				else
				{
					*Copy_pu8ReturnedPinValue = DIO_U8_HIGH;
				}
			break;
			case DIO_U8_PORTC:
				Local_u8PinValue = GET_BIT(DIO_u8_PINC_Reg,Copy_u8PinId);
				if(Local_u8PinValue == 0)
				{
					*Copy_pu8ReturnedPinValue = DIO_U8_LOW;
				}	
				else
				{
					*Copy_pu8ReturnedPinValue = DIO_U8_HIGH;
				}
			break;
			case DIO_U8_PORTD:
				Local_u8PinValue = GET_BIT(DIO_u8_PIND_Reg,Copy_u8PinId);
				if(Local_u8PinValue == 0)
				{
					*Copy_pu8ReturnedPinValue = DIO_U8_LOW;
				}	
				else
				{
					*Copy_pu8ReturnedPinValue = DIO_U8_HIGH;
				}
			break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
u8  DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection)
{
	u8 Local_u8ErrorState = STD_TYPES_OK
	if((Copy_u8PortDirection == DIO_U8_OUTPUT) || (Copy_u8PortDirection == DIO_U8_INPUT))
	{
		switch (Copy_u8PortId)
		{
			case DIO_U8_PORTA:
				switch (Copy_u8PortDirection)
				{
					case DIO_U8_OUTPUT:DIO_u8_DDRA_Reg = 0xff;break;
					case DIO_U8_INPUT :DIO_u8_DDRA_Reg = 0x00;break;
				}
			break;
			case DIO_U8_PORTB:
				switch (Copy_u8PortDirection)
				{
					case DIO_U8_OUTPUT:DIO_u8_DDRB_Reg = 0xff;break;
					case DIO_U8_INPUT :DIO_u8_DDRB_Reg = 0x00;break;
				}
			break;
			case DIO_U8_PORTC:
				switch (Copy_u8PortDirection)
				{
					case DIO_U8_OUTPUT:DIO_u8_DDRC_Reg = 0xff;break;
					case DIO_U8_INPUT :DIO_u8_DDRC_Reg = 0x00;break;
				}
			break;
			case DIO_U8_PORTD:
				switch (Copy_u8PortDirection)
				{
					case DIO_U8_OUTPUT:DIO_u8_DDRD_Reg = 0xff;break;
					case DIO_U8_INPUT :DIO_u8_DDRD_Reg = 0x00;break;
				}
			break;
			default :Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
u8  DIO_u8SetPortValue    (u8 Copy_u8PortId, u8 Copy_u8PortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch (Copy_u8PortId)
	{
		case DIO_U8_PORTA:DIO_u8_PORTA_Reg = Copy_u8PortValue;break;
		case DIO_U8_PORTB:DIO_u8_PORTB_Reg = Copy_u8PortValue;break;
		case DIO_U8_PORTC:DIO_u8_PORTC_Reg = Copy_u8PortValue;break;
		case DIO_U8_PORTD:DIO_u8_PORTD_Reg = Copy_u8PortValue;break;
		default : Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
u8  DIO_u8GetPortValue    (u8 Copy_u8PortId, u8 * Copy_pu8ReturnedPortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if( Copy_pu8ReturnedPortValue != NULL)
	{
		switch (Copy_u8PortId)
		{
			case DIO_U8_PORTA: *Copy_pu8ReturnedPortValue = DIO_u8_PINA_Reg ;break;
			case DIO_U8_PORTB: *Copy_pu8ReturnedPortValue = DIO_u8_PINB_Reg ;break;
			case DIO_U8_PORTC: *Copy_pu8ReturnedPortValue = DIO_u8_PINC_Reg ;break;
			case DIO_U8_PORTD: *Copy_pu8ReturnedPortValue = DIO_u8_PIND_Reg ;break;
			default : Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}