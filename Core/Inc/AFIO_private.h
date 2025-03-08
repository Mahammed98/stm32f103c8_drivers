/*
 * 
 *  NAME : AFIO_PRIVATE.H
 *  CREATE : 9/9/2024
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 * 
 */

#ifndef AFIO_PRIVATE_H 
#define AFIO_PRIVATE_H

#include "Std.h"

#define   AFIO_BASE_ADDRESS        0X40010000 

typedef struct afx_tdef
{
    volatile u32 AFIO_EVCR;
    volatile u32 AFIO_MAPR;
    volatile u32 AFIO_EXRICR1;
    volatile u32 AFIO_EXRICR2;
    volatile u32 AFIO_EXRICR3;
    volatile u32 AFIO_EXRICR4;
    volatile u32 RESERVED;
    volatile u32 AFIO_MAPR2;
}AFx_Tdef;

#define __AFIO    ((volatile struct afx_tdef*)AFIO_BASE_ADDRESS)


#endif
