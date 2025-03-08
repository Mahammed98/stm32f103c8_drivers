/*
 * 
 *  NAME : AFIO_prog.c
 *  CREATE : 9/9/2024
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 * 
 */

#include "AFIO_interface.h"
#include "GPIO_interface.h"

void M_AFIO_void_SetPin_ALFExt(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    volatile u32* Local_Value = 0;
    if(Copy_u8PinNumber >= 0 && Copy_u8PinNumber <= 3)
    {
        Local_Value = &__AFIO->AFIO_EXRICR1;
    }
    else if(Copy_u8PinNumber >= 4 && Copy_u8PinNumber <= 7)
    {
        Local_Value = &__AFIO->AFIO_EXRICR2;

    }
    else if(Copy_u8PinNumber >= 8 && Copy_u8PinNumber <= 11)
    {
        Local_Value = &__AFIO->AFIO_EXRICR3;

    }
    else if(Copy_u8PinNumber >= 12 && Copy_u8PinNumber <= 15)
    {
        Local_Value = &__AFIO->AFIO_EXRICR4;
    }
    else 
    {
        // nothing (error)
    }
    switch(Copy_u8PortName)
        {
            case PORTA_GPIO:
                (*Local_Value) |= (0<<((Copy_u8PinNumber % 4)*4));
                break;
            case PORTB_GPIO:
            	(*Local_Value) |= (1<<((Copy_u8PinNumber % 4)*4));
                break;
            case PORTC_GPIO:
            	(*Local_Value) |= (2<<((Copy_u8PinNumber % 4)*4));
                break;
            case PORTD_GPIO:
            	(*Local_Value) |= (3<<((Copy_u8PinNumber % 4)*4));
                break;
            case PORTE_GPIO:
            	(*Local_Value) |= (4<<((Copy_u8PinNumber % 4)*4));
                break;
            default:
                break;
        }
}
