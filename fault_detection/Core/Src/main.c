/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
SPI_HandleTypeDef hspi3;

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
ADS8688 ads;
uint16_t ads_data[8];
uint32_t freq;

//�?????????大�?�和�?????????小�??
uint16_t maxch1=0,maxch2=0,minch1=65535,minch2=65535;
uint16_t maxkongzai,minkongzai,maxdaizai,mindaizai;
float maxch1_f=-10,maxch2_f=-10,minch1_f=10,minch2_f=10;
float maxkongzai_f=0,minkongzai_f=10;
float maxdaizai_f=0,mindaizai_f=10;
uint32_t count_tim3=0;
uint32_t ch1_150K_totall=0,ch1_100_totall=0;
uint32_t ch1_1k_totall=0;
float ch1_150k,ch1_100,ch1_1k;
//PE2 H or L
uint8_t PE2=0;


//TIM4 steps
/*
1     DDS1K      改为带载状�??      �?启TIM4    测CH2 3      并发送测试数�?
2     DDS1K      改为空载状�??      �?启TIM4    测CH2 3      并发送数�?    发�?�后DDS改成150K
3     DDS150K    空载     等待
4     DDS150K	 空载      等待
5     DDS150k    空载     �?启TIM4  测CH1数据         发�?�后DDS改为100
6     DDS100     空载     等待
7     DDS100     空载     等待
8     DDS100     空载    �?启TIM4  测CH1数据        发�?�数据后改为1k
*/
uint8_t steps=1;



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI3_Init(void);
static void MX_TIM3_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM4_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI3_Init();
  MX_TIM3_Init();
  MX_USART2_UART_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */

  ADS8688_Init(&ads, &hspi3, SPI3_CS_GPIO_Port, SPI3_CS_Pin);
  Init_AD9959();

