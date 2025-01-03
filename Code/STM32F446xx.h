/*
 *============================================================================================================*
 * Name        : STM32F446xx.h	  																			  *
 * Module Name : STM32F446xx MC																				  *
 * Author      : Alfred Nagy Alfred                                                                           * 
 * Date        : 12 Aug 2024                                                                                  * 
 * Description : Header file for the STM32F446xx . Contains addresses of mem , peripheral ,IRQ definitions.   * 
 *============================================================================================================* 
 **/


#ifndef STM32F446xx_h
#define STM32F446xx_h

#include <stdint.h>

/*
======================================================================================================================================================


										VARIOUS MEMORY BASE ADDRESSES


======================================================================================================================================================
 */

#define FLASH_BASE_ADDRESS			0x08000000U
#define SRAM_BASE_ADDRESS			0x20000000U
#define ROM_SYS_BASE_ADDRESS		0x1FFF0000U

/*
======================================================================================================================================================


										BUS BASE ADDRESSES


======================================================================================================================================================
 */

/***********************************************              CORE PERIPHERAL BASE ADDRESSES               ***********************************************/

/******************************                     Systick timer PERIPHERAL BASE ADDRESSES         ***********************************************/
#define STK_CTRL_REG_BASE_ADDRESS  0xE000E010U		/*RW*****priviliged**************0x0*/
#define STK_LOAD_REG_BASE_ADDRESS  0xE000E014U		/*RW*****priviliged**************UNKNOWN*/
#define STK_VAL_REG_BASE_ADDRESS   0xE000E018U		/*RW*****priviliged**************UNKNOWN*/

#define STK_CALIB_REG_BASE_ADDRESS 0xE000E01CU      /*RO******priviliged-             0xC000 0000*/

/***********************************************             System Control Block PERIPHERAL BASE ADDRESSES               ***********************************************/
#define SCB_ICSR_REG_BASE_ADDRESS  0xE000ED04U

#define SCB_AIRCR_REG_BASE_ADDRESS 0xE000ED0CU

#define SCB_SHPR1_REG_BASE_ADDRESS 0xE000ED18U
#define SCB_SHPR2_REG_BASE_ADDRESS 0xE000ED1CU
#define SCB_SHPR3_REG_BASE_ADDRESS 0xE000ED20U

#define SCB_SHCSR_REG_BASE_ADDRESS 0xE000ED24U

#define SCB_CFSR_REG_BASE_ADDRESS  0xE000ED28U

#define SCB_HFSR_REG_BASE_ADDRESS  0xE000ED2CU

#define SCB_MMAR_REG_BASE_ADDRESS  0xE000ED34U

#define SCB_BFAR_REG_BASE_ADDRESS  0xE000ED38U

#define SCB_AFSR_REG_BASE_ADDRESS  0xE000ED3CU
/***********************************************             NVIC PERIPHERAL BASE ADDRESSES              ***********************************************/
#define NVIC_ISER_REG_BASE_ADDRESS 0xE000E100U
#define NVIC_ICER_REG_BASE_ADDRESS 0XE000E180U
#define NVIC_ISPR_REG_BASE_ADDRESS 0XE000E200U
#define NVIC_ICPR_REG_BASE_ADDRESS 0XE000E280U
#define NVIC_IABR_REG_BASE_ADDRESS 0xE000E300U
#define NVIC_IPR_REG_BASE_ADDRESS  0xE000E400U
#define NVIC_STIR_REG_BASE_ADDRESS 0xE000EF00U

/***********************************************              AHB1 PERIPHERAL BASE ADDRESSES               ***********************************************/
#define GPIOA_BASE_ADDRESSES		0x40020000U
#define GPIOB_BASE_ADDRESSES        0x40020400U
#define GPIOC_BASE_ADDRESSES        0x40020800U
#define GPIOD_BASE_ADDRESSES        0x40020C00U
#define GPIOE_BASE_ADDRESSES        0x40021000U
#define GPIOF_BASE_ADDRESSES        0x40021400U
#define GPIOG_BASE_ADDRESSES        0x40021800U
#define GPIOH_BASE_ADDRESSES        0x40021C00U

#define RCC_CR_REG_BASE_ADDRESSES   0x40023800U
#define RCC_PLL_CFGR_BASE_ADDRESSES 0x40023804U
#define RCC_CFGR_BASE_ADDRESSES     0x40023808U
#define RCC_CIR_BASE_ADDRESSES 		0x4002380CU

#define RCC_AHB1_RSTR_BASE_ADDRESSES 0x40023810U
#define RCC_AHB2_RSTR_BASE_ADDRESSES 0x40023814U
#define RCC_AHB3_RSTR_BASE_ADDRESSES 0x40023818U

#define RCC_APB1_RSTR_BASE_ADDRESSES 0x40023820U
#define RCC_APB2_RSTR_BASE_ADDRESSES 0x40023824U

#define RCC_AHB1_ENR_BASE_ADDRESSES  0x40023830U
#define RCC_AHB2_ENR_BASE_ADDRESSES  0x40023834U
#define RCC_AHB3_ENR_BASE_ADDRESSES  0x40023838U

#define RCC_APB1_ENR_BASE_ADDRESSES  0x40023840U
#define RCC_APB2_ENR_BASE_ADDRESSES  0x40023844U

#define RCC_AHB1_LPENR_BASE_ADDRESSES  0x40023850U
#define RCC_AHB2_LPENR_BASE_ADDRESSES  0x40023854U
#define RCC_AHB3_LPENR_BASE_ADDRESSES  0x40023858U

#define RCC_APB1_LPENR_BASE_ADDRESSES  0x40023860U
#define RCC_APB2_LPENR_BASE_ADDRESSES  0x40023864U

#define RCC_BDCR_BASE_ADDRESSES    	   0x40023870U
#define	RCC_CSR_BASE_ADDRESSES         0x40023874U

#define	RCC_SS_CGR_BASE_ADDRESSES 		0x40023880U
#define	RCC_PLLI2_SCFGR_BASE_ADDRESSES  0x40023884U
#define	RCC_PLL_SAI_CFGR_BASE_ADDRESSES 0x40023888U
#define	RCC_DCK_CFGR_BASE_ADDRESSES 	0x4002388CU

#define	RCC_CK_GATENR_BASE_ADDRESSES 	0x40023890U
#define	RCC_DCK_CFGR2_BASE_ADDRESSES 	0x40023894U

/***********************************************              DMA PERIPHERAL BASE ADDRESSES               ***********************************************/
//0x4002 6400 - 0x4002 67FF DMA2
//0x4002 6000 - 0x4002 63FF DMA1
#define DMA1_BASE_ADDRESSES				0x40026000U
#define DMA2_BASE_ADDRESSES 			0x40026400U


/***********************************************              AHB2 PERIPHERAL BASE ADDRESSES               ***********************************************/

/***********************************************              AHB3 PERIPHERAL BASE ADDRESSES               ***********************************************/

/***********************************************              APB1 PERIPHERAL BASE ADDRESSES               ***********************************************/
/***********************************************              APB2 PERIPHERAL BASE ADDRESSES               ***********************************************/

/*********************************************** UART PERIPHERAL BASEADDRESS	****************************************************************/
#define UART1_REG_BASE_ADDRESS 0x40011000U
#define UART2_REG_BASE_ADDRESS 0x40004400U
#define	UART3_REG_BASE_ADDRESS 0x40004800U
#define	UART4_REG_BASE_ADDRESS 0x40004C00U
#define	UART5_REG_BASE_ADDRESS 0x40005000U
#define UART6_REG_BASE_ADDRESS 0x40011400U

#define UARTx_SR_REG_OFFSET	   0x00U
#define UARTx_DR_REG_OFFSET    0x04U
#define UARTx_BBR_REG_OFFSET   0x08U
#define UARTx_CR1_REG_OFFSET   0x0CU
#define UARTx_CR2_REG_OFFSET   0x10U
#define UARTx_CR3_REG_OFFSET   0x14U
#define UARTx_CR4_REG_OFFSET   0x18U
#define UARTx_GTPR_REG_OFFSET  0x1CU

/*********************************************** SPI PERIPHERAL BASEADDRESS	****************************************************************/
#define SPI1_REG_BASE_ADDRESS 0x40013000U
#define SPI2_REG_BASE_ADDRESS 0x40003800U
#define SPI3_REG_BASE_ADDRESS 0x40003C00U
#define SPI4_REG_BASE_ADDRESS 0x40013400U

/***********************************************             SYSTEM CONFIGURATION PERIPHERAL BASE ADDRESSES              ***********************************************/
#define SYSCFG_MEMRMP_REG_BASE_ADDRESS  0x40013800U

#define SYSCFG_PMC_REG_BASE_ADDRESS 	0x40013804U

#define SYSCFG_EXTICR1_REG_BASE_ADDRESS 0x40013808U
#define SYSCFG_EXTICR2_REG_BASE_ADDRESS 0x4001380CU
#define SYSCFG_EXTICR3_REG_BASE_ADDRESS 0x40013810U
#define SYSCFG_EXTICR4_REG_BASE_ADDRESS 0x40013814U

#define SYSCFG_CMPCR_REG_BASE_ADDRESS   0x40013820U

#define SYSCFG_CFGR_REG_BASE_ADDRESS    0x4001382CU

