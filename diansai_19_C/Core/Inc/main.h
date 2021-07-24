/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ADS8688.h"
#include "tft.h"
#include "arm_math.h"
#include "outputdata.h"
#include "math.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern SPI_HandleTypeDef hspi3;

extern TIM_HandleTypeDef htim1;
extern UART_HandleTypeDef huart6;
extern UART_HandleTypeDef huart1;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern arm_rfft_fast_instance_f32 S;//结构体
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SPI3_CS_Pin GPIO_PIN_15
#define SPI3_CS_GPIO_Port GPIOA
#define AD9959_PS0_Pin GPIO_PIN_5
#define AD9959_PS0_GPIO_Port GPIOD
#define AD9959_PWR_Pin GPIO_PIN_6
#define AD9959_PWR_GPIO_Port GPIOD
#define AD9959_PS0D7_Pin GPIO_PIN_7
#define AD9959_PS0D7_GPIO_Port GPIOD
#define AD9959_RESET_Pin GPIO_PIN_9
#define AD9959_RESET_GPIO_Port GPIOG
#define AD9959_PS2_Pin GPIO_PIN_10
#define AD9959_PS2_GPIO_Port GPIOG
#define AD9959_UPDATE_Pin GPIO_PIN_11
#define AD9959_UPDATE_GPIO_Port GPIOG
#define AD9959_PS3_Pin GPIO_PIN_12
#define AD9959_PS3_GPIO_Port GPIOG
#define AD9959_CS_Pin GPIO_PIN_13
#define AD9959_CS_GPIO_Port GPIOG
#define AD9959_SDIO0_Pin GPIO_PIN_14
#define AD9959_SDIO0_GPIO_Port GPIOG
#define AD9959_SCLK_Pin GPIO_PIN_15
#define AD9959_SCLK_GPIO_Port GPIOG
#define AD9959_SDIO1_Pin GPIO_PIN_3
#define AD9959_SDIO1_GPIO_Port GPIOB
#define AD9959_SDIO3_Pin GPIO_PIN_4
#define AD9959_SDIO3_GPIO_Port GPIOB
#define AD9959_SDIO2_Pin GPIO_PIN_5
#define AD9959_SDIO2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
