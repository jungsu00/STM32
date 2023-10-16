/*
 * DotMartrix.h
 *
 *  Created on: Oct 16, 2023
 *      Author: user
 */

#ifndef INC_DOTMARTRIX_H_
#define INC_DOTMARTRIX_H_

#include "main.h"
#include "gpio.h"

	// PC8 = 1,  PC6 = 2,    PC5 = 3,    PA12 = 4,    PA11 = 5,  PB12 = 6,  PB2 = 7,    PB1 = 8
	// PC9 = 9,  PB8 = 10,  PB9 = 11,  PA6 = 12,    PA7 = 13,   PB6 = 14,  PC7 = 15,  PA9 = 16

	// 9, 14, 8, 12, 1, 7, 2, 5 = PC9, PB6, PB1, PA6, PC8, PB2, PC6, PA11
	// 13, 3, 4, 10, 6, 11, 15, 16 = PA7, PC5, PA12, PB8, PB12, PB9, PC7, PA9

#define GPIO_PIN_1			P1
#define GPIO_PIN_2			P2
#define GPIO_PIN_3			P3
#define GPIO_PIN_4			P4
#define GPIO_PIN_5			P5
#define GPIO_PIN_6			P6
#define GPIO_PIN_7			P7
#define GPIO_PIN_8			P8
#define GPIO_PIN_9			P9
#define GPIO_PIN_10		P10
#define GPIO_PIN_11		P11
#define GPIO_PIN_12		P12
#define GPIO_PIN_13		P13
#define GPIO_PIN_14		P14
#define GPIO_PIN_15		P15

void Dotmartrix_ALLON();

#endif /* INC_DOTMARTRIX_H_ */
