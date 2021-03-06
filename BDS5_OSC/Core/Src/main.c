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
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ADS8688.h"
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

// macro and pattern to print binary numbers
#define BYTE_TO_BIN_PAT "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BIN(byte)		\
	(byte & 0x80 ? '1' : '0'),	\
	(byte & 0x40 ? '1' : '0'),	\
	(byte & 0x20 ? '1' : '0'),	\
	(byte & 0x10 ? '1' : '0'),	\
	(byte & 0x08 ? '1' : '0'),	\
	(byte & 0x04 ? '1' : '0'),	\
	(byte & 0x02 ? '1' : '0'),	\
	(byte & 0x01 ? '1' : '0')


/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

uint8_t ch1_freq_tft[20]={0xEE,0xB1,0x10,0x00,0x00,0x00,0x0A,0x30,0x30,0x30,0x30,0x2E,0x30,0x30,0x30,0x30,0xFF,0xFC,0xFF,0xFF};
uint8_t ch1_vpp_tft[20]={0xEE,0xB1,0x10,0x00,0x00,0x00,0x15,0x30,0x30,0x30,0x30,0x2E,0x30,0x30,0x30,0x30,0xFF,0xFC,0xFF,0xFF};
uint8_t ch1_avg_tft[20]={0xEE,0xB1,0x10,0x00,0x00,0x00,0x16,0x30,0x30,0x30,0x30,0x2E,0x30,0x30,0x30,0x30,0xFF,0xFC,0xFF,0xFF};

uint8_t ch2_freq_tft[20]={0xEE,0xB1,0x10,0x00,0x00,0x00,0x17,0x30,0x30,0x30,0x30,0x2E,0x30,0x30,0x30,0x30,0xFF,0xFC,0xFF,0xFF};
uint8_t ch2_vpp_tft[20]={0xEE,0xB1,0x10,0x00,0x00,0x00,0x18,0x30,0x30,0x30,0x30,0x2E,0x30,0x30,0x30,0x30,0xFF,0xFC,0xFF,0xFF};
uint8_t ch2_avg_tft[20]={0xEE,0xB1,0x10,0x00,0x00,0x00,0x19,0x30,0x30,0x30,0x30,0x2E,0x30,0x30,0x30,0x30,0xFF,0xFC,0xFF,0xFF};

uint16_t ch1_maxdata,ch1_mindata;
float ch1_maxvolt,ch1_minvolt;
uint16_t ch2_maxdata,ch2_mindata;
float ch2_maxvolt,ch2_minvolt;
float ch1Vpp,ch2Vpp;
float freq1,freq2;
float ch1_avg,ch2_avg;
// ADS variables
//??????????????????????????????????????
uint8_t scream_head=0xEE,screen_end[4]={0xFF,0xFC,0xFF,0xFF};
//??????????????   0?????????????????????????????    1?????????????????????????????
uint8_t chufazhuangtai=0;

//????????????
uint16_t trigger_volt=32768;

//????????????          1,1????????????,2,2????????????
uint8_t trigger_mode;
//??????????????????    1??????    0??????
uint8_t ch1_show=1,ch2_show=1;

int count_caiyang=0,count_pinlv=0;      //??????????????????
//????????????    0??????????????????????????10mv        1??????????????????????????100mv          2??????????????????????????1v
uint8_t chuizhi_scale=2;

uint16_t count1ms=0;

//????????????     0????????????????????????????????????????1ms??????     1,10ms??????       2,100ms??????
uint8_t shuiping_scale=2;
//????????????????????????????????????????????????????????????????
int fenpin_count[3]={1,10,100};
//??????????????????????????????????????????????????????????????????????????????????
int max_count[3]={502,5020,50200};
//????????????????????????????????????????????????????
uint16_t ch1_values[502],ch2_values[502];
//???????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
//uint16_t ch1_max,ch2_max,ch1_min,ch2_min;
//????????????
uint16_t chufa_volts=0;
//????????????   0????????????????????????????????????????????????????    1????????????????????????????????????????????????????
uint8_t chufa_mode=0;
//????????????  0,??????????????????????????????????????????????   1????????????
uint8_t chufa_ch=0;
//??????????????????????????  ???????????????????????????????
int total_ch1,total_ch2;
int i;

