/*
 *
 *  NAME : DMA_PRIVATE.H
 *  CREATE : 3/8/2025
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 *
 */
#ifndef DMA_PRIVATE
#define DMA_PRIVATE

#define  DMA1_BASE_ADDRESS       			  0x40020000

typedef struct channel_tdef
{
	volatile u32 DMA_CCR;
	volatile u32 DMA_CNDTR;
	volatile u32 DMA_CPAR;
	volatile u32 DMA_CMAR;

}Channel_Regs_Tdef;

typedef struct dma1_tdef
{
	volatile u32 DMA_ISR;
	volatile u32 DMA_IFCR;
	volatile struct channel_tdef DMA_CR[7];


}Dma1_Tdef;

#define __DMA1  ((volatile struct dma1_tdef *)DMA1_BASE_ADDRESS)

/******************************************* STK_CTRL *************************************/


#endif
