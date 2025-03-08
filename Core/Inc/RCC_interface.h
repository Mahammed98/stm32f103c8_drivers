/*
 * 
 *  NAME : RCC_INTERFACE.H
 *  CREATE : 29/8/2024
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 * 
 */
#ifndef RCC_INTERFACE_H 
#define RCC_INTERFACE_H

#include "BitMath.h"
#include "RCC_private.h"
#include "RCC_config.h" 
/*******************************************************    MACROS *************************************************************/
////////////////////////////// FOR PREBUILD CONFIGURATION  //////////////////////////////
#define RCC_HSI      0
#define RCC_HSE      1
#define RCC_PLL      2

#define HSE_Crystal  0
#define HSE_RC       1

#define HSE_PLL      0
#define HSI_PLL      1 

#define PLLMUL_X_2   0
#define PLLMUL_X_3   1



typedef enum {

    AHB1 = 0,
    APB1,
    APB2
}BusName_t;

/*
    Enabale and Disable clock to specifice prepheral,
    you must determine bus name which this prepheral on it, and prepheral number 
*/
void M_RCC_Void_EnableClock(BusName_t Copy_BusType, u8 Copy_PrephralNumber);   
void M_RCC_Void_DisableClock(BusName_t Copy_BusType, u8 Copy_PrephralNumber);
/*   
    enable and disable CSS bin which specifiy for controlling clock source for the system 
    if we run on HSE and frequance is changed from some reason, so CSS wiil change clock source from HSE to HSI 
*/
void M_RCC_Void_EnableSecuritySystem(void);
void M_RCC_Void_DisableSecuritySystem(void);

void M_RCC_Void_ClkSourceInit(void);             //to initilizaed clock for mcu

#endif
