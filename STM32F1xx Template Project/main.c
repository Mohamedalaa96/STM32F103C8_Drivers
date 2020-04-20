
#include "gpio_driver.h"

void Delays(int time);

int main(void)
{
	GPIO_EnableCLock(RCC_GPIOC);
	GPIO_SetMode(GPIOC,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CONFIG_OUTPUT_PUSHPULL,13);
	GPIO_SetMode(GPIOC,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CONFIG_OUTPUT_PUSHPULL,5);

	while(1)
	{
		GPIO_WritePin(GPIOC,GPIO_PIN_13,1);		
		Delays(10);
		GPIO_WritePin(GPIOC,GPIO_PIN_13,0);
		Delays(10);
	}
	
}


void Delays(int time) /// Random delay function
{
	int t;
	for(;time>0;time--)
	{
	 for(t=0;t<100000;t++)
		{}
	}
}
