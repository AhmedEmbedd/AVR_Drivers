/*********************************************************/
/****  Name   : Ahmed Abdulla Mourad *********************/
/****  Date   : 10/2/2024            *********************/
/****  SWC    : Motor Driver          *********************/
/****  version: 1.0.0                *********************/
/*********************************************************/

/*              1-DC_MOTOR
                2-UNIPOLE_STEPPER_MOTOR_4_COILS
Options         3-UNIPOLE_STEPPER_MOTOR_2_COILS
                4-PIPOLE_STEPPER_MOTOR_2_COILS
                */
               
              
#define motor_type       DC_MOTOR
/*Options       1-Clockwise
                2-CounterClockwise*/
#define motor_rotation   Clockwise

/*Pin Conections*/ 
/*For Dc Motor*/
#define motor_PORT            PA
#define motor_vcc_pin         PA0
#define motor_ground_pin      PA1

/*For UNIPOLE_STEPPER_MOTOR_4_COILS
      UNIPOLE_STEPPER_MOTOR_2_COILS
      PIPOLE_STEPPER_MOTOR_2_COILS */
#define motor_coil1_vcc_pin      PA2
#define motor_coil1_ground_pin   PA3
#define motor_coil2_vcc_pin      PA4
#define motor_coil2_ground_pin   PA5
#define motor_coil3_vcc_pin      PA6
#define motor_coil3_ground_pin   PA7
#define motor_coil4_vcc_pin      PA0
#define motor_coil4_ground_pin   PA1

#define motor_coil1_vcc_PORT      PA
#define motor_coil1_ground_PORT   PA
#define motor_coil2_vcc_PORT      PA
#define motor_coil2_ground_PORT   PA
#define motor_coil3_vcc_PORT      PA
#define motor_coil3_ground_PORT   PA
#define motor_coil4_vcc_PORT      PA
#define motor_coil4_ground_PORT   PA

/*speed*/
#define motor_max_volt      5
#define motor_max_freqency  100
#define motor_StrideAngle   20

/*delay in ms*/
#define delay 1

