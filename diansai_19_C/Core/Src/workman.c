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
//			phase = atan(pdata[1]/pdata[0]);
			phase = atan2f(pdata[1],pdata[0]);
		}
		//第四象限
		else
		{
			phase = atan(pdata[1]/(-pdata[0]));
			phase = 2*PI-phase;
		}
	}
	else
	{
		//第二象限
		if(pdata[1]>=0)
		{
			phase = atan((-pdata[1])/pdata[0]);
			phase = PI-phase;
		}
		//第三象限
		else
		{
			phase = atan(pdata[1]/pdata[0]);
			phase = PI+phase;
		}
	}
	return phase;
}

float gophaseDiffer(float *pdata1,float*pdata2)
{
	float phase1,phase2,differ;
	phase1=atan2f(pdata1[0],pdata1[1]);
	phase2=atan2f(pdata2[0],pdata2[1]);

	differ = phase1-phase2;
	if(differ > PI)
	{
		differ = -2*PI + differ;
	}
	if(differ < -PI)
	{
		differ = 2*PI + differ;
	}
	return differ;
}


void DosomethingTim1()
{
	float phase1,phase2,differ;
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
	differ = gophaseDiffer(&fftCh1[64], &fftCh2[64]);

	OutputAll(dataCh1, dataCh2, fftCh1, fftCh2, 1024);

	HAL_TIM_Base_Start_IT(&htim1);

}


void resUart6()
{
	if(controlbuf.controlid==5)
	{
		Write_frequence(0, 100);
	}
	if(controlbuf.controlid==6)
	{
		Write_frequence(0, 1000);
	}
	if(controlbuf.controlid==7)
	{
		Write_frequence(0, 10000);
	}
	if(controlbuf.controlid==8)
	{
		Write_frequence(0, 1000000);
	}
	if(controlbuf.controlid==9)
	{
		Write_frequence(0, 10);
	}
	if(controlbuf.controlid==10)
	{
		Write_frequence(0, 500000);
	}
	if(controlbuf.controlid==11)
	{
		Write_frequence(0, 300000);
	}
}


void resTim3()
{
	getAdsAll();
	onedataCh1[count3] = ads_data[0];
	onedataCh2[count3] = ads_data[1];
	onedataCh1[count3] = (onedataCh1[count3]-32768)/65536*5.12;
	//onedataCh2[count3] = (onedataCh2[count3]-32768)/65536*5.12+0.005;
	onedataCh2[count3] = (onedataCh2[count3]-32768)/65536*5.12;


	if(++count3 >=500)
	{
		HAL_TIM_Base_Stop_IT(&htim3);
		count3=0;
		DosomethingTim3();
	}



}

void DosomethingTim3()
{
	float avg1,avg2,Z;
	arm_mean_f32(onedataCh1,500,&avg1);
	//avg1=onedataCh1[250];
	arm_mean_f32(onedataCh2,500,&avg2);
	tft_text_float(0, 3, avg1);
	tft_text_float(0, 4, avg2);
//
//	if(avg2>=0.11)avg2 = -0.0143*avg2 + 1.0143;
//	if(avg2<0.11)avg2 = 89.834*avg2*avg2 - 13.271*avg2 + 1.4967;

	Z=sqrt(avg1*avg1/avg2/avg2-1);
	Z=620/Z;
	tft_text_float(0, 12, Z);

	Z=avg2/(avg1-avg2)*620;
	tft_text_float(0, 14, Z);




	HAL_TIM_Base_Start_IT(&htim3);
}






