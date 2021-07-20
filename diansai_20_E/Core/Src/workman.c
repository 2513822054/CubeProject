#include "workman.h"



//tim1计数器
uint32_t count1=0;


//获取ads所有开启通道的值
void getAdsAll()
{
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	  HAL_SPI_TransmitReceive(&hspi3, txbuf, rxbuf, 2, 10);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	  ads_data[0] = *(uint16_t *)(&rxbuf[2]);
}


//tim1 响应函数
void ResTim1()
{
	getAdsAll();
	dataCh1[count1] = ads_data[0]*1.0;
	if(++count1>=2048)
	{
		HAL_TIM_Base_Stop_IT(&htim1);
		DosomethingTim1();
		count1=0;
	}
}

void DosomethingTim1()
{
	uint32_t i;


	for(i=0;i<2048;i++)
	{
		dataCh1[i]-=32768;
	}
	OutputAll(0,dataCh1,2048);
	//OutputAll(1,dataCh1FFT,2048);
	//OutputAll(2,dataCh1,2048);

	arm_rfft_fast_f32(&S, dataCh1, dataCh1FFT, 0);
	arm_cmplx_mag_f32(dataCh1FFT, dataCh1, FFT_SIZE);

	for(i=0;i<2048;i++)
	{
		dataCh1[i]/=100;
	}

	OutputAll(0,dataCh1,2048);

}






