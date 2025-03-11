#include "DMA_interface.h"

static void (*Dma_Ptr[7])(void);         // for call back function


void M_DMA_void_Init(u8 Copy_ChannalNum, u8 Copy_Dma_Mode, u8 Copy_Dma_Dir, u8 Copy_Dma_PSize, u8 Copy_Dma_MSize, u8 Copy_ChPriority)
{
	/*         SELCET MODE (MTM OR CIRCULAR)		 */
	if(Copy_Dma_Mode == MEMORY_TO_MEMORY_MODE)
	{
		__SET_BIT(__DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR, 14);
	}
	else if(Copy_Dma_Mode == CIRCULAR_MODE)
	{
		__SET_BIT(__DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR, 5);
	}
	else
	{
		//nothing
	}
	/*         SELCET DIRECTION (READ FROM MEMORY OR READ FROM PERIPHERAL)		 */
	if(Copy_Dma_Dir == READ_FROM_MEMORY)
	{
		__SET_BIT(__DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR, 4);
	}
	else if(Copy_Dma_Dir == READ_FROM_PERIPHERAL)
	{
		__CLR_BIT(__DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR, 4);
	}
	else
	{
			//nothing
	}

	/*       SELECT PERIPHERAL SIZE FOR EACH TREANSFERRING     */
	switch(Copy_Dma_PSize)
	{
		case PERIPHERAL_SIZE_8_BIT: __DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR |= (PERIPHERAL_SIZE_8_BIT << 8);	break;
		case PERIPHERAL_SIZE_16_BIT: __DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR |= (PERIPHERAL_SIZE_16_BIT << 8);	break;
		case PERIPHERAL_SIZE_32_BIT: __DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR |= (PERIPHERAL_SIZE_32_BIT << 8);	break;
		default: break;
	}
	/*       SELECT MEMORY SIZE FOR EACH TREANSFERRING       */
	switch(Copy_Dma_MSize)
	{
		case MEMORY_SIZE_8_BIT: __DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR |= (MEMORY_SIZE_8_BIT << 10);	break;
		case MEMORY_SIZE_16_BIT: __DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR |= (MEMORY_SIZE_16_BIT << 10);	break;
		case MEMORY_SIZE_32_BIT: __DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR |= (MEMORY_SIZE_32_BIT << 10);	break;
		default: break;
	}
	/*       SELECT THE PRIORITY OF CHANNEL       */
	switch(Copy_ChPriority)
	{
		case CHANNEL_PRIORITY_LOW: __DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR |= (CHANNEL_PRIORITY_LOW << 12);	break;
		case CHANNEL_PRIORITY_MEDIUM: __DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR |= (CHANNEL_PRIORITY_MEDIUM);	break;
		case CHANNEL_PRIORITY_HIGH: __DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR |= (CHANNEL_PRIORITY_HIGH << 12);	break;
		case CHANNEL_PRIORITY_VERYHIGH: __DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR |= (CHANNEL_PRIORITY_VERYHIGH << 12);	break;
		default: break;
	}
	/* 		ENABLE PERIPHERAL INCREAMENT */
	__SET_BIT(__DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR, 6);

	/*  	ENABLE MEMORY INCREAMNET */
	__SET_BIT(__DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR, 7);

	/* 		Enable Transfer complete interrupt */
	__SET_BIT(__DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR, 1);
}

void M_DMA_void_SendData(u8 Copy_ChannalNum, volatile u32 *Copy_SourceA, volatile u32 *Copy_DistA, u16 Copy_size)
{
	/* 		set peripheral address (SOURCE)		 */
	__DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CPAR = (u32)Copy_SourceA;
	/* 		set memory address    (DISTENATION)		 */
	__DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CMAR = (u32)Copy_DistA;
	/*     set block of data size (max 65535).       */
	__DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CNDTR = Copy_size;
}
void M_DMA_void_EnableDma(u8 Copy_ChannalNum)
{

	__SET_BIT(__DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR, 0);
}
void M_DMA_void_disableDma(u8 Copy_ChannalNum)
{
	__CLR_BIT(__DMA1->DMA_CR[Copy_ChannalNum-1].DMA_CCR, 0);
}
u8 M_DMA_u8_ReadTransferCompleteFlag(u8 Copy_Channel)
{
	return __GET_BIT(__DMA1->DMA_ISR, ((4*Copy_Channel)-3));
}
void M_DMA_void_ClearTransferCompleteFlag(u8 Copy_Channel)
{
	__SET_BIT(__DMA1->DMA_IFCR, ((4*Copy_Channel)-3));       // CLEAR TC FOR CHANNEL
	__SET_BIT(__DMA1->DMA_IFCR, ((4*Copy_Channel)-4));	   // CLEAR GIF(GLOBAL FLAG FOR TE, HT, AND TC) FOR CHANNEL

}
/*
 * 				NOTE : TE, HT, and TC have a same interrupt handler for specific channel
 * 					so, if you enable two or three for these interrupts,
 * 					you must check the flags at the DMAx_handler for each interrupt type
 *
 */
void M_DMA_void_SetCallBack(void(*Copy_Ptr)(void), u8 Copy_Channel_Num)
{
	Dma_Ptr[Copy_Channel_Num-1] = Copy_Ptr;

}
void DMA1_Channel1_IRQHandler()
{
	Dma_Ptr[0]();
}
void DMA1_Channel2_IRQHandler()
{
	Dma_Ptr[1]();
}
void DMA1_Channel3_IRQHandler()
{
	Dma_Ptr[2]();
}
void DMA1_Channel4_IRQHandler()
{
	Dma_Ptr[3]();
}
void DMA1_Channel5_IRQHandler()
{
	Dma_Ptr[4]();
}
void DMA1_Channel6_IRQHandler()
{
	Dma_Ptr[5]();
}
void DMA1_Channel7_IRQHandler()
{
	Dma_Ptr[6]();
}




