/*
 * shalf1ADC.c
 *
 *      Author: lukas
 */

#include <shalf1ADC.h>
#include <shalf1.h>

bool dmaModeFlag = false;
uint16_t numberOfChannels = 0;
uint32_t adrMemBuff = 0;
uint32_t adrPerBuff = 0;

extern void initADC(ADC_TypeDef* adc){
	if(adc == ADC1){
		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	}
	else if(adc == ADC2){
		RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
	}
	else{

	}
	adcCalibrate(adc);
}

extern ADC_ERR_CODES adcSetupSequence(ADC_TypeDef* adc, ADC_CHN channel, uint8_t numberInSequence){
	adc->SQR3 = 0;
	adc->SQR2 = 0;
	adc->SQR1 = 0;
	if(numberInSequence <= 6 && numberInSequence >= 1){
		adc->SQR3 |= channel << (numberInSequence-1)*5;
		return OK;
	}
	else if (numberInSequence <= 12 && numberInSequence >= 7){
		adc->SQR2 |= channel << ((numberInSequence-6)-1)*5;
		return OK;
	}
	else if(numberInSequence <= 16 && numberInSequence >= 13){
		adc->SQR1 |= channel << ((numberInSequence-12)-1)*5;
		return OK;
	}
	else{
		return channelNotInRange_Err;
	}
}

extern ADC_ERR_CODES adcSetSequenceLength(ADC_TypeDef* adc, uint8_t numberOfConversions){
	adc->SQR1 &= ~ADC_SQR1_L_Msk;
	if(numberOfConversions >= 0 && numberOfConversions <= 16){
		adc->SQR1 |= numberOfConversions << ADC_SQR1_L_Pos;
		return OK;
	}
	else{
		return numberOfConversionsNotInRange_Err;
	}
}

extern void adcSetTrigger(ADC_TypeDef* adc, TRIG_SRC source){
	 adc->CR2 |= source << ADC_CR2_EXTSEL_Pos;
	 ADC1->CR2 |= ADC_CR2_ADON;
}

extern uint16_t adcRead(ADC_TypeDef* adc, ADC_CHN channel){
	if (channel >= -1 && channel <= 17){
		if(!dmaModeFlag){
			if (channel > -1){
				adcSetupSequence(adc, channel, 1);
				adcSetSequenceLength(adc, 0);
			}
			else{
				return channelNotInRange_Err;
			}
		}

		adc->CR2 |= ADC_CR2_ADON;
		adc->SR = 0;
		adc->CR2 |= ADC_CR2_SWSTART;

		while(!(adc->SR & ADC_SR_EOC)){}
		if (!dmaModeFlag){
			if (channel > -1){
				return adc->DR;
			}
			else{
				return channelNotInRange_Err;
			}
		}
		else{
			dmaStop(DMA1_Channel1);
			return 0;
		}
	}
	else{
		return channelNotInRange_Err;
	}
}

extern ADC_ERR_CODES adcInitDMA(ADC_TypeDef* adc, uint32_t adrPer, uint32_t adrMem, uint16_t dataLen){
	adc->CR2 |= ADC_CR2_DMA;
	if (adc==ADC1){
		dmaInit(DMA1, DMA1_Channel1, adrPer, adrMem, dataLen+1, FROM_PER, DMA_CIRC_OFF, 1, 0, MSIZE_16BIT, MSIZE_16BIT, PRIO_HIGH , DMA_TCI );
		dmaStart(DMA1_Channel1);
		dmaModeFlag = true;
		numberOfChannels = dataLen+1;
		adrMemBuff = adrMem;
		adrPerBuff = adrPer;
		return OK;
	}
#if defined(HIGH_DENS) || defined(XL_DENS)
	else if(adc == ADC3){
		dmaInit(DMA2, DMA1_Channel5, adrPer, adrMem, dataLen, FROM_PER, DMA_CIRC_OFF, true, false, MSIZE_32BIT, MSIZE_32BIT, PRIO_VHIGH , DMA_TCI );
		dmaStart(DMA2_Channel5);
		dmaModeFlag = true;
		return OK;
	}
#endif
	else{
		return noDMAavailableForADC_Err;
	}
}

extern void adcDMAReload(){
	if(dmaModeFlag){
		dmaInit(DMA1, DMA1_Channel1, adrPerBuff, adrMemBuff, numberOfChannels, FROM_PER, DMA_CIRC_OFF, 1, 0, MSIZE_16BIT, MSIZE_16BIT, PRIO_HIGH , DMA_TCI );
		dmaStart(DMA1_Channel1);
	}
}

extern void adcCalibrate(ADC_TypeDef* adc){
	adc->CR2 |= ADC_CR2_CAL;
	while(!(adc->CR2 & ADC_CR2_CAL)){}
}

extern ADC_ERR_CODES adcDataAlignment(ADC_TypeDef* adc, DATA_ALIGNMENT alignment){
	if (alignment == DATA_RIGHT || alignment == DATA_LEFT){
		adc->CR2 |= alignment << ADC_CR2_ALIGN_Pos;
		return OK;
	}
	else{
		return invalidAlignment;
	}
}

extern ADC_ERR_CODES adcSetCyclesOfConversion(ADC_TypeDef* adc, ADC_CYCLES numberOfCycles, ADC_CHN channel){
	if ((channel >= 0) && (channel <= 9)){
		adc->SMPR2 |= numberOfCycles << (channel*3);
		return OK;
	}
	else if((channel >= 10) && (channel <= 17)){
		adc->SMPR1 |= numberOfCycles << ((channel-10)*3);
		return OK;
	}
	else{
		return channelNotInRange_Err;
	}
}
