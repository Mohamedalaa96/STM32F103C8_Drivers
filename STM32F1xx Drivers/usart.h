#ifndef __USART_H__
#define __USART_H__

#include "stm32f10x.h"
#include "gpio_driver.h"

void Serial_Begin(USART_TypeDef * USART, uint32_t buadrate);
uint8_t Serial_Available(USART_TypeDef  * USART);
void Serial_SendChar(USART_TypeDef  * USART_NUMBER,char out);
char Serial_ReadChar(USART_TypeDef  * USART);
void Serial_SendString(USART_TypeDef * USART ,char * str);

#endif

