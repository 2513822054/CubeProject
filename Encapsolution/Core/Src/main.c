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
uint8_t formShow[500]={166.26834261762758,198.7106771713121,220.38795248208143,227.99999999999997,220.387954532874,198.71068096068268,166.26834756867882,128.0000053589793,89.73166233342378,57.28932661805868,35.6120495687114,28.000000000000327,35.61204341633369,57.289315249946995,89.73164748027007,127.99998928204137,166.26833271552465,198.7106695925704,220.38794838049552,227.9999999999991,220.38795863445836,198.71068853942316,166.26835747078107,128.00001607693804,89.73167223552686,57.28933419680084,35.612053670297826,28.000000000001748,35.61203931474989,57.28930767120694,89.73163757816792,127.99997856408274,166.26832281342152,198.71066201382774,220.38794427890852,227.9999999999971,220.38796273604166,198.71069611816287,166.26836737288284,128.00002679489668,89.73168213763022,57.28934177554392,35.61205777188533,28.000000000004334,35.61203521316715,57.28930009246751,89.73162767606638,127.99996784612392,166.26831291131776,198.71065443508448,220.38794017732047,227.99999999999392,220.38796683762388,198.71070369690165,166.2683772749843,128.00003751285513,89.73169203973433,57.289349354287566,35.61206187347399,28.000000000008086,35.612031111585395,57.28929251372891,89.73161777396544,127.99995712816546,166.26830300921344,198.71064685634045,220.38793607573143,227.99999999998963,220.38797093920493,198.71071127563985,166.26838717708503,128.00004823081358,89.73170194183857,57.28935693303228,35.6120659750637,28.00000000001296,35.61202701000484,57.28928493499136,89.73160787186495,127.99994641020665,166.26829310710866,198.7106392775956,220.3879319741412,227.99999999998417,220.38797504078508,198.71071885437698,166.26839707918563,128.0000589487724,89.73171184394324,57.289364511777535,35.61207007665446,28.000000000018986,35.61202290842536,57.28927735625436,89.73159796976456,127.99993569224785,166.26828320500377,198.71063169884965,220.38792787254988,227.99999999997755,220.38797914236392,198.71072643311356,166.2684069812858,128.0000696667312,89.73172174604869,57.28937209052387,35.61207417824603,28.000000000026162,35.61201880684679,57.289269777518186,89.73158806766462,127.99992497428974,166.26827330289808,198.71062412010292,220.3879237709575,227.99999999996982,220.38798324394224,198.71073401184935,166.26841688338487,128.0000803846893,89.73173164815458,57.289379669271014,35.612078279838926,28.00000000003449,35.61201470526956,57.289262198783334,89.73157816556576,127.99991425633092,166.268263400792,198.71061654135536,220.38791966936435,227.9999999999609,220.38798734551892,198.7107415905838,166.26842678548417,128.00009110264884,89.73174155026089,57.28938724801846,35.6120823814326,28.000000000043983,35.61201060369284,57.289254620048766,89.73156826346604,127.99990353837282,166.2682534986861,198.7106089626075,220.38791556776988,227.99999999995083,220.38799144709486,198.71074916931846,166.26843668758235,128.00010182060694,89.73175145236699,57.289394826767236,35.612086483027895,28.000000000054598,35.61200650211774,57.289247041315534,89.73155836136807,127.99989282041331,166.26824359657914,198.71060138385783,220.38791146617433,227.99999999993966,220.38799554866944,198.71075674805127,166.2684465896814,128.00011253856647,89.73176135447419,57.289402405516825,35.61209058462343,28.00000000006638,35.6120024005434,57.2892394625821,89.73154845926922,127.9998821024552,166.26823369447172,198.71059380510883,220.38790736457798,227.9999999999273,220.3879996502435,198.71076432678433,166.26845649177872,128.00012325652455,89.73177125658117,57.2894099842667,35.61209468622084,28.000000000079297,35.611998298970406,57.28923188385049,89.73153855717214,127.99987138449568,166.26822379236452,198.71058622635752,220.38790326298061,227.99999999991383,220.38800375181594,198.71077190551551,166.2684663938769,128.00013397448265,89.73178115868991,57.28941756301741,35.612098787818766,28.000000000093365,35.61199419739795,57.28922430511868,89.7315286550755,127.99986066653759,166.26821389025687,198.71057864760644,220.3878991613816,227.99999999989916,220.38800785338788,198.7107794842459,166.26847629597333,128.00014469244076,89.73179106079778,57.289425141769925,35.61210288941831,28.000000000108585,35.61199009582708,57.28921672638869,89.73151875297927,127.99984994857948,166.2682039881475,198.7105710688535,220.38789505978207,227.99999999988336,220.38801195495824,198.7107870629765,166.26848619806933,128.00015541040028,89.73180096290739,57.28943272052325,35.61210699101889,28.00000000012497,35.61198599425728,57.289209147659506,89.7315088508835,127.99983923062138,166.26819408603896,198.71056349010078,220.38789095818095,227.99999999986642,220.3880160565275,198.71079464170526,166.2684961001662,128.0001661283598,89.73181086501745,57.2894402992754,35.61211109261947,28.000000000142478,35.61198189268799,57.28920156893115,89.73149894878685,127.99982851266185,166.26818418392867,198.71055591134623,220.38788685657875,227.99999999984834,220.38802015809625,198.71080222043324,166.26850600225998,128.0001768463165,89.73182076712531,57.289447878030344,35.612115194222184,28.00000000016115,35.61197779112031,57.28919399020259,89.73148904669064,127.99981779470234,166.26817428181795,198.71054833259188,220.3878827549766,227.99999999982907,220.38802425966287,198.71080979916036,166.26851590435598,128.00018756427602,89.73183066923625,57.289455456786115,35.61211929582542,28.00000000018096,35.61197368955314,57.289186411474844,89.73147914459489,127.99980707674565,166.26816437970945,198.7105407538367,220.3878786533723,227.9999999998087,220.3880283612295,198.7108173778877,166.26852580645152,128.00019828223552,89.73184057134631,57.2894630355417,35.61212339743025,28.000000000201922,35.61196958798813,57.289178832749926,89.73146924250217,127.99979635878613,166.26815447759785,198.7105331750807,220.38787455176748,227.99999999978718,220.38803246279508,198.71082495661426,166.26853570854664,128.00020900019362,89.73185047345811,57.28947061429808,35.61212749903507,28.00000000022405,35.61196548642309,57.2891712540238,89.73145934040728,127.99978564082662,166.26814457548713,198.7105255963229,220.38787045016102,227.99999999976447,220.3880365643596,198.71083253533897,166.26854561063737,128.0002197181503,89.73186037556775,57.28947819305529,35.61213160064203,28.000000000247297,35.611961384859114,57.2891636752985,89.73144943831284,127.99977492286709,166.26813467337334,198.7105180175653,220.3878663485541,227.99999999974062,220.38804066592138,198.71084011406185,166.2685555127316,128.00023043610983,89.73187027768043,57.2894857718143,35.61213570225007,28.00000000027171,35.61195728329619,57.289156096574004,89.73143953621883,127.9997642049104,166.26812477126305,198.7105104388059,220.38786224694553,227.99999999971567,220.3880447674838,198.71084769278593,166.2685654148254,128.00024115406936,89.73188017979356,57.28949335057413,35.61213980385915,28.000000000297277,35.611953181735416,57.289148517852325,89.73142963412789,127.99975348695088,166.2681148691497,198.71050286004765,220.387858145337,227.99999999968952,220.38804886904512,198.71085527150922,166.26857531691874,128.00025187202888,89.73189008190714,57.289500929332775,35.6121439054682,28.00000000032398,35.61194908017461,57.28914093912945,89.73141973203477,127.99974276899137,166.26810496703854,198.71049528128663,220.38785404372632,227.99999999966224,220.38805297060537,198.71086285022966,166.26858521900903,128.00026258998557,89.73189998401853,57.289508508094215,35.61214800707941,28.000000000351847,35.611944978614886,57.28913336040739,89.7314098299447,127.99973205103468,166.2680950649243,198.71048770252474,220.38784994211568,227.99999999963381,220.38805707216352,198.71087042895132,166.2685951211015,128.00027330794506,89.73190988613297,57.289516086856494,35.61215210869169,28.000000000380837,35.61194087705621,57.289125781688156,89.73139992785244,127.99972133307516,166.26808516281227,198.71048012376409,220.38784584050285,227.9999999996042,220.38806117372164,198.71087800767216,166.26860502319352,128.0002840259046,89.73191978824786,57.28952366561957,35.61215621030502,28.000000000411006,35.6119367754997,57.28911820296773,89.73139002576063,127.99971061511847,166.26807526069715,198.71047254500058,220.387841738889,227.9999999995735,220.38806527527873,198.71088558639218,166.2686149252851,128.00029474386412,89.73192969036057,57.28953124438145,35.612160311918316,28.0000000004423,35.61193267394313,57.289110624250114,89.73138012367188,127.99969989715896,166.2680653585816,198.71046496623632,220.3878376372741,227.99999999954161,220.38806937683472,198.71089316510938,166.26862482737363,128.0003054618208,89.73193959247634,57.28953882314616,35.612164413533776,28.000000000474756,35.611928572388734,57.28910304553129,89.73137022158096,127.99968917919944,166.26805545646562,198.7104573874712,220.3878335356581,227.9999999995086,220.38807347838969,198.71090074382982,166.26863472946698,128.00031617978033,89.73194949458991,57.28954640190966,35.61216851514919,28.000000000508365,35.61192447083431,57.28909546681531,89.73136031949309,127.99967846124275,166.2680455543518,198.71044980870727,220.38782943404215,227.99999999947443,220.3880775799425,198.71090832254538,166.26864463155462,128.00032689773985,89.73195939670919,57.28955398067599,35.61217261676677,28.00000000054311,35.61192036928094,57.289087888096105,89.7313504174004,127.9996677432804,166.26803565223233,198.71044222993854,220.3878253324251,227.9999999994391};
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi3;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart6;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART6_UART_Init(void);
static void MX_TIM1_Init(void);
static void MX_SPI3_Init(void);
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
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  MX_USART6_UART_Init();
  MX_TIM1_Init();
  MX_SPI3_Init();
  /* USER CODE BEGIN 2 */

  HAL_UART_Receive_IT(&huart1, (uint8_t *)&R_onedata, 1);

  tft_form(0,7,formShow,500,0);

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
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 2624;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 8400000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 921600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 921600;
  huart6.Init.WordLength = UART_WORDLENGTH_8B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_NONE;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE END USART6_Init 2 */

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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD2 PD3 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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