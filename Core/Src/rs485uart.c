/*
 * rs485uart.c
 *
 *  Created on: 13.02.2023
 *      Author: lukas
 */

#include <shalf1.h>
#include <stdbool.h>
#include "rs485uart.h"

#define USART_TX_EMPTY(usart)  ((usart)->SR & USART_SR_TXE)
#define USART_WAIT_MB(usart)      do { while(!USART_TX_EMPTY(usart)); } while(0)

//USART in DMA Modus -> Modbus empfängt 5 Bytes
void initRS485UART(void){
	__disable_irq();
	gpioInitPort(GPIOA);
	afioInit();
	USARTEnable(USART1);
	gpioSetupPin(GPIOA, PIN9, OUT_50MHZ);
	gpioSetupMode(GPIOA, PIN9, AF_PP);
	gpioSetupPin(GPIOA, PIN10, INPUT);
	gpioSetupInput(GPIOA, PIN10, FLOATING);
	USARTIRQ(USART1, USART_IRQ_RXNEIE, true);
	//usartSetDmaRxMode(USART1, DMA_RECEIVE_ON);
	//gpioSetupOutput(GPIOA, PIN3, AF_PP);
	USARTSetBaudrate(USART1, 9600);
	USARTTXOn(USART1, TRANSMITTER_ON);
	USARTRXOn(USART1, RECEIVER_ON);
	NVIC_EnableIRQ(USART1_IRQn);
	__enable_irq();
}

void initUSARTDMA(uint32_t* memAdr){
	uint8_t foo;
	foo = dmaInit(DMA1, DMA1_Channel5, USART1->DR, memAdr, 6, FROM_PER, DMA_CIRC_OFF, 1, 0, MSIZE_8BIT, PSIZE_8BIT, PRIO_HIGH, DMA_TCI);
}

/*
  * Desc.: send a String over the USART
  * @param: (USART_TypeDef*)usart: USART
  * @param: (char*) str: String to be sent
  * @return: none
  */
void USARTSendStringMB(USART_TypeDef* usart, char* str, int len){
	while(len != 0){
		USART_WAIT_MB(usart);
		usart->DR = *str++ & 0x01FF;
		USART_WAIT_MB(usart);
		len--;
	}
}
