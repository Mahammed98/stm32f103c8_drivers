/*
 * 
 *  NAME : RCC_CONFIG.H
 *  CREATE : 29/8/2024
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 * 
 */
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H
/*
    choose clk source from one of them
        1- RCC_HSI
        2- RCC_HSE
        3- RCC_PLL
*/
#define CLK_SOURCE        RCC_HSE
/*
    choose HSE source from one of them 
        1- HSE_Crystal
        2- HSE_RC
*/
#define HSE_SOURCE        HSE_Crystal
/*
    choose PLL source from one of them
        1- HSE_PLL
        2- HSI_PLL
*/
#define PLL_SOURCE        HSE_PLL
/*
    choose PLL multiplication frequanc
        1- PLLMUL_X_2
        2- PLLMUL_X_3
*/
#define PLL_MUL           PLLMUL_X_2
#endif
