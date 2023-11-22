#define F_CPU	8000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "I2C_interface.h"
#include "util\delay.h"

void main(void)
{
	Error_Status Error=NoError;
	DIO_VoidInit();
	I2C_voidSlaveInit(2);
	u8* Data=0;
	
    while(1)
    {
		I2C_Slave_voidListen();
		Error=I2C_u8SlaveReadDataByte(Data);
		
        if ((Error== NoError) && (*Data==1))
        {
	        /*Tea & Sugar Mixer and Canister Motors*/
	        DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,PIN_HIGH);
	        DIO_voidSetPinValue(DIO_PORTA,DIO_PIN1,PIN_LOW);
	        DIO_voidSetPinValue(DIO_PORTC,DIO_PIN2,PIN_HIGH);
	        DIO_voidSetPinValue(DIO_PORTC,DIO_PIN3,PIN_LOW);
	        
	        DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_HIGH);
	        DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,PIN_LOW);
	        DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_HIGH);
	        DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_LOW);
	        
	        /*Motors Off*/
	        _delay_ms(1000);
	        DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,PIN_LOW);
	        DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_LOW);
	        _delay_ms(2000);
	        DIO_voidSetPinValue(DIO_PORTC,DIO_PIN2,PIN_LOW);
	        DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_LOW);
        }
		 
	   	else if ((Error== NoError) && (*Data==2))
	   	{
	   		/*Coffee & Sugar Mixer and Canister Motors*/
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN3,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN5,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_LOW);	  
	  	  
	   		/*Motors Off*/	  
	   		_delay_ms(1000);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_LOW);	  
	   		_delay_ms(2000);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN4,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_LOW);
	   	}	  
	  	  
	   	else if ((Error== NoError) && (*Data==3))
	   	{
	   		/*Coffee & Sugar & Milk Mixer and Canister Motors*/
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN3,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN5,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN5,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN6,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,PIN_LOW);	  
	  	  
	   		/*Motors Off*/	  
	   		_delay_ms(1000);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_LOW);	  
	   		_delay_ms(2000);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN4,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_LOW);
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN6,PIN_LOW);
	   	}	  
	  	  
	   	else if ((Error== NoError) && (*Data==4))
	   	{
	   		/*Chocolate & Sugar & Milk Mixer and Canister Motors*/
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN6,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN7,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN5,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN6,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,PIN_LOW);	  
	  	  
	   		/*Motors Off*/	  
	   		_delay_ms(1000);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN6,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_LOW);	  
	   		_delay_ms(2000);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_LOW);
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN6,PIN_LOW);
	   	}	  
	  	  
	   	else if ((Error== NoError) && (*Data==5))
	   	{
	   		/*Chocolate & Sugar & Coffee & Milk Mixer and Canister Motors*/
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN6,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN7,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN5,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN6,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN3,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN5,PIN_LOW);	  
	  	  
	   		/*Motors Off*/	  
	   		_delay_ms(1000);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN6,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,PIN_LOW);	  
	   		_delay_ms(2000);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_LOW);
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN6,PIN_LOW);
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN4,PIN_LOW);
	   	}	  
	  	  
	   	else if ((Error== NoError) && (*Data==6))
	   	{
	   		/*Chocolate & Sugar & Coffee & Milk Mixer and Canister Motors*/
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN6,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN7,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN5,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN6,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN3,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN5,PIN_LOW);	  
	  	  
	   		/*Motors Off*/	  
	   		_delay_ms(1000);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN6,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,PIN_LOW);	  
	   		_delay_ms(2000);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_LOW);
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN6,PIN_LOW);
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN4,PIN_LOW);
	   	}	  
	  	  
	   	else if ((Error== NoError) && (*Data==7))
	   	{
	   		/*Caramel & Sugar Mixer and Canister Motors*/
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_LOW);	  
	  	  
	   		/*Motors Off*/	  
	   		_delay_ms(1000);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_LOW);	  
	   		_delay_ms(2000);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_LOW);
	   	}	  
	  	  
	   	else if ((Error== NoError) && (*Data==8))
	   	{
	   		/*Tea & Milk & Sugar Mixer and Canister Motors*/
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN1,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN3,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN5,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN6,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,PIN_LOW);	  
	  	  
	   		/*Motors Off*/	  
	   		_delay_ms(1000);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_LOW);	  
	   		_delay_ms(2000);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN2,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_LOW);
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN6,PIN_LOW);
	   	}	  
	  	  
	   	else if ((Error== NoError) && (*Data==9))
	   	{
	   		/*Coffee & Sugar & Milk Mixer and Canister Motors*/
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN3,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN5,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_LOW);	  
	  	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN5,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN6,PIN_HIGH);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,PIN_LOW);	  
	  	  
	   		/*Motors Off*/	  
	   		_delay_ms(1000);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_LOW);	  
	   		_delay_ms(2000);	  
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN4,PIN_LOW);	  
	   		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_LOW);
	   		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN6,PIN_LOW);
	   	}
    }
}