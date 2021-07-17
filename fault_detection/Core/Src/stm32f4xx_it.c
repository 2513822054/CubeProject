/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
  uint8_t str[20];
  uint8_t txbuf[4] = {0};
  uint8_t rxbuf[4] = {0};

  extern uint32_t count_tim3;
  extern uint8_t PE2;


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
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
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
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line4 interrupt.
  */
void EXTI4_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI4_IRQn 0 */

  /* USER CODE END EXTI4_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
  /* USER CODE BEGIN EXTI4_IRQn 1 */
  if(freq==1000)freq=150000;
  else if(freq==150000)freq=100;
  else freq=1000;
  Write_frequence(0, freq);


  /* USER CODE END EXTI4_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */
//  ADS_Read_All_Raw(&ads, ads_data);




	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	  HAL_SPI_TransmitReceive(&hspi3, txbuf, rxbuf, 2, 10);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	  ads_data[0] = *(uint16_t *)(&rxbuf[2]);
	  //HAL_UART_Transmit(&huart2, ads_data, 2, 5);
	  //sprintf((char*)str,"X=%5d\r\n",((int)ads_data[0]-0x8000)/64);
	  //HAL_UART_Transmit(&huart2, str, 9, 5);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	  HAL_SPI_TransmitReceive(&hspi3, txbuf, rxbuf, 2, 10);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	  ads_data[1] = *(uint16_t *)(&rxbuf[2]);
	  //HAL_UART_Transmit(&huart2, &ads_data[1], 2, 5);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	  HAL_SPI_TransmitReceive(&hspi3, txbuf, rxbuf, 2, 10);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
      if(ads_data[0]<minch1)minch1=ads_data[0];
      if(ads_data[0]>maxch1)maxch1=ads_data[0];
	  Dosomething_tim3();


	  /*
	  ads_data[2] = *(uint16_t *)(&rxbuf[2]);
      if(ads_data[0]<minch1)minch1=ads_data[0];
      if(ads_data[0]>maxch1)maxch1=ads_data[0];
      if(ads_data[1]<minch2)minch2=ads_data[1];
      if(ads_data[1]>maxch2)maxch2=ads_data[1];

      //如果PE2是高电平    继电器脸上    测量到带载电压
      if(PE2)
      {
     	  if(ads_data[2]<mindaizai)mindaizai=ads_data[2];
      	  if(ads_data[2]>maxdaizai)maxdaizai=ads_data[2];
      }
      else
      {
      	  if(ads_data[2]<minkongzai)minkongzai=ads_data[2];
      	  if(ads_data[2]>maxkongzai)maxkongzai=ads_data[2];
      	  ch1_1k_totall+=ads_data[0];
      }
      if(++count_tim3>=300)
      {
     	  HAL_TIM_Base_Stop_IT(&htim3);
     	  count_tim3=0;
     	  Dosomething_tim3();
      }
	*/





