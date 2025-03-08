#ifndef __MATH_H__
#define __MATH_H__

#define __SET_BIT(REG, BIT)   (REG |=  (1U << BIT))
#define __CLR_BIT(REG, BIT)   (REG &= ~(1U << BIT))
#define __TOG_BIT(REG, BIT)   (REG ^=  (1U << BIT))
#define __GET_BIT(REG, BIT)   ((REG >> BIT) & 1U)

#endif
