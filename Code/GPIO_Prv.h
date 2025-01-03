/*
 * GPIO_Prv.h
 *
 *  Created on: Aug 13, 2024
 *      Author: 20102
 */

#ifndef GPIO_INC_GPIO_PRV_H_
#define GPIO_INC_GPIO_PRV_H_

#define MODER_MASK 0x03
#define MODER_PULL_UP_DOWN_OSPEEDR_PIN_ACCESS 2U

#define PULL_UP_DOWN_MASK 0x03

#define OSPEEDR_REG_MASK 0x03

#define GPIO_PERIPHERAL_NUM  8U

#define AF_REG_MASK  4U
#define AF_PIN_NUM_DIV_MASK 8U
#define AFR_MASK  0x0F

#define ONE_UL     1U
#define PORT_LOCKER 0x1FF
#define PORT_LOCKER_ 0xFF

#define LOCKER_BIT 16U

#define GPIOBSSR_RESET_MASK 16U

#define ZERO_U  0U

#endif /* GPIO_INC_GPIO_PRV_H_ */
