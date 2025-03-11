/*
 *
 *  NAME : DMA_INTERFACE.H
 *  CREATE : 3/8/2025
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 *
 */
#ifndef DMA_INTERFACE
#define DMA_INTERFACE
///////////////////////////////////////////////include files ///////////////////////////////////
#include "BitMath.h"
#include "Std.h"
#include "DMA_config.h"
#include "DMA_private.h"
/******************************************** MACROS *************************************/
/*  DMA MODES */
#define MEMORY_TO_MEMORY_MODE    		 1
#define CIRCULAR_MODE			 		 2
/* DMA DIRECTION */
#define READ_FROM_MEMORY    	 		 1
#define READ_FROM_PERIPHERAL			 2
/*  DMA PERIPHERAL SIZE AT ONE TRANSFERRING */
#define PERIPHERAL_SIZE_8_BIT    		 0
#define PERIPHERAL_SIZE_16_BIT			 1
#define PERIPHERAL_SIZE_32_BIT   		 2
/*  DMA MEMORY SIZE AT ONE TRANSFERRING */
#define MEMORY_SIZE_8_BIT			 	 0
#define MEMORY_SIZE_16_BIT    		 	 1
#define MEMORY_SIZE_32_BIT			 	 2
/* DMA PRIORITY LEVELS */
#define CHANNEL_PRIORITY_LOW    		 0
#define CHANNEL_PRIORITY_MEDIUM    		 1
#define CHANNEL_PRIORITY_HIGH			 2
#define CHANNEL_PRIORITY_VERYHIGH    	 3



/*********************************** PROTOTYPES *****************************************/
void M_DMA_void_Init(u8 Copy_ChannalNum, u8 Copy_Dma_Mode, u8 Copy_Dma_Dir, u8 Copy_Dma_PSize, u8 Copy_Dma_MSize, u8 Copy_ChPriority);  // to initialize DMA, input channel number
void M_DMA_void_SendData(u8 Copy_ChannalNum, volatile u32 *Copy_MA, volatile u32 *Copy_PA, u16 Copy_size);    // for DMA to be ready for transferring data
void M_DMA_void_EnableDma(u8 Copy_ChannalNum);                                            // enable DMA
void M_DMA_void_disableDma(u8 Copy_ChannalNum);                                           // disable DMA
u8 M_DMA_u8_ReadTransferCompleteFlag(u8 Copy_Channel);									  // read transfer complete flag
void M_DMA_void_ClearTransferCompleteFlag(u8 Copy_Channel);								  // clear TC flag
void M_DMA_void_SetCallBack(void(*Copy_Ptr)(void), u8 Copy_Channel_Num);
#endif
