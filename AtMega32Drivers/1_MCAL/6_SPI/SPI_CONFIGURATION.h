/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 20/3/2024            *********************/
/****  SWC    : SPI Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

#ifndef SPI_CONFIGURATION_H
#define SPI_CONFIGURATION_H

/****************************************************/
/*OPTIONS  :Master
           :Slave
*/
#define Power   Master
/****************************************************/

/****************************************************/
/*OPTIONS  : LSB    //he LSB of the data word is transmitted first
           : MSB    //he LSB of the data word is transmitted first
*/
#define DataOrder   MSB
/****************************************************/

/*OPTIONS for  :Rising   //SCK is low  when idle
  Leading edge :Falling  //SCK is High when idle
*/ 
#define Clock Polarity  Rising 

/****************************************************/
/*OPTIONS for  :Sample   //SCK is low  when idle
  Leading edge :Setup    //SCK is High when idle
*/
#define Clock Phase  Setup

/****************************************************/

/*        <<OPTIONS>>
          NormalSpeed      
          DoubleSpeed    
 */ 
#define ClockSpeed     NormalSpeed


/*        <<OPTIONS>>
          DividedBy_2   
          DividedBy_8      
          DividedBy_32     
          DividedBy_4      
          DividedBy_16     
          DividedBy_64     
          DividedBy_128    
 */    
#define ClockRate      DividedBy_4

/****************************************************/

#endif