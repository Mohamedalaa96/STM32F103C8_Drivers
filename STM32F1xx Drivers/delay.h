#ifndef __DELAY_H_
#define __DELAY_H_

#include "stm32f10x.h"                  // Device header

void SysTickInit(void);

void _delayMilli(void);
void _delayMicro(void);
void delay(uint32_t time );
void delayMicroSeconds(uint32_t time );

#endif

