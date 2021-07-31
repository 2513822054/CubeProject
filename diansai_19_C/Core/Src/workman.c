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
	float avg1,avg2;
	arm_mean_f32(onedataCh1,500,&avg1);
	//avg1=onedataCh1[250];
	arm_mean_f32(onedataCh2,500,&avg2);

//	if(avg2>=0.11)avg2 = -0.0143*avg2 + 1.0143;
//	if(avg2<0.11)avg2 = 89.834*avg2*avg2 - 13.271*avg2 + 1.4967;

	//补偿
	if(avg1<0.8)avg1 = (-0.42*avg1*avg1*avg1 + 0.6881*avg1*avg1 - 0.3851*avg1 + 1.1015)*avg1;
	else avg1=(0.0006*avg1 + 1.02)*avg1;

	if(avg2<0.8)avg2 = (-0.5028*avg2*avg2*avg2 + 0.8667*avg2*avg2 - 0.511*avg2 + 1.13)*avg2;
	else avg2 = 1.02*avg2;

	tft_text_float_3(0, 3, avg1);
	tft_text_float_3(0, 4, avg2);


	Z[0]=sqrt(avg1*avg1/avg2/avg2-1);
	Z[0]=620/Z[0];
	tft_text_float_3(0, 12, Z[0]);

	Z[0]=avg2/(avg1-avg2)*620;
	tft_text_float_3(0, 14, Z[0]);


	HAL_TIM_Base_Start_IT(&htim3);
}


void resTim4()
{
	if(count4<=200)
	{
	getAdsAll();
	sweepCh1[count4] = ads_data[0];
	sweepCh2[count4] = ads_data[1];
	sweepCh1[count4] = (sweepCh1[count4])/65536*5.12;
	//onedataCh2[count3] = (onedataCh2[count3]-32768)/65536*5.12+0.005;
	sweepCh2[count4] = (sweepCh2[count4])/65536*5.12;

//	Z[count4] = sqrt(sweepCh1[count4]*sweepCh1[count4]/sweepCh2[count4]/sweepCh2[count4]-1);
//	Z[count4]=620/Z[count4];
	Z[count4]=sweepCh2[count4]/sweepCh1[count4];
	}
	if(++count4<=200)
	{
		Write_frequence(0, 2500*count4);
		//Write_frequence(0, 48000);
	}
	else if(count4<=250)
	{
		Write_frequence(0, 30);
	}
	else
	{
		HAL_TIM_Base_Stop_IT(&htim4);
		count4=0;
		DosomethingTim4();
	}

}

void DosomethingTim4()
{
	uint32_t i;
	uint8_t Zshow[201],showCh1[201],showCh2[201];
	float Zmax,ch1max,ch2max,Zmin;
	uint32_t ZmaxP,ch1maxP,ch2maxP,ZminP;
	float std;
	arm_max_f32(Z,201,&Zmax,&ZmaxP);
	arm_min_f32(Z,201,&Zmin,&ZminP);
	//arm_max_f32(sweepCh1,201,&ch1max,&ch1maxP);
	//arm_max_f32(sweepCh2,201,&ch2max,&ch2maxP);

	for(i=0;i<=200;i++)
	{
		//Zshow[i]=Z[i]/Zmax*255;
		Zshow[i]=Z[i]*255;
		showCh1[i] = sweepCh1[i]/ch1max *255;
		showCh2[i] = sweepCh2[i]/ch2max *255;
	}
	tft_form(0, 8, Zshow, 201, 0);
	//tft_form(0, 9, showCh1, 201, 0);
	tft_form(0, 10, showCh2, 201, 0);
	//tft_text_float_3(0, 4, ch2max);
	tft_text_float_3(0, 12, Zmax);
	//tft_text_float_3(0, 3, ch1max);
	tft_text_int(0, 3, ZmaxP);
	tft_text_int(0, 4, ZminP);
	//arm_var_f32(Z,201,&std);
	//arm_var_f32(Z,201,&std);
	arm_std_f32(Z,201,&std);
	tft_text_float_6(0, 11, std);

	//曲线平缓情况
	if(std<=0.025)
	{
		//断路情况
		if(Z[0]>=0.96)
		{
			tft_text(0, 9, "open", 5);
		}
		//短路情况
		else if(Z[0]<=0.1)
		{
			tft_text(0, 9, "short", 5);
		}
		//电阻情况
		else
		{
			uint8_t output[8] = {0xD2,0xBB,0xB8,0xF6,0xB5,0xE7,0xD7,0xE8};
			tft_text(0, 9, output, 8);
		}
	}
	else
	{
		//阻抗下降情况
		if(ZmaxP<10 && ZminP>191)
		{
			//单电容情况
			if(Z[0]>0.9)
			{
				uint8_t output[8] = {0xD2,0xBB,0xB8,0xF6,0xB5,0xE7,0xC8,0xDD};
				tft_text(0, 9, output, 8);
			}
			//电容电阻并联
			else
			{
				uint8_t output[12] = {0xB5,0xE7,0xC8,0xDD,0xB5,0xE7,0xD7,0xE8,0xB2,0xA2,0xC1,0xAA};
				tft_text(0, 9, output, 12);
			}
		}
		//阻抗上升情况
		else if(ZminP<15 && ZmaxP>191)
		{
			//单电感情况
			if(1)
			{
				uint8_t output[8] = {0xD2,0xBB,0xB8,0xF6,0xB5,0xE7,0xB8,0xD0};
				tft_text(0, 9, output, 8);
			}
		}
		//阻抗脉冲变化情况
		else if(ZmaxP>10 && ZmaxP<191)
		{
			//电容电感并联
			if(1)
			{
				uint8_t output[12] = {0xB5,0xE7,0xC8,0xDD,0xB5,0xE7,0xB8,0xD0,0xB2,0xA2,0xC1,0xAA};
				tft_text(0, 9, output, 12);
			}
		}
		else if(ZminP>10 && ZminP<191)
		{
			//电容电感串联
			if(1)
			{
				uint8_t output[12] = {0xB5,0xE7,0xC8,0xDD,0xB5,0xE7,0xB8,0xD0,0xB4,0xAE,0xC1,0xAA};
				tft_text(0, 9, output, 12);
			}
		}

	}


	HAL_TIM_Base_Start_IT(&htim4);



}






