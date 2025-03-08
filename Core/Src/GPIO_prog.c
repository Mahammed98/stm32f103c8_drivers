#include "GPIO_interface.h"


void M_GPIO_void_SetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode, u8 Copy_u8IOMode)
{
	/*
	 *  first you must reset all pins in GPIOx_CRL and GPIOx_CRH
	 *  Because in CNF[0:1] the default value is 0x01 (floating input)
	 */

    if(Copy_u8PinNumber >= 0 && Copy_u8PinNumber <= 7)
    {
        switch(Copy_u8PortName)
        {
            case PORTA_GPIO:
            	GPIO_A->GPIOx_CRL &= ~(0xf<<(4*Copy_u8PinNumber));
            	GPIO_A->GPIOx_CRL |= (u32)(Copy_u8PinMode << (4*Copy_u8PinNumber));
            	GPIO_A->GPIOx_CRL |= (u32)(Copy_u8IOMode << (2+(4*Copy_u8PinNumber)));
                break;
            case PORTB_GPIO:
            	GPIO_B->GPIOx_CRL &= ~(0xf<<(4*Copy_u8PinNumber));
                GPIO_B->GPIOx_CRL |= (u32)(Copy_u8PinMode << (4*Copy_u8PinNumber));
                GPIO_B->GPIOx_CRL |= (u32)(Copy_u8IOMode << (2+(4*Copy_u8PinNumber)));
                break;
            case PORTC_GPIO:
            	GPIO_C->GPIOx_CRL &= ~(0xf<<(4*Copy_u8PinNumber));
                GPIO_C->GPIOx_CRL |= (u32)(Copy_u8PinMode << (4*Copy_u8PinNumber));
                GPIO_C->GPIOx_CRL |= (u32)(Copy_u8IOMode << (2+(4*Copy_u8PinNumber)));
                break;
            case PORTD_GPIO:
            	GPIO_D->GPIOx_CRL &= ~(0xf<<(4*Copy_u8PinNumber));
                GPIO_D->GPIOx_CRL |= (u32)(Copy_u8PinMode << (4*Copy_u8PinNumber));
                GPIO_D->GPIOx_CRL |= (u32)(Copy_u8IOMode << (2+(4*Copy_u8PinNumber)));
                break;
            case PORTE_GPIO:
            	GPIO_E->GPIOx_CRL &= ~(0xf<<(4*Copy_u8PinNumber));
                GPIO_E->GPIOx_CRL |= (u32)(Copy_u8PinMode << (4*Copy_u8PinNumber));
                GPIO_E->GPIOx_CRL |= (u32)(Copy_u8IOMode << (2+(4*Copy_u8PinNumber)));
                break;
            default:
                break;
        }
    }
    else if(Copy_u8PinNumber >= 8 && Copy_u8PinNumber <= 15)
    {
        switch(Copy_u8PortName)
        {
            case PORTA_GPIO:
            	GPIO_A->GPIOx_CRH &= ~(0xf<<(4*Copy_u8PinNumber));
            	GPIO_A->GPIOx_CRH |= (u32)(Copy_u8PinMode << (4*Copy_u8PinNumber));
            	GPIO_A->GPIOx_CRH |= (u32)(Copy_u8IOMode << (2+(4*Copy_u8PinNumber)));
                break;
            case PORTB_GPIO:
            	GPIO_B->GPIOx_CRH &= ~(0xf<<(4*Copy_u8PinNumber));
                GPIO_B->GPIOx_CRH |= (u32)(Copy_u8PinMode << (4*(Copy_u8PinNumber-8)));
                GPIO_B->GPIOx_CRH |= (u32)(Copy_u8IOMode << (2+(4*(Copy_u8PinNumber-8))));
                break;
            case PORTC_GPIO:
            	GPIO_C->GPIOx_CRH &= ~(0xf<<(4*Copy_u8PinNumber));
                GPIO_C->GPIOx_CRH |= (u32)(Copy_u8PinMode << (4*(Copy_u8PinNumber-8)));
                GPIO_C->GPIOx_CRH |= (u32)(Copy_u8IOMode << (2+(4*(Copy_u8PinNumber-8))));
                break;
            case PORTD_GPIO:
            	GPIO_D->GPIOx_CRH &= ~(0xf<<(4*Copy_u8PinNumber));
                GPIO_D->GPIOx_CRH |= (u32)(Copy_u8PinMode << (4*(Copy_u8PinNumber-8)));
                GPIO_D->GPIOx_CRH |= (u32)(Copy_u8IOMode << (2+(4*(Copy_u8PinNumber-8))));
                break;
            case PORTE_GPIO:
            	GPIO_E->GPIOx_CRH &= ~(0xf<<(4*Copy_u8PinNumber));
                GPIO_E->GPIOx_CRH |= (u32)(Copy_u8PinMode << (4*(Copy_u8PinNumber-8)));
                GPIO_E->GPIOx_CRH |= (u32)(Copy_u8IOMode << (2+(4*(Copy_u8PinNumber-8))));
                break;
            default:
                break;
        }
    }
    else
    {
        // nothing
    }
}

