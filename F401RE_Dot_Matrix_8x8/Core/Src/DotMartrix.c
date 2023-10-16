/*
 * DotMartrix.c
 *
 *  Created on: Oct 16, 2023
 *      Author: user
 */

#include "DotMartrix.h"

	// PC8 = 1,  PC6 = 2,    PC5 = 3,    PA12 = 4,    PA11 = 5,  PB12 = 6,  PB2 = 7,    PB1 = 8
	// PC9 = 9,  PB8 = 10,  PB9 = 11,  PA6 = 12,    PA7 = 13,   PB6 = 14,  PC7 = 15,  PA9 = 16

	// 9, 14, 8, 12, 1, 7, 2, 5 = PC9, PB6, PB1, PA6, PC8, PB2, PC6, PA11
	// 13, 3, 4, 10, 6, 11, 15, 16 = PA7, PC5, PA12, PB8, PB12, PB9, PC7, PA9

void Dotmartrix_ALLON(){
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6 | GPIO_PIN_11 , GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6 | GPIO_PIN_2 | GPIO_PIN_1, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_6 , GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7 | GPIO_PIN_12 | GPIO_PIN_9 , GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8 | GPIO_PIN_12 | GPIO_PIN_9 , GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5 | GPIO_PIN_7, GPIO_PIN_RESET);
}

