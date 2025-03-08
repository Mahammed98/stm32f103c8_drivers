/*
 *
 *  NAME : EXTI_INTERFACE.H
 *  CREATE : 2/2/2024
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 *
 *                                           STEPS FOR ENABLE EXTERNAL INTERRUPT
 *
 *
 *       1- SET GPIO PORT AND PINS MODE
 *       	- M_GPIO_void_SetPinMode(PORTA_GPIO, 1, INPUT, INPUT_PULL_UP_DOWN);
 *          - M_GPIO_void_InputPullUp_PullDown(PORTA_GPIO,0,PULL_UP);
 *       2- SET CLOCK FOR AFIO REGISTER (APB2 BUS)
 *       	- M_RCC_Void_EnableClock(APB2,AFIOEN);
 *       3- EXTI INITILIZATION
 *          - M_EXTI_void_SelectExtPin(PORTA_GPIO,1);
 *	  	    - M_EXTI_void_EnableLine(1);
 * 	  	    - M_EXTI_void_EventType(1, __FULLING_EDGE__);
 * 	  	  	- M_EXTI_void_SetCallBack(App_void_ToggleLed);
 * 	  	 4-  NVIC  INITILIZATION
 *			- NVIC_SetPriority(EXTI1_IRQn, 1);
 * 	  	  	- __enable_irq();
 *	 	 	- NVIC_EnableIRQ(EXTI1_IRQn);
 *
 */
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "EXTI_private.h"
#include "EXTI_config.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"

#define  __RISING_EDGE__  0U
#define  __FULLING_EDGE__ 1U
#define  __ON_CHANGING__  2U
/************************************
 *
 *
 * Functions Prototype
 *
 *
 ***********************************/
void M_EXTI_void_EnableLine(u8 Local_LineNum);       // to enable external interrupt specific line
void M_EXTI_void_DisablLine(u8 Local_LineNum);		// to disable external interrupt specific line
void M_EXTI_void_SelectExtPin(u8 Local_PortNum, u8 Local_PinNum);
void M_EXTI_void_EventType(u8 Local_LineNum, u8 Local_EventType);     // select event type (rising or falling or on changing)
void M_EXTI_void_TriggSW(u8 Local_LineNum);     // enable Software trigger (if you don't use a push button)(simulate push button)
void M_EXTI_void_ClearSWT(u8 Local_LineNum);       // clear software trigger

void M_EXTI_void_SetCallBack(void(*ptr)(void));       // call back function for interrupt handler


#endif