//  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
//  HAL_SPI_TransmitReceive(&hspi3, temp, ads_data, 2, 10);
//  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);


  //TIM3->PSC=9;
  TIM3->ARR=2697;
  //HAL_TIM_Base_Start_IT(&htim3);
  TIM4->ARR=19999;
  Write_frequence(0, 150000);
  //HAL_TIM_Base_Start_IT(&htim4);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET);
  HAL_TIM_Base_Start_IT(&htim3);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI3_Init(void)
{

  /* USER CODE BEGIN SPI3_Init 0 */

  /* USER CODE END SPI3_Init 0 */

  /* USER CODE BEGIN SPI3_Init 1 */

  /* USER CODE END SPI3_Init 1 */
  /* SPI3 parameter configuration*/
  hspi3.Instance = SPI3;
  hspi3.Init.Mode = SPI_MODE_MASTER;
  hspi3.Init.Direction = SPI_DIRECTION_2LINES;
  hspi3.Init.DataSize = SPI_DATASIZE_16BIT;
  hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi3.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi3.Init.NSS = SPI_NSS_SOFT;
  hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi3.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI3_Init 2 */

  /* USER CODE END SPI3_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 2099;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 419;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 3999;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 921600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SPI3_CS_GPIO_Port, SPI3_CS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_SET);

  /*Configure GPIO pin : PE2 */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : KEY1_Pin */
  GPIO_InitStruct.Pin = KEY1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEY1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PC0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI3_CS_Pin */
  GPIO_InitStruct.Pin = SPI3_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(SPI3_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PD2 PD3 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PD4 PD5 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

}

/* USER CODE BEGIN 4 */
char max1print[9],max2print[9],min1print[9],min2print[9],Vpp1[9],Vdc1[9],Vpp2[9],Vdc2[9];
char Vppkongzai[9],Vdckongzai[9],maxkongzaiprint[9],minkongzaiprint[9];
char Vppdaizai[9],Vdcdaizai[9],maxdaizaiprint[9],mindaizaiprint[9];
int count=0;
float Vdc11,Vdc22;
float Vpp11,Vpp22;
float kongzaiVdc,daizaiVdc;
float Ri,Ro;
char Riprint[9],Roprint[9];
uint8_t begin[7]={0xEE,0xB1,0x10,0x00,0x00,0x00,0x01},end[4]={0xFF,0xFC,0xFF,0xFF};


void Dosomething_tim3()
{
	maxch1_f=((int)maxch1-32768)/65536.0*5.12;
	minch1_f=((int)minch1-32768)/65536.0*5.12;

//	ch1_100=((ch1_100_totall*1.0/300)-32768)/65536/5.12;
//	ch1_1k=((ch1_1k_totall*1.0/300)-32768)/65536/5.12;
//	ch1_150k=((ch1_150K_totall*1.0/300)-32768)/65536/5.12;

	maxch2_f=((int)maxch2-32768)/65536.0*5.12;
	minch2_f=((int)minch2-32768)/65536.0*5.12;

	maxdaizai_f=((int)maxdaizai)/65536.0*10.24;
	mindaizai_f=((int)mindaizai)/65536.0*10.24;

	maxkongzai_f=((int)maxkongzai)/65536.0*10.24;
	minkongzai_f=((int)minkongzai)/65536.0*10.24;

	Vpp11=(maxch1_f-minch1_f);
	Vpp22=(maxch2_f-minch2_f);

	Vdc11=(maxch1_f+minch1_f)/2;
	Vdc22=(maxch2_f+minch2_f)/2;

	kongzaiVdc=(maxkongzai_f+minkongzai_f)/2;
	daizaiVdc = (maxdaizai_f+mindaizai_f)/2;


	Ri=Vpp22/(Vpp11-Vpp22)*6.8;
    Ro=(kongzaiVdc-daizaiVdc)/daizaiVdc*1.6;

//	sprintf(max1print,"ch1max:%d\r\r\n",maxch1);
//	sprintf(min1print,"ch1min:%d\r\r\n",minch1);
//	sprintf(Vpp1,"Vpp:%d\r\r\n",maxch1-minch1);
//	sprintf(Vdc1,"Vdc:%d\r\r\n",(maxch1+minch1)/2);

	sprintf(max1print,"%.6f",maxch1_f);
	sprintf(min1print,"%.6f",minch1_f);
	sprintf(Vpp1,"%.6f",Vpp11);
	sprintf(Vdc1,"%.6f",Vdc11);

	sprintf(max2print,"%.6f",maxch2_f);
	sprintf(min2print,"%.6f",minch2_f);
	sprintf(Vpp2,"%.6f",maxch2_f-minch2_f);
	sprintf(Vdc2,"%.6f",Vdc22);

	sprintf(maxkongzaiprint,"%.6f",maxkongzai_f);
	sprintf(minkongzaiprint,"%.6f",minkongzai_f);
	sprintf(Vppkongzai,"%.6f",maxkongzai_f-minkongzai_f);
	sprintf(Vdckongzai,"%.6f",(maxkongzai_f+minkongzai_f)/2);

	sprintf(maxdaizaiprint,"%.6f",maxdaizai_f);
	sprintf(mindaizaiprint,"%.6f",mindaizai_f);
	sprintf(Vppdaizai,"%.6f",maxdaizai_f-mindaizai_f);
	sprintf(Vdcdaizai,"%.6f",(maxdaizai_f+mindaizai_f)/2);

	sprintf(Riprint,"%.6f",Ri);
	sprintf(Roprint,"%.6f",Ro);

	begin[6]=0x01;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, max1print, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x02;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, min1print, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x03;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, Vpp1, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x04;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, Vdc1, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x05;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, max2print, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x06;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, min2print, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x07;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, Vpp2, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x08;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, Vdc2, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x09;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, maxkongzaiprint, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x0a;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, minkongzaiprint, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x0b;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, Vppkongzai, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x0c;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, Vdckongzai, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x0d;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, maxdaizaiprint, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x0e;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, mindaizaiprint, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x0f;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, Vppdaizai, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x10;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, Vdcdaizai, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x25;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, Vdcdaizai, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x25;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, Riprint, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	begin[6]=0x26;
	HAL_UART_Transmit(&huart2, begin, 7, 5);
	HAL_UART_Transmit(&huart2, Roprint, 9, 5);
	HAL_UART_Transmit(&huart2, end, 4, 5);

	//HAL_UART_Transmit(&huart2, "\r\r\n", 6, 5);



	maxch1=0;
	minch1=65535;
	maxch2=0;
	minch2=65535;
//	maxkongzai=0;
//	minkongzai=65535;

	if(PE2)
	{
		maxkongzai=0;
		minkongzai=65535;
	}
	else
	{
		maxdaizai=0;
		mindaizai=65535;
	}

//	maxdaizai=0;
//	mindaizai=65535;



	//HAL_Delay(300);


	HAL_TIM_Base_Start_IT(&htim3);

}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
