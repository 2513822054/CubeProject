#ifndef __WORKMAN_H
#define __WORKMAN_H

#include "main.h"

extern float dataCh1[1024],dataCh2[1024];
extern uint32_t count1;



void getAdsAll();//获取ads所有开启通道的值
void resTim1();//tim1响应函数
void DosomethingTim1();//tim1完成函数
void resUart6();
void resTim3();
void DosomethingTim3();


void resTim4();


#endif
