/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 15/4/2024            *********************/
/****  SWC    : I2C Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

typedef enum 
{
	NO_error,Start_Error,Re_StartError,Slave_ADD_RD_Err
	,Slave_ADD_WR_Err,Master_WR_Err,Master_RD_Err
	
}TWI_error;

//I Have More Than One Return  I The Funcation
//So I Used enum

void       TWI_VoidMasterInit(void);
u8         TWI_VoidSlaveInit(u8 Copy_u8Address);
TWI_error  TWI_u8SendStartCondition(void);
TWI_error  TWI_u8SendRestartCondition(void);
TWI_error  TWI_u8SendStopCondition(void);
TWI_error  TWI_u8SendSlaveAddWithWrite(u8 Copy_u8SlaveAddress);
TWI_error  TWI_u8SendSlaveAddWithRead(u8 Copy_u8SlaveAddress);
TWI_error  TWI_u8SendDataByte(u8 Copy_u8Data);
TWI_error  TWI_u8ReadDataByte(u8 * Copy_pu8RecData);



#endi f