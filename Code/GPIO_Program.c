/*
 *============================================================================================================*
 * Name        : GPIO_Program.c	  																			  *
 * Module Name : GPIO Peripheral																		      *
 * Author      : Alfred Nagy Alfred                                                                           *
 * Date        : 12 Aug 2024                                                                                  *
 * Description : Source file for the GPIO peripheral 													      *
 *============================================================================================================*
 **/
#include "STM32F446xx.h"
#include "Common.h"

#include "GPIO_Interface.h"
#include "GPIO_Prv.h"


/************************************************************************************************
 * @fn  GPIO_u8PinInit
 * @brief the function initializes the GPIO pin according to the input parameters
 * @param[in]  CONFIG : the initialization values of the pin
 * @return val ErrorStatus .get option @Error_Status enum
 *************************************************************************************************/
static GPIO_REG_DEF_T* GPIO_PORT[GPIO_PERIPHERAL_NUM]={GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH};
//GPIO_REG_DEF_T * const GPIO_A = GPIOA;

uint8_t	GPIO_u8PinInit(const PinConfig_t * CONFIG)
{
	uint8_t ErrorStatus=NOK;

	if(CONFIG != NULL)
	{
		if(CONFIG->Port_x >= Port_A && CONFIG->Port_x <= Port_H && CONFIG->PinNum >= PIN_0 && CONFIG->PinNum <= PIN_15 && CONFIG->Mode >=Input &&CONFIG->Mode<=Analog && CONFIG->Speed>=LowSpeed && CONFIG->Speed<=HighSpeed && CONFIG->OutputType >=PushPull && CONFIG->OutputType <=OpenDrain && CONFIG ->PullType >= NoPUll && CONFIG ->PullType <= PullDown && CONFIG ->Alf_Fun >= AF0 && CONFIG ->Alf_Fun <= AF15 )
		{

			uint8_t Step_Mode_Speed_PullType= MODER_PULL_UP_DOWN_OSPEEDR_PIN_ACCESS*(CONFIG -> PinNum) ;

			/*selecting the mode*/
			GPIO_PORT[CONFIG -> Port_x]->MODER &=  ~(MODER_MASK << Step_Mode_Speed_PullType) ;
			GPIO_PORT[CONFIG -> Port_x]->MODER |=   ( (CONFIG->Mode) << Step_Mode_Speed_PullType );

			/*selecting pull up/down if configured*/
			GPIO_PORT[CONFIG -> Port_x]->PUPDR &= ~(PULL_UP_DOWN_MASK << Step_Mode_Speed_PullType) ;
			GPIO_PORT[CONFIG -> Port_x]->PUPDR |=  ((CONFIG->PullType) << Step_Mode_Speed_PullType) ;

			if( CONFIG->Mode == Output|| CONFIG->Mode == Alt_Fun)
			{
				/*configuring the push-pull / open drain*/
				GPIO_PORT[CONFIG -> Port_x]->OTYPER &= ~(ONE_UL << CONFIG -> PinNum)  ;
				GPIO_PORT[CONFIG -> Port_x]->OTYPER |=  ( (CONFIG->OutputType) << (CONFIG -> PinNum) );

				/*selecting the speed*/
				GPIO_PORT[CONFIG -> Port_x]->OSPEEDR &= ~(OSPEEDR_REG_MASK << Step_Mode_Speed_PullType) ;
				GPIO_PORT[CONFIG -> Port_x]->OSPEEDR |=  ( CONFIG->Speed << Step_Mode_Speed_PullType ) ;
			}
			else
			{
				/*nothing*/
			}

			if( CONFIG->Mode == Alt_Fun || CONFIG->Mode == Analog)
			{
				uint8_t REG_NUM = (CONFIG -> PinNum)/AF_PIN_NUM_DIV_MASK;
				uint8_t PIN_NUM =  AF_REG_MASK*( (CONFIG -> PinNum)%AF_PIN_NUM_DIV_MASK);

				GPIO_PORT[CONFIG -> Port_x]->AFR[REG_NUM] &=  ~( AFR_MASK << PIN_NUM );
				GPIO_PORT[CONFIG -> Port_x]->AFR[REG_NUM] |=   ( CONFIG-> Alf_Fun << PIN_NUM );
			}

			ErrorStatus = OK;
		}
		else
		{
			ErrorStatus = NOK ;
		}
	}
	else
	{
		ErrorStatus = NULL_PTR_ERROR ;
	}
	return ErrorStatus;
}
/************************************************************************************************
 * @fn  GPIO_u8SetPinVal
 * @brief this function outputs a certain value on an output pin
 * @param[in]  Port_x : the port num that is used. get option @Port_T enum
 * @param[in]  PinNum : the pin num that is required to output high or low on it.get option @PIN_T enum
 * @param[in]  PINVAL : the Pin State .get option @PinVal_t enum
 * @return val ErrorStatus .get option @Error_Status enum
 *************************************************************************************************/
