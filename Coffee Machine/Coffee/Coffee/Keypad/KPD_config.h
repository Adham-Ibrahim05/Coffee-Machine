/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 18/9/2022        *****/
/********** SWC     : KPD             *****/
/********** verison : v-1             *****/
/******************************************/
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H


#define KPD_u8_KEYS      {{'1','2','3','/'},\
						 {'4','5','6','k'},\
						 {'7','8','9','-'},\
						 {'*','0','#','+'}}
						  
#define KPD_u8_PORT       DIO_PORTB 
							 
#define KPD_u8_R1_PIN     DIO_PIN0
#define KPD_u8_R2_PIN     DIO_PIN1
#define KPD_u8_R3_PIN     DIO_PIN2
#define KPD_u8_R4_PIN     DIO_PIN3
							 
#define KPD_u8_C1_PIN     DIO_PIN4
#define KPD_u8_C2_PIN     DIO_PIN5
#define KPD_u8_C3_PIN     DIO_PIN6
#define KPD_u8_C4_PIN     DIO_PIN7 


#endif