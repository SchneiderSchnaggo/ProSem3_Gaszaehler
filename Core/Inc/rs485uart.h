/*
 * rs485uart.h
 *
 *  Created on: 13.02.2023
 *      Author: lukas
 */

#ifndef INC_RS485UART_H_
#define INC_RS485UART_H_

#include <stdbool.h>


extern void initRS485UART(void);
extern void initUSARTDMA(uint32_t* memAdr);

#endif /* INC_RS485UART_H_ */
