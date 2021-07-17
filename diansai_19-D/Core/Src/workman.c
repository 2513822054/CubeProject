#include "workman.h"

//二通道检测的峰峰值  和三通道检测的直流量   两次测量的
float Vpp21,Vpp22;
float Vdc31,Vdc32;

//校准模式测得值
float VppTrue=0,VdcTrue=0;
float LTrue=0,HTrue=0;

uint8_t error;
uint16_t ch4_L,ch4_H;

//ch4  低频和高频时的幅值测试用
uint8_t ch4_L_show[30],ch4_H_show[30];

uint16_t caliTimes=0;//校准次数

//模式开启和关闭
void stateMode0_Start()
{
	count3=0;
	count4=0;
	count5=130;
	stateMode=0;
	stateMode0_Stop();
	Write_frequence(0,1000);
	HAL_TIM_Base_Start_IT(&htim4);
}
void stateMode1_Start()
{
	stateMode0_Stop();

	count3=0;
	count4=0;
	stateMode=1;
	PE0=0;
	Write_Amplitude(0, 100);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, 0);

	HAL_TIM_Base_Start_IT(&htim5);
}
void stateMode2_Start()
{

	stateMode0_Stop();

	count3=0;
	count4=0;
	stateMode=2;
	PE0=0;
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, 0);

	HAL_TIM_Base_Start_IT(&htim4);

}
void stateMode3_Start()
{
	stateMode0_Stop();

	count3=0;
	count4=0;
	stateMode=3;
	PE0=0;
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, 0);

	VppTrue = 0;
	VdcTrue = 0;
	LTrue = 0;
	HTrue = 0;

	HAL_TIM_Base_Start_IT(&htim4);
}
void stateMode0_Stop()
{
	Write_Amplitude(0, 260);
	count3=0;
	count4=0;
	//stateMode=0;
	HAL_TIM_Base_Stop_IT(&htim4);
	HAL_TIM_Base_Stop_IT(&htim3);
	HAL_TIM_Base_Stop_IT(&htim5);
	Write_frequence(0,1000);
}
void stateMode1_Stop()
{
	count3=0;
	count4=0;
	//stateMode=0;
	HAL_TIM_Base_Stop_IT(&htim4);
	HAL_TIM_Base_Stop_IT(&htim3);
	HAL_TIM_Base_Stop_IT(&htim5);
	Write_frequence(0,1000);
}
void stateMode2_Stop()
{
	count3=0;
	count4=0;
	//stateMode=0;
	HAL_TIM_Base_Stop_IT(&htim4);
	HAL_TIM_Base_Stop_IT(&htim3);
	Write_frequence(0,1000);
}
void tim4Mode0()
{
	//翻转PE0
	PE0=!PE0;
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, PE0);
	//显示界面或采样
	if(++count4>=5)
	{
		count4=0;
		showMode0();
	}
	else
	{
		HAL_Delay(30);
		HAL_TIM_Base_Start_IT(&htim3);
	}


}
void tim4Mode1()
{

}

uint8_t judgeman(float ch2Vpp,float ch3Vdc)
{
	float ratio2=ch2Vpp/VppTrue,ratio3=ch3Vdc/VdcTrue;
	uint8_t state2,state3;
	if(ratio2<0.3)state2=0;
	else if(ratio2<1.5)state2=1;
	else if(ratio2<2.7)state2=2;
	else if(ratio2<4)state2=3;
	else return 2;

	if(ratio3<0.1)state3=0;
	else if(ratio3<1.2)state3=1;
	else if(ratio3<2.2)state3=2;
	else state3=3;

	switch(state2)
	{
		case 0:
		{
			if(state3==0)return 8;
			else if(state3==2)return 6;
			else if(state3==3)return 5;
			break;
		}
		case 1:
		{
			if(state3==0)return 3;
			else if(state3==1)
			{
				if(ratio3<0.95)
				{
					return 2;
				}
				else
				{
					return 0;
				}
			}
			else if(state3==3)return 7;
			break;
		}
		case 2:
		{
			if(state3==1)return 10;
			else if(state3==2)
			{
				if(ch2Vpp/Vpp2>2.3)return 1;
				else return 4;
			}
			break;
		}
		case 3:
		{
			if(state3==1)return 9;
			break;
		}
	}
	return 15;

}
uint8_t judgeman2()
{
	float state1=ch4_L/LTrue,state2=ch4_H/HTrue;
	if(state1>=1.175)return 13;
	else if(state2>=1.08)return 11;
	else if(state2<0.93)return 14;

}