/***********************************************             EXTI PERIPHERAL BASE ADDRESSES              ***********************************************/
#define EXTI_IMR_REG_BASE_ADDRESS		0x40013C00U
#define EXTI_EMR_REG_BASE_ADDRESS		0x40013C04U
#define EXTI_RTSR_REG_BASE_ADDRESS		0x40013C08U
#define EXTI_FTSR_REG_BASE_ADDRESS		0x40013C08U
#define EXTI_SWIER_REG_BASE_ADDRESS		0x40013C10U
#define EXTI_PR_REG_BASE_ADDRESS		0x40013C14U


/***********************************************              RCC REGISTER ENUM & STRUCT DEFINITIONS         ***********************************************/

/*RCC control register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x00
 *
 * Reset value: 0x0000 XX83 where X is undefined.
 *
 * */
typedef union
{
	uint32_t _4__BYTES ;

	struct
	{
		uint8_t HSION     : 1 ; /*Internal high-speed clock enable*/
		uint8_t HSIRDY    : 1 ; /*Internal high-speed clock ready flag*/
		uint8_t Bit_2     : 1 ; /*Reserved     unused*/

		uint8_t HSITRIM   : 5 ; /*5 user programmed Bits ------ Internal high-speed clock trimming*/

		uint8_t HSICAL	  : 8 ; /*used by H.W ONLY--startup code modifies it--Internal high-speed clock calibration------These bits are initialized automatically at startup*/

		uint8_t HSEON     : 1 ; /*HSE clock enable*/
		uint8_t HSERDY    : 1 ; /*HSE clock ready flag*/
		uint8_t HSEBYP    : 1 ; /*HSE clock bypass----high is bypassed---where in bypassed mode on osc_out is used*/
		uint8_t CSSON	  : 1 ; /*Clock security system enable*/

		uint8_t _4_BITS__ : 4 ;	/*4 Reserved---> unused BITS*/

		uint8_t PLLON     : 1 ; /*Main PLL (PLL) enable*/
		uint8_t PLLRDY    : 1 ; /*Main PLL (PLL) clock ready flag*/
		uint8_t PLLI2SON  : 1 ; /*PLLI2S enable*/
		uint8_t PLLI2SRDY : 1 ; /*PLLI2S clock ready flag*/
		uint8_t PLLSAION  : 1 ; /*PLLSAI enable*/
		uint8_t PLLSAIRDY : 1 ; /*PLLSAI clock ready flag*/

		uint8_t _2_BITS   : 2 ; /*2 Reserved ---> unused BITS*/

	}BITS;

}RCC_CR_REG_TypeDef;


/*
======================================================================================================================================================
======================================================================================================================================================
 */




/*RCC PLL configuration register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x04
 *
 * Reset value: 0x2400 3010
 *
 * */
typedef union
{
	uint32_t _4__BYTES ;

	struct
	{
		/*
		 * Division factor for the main PLL (PLL) input clock
		 * These bits can be written only when the PLL is disabled.
		 *
		 * These Bits must be set and assure that the clock entering the VCO ranges from 100 MHZ to 432 MHZ
		 *
		 * VCO input frequency = PLL input clock frequency / PLLM with 2 ≤ PLLM ≤ 63
		 * */
		uint8_t PLLM : 6 ;

		/*
		 * Division factor for the main PLL (PLL) input clock
		 * These bits can be written only when the PLL is disabled.
		 *
		 * These Bits must be set and assure that the clock entering the VCO ranges from 1 MHZ to 2 MHZ
		 *
		 * VCO output frequency = VCO input frequency × PLLN with 50 ≤ PLLN ≤ 432
		 * */
		uint16_t PLLN : 9 ;

		uint8_t BIT_15 : 1 ;/*1 Reserved---> unused BIT*/

		/*
		 * Division factor for the main PLL (PLL) input clock
		 * These bits can be written only when the PLL is disabled.
		 *
		 *  The software has to set these bits correctly not to exceed 180 MHz on this domain.
		 *
		 * PLL output clock frequency = VCO frequency / PLLP with PLLP = 2, 4, 6, or 8
		 * */
		uint8_t PLLP : 2 ;

		uint8_t _4_BITS : 4 ;/*4 Reserved---> unused BITS*/

		/*
		 * Main PLL(PLL) and audio PLL (PLLI2S) entry clock source
		 * This bit can be written only when PLL and PLLI2S are disabled.
		 *
		 *  The software has to set these bits correctly not to exceed 180 MHz on this domain.
		 *  0: HSI clock selected as PLL and PLLI2S clock entry
		 *1: HSE oscillator clock selected as PLL and PLLI2S clock entry
		 * */
		uint8_t PLLSRC : 1 ;

		uint8_t BIT_23 : 1 ;/*1 Reserved---> unused BIT*/

		/*
		 * Main PLL (PLL) division factor for USB OTG FS, SDIOclocks
		 * These bits should be written only if PLL is disabled.
		 *
		 *  The USB OTG FS requires a 48 MHz clock to work correctly.
		 *  The SDIOneeds a frequency lower than or equal to 48 MHz to work correctly.
		 *
		 *  2 ≤ PLLQ ≤ 15
		 * */
		uint8_t PLLQ   : 4;

		/*
		 * Main PLL division factor for I2Ss, SAIs, SYSTEM and SPDIF-Rx clocks
		 * These bits should be written only if PLL is disabled.
		 *
		 *  Clock frequency = VCO frequency / PLLR
		 *
		 *   2 ≤ PLLR ≤ 7

		 * */
		uint8_t PLLR   : 3;

		uint8_t Bit_31 : 1;/*1 Reserved---> unused BIT*/
	}BITS;

}RCC_PLLCFGR_REG_TypeDef;



/*
======================================================================================================================================================
======================================================================================================================================================
 */


/*RCC clock configuration register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x08
 *
 * Reset value: 0x0000 0000
 *
 * Access: 0 ≤ wait state ≤ 2, word, half-word and byte access
 *
 * 1 or 2 wait states inserted only if the access occurs during a clock source switch
 *
 * */
typedef union
{
	uint32_t _4__BYTES ;

	struct
	{
		/*
		 * System clock switch
		 *
		 *Set and cleared by software to select the system clock source.
		 *
		 * 00: HSI oscillator selected as system clock
		 * 01: HSE oscillator selected as system clock
		 * 10: PLL_P selected as system clock , i.e PLLCLK
		 * 11: PLL_R selected as system clock
		 *
		 * */
		uint8_t SW : 2 ;

		/*
		 * System clock switch status
		 *
		 * Set and cleared by hardware to indicate which clock source is used as the system clock.
		 *
		 * 00: HSI oscillator selected as system clock
		 * 01: HSE oscillator selected as system clock
		 * 10: PLL_P selected as system clock , i.e PLLCLK
		 * 11: PLL_R selected as system clock
		 *
		 * */
		uint8_t SWS : 2 ;

		/*
		 * AHB prescaler
		 *
		 * The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after HPRE write.
		 *
		 * The AHB clock frequency must be at least 25 MHz when the Ethernet is used
		 *
		 * 0xxx: system clock not divided
		 *
		 * 1000: system clock divided by 2
		 * 1001: system clock divided by 4
		 * 1010: system clock divided by 8
		 * 1011: system clock divided by 16
		 * 1100: system clock divided by 64
		 * 1101: system clock divided by 128
		 * 1110: system clock divided by 256
		 * 1111: system clock divided by 512
		 * */
		uint8_t HPRE : 4;

		uint8_t BIT_8_9 : 2; /*2 Reserved---> unused BITS*/

		/*
		 *
		 * APB Low speed prescaler (APB1)
		 *
		 * The software has to set these bits correctly not to exceed 45 MHz on this domain.
		 * The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after
		 * PPRE1 write.
		 *
		 * 0xx: AHB clock not divided
		 *
		 * 100: AHB clock divided by 2
		 * 101: AHB clock divided by 4
		 * 110: AHB clock divided by 8
		 * 111: AHB clock divided by 16
		 * */
		uint8_t PPRE1 : 3 ;

		/*
		 *
		 * APB Low speed prescaler (APB2)
		 *
		 *  The software has to set these bits correctly not to exceed 90 MHz on this domain.
		 * The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after
		 * PPRE2 write.
		 *
		 * 0xx: AHB clock not divided
		 *
		 * 100: AHB clock divided by 2
		 * 101: AHB clock divided by 4
		 * 110: AHB clock divided by 8
		 * 111: AHB clock divided by 16
		 * */
		uint8_t PPRE2 : 3 ;

		/*
		 * HSE division factor for RTC clock
		 *
		 * Set and cleared by software to divide the HSE clock input clock to generate a 1 MHz clock for RTC.
		 *
		 * The software has to set these bits correctly to ensure that the clock supplied to the
		 * RTC is 1 MHz. These bits must be configured if needed before selecting the RTC
		 * clock source.
		 *
		 * 00000: no clock
		 * 00001: no clock
		 * 00010: HSE/2
		 * 00011: HSE/3
		 * 00100: HSE/4
		 * -->
		 * 11110: HSE/30
		 * 11111: HSE/31
		 */
		uint8_t RTCPRE : 5;

		/*
		 *  Microcontroller clock output 1
		 *
		 *  Clock source selection may generate glitches on MCO1. It is
		 *	highly recommended to configure these bits only after reset before enabling the external
		 *	oscillators and PLL.
		 *
		 *	00: HSI clock selected
		 *	01: LSE oscillator selected
		 *	10: HSE oscillator clock selected
		 *	11: PLL clock selected
		 *
		 */
		uint8_t MCO1 : 2;

		uint8_t BIT_23 : 1; /* Reserved ---> unused */

		/*
		 * MCO1 prescaler
		 *
		 * It is highly recommended to change this prescaler only after reset before enabling the external oscillators and the PLL.
		 *
		 * 0xx: no division
		 *
		 * 100: division by 2
		 * 101: division by 3
		 * 110: division by 4
		 * 111: division by 5
		 */
		uint8_t MCO1PRE : 3 ;


		/*
		 * MCO2 prescaler
		 *
		 * It is highly recommended to change this prescaler only after reset before enabling the external oscillators and the PLLs.
		 *
		 * 0xx: no division
		 *
		 * 100: division by 2
		 * 101: division by 3
		 * 110: division by 4
		 * 111: division by 5
		 */
		uint8_t MCO2PRE : 3 ;

		/*
		 *  Microcontroller clock output 2
		 *
		 * It is highly recommended to configure these bits only after reset before enabling the external oscillators and the PLLs.
		 *
		 * 00: System clock (SYSCLK) selected
		 * 01: PLLI2S clock selected
		 * 10: HSE oscillator clock selected
		 * 11: PLL clock selected
		 * */
		uint8_t MCO2 : 2;

	}BITS;

}RCC_CFGR_REG_TypeDef;


