/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId HightTaskHandle;
osThreadId MediumTask02Handle;
osThreadId LowTask03Handle;
osSemaphoreId myBinarySem01Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartHightTask(void const * argument);
void StartMediumTask02(void const * argument);
void StartLowTask03(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of myBinarySem01 */
  osSemaphoreDef(myBinarySem01);
  myBinarySem01Handle = osSemaphoreCreate(osSemaphore(myBinarySem01), 1);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of HightTask */
  osThreadDef(HightTask, StartHightTask, osPriorityHigh, 0, 128);
  HightTaskHandle = osThreadCreate(osThread(HightTask), NULL);

  /* definition and creation of MediumTask02 */
  osThreadDef(MediumTask02, StartMediumTask02, osPriorityNormal, 0, 128);
  MediumTask02Handle = osThreadCreate(osThread(MediumTask02), NULL);

  /* definition and creation of LowTask03 */
  osThreadDef(LowTask03, StartLowTask03, osPriorityLow, 0, 128);
  LowTask03Handle = osThreadCreate(osThread(LowTask03), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartHightTask */
/**
  * @brief  Function implementing the HightTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartHightTask */
void StartHightTask(void const * argument)
{
  /* USER CODE BEGIN StartHightTask */
  /* Infinite loop */
  for(;;)
  {
	  printf("Entered High Task\r\n");
	  printf("Leaving High Task\r\n");
	  osDelay(3000);
  }
  /* USER CODE END StartHightTask */
}

/* USER CODE BEGIN Header_StartMediumTask02 */
/**
* @brief Function implementing the MediumTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartMediumTask02 */
void StartMediumTask02(void const * argument)
{
  /* USER CODE BEGIN StartMediumTask02 */
  /* Infinite loop */
  for(;;)
  {
	  printf("Entered Medium Task\r\n");
	  printf("Leaving Medium Task\r\n");
	  osDelay(3000);
  }
  /* USER CODE END StartMediumTask02 */
}

/* USER CODE BEGIN Header_StartLowTask03 */
/**
* @brief Function implementing the LowTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLowTask03 */
void StartLowTask03(void const * argument)
{
  /* USER CODE BEGIN StartLowTask03 */
  /* Infinite loop */
  for(;;)
  {
	  printf("Entered Low Task\r\n");
	  printf("Leaving Low Task\r\n");
	  osDelay(3000);
  }
  /* USER CODE END StartLowTask03 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
