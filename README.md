# STM32F103C8_Drivers

## GPIO Driver 

### void GPIO_EnableCLock(uint8_t RCC_GPIO);
		
void GPIO_SetMode(GPIO_TypeDef *GPIO_PORT, uint8_t GPIO_MODE, uint8_t GPIO_CONFIG, uint8_t BIT);

void GPIO_WritePin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN,uint8_t state);

uint16_t GPIO_ReadPin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN);

void GPIO_TogglePin(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN);