/*
======================================================================================================================================================
======================================================================================================================================================
 */


/*RCC Interrupt register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x0C
 *
 * Reset value: : 0x0000 0000
 *
 * */

typedef union
{
	uint32_t _4__BYTES ;

	struct
	{

		/*
			======================================================================================================================================================


											THESE NEXT BITS ARE THE INTERRUPT FLAGS


			======================================================================================================================================================
		 */

		/*
		 * LSI ready interrupt flag
		 *
		 * This bit is set by hardware when the internal low speed clock becomes stable and LSIRDYDIE is set.
		 *
		 * It is cleared by software by setting the LSIRDYC bit.
		 *
		 * 0: No clock ready interrupt caused by the LSI oscillator
		 * 1: Clock ready interrupt caused by the LSI oscillator
		 *
		 * */
		uint8_t LSIRDYF : 1 ;

		/*
		 * LSE ready interrupt flag
		 *
		 * This bit is set by hardware when the External Low Speed clock becomes stable and LSERDYDIE is set.
		 *
		 * It is cleared by software by setting the LSERDYC bit.
		 *
		 * 0: No clock ready interrupt caused by the LSE oscillator
		 * 1: Clock ready interrupt caused by the LSE oscillator
		 *
		 * */
		uint8_t LSERDYF : 1 ;


		/*
		 * HSI ready interrupt flag
		 *
		 * This bit is set by hardware when the Internal High Speed clock becomes stable and HSIRDYDIE is set.
		 *
		 * It is cleared by software by setting the HSIRDYC bit.
		 *
		 * 0: No clock ready interrupt caused by the HSI oscillator
		 * 1: Clock ready interrupt caused by the HSI oscillator
		 *
		 * */
		uint8_t HSIRDYF : 1 ;

		/*
		 * HSE ready interrupt flag
		 *
		 * This bit is set by hardware when External High Speed clock becomes stable and HSERDYDIE is set.
		 *
		 * It is cleared by software by setting the HSERDYC bit.
		 *
		 * 0: No clock ready interrupt caused by the HSE oscillator
		 * 1: Clock ready interrupt caused by the HSE oscillator
		 *
		 * */
		uint8_t HSERDYF : 1 ;

		/*
		 * Main PLL (PLL) ready interrupt flag
		 *
		 * This bit is set by hardware when PLL is locked and PLLRDYDIE is set.
		 *
		 * It is cleared by software setting the PLLRDYC bit.
		 *
		 * 0: No clock ready interrupt caused by PLL lock
		 * 1: Clock ready interrupt caused by PLL lock
		 *
		 * */
		uint8_t PLLRDYF : 1 ;

		/*
		 *  PLLI2S ready interrupt flag
		 *
		 * This bit is set by hardware when the PLLI2S is locked and PLLI2SRDYDIE is set.
		 *
		 * It is cleared by software by setting the PLLRI2SDYC bit.
		 *
		 * 0: No clock ready interrupt caused by PLLI2S lock
		 * 1: Clock ready interrupt caused by PLLI2S lock
		 *
		 * */
		uint8_t PLLI2SRDYF : 1 ;

		/*
		 *  PLLSAI Ready Interrupt flag
		 *
		 * This bit is set by hardware when the PLLSAI is locked and PLLSAIRDYDIE is set.
		 *
		 * It is cleared by software by setting the PLLSAIRDYC bit.
		 *
		 * 0: No clock ready interrupt caused by PLLSAI lock
		 * 1: Clock ready interrupt caused by PLLSAI lock
		 *
		 * */
		uint8_t PLLSAIRDYF : 1 ;

		/*
		 *  Clock security system interrupt flag
		 *
		 * This bit is set by hardware when a failure is detected in the HSE oscillator.
		 *
		 * It is cleared by software by setting the CSSC bit.
		 *
		 * 0: No clock security interrupt caused by HSE clock failure
		 * 1: Clock security interrupt caused by HSE clock failure
		 *
		 * */
		uint8_t CSSF : 1 ;


		/*
		======================================================================================================================================================


											THESE NEXT BITS ARE USED TO ENABLE INTERRUPT


		======================================================================================================================================================
		 */


		/*
		 * LSI ready interrupt enable
		 *
		 * This bit is set and cleared by software to enable/disable interrupt caused by LSI oscillator stabilization.
		 *
		 * 0: LSI ready interrupt disabled
		 * 1: LSI ready interrupt enabled
		 *
		 * */
		uint8_t LSIRDYIE : 1 ;

		/*
		 *  LSE ready interrupt enable
		 *
		 * This bit is set and cleared by software to enable/disable interrupt caused by the LSE  oscillator stabilization.
		 *
		 * 0: LSE ready interrupt disabled
		 * 1: LSE ready interrupt enabled
		 *
		 * */
		uint8_t LSERDYIE : 1 ;

		/*
		 * HSI ready interrupt enable
		 *
		 * This bit is set and cleared by software to enable/disable interrupt caused by HSI oscillator stabilization.
		 *
		 *
		 * 0: HSI ready interrupt disabled
		 * 1: HSI ready interrupt enabled
		 *
		 * */
		uint8_t HSIRDYIE : 1 ;

		/*
		 * HSE ready interrupt enable
		 *
		 * This bit is set and cleared by software to enable/disable interrupt caused by HSE oscillator stabilization.
		 *
		 *
		 * 0: HSE ready interrupt disabled
		 * 1: HSE ready interrupt enabled
		 *
		 * */
		uint8_t HSERDYIE : 1 ;


		/*
		 * Main PLL (PLL) ready interrupt enable
		 *
		 * This bit is set and cleared by software to enable/disable interrupt caused by PLL lock.
		 *
		 * 0: PLL lock interrupt disabled
		 * 1: PLL lock interrupt enabled
		 *
		 * */
		uint8_t PLLRDYIE : 1 ;


		/*
		 * PLLI2S ready interrupt enable
		 *
		 * This bit is set and cleared by software to enable/disable interrupt caused by PLLI2S lock.
		 *
		 * 0: PLLI2S lock interrupt disabled
		 * 1: PLLI2S lock interrupt enabled
		 *
		 * */
		uint8_t PLLI2SRDYIE : 1 ;

		/*
		 * PLLSAI ready interrupt enable
		 *
		 * This bit is set and cleared by software to enable/disable interrupt caused by PLLSAI lock.
		 *
		 * 0: PLLSAI lock interrupt disabled
		 * 1: PLLSAI lock interrupt enabled
		 *
		 * */
		uint8_t PLLSAIRDYIE : 1 ;


		/*
		======================================================================================================================================================
		======================================================================================================================================================
		 */

		uint8_t BIT_15 : 1 ; /*1 Reserved --> unused BIT */

		/*
		======================================================================================================================================================


		  	  	  	  	  	  	  	  	  	  	  	  THESE NEXT BITS ARE USED TO CLEAR FLAGS


		======================================================================================================================================================
		 */



		/*
		 * LSI ready interrupt clear
		 *
		 * This bit is set by software to clear the LSIRDYF flag.
		 *
		 * 0: No effect
		 * 1: LSIRDYF cleared
		 *
		 * */
		uint8_t LSIRDYC : 1 ;


		/*
		 * LSE ready interrupt clear
		 *
		 * This bit is set by software to clear the LSERDYF flag.
		 *
		 * 0: No effect
		 * 1: LSERDYF cleared
		 *
		 * */
		uint8_t LSERDYC : 1 ;

		/*
		 * HSI ready interrupt clear
		 *
		 * This bit is set by software to clear the HSIRDYF flag.
		 *
		 * 0: No effect
		 * 1: HSIRDYF cleared
		 *
		 * */
		uint8_t HSIRDYC : 1 ;


		/*
		 * HSE ready interrupt clear
		 *
		 * This bit is set by software to clear the HSERDYF flag.
		 *
		 * 0: No effect
		 * 1: HSERDYF cleared
		 *
		 * */
		uint8_t HSERDYC : 1 ;

		/*
		 * : Main PLL(PLL) interrupt clear
		 *
		 * This bit is set by software to clear the PLLRDYF flag.
		 *
		 * 0: No effect
		 * 1: PLLRDYF cleared
		 *
		 * */
		uint8_t PLLRDYC : 1 ;


		/*
		 * PLLI2S interrupt clear
		 *
		 * This bit is set by software to clear the PLLI2SRDYF flag.
		 *
		 * 0: No effect
		 * 1: PLLI2SRDYF cleared
		 *
		 * */
		uint8_t PLLI2SRDYC : 1 ;

		/*
		 * PLLSAI interrupt clear
		 *
		 * This bit is set by software to clear the PLLSAIRDYF flag.It is reset by hardware when the PLLSAIRDYF is cleared.
		 *
		 * 0: No effect
		 * 1: PLLSAIRDYF cleared
		 *
		 * */
		uint8_t PLLSAIRDYC : 1 ;

		/*
		 * Clock security system interrupt clear
		 *
		 * This bit is set by software to clear the CSSF flag.
		 *
		 * 0: No effect
		 * 1: Clear CSSF flag
		 *
		 * */
		uint8_t CSSC : 1 ;

		uint8_t __8_BITS ; /*8 Reserved ----> unused BITS*/
	}BITS;

}RCC_CIR_REG_TypeDef;


