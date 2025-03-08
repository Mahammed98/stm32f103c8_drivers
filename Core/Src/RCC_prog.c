/*
 * 
 *  NAME : RCC_PROG.C
 *  CREATE : 29/8/2024
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 * 
 */
#include "RCC_interface.h"

void M_RCC_Void_EnableClock(BusName_t Copy_BusType, u8 Copy_PrephralNumber)
{
    switch (Copy_BusType)
    {
        case AHB1:     
            __SET_BIT(RCC_AHBENR, Copy_PrephralNumber);
            break;
        case APB1:     
        	__SET_BIT(RCC_APB1ENR, Copy_PrephralNumber);
            break;
        case APB2:     
        	__SET_BIT(RCC_APB2ENR, Copy_PrephralNumber);
            break;
        default:   /* error */
            break;
    }
}

void M_RCC_Void_DisableClock(BusName_t Copy_BusType, u8 Copy_PrephralNumber)
{
    switch (Copy_BusType)
    {
        case AHB1:     
        	__CLR_BIT(RCC_AHBENR, Copy_PrephralNumber);
            break;
        case APB1:     
        	__CLR_BIT(RCC_APB1ENR, Copy_PrephralNumber);
            break;
        case APB2:     
        	__CLR_BIT(RCC_APB2ENR, Copy_PrephralNumber);
            break;
        default:    /* error */
            break;
    }
}

void M_RCC_Void_EnableSecuritySystem(void)
{
	__SET_BIT(RCC_CR, CSSON);
}

void M_RCC_Void_DisableSecuritySystem(void)
{
	__CLR_BIT(RCC_CR, CSSON);
}


void M_RCC_Void_ClkSourceInit(void)
{
    #if     CLK_SOURCE      ==     RCC_HSI  
        __SET_BIT(__RCC->CR, HSION);   // enable HSI
        while(__GET_BIT(__RCC->CR, HSIRDY) == 0);     // polling while HSE Frequance is stable
        __CLR_BIT(__RCC->CFGR,SW0);
        __CLR_BIT(__RCC->CFGR,SW1);
    #elif   CLK_SOURCE      ==     RCC_HSE
        __SET_BIT(__RCC->CR, HSEON);   // enable HSE
        while(__GET_BIT(__RCC->CR, HSERDY) == 0);     // polling while HSE Frequance is stable
        #if       HSE_SOURCE    ==    HSE_Crystal   
        __CLR_BIT(__RCC->CR,HSEBYP);   // disable bypasse mode
        #elif     HSE_SOURCE    ==    HSE_RC 
            __SET_BIT(__RCC->CR,HSEBYP);      // enalbe bypasse mode
        #endif
        /* select HSE as system clock */
            __SET_BIT(__RCC->CFGR,SW0);
            __CLR_BIT(__RCC->CFGR,SW1);
    #elif   CLK_SOURCE      ==     RCC_PLL
        __SET_BIT(__RCC->CR, PLLON);        // enable PLL
        /* select PLL as system clock */
        __CLR_BIT(__RCC->CFGR,SW0);
        __SET_BIT(__RCC->CFGR,SW1);
        #if       PLL_SOURCE    ==    HSE_PLL
        __SET_BIT(__RCC->CR, HSEON);   // enable HSE
        __SET_BIT(__RCC->CFGR, PLL_SRC);    // choose HSE input on PLL
        #elif      PLL_SOURCE    ==    HSI_PLL 
        __SET_BIT(__RCC->CR, HSION);   // enable HSI
        __CLR_BIT(__RCC->CFGR, PLL_SRC);    // choose HSI input on PLL
        #endif
            __RCC->CFGR |= (PLL_MUL<<18);
    #endif
}
