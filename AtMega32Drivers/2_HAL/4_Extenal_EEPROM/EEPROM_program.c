/****/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 18/4/2024            *********************/
/****  SWC    : EEPROM Driver        *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h "

#include "EEPROM_config.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"

#include "I2C_INTERFACE.h"

TWI_error EEPROM_voidWrite_Byte(u8 copy_u8DATA,u16 copy_u16Address)
{
	TWI_error local_error=NO_error;
	TWI_u8SendRestartCondition();
	local_error|=TWI_u8SendSlaveAddWithWrite(0x50 | (((copy_u16Address) & 0x0700) >> 8));
	TWI_u8SendDataByte((u8)copy_u16Address);
	TWI_u8SendDataByte(copy_u8DATA);
	TWI_u8SendStopCondition();
	return local_error;
}
u8 EEPROM_voidRead_Byte(u8 *copy_u8DATA,u16 copy_u16Address)
{
	u8 local_error=OK;
	local_error=TWI_u8SendRestartCondition();
	local_error|=TWI_u8SendSlaveAddWithWrite((0x50)|(copy_u16Address>>8));
	local_error|=TWI_u8SendDataByte((u8)copy_u16Address);
	local_error|=TWI_u8SendRestartCondition();
	local_error|=TWI_u8SendSlaveAddWithRead((0x50)|(copy_u16Address>>8));
	local_error|=TWI_u8ReadDataByte(copy_u8DATA);
	TWI_u8SendStopCondition();

	return local_error;

}
