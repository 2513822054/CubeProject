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
#include "ad9959.h"
#include "ADS8688.h"
#include "tft.h"
#include <stdio.h>
#include "arm_math.h"
#include "outputdata.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

extern SPI_HandleTypeDef hspi3;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart6;

extern float Input[1024];
extern float Output[1024], Real_Output[1024]; //�??终幅值结果数�??
extern arm_rfft_fast_instance_f32 S;//结构�??

//设置状�?�机模式     0 测试模式  1幅频特�?�模�?????   2故障�?????测模�?????
extern uint8_t stateMode;


//PE0电平状�??           �?????1则输出继电器相连，输出带�?????        0为空�?????
extern uint8_t PE0;

extern uint16_t count3,count4,count5;

//采样�?????  和buf
extern uint16_t ads_data[8];
extern uint8_t txbuf[4];
extern uint8_t rxbuf[4];

extern ADS8688 ads;


//幅频特�?�采样数�???
extern uint16_t AF[400];

//各个通道的最大�?�和�?????小�??
extern uint16_t ch1max,ch2max,ch3max,ch4max,ch1min,ch2min,ch3min,ch4min;
//�?????大�?�最小�?�和各种值的浮点�?????
extern float ch1max_f,ch2max_f,ch3max_f,ch4max_f,ch1min_f,ch2min_f,ch3min_f,ch4min_f;
//峰峰�????? 平均�?????
extern float Vpp1,Vpp2,Vdc1,Vdc2;
extern float Vpp3Noload,Vpp3Load,Vdc3Noload,Vdc3Load;
//输入输出电阻
extern float Ri[5],Ro,Au;


//幅频特�?�采样数�???
extern uint16_t AF[400];
extern uint16_t AF_max,AF_place;
extern uint8_t AF_print[400];


//测c1double
extern float ch1Mode2[850];
extern float ch3Mode2[850];
extern uint32_t count2;
extern float c1DoubleMax;
extern float c2DoubleMin;

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SPI3_CS_Pin GPIO_PIN_15
#define SPI3_CS_GPIO_Port GPIOA
#define Relay_In_Pin GPIO_PIN_0
#define Relay_In_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
