#define F_CPU 8000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "KPD_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include "I2C_interface.h"
#include "Timer1_interface.h"
#include "util/delay.h"

void Ultrasonic_ISR (void);

u16 Read1=0,Read2=0,Difference=0,mv=0,Digital=0;
u8 Level=0,temp=0,Local_u8Key;
u8 Level_flag=0,Temp_flag=0,Welc_flag=0;
Error_Status Error=NoError;

void main(void)
{
	DIO_VoidInit();
	LCD_voidInit();
	ADC_voidInit ();
	ADC_voidEnable();
	Timer1_voidInit();
	Timer1_ICUSenseMode(ICU_RISING_EDGE);
	Timer1_ICUInterruptEnable();
	Timer1_VoidICUSetCallBack(Ultrasonic_ISR);
	I2C_voidMasterInit(0);
	GIE_voidEnable();

    while(1)
    {	
        /*Ultrasonic (Water Level)*/
		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_HIGH);
		_delay_us(10);
		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_LOW);
		
		Level = Difference/58;
		if (Level_flag==0)
		{
			LCD_voidGoToXY(0, 0);
			LCD_voidSendString("Water Level =");
			LCD_voidGoToXY(0, 14);
			LCD_voidWriteNumber(Level);
			LCD_voidSendString("  ");
		}
		
		/*Temperature (Water Heating)*/
		ADC_Channel(ADC0);
		ADC_voidStartConversion();
		Digital = ADC_u16GetChannelReading();
		mv = ((u32) Digital*5000UL)/1024UL; 
		temp = mv/10;
		
		if (Level == 80)
		{
			Level_flag = 1;
			if (Temp_flag==0)
			{
				LCD_voidGoToXY(0, 0);
				LCD_voidSendString("Temperature =");
				LCD_voidGoToXY(0, 14);
				LCD_voidWriteNumber(temp);
				LCD_voidGoToXY(2, 5);
				LCD_voidSendString("Heating...");
			}		
		}
		
		/*Welcome Page*/
		if (temp == 90)
		{
			Temp_flag = 1;
			if (Welc_flag==0)
			{
				LCD_voidGoToXY(0, 0);
				LCD_voidSendString("   Coffee Machine");
				LCD_voidGoToXY(2, 5);
				LCD_voidSendString("  Welcome   ");
			}
		}
		
		/*Drinks Selection*/
		KPD_u8GetKeyState(&Local_u8Key);
		if (Local_u8Key!=KPD_u8_KEY_NOT_PRESSED)
		{
			/*Communication Starts*/
			Error =I2C_u8SendStartCondition();
			Error=I2C_u8SendSlaveAddressWithWrite(2);
			
			switch(Local_u8Key)
			{
				/*Tea*/
				case '1':
				Welc_flag = 1;
				/*Motors With Communication*/
				if (Error == NoError)
				{Error=I2C_u8MasterWriteDataByte(1);}
					
				if (Error == NoError)
				{	
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Flavor 1");
					LCD_voidGoToXY(2, 5);
					LCD_voidSendString("Processing...");
					/*Valves ON*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_HIGH);
					_delay_ms(3000);
					/*Valves OFF*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_LOW);
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Enjoy Your Drink");
					_delay_ms(1000);
					Welc_flag = 0;
				}
				I2C_u8SendStopCondition();
				break;
				
				/*Nescafe Black*/
				case '2':
				Welc_flag = 1;
				/*Motors With Communication*/
				if (Error == NoError)
				{Error=I2C_u8MasterWriteDataByte(2);}
					
				if (Error == NoError)
				{
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Flavor 2");
					LCD_voidGoToXY(2, 5);
					LCD_voidSendString("Processing...");
					/*Valves ON*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_HIGH);
					_delay_ms(3000);
					/*Valves OFF*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_LOW);
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Enjoy Your Drink");
					_delay_ms(1000);
					Welc_flag = 0;
				}	
				I2C_u8SendStopCondition();
				break;
				
				/*Nescafe Milk*/
				case '3':
				Welc_flag = 1;
				/*Motors With Communication*/
				if (Error == NoError)
				{Error=I2C_u8MasterWriteDataByte(3);}
				
				if (Error == NoError)
				{	
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Flavor 3");
					LCD_voidGoToXY(2, 5);
					LCD_voidSendString("Processing...");
					/*Valves ON*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_HIGH);
					_delay_ms(3000);
					/*Valves OFF*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_LOW);
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Enjoy Your Drink");
					_delay_ms(1000);
					Welc_flag = 0;
				}
				I2C_u8SendStopCondition();
				break;
				
				/*Hot Chocolate*/
				case '4':
				Welc_flag = 1;
				/*Motors With Communication*/
				if (Error == NoError)
				{Error=I2C_u8MasterWriteDataByte(4);}
				
				if (Error == NoError)
				{
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Flavor 4");
					LCD_voidGoToXY(2, 5);
					LCD_voidSendString("Processing...");
					/*Valves ON*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_HIGH);
					_delay_ms(3000);
					/*Valves OFF*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_LOW);
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Enjoy Your Drink");
					_delay_ms(1000);
					Welc_flag = 0;
				}
				I2C_u8SendStopCondition();
				break;
				
				/*Cappuccino*/
				case '5':
				Welc_flag = 1;
				/*Motors With Communication*/
				if (Error == NoError)
				{Error=I2C_u8MasterWriteDataByte(5);}
				
				if (Error == NoError)
				{
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Flavor 5");
					LCD_voidGoToXY(2, 5);
					LCD_voidSendString("Processing...");
					/*Valves ON*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_HIGH);
					_delay_ms(3000);
					/*Valves OFF*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_LOW);
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Enjoy Your Drink");
					_delay_ms(1000);
					Welc_flag = 0;
				}
				I2C_u8SendStopCondition();
				break;
				
				/*Mocha*/
				case '6':
				Welc_flag = 1;
				/*Motors With Communication*/
				if (Error == NoError)
				{Error=I2C_u8MasterWriteDataByte(6);}
				
				if (Error == NoError)
				{
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Flavor 6");
					LCD_voidGoToXY(2, 5);
					LCD_voidSendString("Processing...");
					/*Valves ON*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_HIGH);
					_delay_ms(3000);
					/*Valves OFF*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_LOW);
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Enjoy Your Drink");
					_delay_ms(1000);
					Welc_flag = 0;
				}
				I2C_u8SendStopCondition();
				break;
				
				/*Nescafe Caramel*/
				case '7':
				Welc_flag = 1;
				/*Motors With Communication*/
				if (Error == NoError)
				{Error=I2C_u8MasterWriteDataByte(7);}
				
				if (Error == NoError)
				{
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Flavor 7");
					LCD_voidGoToXY(2, 5);
					LCD_voidSendString("Processing...");
					/*Valves ON*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_HIGH);
					_delay_ms(3000);
					/*Valves OFF*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_LOW);
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Enjoy Your Drink");
					_delay_ms(1000);
					Welc_flag = 0;
				}
 				I2C_u8SendStopCondition();
				break;
				
				/*Tea Milk*/
				case '8':
				Welc_flag = 1;
				/*Motors With Communication*/
				if (Error == NoError)
				{Error=I2C_u8MasterWriteDataByte(8);}
				
				if (Error == NoError)
				{
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Flavor 8");
					LCD_voidGoToXY(2, 5);
					LCD_voidSendString("Processing...");
					/*Valves ON*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_HIGH);
					_delay_ms(3000);
					/*Valves OFF*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_LOW);
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Enjoy Your Drink");
					_delay_ms(1000);
					Welc_flag = 0;
				}
 				I2C_u8SendStopCondition();
				break;
				
				/*Latte*/
				case '9':
				Welc_flag = 1;
				/*Motors With Communication*/
				if (Error == NoError)
				{Error=I2C_u8MasterWriteDataByte(9);}
				
				if (Error == NoError)
				{
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Flavor 9");
					LCD_voidGoToXY(2, 5);
					LCD_voidSendString("Processing...");
					/*Valves ON*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_HIGH);
					_delay_ms(3000);
					/*Valves OFF*/
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_LOW);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,PIN_LOW);
					LCD_voidSendCommand(1);
					LCD_voidGoToXY(0, 0);
					LCD_voidSendString(" Enjoy Your Drink");
					_delay_ms(1000);
					Welc_flag = 0;
				}
				I2C_u8SendStopCondition();
				break;
			}	
		}	
    }
}


void Ultrasonic_ISR (void)
{
	u8 static count=0;
	count++;
	if (count==1)
	{
		Read1 = Timer1_ICR1Read();
		Timer1_ICUSenseMode(ICU_FALLING_EDGE);
	}
	else if (count==2)
	{
		Read2 = Timer1_ICR1Read();
		Difference = Read2-Read1;
		Timer1_ICUSenseMode(ICU_RISING_EDGE);
		TCNT1 = 0;
		count = 0;
	}
}