/*
 * delay.c
 *
 *  Created on: 16.03.2023
 *      Author: lukas
 */

#include "delay.h"
#include <shalf1.h>
#include <stdbool.h>

bool timFlag = false;

//TestPush

void initTimer(void){
	__disable_irq();
	timerBusClkOn(TIM2);
	timerSetPrescaler(TIM2, TIM_PSC);
	timerEnableInterrupt(TIM2);
	timerSetOnePulseMode(TIM2, ONE_PULSE_MODE_ON);
	NVIC_EnableIRQ(TIM2_IRQn);
	__enable_irq();
}

extern void delay_ms(uint16_t milliseconds){
	timerSetAutoReloadValue(TIM2, milliseconds);
	timerStart(TIM2);
	while(!timFlag){}
	timFlag = false;
}

void TIM2_IRQHandler(void){
	timFlag = true;
	TIM2->SR = 0;
}

