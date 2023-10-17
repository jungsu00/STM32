/*
 * DotMartrix.c
 *
 *  Created on: Oct 16, 2023
 *      Author: user
 */

#include "DotMartrix.h"

	// PC8 = 1,  PC6 = 2,    PC5 = 3,    PA12 = 4,    PA11 = 5,  PB12 = 6,  PB2 = 7,    PB1 = 8
	// PC9 = 9,  PB8 = 10,  PB9 = 11,  PA6 = 12,    PA7 = 13,   PB6 = 14,  PC7 = 15,  PA9 = 16

	// 9,   14,   8,   12,   1,     7,     2,     5 (+)
	// 13,   3,   4,   10,   6,   11,   15,   16 (-)

	// PC9,   PB6,      PB1,   PA6,    PC8,   PB2,   PC6,   PA11
	// PA7,   PC5,   PA12,   PB8,   PB12,   PB9,   PC7,   PA9

int Dotmatrix_Control_Y[8][8] = {
	{1, 1, 0, 0, 0, 0, 1, 1},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 0, 0}
};

int Dotmatrix_Control_E[8][8] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 0, 0, 0, 0, 0, 0},
	{1, 1, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 0, 0, 0, 0, 0, 0},
	{1, 1, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

int Dotmatrix_Control_S[8][8] = {
	{0, 1, 1, 1, 1, 1, 1, 0},
	{1, 1, 0, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 0, 0, 0, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1},
	{0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 1, 1},
	{0, 1, 1, 1, 1, 1, 1, 0}
};

void Dotmatrix_ALLON(){
	  HAL_GPIO_WritePin(GPIOA, P6 | P11 , GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOB, P6 | P2 | P1, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOC, P9 | P8 | P6 , GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOA, P7 | P12 | P9 , GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, P8 | P12 | P9 , GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOC, P5 | P7, GPIO_PIN_RESET);
}

void Dotmatrix_Setup(){
	  HAL_GPIO_WritePin(GPIOA, P6 | P11 , GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, P6 | P2 | P1, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOC, P9 | P8 | P6 , GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOA, P7 | P12 | P9 , GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, P8 | P12 | P9 , GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOC, P5 | P7, GPIO_PIN_RESET);
}

void Col_Setup(){
	  HAL_GPIO_WritePin(GPIOA, P7 | P12 | P9 , GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, P8 | P12 | P9 , GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOC, P5 | P7, GPIO_PIN_RESET);
}

//PC9, PB6, PB1, PA6, PC8, PB2, PC6, PA11
//PA7, PC5, PA12, PB8, PB12, PB9, PC7, PA9

void Row_Control(void) {
	for(int Control = 0; Control <30000; Control++){
		for(int Row = 0; Row < 8; Row++){
			if(Row == 0){
				Col_Setup();
				Col_Control(Control, Row);
				PCS9;
				PCRS9;
			}
			else if(Row == 1){
				Col_Setup();
				Col_Control(Control, Row);
				PBS6;
				PBRS6;
			}
			else if(Row == 2){
				Col_Setup();
				Col_Control(Control, Row);
				PBS1;
				PBRS1;
			}
			else if(Row == 3){
				Col_Setup();
				Col_Control(Control, Row);
				PAS6;
				PARS6;
			}
			else if(Row == 4){
				Col_Setup();
				Col_Control(Control, Row);
				PCS8;
				PCRS8;
			}
			else if(Row == 5){
				Col_Setup();
				Col_Control(Control, Row);
				PBS2;
				PBRS2;
			}
			else if(Row == 6){
				Col_Setup();
				Col_Control(Control, Row);
				PCS6;
				PCRS6;
			}
			else if(Row == 7){
				Col_Setup();
				Col_Control(Control, Row);
				PAS11;
				PARS11;
			}
		}
	}
}

void Col_Control(int Control, int Row){
	if(Control >= 0 && Control <= 10000 ){
		for(int Col = 0; Col < 8; Col++){
			if(Dotmatrix_Control_Y[Row][Col] == 0) {
				Col_Control_1(Col);
			}
		}
	}
	else if(Control >= 10000 && Control <= 20000){
		for(int Col = 0; Col < 8; Col++){
			if(Dotmatrix_Control_E[Row][Col] == 0) {
				Col_Control_1(Col);
			}
		}
	}
	else if(Control >= 20000 && Control <= 30000){
		for(int Col = 0; Col < 8; Col++){
			if(Dotmatrix_Control_S[Row][Col] == 0) {
				Col_Control_1(Col);
			}
		}
	}
}

void Col_Control_1(int Col){
	if(Col == 0) PAS7;					// Dotmatrix_Control[x][0]
	else if(Col == 1) PCS5;			// Dotmatrix_Control[x][1]
	else if(Col == 2) PAS12;			// Dotmatrix_Control[x][2]
	else if(Col == 3) PBS8;			// Dotmatrix_Control[x][3]
	else if(Col == 4) PBS12;			// Dotmatrix_Control[x][4]
	else if(Col == 5) PBS9;			// Dotmatrix_Control[x][5]
	else if(Col == 6) PCS7;			// Dotmatrix_Control[x][6]
	else if(Col == 7) PAS9;			// Dotmatrix_Control[x][7]
}
