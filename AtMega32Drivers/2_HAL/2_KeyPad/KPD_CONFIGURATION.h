/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 2/2/2024             *********************/
/****  SWC    : DIO Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/
/*PORT*/
#define KPD_U8_PORT            DIO_U8_PORTA
/*ROWS*/
#define KPD_U8_ROW0            DIO_U8_PIN0         // Set DIO Pins As output_HIGH
#define KPD_U8_ROW1            DIO_U8_PIN1         // Set DIO Pins As output_HIGH
#define KPD_U8_ROW2            DIO_U8_PIN2         // Set DIO Pins As output_HIGH
#define KPD_U8_ROW3            DIO_U8_PIN3         // Set DIO Pins As output_HIGH
/*COULUMS*/
#define KPD_U8_COULUM0         DIO_U8_PIN4         // Set DIO Pins As Input Pull_UP
#define KPD_U8_COULUM1         DIO_U8_PIN5         // Set DIO Pins As Input Pull_UP
#define KPD_U8_COULUM2         DIO_U8_PIN6         // Set DIO Pins As Input Pull_UP
#define KPD_U8_COULUM3         DIO_U8_PIN7         // Set DIO Pins As Input Pull_UP

#define KPD_Patern  {{'1','2','3','+'}, \
                     {'4','5','6','-'}, \
                     {'7','8','9','*'}, \
                     {'0','=','/','%'}}