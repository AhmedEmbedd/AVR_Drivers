/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 15/4/2024            *********************/
/****  SWC    : TWI Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "I2C_INTERFACE.h"
#include "I2C_PRIVATE.h"
#include "I2C_CONFIGURATION.h"


void TWI_VoidMasterInit(void)
{
	/* SET CLOCK fre to 400kb/s*/
	TWI_u8_TWBR_Reg=32;
	TWI_u8_TWSR_Reg=0;
	//CLR_BIT(TWI_u8_TWSR_Reg,TWSR_TWPS0);
	//CLR_BIT(TWI_u8_TWSR_Reg,TWSR_TWPS1);
	/*set address for master if it was recive*/

	TWI_u8_TWAR_Reg=2;

	/*enable TWI*/
	SET_BIT(TWI_u8_TWCR_Reg,TWCR_TWEN);


}
u8  TWI_VoidSlaveInit(u8 Copy_u8Address)
{
	u8  local_error =NO_error;
	if (Copy_u8Address!=NULL)
	{
		TWI_u8_TWAR_Reg = (Copy_u8Address << 1) ;
	    SET_BIT(TWI_u8_TWCR_Reg,6); 
	    SET_BIT(TWI_u8_TWCR_Reg,2);	
	}
	else
	{
		 local_error =Start_Error;
	}
	return local_error;


}
TWI_error  TWI_u8SendStartCondition(void)
{
	TWI_error local_error=NO_error;
	/* send start condition on the bus*/
	SET_BIT(TWI_u8_TWCR_Reg,5);

	/* clear interrupt flag of to start operation*/
	SET_BIT(TWI_u8_TWCR_Reg,7);
	/*enable TWI*/
	SET_BIT(TWI_u8_TWCR_Reg,2);
	/* wait until the falg is rised*/
	while((GET_BIT(TWI_u8_TWCR_Reg,7))==0);
	if((TWI_u8_TWSR_Reg&0xf8)!=Start_AC)
	{
		local_error=Start_Error;
	}

	return local_error;
}
TWI_error  TWI_u8SendRestartCondition(void)
{
	TWI_error local_error=NO_error;
	/* send start condition on the bus*/
	SET_BIT(TWI_u8_TWCR_Reg,TWCR_TWSTA);
	/*enable TWI*/
	SET_BIT(TWI_u8_TWCR_Reg,TWCR_TWEN);
	/* clear interrupt flag of to start operation*/
	SET_BIT(TWI_u8_TWCR_Reg,TWCR_TWINT);
	/* wait until the falg is rised*/
	while((GET_BIT(TWI_u8_TWCR_Reg,TWCR_TWINT))==0);
	if((TWSR&0xf8)!=RE_Start_AC)
	{
		local_error=Re_StartError;
	}

	return local_error;

}
TWI_error  TWI_u8SendStopCondition(void)
{

	/*generate  stop condition on the path */
	//SET_BIT(TWI_u8_TWCR_Reg,TWCR_TWSTO);
	/* clear interrupt flag of to start operation*/
	//SET_BIT(TWI_u8_TWCR_Reg,TWCR_TWINT);

	TWI_u8_TWCR_Reg=(1<<TWCR_TWINT)|(1<<TWCR_TWSTO)|(1<<TWCR_TWEN);


}
TWI_error  TWI_u8SendSlaveAddWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_error local_error=NO_error;

	TWI_u8_TWDR_Reg=((copy_u8SlaveAddress<<1) & 0xFE);
	/*enable TWI*/
	TWI_u8_TWCR_Reg=(1<<TWCR_TWINT)|(1<<TWCR_TWEN);
	//SET_BIT(TWI_u8_TWCR_Reg,TWCR_TWEN);

	/*set slave Address on the 7 most bit*/


	/* clear interrupt flag of to start operation*/
	//SET_BIT(TWI_u8_TWCR_Reg,TWCR_TWINT);
	/* wait until the falg is rised*/
	while(!(GET_BIT(TWI_u8_TWCR_Reg,TWCR_TWINT)));
	if(( TWI_u8_TWSR_Reg & 0xf8 ) != Salve_Add_WR_AC)
	{
		local_error=Slave_ADD_WR_Err;
	}

	return local_error;

}
TWI_error  TWI_u8SendSlaveAddWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_error local_error=NO_error;
	/*clear Start condition*/
	//CLR_BIT(TWI_u8_TWCR_Reg,TWCR_TWSTA);

	/*set slave Address on the 7 most bit*/
	TWI_u8_TWDR_Reg=((copy_u8SlaveAddress<<1)|1);
	/*SET for Read request*/

	/* clear interrupt flag of to start operation*/
	TWI_u8_TWCR_Reg=(1<<TWCR_TWINT)|(1<<TWCR_TWEN);
	/*enable TWI*/

	/* wait until the falg is rised*/
	while((GET_BIT(TWI_u8_TWCR_Reg,TWCR_TWINT))==0);
	if((TWI_u8_TWSR_Reg&0xf8)!=Salve_Add_RD_AC)
	{
		local_error=Slave_ADD_RD_Err;
	}

	return local_error;

}
TWI_error  TWI_u8SendDataByte(u8 Copy_u8Data)
{
	TWI_error local_error=NO_error;
	/* write the data in */
	TWI_u8_TWDR_Reg=copy_u8Data;

	/* clear interrupt flag of to start operation*/
	TWI_u8_TWCR_Reg = (1<<TWCR_TWINT)|(1<<TWCR_TWEN);

	/* wait until the falg is rised*/
	while((GET_BIT(TWI_u8_TWCR_Reg,TWCR_TWINT))==0);
	if((TWI_u8_TWSR_Reg&0xf8)!=Master_WR_AC)
	{
		local_error=Master_WR_Err;
	}
	return local_error;

}
TWI_error  TWI_u8ReadDataByte(u8 * Copy_pu8RecData)
{
	TWI_error local_error=NO_error;
	/*enable master to generate AC*/
	SET_BIT(TWI_u8_TWCR_Reg,TWCR_TWEA);
	/*enable TWI*/
	SET_BIT(TWI_u8_TWCR_Reg,TWCR_TWEN);
	/* clear interrupt flag of to start operation*/
	SET_BIT(TWI_u8_TWCR_Reg,TWCR_TWINT);
	/* wait until the falg is rised*/
	while((GET_BIT(TWI_u8_TWCR_Reg,TWCR_TWINT))==0);
	if((TWI_u8_TWSR_Reg&0xf8)!=Master_RD_AC)
	{
		local_error=Master_RD_Err;
	}
	else{
		/* Read the Recived data*/
		*Copy_pu8RecData=TWI_u8_TWDR_Reg;
	}


	return local_error;

}


