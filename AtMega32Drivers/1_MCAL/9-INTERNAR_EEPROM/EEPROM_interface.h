/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 18/4/2024            *********************/
/****  SWC    : EEPROM Driver        *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


void EEPROM_voidWrite_Byte(u8 copy_u8Data, u16 copy_u16Address);

void EEPROM_voidRead_Byte(u8 *copy_pvData, u16 copy_u16Address);







#endif
