#ifndef __TFT_H
#define __TFT_H
#include "main.h"
#define SEND &huart6
#define RECEIVE &huart1

extern uint8_t R_onedata,R_alldata[256];

//接收指令   //如果返回值是0则说明暂时没有接收到完整数据
//1说明返回的是按钮指令    会将按下的按钮和按下的状态存入buttonbuf内
uint8_t tft_receive();

//处理指令
uint8_t tft_manage();
//发送文本控件内容
void tft_text(uint8_t screen,uint8_t id,uint8_t *text,uint8_t len);
//发送图标内容   曲线表
void tft_form(uint8_t screen,uint8_t id,uint8_t *text,uint16_t len);

typedef struct
{
	//界面号
	uint8_t screenid;
	//控件号
	uint8_t buttonid;
	//按下还是弹起
	uint8_t press;
}tft_button;

extern tft_button buttonbuf;

#endif
