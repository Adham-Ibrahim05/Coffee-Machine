/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 18/9/2022        *****/
/********** SWC     : KPD             *****/
/********** verison : v-1             *****/
/******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL 
#include <util/delay.h>

#include "DIO_interface.h"
#include "DIO_config.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"


static const u8 KPD_Au8Key[4][4]=KPD_u8_KEYS;

static const u8 KPD_Au8RowsPins[4]={KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};

static const u8 KPD_Au8ColsPins[4]={KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};

u8 KPD_u8GetKeyState(u8* Copy_pu8ReturnedKey)
{
	u8 Local_u8ErrorState = 1;
	u8 Local_u8RowCounter;
	u8 Local_u8ColCounter;
	u8 Local_u8PinValue;
	u8 Local_u8Flag = 0;
	if(Copy_pu8ReturnedKey != NULL)
	{
		*Copy_pu8ReturnedKey =KPD_u8_KEY_NOT_PRESSED;
		for(Local_u8RowCounter=0 ;Local_u8RowCounter<=3 ;Local_u8RowCounter++)
		{
			DIO_voidSetPinValue(KPD_u8_PORT,KPD_Au8RowsPins[Local_u8RowCounter],PIN_LOW);
			for(Local_u8ColCounter=0 ;Local_u8ColCounter<=3 ;Local_u8ColCounter++)
			{
				DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColsPins[Local_u8ColCounter],&Local_u8PinValue);
				if(Local_u8PinValue == PIN_LOW)
				{
					/*Debouncing*/
					_delay_ms(20);
					/*Check Agian if Pin Value is Low*/
					DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColsPins[Local_u8ColCounter],&Local_u8PinValue);
					while(Local_u8PinValue == PIN_LOW)
					{
						DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColsPins[Local_u8ColCounter],&Local_u8PinValue);
					}
					*Copy_pu8ReturnedKey = KPD_Au8Key[Local_u8RowCounter][Local_u8ColCounter];
					Local_u8Flag = 1;
					break; 
				}
			}
			DIO_voidSetPinValue(KPD_u8_PORT,KPD_Au8RowsPins[Local_u8RowCounter],PIN_HIGH);
			if(Local_u8Flag == 1) 
			{
			    break;
			}	
		}
	}
	else
	{
	  Local_u8ErrorState = 0;
	}
	return Local_u8ErrorState;
	
}

