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

#define P1			GPIO_PIN_1
#define P2			GPIO_PIN_2
#define P3			GPIO_PIN_3
#define P4			GPIO_PIN_4
#define P5			GPIO_PIN_5
#define P6			GPIO_PIN_6
#define P7			GPIO_PIN_7
#define P8			GPIO_PIN_8
#define P9			GPIO_PIN_9
#define P10		GPIO_PIN_10
#define P11		GPIO_PIN_11
#define P12		GPIO_PIN_12
#define P13		GPIO_PIN_13
#define P14		GPIO_PIN_14
#define P15		GPIO_PIN_15

//(GPIOA, GPIO_PIN_10) Control
#define PAS10			GPIOA -> ODR |= P10;
#define PARS10			GPIOA -> ODR &= ~P10;

//Cols = PC9, PB6, PB1, PA6, PC8, PB2, PC6, PA11
#define PCS9				GPIOC -> ODR |= P9;
#define PBS6				GPIOB -> ODR |= P6;
#define PBS1				GPIOB -> ODR |= P1;
#define PAS6				GPIOA -> ODR |= P6;
#define PCS8				GPIOC -> ODR |= P8;
#define PBS2				GPIOB -> ODR |= P2;
#define PCS6				GPIOC -> ODR |= P6;
#define PAS11			GPIOA -> ODR |= P11;

#define PCRS9				GPIOC -> ODR &= ~P9;
#define PBRS6				GPIOB -> ODR &= ~P6;
#define PBRS1				GPIOB -> ODR &= ~P1;
#define PARS6				GPIOA -> ODR &= ~P6;
#define PCRS8				GPIOC -> ODR &= ~P8;
#define PBRS2				GPIOB -> ODR &= ~P2;
#define PCRS6				GPIOC -> ODR &= ~P6;
#define PARS11			GPIOA -> ODR &= ~P11;

//Rows = PA7, PC5, PA12, PB8, PB12, PB9, PC7, PA9
#define PAS7				GPIOA -> ODR |= P7
#define PCS5				GPIOC -> ODR |= P5
#define PAS12			GPIOA -> ODR |= P12
#define PBS8				GPIOB -> ODR |= P8
#define PBS12			GPIOB -> ODR |= P12
#define PBS9				GPIOB -> ODR |= P9
#define PCS7				GPIOC -> ODR |= P7
#define PAS9				GPIOA -> ODR |= P9

#define PARS7			GPIOA -> ODR &= ~P7
#define PCRS5			GPIOC -> ODR &= ~P5
#define PARS12			GPIOA -> ODR &= ~P12
#define PBRS8			GPIOB -> ODR &= ~P8
#define PBRS12			GPIOB -> ODR &= ~P12
#define PBRS9			GPIOB -> ODR &= ~P9
#define PCRS7			GPIOC -> ODR &= ~P7
#define PARS9			GPIOA -> ODR &= ~P9

void Dotmatrix_ALLON();			// 도트 매트릭스 전체 점등
void Dotmatrix_Setup();				// 도트 매트릭스 전체 Reset
void Col_Setup();							// Col(열) Reset
void Row_Control();						// Row(행)을 통제하며 Col_Control() 을 컨트롤 함
void Col_Control();                      // Col_Control_1() 을 컨트롤 함
void Col_Control_1();					// Col(열)을 통제함

#endif /* INC_DOTMARTRIX_H_ */