//??????
//uint8_t ch1_show_head[10]={
//		0xEE,0xB1,0x32,0x00,0x00,0x00,0x02,0x00,0x01,0x90
//};
//uint8_t ch2_show_head[10]={
//		0xEE,0xB1,0x32,0x00,0x00,0x00,0x02,0x01,0x01,0x90
//};
uint8_t ch_showall[948]=
{
0xEE,0xB1,0x32,0x00,0x00,0x00,0x02,0x00,0x01,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFC,0xFF,0xFF,
0xEE,0xB1,0x32,0x00,0x00,0x00,0x02,0x01,0x01,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFC,0xFF,0xFF
};

//??????????????????????????????????
uint8_t R_alldata[256];   //??????????????????
uint8_t R_onedata;    //????????????
uint16_t R_place=0;         //????????????????????????????????????????



//?????????????????????????????????????????????????????????????????
uint32_t ch1_period=0,ch1_duty,ch2_period,ch2_duty;


ADS8688 ads;
//????????????????????????????????????????????????????
uint16_t ads_data[2];

uint8_t rxbuf[2] = {0};
uint8_t txbuf[2] = {0x00, 0x00};

uint8_t CH1_ON=0;
uint8_t CH2_ON=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

void print(char *msg, ...);
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
//	memcpy(ch_showall+828*sizeof(uint8_t),ch1_freq_tft,sizeof(ch1_freq_tft));
//	memcpy(ch_showall+848*sizeof(uint8_t),ch1_vpp_tft,sizeof(ch1_vpp_tft));
//	memcpy(ch_showall+868*sizeof(uint8_t),ch1_avg_tft,sizeof(ch1_avg_tft));
//	memcpy(ch_showall+888*sizeof(uint8_t),ch2_freq_tft,sizeof(ch2_freq_tft));
//	memcpy(ch_showall+908*sizeof(uint8_t),ch2_vpp_tft,sizeof(ch2_vpp_tft));
//	memcpy(ch_showall+928*sizeof(uint8_t),ch2_avg_tft,sizeof(ch2_avg_tft));
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  HAL_Delay(200);
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM2_Init();
  MX_SPI3_Init();
  MX_TIM5_Init();
  MX_TIM3_Init();
  MX_USART2_UART_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start(&htim2);
  HAL_TIM_IC_Start_DMA(&htim2,TIM_CHANNEL_1,&ch1_period,1);
  htim2.State = HAL_TIM_STATE_READY;
  HAL_TIM_Base_Start(&htim5);
  HAL_TIM_IC_Start_DMA(&htim5,TIM_CHANNEL_1,&ch2_period,1);
  htim5.State = HAL_TIM_STATE_READY;
  //HAL_TIM_IC_Start_DMA(&htim2,TIM_CHANNEL_2,&ch1_duty,1);

  ADS8688_Init(&ads, &hspi3, SPI3_CS_GPIO_Port, SPI3_CS_Pin);
  HAL_Delay(500);
  //ADS_Read_All_Raw(&ads, ads_data);
  HAL_UART_Receive_IT(&huart1, (uint8_t *)&R_onedata, 1);
  //HAL_UART_Transmit_IT(&huart2, ch_showall, 828);
  TIM3->PSC=99;
  HAL_TIM_Base_Start_IT(&htim3);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//		  for(int i=0; i<2; i++) {
//			  if(i==1)
//			  {
//			  printf("CHN_%d: %u %u    "BYTE_TO_BIN_PAT" "BYTE_TO_BIN_PAT"  %f\n", i, (uint16_t)(ads_data[0]), (uint16_t)(ads_data[1]) ,  BYTE_TO_BIN(ads_data[1]), BYTE_TO_BIN(ads_data[0]), volt1[0]);
//				//printf("%d",12);
//			  }
//			  else
//			  {
//			  printf("CHN_%d: %u %u    "BYTE_TO_BIN_PAT" "BYTE_TO_BIN_PAT"  %f\n", i, (uint16_t)(ads_data[0]), (uint16_t)(ads_data[1]) ,  BYTE_TO_BIN(ads_data[1]), BYTE_TO_BIN(ads_data[0]), volt2[0]);
//			  }
//		  }


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
  /** Enables the Clock Security System
  */
  HAL_RCC_EnableCSS();
}

