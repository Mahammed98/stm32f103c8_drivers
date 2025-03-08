/*
 *
 *  NAME : SYSTICK_INTERFACE.H
 *  CREATE : 2/10/2025
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 *
 */
#ifndef SYSTICK_INTERFACE
#define SYSTICK_INTERFACE
///////////////////////////////////////////////include files ///////////////////////////////////
#include "bitMath.h"
#include "Std.h"
#include "SysTick_private.h"
#include "SysTick_config.h"

/******************************************** MACROS *************************************/
#define SYSTICK_CLK_AHB_8   0U
#define SYSTICK_CLK_AHB     1U

/*********************************** PROTOTYPES *****************************************/
void M_SysTick_void_Init(void);       // initialization of systick timer
void M_SysTick_DelayUs(u32 Copy_u32_Time_Us);
void M_SysTick_DelayMs(u32 Copy_u32_Time_Ms);           // MAX DELAY IN MS ARE 16700 MS
void M_SysTick_voidSetIntervalPeriodic(u32 Copy_u32_Ticks, void(*Copy_Ptr)(void));
void M_SysTick_voidSetIntervalSingle(u32 Copy_u32_Ticks, void(*Copy_Ptr)(void));
#endif
