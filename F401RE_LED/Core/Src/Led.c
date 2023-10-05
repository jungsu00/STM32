/*
 * Led.c
 *
 *  Created on: Oct 5, 2023
 *      Author: user
 */

#include "Led.h"

void Led_Control1(void){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
	HAL_Delay(1000);
}

void Led_Control2(void){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
	HAL_Delay(500);
}

void Led_Control3(void){
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_4);
	HAL_Delay(1000);
}

void Led_Control4(void){
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
	HAL_Delay(500);
}

void Led_Control5(void){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
	HAL_Delay(500);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_10);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
	HAL_Delay(500);
}

void Led_Toggle_Control1(void){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_10);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_4);
}

void Led_Toggle_Control2(void){
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
}
