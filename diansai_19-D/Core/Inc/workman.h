#ifndef __WORKMAN_H
#define __WORKMAN_H

#include "main.h"

//不同模式的开启和停止
void stateMode0_Start();
void stateMode1_Start();
void stateMode2_Start();
void stateMode3_Start();
void stateMode0_Stop();
void stateMode1_Stop();
void stateMode2_Stop();

//不同模式下指令定时器的操作函数
void tim4Mode0();
void tim4Mode1();
void tim4Mode2();
//校准模式
void tim4Mode3();


//不同模式下采样定时器的操作函数
void tim3Mode0();
void tim3Mode1();
void tim3Mode2();
//校准模式
void tim3Mode3();

//1模式下定时器5的操作函数
void tim5Mode1();
//不同模式下显示界面的函数
void showMode0();
void showMode1();
void showMode2();

//模式2下测量通道4的平均值
uint16_t getCh4Avg();

//ads获取四个通道值
void ads_get_all();

void Dosomething3();
void Dosomething3Mode0();
void Dosomething3Mode2();
void Dosomething3Mode3();
#endif