/* USER CODE BEGIN 4 */
//??????????????????????????????????????????????????????????????????????
void FinishCount(){
//	if(++count1ms<5 && shuiping_scale==0)
//	{
//		return;
//	}
//	count1ms=0;
	int temp1,temp2;

	if(chuizhi_scale==1)
	{
		for(i=0;i<=402;i++)
			{
			temp1=((int)ch1_values[i]-32768)*10+32768;
			temp2=((int)ch2_values[i]-32768)*10+32768;
			if(temp1>65535)ch1_values[i]=65535;
			else if(temp1<0)ch1_values[i]=0;
			else ch1_values[i]=(uint16_t)temp1;
			if(temp2>65535)ch2_values[i]=65535;
			else if(temp2<0)ch2_values[i]=0;
			else ch2_values[i]=(uint16_t)temp2;
//			ch1_values[i]=(uint16_t)((int)ch1_values[i]-32768)*10+32768;
//			ch2_values[i]=(uint16_t)((int)ch2_values[i]-32768)*10+32768;

			}
	}
	if(chuizhi_scale==0)
	{
		for(i=0;i<=402;i++)
			{
			temp1=((int)ch1_values[i]-32768)*100+32768;
			temp2=((int)ch2_values[i]-32768)*100+32768;

			if(temp1>65535)ch1_values[i]=65535;
			else if(temp1<0)ch1_values[i]=0;
			else ch1_values[i]=(uint16_t)temp1;

			if(temp2>65535)ch2_values[i]=65535;
			else if(temp2<0)ch2_values[i]=0;
			else ch2_values[i]=(uint16_t)temp2;
			}
	}
	for(i=0;i<=402;i++)
	{
			  ch1_values[i]=(uint16_t)(ch1_values[i]<<8|ch1_values[i]>>8);
			  ch2_values[i]=(uint16_t)(ch2_values[i]<<8|ch2_values[i]>>8);
	}

	//????????????????????????????????????????????????
	ch1_maxvolt=ch1_maxdata*1.0/65535*10.24-5.12;
	ch1_minvolt=ch1_mindata*1.0/65535*10.24-5.12;
	ch2_maxvolt=ch2_maxdata*1.0/65535*10.24-5.12;
	ch2_minvolt=ch2_mindata*1.0/65535*10.24-5.12;
	ch1Vpp=ch1_maxvolt-ch1_minvolt;
	ch2Vpp=ch2_maxvolt-ch2_minvolt;
	ch1_avg=(ch1_maxvolt+ch1_minvolt)/2;
	ch2_avg=(ch2_maxvolt+ch2_minvolt)/2;

	memcpy(ch_showall+828*sizeof(uint8_t),ch1_freq_tft,sizeof(ch1_freq_tft));
	memcpy(ch_showall+848*sizeof(uint8_t),ch1_vpp_tft,sizeof(ch1_vpp_tft));
	memcpy(ch_showall+868*sizeof(uint8_t),ch1_avg_tft,sizeof(ch1_avg_tft));
	memcpy(ch_showall+888*sizeof(uint8_t),ch2_freq_tft,sizeof(ch2_freq_tft));
	memcpy(ch_showall+908*sizeof(uint8_t),ch2_vpp_tft,sizeof(ch2_vpp_tft));
	memcpy(ch_showall+928*sizeof(uint8_t),ch2_avg_tft,sizeof(ch2_avg_tft));
	//????????????
	if(84000000.0/ch1_period<=1001)freq1=84000000.0/ch1_period;
	//else freq1=1001;
	if(84000000.0/ch2_period<=1001)freq2=84000000.0/ch2_period;
	//else freq2=1001;

	sprintf(&ch1_freq_tft[7],"%.3f",freq1);
	sprintf(&ch2_freq_tft[7],"%.3f",freq2);

	//??????????????????????????????

	sprintf(&ch1_vpp_tft[7],"%.5f",ch1Vpp);
	sprintf(&ch2_vpp_tft[7],"%.5f",ch2Vpp);
	sprintf(&ch1_avg_tft[7],"%.5f",ch1_avg);
	sprintf(&ch2_avg_tft[7],"%.5f",ch2_avg);


	if(ch1_show==1)
	{
		for(i=0;i<=399;i++){
			ch_showall[10+i]=(uint8_t)(ch1_values[1+i]);
		}
	}
	else
	{
		for(i=0;i<=399;i++){
			ch_showall[10+i]=0;
		}
	}
	if(ch2_show==1)
	{
		for(i=0;i<=399;i++){
		ch_showall[424+i]=(uint8_t)(ch2_values[1+i]);
		}
	}
	else
	{
		for(i=0;i<=399;i++){
			ch_showall[424+i]=0;
		}
	}



	if(shuiping_scale==0)
	{
		if(++count_pinlv>=10)
		{
			HAL_UART_Transmit_DMA(&huart2, ch_showall, 948);
			count_pinlv=0;
		}
	}
	else HAL_UART_Transmit_DMA(&huart2, ch_showall, 948);
	//HAL_Delay(10);
	//huart2->State=HAL_USART_STATE_READY;
//	chufazhuangtai=1;
//	ch1_maxdata=0;
//	ch1_mindata=65535;
//	ch2_maxdata=0;
//	ch2_mindata=65535;
//	count_caiyang=0;
//
////
////	  HAL_TIM_Base_Start(&htim2);
////	  HAL_TIM_IC_Start_DMA(&htim2,TIM_CHANNEL_1,&ch1_period,1);
////	  HAL_TIM_Base_Start(&htim5);
////	  HAL_TIM_IC_Start_DMA(&htim5,TIM_CHANNEL_2,&ch2_period,1);
////	  htim2.State = HAL_TIM_STATE_READY;
////	  htim3.State = HAL_TIM_STATE_READY;
//
//
//
	//while(huart2.gState!=HAL_UART_STATE_READY);
	chufazhuangtai = 1;
	HAL_TIM_Base_Start_IT(&htim3);


}