//  switch(steps)
//  {
//  	  case 2:
//  	  case 3:
//      {
////          if(ads_data[0]<minch1)minch1=ads_data[0];
////          if(ads_data[0]>maxch1)maxch1=ads_data[0];
//          if(ads_data[1]<minch2)minch2=ads_data[1];
//          if(ads_data[1]>maxch2)maxch2=ads_data[1];
//
//          //如果PE2是高电平    继电器脸上    测量到带载电压
//          if(PE2)
//          {
//         	  if(ads_data[2]<mindaizai)mindaizai=ads_data[2];
//          	  if(ads_data[2]>maxdaizai)maxdaizai=ads_data[2];
//          }
//          else
//          {
//          	  if(ads_data[2]<minkongzai)minkongzai=ads_data[2];
//          	  if(ads_data[2]>maxkongzai)maxkongzai=ads_data[2];
//          	  ch1_1k_totall+=ads_data[0];
//          }
//          if(++count_tim3>=300)
//          {
//         	  HAL_TIM_Base_Stop_IT(&htim3);
//         	  count_tim3=0;
//         	  //Dosomething_tim3();
//          }
//          break;
//      }
//      //检测CH1电压        取平均值
//  	  case 6:
//  	  {
//  		  ch1_150K_totall+=ads_data[0];
//          if(++count_tim3>=300)
//          {
//         	  HAL_TIM_Base_Stop_IT(&htim3);
//         	  count_tim3=0;
//         	  //Dosomething_tim3();
//          }
//          break;
//  	  }
//  	  case 9:
//  	  {
//  		  ch1_100_totall+=ads_data[0];
//          if(++count_tim3>=300)
//          {
//         	  HAL_TIM_Base_Stop_IT(&htim3);
//         	  count_tim3=0;
//         	  //Dosomething_tim3();
//          }
//          break;
//  	  }
//
//
//  }
//if(flag)
//{
//  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
//  HAL_SPI_TransmitReceive(&hspi3, txbuf, rxbuf, 4, 10);
//  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
//
//  if(maxch1>*(uint16_t *)(&rxbuf[2]))maxch1=*(uint16_t *)(&rxbuf[2]);
//  if(minch1<*(uint16_t *)(&rxbuf[2]))minch1=*(uint16_t *)(&rxbuf[2]);
//}
//
//else
//{
//  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
//  HAL_SPI_TransmitReceive(&hspi3, txbuf, rxbuf, 4, 10);
//  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
//
//  if(maxch2>*(uint16_t *)(&rxbuf[2]))maxch2=*(uint16_t *)(&rxbuf[2]);
//  if(minch2<*(uint16_t *)(&rxbuf[2]))minch2=*(uint16_t *)(&rxbuf[2]);
//}
//flag=!flag;
  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */

  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */
 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_2);
  PE2=!PE2;
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, PE2);
  HAL_Delay(50);
  count_tim3=0;
  HAL_TIM_Base_Start_IT(&htim3);

//  switch(steps)
//  {
//  //空载   开启TIM3    测CH2  CH3    并发送测试数据
//      case 1:
//      {
//    	  steps=2;
//    	  PE2=0;
//    	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, PE2);
//    	  HAL_TIM_Base_Start_IT(&htim3);
//    	  break;
//      }
//      //带载   开启TIM3    测CH2  CH3    并发送测试数据
//      case 2:
//      {
//    	  steps=3;
//    	  PE2=1;
//    	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, PE2);
//    	  HAL_TIM_Base_Start_IT(&htim3);
//    	  break;
//      }
//      //将频率改成150k   然后等待两个周期   空载
//      case 3:
//      {
//    	  steps=4;
//    	  PE2=0;
//    	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, PE2);
//    	  Write_frequence(0, 150000);
//    	  break;
//      }
//
//      case 4:
//      {
//    	  steps=5;
//    	  break;
//      }
//      //开始测150K 的检波CH1
//      case 5:
//      {
//    	  steps=6;
//    	  HAL_TIM_Base_Start_IT(&htim3);
//    	  break;
//      }
//      //将频率改成100hz    然后等待两个周期
//      case 6:
//      {
//    	  steps=7;
//    	  Write_frequence(0, 100);
//    	  break;
//      }
//
//      case 7:
//      {
//    	  steps=8;
//    	  break;
//      }
//      //测100的检波
//      case 8:
//      {
//    	  steps=9;
//    	  HAL_TIM_Base_Start_IT(&htim3);
//    	  break;
//      }
//      //将频率改成1K
//      case 9:
//      {
//    	  steps=10;
//    	  Write_frequence(0, 1000);
//    	  break;
//      }
//      case 10:
//      {
//    	  steps=1;
//    	  //HAL_TIM_Base_Start_IT(&htim3);
//    	  Dosomething_tim3();
//    	  break;
//      }
//
//  }


  /* USER CODE END TIM4_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
