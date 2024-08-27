/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 5/2/2024             *********************/
/****  SWC    : LCD Driver           *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/
/*funcations for LCD*/

void LCD_VoidInti (void) ;

void LCD_VoidSendComand (u8 Copy_u8Com) ;

void LCD_VoidWriteCharcter (u8 Copy_u8Char) ;

void LCD_VoidWriteString (u8 * Copy_u8String ) ;

void LCD_VoidWriteNumber (u8  Copy_u8Number ) ;

u8 LCD_u8GoToLocation (u8  Copy_u8Line ,u8  Copy_u8Location) ;

void LCD_VoidClearLCD(void) ;

u8 LCD_u8MoveDisplay (u8  Copy_u8Dieriction) ;
/*macros for writing*/
#define LCD_U8_LINE1   0
#define LCD_U8_LINE2   1
/*macros for moving*/
#define LCD_U8_LEFT    0
#define LCD_U8_RIGHT   1