/*
======================================================================================================================================================
======================================================================================================================================================
 */


/*RCC AHB1 peripheral reset register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x10
 *
 * Reset value: 0x0000 0000
 *
 * */
typedef union
{
	uint32_t _4__BYTES ;

	struct
	{

		/*
		======================================================================================================================================================


													THESE NEXT BITS ARE USED FOR GPIOX RESET


		======================================================================================================================================================
		 */

		/*
		 * IO port A reset
		 *
		 * 0: does not reset IO port A
		 * 1: resets IO port A
		 *
		 * */
		uint8_t GPIOARST : 1;

		/*
		 * IO port B reset
		 *
		 * 0: does not reset IO port B
		 * 1: resets IO port B
		 *
		 * */
		uint8_t GPIOBRST : 1;

		/*
		 * IO port C reset
		 *
		 * 0: does not reset IO port C
		 * 1: resets IO port C
		 *
		 * */
		uint8_t GPIOCRST : 1;

		/*
		 * IO port D reset
		 *
		 * 0: does not reset IO port D
		 * 1: resets IO port D
		 *
		 * */
		uint8_t GPIODRST : 1;

		/*
		 * IO port E reset
		 *
		 * 0: does not reset IO port F
		 * 1: resets IO port E
		 *
		 * */
		uint8_t GPIOERST : 1;

		/*
		 * IO port F reset
		 *
		 * 0: does not reset IO port F
		 * 1: resets IO port F
		 *
		 * */
		uint8_t GPIOFRST : 1;

		/*
		 * IO port G reset
		 *
		 * 0: does not reset IO port G
		 * 1: resets IO port G
		 *
		 * */
		uint8_t GPIOGRST : 1;

		/*
		 * IO port H reset
		 *
		 * 0: does not reset IO port H
		 * 1: resets IO port H
		 *
		 * */
		uint8_t GPIOHRST : 1;


		uint8_t __4__BITS : 4 ; /*4 Reserved --- > unused BITS */


		/*
		 * CRC reset
		 *
		 * 0: does not reset CRC
		 * 1: resets CRC
		 *
		 * */
		uint8_t CRCRST : 1;


		uint8_t __8__BITS ; /*8 Reserved --- > unused BITS */

		/*
		 * DMA1 reset
		 *
		 * 0: does not reset DMA1
		 * 1: resets DMA1
		 *
		 * */
		uint8_t DMA1RST : 1;

		/*
		 * DMA2 reset
		 *
		 * 0: does not reset DMA2
		 * 1: resets DMA2
		 *
		 * */
		uint8_t DMA2RST : 1;

		uint8_t __6__BITS : 6 ; /*6 Reserved --- > unused BITS */

		/*
		 * OTGHS reset
		 *
		 * 0: does not reset OTGHS
		 * 1: resets OTGHS
		 *
		 * */
		uint8_t OTGHSRST : 1;

		uint8_t __2__BITS : 2 ; /*2 Reserved --- > unused BITS */

	}BITS;

}RCC_AHB1RSTR_REG_TypeDef;


/*
======================================================================================================================================================
======================================================================================================================================================
 */

/*RCC AHB2 peripheral reset register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x14
 *
 * Reset value: 0x0000 0000
 *
 * */
typedef union
{
	uint32_t _4__BYTES ;

	struct
	{
		/*
		 * Camera interface reset
		 *
		 * 0: does not reset the Camera interface
		 * 1: resets the Camera interface
		 * */
		uint8_t DCMIRST : 1;

		uint8_t _6_BITS   : 6 ; /*6 Reserved ---> unused BITS*/

		/*
		 * USB OTG FS module reset
		 *
		 * 0: does not reset the USB OTG FS module
		 * 1: resets the USB OTG FS module
		 * */
		uint8_t OTGFSRST : 1;

		uint32_t _24_BITS   : 24 ; /*24 Reserved ---> unused BITS*/

	}BITS;

}RCC_AHB2RSTR_REG_TypeDef;




/*
======================================================================================================================================================
======================================================================================================================================================
 */




/*RCC AHB3 peripheral reset register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x18
 *
 * Reset value: 0x0000 0000
 *
 * */
typedef union
{
	uint32_t _4__BYTES ;

	struct
	{
		/*
		 * Flexible memory controller module reset
		 *
		 * 0: does not reset the FMC module
		 * 1: resets the FMC module
		 * */
		uint8_t FMCRST : 1;

		/*
		 * QUADSPI module reset
		 *
		 * 0: does not reset the QUADSPI module reset
		 * 1: resets the QUADSPI module reset
		 * */
		uint8_t QSPIRST : 1;

		uint32_t _30_BITS   : 30 ; /*24 Reserved ---> unused BITS*/

	}BITS;

}RCC_AHB3RSTR_REG_TypeDef;




/*
======================================================================================================================================================
======================================================================================================================================================
 */




/*RCC APB1 peripheral reset register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x20
 *
 * Reset value: 0x0000 0000
 *
 * */
typedef union
{
	uint32_t _4__BYTES ;

	struct
	{
		/*
		======================================================================================================================================================


													THESE NEXT BITS ARE USED TO RESET TIM 2->7 + TIM 12->14


		======================================================================================================================================================
		 */

		/*
		 * TIM2 reset
		 *
		 * 0: does not reset TIM2
		 * 1: resets TIM2
		 * */
		uint8_t TIM2RST : 1;

		/*
		 * TIM3 reset
		 *
		 * 0: does not reset TIM3
		 * 1: resets TIM3
		 * */
		uint8_t TIM3RST : 1;

		/*
		 * TIM4 reset
		 *
		 * 0: does not reset TIM4
		 * 1: resets TIM4
		 * */
		uint8_t TIM4RST : 1;

		/*
		 * TIM5 reset
		 *
		 * 0: does not reset TIM5
		 * 1: resets TIM5
		 * */
		uint8_t TIM5RST : 1;

		/*
		 * TIM6 reset
		 *
		 * 0: does not reset TIM6
		 * 1: resets TIM6
		 * */
		uint8_t TIM6RST : 1;

		/*
		 * TIM7 reset
		 *
		 * 0: does not reset TIM7
		 * 1: resets TIM7
		 * */
		uint8_t TIM7RST : 1;


		/*
		 * TIM12 reset
		 *
		 * 0: does not reset TIM12
		 * 1: resets TIM12
		 * */
		uint8_t TIM12RST : 1;

		/*
		 * TIM13 reset
		 *
		 * 0: does not reset TIM13
		 * 1: resets TIM13
		 * */
		uint8_t TIM13RST : 1;

		/*
		 * TIM14 reset
		 *
		 * 0: does not reset TIM14
		 * 1: resets TIM14
		 * */
		uint8_t TIM14RST : 1;


		uint8_t _2_BITS   : 2 ; /*2 Reserved ---> unused BITS*/

		/*
		 * Window watchdog reset
		 *
		 * 0: does not reset Window watchdog
		 * 1: resets Window watchdog
		 * */
		uint8_t WWDGRST : 1;

		uint8_t _2_BITS__   : 2 ; /*2 Reserved ---> unused BITS*/


		/*
		======================================================================================================================================================


													THESE NEXT BITS ARE USED TO RESET COMM PROTOCOLS


		======================================================================================================================================================
		 */

		/*
		 * SPI2 reset
		 *
		 * 0: does not reset SPI2
		 * 1: resets SPI2
		 * */
		uint8_t SPI2RST : 1;

		/*
		 * SPI3 reset
		 *
		 * 0: does not reset SPI3
		 * 1: resets SPI3
		 * */
		uint8_t SPI3RST : 1;

		/*
		 * SPDIF-Rx reset
		 *
		 * 0: does not reset SPDIF-Rx
		 * 1: resets SPDIF-Rx
		 * */
		uint8_t SPDIFRXRST : 1;

		/*
		 * USART2 reset
		 *
		 * 0: does not reset USART2
		 * 1: resets USART2
		 * */
		uint8_t USART2RST : 1;

		/*
		 * USART3 reset
		 *
		 * 0: does not reset USART3
		 * 1: resets USART3
		 * */
		uint8_t USART3RST : 1;


		/*
		 * USART4 reset
		 *
		 * 0: does not reset USART4
		 * 1: resets USART4
		 * */
		uint8_t USART4RST : 1;

		/*
		 * USART4 reset
		 *
		 * 0: does not reset USART4
		 * 1: resets USART4
		 * */
		uint8_t USART5RST : 1;



		/*
		 * I2C1 reset
		 *
		 * 0: does not reset I2C1
		 * 1: resets I2C1
		 * */
		uint8_t I2C1RST : 1;

		/*
		 * I2C2 reset
		 *
		 * 0: does not reset I2C2
		 * 1: resets I2C2
		 * */
		uint8_t I2C2RST : 1;

		/*
		 * I2C3 reset
		 *
		 * 0: does not reset I2C3
		 * 1: resets I2C3
		 * */
		uint8_t I2C3RST : 1;

		/*
		 * FMPI2C1 reset
		 *
		 * 0: does not reset FMPI2C1
		 * 1: resets FMPI2C1
		 * */
		uint8_t IFMPI2C1RST : 1;

		/*
		 * CAN1 reset
		 *
		 * 0: does not reset CAN1
		 * 1: resets CAN1
		 * */
		uint8_t CAN1RST : 1;

		/*
		 * CAN2 reset
		 *
		 * 0: does not reset CAN2
		 * 1: resets CAN2
		 * */
		uint8_t CAN2RST : 1;

		/*
		 *  CEC reset
		 *
		 * 0: does not reset  CEC
		 * 1: resets  CEC
		 * */
		uint8_t CECRST : 1;

		/*
		 *   Power interface reset
		 *
		 * 0: does not reset  Power interface
		 * 1: resets  Power interface
		 * */
		uint8_t PWRRST : 1;

		/*
		 *  DAC interface reset
		 *
		 * 0: does not reset DAC
		 * 1: resets  Power DAC
		 * */
		uint8_t DACRST : 1;

		uint8_t _2_BITS___   : 2 ; /*2 Reserved ---> unused BITS*/

	}BITS;

}RCC_APB1RSTR_REG_TypeDef;