void showError()
{
	uint8_t vpp2_print[20],Vdc3Load_print[20],Vdc3Noload_print[20];

	sprintf(vpp2_print,"%.6f\r\r\n",Vpp22);
	sprintf(Vdc3Load_print,"%.3f\r\r\n",Vdc32);

	tft_text(0,11,vpp2_print,10);
	tft_text(0,12,Vdc3Load_print,10);

	switch(error)
	{
		case 0:tft_text(0,14,"NoError",10);break;
		case 1:tft_text(0,14,"R1 Open",10);break;
		case 2:tft_text(0,14,"R2 Open",10);break;
		case 3:tft_text(0,14,"R3 Open",10);break;
		case 4:tft_text(0,14,"R4 Open",10);break;
		case 5:tft_text(0,14,"R1 Short",10);break;
		case 6:tft_text(0,14,"R2 Short",10);break;
		case 7:tft_text(0,14,"R3 Short",10);break;
		case 8:tft_text(0,14,"R4 Short",10);break;
		case 9:tft_text(0,14,"C1 Open",10);break;
		case 10:tft_text(0,14,"C2 Open",10);break;
		case 11:tft_text(0,14,"C3 Open",10);break;
		case 12:tft_text(0,14,"C1 Double",10);break;
		case 13:tft_text(0,14,"C2 Double",10);break;
		case 14:tft_text(0,14,"C3 Double",10);break;
	}

}


void tim4Mode2()
{

	//如果count4在4以内则用切换电平进行channel2 和 Ch3的测量
	if(count4<=3)
	{
		switch(count4)
		{
			case 0:
			{
				PE0=0;
				count4++;
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, PE0);
				return;
			}
			case 1:
			{
				PE0=1;
				count4++;
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, PE0);
				HAL_Delay(30);
				HAL_TIM_Base_Start_IT(&htim3);
				//HAL_TIM_Base_Start(&htim3);
				return;
			}
			case 2:
			{
				PE0=0;
				count4++;
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, PE0);
				return;
			}
			case 3:
			{
				PE0=1;
				count4++;
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, PE0);
				HAL_Delay(30);
				HAL_TIM_Base_Start_IT(&htim3);
				return;
			}
		}
	}
	else if(count4==4)
	{
		error = judgeman(Vpp21, Vdc31);
		//showError();
		//如果两次错误一样，则可以进入下一步   不一样则重新测
		if(error == judgeman(Vpp22, Vdc32))
		{
			//如果无错误则进入幅度测试   修改幅度和继电器设置为空载
			if(error==0)
			{
				count4++;
				//test

				//count4=0;

				PE0=0;
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, PE0);
				Write_frequence(0,100);

				return;
			}
			//如果判断不出则重新进行测试
			else if(error == 15)
			{
				count4=0;
				return;
			}
			//判断出错误了进行显示并归位
			else
			{
				showError();
				count4=0;
				return;
			}
		}
		else
		{
			count4=0;
			return;
		}
	}
	else if(count4==5)
	{
		count4++;
		return;
	}

	//进行频率测试
	else if(count4==6)
	{
		//error =0;
		//showError();
		//count4=0;
		ch4_L=getCh4Avg();
		//修改为高频为下一次测试做准备
		Write_frequence(0,70000);
		count4++;
		//count4++;
		return;
	}
	//等待100ms
	else if(count4==7)
	{
		count4++;
		return;
	}

	else if(count4==8)
	{
		float L4,H4;
		ch4_H=getCh4Avg();
		Write_frequence(0,1000);

		L4=(int32_t)(ch4_L)*1.0;
		H4=(int32_t)(ch4_H)*1.0;
		//判断test
		sprintf(ch4_L_show,"%.1f",L4);
		sprintf(ch4_H_show,"%.1f",H4);
		tft_text(0,13,ch4_L_show,9);
		tft_text(0,16,ch4_H_show,9);

		error = judgeman2();
		showError();
		count4=0;
		return;
	}
}


