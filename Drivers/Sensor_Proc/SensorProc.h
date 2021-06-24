#ifndef _SENSORPROC_
#define _SENSORPROC_

#include "stm32l4xx_hal.h"

uint16_t getAdcRaw(ADC_HandleTypeDef* hadc);
uint8_t checkValueAdc(uint16_t l_adc_raw);
float getVoltageAdc(uint16_t l_adc_raw);
float getRotationAngle(float l_voltage_adc);

#endif /*_SENSORPROC_*/