/*
======================================================================================================================================================
======================================================================================================================================================
 */




/*RCC APB2 peripheral reset register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x24
 *
 * Reset value: 0x0000 0000
 *
 * */
typedef union
{
	uint32_t _4__BYTES ;

	struct
	{
		/*
		 * TIM1 reset
		 *
		 * 0: does not reset TIM1
		 * 1: resets TIM1
		 * */
		uint8_t TIM1RST : 1;

		/*
		 * TIM8 reset
		 *
		 * 0: does not reset TIM8
		 * 1: resets TIM8
		 * */
		uint8_t TIM8RST : 1;

		uint8_t _2_BITS   : 2 ; /*2 Reserved ---> unused BITS*/

		/*
		 * USART1 reset
		 *
		 * 0: does not reset USART1
		 * 1: resets USART1
		 * */
		uint8_t USART1RST : 1;

		/*
		 * USART6 reset
		 *
		 * 0: does not reset USART6
		 * 1: resets USART6
		 * */
		uint8_t USART6RST : 1;

		uint8_t _2_BITS_   : 2 ; /*2 Reserved ---> unused BITS*/

		/*
		 * ADC reset
		 *
		 * 0: does not reset ADC
		 * 1: resets ADC
		 * */
		uint8_t ADCRST : 1;

		uint8_t _2_BITS__   : 2 ; /*2 Reserved ---> unused BITS*/


		/*
		 * SDIO reset
		 *
		 * 0: does not reset SDIO
		 * 1: resets SDIO
		 * */
		uint8_t SDIORST : 1;

		/*
		 * SPI1 reset
		 *
		 * 0: does not reset SPI1
		 * 1: resets SPI1
		 * */
		uint8_t SPI1RST : 1;

		/*
		 * SPI4 reset
		 *
		 * 0: does not reset SPI4
		 * 1: resets SPI4
		 * */
		uint8_t SPI4RST : 1;

		/*
		 * System configuration controller reset
		 *
		 * 0: does not reset SYSCFG
		 * 1: resets SYSCFG
		 * */
		uint8_t SYSCFGRST : 1;

		uint8_t BIT_15   : 1 ; /*1 Reserved ---> unused BIT*/

		/*
		 * TIM9 reset
		 *
		 * 0: does not reset TIM9
		 * 1: resets TIM9
		 * */
		uint8_t TIM9RST : 1;

		/*
		 * TIM10 reset
		 *
		 * 0: does not reset TIM10
		 * 1: resets TIM10
		 * */
		uint8_t TIM10RST : 1;

		/*
		 * TIM11 reset
		 *
		 * 0: does not reset TIM11
		 * 1: resets TIM11
		 * */
		uint8_t TIM11RST : 1;

		uint8_t _3_BITS   : 3 ; /*3 Reserved ---> unused BITS*/

		/*
		 * SAI1 reset
		 *
		 * 0: does not reset SAI1
		 * 1: resets SAI1
		 * */
		uint8_t SAI1RST : 1;

		/*
		 * SAI2 reset
		 *
		 * 0: does not reset SAI2
		 * 1: resets SAI2
		 * */
		uint8_t SAI2RST : 1;

		uint8_t _8_BITS ; /*8 Reserved ---> unused BITS*/

	}BITS;

}RCC_APB2RSTR_REG_TypeDef;


/*
 *
 * Address : 0x28
 *
 * Address : 0x2C
 *
 * THESE TWO ADDRESSES ARE NOT USED IN ANY REGISTERS
 *
 * */

/*
======================================================================================================================================================
======================================================================================================================================================
 */




/*RCC AHB1 peripheral clock enable register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x30
 *
 * Reset value: 0x0000 0000
 *
 * */
typedef union
{
	uint32_t _4__BYTES ;

	struct
	{
		/*
		 * IO port A clock enable
		 *
		 * 0: IO port A clock disabled
		 * 1: IO port A clock Enabled
		 * */
		uint8_t GPIOAEN : 1;

		/*
		 * IO port B clock enable
		 *
		 * 0: IO port B clock disabled
		 * 1: IO port B clock Enabled
		 * */
		uint8_t GPIOBEN : 1;

		/*
		 * IO port C clock enable
		 *
		 * 0: IO port C clock disabled
		 * 1: IO port C clock Enabled
		 * */
		uint8_t GPIOCEN : 1;

		/*
		 * IO port D clock enable
		 *
		 * 0: IO port D clock disabled
		 * 1: IO port D clock Enabled
		 * */
		uint8_t GPIODEN : 1;

		/*
		 * IO port E clock enable
		 *
		 * 0: IO port E clock disabled
		 * 1: IO port E clock Enabled
		 * */
		uint8_t GPIOEEN : 1;

		/*
		 * IO port F clock enable
		 *
		 * 0: IO port F clock disabled
		 * 1: IO port F clock Enabled
		 * */
		uint8_t GPIOFEN : 1;

		/*
		 * IO port G clock enable
		 *
		 * 0: IO port G clock disabled
		 * 1: IO port G clock Enabled
		 * */
		uint8_t GPIOGEN : 1;
		/*
		 * IO port H clock enable
		 *
		 * 0: IO port H clock disabled
		 * 1: IO port H clock Enabled
		 * */
		uint8_t GPIOHEN : 1;

		uint8_t _4_BITS   : 4 ; /*4 Reserved ---> unused BITS*/

		/*
		 * CRC clock enable
		 *
		 * 0: CRC clock disabled
		 * 1: CRC clock Enabled
		 * */
		uint8_t CRCEN : 1;

		uint8_t _5_BITS   : 5 ; /*5 Reserved ---> unused BITS*/

		/*
		 * Backup SRAM interface clock enable
		 *
		 * 0: Backup SRAM interface clock disabled
		 * 1: Backup SRAM interface clock Enabled
		 * */
		uint8_t BKPSRAMEN : 1;

		uint8_t _2_BITS   : 2 ; /*2 Reserved ---> unused BITS*/

		/*
		 * DMA1 clock enable
		 *
		 * 0: DMA1 clock disabled
		 * 1: DMA1 clock Enabled
		 * */
		uint8_t DMA1EN : 1;

		/*
		 * DMA2 clock enable
		 *
		 * 0: DMA2 clock disabled
		 * 1: DMA2 clock Enabled
		 * */
		uint8_t DMA2EN : 1;

		uint8_t _6_BITS   : 6 ; /*6 Reserved ---> unused BITS*/

		/*
		 *  USB OTG HS clock enable
		 *
		 * 0:  USB OTG HS clock disabled
		 * 1:  USB OTG HS clock Enabled
		 * */
		uint8_t OTGHSENEN : 1;

		/*
		 *   USB OTG HSULPI clock enable
		 *
		 * 0:   USB OTG HSULPI clock disabled
		 * 1:  USB OTG HSULPI clock Enabled
		 * */
		uint8_t OTGHSULPIEN : 1;

		uint8_t BIT_31   : 1 ; /*1 Reserved ---> unused BIT*/

	}BITS;

}RCC_AHB1ENR_REG_TypeDef;




/*
======================================================================================================================================================
======================================================================================================================================================
 */




/*RCC AHB3 peripheral reset register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x34
 *
 * Reset value: 0x0000 0000
 *
 * */