u8 M_GPIO_void_ReadPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    u8 Local_u8state = 0;
    switch(Copy_u8PortName)
    {
        case PORTA_GPIO:     
                Local_u8state = __GET_BIT(GPIO_A->GPIOx_IDR,Copy_u8PinNumber);
                break;
            case PORTB_GPIO:     
                Local_u8state = __GET_BIT(GPIO_B->GPIOx_IDR,Copy_u8PinNumber);
                break;
            case PORTC_GPIO:     
                Local_u8state = __GET_BIT(GPIO_C->GPIOx_IDR,Copy_u8PinNumber);
                break;
            case PORTD_GPIO:     
                Local_u8state = __GET_BIT(GPIO_D->GPIOx_IDR,Copy_u8PinNumber);
                break;
            case PORTE_GPIO:     
                Local_u8state = __GET_BIT(GPIO_E->GPIOx_IDR,Copy_u8PinNumber);
                break;
            default:
                break;
    }
    return Local_u8state;
}
void M_GPIO_void_WritePin(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8State)
{
    if(Copy_u8State == HIGH)
    {
        switch(Copy_u8PortName)
        {
            case PORTA_GPIO:     
                __SET_BIT(GPIO_A->GPIOx_ODR,Copy_u8PinNumber);
                break;
            case PORTB_GPIO:     
                __SET_BIT(GPIO_B->GPIOx_ODR,Copy_u8PinNumber);
                break;
            case PORTC_GPIO:     
                __SET_BIT(GPIO_C->GPIOx_ODR,Copy_u8PinNumber);
                break;
            case PORTD_GPIO:     
                __SET_BIT(GPIO_D->GPIOx_ODR,Copy_u8PinNumber);
                break;
            case PORTE_GPIO:     
                __SET_BIT(GPIO_E->GPIOx_ODR,Copy_u8PinNumber);
                break;
            default:
                break;
        }
    }
    else if (Copy_u8State == LOW)
    {
        switch(Copy_u8PortName)
        {
            case PORTA_GPIO:     
                __CLR_BIT(GPIO_A->GPIOx_ODR,Copy_u8PinNumber);
                break;
            case PORTB_GPIO:     
                __CLR_BIT(GPIO_B->GPIOx_ODR,Copy_u8PinNumber);
                break;
            case PORTC_GPIO:     
                __CLR_BIT(GPIO_C->GPIOx_ODR,Copy_u8PinNumber);
                break;
            case PORTD_GPIO:     
                __CLR_BIT(GPIO_D->GPIOx_ODR,Copy_u8PinNumber);
                break;
            case PORTE_GPIO:     
                __CLR_BIT(GPIO_E->GPIOx_ODR,Copy_u8PinNumber);
                break;
            default:
                break;
        }
    }
    else
    {
        //nothing
    }
    
}

