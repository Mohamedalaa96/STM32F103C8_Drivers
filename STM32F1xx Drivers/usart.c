#include"usart.h"


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

