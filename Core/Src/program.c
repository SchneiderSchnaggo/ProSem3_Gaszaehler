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

void initPins();
void indicateMagnet();
void outputClock();
void delay(void);

bool usartRXFlag = false;
uint8_t usartBuff[6];
uint8_t byteNum = 0;

void start(void){
	initUSARTDMA((uint32_t*)usartBuff);
	initRS485UART();
	while(1){
		if(usartRXFlag){
			//modbusrequest()hier implementieren!
			usartRXFlag = false;
			modbusResponse(usartBuff, sizeof(usartBuff)/sizeof(uint8_t));
		}
	}
}

void USART1_IRQHandler(void){
	//do some Stuff here
	/*char received;
	if(USART1->SR & USART_SR_RXNEIE){
		received = USART1->DR & 0x01FF;
	}
	*usartBuff[byteNUm] = received;
	if(byteNum < 5){
		byteNum++;
	}
	else{
		bbyteNum = 0;
	}*/
	usartRXFlag = true;
}

//---------
void indicateMagnet(){
	initPins();
	systickInit(SYSTICK_1S);
	systickSetTicks(1);
	initRS485UART();
	gpioSetPin(GPIOC, PIN4);
	while(1){
		/*if(isSysTickExpired()){
			gpioTogglePin(GPIOC, PIN4);
			systickSetTicks(1);
		}*/
		if(!gpioGetPinVal(GPIOC, PIN9)){
			gpioSetPin(GPIOC, PIN4);
			gpioSetPin(GPIOB, PIN12);
			USARTSendString(USART1, "Tick \n");
			gpioResetPin(GPIOB, PIN12);
			delay();
		}
		else{
			gpioResetPin(GPIOC, PIN4);
		}
	}
}

void initPins(){
	gpioInitPort(GPIOC);
	gpioSetupPin(GPIOC, PIN4, OUT_2MHZ);
	gpioSetupMode(GPIOC, PIN4, GP_PP);
	gpioSetupPin(GPIOC, PIN9, INPUT);
	gpioSetupInput(GPIOC, PIN9, IN_PUPD);
	gpioSetPullupPulldown(GPIOC, PIN9, true);
	gpioInitPort(GPIOB);
	gpioSetupPin(GPIOB, PIN12, OUT_2MHZ);
	gpioSetupMode(GPIOB, PIN12, GP_PP);
	gpioResetPin(GPIOB, PIN12);
}

void outputClock(){
	gpioInitPort(GPIOA);
	afioInit();
	gpioSetupPin(GPIOA, PIN8, OUT_50MHZ);
	gpioSetupMode(GPIOA, PIN8, AF_PP);
	setClock(HSI, SYSCLK_32, APB_8MHZ, APB_8MHZ);
	RCC->CFGR |= RCC_CFGR_MCO_SYSCLK;
}

void delay(void){
	int i=0;
	for(i=0; i < 1600000; i++){}
}