int Dosomething(){
	//????????????????????????????????????????
	if(R_alldata[1]==0xB1&&R_alldata[2]==0x11&&R_alldata[3]==0x00&&R_alldata[4]==0x00&&R_alldata[5]==0x00&&R_alldata[7]==0x10&&R_alldata[8]==0x01)
	{
		//ch1??????????????????????????????????????????????????????????????
		if(R_alldata[6]==0x05)
		{
			//???????????????????????????????????1
			if(R_alldata[9]==0x01)
			{
				ch1_show=1;
				count_caiyang=0;
			}
			//????????????1
			if(R_alldata[9]==0x00)
			{
				ch1_show=0;
				count_caiyang=0;
			}
		}
		//ch2??????????????????????????????????????????????????????????????
		if(R_alldata[6]==0x06)
		{
					//???????????????????????????????????2
			if(R_alldata[9]==0x01)
			{
				ch2_show=1;
				count_caiyang=0;
			}
					//????????????2
			if(R_alldata[9]==0x00)
			{
				ch2_show=0;
				count_caiyang=0;
			}
		}
		//????????????????????????????????????
		if(R_alldata[6]==0x0b)
		{
			//CH1??????
			if(R_alldata[9]==0x00)
			{
				chufa_ch=0;
				count_caiyang=0;
			}
			//ch2??????
			if(R_alldata[9]==0x01)
			{
				chufa_ch=1;
				count_caiyang=0;
			}
		}
		//?????????????????????
		if(R_alldata[6]==0x1A)
		{
			if(R_alldata[9]==0x00)chufa_mode=0;
			if(R_alldata[9]==0x01)chufa_mode=1;
		}

		//?????????????????????
		if(R_alldata[6]==0x1B)
		{
			if(chufa_ch==0)
			{

				if(ch1Vpp>0.9)
				{
					chuizhi_scale=2;
				}
				else if(ch1Vpp>0.09)
				{
					chuizhi_scale=1;
				}
				else
				{
					chuizhi_scale=0;
				}

				if(freq1>298)
				{
					shuiping_scale=0;TIM3->PSC=0;count_caiyang=0;

				}
				else if(freq1>29.5)
				{
					shuiping_scale=1;TIM3->PSC=9;count_caiyang=0;
				}
				else
				{
					shuiping_scale=1;TIM3->PSC=99;count_caiyang=0;
				}
			}
			if(chufa_ch==1)
			{
				if(ch2Vpp>0.9)
				{
					chuizhi_scale=2;
				}
				else if(ch2Vpp>0.09)
				{
					chuizhi_scale=1;
				}
				else
				{
					chuizhi_scale=0;
				}

				if(freq2>298)
				{
					shuiping_scale=0;TIM3->PSC=0;count_caiyang=0;
				}
				else if(freq2>29.5)
				{
					shuiping_scale=1;TIM3->PSC=9;count_caiyang=0;
				}
				else
				{
					shuiping_scale=1;TIM3->PSC=99;count_caiyang=0;
				}
			}
		}


	}
	//??????????????????????????????????????????????
	else if(R_alldata[1]==0xB1&&R_alldata[2]==0x11&&R_alldata[3]==0x00&&R_alldata[4]==0x00&&R_alldata[5]==0x00&&R_alldata[7]==0x1b)
	{
		//????????????????????????????????????????
		if(R_alldata[6]==0x04)
		{
			switch(R_alldata[8])
			{
				case 0:chuizhi_scale=0;break;
				case 1:chuizhi_scale=1;break;
				case 2:chuizhi_scale=2;break;
			}
		}
		//????????????????????????????????????????
		if(R_alldata[6]==0x08)
		{
			switch(R_alldata[8])
			{
				case 0:shuiping_scale=0;TIM3->PSC=0;count_caiyang=0;break;
				case 1:shuiping_scale=1;TIM3->PSC=9;count_caiyang=0;break;
				case 2:shuiping_scale=2;TIM3->PSC=99;count_caiyang=0;break;
			}
		}

	}

	//??????????????????????????????????????????
	else if(R_alldata[1]==0xB1&&R_alldata[2]==0x11&&R_alldata[3]==0x00&&R_alldata[4]==0x00&&R_alldata[5]==0x00&&R_alldata[6]==0x03&&R_alldata[7]==0x13)
	{
		if(chuizhi_scale==2)trigger_volt=(uint16_t)R_alldata[11]*256;
		if(chuizhi_scale==1)trigger_volt=(uint16_t)((float)R_alldata[11]*25.6)+29491;
		//if(chuizhi_scale==1)trigger_volt=((short int)R_alldata[11]*256-32768)/10;
		if(chuizhi_scale==0)trigger_volt=(uint16_t)((float)R_alldata[11]*2.56)+29819;
	}

	//???????????????????????????????????????
	else if(R_alldata[1]==0xB1&&R_alldata[2]==0x11&&R_alldata[3]==0x00&&R_alldata[4]==0x00&&R_alldata[5]==0x00&&R_alldata[6]==0x1A&&R_alldata[7]==0x10&&R_alldata[8]==0x01)
	{
//		if(R_alldata[9]==0x00)chufa_mode=0;
//		if(R_alldata[9]==0x01)chufa_mode=1;
	}



}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	//UNUSED(huart);
	if(huart->Instance == USART1)
	{
		int i;
		//int isend=0;

					R_alldata[R_place]=R_onedata;     //??????????????????
				//??????????????????????????????
				if(R_onedata==0xEE){
					R_place++;                                      //??????????????????????????????????????????????????????????????????????????????????????????
				}
				else if(R_place>=1)R_place++;
				//??????????????????????????????????????????????????????????????????????
				if(R_place>5){
						if(R_alldata[R_place-1]==0xFF&&R_alldata[R_place-2]==0xFF&&R_alldata[R_place-3]==0xFC&&R_alldata[R_place-4]==0xFF){
							Dosomething();                            //????????????????????????
							for(i=0;i<=255;i++)R_alldata[i]=0;            //????????????
							R_place=0;                                                  //??????????????????????????????????
						}
					}

					R_onedata = 0;                                                                             //????????????????????????????????????????????????????????????????
					HAL_UART_Receive_IT(&huart1, (uint8_t *)&R_onedata, 1);
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_7)
	{
			//HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
			chufazhuangtai=1;
			ch1_maxdata=0;
			ch1_mindata=65535;
			ch2_maxdata=0;
			ch2_mindata=65535;
			count_caiyang=0;
			//HAL_TIM_Base_Start_IT(&htim3);
		//
		//	  HAL_TIM_Base_Start(&htim2);
		//	  HAL_TIM_IC_Start_DMA(&htim2,TIM_CHANNEL_1,&ch1_period,1);
		//	  HAL_TIM_Base_Start(&htim5);
		//	  HAL_TIM_IC_Start_DMA(&htim5,TIM_CHANNEL_2,&ch2_period,1);
		//	  htim2.State = HAL_TIM_STATE_READY;
		//	  htim3.State = HAL_TIM_STATE_READY;

	}
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
