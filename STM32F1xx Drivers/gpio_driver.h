
#ifndef __GPIO_DRIVER_H
#define __GPIO_DRIVER_H

#include <stdint.h>
#include "gpio_macros.h"
#include "stm32f10x.h"                  // Device header



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

   
/*************************** Pripheral Addresses ***************************/

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
    void GPIO_SetMode(GPIO_TypeDef *GPIO_PORT, uint8_t GPIO_MODE, uint8_t GPIO_CONFIG, uint16_t BIT);

    void GPIO_WritePin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN,uint8_t state);

    uint16_t GPIO_ReadPin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN);

    void GPIO_TogglePin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN);

#endif
