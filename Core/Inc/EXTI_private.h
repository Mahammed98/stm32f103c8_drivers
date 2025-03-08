/*
 *
 *  NAME : EXTI_PRIVATE.H
 *  CREATE : 2/2/2024
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 *
 */
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#include "Std.h"


#define EXTI_BASE_ADDRESS          0x40010400

typedef struct exti_tdef{

volatile u32 EXTI_IMR_REG;
volatile u32 EXTI_EMR_REG;
volatile u32 EXTI_RTSR_REG;
volatile u32 EXTI_FTSR_REG;
volatile u32 EXTI_SWIER_REG;
volatile u32 EXTI_PR_REG;

}EXTI_Tdef;

#define __EXTIR   ((volatile EXTI_Tdef*) EXTI_BASE_ADDRESS)
#endif