typedef union
{
	uint32_t _4__BYTES ;

	struct
	{
		/*
		 * Camera interface enable
		 *
		 * 0: Camera interface clock disabled
		 * 1: Camera interface clock enabled
		 * */
		uint8_t DCMIEN : 1;

		uint8_t _6_BITS   : 6 ; /*6 Reserved ---> unused BITS*/

		/*
		 *  USB OTG FS enable
		 *
		 * 0:  USB OTG FS clock disabled
		 * 1:  USB OTG FS clock enabled
		 * */
		uint8_t OTGFSEN : 1;

		uint32_t _24_BITS   : 24 ; /*24 Reserved ---> unused BITS*/

	}BITS;

}RCC_AHB2ENR_REG_TypeDef;





/*
======================================================================================================================================================
======================================================================================================================================================
 */




/*RCC AHB3 peripheral reset register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x38
 *
 * Reset value: 0x0000 0000
 *
 * */
typedef union
{
	uint32_t _4__BYTES ;

	struct
	{
		/*
		 * Flexible memory controller module enable
		 *
		 * 0: Flexible memory controller module clock disabled
		 * 1: Flexible memory controller module clock enabled
		 * */
		uint8_t FMCEN : 1;

		/*
		 * QUADSPI memory controller module clock enable
		 *
		 * 0:  QUADSPI module clock disabled
		 * 1:  QUADSPI module clock enabled
		 * */
		uint8_t QSPIEN : 1;

		uint32_t _30_BITS   : 30 ; /*30 Reserved ---> unused BITS*/

	}BITS;

}RCC_AHB3ENR_REG_TypeDef;


/*
 *
 * ADDRESS : 0x3C is not used
 *
 * */


/*
======================================================================================================================================================
======================================================================================================================================================
 */




/*RCC AHB3 peripheral reset register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x40
 *
 * Reset value: 0x0000 0000
 *
 * */
typedef union
{
	uint32_t _4__BYTES ;

	struct
	{
		/*
				======================================================================================================================================================


															THESE NEXT BITS ARE USED TO ENABLE TIM 2->7 + TIM 12->14 CLOCK


				======================================================================================================================================================
		 */

		/*
		 * TIM2 Enable clock
		 *
		 * 0: TIM2 clock is disabled
		 * 1: TIM2 clock is enabled
		 * */
		uint8_t TIM2EN : 1;

		/*
		 * TIM3 Enable clock
		 *
		 * 0: TIM3 Disable clock
		 * 1: TIM3  Enable clock
		 * */
		uint8_t TIM3EN : 1;

		/*
		 * TIM4  Enable clock
		 *
		 * 0: TIM4  Disable clock
		 * 1: TIM4  Enable clock
		 * */
		uint8_t TIM4EN : 1;

		/*
		 * TIM5 Enable clock
		 *
		 * 0: does Disable clock
		 * 1: TIM5 Enable clock
		 * */
		uint8_t TIM5EN : 1;

		/*
		 * TIM6 Enable clock
		 *
		 * 0:  TIM6 Disable clock
		 * 1:  TIM6 Enable clock
		 * */
		uint8_t TIM6EN : 1;

		/*
		 * TIM7  Enable clock
		 *
		 * 0: TIM7  Disable clock
		 * 1: TIM7  Enable clock
		 * */
		uint8_t TIM7EN : 1;


		/*
		 * TIM12 Enable clock
		 *
		 * 0: TIM12 Disable clock
		 * 1: TIM12 Enable clock
		 * */
		uint8_t TIM12EN : 1;

		/*
		 * TIM13 Enable clock
		 *
		 * 0: TIM13 Disable clock
		 * 1: TIM13 Enable clock
		 * */
		uint8_t TIM13EN : 1;

		/*
		 * TIM14 Enable clock
		 *
		 * 0: TIM14 Disable clock
		 * 1: TIM14 Enable clock
		 * */
		uint8_t TIM14EN : 1;


		uint8_t _2_BITS   : 2 ; /*2 Reserved ---> unused BITS*/

		/*
		 * Window watchdog Enable clock
		 *
		 * 0: Window watchdog Disable clock
		 * 1: Window watchdog Enable clock
		 * */
		uint8_t WWDGEN : 1;

		uint8_t _2_BITS__   : 2 ; /*2 Reserved ---> unused BITS*/


		/*
				======================================================================================================================================================


										 THESE NEXT BITS ARE USED TO ENABLE COMM PROTOCOLS CLOCK


				======================================================================================================================================================
		 */

		/*
		 * SPI2  Enable clock
		 *
		 * 0: SPI2 Disable clock
		 * 1: SPI2 Enable clock
		 * */
		uint8_t SPI2EN : 1;

		/*
		 * SPI3 Enable clock
		 *
		 * 0: SPI3 Disable clock
		 * 1: SPI3 Enable clock
		 * */
		uint8_t SPI3EN : 1;

		/*
		 * SPDIF-Rx  Enable clock
		 *
		 * 0: SPDIF-Rx  Disable clock
		 * 1: SPDIF-Rx Enable clock
		 * */
		uint8_t SPDIFRXEN : 1;

		/*
		 * USART2  Enable clock
		 *
		 * 0: USART2 Disable clock
		 * 1: USART2 Enable clock
		 * */
		uint8_t USART2EN : 1;

		/*
		 * USART3 Enable clock
		 *
		 * 0: USART3 Disable clock
		 * 1: USART3 Enable clock
		 * */
		uint8_t USART3EN : 1;


		/*
		 * USART4 Enable clock
		 *
		 * 0: USART4 Disable clock
		 * 1: USART4 Enable clock
		 * */
		uint8_t USART4EN : 1;

		/*
		 * USART4  Enable clock
		 *
		 * 0: USART4 Disable clock
		 * 1: USART4 Enable clock
		 * */
		uint8_t USART5EN : 1;



		/*
		 * I2C1 Enable clock
		 *
		 * 0: I2C1 Disable clock
		 * 1: I2C1 Enable clock
		 * */
		uint8_t I2C1EN : 1;

		/*
		 * I2C2  Enable clock
		 *
		 * 0: I2C2 Disable clock
		 * 1: I2C2 Enable clock
		 * */
		uint8_t I2C2EN : 1;

		/*
		 * I2C3 Enable clock
		 *
		 * 0: I2C3 Disable clock
		 * 1: I2C3 Enable clock
		 * */
		uint8_t I2C3EN : 1;

		/*
		 * FMPI2C1  Enable clock
		 *
		 * 0: FMPI2C1 Disable clock
		 * 1: FMPI2C1 Enable clock
		 * */
		uint8_t IFMPI2C1EN : 1;

		/*
		 * CAN1  Enable clock
		 *
		 * 0: CAN1 Disable clock
		 * 1: CAN1 Enable clock
		 * */
		uint8_t CAN1EN : 1;

		/*
		 * CAN2 Enable clock
		 *
		 * 0: CAN2 Disable clock
		 * 1: CAN2 Enable clock
		 * */
		uint8_t CAN2EN : 1;

		/*
		 *  CEC Enable clock
		 *
		 * 0: CEC Disable clock
		 * 1: CEC Enable clock
		 * */
		uint8_t CECEN : 1;

		/*
		 *   Power interface  Enable clock
		 *
		 * 0:  Power interface Disable clock
		 * 1: Power interface Enable clock
		 * */
		uint8_t PWREN : 1;

		/*
		 *  DAC interface  Enable clock
		 *
		 * 0: DAC Disable clock
		 * 1: DAC  Enable clock
		 * */
		uint8_t DACEN : 1;

		uint8_t _2_BITS___   : 2 ; /*2 Reserved ---> unused BITS*/

	}BITS;

}RCC_APB1ENR_REG_TypeDef;




/*
======================================================================================================================================================
======================================================================================================================================================
 */




/*RCC APB2 peripheral clock enable register
 *
 * 32 Bits register used to control the RCC
 *
 * Address offset: 0x44
 *
 * Reset value: 0x0000 0000
 *
 * */
