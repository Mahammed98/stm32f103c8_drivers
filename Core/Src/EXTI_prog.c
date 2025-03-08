#include "EXTI_interface.h"

static void (*Call_Back_Ptr)(void);
/****************************************************************************************************/
/****************************************************************************************************/
void M_EXTI_void_EnableLine(u8 Local_LineNum)
{
	__SET_BIT(__EXTIR->EXTI_IMR_REG, Local_LineNum);
}
///////////////////////////////////////////////////////////////////////////////////////////
void M_EXTI_void_DisablLine(u8 Local_LineNum)
{
	__CLR_BIT(__EXTIR->EXTI_IMR_REG, Local_LineNum);
}
/////////////////////////////////////////////////////////////////////////////////////////////
void M_EXTI_void_SelectExtPin(u8 Local_PortNum, u8 Loca_PinNum)
{
	M_AFIO_void_SetPin_ALFExt(Local_PortNum, Loca_PinNum);
}
/////////////////////////////////////////////////////////////////////////////////////////////

void M_EXTI_void_EventType(u8 Local_LineNum, u8 Local_EventType)
{
	switch(Local_EventType)
	{
		case __RISING_EDGE__:
			__SET_BIT(__EXTIR->EXTI_RTSR_REG, Local_LineNum);
			__CLR_BIT(__EXTIR->EXTI_FTSR_REG, Local_LineNum);
			break;
		case __FULLING_EDGE__:
			__SET_BIT(__EXTIR->EXTI_FTSR_REG, Local_LineNum);
			__CLR_BIT(__EXTIR->EXTI_RTSR_REG, Local_LineNum);
			break;
		case __ON_CHANGING__:
			__SET_BIT(__EXTIR->EXTI_RTSR_REG, Local_LineNum);
			__SET_BIT(__EXTIR->EXTI_FTSR_REG, Local_LineNum);
			break;
		default: break;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////

void M_EXTI_void_TriggSW(u8 Local_LineNum)
{
	__SET_BIT(__EXTIR->EXTI_SWIER_REG, Local_LineNum);
}
/////////////////////////////////////////////////////////////////////////////////////////////

void M_EXTI_void_ClearSWT(u8 Local_LineNum)
{
	__SET_BIT(__EXTIR->EXTI_PR_REG, Local_LineNum);

}
////////////////////////////////////// interrupt ///////////////////////////////////////////////////////
void M_EXTI_void_SetCallBack(void(*ptr)(void))
{
	Call_Back_Ptr = ptr;

}

void EXTI1_IRQHandler()
{
	Call_Back_Ptr();
}


