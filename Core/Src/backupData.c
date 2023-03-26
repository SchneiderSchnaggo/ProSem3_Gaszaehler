/*
 * backupData.c
 *
 *  Created on: 26.03.2023
 *      Author: lukas
 */

#include <backupData.h>

uint16_t counterH = 0;
uint16_t counterL = 0;
uint16_t data2BKP[2] = {0, 0};

extern void writeTicks(uint32_t counter, BKPReg startReg){
	counterH = (counter>>16) & 0xFFFF;
	counterL = counter & 0xFFFF;
	data2BKP[0] = counterH;
	data2BKP[1] = counterL;
	backupWriteArray(data2BKP, BKP1, sizeof(data2BKP)/sizeof(uint16_t));
}

extern void getTicks(uint16_t* data, BKPReg startReg, uint8_t numOfBytes){
	backupReadArray(data, startReg, numOfBytes);
}

extern uint32_t getNumOfTicks(BKPReg startReg){
	uint16_t buff[2] = {0, 0};
	getTicks(buff, startReg, 2);
	uint32_t retVal = 0;
	retVal = buff[0] << 16;
	retVal |= buff[1];
	return retVal;
}