//校准模式
void tim4Mode3()
{
	if(count4==0)
	{
		PE0=0;
		count4++;
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, PE0);
		return;
	}
	else if(count4==1)
	{
		PE0=1;
		count4++;
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, PE0);
		HAL_Delay(30);
		HAL_TIM_Base_Start_IT(&htim3);
		return;
	}
	else if(count4==2)
	{
		PE0=0;
		count4++;
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, PE0);
		return;
	}
	else if(count4==3)
	{
		PE0=1;
		count4++;
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, PE0);
		HAL_Delay(30);
		HAL_TIM_Base_Start_IT(&htim3);
		return;
	}
	else if(count4==4)
	{
		PE0=0;
		count4++;
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, PE0);
		Write_frequence(0, 100);
		return;
	}


	else if(count4==5)
	{
		count4++;
		return;
	}
	else if(count4==6)
	{
		count4++;
		LTrue += getCh4Avg();
		Write_frequence(0,70000);
		return;
	}
	else if(count4==7)
	{

		count4++;
		return;
	}
	else if(count4==8)
	{

    	float L4,H4;
    	HTrue += getCh4Avg();
    	Write_frequence(0,1000);
    	count4=0;

    	if(++caliTimes==10)
    	{
    		HAL_TIM_Base_Stop_IT(&htim4);
    		caliTimes=0;
    		LTrue = LTrue/10;
    		HTrue = HTrue/10;
    		VppTrue = VppTrue/20;
    		VdcTrue = VdcTrue/20;

    		L4=(int32_t)(LTrue)*1.0;
    		H4=(int32_t)(HTrue)*1.0;
    		//判断test
    		sprintf(ch4_L_show,"LTrue:%.1f",L4);
    		sprintf(ch4_H_show,"HTrue:%.1f",H4);
    		tft_text(0,13,ch4_L_show,15);
    		tft_text(0,16,ch4_H_show,15);

    		//判断test
    		uint8_t vpp2_print[20],Vdc3Load_print[20],Vdc3Noload_print[20];
    		//test
    		sprintf(vpp2_print,"%.6f\r\r\n",VppTrue);
    		sprintf(Vdc3Load_print,"%.3f\r\r\n",VdcTrue);
    		tft_text(0,11,vpp2_print,15);
    		tft_text(0,12,Vdc3Load_print,15);

    		stateMode = 0;
    	}
    	return;
	}

}


//采样函数
void ads_get_all()
{
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	  HAL_SPI_TransmitReceive(&hspi3, txbuf, rxbuf, 2, 10);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	  ads_data[0] = *(uint16_t *)(&rxbuf[2]);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	  HAL_SPI_TransmitReceive(&hspi3, txbuf, rxbuf, 2, 10);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	  ads_data[1] = *(uint16_t *)(&rxbuf[2]);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	  HAL_SPI_TransmitReceive(&hspi3, txbuf, rxbuf, 2, 10);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	  ads_data[2] = *(uint16_t *)(&rxbuf[2]);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	  HAL_SPI_TransmitReceive(&hspi3, txbuf, rxbuf, 2, 10);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	  ads_data[3] = *(uint16_t *)(&rxbuf[2]);
}

//采样定时器响应函数
void tim3Mode0()
{
	ads_get_all();
	if(ch1max<ads_data[0])ch1max=ads_data[0];
	if(ch2max<ads_data[1])ch2max=ads_data[1];
	if(ch3max<ads_data[2])ch3max=ads_data[2];
	if(ch1min>ads_data[0])ch1min=ads_data[0];
	if(ch2min>ads_data[1])ch2min=ads_data[1];
	if(ch3min>ads_data[2])ch3min=ads_data[2];
	if(++count3>=600)
	{
		HAL_TIM_Base_Stop_IT(&htim3);
		count3=0;
		Dosomething3Mode0();
	}
}
void tim3Mode1()
{


}
void tim3Mode2()
{
	ads_get_all();
	//if(ch1max<ads_data[0])ch1max=ads_data[0];
	if(ch2max<ads_data[1])ch2max=ads_data[1];
	if(ch3max<ads_data[2])ch3max=ads_data[2];
	//if(ch1min>ads_data[0])ch1min=ads_data[0];
	if(ch2min>ads_data[1])ch2min=ads_data[1];
	if(ch3min>ads_data[2])ch3min=ads_data[2];
	if(++count3>=600)
	{
		HAL_TIM_Base_Stop_IT(&htim3);
		count3=0;
		if(stateMode==2)Dosomething3Mode2();
		else Dosomething3Mode3();
	}

}


