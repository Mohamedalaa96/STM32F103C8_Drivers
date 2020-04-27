#include"usart.h"

void Serial_Begin(USART_TypeDef * USART, uint32_t buadrate){

	//**Baud Rate calculation*//
	double f_clk = 36000000.0;
	//Enable Clock for Alternative Functions pins 
		RCC->APB2ENR |=  RCC_APB2ENR_AFIOEN;
	
	if (USART == USART1){
		//Diff bus , clock speed
		 f_clk = 72000000.0;
		//edit this ///**************************************************
		GPIO_EnableCLock(RCC_GPIOA);
		//Enable clock for the choosed module
		RCC->APB2ENR |=  RCC_APB2ENR_USART1EN; 
		GPIO_SetMode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CONFIG_OUTPUT_ALT_PP,9);
		GPIO_SetMode(GPIOA,GPIO_MODE_INPUT,GPIO_CONFIG_INPUT_PUP_PDWN,10);
	}
	else if (USART == USART2){

		GPIO_EnableCLock(RCC_GPIOA);
		//Enable clock for the choosed module
		RCC->APB1ENR |=  RCC_APB1ENR_USART2EN; 
		//Set Pin Mode for pins used 
		GPIO_SetMode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CONFIG_OUTPUT_ALT_PP,2);
		GPIO_SetMode(GPIOA,GPIO_MODE_INPUT,GPIO_CONFIG_INPUT_PUP_PDWN,3);
	
	}
	
	else if (USART == USART3){
		GPIO_EnableCLock(RCC_GPIOB);
		//Enable clock for the choosed module
		RCC->APB1ENR |=  RCC_APB1ENR_USART3EN; //* edit this 
		//Set Pin Mode for pins used 
		GPIO_SetMode(GPIOB,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CONFIG_OUTPUT_ALT_PP,10);
		GPIO_SetMode(GPIOB,GPIO_MODE_INPUT,GPIO_CONFIG_INPUT_PUP_PDWN,11);
	}
		uint16_t dev = (f_clk/(16*buadrate)); 
		f_clk = 16* ( (f_clk/(16*buadrate)) - dev );
		//preparing the round up
		uint16_t dec = f_clk; //remove the fraction part get the decimal only , 
		uint8_t frac2 = 100*(f_clk-dec); //convert the decimal part into its equavilent *100
		if(frac2>50)
			{
				dec ++; //rounding up
				if(dec == 16) //max of the 4 bit size of fraction bits  (max of 15d)
				{
					dec = 0;	//clear the calculation of saving fraction, that there's no fraction
					dev ++; //round up the floating point it self to the mantisua 
				}
			}
			uint16_t final; 
			final = (dev<<4);
			final += dec;
			USART->BRR = final;  //******************
			//Enable Transmission ,, 	//Enable Receive 
			USART->CR1 |= USART_CR1_RE | USART_CR1_TE | USART_CR1_UE;
	

}

uint8_t Serial_Available(USART_TypeDef  * USART){
	 if (USART->SR & USART_SR_RXNE)
			return 1;
	 else
		 return 0;
}
char Serial_ReadChar(USART_TypeDef  * USART){
	return USART->DR;
}
	
void Serial_SendChar(USART_TypeDef  * USART,char out){
		while( (USART2->SR & (1<< 6) ) == 0){}//do noting untill data send 	
		USART->DR= out;

}

void Serial_SendString(USART_TypeDef * USART ,char * str){
	uint8_t counter =0;
	while (str[counter] != '\0'){
		Serial_SendChar(USART,str[counter]);
		counter++;
	}
}

