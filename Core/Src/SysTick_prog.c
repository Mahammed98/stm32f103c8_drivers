#include "SysTick_interface.h"

static void (*SysTick_CallBack_Ptr)(void);
static u8 SysTick_Interval_Mode;

/********************************** functions body ***********************************/
void M_SysTick_void_Init(void)
{
	/* disable systick interrupt, disable systick , and enable systick clk*/
	#if   SYSTICK_CLK    ==   SYSTICK_CLK_AHB_8
		__SYSTICK->STK_CTRL = 0;
	#elif   SYSTICK_CLK    ==   SYSTICK_CLK_AHB
		__SYSTICK->STK_CTRL = 0X00000004;
	#endif
}
void M_SysTick_DelayUs(u32 Local_Time_Us)
{
	u32 Local_Overflow_Time = 0;
	f32 Local_CountF = 0.0;
	#if   SYSTICK_CLK    ==   SYSTICK_CLK_AHB_8
		Local_Overflow_Time = SYSTICK_REG_RESOLUTION * 1U;
	#elif   SYSTICK_CLK    ==   SYSTICK_CLK_AHB
		/*
		 * TICK_TIME = PRE/FCLK --> no prescalar, so tick_time = 1/8000000  = 0.125us
		 *
		 *                           (/ 8U) = (* 0.125)
		 */
		Local_Overflow_Time = SYSTICK_REG_RESOLUTION / 8U;
	#endif
	Local_CountF = (f32)Local_Time_Us / Local_Overflow_Time;
	__SYSTICK->STK_LOAD = ((f32)Local_CountF * SYSTICK_REG_RESOLUTION)-1U;
	__SET_BIT(__SYSTICK->STK_CTRL,__ENABLE);     // enable systick timer
	while(!__GET_BIT(__SYSTICK->STK_CTRL,__COUNTFLAG));
	__CLR_BIT(__SYSTICK->STK_CTRL,__ENABLE);     // disabble systick timer
	__SYSTICK->STK_LOAD = 0;
	__SYSTICK->STK_VAL = 0;        // CLEAR SYSTICK FLAG

}
void M_SysTick_DelayMs(u32 Local_Time_Ms)
{
	u32 Local_Overflow_Time = 0;
	f32 Local_CountF = 0.0;
	#if   SYSTICK_CLK    ==   SYSTICK_CLK_AHB_8
		Local_Overflow_Time = SYSTICK_REG_RESOLUTION * 1U;
	#elif   SYSTICK_CLK    ==   SYSTICK_CLK_AHB
		/*
		 * TICK_TIME = PRE/FCLK --> no prescalar, so tick_time = 1/8000000  = 0.125us
		 *
		 *                           (/ 8U) = (* 0.125)
		 */
		Local_Overflow_Time = SYSTICK_REG_RESOLUTION / 8U;
	#endif
	Local_CountF = (f32)(Local_Time_Ms*1000) / Local_Overflow_Time;
	__SYSTICK->STK_LOAD = ((f32)Local_CountF * SYSTICK_REG_RESOLUTION)-1U;
	__SET_BIT(__SYSTICK->STK_CTRL,__ENABLE);     // enable systick timer
	while(!__GET_BIT(__SYSTICK->STK_CTRL,__COUNTFLAG));
	__CLR_BIT(__SYSTICK->STK_CTRL,__ENABLE);     // disable systick timer
	__SYSTICK->STK_LOAD = 0;
	__SYSTICK->STK_VAL = 0;        // CLEAR SYSTICK FLAG
}
/************************************************************ interrupt functions ***********************************************************************/
void M_SysTick_voidSetIntervalPeriodic(u32 Copy_u32_Ticks, void(*Copy_Ptr)(void))
{
	/* load value to load register */
	__SYSTICK->STK_LOAD = Copy_u32_Ticks;
	/* save call back */
	SysTick_CallBack_Ptr = Copy_Ptr;
	/* Set mode to periodic */
	SysTick_Interval_Mode = SYSTICK_PERIODIC;
	/* enable systick interrupt */
	__SET_BIT(__SYSTICK->STK_CTRL,__TICKINT);     // enable systick timer
	/* enable systick */
	__SET_BIT(__SYSTICK->STK_CTRL,__ENABLE);     // enable systick timer
}
void M_SysTick_voidSetIntervalSingle(u32 Copy_u32_Ticks, void(*Copy_Ptr)(void))
{
	/* load value to load register */
	__SYSTICK->STK_LOAD = Copy_u32_Ticks;
	/* save call back */
	SysTick_CallBack_Ptr = Copy_Ptr;
	/* Set mode to single */
	SysTick_Interval_Mode = SYSTICK_SINGLE;
	/* enable systick interrupt */
	__SET_BIT(__SYSTICK->STK_CTRL,__TICKINT);     // enable systick timer
	/* enable systick */
	__SET_BIT(__SYSTICK->STK_CTRL,__ENABLE);     // enable systick timer
}

void SysTick_Handler(void)
{
	/* call function which sit at app layer */
	SysTick_CallBack_Ptr();
	if(SysTick_Interval_Mode == SYSTICK_SINGLE)
	{
		__CLR_BIT(__SYSTICK->STK_CTRL,__TICKINT);     // disable systick interrupt
		__CLR_BIT(__SYSTICK->STK_CTRL,__ENABLE);     // disable systick timer
		__SYSTICK->STK_LOAD = 0;
		__SYSTICK->STK_VAL = 0;        // CLEAR SYSTICK FLAG
	}
	__SYSTICK->STK_VAL = 0;        // to CLEAR SYSTICK FLAG
	//Local_Temp = __GET_BIT(__SYSTICK->STK_CTRL,__COUNTFLAG);         // to CLEAR SYSTICK FLAG
}
