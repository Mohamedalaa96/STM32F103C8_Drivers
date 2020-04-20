//V1.0


#include "gpio_driver.h"



//use struct to set configuration and enum , could be modified
void GPIO_SetMode(uint32_t GPIOx, uint8_t GPIO_MODE, uint8_t GPIO_CONFIG, uint8_t BIT){

     if (BIT >7){
        BIT = (BIT-8); 
			 uint32_t l;
			 //make this bits zeros 
			 l = ResetNibble(GPIOx_CRL_HIGH(GPIOx),BIT);
			 //shift the CONFIG back to MODE to make [CONFIG-MODE] package
			 GPIO_CONFIG = ((GPIO_CONFIG << 2) | GPIO_MODE) ;
			 //Write the packet to its location
			 GPIOx_CRL_HIGH(GPIOx)= WriteNibble(l,BIT,GPIO_CONFIG);
			 
			
    }
    else{
				uint32_t l;
				//make this bits zeros 
				l = ResetNibble(GPIOx_CRL_LOW(GPIOx),BIT);
			 //shift the CONFIG back to MODE to make [CONFIG-MODE] package
				GPIO_CONFIG = ((GPIO_CONFIG << 2) | GPIO_MODE) ;
			 //Write the packet to its location
				GPIOx_CRL_LOW(GPIOx)= WriteNibble(l,BIT,GPIO_CONFIG);
       

    }
}

void GPIO_EnableCLock(uint8_t RCC_GPIO){
	RCC_APB2ENR |= (uint32_t)RCC_GPIO;

}
void GPIO_WritePin(uint32_t GPIOx, uint16_t GPIO_PIN,uint8_t state){
	if (state == 0){
		GPIOx_BSRR(GPIOx) =(uint32_t)(GPIO_PIN << 16U);
	}
	else{
		GPIOx_BSRR(GPIOx)= (uint32_t)GPIO_PIN;
	}
}

