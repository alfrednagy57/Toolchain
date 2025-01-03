/*
 ============================================================================
 Name        : RCC_Program.c
 Module Name : RCC
 Author      : Alfred Nagy Alfred
 Date        : 3 Aug 2024
 Description : Source file for the NucleoF446RE RCC driver
 ============================================================================
 */
#include "STM32F446xx.h"

#include "Common.h"
#include "RCC_Interface.h"
#include "RCC_Prv.h"

uint8_t RCC_u8SetPllConfig(const PLL_ALL_CONFIGS * const PLL_CONFIG)
{
	if(PLL_CONFIG == NULL)
	{
		return NOK;
	}

	/* selecting the M divisor for HSE and HSI*/
	/* SOFTWARE MUST ASSURE THAT THE CLOCK EBTERING THE VCO ranges from 100 MHZ to 432 MHZ */
	RCC_PLLCFGR_REG.BITS.PLLM= PLL_CONFIG->PLL_Divisor;


	/* selecting the N divisor for PLL*/
	/* These Bits must be set and assure that the clock entering the VCO ranges from 1 MHZ to 2 MHZ*/
	/* VCO output frequency = VCO input frequency × PLLN with 50 ≤ PLLN ≤ 432*/
	RCC_PLLCFGR_REG.BITS.PLLN= PLL_CONFIG->PLLN_Divisor;

	/* selecting the P divisor */
	/* The software has to set these bits correctly not to exceed 180 MHz on this domain.*/
	/* PLL output clock frequency = VCO frequency / PLLP with PLLP = 2, 4, 6, or 8*/
	RCC_PLLCFGR_REG.BITS.PLLP=PLL_CONFIG->PLLP_Divisor;

	/* selecting the Q divisor */
	/* The software has to set these bits correctly not to exceed 180 MHz on this domain.*/
	/* 2 ≤ PLLQ ≤ 15*/
	RCC_PLLCFGR_REG.BITS.PLLQ=PLL_CONFIG->PLLQ_Divisor;

	/*selecting the R divisor */
	/* The USB OTG FS requires a 48 MHz clock to work correctly.*/
	/* The SDIOneeds a frequency lower than or equal to 48 MHz to work correctly.*/
	/* The software has to set these bits correctly not to exceed 180 MHz on this domain.*/
	/* 2 ≤ PLLR ≤ 7*/
	RCC_PLLCFGR_REG.BITS.PLLR=PLL_CONFIG->PLLR_Divisor;

	return OK;
}


uint8_t RCC_u8SetClkSrc(const SYS_PLL_SRC_TypeDef * const CLK_CONFIG)
{
	uint16_t timeout = TimeOut;

	if(CLK_CONFIG == NULL)
	{
		return NOK;
	}

	if( *CLK_CONFIG == SYS_PLLP || *CLK_CONFIG == SYS_PLLR)
	{
		RCC_CR_REG.BITS.PLLON=ONE_U;

		while(RCC_CR_REG.BITS.PLLRDY == ZERO_U&&timeout!=0);
	}
	else
	{
		/*nothing*/
	}

	FLASH_ACR_REG |= 0x05;//for 180MHZ

	RCC_CFGR_REG.BITS.SW = *CLK_CONFIG;

	while( (RCC_CFGR_REG.BITS.SW != RCC_CFGR_REG.BITS.SWS) && (timeout--)!=0);

	return OK;
}

