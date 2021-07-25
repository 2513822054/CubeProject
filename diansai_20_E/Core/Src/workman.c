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
	uint32_t i,j;
	uint8_t dataOutput[2048];
	float THD=0;
	float THD_data[6];
	float Vpp;
	float max=-32768,min=32768;
//	for(i=0;i<2048;i++)
//	{
//		//dataOutput[i]=(uint8_t)(dataCh1[i]/256);
//		dataCh1[i]-=32768;
//	}
	for(i=2;i<=1400;i++)
	{
		if(32768>=dataCh1[i-1] && 32768>dataCh1[i-2] && 32768<=dataCh1[i+1] && 32768<dataCh1[i+2])break;
	}
	for(j=i;j<i+600;j++)
	{
		dataOutput[j-i]=(uint8_t)(dataCh1[j]/256);
	}

	for(i=0;i<2048;i++)
	{
		//dataOutput[i]=(uint8_t)(dataCh1[i]/256);
		if(dataCh1[i]>max)max=dataCh1[i];
		if(dataCh1[i]<min)min=dataCh1[i];

		dataCh1[i]-=32768;
	}
	Vpp = max-min;
	Vpp = Vpp/65536*5.12;
	max = -32768;
	min = 32768;

//	OutputAll(0,dataCh1,2048);
//	OutputAll(1,dataCh1FFT,2048);
//	OutputAll(2,dataCh1,2048);

	if(isShow)
	{
		tft_form(0, 1, dataOutput,600, 0);
	}


	arm_rfft_fast_f32(&S, dataCh1, dataCh1FFT, 0);
	arm_cmplx_mag_f32(dataCh1FFT, dataCh1, FFT_SIZE);
	for(i=0;i<600;i++)
	{
		dataOutput[i] = dataCh1[i]/162000;
	}
	if(isShow)
	{
		tft_form(0, 1, dataOutput,600, 1);
	}

	if(++showtimes>=10)
	{
		tft_text_float(0, 5, Vpp);
		tft_text(0,6,"1k",2);

		for(i=0;i<5;i++)
		{
			THD_data[i]= dataCh1[32*(i+1)]/3200;
		}
		arm_power_f32(&THD_data[1],4,&THD);
		arm_sqrt_f32(THD, &THD);
		THD/=THD_data[0];
		THD*=100;
		tft_text_float(0,3,THD);

//
//		tft_text_float(0, 5, THD_data[0]);
//		tft_text_float(0, 6, THD_data[1]);
//		tft_text_float(0, 7, THD_data[2]);
//		tft_text_float(0, 8, THD_data[3]);
//		tft_text_float(0, 9, THD_data[4]);

		//方波
		if(THD_data[2]*2.9<THD_data[0] && THD_data[2]*3.1>THD_data[0] && THD_data[4]*5.1<THD_data[0] && THD_data[4]*5.3>THD_data[0])
		{
			uint8_t fangbo[4]={0xB7,0xBD,0xB2,0xA8};
			tft_text(0, 10, fangbo, 4);
		}
		//三角波
		else if(THD_data[2]*9.0<THD_data[0] && THD_data[2]*9.3>THD_data[0] && THD_data[4]*25<THD_data[0] && THD_data[4]*28>THD_data[0])
		{
			uint8_t fangbo[6]={0xC8,0xFD,0xBD,0xC7,0xB2,0xA8};
			tft_text(0, 10, fangbo, 6);
		}

		//标准正弦波
		else if(THD<1)
		{
			uint8_t fangbo[6]={0xD5,0xFD,0xCF,0xD2,0xB2,0xA8};
			tft_text(0, 10, fangbo, 6);
		}

		//无明显失真
		else if(THD<3.8)
		{
			uint8_t fangbo[10]={0xCE,0xDE,0xC3,0xF7,0xCF,0xD4,0xCA,0xA7,0xD5,0xE6};
			tft_text(0, 10, fangbo, 10);
		}

		//交越失真
		else if(THD<5)
		{
			uint8_t fangbo[8]={0xBD,0xBB,0xD4,0xBD,0xCA,0xA7,0xD5,0xE6};
			tft_text(0, 10, fangbo, 8);
		}

		//单向失真
		else if(THD<20)
		{
			uint8_t fangbo[8]={0xB5,0xA5,0xCF,0xF2,0xCA,0xA7,0xD5,0xE6};
			tft_text(0, 10, fangbo, 8);
		}

		//双向失真
		else if(THD<30)
		{
			uint8_t fangbo[8]={0xCB,0xAB,0xCF,0xF2,0xCA,0xA7,0xD5,0xE6};
			tft_text(0, 10, fangbo, 8);
		}

		//完全失真
		else
		{
			uint8_t fangbo[8]={0xCD,0xEA,0xC8,0xAB,0xCA,0xA7,0xD5,0xE6};
			tft_text(0, 10, fangbo, 8);
		}



		showtimes=0;
	}
//	HAL_NVIC_EnableIRQ(EXTI0_IRQn);



//	for(i=0;i<2048;i++)
//	{
//		dataCh1[i]/=100;
//	}
//
//	OutputAll(0,dataCh1,2048);
	HAL_TIM_Base_Start_IT(&htim1);
}




void resButton()
{
	// 显示曲线按钮被按下
		  if(controlbuf.controlid==0x07)
		  {
			  isShow = !isShow;
			  if(isShow==0)
			  {
				  tft_form_delete(0, 1, 0);
				  tft_form_delete(0, 1, 1);
			  }
		  }
		  //正常模式  0001
		  if(controlbuf.controlid==0x08)
		  {
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, RESET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, RESET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, SET);
		  }
		  //顶部失真 0101
		  if(controlbuf.controlid==0x09)
		  {
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, RESET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, SET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, SET);
		  }
		  //底部失真  0111
		  if(controlbuf.controlid==11)
		  {
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, RESET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, SET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, SET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, SET);
		  }
		  //双向失真失真  1111
		  if(controlbuf.controlid==12)
		  {
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, SET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, SET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, SET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, SET);
		  }
		  //交越失真   0000
		  if(controlbuf.controlid==13)
		  {
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, RESET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, RESET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, RESET);
		  }

}




