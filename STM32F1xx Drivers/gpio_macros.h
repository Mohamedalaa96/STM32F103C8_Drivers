

#define RCC_APB2ENR     (*((volatile uint32_t *) 0x40021018))


/****************************Useful Macros*************************************/


#define ResetNibble(word,nipple) 		( ~(~word | ( 0xF << (nipple<<2) ) ) )
#define WriteNibble(word,nipple,data)   ( word | (data << (nipple<<2) ) 	)
#define valueOf(address)                (*(volatile unsigned long *) address)

/****************************GPIO_SetMode Parameters*************************************/

//GPIO_CONFIG 
//CNFy [1:0]
#define GPIO_CONFIG_INPUT_ANALOG 		    0x00
#define GPIO_CONFIG_INPUT_FLOATING		    0x01
#define GPIO_CONFIG_INPUT_PUP_PDWN		    0x02

#define GPIO_CONFIG_OUTPUT_PUSHPULL         0x00
#define GPIO_CONFIG_OUTPUT_OPENDRAIN        0x01
#define GPIO_CONFIG_OUTPUT_ALT_PP           0x02  //Alternating function (push pull).
#define GPIO_CONFIG_OUTPUT_ALT_OD           0x03  //Alternating function (open drain).

//GPIO_MODE
//MODEy[1:0]
#define GPIO_MODE_INPUT                  	0x00
#define GPIO_MODE_OUTPUT_10_MHZ        		0x01
#define GPIO_MODE_OUTPUT_2_MHZ         		0x02
#define GPIO_MODE_OUTPUT_50_MHZ        		0x03



