#include "delay.h"

void SysTickInit(){
	SysTick->CTRL = ((1<<2) |1); //AHB clock	, clear the value register
}


void delay(uint32_t time ){
	for (; time>0;time--){
		_delayMilli();
	}
}

void delayMicroSeconds(uint32_t time ){
	for (; time>0;time--){
		_delayMilli();
	}
}

void _delayMilli(){
	SysTick->LOAD = 0x11940 -1;	//1millisecond on 72MHz clk
	//SysTick->VAL=0;
	while ((SysTick->CTRL & (1<<0x10)) == 0); //wait to the flag to be raised.
}

void _delayMicro(){
	SysTick->LOAD = 0x48 -1;	//1millisecond on 72MHz clk
	//SysTick->VAL=0;
	while ((SysTick->CTRL & (1<<0x10)) == 0); //wait to the flag to be raised.
}

