/*
 *============================================================================================================*
 * Name        : main.c	  																			  *
 * Author      : Alfred Nagy Alfred                                                                           *
 * Date        : 12 Aug 2024                                                                                  *
 * Description : Main program body 													      *
 *============================================================================================================*
 **/
#include <stdint.h>

#include "Common.h"
#include "STM32F446xx.h"

#include "GPIO_Interface.h"
#include "RCC_Interface.h"

void main(void) __attribute__((section(".MAIN_TEXT")));

void main(void)
{	
	//Clock configurations
	PLL_ALL_CONFIGS PLL_CONFIG = {
			.PLL_MAIN_Source = PLL_HSI ,
			.PLL_Divisor = PLLM8,
			.PLLN_Divisor = PLLN180,
			.PLLP_Divisor = PLLP_DIV2,
			.PLLR_Divisor = PLLR_DIV2,
			.PLLQ_Divisor = PLLQ_DIV2,
			.HSE_BYPASS = HSE_not_bypassed
	};

	RCC_SYS_CLK_CONFIG CONFIG_RCC= {
			.PLL_CONFIG=PLL_CONFIG,
			.SYS_CLOCK_SRC=SYS_PLLP,
			.AHB_PRESALE=AHB_NOT_DIV
	};

	//setup rcc with 180MHZ using pll
	RCC_SetClk_STATUS(&CONFIG_RCC,ON);
	
	//enable clock on gpio_a to use it for testing
	RCC_AHB1_EN_CLK(AHB1_GPIOA);
	
	//pinA_5 configurations
	PinConfig_t GPIO_PINA5_LED={
			.Port_x = Port_A,
			.PinNum=PIN_5,
			.Mode=Output,
			.OutputType=PushPull,
			.Speed=HighSpeed,
			.PullType=NoPUll,
			.Alf_Fun=AF0
	};
	
	//Enable pinA_5
	GPIO_u8PinInit( &GPIO_PINA5_LED );

	//variable for delay
	uint32_t x = 0;
	
	while(1)
	{	

		//toggle pinA_5 status
		GPIO_u8TogglePinVal(Port_A,PIN_5);
		
		x = 0;
		
		//delay
		while(x<0xffffffU)
		{
			x++;
		}
	}

}