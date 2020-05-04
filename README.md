# STM32F103C8_Drivers
STM32F103C8 Drivers found on Bluepill board, developed and tested on Keil IDE

## GPIO Driver 

### void GPIO_EnableCLock(uint8_t RCC_GPIO);
Implementation Example:
```sh
GPIO_EnableCLock(RCC_GPIOB);
```

### void GPIO_SetMode(GPIO_TypeDef *GPIO_PORT, uint8_t GPIO_MODE, uint8_t GPIO_CONFIG, uint8_t BIT);
Implementation Example:
```sh
GPIO_SetMode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CONFIG_OUTPUT_PUSHPULL,5);
```
#### * Paramitters:

#### GPIO_PORT:

GPIOA 
GPIOB
GPIOC
...etc.

#### GPIO_MODE:

GPIO_MODE_INPUT                  
GPIO_MODE_OUTPUT_10_MHZ        		
GPIO_MODE_OUTPUT_2_MHZ         		
GPIO_MODE_OUTPUT_50_MHZ

#### GPIO_CONFIG :

GPIO_CONFIG_INPUT_ANALOG 		   	  
GPIO_CONFIG_INPUT_FLOATING		   
GPIO_CONFIG_INPUT_PUP_PDWN		

GPIO_CONFIG_OUTPUT_PUSHPULL        
GPIO_CONFIG_OUTPUT_OPENDRAIN     
GPIO_CONFIG_OUTPUT_ALT_PP         
GPIO_CONFIG_OUTPUT_ALT_OD         

#### BIT:
unsigned byte int 0:15. 
	

### void GPIO_WritePin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN,uint8_t state);
Implementation Example:
```sh
GPIO_EnableCLock(RCC_GPIOB);
```

### uint16_t GPIO_ReadPin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN);
Implementation Example:
```sh
GPIO_EnableCLock(RCC_GPIOB);
```

### void GPIO_TogglePin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN);
