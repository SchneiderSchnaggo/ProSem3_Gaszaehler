/*
 * backupData.h
 *
 *  Created on: 26.03.2023
 *      Author: lukas
 */

#ifndef INC_BACKUPDATA_H_
#define INC_BACKUPDATA_H_

#include <stdint.h>
#include <stm32f1xx.h>
#include <shalf1.h>

extern void writeTicks(uint32_t counter, BKPReg startReg);
extern void getTicks(uint16_t* data, BKPReg startReg, uint8_t numOfBytes);
extern uint32_t getNumOfTicks(BKPReg startReg);

#endif /* INC_BACKUPDATA_H_ */