typedef union
{
	uint32_t _4__BYTES ;

	struct
	{
		/*
		 * TIM1 reset
		 *
		 * 0: does not reset TIM1
		 * 1: resets TIM1
		 * */
		uint8_t TIM1EN : 1;

		/*
		 * TIM8 reset
		 *
		 * 0: does not reset TIM8
		 * 1: resets TIM8
		 * */
		uint8_t TIM8EN : 1;

		uint8_t _2_BITS   : 2 ; /*2 Reserved ---> unused BITS*/

		/*
		 * USART1 reset
		 *
		 * 0: does not reset USART1
		 * 1: resets USART1
		 * */
		uint8_t USART1EN : 1;

		/*
		 * USART6 reset
		 *
		 * 0: does not reset USART6
		 * 1: resets USART6
		 * */
		uint8_t USART6EN : 1;

		uint8_t _2_BITS_   : 2 ; /*2 Reserved ---> unused BITS*/

		/*
		 * ADC reset
		 *
		 * 0: does not reset ADC
		 * 1: resets ADC
		 * */
		uint8_t ADC1EN : 1;


		/*
		 * ADC reset
		 *
		 * 0: does not reset ADC
		 * 1: resets ADC
		 * */
		uint8_t ADC2EN : 1;


		/*
		 * ADC reset
		 *
		 * 0: does not reset ADC
		 * 1: resets ADC
		 * */
		uint8_t ADC3EN : 1;


		/*
		 * SDIO reset
		 *
		 * 0: does not reset SDIO
		 * 1: resets SDIO
		 * */
		uint8_t SDIOEN : 1;

		/*
		 * SPI1 reset
		 *
		 * 0: does not reset SPI1
		 * 1: resets SPI1
		 * */
		uint8_t SPI1EN : 1;

		/*
		 * SPI4 reset
		 *
		 * 0: does not reset SPI4
		 * 1: resets SPI4
		 * */
		uint8_t SPI4EN : 1;

		/*
		 * System configuration controller reset
		 *
		 * 0: does not reset SYSCFG
		 * 1: resets SYSCFG
		 * */
		uint8_t SYSCFGEN : 1;

		uint8_t BIT_15   : 1 ; /*1 Reserved ---> unused BIT*/

		/*
		 * TIM9 reset
		 *
		 * 0: does not reset TIM9
		 * 1: resets TIM9
		 * */
		uint8_t TIM9EN : 1;

		/*
		 * TIM10 reset
		 *
		 * 0: does not reset TIM10
		 * 1: resets TIM10
		 * */
		uint8_t TIM10EN : 1;

		/*
		 * TIM11 reset
		 *
		 * 0: does not reset TIM11
		 * 1: resets TIM11
		 * */
		uint8_t TIM11EN : 1;

		uint8_t _3_BITS   : 3 ; /*3 Reserved ---> unused BITS*/

		/*
		 * SAI1 reset
		 *
		 * 0: does not reset SAI1
		 * 1: resets SAI1
		 * */
		uint8_t SAI1EN : 1;

		/*
		 * SAI2 reset
		 *
		 * 0: does not reset SAI2
		 * 1: resets SAI2
		 * */
		uint8_t SAI2EN : 1;

		uint8_t _8_BITS ; /*8 Reserved ---> unused BITS*/

	}BITS;

}RCC_APB2ENR_REG_TypeDef;

/***********************************************             GPIO REGISTER DEFINITION STRUCT               ***********************************************/
typedef struct
{
	volatile uint32_t  MODER ;			/*GPIO PORT MODE REGISTER*/
	volatile uint32_t  OTYPER;          /*GPIO PORT OUTPUT TYPE REGISTER*/
	volatile uint32_t  OSPEEDR;         /*GPIO PORT OUTPUT SPEED REGISTER*/
	volatile uint32_t  PUPDR;           /*GPIO PORT PULL UP/DOWN REGISTER*/
	volatile uint32_t  IDR;             /*GPIO INPUT DATA REGISTER*/
	volatile uint32_t  ODR;             /*GPIO OUTPUT DATA REGISTER*/
	volatile uint32_t  BSRR;            /*GPIO BIT RE/SET REGISTER*/
	volatile uint32_t  LCKR;            /*GPIO PORT LOCK REGISTER*/
	volatile uint32_t  AFR[2];          /*GPIO PORT ALTERNATE FUNCTION REGISTER*/
}GPIO_REG_DEF_T;

/*
======================================================================================================================================================
======================================================================================================================================================
 */
//typedef struct
//{
//
//	uint32_t LISR;
//	uint32_t HISR;
//	uint32_t LIFCR;
//	uint32_t HIFCR;
//
//	uint16_t *SxCR1;
//	uint16_t *SxCR2;
//
//	uint16_t *SxPAR1;
//	uint16_t *SxPAR2;
//
//	uint16_t *SxM0AR1;
//	uint16_t *SxM0AR2;
//
//	uint16_t *SxM1AR1;
//	uint16_t *SxM1AR2;
//
//	uint16_t *SxFCR1;
//	uint16_t *SxFCR2;
//
//}DMA_STRUCT_TYPEDEF;

typedef struct
{

	uint32_t SxCR;
	uint32_t DMA_SxNDTR;
	uint32_t SxPAR;
	uint32_t SxM0AR;
	uint32_t SxM1AR;
	uint32_t SxFCR;

}DMA_STREAM_CTL_STRUCT;

typedef struct
{

	uint32_t LISR;
	uint32_t HISR;
	uint32_t LIFCR;
	uint32_t HIFCR;

	DMA_STREAM_CTL_STRUCT STREAM_CTL[8];

}DMA_STRUCT_TYPEDEF;

/***********************************************             SCB DEFINITION STRUCT               ***********************************************/
typedef struct
{
	uint8_t MEM_fault_SHPR1;

	uint8_t BUS_fault_SHPR1;

	uint8_t USAGE_fault_SHPR1;

	uint8_t RESERVED_SHPR1;

	uint16_t RESERVED_SHPR2;

	uint8_t RESERVED2_SHPR2;

	uint8_t SVCall_SHPR2;

	uint16_t RESERVED_SHPR3;

	uint8_t PendSV_SHPR3;

	uint8_t Systick_SHPR3;

}SCB_SHPR1_2_3_REG_DEF_T;
/***********************************************             NVIC DEFINITION STRUCT               ***********************************************/
typedef struct {
    uint32_t NVIC_ISER_X[8];        // 0xE000E100 - 0xE000E11F (8 registers, 32 bytes)
    uint32_t RESERVED_NVIC_1_[24];  // 0xE000E120 - 0xE000E17F (24 registers, 96 bytes)
    uint32_t NVIC_ICER_X[8];        // 0xE000E180 - 0xE000E19F (8 registers, 32 bytes)
    uint32_t RESERVED_NVIC_2_[24];  // 0xE000E1A0 - 0xE000E1FF (24 registers, 96 bytes)
    uint32_t NVIC_ISPR_X[8];        // 0xE000E200 - 0xE000E21F (8 registers, 32 bytes)
    uint32_t RESERVED_NVIC_3_[24];
    uint32_t NVIC_ICPR_X[8];        // 0xE000E280 - 0xE000E29F (8 registers, 32 bytes)
    uint32_t RESERVED_NVIC_4_[24];
    uint32_t NVIC_IABR_X[8];        // 0xE000E300 - 0xE000E31F (8 registers, 32 bytes)
    uint32_t RESERVED_NVIC_5_[56];  // 0xE000E320 - 0xE000E3FF (56 registers, 224 bytes)
    uint8_t  NVIC_IPR_X[240];       // 0xE000E400 - 0xE000E4EF (240 registers, 240 bytes)
    uint32_t RESERVED_NVIC_6_[644]; // 0xE000E4F0 - 0xE000EEFF (644 registers, 2576 bytes)
    uint32_t NVIC_STIR;             // 0xE000EF00 - 0xE000EF03 (1 register, 4 bytes)
} NVIC_REG_DEF_T;

/***********************************************              SYSTEM CONFIGURATION PERIPHERAL STRUCT DEFINITION           ***********************************************/

typedef struct
{
	uint32_t SYSCFG_MEMRMP;

	uint32_t SYSCFG_PMC;

	uint32_t  SYSCFG_EXTICRX[4];

	uint32_t RESERVED[2];

	uint32_t SYSCFG_CMPCR;

	uint32_t RESERVED_2[2];

	uint32_t SYSCFG_CFGR;

}SYSCFG_EXTICR1_STRUCT_DEF;

/***********************************************             EXTI PERIPHERAL STRUCT DEFINITION              ***********************************************/
typedef struct {
	uint32_t EXTI_IMR;
	uint32_t EXTI_EMR;
	uint32_t EXTI_RTSR;
	uint32_t EXTI_FTSR;
	uint32_t EXTI_SWIER;
	uint32_t EXTI_PR;

}EXTI_REG_TYPEDEF;
/***********************************************              APB2               ***********************************************/
/***********************************************              UART               ***********************************************/
typedef struct {

	uint32_t SR_REG  ; //Status register
	uint32_t DR_REG  ; //Data register
	uint32_t BBR_REG ; //Baud rate register
	uint32_t CR1_REG ; //Control register 1
	uint32_t CR2_REG ; //Control register 2
	uint32_t CR3_REG ; //Control register 3
	uint32_t GTPR_REG; //Guard time and prescaler register

}UARTx_TYPEDEF_STRUCT;
/***********************************************              SPI               ***********************************************/
typedef struct {

	uint32_t CR1_REG      ; //Control register 1
	uint32_t CR2_REG      ; //Control register 2
	uint32_t SR_REG       ; //Status register
	uint32_t DR_REG       ; //Data register
	uint32_t CRCP_REG     ; //CRC polynomial register
	uint32_t RxCRC_REG    ; //RX CRC register
	uint32_t TxCRC_REG    ; //TX CRC register
	uint32_t I2SCFGR_REG  ; //I2S configuration register
	uint32_t I2SP_REG     ; //I2S prescaler

}SPIx_TYPEDEF_STRUCT;
/***********************************************              CORE PERIPHERAL DEFINITIONS               ***********************************************/

/******************************                 systick    Type----Required privilege----  RESET VAL         ***********************************************/
#define STK_CTRL_REG  (*(volatile uint32_t* const)STK_CTRL_REG_BASE_ADDRESS)		/*RW*****priviliged**************0x0*/
#define STK_RELOAD_REG  (*(volatile uint32_t* const)STK_LOAD_REG_BASE_ADDRESS)		/*RW*****priviliged**************UNKNOWN*/
#define STK_VAL_REG   (*(volatile uint32_t* const)STK_VAL_REG_BASE_ADDRESS)		    /*RW*****priviliged**************UNKNOWN*/

#define STK_CALIB_REG (*(volatile uint32_t* const)STK_CALIB_REG_BASE_ADDRESS)      /*RO******priviliged-             0xC000 0000*/