uint8_t RCC_SetClk_STATUS(const RCC_SYS_CLK_CONFIG * const SYS_CONFIG,const Status_TypeDef Status)
{
	if(SYS_CONFIG == NULL || !Status)
	{
		return NOK;
	}

	/*selecting between HSI and HSE clk*/
	if((SYS_CONFIG->PLL_CONFIG).PLL_MAIN_Source == PLL_HSI)
	{
		RCC_CR_REG.BITS.HSION = ONE_U;

		while(ZERO_U==RCC_CR_REG.BITS.HSIRDY);

		RCC_PLLCFGR_REG.BITS.PLLSRC =ZERO_U;
	}
	else if((SYS_CONFIG->PLL_CONFIG).PLL_MAIN_Source == PLL_HSE)
	{
		RCC_CR_REG.BITS.HSEBYP = (SYS_CONFIG->PLL_CONFIG).HSE_BYPASS;

		RCC_CR_REG.BITS.HSEON = ONE_U;

		while(ZERO_U==RCC_CR_REG.BITS.HSERDY);

		RCC_PLLCFGR_REG.BITS.PLLSRC =ONE_U;

	}
	else
	{
		/*nothing*/
	}

	RCC_u8SetPllConfig(&SYS_CONFIG->PLL_CONFIG);

	RCC_u8SetClkSrc(&SYS_CONFIG->SYS_CLOCK_SRC);


	RCC_CFGR_REG.BITS.HPRE = SYS_CONFIG->AHB_PRESALE;

	/*turn on the css to ensure that the system will not fail */
	RCC_CR_REG.BITS.CSSON=ONE_U;

	return OK;
}
/*
======================================================================================================================================================


										PeriPheral ENABLE

ALL THE FUNCTION
 ***GETS THE PERIPHERAL NUM , THEN IT USES THE REGISTER TO ENABLE
 *** A BIT THAT ALLOW THE CLOCK TO GO THROUGH A SPECIFIC PATH THAT
 *** ACTIVATES THE PERIPHERAL

======================================================================================================================================================
 */

/*AHB ENABLE*/
void RCC_AHB1_EN_CLK(const AHB1_ENABLE_POS Pripheral)
{
	RCC_AHB1ENR_REG._4__BYTES |= (ONE_U<<Pripheral);
}

void RCC_AHB2_EN_CLK(const AHB2_ENABLE_POS Pripheral)
{
	RCC_AHB2ENR_REG._4__BYTES |= (ONE_U<<Pripheral);
}

void RCC_AHB3_EN_CLK(const AHB3_ENABLE_POS Pripheral)
{
	RCC_AHB3ENR_REG._4__BYTES |= (ONE_U<<Pripheral);
}

/*APB ENABLE*/
void RCC_APB1_EN_CLK(const APB1_ENABLE_POS Pripheral)
{
	RCC_APB1ENR_REG._4__BYTES |= (ONE_U<<Pripheral);
}

void RCC_APB2_EN_CLK(const APB2_ENABLE_POS Pripheral)
{
	RCC_APB2ENR_REG._4__BYTES |= (ONE_U<<Pripheral);
}

/*
======================================================================================================================================================


										PeriPheral DISABLE

ALL THE FUNCTION

 ***GETS THE PERIPHERAL NUM , THEN IT USES THE REGISTER TO DISABLE
 *** A BIT THAT PREVENTS THE CLOCK TO GO THROUGH A SPECIFIC PATH THAT
 *** ACTIVATES THE PERIPHERAL

======================================================================================================================================================
 */

/*AHB DISABLE*/
void RCC_AHB1_DIS_CLK(const AHB1_ENABLE_POS Pripheral)
{
	RCC_AHB1ENR_REG._4__BYTES &= (~(ONE_U<<Pripheral));
}

void RCC_AHB2_DIS_CLK(const AHB2_ENABLE_POS Pripheral)
{
	RCC_AHB2ENR_REG._4__BYTES &= (~(ONE_U<<Pripheral));
}

void RCC_AHB3_DIS_CLK(const AHB3_ENABLE_POS Pripheral)
{
	RCC_AHB3ENR_REG._4__BYTES &= (~(ONE_U<<Pripheral));
}

/*APB DISABLE*/
void RCC_APB1_DIS_CLK(const APB1_ENABLE_POS Pripheral)
{
	RCC_APB1ENR_REG._4__BYTES &= (~(ONE_U<<Pripheral));
}

void RCC_APB2_DIS_CLK(const APB2_ENABLE_POS Pripheral)
{
	RCC_APB2ENR_REG._4__BYTES &= (~(ONE_U<<Pripheral));
}
