
#ifndef __GPIO_DRIVER_H
#define __GPIO_DRIVER_H

#include <stdint.h>
#include "gpio_macros.h"


/*************************** GPIO PINs ***************************/
    #define GPIO_PIN_0	0x0001
    #define GPIO_PIN_1	0x0002
    #define GPIO_PIN_2	0x0004
    #define GPIO_PIN_3	0x0008
    #define GPIO_PIN_4	0x0010
    #define GPIO_PIN_5	0x0020
    #define GPIO_PIN_6	0x0040
    #define GPIO_PIN_7	0x0080
    #define GPIO_PIN_8	0x0100
    #define GPIO_PIN_9	0x0200
    #define GPIO_PIN_10	0x0400
    #define GPIO_PIN_11	0x0800
    #define GPIO_PIN_12	0x1000
    #define GPIO_PIN_13	0x2000
    #define GPIO_PIN_14 0x4000
    #define GPIO_PIN_15 0x8000


/*************************** Pripheral Structs ***************************/

    typedef struct
    {
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
    } GPIO_TypeDef;

/*************************** Pripheral Addresses ***************************/
    #define GPIOC          ((GPIO_TypeDef *) 0x40011000U)

/*************************** RCC_OFFSETS for GPIO ***************************/

    #define RCC_GPIOA			0x04
    #define RCC_GPIOB			0x08
    #define RCC_GPIOC			0x10
    #define RCC_GPIOD			0x20
    #define RCC_GPIOE			0x40
    #define RCC_GPIOF			0x80



/*************************** Functions Prototypes ***************************/

    //EX: ....(RCC_GPIOC);
    void GPIO_EnableCLock(uint8_t RCC_GPIO);
    //Ex: ....(GPIOC,GPIO_MODE_OUTPUT0
    void GPIO_SetMode(GPIO_TypeDef *GPIO_PORT, uint8_t GPIO_MODE, uint8_t GPIO_CONFIG, uint8_t BIT);

    void GPIO_WritePin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN,uint8_t state);

    uint16_t GPIO_ReadPin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN);


#endif
