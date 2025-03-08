/*
 * 
 *  NAME : RCC_PRIVATE.H
 *  CREATE : 29/8/2024
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 * 
 */
#ifndef RCC_PRIVATE_H 
#define RCC_PRIVATE_H

#include "Std.h"
///////////////////////////////////// BASE ADDRESS //////////////////////////////////////////
#define         RCC_BASE_ADDRESS           0x40021000

///////////////////////////////////// RCC REGISTERS /////////////////////////////////////////
#define         RCC_CR                     (*((volatile u32*)(RCC_BASE_ADDRESS + 0x00)))
#define         RCC_CFGR                   (*((volatile u32*)(RCC_BASE_ADDRESS + 0x04)))
#define         RCC_CIR                    (*((volatile u32*)(RCC_BASE_ADDRESS + 0x08)))
#define         RCC_APB2RSTR               (*((volatile u32*)(RCC_BASE_ADDRESS + 0x0c)))
#define         RCC_APB1RSTR               (*((volatile u32*)(RCC_BASE_ADDRESS + 0x10)))
#define         RCC_AHBENR                 (*((volatile u32*)(RCC_BASE_ADDRESS + 0x14)))
#define         RCC_APB2ENR                (*((volatile u32*)(RCC_BASE_ADDRESS + 0x18)))
#define         RCC_APB1ENR                (*((volatile u32*)(RCC_BASE_ADDRESS + 0x1c)))
#define         RCC_BDCR                   (*((volatile u32*)(RCC_BASE_ADDRESS + 0x20)))
#define         RCC_CSR                    (*((volatile u32*)(RCC_BASE_ADDRESS + 0x24)))
#define         RCC_CFGR2                  (*((volatile u32*)(RCC_BASE_ADDRESS + 0x2c)))


typedef struct rcc_tdef{
   volatile  u32 CR;
   volatile  u32 CFGR;
   volatile  u32 CIR;
   volatile  u32 APB2RSTR;
   volatile  u32 APB1RSTR;
   volatile  u32 AHBENR;
   volatile  u32 APB2ENR;
   volatile  u32 APB1ENR;
   volatile  u32 BDCR;
   volatile  u32 CSR;
   volatile  u32 RESERVED1;
   volatile  u32 CFGR2;
} RCC_Tdef;

#define  __RCC            ((volatile struct rcc_tdef*)RCC_BASE_ADDRESS)

////////////////// RCC_AHBENR register bits  ///////////////////////
#define DMA2EN           1
#define SRAMEN           2
#define FLITFEN          4
#define CRCEN            6
#define FSMCEN           8
////////////////// RCC_APB2ENR register bits  ///////////////////////
#define AFIOEN           0
#define IOPAEN           2
#define IOPBEN           3
#define IOPCEN           4
#define IOPDEN           5
#define IOPEEN           6
#define IOPFEN           7
#define IOPGEN           8
#define ADC1EN           9
#define TIM1EN           11
#define SPI1EN           12
#define USART1EN         14
#define TIM15EN          16
#define TIM16EN          17
#define TIM17EN          18
////////////////// RCC_APB1ENR register bits  ///////////////////////
#define TIM2EN           0
#define TIM3EN           1
#define TIM4EN           2
#define TIM5EN           3
#define TIM6EN           4
#define TIM7EN           5
#define TIM12EN          6
#define TIM13EN          7
#define TIM14EN          8
#define WWDGEN           11
#define SPI2EN           14
#define SPI3EN           15
#define USART2EN         17
#define USART3EN         18
#define UART4EN          19
#define UART5EN          20
#define I2C1EN           21
#define I2C2EN           22
#define BKPEN            27
#define PWREN            28
#define DACEN            29
#define CECEN            30
////////////////// RCC_CR register bits  ///////////////////////
#define HSION            0        // to enable HSI
#define HSIRDY           1        // to ensure that clock source is stable
/* 
    these five bits are specified for canceling errors occured due to variations 
    in voltage and temperature to HSI clock source, by deualt it has (10000) 16
    which mean 16MHz it's a value of internal Ocilator, if clock being 16Mhz + 80KHz
    we must decrement these four bits by 2 to be 16MHz pure,(each decrement bit = 40KHz)
*/
#define HSITRIM1         3        
#define HSITRIM2         4
#define HSITRIM3         5
#define HSITRIM4         6
#define HSITRIM5         7
/*
    if clock being 16Mhz + 90KHz, we will decrement 2 bits, it will be 16 + 10KHz
    so this 10 remains will canceling by these 8 bits (its read only can't write on it)
*/
#define HSICAL1          8
#define HSICAL2          9
#define HSICAL3          10
#define HSICAL4          11
#define HSICAL5          12
#define HSICAL6          13
#define HSICAL7          14
#define HSICAL8          15
#define HSEON            16      // to enable HSE
#define HSERDY           17      // to ensure that clock source is stable
#define HSEBYP           18      // to enable bypass on xtal1 pin when using HSE with RC circuit
#define CSSON            19      // it is controlling clock source if HSE is failure, HSi while running instead of it 
#define PLLON            24      // to enable PLL
#define PLLRDY           25      // to ensure that clock source is stable

////////////////// RCC_CFGR register bits  ///////////////////////
#define SW0              0
#define SW1              1
#define SWS0             2
#define SWS1             3
#define HPRE0            4
#define HPRE1            5
#define HPRE2            6
#define HPRE3            7
#define PPRE1_0          8
#define PPRE1_1          9
#define PPRE1_2          10
#define PPRE2_0          11
#define PPRE2_1          12
#define PPRE2_2          13
#define ADC_PRE0         14
#define ADC_PRE1         15
#define PLL_SRC          16
#define PLL_XTPRE        17
#define PLLMUL0          18     // PLL multiplication factor
#define PLLMUL1          19
#define PLLMUL2          20
#define PLLMUL3          21
#define MCO0             24     //Microcontroller clock output
#define MCO1             25
#define MCO2             26
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
