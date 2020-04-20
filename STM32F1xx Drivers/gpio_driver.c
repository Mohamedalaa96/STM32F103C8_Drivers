//V1.0


#include "gpio_driver.h"


void GPIO_EnableCLock(uint8_t RCC_GPIO){
	RCC_APB2ENR |= (uint32_t)RCC_GPIO;

}
//use struct to set configuration and enum , could be modified
void GPIO_SetMode(GPIO_TypeDef *GPIO_PORT, uint8_t GPIO_MODE, uint8_t GPIO_CONFIG, uint8_t BIT){

     if (BIT >7){
        BIT = (BIT-8); 
			 uint32_t l;
			 //make this bits zeros 
			 l = ResetNibble(GPIO_PORT->CRH,BIT);
			 //shift the CONFIG back to MODE to make [CONFIG-MODE] package
			 GPIO_CONFIG = ((GPIO_CONFIG << 2) | GPIO_MODE) ;
			 //Write the packet to its location
			GPIO_PORT->CRH= WriteNibble(l,BIT,GPIO_CONFIG);
			 
			
    }
    else{
				uint32_t l;
				//make this bits zeros 
				l = ResetNibble(GPIO_PORT->CRL,BIT);
			 //shift the CONFIG back to MODE to make [CONFIG-MODE] package
				GPIO_CONFIG = ((GPIO_CONFIG << 2) | GPIO_MODE) ;
			 //Write the packet to its location
				GPIO_PORT->CRL= WriteNibble(l,BIT,GPIO_CONFIG);
       

    }
}


void GPIO_WritePin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN,uint8_t state){
	if (state == 0){
		GPIO_PORT->BSRR = (uint32_t)(GPIO_PIN << 16U);
	}
	else{
		GPIO_PORT->BSRR = (uint32_t)(GPIO_PIN);
	}
}

uint16_t GPIO_ReadPin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN){
		return ( GPIO_PORT->IDR & GPIO_PIN) ;
}
void GPIO_TogglePin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN){
	GPIO_PORT->ODR ^= GPIO_PIN;

}
