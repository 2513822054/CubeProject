#include "workman.h"

uint32_t count1=0;
float dataCh1[1024]={0},dataCh2[1024]={0};


//获取ads所有开启通道的值
void getAdsAll()
{
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	  HAL_SPI_TransmitReceive(&hspi3, txbuf, rxbuf, 2, 10);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	  ads_data[0] = *(uint16_t *)(&rxbuf[2]);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	  HAL_SPI_TransmitReceive(&hspi3, txbuf, rxbuf, 2, 10);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	  ads_data[1] = *(uint16_t *)(&rxbuf[2]);

}



void resTim1()
{
	getAdsAll();
	dataCh1[count1] = ads_data[0];
	dataCh2[count1] = ads_data[1];
	if(++count1==1024)
	{
		HAL_TIM_Base_Stop_IT(&htim1);
		count1=0;
		DosomethingTim1();
	}

}

//判断相位函数
float gophase(float *pdata)
{
	float phase;
	if(pdata[0]>=0)
	{
		//第一象限
		if(pdata[1]>=0)
		{
			phase = atan(pdata[1]/pdata[0]);
		}
		//第四象限
		else
		{
			phase = atan(pdata[1]/(-pdata[0]));
			phase = 6.2831852-phase;
		}
	}
	else
	{
		//第二象限
		if(pdata[1]>=0)
		{
			phase = atan((-pdata[1])/pdata[0]);
			phase = 3.1415926-phase;
		}
		//第三象限
		else
		{
			phase = atan(pdata[1]/pdata[0]);
			phase = 3.1415926+phase;
		}
	}
	return phase;
}

void DosomethingTim1()
{
	float phase1,phase2;
	uint32_t i;
	float bufCh1[1024],bufCh2[1024];
	float fftCh1[1024],fftCh2[1024];
	//拷贝采样到的函数
	arm_copy_f32(&dataCh1, &bufCh1, 1024);
	arm_copy_f32(&dataCh2, &bufCh2, 1024);



	arm_rfft_fast_f32(&S, bufCh1, fftCh1, 0);
	arm_rfft_fast_f32(&S, bufCh2, fftCh2, 0);

	for(i=0;i<1024;i++)
	{
		fftCh1[i]/=100;
		fftCh2[i]/=100;
	}


	phase1=gophase(&fftCh1[64]);
	phase2=gophase(&fftCh2[64]);


	OutputAll(dataCh1, dataCh2, fftCh1, fftCh2, 1024);

	HAL_TIM_Base_Start_IT(&htim1);

}
