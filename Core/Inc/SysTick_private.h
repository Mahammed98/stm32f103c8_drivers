/*
 *
 *  NAME : SYSTICK_PRIVATE.H
 *  CREATE : 2/10/2025
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 *
 */
#ifndef SYSTICK_PRIVATE
#define SYSTICK_PRIVATE

#define  SYSTICK_BASE_ADDRESS       			  0xE000E010
#define  SYSTICK_REG_RESOLUTION                   16777216U

#define  SYSTICK_PERIODIC      0U
#define  SYSTICK_SINGLE        1U
typedef struct
{
	volatile u32 STK_CTRL;
	volatile u32 STK_LOAD;
	volatile u32 STK_VAL;
	volatile u32 STK_CALIB;

}SysTick_Tdef;

#define __SYSTICK  ((volatile SysTick_Tdef *)SYSTICK_BASE_ADDRESS)

/******************************************* STK_CTRL *************************************/
#define  __COUNTFLAG       16
#define  __CLKSOURCE    	2
#define  __TICKINT      	1
#define  __ENABLE       	0


#endif
