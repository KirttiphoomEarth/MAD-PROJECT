/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f7xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "main.h"
#include "stm32f7xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */
extern uint32_t CountTim4;
extern uint32_t CountTim3_PrintCheck;
//extern bool NewState[8][8];

extern bool readState[8][8];
uint8_t currentState[8][8][6][2];

//bool OldState[8][8];
//bool State[8][8];
/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M7 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F7xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f7xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */
	CountTim4++;
	//displayNumber(CountTim4);
//	displayOld_State(OldState[7][0], OldState[6][0], OldState[5][0], OldState[4][0]);
//	displayNew_State(NewState[7][0], NewState[6][0], NewState[5][0], NewState[4][0]);
  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */
	//================================ Scan Board ================================//
	//	 a4 = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_8);
	//	 a3 = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_7);
	//	 a2 = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_9);
	//	 a1 = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_1);
//	NewState[7][0] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_8);
//	NewState[6][0] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_7);
//	NewState[5][0] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_9);
//	NewState[4][0] = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_1);

//	readState[7][0] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_8);// [row][col]
//	readState[6][0] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_7);
//	readState[5][0] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_9);
//	readState[4][0] = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_1);
//	extern bool extern bool readState[8][8];[8][8];
	//==================== Colum [0] ======================//
	readState[7][0][1] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_10);
	readState[6][0] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_12);
	readState[5][0] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_6);
	readState[4][0] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_7);
	readState[3][0] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15);
	readState[2][0] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2);
	readState[1][0] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3);
	readState[0][0] = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4);

	//==================== Colum [1] ======================//
	readState[7][1] = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5);
	readState[6][1] = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_6);
	readState[5][1] = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_7);
	readState[4][1] = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3);
	readState[3][1] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_1);
	readState[2][1] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_0);
	readState[1][1] = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_1);
	readState[0][1] = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_0);

	//==================== Colum [2] ======================//
	readState[7][2] = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_0);
	readState[6][2] = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_1);
	readState[5][2] = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9);
	readState[4][2] = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_12);
	readState[3][2] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_11);
	readState[2][2] = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_2);
	readState[1][2] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	readState[0][2] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);

	//==================== Colum [3] ======================//
	readState[7][3] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0);
	readState[6][3] = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_3);
	readState[5][3] = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2);
	readState[4][3] = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3);
	readState[3][3] = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2);
	readState[2][3] = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4);
	readState[1][3] = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5);
	readState[0][3] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_2);

	//==================== Colum [4] ======================//
	readState[7][4] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_8);
	readState[6][4] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_9);
	readState[5][4] = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_1);
	readState[4][4] = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_6);
	readState[3][4] = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_15);
	readState[2][4] = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_10);
	readState[1][4] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
	readState[0][4] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_3);

	//==================== Colum [5] ======================//
	readState[7][5] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_5);
	readState[6][5] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_10);
	readState[5][5] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8);
	readState[4][5] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);
	readState[3][5] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
	readState[2][5] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);
	readState[1][5] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);
	readState[0][5] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);

	//==================== Colum [6] ======================//
	readState[7][6] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7);
	readState[6][6] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);
	readState[5][6] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
	readState[4][6] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
	readState[3][6] = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_13);
	readState[2][6] = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_12);
	readState[1][6] = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_11);
	readState[0][6] = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10);

	//==================== Colum [7] ======================//
	readState[7][7] = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12);
	readState[6][7] = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_14);
	readState[5][7] = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15);
	readState[4][7] = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_13);
	readState[3][7] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_13);
	readState[2][7] = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_12);
	readState[1][7] = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_14);
	readState[0][7] = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10);
  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */

  /* USER CODE END TIM4_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