//各模式下的显示函数
void showMode0()
{
	//test
	uint8_t vpp2_print[20],Vdc3Load_print[20],Vdc3Noload_print[20];



	static uint8_t Ri_print[20],Ro_print[20],Au_print[20];
	//sprintf(Ri_print,"%.3f\r\r\n",Ri[3]);
	sprintf(Ri_print,"%.6f\r\r\n",(Ri[1]+Ri[2]+Ri[3]+Ri[4])/4);
	sprintf(Ro_print,"%.3f\r\r\n",Ro);
	sprintf(Au_print,"%.6f\r\r\n",Au);

	//test
	sprintf(vpp2_print,"%.6f\r\r\n",Vpp2);
	sprintf(Vdc3Load_print,"%.3f\r\r\n",Vdc3Load);
	sprintf(Vdc3Noload_print,"%.6f\r\r\n",Vpp1);


	tft_text(0,1,Ri_print,20);
	tft_text(0,2,Ro_print,20);
	tft_text(0,3,Au_print,20);

	//test
	tft_text(0,11,vpp2_print,20);
	tft_text(0,12,Vdc3Load_print,20);
	tft_text(0,13,Vdc3Noload_print,20);


}

//tim3采样完后的函数
void Dosomething3Mode0()
{
	//将最大值最小值化成浮点型
	ch1max_f = ((int32_t)ch1max-32768)/65536.0*5.12;
	ch2max_f = ((int32_t)ch2max-32768)/65536.0*5.12;
	ch3max_f = ((int32_t)ch3max)/65536.0*10.24;
	ch1min_f = ((int32_t)ch1min-32768)/65536.0*5.12;
	ch2min_f = ((int32_t)ch2min-32768)/65536.0*5.12;
	ch3min_f = ((int32_t)ch3min)/65536.0*10.24;

	ch1max=0;
	ch2max=0;
	ch3max=0;
	ch1min=65535;
	ch2min=65535;
	ch3min=65535;

	//求各项指标
	Vpp1=ch1max_f - ch1min_f;
	Vpp2=ch2max_f - ch2min_f;

	Vdc1=(ch1max_f + ch1min_f)/2;
	Vdc2=(ch2max_f + ch2min_f)/2;

	//如果PE0为高   继电器连接  测得的是带载的情况
	if(PE0)
	{
		Vpp3Load = ch3max_f - ch3min_f;
		Vdc3Load = (ch3max_f + ch3min_f)/2;
	}
	else
	{
		Vpp3Noload = ch3max_f - ch3min_f;
		Vdc3Noload = (ch3max_f + ch3min_f)/2;
	}
	Ri[count4] = Vpp2/(Vpp1-Vpp2)*6.8;
	Ro = (Vdc3Noload-Vdc3Load)/Vdc3Load*1.6;
	Au = Vpp3Noload/Vpp2*2;
}
void Dosomething3Mode2()
{
	//ch1max_f = ((int32_t)ch1max-32768)/65536.0*5.12;
	ch2max_f = ((int32_t)ch2max-32768)/65536.0*5.12;
	ch3max_f = ((int32_t)ch3max)/65536.0*10.24;
	//ch1min_f = ((int32_t)ch1min-32768)/65536.0*5.12;
	ch2min_f = ((int32_t)ch2min-32768)/65536.0*5.12;
	ch3min_f = ((int32_t)ch3min)/65536.0*10.24;

	//求各项指标
//	Vpp1=ch1max_f - ch1min_f;
//	Vpp2=ch2max_f - ch2min_f;
//
//	Vdc1=(ch1max_f + ch1min_f)/2;
//	Vdc2=(ch2max_f + ch2min_f)/2;
	if(count4==2)
	{
		Vpp21 = ch2max_f - ch2min_f;
		Vdc31 = (ch3max_f + ch3min_f)/2;
	}
	else if(count4==4)
	{
		Vpp22 = ch2max_f - ch2min_f;
		Vdc32 = (ch3max_f + ch3min_f)/2;
	}

	ch1max=0;
	ch2max=0;
	ch3max=0;
	ch1min=65535;
	ch2min=65535;
	ch3min=65535;

}

