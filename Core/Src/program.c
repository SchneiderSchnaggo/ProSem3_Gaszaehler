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
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

//projectspecific includes:
#include "gpio.h"
#include "delay.h"
#include "rs485uart.h"
#include "modbusRTU.h"

#define USART_MSG_LEN  7

static char usartBuff[USART_MSG_LEN];
static char rcv;
static int cnt = 0;
static bool usartRXFlag = false;
char foo;

static uint32_t tickCNT = 0;
char ausg[20] = "ausgabe\n";

void start(void){
	initRS485UART();
	initTimer();
	initPins();
	while(1){
		if(usartRXFlag){
			//modbusrequest()hier implementieren!
			USART1->CR1 &= ~USART_CR1_RXNEIE_Msk;
			//sprintf(ausg, "tick: %" PRIu32 "\n", tickCNT);
			gpioSetPin(GPIOB, PIN12);
			//USARTSendString(USART1, ausg);
			setCounter(tickCNT);
			modbusResponse(usartBuff, sizeof(usartBuff)-1);
			USART1->CR1 |= USART_CR1_RXNEIE;
			gpioResetPin(GPIOB, PIN12);
			delay_ms(100);
			usartRXFlag = false;
			//USART1->CR1 |= USART_CR1_RXNEIE;
			//}
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
	EXTI->PR |= EXTI_PR_PR9;
}
