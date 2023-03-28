/*
 * gpio.c
 *
 *  Created on: 16.03.2023
 *      Author: lukas
 */
#include <gpio.h>
#include <shalf1.h>


/*
  * Desc.: GPIO-Pininitialisierung
  * @return: none
  */
void initPins(){
	gpioInitPort(GPIOC);
	gpioSetupPin(GPIOC, PIN4, OUT_2MHZ);
	gpioSetupMode(GPIOC, PIN4, GP_PP);
	gpioSetupPin(GPIOC, PIN9, INPUT);
	gpioSetupInput(GPIOC, PIN9, IN_PUPD);
	gpioSetPullupPulldown(GPIOC, PIN9, true);
	extiConfigureEXTI(PORT_C, PIN9);
	extiEnableIrq(EXTI_P9);
	extiSetTriggerEdge(false, EXTI_P9);
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	gpioInitPort(GPIOB);
	gpioSetupPin(GPIOB, PIN12, OUT_2MHZ);
	gpioSetupMode(GPIOB, PIN12, GP_PP);
	gpioResetPin(GPIOB, PIN12);
}

/*
  * Desc.: Taktsignal für Ausgänge
  * @return: none
  */
void outputClock(){
	gpioInitPort(GPIOA);
	afioInit();
	gpioSetupPin(GPIOA, PIN8, OUT_50MHZ);
	gpioSetupMode(GPIOA, PIN8, AF_PP);
	setClock(HSI, SYSCLK_32, APB_8MHZ, APB_8MHZ);
	RCC->CFGR |= RCC_CFGR_MCO_SYSCLK;
}