void Dosomething3Mode3()
{
	//ch1max_f = ((int32_t)ch1max-32768)/65536.0*5.12;
	ch2max_f = ((int32_t)ch2max-32768)/65536.0*5.12;
	ch3max_f = ((int32_t)ch3max)/65536.0*10.24;
	//ch1min_f = ((int32_t)ch1min-32768)/65536.0*5.12;
	ch2min_f = ((int32_t)ch2min-32768)/65536.0*5.12;
	ch3min_f = ((int32_t)ch3min)/65536.0*10.24;

	//求各项指标
//	Vpp1=ch1max_f - ch1min_f;
//	Vpp2=ch2max_f - ch2min_f;
//
//	Vdc1=(ch1max_f + ch1min_f)/2;
//	Vdc2=(ch2max_f + ch2min_f)/2;
	if(count4==2)
	{
		VppTrue += ch2max_f - ch2min_f;
		VdcTrue += (ch3max_f + ch3min_f)/2;
	}
	else if(count4==4)
	{
		VppTrue += ch2max_f - ch2min_f;
		VdcTrue += (ch3max_f + ch3min_f)/2;
	}

//	if(++caliTimes==20)
//	{
//		HAL_TIM_Base_Stop_IT(&htim4);
//	}


	ch1max=0;
	ch2max=0;
	ch3max=0;
	ch1min=65535;
	ch2min=65535;
	ch3min=65535;

}



void showMode1()
{
	int j;
	int16_t L1,L2,H1,H2,D1,D2;
	float L=0,H=0;
	float L_freq,H_freq;
	uint16_t MAX_AF,F7;

	uint8_t L_text[12],H_text[12];

	for(MAX_AF=AF[0],j=1;j<400;j++)
	{
      if(MAX_AF < AF[j]) MAX_AF = AF[j];
      //MAX_place = j;
	}
	//求上下限频率值
	F7=MAX_AF*0.707213;
	for(j=0;j<=399;j++)
	{
		if(L==0)
		{
			if(F7-AF[j]>=0)
			{
				L1=j;
				D1=F7-AF[j];
			}
			else
			{
				D2=AF[j]-F7;
				L=(float)L1+D1*1.0/(D2+D1);
			}
		}
		else
		{

				if(AF[j]-F7>=0)
				{
					H1=j;
					D1=AF[j]-F7;
				}
				else
				{
					D2=F7-AF[j];
					H=(float)H1+D1*1.0/(D2+D1);
					break;
				}
		}
	}
	L_freq = L*12.5;
	H_freq = ((H-120)*500+10000)/1000;

	for(j=0;j<=399;j++)
	{
		//AF_print[j]=(uint8_t)(AF[j]*1.0/AF_max*65536/256);
		//AF_print[j]=(uint8_t)(AF[j]/16);
		AF_print[j] = (uint32_t)AF[j]*256/MAX_AF-1;
	}
	sprintf(L_text,"%.2fHz",L_freq);
	sprintf(H_text,"%.2fKHz",H_freq);
	tft_text(0,9,H_text,12);
	tft_text(0,10,L_text,12);

	tft_form(0,5,AF_print,400);
	AF_max=0;
	count5=0;
	HAL_TIM_Base_Start(&htim5);

}

void tim5Mode1()
{
	//if(count5<=400)Write_frequence(0, (count5+1)*500);
//	if(count5<=40)
//	{
//		Write_frequence(0, count5*25);
//	}
//	else if(count5<=80)
//	{
//		Write_frequence(0, (count5-40)*225+1000);
//	}
//	else if(count5<=400)
//	{
//		Write_frequence(0, (count5-80)*593.75+10000);
//	}
//	if(count5>=450)
//	{
//		Write_frequence(0, 0);
//	}
//	if(count5>=0&&count5<400)
//	{
//		ads_get_all();
//		AF[count5]=ads_data[3];
//		if(ads_data[3]>AF_max)
//		{
//			AF_max=ads_data[3];
//			AF_place=count5-20;
//		}
//	}
//	count5++;
//	if(count5>=400)
//	{
//		HAL_TIM_Base_Stop(&htim5);
//		showMode1();
//	}
	if(count5<=50)
	{
		//count5=10;
		Write_frequence(0, 10);
	}
	else if(count5<=130)
	{
		Write_frequence(0, (count5-50)*12.5);
	}
	else if(count5<=170)
	{
		Write_frequence(0, (count5-130)*225+1000);
	}
	else if(count5<=450)
	{
		Write_frequence(0, (count5-170)*500+10000);
	}

	if(count5>=50 && count5<450)
	{
		//TODO: DELAY
		HAL_Delay(10);
		ads_get_all();
		AF[count5-50]=ads_data[3];
	}
	count5++;
	if(count5>=450)
	{
		HAL_TIM_Base_Stop(&htim5);
		showMode1();
	}

}

uint16_t getCh4Avg()
{
	uint32_t all=0,j;
	for(j=0;j<8;j++)
	{
		ads_get_all();
		all+=ads_data[3];
		HAL_Delay(4);
	}
	return (uint16_t)(all/8);

}



