#include "tft.h"

//收到指令值和指令单元
uint8_t R_onedata,R_alldata[256];
uint32_t R_place;
tft_button buttonbuf;



//文本控件发送内容
void tft_text(uint8_t screen,uint8_t id,uint8_t *text,uint8_t len)
{
	uint8_t head[7]={0xEE,0xB1,0x10,0x00,screen,0x00,id};
	uint8_t end[4]={0xFF,0xFC,0xFF,0xFF};
	HAL_UART_Transmit(SEND, head, 7, 5);
	HAL_UART_Transmit(SEND, text, len, 5);
	HAL_UART_Transmit(SEND, end, 4, 5);
}
//发送图标内容
void tft_form(uint8_t screen,uint8_t id,uint8_t *text,uint16_t len)
{
	uint8_t head[10]={0xEE,0xB1,0x32,0x00,0x00,0x00,id,0x00,(uint8_t)(len),(uint8_t)(len>>8)};
	uint8_t end[4]={0xFF,0xFC,0xFF,0xFF};
	HAL_UART_Transmit(SEND, head, 10, 5);
	HAL_UART_Transmit(SEND, text, len, 5);
	HAL_UART_Transmit(SEND, end, 4, 5);
}

uint32_t i;
//接收指令
uint8_t tft_receive()
{
	uint8_t state;
	R_alldata[R_place]=R_onedata;     //±£´æÖ¸Áîµ¥Ôª
	//Èç¹ûÖ¸Áîµ¥ÔªÎªÖ¸ÁîÍ·
	if(R_onedata==0xEE){
	R_place++;                                      //¿ªÊ¼»ñÈ¡ÏÂÒ»¸öÖ¸Áîµ¥Ôª
	}
	else if(R_place>=1)R_place++;
	//³¬¹ýÎå¸öÖ¸Áîµ¥ÔªºóÅÐ¶ÏÊÇ·ñ½áÊøÖ¸Áî
	if(R_place>5){
		if(R_alldata[R_place-1]==0xFF&&R_alldata[R_place-2]==0xFF&&R_alldata[R_place-3]==0xFC&&R_alldata[R_place-4]==0xFF){
			state=tft_manage();                            //µ÷ÓÃÖ¸Áî´¦Àíº¯Êý
			for(i=0;i<=255;i++)R_alldata[i]=0;            //Çå¿ÕÖ¸Áî
			R_place=0;                                                  //Ö¸ÁîÎ»ÖÃÇåÁã
		}
	}
	R_onedata = 0;                                                                             //Çå¿ÕÖ¸Áîµ¥Ôª£¬»ñÈ¡ÏÂÒ»¸öÖ¸Áîµ¥Ôª
	HAL_UART_Receive_IT(RECEIVE, (uint8_t *)&R_onedata, 1);
	return state;
}

uint8_t tft_manage()
{
	//按钮被按下
	if(R_alldata[1]==0xB1 && R_alldata[2]==0x11 && R_alldata[3]==0x00)
	{
		buttonbuf.screenid = R_alldata[4];
		buttonbuf.buttonid = R_alldata[6];
		buttonbuf.press = R_alldata[9];
		return 1;
	}



	return 0;
}







