/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 5/2/2024             *********************/
/****  SWC    : LCD Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

/*macros for LCD pins*/
#define LCD_VDD_PIN          DIO_U8_PIN0
#define LCD_VDD_PORT         DIO_U8_PORTA

#define LCD_DATA_PORT        DIO_U8_PORTC
#define LCD_Control_PORT     DIO_U8_PORTB
#define LCD_RS_PIN           DIO_U8_PIN2
#define LCD_RW_PIN           DIO_U8_PIN1
#define LCD_E_PIN            DIO_U8_PIN0
/*macros for LCD mode
options:LCD_8_BIT_MODE
       :LCD_4_BIT_MODE*/
#define LCD_MODE             LCD_8_BIT_MODE
/*DB PINS CONFIGURATIONS*/
#define LCD_DB7_PIN          DIO_U8_PIN7
#define LCD_DB6_PIN          DIO_U8_PIN6
#define LCD_DB5_PIN          DIO_U8_PIN5
#define LCD_DB4_PIN          DIO_U8_PIN4
/*DB PORTS CONFIGURATIONS*/
#define LCD_DB7_PORT         DIO_U8_PORTA
#define LCD_DB6_PORT         DIO_U8_PORTA
#define LCD_DB5_PORT         DIO_U8_PORTA
#define LCD_DB4_PORT         DIO_U8_PORTA


