/*
 * 
 *  NAME : GPIO_PRIVATE.H
 *  CREATE : 6/9/2024
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 * 
 */
#ifndef GPIO_PRIVATE_H 
#define GPIO_PRIVATE_H

#include "Std.h"

#define   GPIOA_BASE_ADDRESS        0X40010800 
#define   GPIOB_BASE_ADDRESS        0X40010C00  
#define   GPIOC_BASE_ADDRESS        0X40011000  
#define   GPIOD_BASE_ADDRESS        0X40011400  
#define   GPIOE_BASE_ADDRESS        0X40011800  

typedef struct 
{
    volatile u32 GPIOx_CRL;
    volatile u32 GPIOx_CRH;
    volatile u32 GPIOx_IDR;
    volatile u32 GPIOx_ODR;
    volatile u32 GPIOx_BSRR;
    volatile u32 GPIOx_BRR;
    volatile u32 GPIOx_LCKR;

    
}GPIOx_Tdef;

#define GPIO_A    ((volatile GPIOx_Tdef*)GPIOA_BASE_ADDRESS)
#define GPIO_B    ((volatile GPIOx_Tdef*)GPIOB_BASE_ADDRESS)
#define GPIO_C    ((volatile GPIOx_Tdef*)GPIOC_BASE_ADDRESS)
#define GPIO_D    ((volatile GPIOx_Tdef*)GPIOD_BASE_ADDRESS)
#define GPIO_E    ((volatile GPIOx_Tdef*)GPIOE_BASE_ADDRESS)


#endif
