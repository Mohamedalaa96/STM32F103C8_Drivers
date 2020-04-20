

#define RCC_APB2ENR     (*((volatile unsigned long *) 0x40021018))


//*************//

#define ResetNibble(word,nipple) 			( ~(~word | ( 0xF << (nipple<<2) ) ) )
#define WriteNibble(word,nipple,data) (    word | (data << (nipple<<2) ) 	)

/****************************GPIO_SetMode Parameters*************************************/

//GPIO_CONFIG 
//CNFy [1:0]
#define GPIO_CONFIG_INPUT_ANALOG 					0x00
#define GPIO_CONFIG_INPUT_FLOATING				0x01
#define GPIO_CONFIG_INPUT_PUP_PDWN				0x02

#define GPIO_CONFIG_OUTPUT_PUSHPULL       0x00
#define GPIO_CONFIG_OUTPUT_OPENDRAIN      0x01
#define GPIO_CONFIG_OUTPUT_ALT_PP         0x02  //Alternating function (push pull).
#define GPIO_CONFIG_OUTPUT_ALT_OD         0x03  //Alternating function (open drain).

//GPIO_MODE
//MODEy[1:0]
#define GPIO_MODE_INPUT                  	0x00
#define GPIO_MODE_OUTPUT_10_MHZ        		0x01
#define GPIO_MODE_OUTPUT_2_MHZ         		0x02
#define GPIO_MODE_OUTPUT_50_MHZ        		0x03


#define GPIO_CRL_LOW_OFFSET							0x00U
#define GPIO_CRL_HIGH_OFFSET            0x04U
#define GPIO_IDR_OFFSET                 0x08U
#define GPIO_BSRR_OFFSET                0x10U
#define GPIO_ODR_OFFSET                 0x0CU   //OUTPUT DATA REGISTER
#define GPIO_RESET_OFFSET               0x14U
#define GPIO_LOCK_OFFSET                0x18U
#define GPIO_SRR_OFFSET                 0x10U

#define GPIOx_CRL_LOW(base) 	(*((volatile unsigned long *)(base +GPIO_CRL_LOW_OFFSET )))
#define GPIOx_CRL_HIGH(base) 	(*((volatile unsigned long *)(base +GPIO_CRL_HIGH_OFFSET)))

#define GPIOx_RST(base)     (*((volatile unsigned long *) (base +GPIO_R_SET_OFFSET)))
#define GPIOx_BSRR(base)    (*((volatile unsigned long *) (base +GPIO_BSRR_OFFSET)))
#define GPIOx_IDR(base)     (*((volatile unsigned long *) (base +GPIO_IDR_OFFSET)))
#define GPIOx_ODR(base)     (*((volatile unsigned long *) (base +GPIO_ODR_OFFSET)))
#define GPIOx_LOCK(base)     (*((volatile unsigned long *) (base +GPIO_LOCK_OFFSET)))

#define valueOf(address) (*(volatile unsigned long *) address)
