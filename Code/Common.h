/*
 * COMMON.h
 *
 *  Created on: Aug 13, 2024
 *      Author: 20102
 */

#ifndef COMMON_H_
#define COMMON_H_

typedef float f32_t;
typedef double f64_t;

typedef signed long sint32_t ;

/***********************************************             Common macros               ***********************************************/
#define ONE_U	1U
#define ZERO_U  0U

#define NULL ((void*)0)

/***********************************************             Error Status               ***********************************************/
/*
 * @Error_Status enum
 *
 * */
typedef enum
{

	NOK,
	OK,
	NULL_PTR_ERROR,
	SCB_ERROR,
	NVIC_ERROR,
	SYSCFG_SET_EXTI_ERROR,
	SYSCFG_SET_EXTI_DONE,
	EXTI_INIT_ERROR,
	EXTI_INIT_OK,
	EXTI_IRQ_NUM_ERROR,
	EXTI_CLR_PF_OK,
	EXTI_IRQ_NUM_CALLBACK_SET,
	EXTI_ISR_NULL_PTR_ERROR,
	EXTI_SET_TRIG_OK,
	DMA_REG_ERROR,
	UART_NOK,
	SPI_INIT_ERR,
	SPI_NUM_ERR

}Error_Status_enum_Type;

typedef enum
{
	OFF,
	ON

}Status_TypeDef;


#define _weak_ __attribute__((weak))


#define NULL_Ptr_ERR(PTR) (PTR == NULL)

#endif /* COMMON_H_ */
