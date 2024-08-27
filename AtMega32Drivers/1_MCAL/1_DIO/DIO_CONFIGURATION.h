/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 4/2/2024             *********************/
/****  SWC    : DIO Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#ifndef DIO_CONFIGURATION_H
#define DIO_CONFIGURATION_H

/* Intial Directions for All Pins */
/* Options : DIO_PIN_INITIAL_INPUT            0
             DIO_PIN_INITIAL_OUTPUT  */
/* PORTA */			 
#define DIO_u8_PA0_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PA1_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PA2_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PA3_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PA4_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PA5_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PA6_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PA7_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
/* PORTB */			                                             
#define DIO_u8_PB0_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PB1_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PB2_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PB3_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PB4_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PB5_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PB6_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PB7_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
/* PORTC */			                                             
#define DIO_u8_PC0_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PC1_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PC2_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PC3_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PC4_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PC5_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PC6_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PC7_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
/* PORTD */			                                             
#define DIO_u8_PD0_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PD1_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PD2_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PD3_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PD4_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PD5_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PD6_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT
#define DIO_u8_PD7_INTIAL_DIRECTION                              DIO_u8_INTIAL_INPUT

/* Intial Values for All Pins */
/* Options : DIO_PIN_INITIAL_HIGH             
             DIO_PIN_INITIAL_LOW              
             DIO_PIN_INITIAL_INPUT_FLOAT      
             DIO_PIN_INITIAL_INPUT_PULLUP               */
/* PORTA */			 
#define DIO_u8_PA0_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PA1_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PA2_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PA3_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PA4_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PA5_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PA6_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PA7_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
/* PORTB */			                                             
#define DIO_u8_PB0_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PB1_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PB2_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PB3_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PB4_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PB5_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PB6_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PB7_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
/* PORTC */			                                             
#define DIO_u8_PC0_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PC1_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PC2_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PC3_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PC4_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PC5_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PC6_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PC7_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
/* PORTD */			                                             
#define DIO_u8_PD0_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PD1_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PD2_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PD3_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PD4_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PD5_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PD6_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING
#define DIO_u8_PD7_INTIAL_VALUE                                  DIO_u8_INPUT_FLOATING

#endif


