#ifndef __WORKMAN_H_
#define __WORKMAN_H_
#include "ad9959.h"
#include "ADS8688.h"
#include "DAC8563.h"
#include "outputdata.h"
#include "tft.h"
#include "Zdosomething.h"
#include "Zresponse.h"
#include "W25Q128.h"
#include "main.h"


extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi3;

extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim3;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart6;

extern uint32_t count3;
float DACoutput[200];
void get_ads_alldata();

//初始化自己外设及while循环前的函数
void init_start();
//while循环里做的函数
void while_do();




#endif