void M_GPIO_void_WritePinBSRR(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8State)
{
    if(Copy_u8State == HIGH)
    {
        switch(Copy_u8PortName)
        {
            case PORTA_GPIO:
            	__SET_BIT(GPIO_A->GPIOx_BSRR, Copy_u8PinNumber);
                break;
            case PORTB_GPIO:
            	__SET_BIT(GPIO_B->GPIOx_BSRR, Copy_u8PinNumber);
                break;
            case PORTC_GPIO:
            	__SET_BIT(GPIO_C->GPIOx_BSRR, Copy_u8PinNumber);
                break;
            case PORTD_GPIO:     
            	__SET_BIT(GPIO_D->GPIOx_BSRR, Copy_u8PinNumber);
                break;
            case PORTE_GPIO:     
            	__SET_BIT(GPIO_E->GPIOx_BSRR, Copy_u8PinNumber);
                break;
            default:
                break;
        }
    }
    else if (Copy_u8State == LOW)
    {
        switch(Copy_u8PortName)
        {
            case PORTA_GPIO:     
            	__CLR_BIT(GPIO_A->GPIOx_BSRR, Copy_u8PinNumber);
            	__SET_BIT(GPIO_A->GPIOx_BSRR,(Copy_u8PinNumber+16));
                break;
            case PORTB_GPIO:     
            	__CLR_BIT(GPIO_B->GPIOx_BSRR, Copy_u8PinNumber);
            	__SET_BIT(GPIO_B->GPIOx_BSRR,(Copy_u8PinNumber+16));
                break;
            case PORTC_GPIO:
            	__CLR_BIT(GPIO_C->GPIOx_BSRR, Copy_u8PinNumber);
            	__SET_BIT(GPIO_C->GPIOx_BSRR,(Copy_u8PinNumber+16));
                break;  
            case PORTD_GPIO:
            	__CLR_BIT(GPIO_D->GPIOx_BSRR, Copy_u8PinNumber);
            	__SET_BIT(GPIO_D->GPIOx_BSRR,(Copy_u8PinNumber+16));
                break;
            case PORTE_GPIO:
            	__CLR_BIT(GPIO_E->GPIOx_BSRR, Copy_u8PinNumber);
            	__SET_BIT(GPIO_E->GPIOx_BSRR,(Copy_u8PinNumber+16));
                break;
            default:
                break;
        }
    }
    else
    {
        //nothing
    }  
}
void M_GPIO_void_WritePinBRR(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    
    switch(Copy_u8PortName)
    {
        case PORTA_GPIO:     
            GPIO_A->GPIOx_BRR = 1<<(Copy_u8PinNumber);
            break;
        case PORTB_GPIO:     
            GPIO_B->GPIOx_BRR = 1<<(Copy_u8PinNumber);
            break;
        case PORTC_GPIO:     
            GPIO_C->GPIOx_BRR = 1<<(Copy_u8PinNumber);
            break;  
        case PORTD_GPIO:     
            GPIO_D->GPIOx_BRR = 1<<(Copy_u8PinNumber);
            break;
        case PORTE_GPIO:     
            GPIO_E->GPIOx_BRR = 1<<(Copy_u8PinNumber);
            break;
        default:
            break;
    }

}

void M_GPIO_void_LockPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    switch(Copy_u8PortName)
    {
        case PORTA_GPIO:     
            __SET_BIT(GPIO_A->GPIOx_LCKR,Copy_u8PinNumber);
            break;
        case PORTB_GPIO:     
            __SET_BIT(GPIO_B->GPIOx_LCKR,Copy_u8PinNumber);
            break;
        case PORTC_GPIO:     
            __SET_BIT(GPIO_C->GPIOx_LCKR,Copy_u8PinNumber);
            break;
        case PORTD_GPIO:     
            __SET_BIT(GPIO_D->GPIOx_LCKR,Copy_u8PinNumber);
            break;
        case PORTE_GPIO:     
            __SET_BIT(GPIO_E->GPIOx_LCKR,Copy_u8PinNumber);
            break;
        default:
            break;
    }
    __SET_BIT(GPIO_E->GPIOx_LCKR,16);
    while(__GET_BIT(GPIO_E->GPIOx_LCKR,16) == 0);   // to ensure the lock is active
}
void M_GPIO_void_InputPullUp_PullDown(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8State_Pull)
{
	if(Copy_u8State_Pull == PULL_UP)
	    {
	        switch(Copy_u8PortName)
	        {
	            case PORTA_GPIO:
	                __SET_BIT(GPIO_A->GPIOx_ODR,Copy_u8PinNumber);
	                break;
	            case PORTB_GPIO:
	                __SET_BIT(GPIO_B->GPIOx_ODR,Copy_u8PinNumber);
	                break;
	            case PORTC_GPIO:
	                __SET_BIT(GPIO_C->GPIOx_ODR,Copy_u8PinNumber);
	                break;
	            case PORTD_GPIO:
	                __SET_BIT(GPIO_D->GPIOx_ODR,Copy_u8PinNumber);
	                break;
	            case PORTE_GPIO:
	                __SET_BIT(GPIO_E->GPIOx_ODR,Copy_u8PinNumber);
	                break;
	            default:
	                break;
	        }
	    }
	    else if (Copy_u8State_Pull == PULL_DOWN)
	    {
	        switch(Copy_u8PortName)
	        {
	            case PORTA_GPIO:
	                __CLR_BIT(GPIO_A->GPIOx_ODR,Copy_u8PinNumber);
	                break;
	            case PORTB_GPIO:
	                __CLR_BIT(GPIO_B->GPIOx_ODR,Copy_u8PinNumber);
	                break;
	            case PORTC_GPIO:
	                __CLR_BIT(GPIO_C->GPIOx_ODR,Copy_u8PinNumber);
	                break;
	            case PORTD_GPIO:
	                __CLR_BIT(GPIO_D->GPIOx_ODR,Copy_u8PinNumber);
	                break;
	            case PORTE_GPIO:
	                __CLR_BIT(GPIO_E->GPIOx_ODR,Copy_u8PinNumber);
	                break;
	            default:
	                break;
	        }
	    }
	    else
	    {
	        //nothing
	    }
}