uint8_t	GPIO_u8SetPinVal(const Port_T Port_x,const PIN_T PinNum,const PinVal_t PINVAL)
{
	uint8_t ErrorStatus=OK;

	if(Port_x >= Port_A && Port_x <= Port_H &&PinNum >= PIN_0 &&PinNum <= PIN_15)
	{

		if(PINVAL == Pin_High)
		{
			GPIO_PORT[Port_x]->BSRR =  ONE_UL<<PinNum ;
		}
		else if( PINVAL == Pin_Low)
		{
			GPIO_PORT[Port_x]->BSRR =  ( ONE_UL<<(PinNum+GPIOBSSR_RESET_MASK) );
		}
		else
		{
			ErrorStatus = NOK;
		}

	}
	else
	{
		ErrorStatus = NOK;
	}

	return ErrorStatus ;
}
/************************************************************************************************
 * @fn  GPIO_u8TogglePinVal
 * @brief this function used to output high or low on a pin
 * @param[in]  Port_x : the port num that is used. get option @Port_T enum
 * @param[in]  PinNum : the pin num that is required to toggle it is state.get option @PIN_T enum
 * @return val ErrorStatus .get option @Error_Status enum
 *************************************************************************************************/
uint8_t	GPIO_u8TogglePinVal(const Port_T Port_x,const PIN_T PinNum)
{
	uint8_t ErrorStatus=OK;

	if(Port_x >= Port_A && Port_x <= Port_H &&PinNum >= PIN_0 &&PinNum <= PIN_15)
	{
		GPIO_PORT[Port_x]->ODR ^=  ONE_UL<<PinNum ;
	}
	else
	{
		ErrorStatus = NOK;
	}

	return ErrorStatus;
}
/************************************************************************************************
 * @fn  GPIO_u8ReadPinVal
 * @brief this function used to read a certain pin value
 * @param[in]  Port_x  : the port num that is used. get option @Port_T enum
 * @param[in]  *PinNum : the pin num that is required to read it is state.get option @PIN_T enum
 * @param[in]  PinNum  : this pointer contains an address to an variable that the required to save the pin state in it
 * @return val ErrorStatus .get option @Error_Status enum
 *************************************************************************************************/
uint8_t	GPIO_u8ReadPinVal(const Port_T Port_x,uint8_t* const PinNum)
{
	uint8_t ErrorStatus=OK;
	if(PinNum != NULL)
	{
		if(Port_x >= Port_A && Port_x <= Port_H &&(*PinNum) >= PIN_0 &&(*PinNum)<= PIN_15 )
		{
			*PinNum = (GPIO_PORT_CALC( Port_x).IDR>> *PinNum) & ONE_UL ;
		}
		else
		{
			ErrorStatus = NOK;
		}
	}
	else
	{
		ErrorStatus = NULL_PTR_ERROR ;
	}
	return ErrorStatus;
}
/************************************************************************************************
 * @fn  GPIO_u8LckPin
 * @brief this function used to lock a certain pin Configurations .
 * @param[in]  Port_x  : the port num that is used. get option @Port_T enum
 * @param[in]  PinNum  : the pin num that is required to lock it.get option @PIN_T enum
 * @return val ErrorStatus .get option @Error_Status enum
 *************************************************************************************************/
uint8_t GPIO_u8LckPin(const Port_T Port_x,uint16_t const PinNum)
{
	uint8_t ErrorStatus=OK;

	if(Port_x >= Port_A && Port_x <= Port_H &&PinNum >= PIN_0 &&PinNum<= PIN_15)
	{
		//uint32_t LCkR_VAL=0;
	
		GPIO_PORT[Port_x]->LCKR = (ONE_UL<<LOCKER_BIT) | (ONE_UL<<PinNum);

		GPIO_PORT[Port_x]->LCKR = (ONE_UL<<PinNum);

		GPIO_PORT[Port_x]->LCKR = (ONE_UL<<LOCKER_BIT) | (ONE_UL<<PinNum);

		ErrorStatus = (uint8_t)GPIO_PORT[Port_x]->LCKR;

		ErrorStatus = (uint8_t)(((GPIO_PORT[Port_x]->LCKR )>>16)&(0x01U));
	}
	else
	{
		ErrorStatus = NOK;
	}

	return ErrorStatus;
}
/************************************************************************************************
 * @fn  GPIO_u8LckPin
 * @brief this function used to lock a certain port Configurations .
 * @param[in]  Port_x  : the port num that is used. get option @Port_T enum
 * @return val ErrorStatus .get option @Error_Status enum
 *************************************************************************************************/
uint8_t GPIO_u8LckPort(const Port_T Port_x)
{
	uint8_t ErrorStatus=OK;

	if(Port_x >= Port_A && Port_x <= Port_H)
	{
		uint8_t PINS = ZERO_U;

		for(;PINS<=PIN_15;PINS++)
		{
			ErrorStatus=GPIO_u8LckPin(Port_x,PINS);
		}
	}
	else
	{
		ErrorStatus=NOK;
	}

	return ErrorStatus;
}
