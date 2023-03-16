#include "program.h"
#include "usbd_cdc_if.h"
#include <stdint.h>
#include <stm32f1xx.h>
#include <system_stm32f1xx.h>
//#include <system_stm32f1xx.c>
#include <stdbool.h>
#include <shalf1.h>
#include <shalf1GPIO.h>
#include <shalf1SysTick.h>
#include <shalf1RCC.h>
#include "rs485uart.h"
#include "modbusRTU.h"
#include <stdio.h>
#include "gpio.h"

#define USART_MSG_LEN  6


void indicateMagnet();
void delay(void);
void usartTest(void);
char rcv;

int cnt;

bool usartRXFlag = false;
char usartBuff[USART_MSG_LEN];
uint8_t byteNum = 0;

void start(void){
	initPins();
	indicateMagnet();

	//initUSARTDMA((uint32_t*)usartBuff);
	//initRS485UART();
	/*indicateMagnet();
	while(1){
		if(usartRXFlag){
			//modbusrequest()hier implementieren!
			usartRXFlag = false;
			modbusResponse(usartBuff, sizeof(usartBuff)/sizeof(uint8_t));
		}
	}*/
}

void USART1_IRQHandler(void){
	cnt = USART_MSG_LEN;
	rcv = USART1->DR & 0x01FF;
	int i = 0;
	while((rcv != '\n') && (cnt != 0)){
		while(!(USART1->SR & USART_SR_RXNE)){
		}

		usartBuff[i++] = rcv;
		cnt--;
	}
	usartBuff[USART_MSG_LEN] = '\0';
	//gpioSetPin(GPIOB, PIN12);
	//USARTSendString(USART1, usartBuff);
	//gpioResetPin(GPIOB, PIN12);
	USART1->CR1 &= ~USART_CR1_RXNEIE_Msk;
	usartRXFlag = true;
}

//---------
void indicateMagnet(){
	initPins();
	systickInit(SYSTICK_1S);
	systickSetTicks(1);
	initRS485UART();
	gpioSetPin(GPIOC, PIN4);
	int tickCNT = 0;
	char ausg[20];
	while(1){
		/*if(isSysTickExpired()){
			gpioTogglePin(GPIOC, PIN4);
			systickSetTicks(1);
		}*/
		USART1->CR1 |= USART_CR1_RXNEIE;
		if(!gpioGetPinVal(GPIOC, PIN9)){
			gpioSetPin(GPIOC, PIN4);
			gpioSetPin(GPIOB, PIN12);
			USARTSendString(USART1, "Tick\n");
			tickCNT++;
			gpioResetPin(GPIOB, PIN12);
		}
		else{
			gpioResetPin(GPIOC, PIN4);
		}
		if(usartRXFlag){
			usartRXFlag = false;
			if(usartBuff[0] == 69){
				gpioSetPin(GPIOB, PIN12);
				sprintf(ausg, "tick: %d", tickCNT);
				USARTSendString(USART1, ausg);
				gpioResetPin(GPIOB, PIN12);
				delay();

			}
		}
	}
}



void delay(void){
	int i=0;
	for(i=0; i < 1600000; i++){}
}


