/*
 *============================================================================================================*
 * Name        : GPIO_Interface.h	  																			  *
 * Module Name : GPIO Peripheral																				  *
 * Author      : Alfred Nagy Alfred                                                                           *
 * Date        : 12 Aug 2024                                                                                  *
 * Description : Interface Header file for the GPIO peripheral 													  *
 *============================================================================================================*
 **/

//#include <stdint.h>

#ifndef GPIO_Interface_h
#define GPIO_Interface_h

/*
 * @Port_T enum
 *
 *
 * */
typedef enum
{
	
	Port_A=0,
	Port_B,
	Port_C,
	Port_D,
	Port_E,
	Port_F,
	Port_G,
	Port_H,
	GPIO_PERIPHERAL_NUM_ENUM

}Port_T;

/*
 * @Port_T enum
 *
 *
 * */
typedef enum
{
	
	PIN_0=0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,
    PIN_11,
    PIN_12,
    PIN_13,
    PIN_14,
    PIN_15

}PIN_T;


typedef enum
{
	
	Input=0,
	Output,
	Alt_Fun,
	Analog

}Mode_t;

typedef enum
{
	
	LowSpeed=0,
	MediumSpeed,
	FastSpeed,
	HighSpeed
	
}OutputSpeed_t;

typedef enum 
{
	PushPull=0,
	OpenDrain

}OutputType_t;

typedef enum
{
	
	NoPUll=0,
	PullUp,
	PullDown
	
}PullUpDown_t;
/*
 *
 * @PinVal_t enum
 *
 * */
typedef enum 
{
	Pin_Low=0,
	Pin_High

}PinVal_t;

typedef enum
{

	AF0=0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
	
}AFt;


typedef struct
{
	
	Port_T Port_x;
	PIN_T  PinNum;
	Mode_t Mode;
	OutputSpeed_t Speed;
	OutputType_t  OutputType;
	PullUpDown_t  PullType;
	AFt Alf_Fun;
	
}PinConfig_t;

uint8_t	GPIO_u8PinInit(const PinConfig_t * CONFIG);

uint8_t	GPIO_u8SetPinVal(const Port_T Port_x,const PIN_T PinNum,const PinVal_t PINVAL);

uint8_t	GPIO_u8TogglePinVal(const Port_T Port_x,const PIN_T PinNum);

uint8_t	GPIO_u8ReadPinVal(const Port_T Port_x,uint8_t* const PinNum);

uint8_t GPIO_u8LckPin(const Port_T Port_x,uint16_t const PinNum);

uint8_t GPIO_u8LckPort(const Port_T Port_x);

#endif
