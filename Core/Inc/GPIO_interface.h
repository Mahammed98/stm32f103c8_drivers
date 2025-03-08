/*
 * 
 *  NAME : GPIO_INTERFACE.H
 *  CREATE : 6/9/2024
 *  AUTHOR : MOHAMED EL NABAWY
 *  VERSION : V1
 * 
 */

#ifndef GPIO_INTERFACE_H 
#define GPIO_INTERFACE_H

#include "BitMath.h"
#include "GPIO_config.h" 
#include "GPIO_private.h"

/*******************************************************    MACROS *************************************************************/
////////////////////////////// FOR PREBUILD CONFIGURATION  //////////////////////////////
// PORT NUMBERS
#define   PORTA_GPIO      0
#define   PORTB_GPIO      1
#define   PORTC_GPIO      2
#define   PORTD_GPIO      3
#define   PORTE_GPIO      4

// PINS NUMBER
#define   PIN0                      0
#define   PIN1                      1
#define   PIN2                      2
#define   PIN3                      3
#define   PIN4                      4
#define   PIN5                      5
#define   PIN6                      6
#define   PIN7                      7
#define   PIN8                      8
#define   PIN9                      9
#define   PIN10                     10
#define   PIN11                     11
#define   PIN12                     12
#define   PIN13                     13
#define   PIN14                     14
#define   PIN15                     15
// MODE GPIO PINS
#define   INPUT                      0
#define   OUTPUT_MAX_SPEED_10MHZ     1U
#define   OUTPUT_MAX_SPEED_2MHZ      2U
#define   OUTPUT_MAX_SPEED_50MHZ     3U
// INPUT MODES 
#define   ANALOG_MOED                0
#define   FLOATING_INPUT_MODE        1U
#define   INPUT_PULL_UP_DOWN         2U
// OUTPUT MODES 
#define   GPO_PUSH_PULL              0
#define   GPO_OPEN_DRAIN             1U
#define   ALTF_OUTPUT_PUSH_PULL      2U
#define   ALTF_OUTPUT_OPEN_DRAIN     3U

#define   HIGH                       1
#define   LOW                        0

#define   PULL_UP                    1
#define   PULL_DOWN                  0

///////////////////////////////////// PROTOTYPES   /////////////////////////////////////////
/*  
                    to determine pin mode and its configuration 
    1- Copy_u8PinMode     ->    select (OUTPUT OR INPUT)
    2- Copy_u8IOMode      ->    OUTPUT -> select (GPO_PUSH_PULL, GPO_OPEN_DRAIN, ALTF_OUTPUT_PUSH_PULL, ALTF_OUTPUT_OPEN_DRAIN )
                          ->    INPUT  -> select (ANALOG_MOED, FLOATING_INPUT_MODE, INPUT_PULL_UP_DOWN)
*/
void M_GPIO_void_SetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode, u8 Copy_u8IOMode);
u8 M_GPIO_void_ReadPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber);             // to read pin value 
void M_GPIO_void_WritePin(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8State);      // to write on pin ( 0, 1 )
void M_GPIO_void_WritePinBSRR(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8State);      // to write on pin ( 0, 1 ) using bsrr register
void M_GPIO_void_WritePinBRR(u8 Copy_u8PortName, u8 Copy_u8PinNumber);      // to write on pin (0) using brr register
void M_GPIO_void_LockPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber);      // to lock pin from using as an another mode
/////////////////////////////////// altrenate function for external interrupt ////////////////////////////////////
void M_GPIO_void_AFExtInterrupt(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
void M_GPIO_void_InputPullUp_PullDown(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8State_Pull);

#endif