/***********************************************             GPIO REGISTERS PERIPHERAL DEFINITIONS               ***********************************************/
#define GPIO_A_REG         (*(GPIO_REG_DEF_T * const)GPIOA_BASE_ADDRESSES)
#define GPIO_B_REG         (*(GPIO_REG_DEF_T * const)GPIOB_BASE_ADDRESSES)
#define GPIO_C_REG         (*(GPIO_REG_DEF_T * const)GPIOC_BASE_ADDRESSES)
#define GPIO_D_REG         (*(GPIO_REG_DEF_T * const)GPIOD_BASE_ADDRESSES)
#define GPIO_E_REG         (*(GPIO_REG_DEF_T * const)GPIOE_BASE_ADDRESSES)
#define GPIO_F_REG         (*(GPIO_REG_DEF_T * const)GPIOF_BASE_ADDRESSES)
#define GPIO_G_REG         (*(GPIO_REG_DEF_T * const)GPIOG_BASE_ADDRESSES)
#define GPIO_H_REG         (*(GPIO_REG_DEF_T * const)GPIOH_BASE_ADDRESSES)

#define GPIOA		(GPIO_REG_DEF_T * const)0x40020000UL
#define GPIOB       (GPIO_REG_DEF_T * const)0x40020400UL
#define GPIOC       (GPIO_REG_DEF_T * const)0x40020800UL
#define GPIOD       (GPIO_REG_DEF_T * const)0x40020C00UL
#define GPIOE       (GPIO_REG_DEF_T * const)0x40021000UL
#define GPIOF       (GPIO_REG_DEF_T * const)0x40021400UL
#define GPIOG       (GPIO_REG_DEF_T * const)0x40021800UL
#define GPIOH       (GPIO_REG_DEF_T * const)0x40021C00UL

#define GPIO_PORT_CALC(PORT_ID)      (*(GPIO_REG_DEF_T * const)(GPIOA_BASE_ADDRESSES+PORT_ID*0x400 ))

/***********************************************             RCC REGISTERS PERIPHERAL DEFINITIONS               ***********************************************/
#define RCC_CR_REG (*(volatile RCC_CR_REG_TypeDef * const)RCC_CR_REG_BASE_ADDRESSES)
#define RCC_PLLCFGR_REG (*(volatile RCC_PLLCFGR_REG_TypeDef * const)RCC_PLL_CFGR_BASE_ADDRESSES)
#define RCC_CFGR_REG (*(volatile RCC_CFGR_REG_TypeDef * const)RCC_CFGR_BASE_ADDRESSES)
#define RCC_CIR_REG (*(volatile RCC_CIR_REG_TypeDef * const)RCC_CIR_BASE_ADDRESSES)
#define RCC_AHB1RSTR_REG (*(volatile RCC_AHB1RSTR_REG_TypeDef * const)RCC_AHB1_RSTR_BASE_ADDRESSES)
#define RCC_AHB2RSTR_REG (*(volatile RCC_AHB2RSTR_REG_TypeDef * const)RCC_AHB2_RSTR_BASE_ADDRESSES)
#define RCC_AHB3RSTR_REG (*(volatile RCC_AHB3RSTR_REG_TypeDef * const)RCC_AHB3_RSTR_BASE_ADDRESSES)
#define RCC_APB1RSTR_REG (*(volatile RCC_APB1RSTR_REG_TypeDef * const )RCC_APB1_RSTR_BASE_ADDRESSES)
#define RCC_APB2RSTR_REG (*(volatile RCC_APB2RSTR_REG_TypeDef * const )RCC_APB2_RSTR_BASE_ADDRESSES)
#define RCC_AHB1ENR_REG (*(volatile RCC_AHB1ENR_REG_TypeDef * const )RCC_AHB1_ENR_BASE_ADDRESSES)
#define RCC_AHB2ENR_REG (*(volatile RCC_AHB2ENR_REG_TypeDef * const )RCC_AHB2_ENR_BASE_ADDRESSES)
#define RCC_AHB3ENR_REG (*(volatile RCC_AHB3ENR_REG_TypeDef * const )RCC_AHB3_ENR_BASE_ADDRESSES)
#define RCC_APB1ENR_REG (*(volatile RCC_APB1ENR_REG_TypeDef * const)RCC_APB1_ENR_BASE_ADDRESSES)
#define RCC_APB2ENR_REG (*(volatile RCC_APB2ENR_REG_TypeDef * const)RCC_APB2_ENR_BASE_ADDRESSES)

/***********************************************            FLASH REGISTERS PERIPHERAL DEFINITIONS               ***********************************************/

#define FLASH_ACR_REG 		(*(volatile uint32_t * const )0x40023C00)

/***********************************************             SCB REGISTERS PERIPHERAL DEFINITIONS               ***********************************************/
#define SCB_ICSR_REG		(*(volatile uint32_t * const )SCB_ICSR_REG_BASE_ADDRESS)
#define SCB_AIRCR_REG 		(*(volatile uint32_t * const )SCB_AIRCR_REG_BASE_ADDRESS)

							/**like nvic priorities to set priority write in bits 4 to 7	*/
#define SCB_SHPR_REGS 		(*(volatile SCB_SHPR1_2_3_REG_DEF_T * const)SCB_SHPR1_REG_BASE_ADDRESS)

#define SCB_SHCSR_REG       (*(volatile uint32_t * const )SCB_SHCSR_REG_BASE_ADDRESS)

#define SCB_CFSR_REG        (*(volatile uint32_t * const )SCB_CFSR_REG_BASE_ADDRESS)

#define SCB_HFSR_REG        (*(volatile uint32_t * const )SCB_HFSR_REG_BASE_ADDRESS)

#define SCB_MMAR_REG 		(*(volatile uint32_t * const)SCB_MMAR_REG_BASE_ADDRESS)

#define SCB_BFAR_REG 		(*(volatile uint32_t * const)SCB_BFAR_REG_BASE_ADDRESS)

#define SCB_AFSR_REG 		(*(volatile uint32_t * const)SCB_AFSR_REG_BASE_ADDRESS)

/***********************************************             NVIC REGISTERS PERIPHERAL DEFINITIONS               ***********************************************/
#define NVIC_REG 	(*(volatile NVIC_REG_DEF_T * const )NVIC_ISER_REG_BASE_ADDRESS)

/***********************************************             SYSTEM CONFIGURATION PERIPHERAL DEFINITIONS               ***********************************************/
#define SYSCFG_REG (*(volatile SYSCFG_EXTICR1_STRUCT_DEF * const )SYSCFG_MEMRMP_REG_BASE_ADDRESS)

/***********************************************             EXTI CONFIGURATION PERIPHERAL DEFINITIONS               ***********************************************/

#define EXTI_REG (*(volatile EXTI_REG_TYPEDEF * const)EXTI_IMR_REG_BASE_ADDRESS)

/***********************************************             DMA PERIPHERAL DEFINITIONS               ***********************************************/

#define DMA1_REG (*(volatile DMA_STRUCT_TYPEDEF * const)DMA1_BASE_ADDRESSES)
#define DMA2_REG (*(volatile DMA_STRUCT_TYPEDEF * const)DMA2_BASE_ADDRESSES)

/*********************************************** UART PERIPHERAL DEFINITIONS	****************************************************************/
#define UART1_REG/*_SR*/     (*(volatile UARTx_TYPEDEF_STRUCT * const )(UART1_REG_BASE_ADDRESS))
#define UART1_DR_REG   (*(volatile uint32_t * const )(UART1_REG_BASE_ADDRESS+UARTx_DR_REG_OFFSET))
//#define UART1_BBR_REG  (*(volatile uint32_t * const )(UART1_REG_BASE_ADDRESS+UARTx_BBR_REG_OFFSET))
//#define UART1_CR1_REG  (*(volatile uint32_t * const )(UART1_REG_BASE_ADDRESS+UARTx_CR1_REG_OFFSET))
//#define UART1_CR2_REG  (*(volatile uint32_t * const )(UART1_REG_BASE_ADDRESS+UARTx_CR2_REG_OFFSET))
//#define UART1_CR3_REG  (*(volatile uint32_t * const )(UART1_REG_BASE_ADDRESS+UARTx_CR3_REG_OFFSET))
//#define UART1_CR4_REG  (*(volatile uint32_t * const )(UART1_REG_BASE_ADDRESS+UARTx_CR4_REG_OFFSET))
//#define UART1_GTPR_REG (*(volatile uint32_t * const )(UART1_REG_BASE_ADDRESS+UARTx_GTPR_REG_OFFSET))

#define UART6_REG/*_SR*/     (*(volatile UARTx_TYPEDEF_STRUCT * const )(UART6_REG_BASE_ADDRESS))

/*********************************************** SPI PERIPHERAL DEFINITIONS	****************************************************************/
#define SPI1_REG			(*(volatile SPIx_TYPEDEF_STRUCT *const)(SPI1_REG_BASE_ADDRESS))
#define SPI2_REG			(*(volatile SPIx_TYPEDEF_STRUCT *const)(SPI2_REG_BASE_ADDRESS))
#define SPI3_REG			(*(volatile SPIx_TYPEDEF_STRUCT *const)(SPI3_REG_BASE_ADDRESS))
#define SPI4_REG			(*(volatile SPIx_TYPEDEF_STRUCT *const)(SPI4_REG_BASE_ADDRESS))

#endif
