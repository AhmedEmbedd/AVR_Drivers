/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 20/3/2024            *********************/
/****  SWC    : SPI Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"SPI_INTERFACE.h"
#include"SPI_PRIVATE.h"
#include"SPI_CONFIGURATION.h"

#define Init_Reg     "0b00##DataOrder##Power##ClockPolarity##ClockPhase##00"

void SPI_VoidInit(void) 
{
	SPI_u8_SPCR_Reg = (Init_Reg)||(ClockRate) ;
	if(ClockSpeed==NormalSpeed)
	{  
        CLR_BIT(SPI_u8_SPSR_Reg,0);
	}
	else if(ClockSpeed==DoubleSpeed)
	{  
        SET_BIT(SPI_u8_SPSR_Reg,0);
	}
}

u8 SPI_u8TransAndRec(u8 Copy_u8TransimettedByte,u8* Copy_pu8RecievedByte)
{   
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if(Copy_pu8RecievedByte!=NULL)
	{              /*send byte*/
		SPI_u8_SPDR_Reg=Copy_u8TransimettedByte;
		
		while(GET_BIT(SPI_u8_SPSR_Reg,7)==0) ;
			/*read byte*/
		*Copy_pu8RecievedByte=SPI_u8_SPDR_Reg;
	   
	    Local_u8ErrorState=STD_TYPES_OK ;
	}
	
	return Local_u8ErrorState ;
}
void SPI_VoidSlaveSendByte(u8 Copy_u8DataByte)
{
	SPI_u8_SPDR_Reg=Copy_u8DataByte;
}
void SPI_VoidMasterSendByte(u8 Copy_u8DataByte)
{
	while(GET_BIT(SPI_u8_SPSR_Reg,7)==0) ;
	SPI_u8_SPDR_Reg=Copy_u8DataByte;
}

u8  SPI_VoidRecByte(u8* Copy_pu8RecByte)  
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if(Copy_pu8RecByte!=NULL)
	{ 	
		while(GET_BIT(SPI_u8_SPSR_Reg,7)==0) ;
			/*read byte*/
		*Copy_pu8RecByte=SPI_u8_SPDR_Reg;
	   
	    Local_u8ErrorState=STD_TYPES_OK ;
	}
     
    return Local_u8ErrorState ;	 
}
