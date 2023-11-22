/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 18/9/2022        *****/
/********** SWC     : KPD             *****/
/********** verison : v-1             *****/
/******************************************/
#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

#define KPD_u8_KEY_NOT_PRESSED   0xff

u8 KPD_u8GetKeyState(u8* Copy_pu8ReturnedKey);

#endif