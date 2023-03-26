#include "program.h"
#include "usbd_cdc_if.h"
#include <stdint.h>
#include <stm32f1xx.h>
#include <system_stm32f1xx.h>
#include <stdbool.h>
#include <shalf1.h>
#include <shalf1GPIO.h>
#include <shalf1SysTick.h>
#include <shalf1RCC.h>
#include <shalf1Backup.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

//projectspecific includes:
#include "gpio.h"
#include "delay.h"
#include "rs485uart.h"
#include "modbusRTU.h"
#include "backupData.h"

#define USART_MSG_LEN  9

static char usartBuff[USART_MSG_LEN];
static uint32_t cnt = 0; //G4 Gaszaehler kann 99999 m³ anzeigen, d.h. bei maximaler Volumenmessung kommt es zu 9.9999x10⁶ Zählimpulsen -> 32bit Integer
static bool usartRXFlag = false;
char foo;
uint16_t tickBuff[] = {0, 0};

static uint32_t tickCNT = 0;

void start(void){
	tickCNT = getNumOfTicks(BKP1);
	initRS485UART();
	initTimer();
	initPins();
	while(1){
		if(usartRXFlag){
			USART1->CR1 &= ~USART_CR1_RXNEIE_Msk;
			gpioSetPin(GPIOB, PIN12);
			getTicks(tickBuff, BKP1, sizeof(tickBuff)/sizeof(uint16_t));
			registerWrite(0, tickBuff[1]); //Puffer drehen
			registerWrite(1, tickBuff[0]);
			modbusResponse(usartBuff, sizeof(usartBuff)-1);
			USART1->CR1 |= USART_CR1_RXNEIE;
			gpioResetPin(GPIOB, PIN12);
			delay_ms(100);
			usartRXFlag = false;
		}

	}
}


/*-----------------------------------------------------------------------------
+++++++++++++++++++++++++++++++ISR+++++++++++++++++++++++++++++++++++++++++++++
-----------------------------------------------------------------------------*/
void USART1_IRQHandler(void){
	if(!usartRXFlag){
		while(!(USART1->SR & USART_SR_RXNE)){}
		usartBuff[cnt]= USART1->DR & 0x01FF;
		cnt++;
		if((cnt == USART_MSG_LEN-1)){
			//USART1->CR1 &= ~USART_CR1_RXNEIE_Msk;
			USART1->DR = 0;
			usartRXFlag = true;
			cnt=0;
		}
	}
	else{
		while(!(USART1->SR & USART_SR_RXNE)){}
		foo= USART1->DR & 0x01FF;
		USART1->DR = 0;
	}
}

void EXTI9_5_IRQHandler(void){
	tickCNT++;
	writeTicks(tickCNT, BKP1);
	gpioTogglePin(GPIOC, PIN4); //optional for debugging
	EXTI->PR |= EXTI_PR_PR9;
}

//TODO
//-functions for USB
//-functions for backup registers
