/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#include "Common.h"
#include "STM32F446xx.h"

#include "GPIO_Interface.h"
#include "RCC_Interface.h"

void main(void) __attribute__((section(".MAIN_TEXT")));

void main(void)
{	
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

	RCC_SetClk_STATUS(&CONFIG_RCC,ON);

	RCC_AHB1_EN_CLK(AHB1_GPIOA);

	PinConfig_t GPIO_PINA5_LED={
			.Port_x = Port_A,
			.PinNum=PIN_5,
			.Mode=Output,
			.OutputType=PushPull,
			.Speed=HighSpeed,
			.PullType=NoPUll,
			.Alf_Fun=AF0
	};

	GPIO_u8PinInit( &GPIO_PINA5_LED );

	unsigned int x = 0;
	while(1)
	{	

		
		GPIO_u8TogglePinVal(Port_A,PIN_5/*,Pin_Low*/);
		
		x = 0;

		while(x<0xffffffU)
		{
			x++;
		}
/*
		GPIO_u8SetPinVal(Port_A,PIN_5,Pin_High);
		
		x = 0;

		while(x<0xffU)
		{
			x++;
		}
*/
	}

}
/*
void Reset_Handler(void)
{
	int x = 5;
	x+=5;
}
*/