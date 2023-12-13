/*
 * Systick.c
 *
 *  Created on: Nov 14, 2023
 *      Author: user
 */

#include "main.h"

uint32_t SystemTime;

void HAL_SYSTICK_Callback(void){

	SystemTime++;

  	if(SystemTime % 100 == 0){
  		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
  	}
}
