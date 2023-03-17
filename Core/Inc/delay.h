/*
 * delay.h
 *
 *  Created on: 16.03.2023
 *      Author: lukas
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#include <stdint.h>

#define TIM_PSC (48000)

extern void initTimer(void);
extern void delay(uint16_t milliseconds);

#endif /* INC_DELAY_H_ */
