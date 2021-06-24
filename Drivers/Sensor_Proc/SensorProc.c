#include "SensorProc.h"
#include "math.h"

uint16_t getAdcRaw(ADC_HandleTypeDef* hadc)
{
	return HAL_ADC_GetValue(hadc);
}

uint8_t checkValueAdc(uint16_t l_adc_raw)
{
	const uint16_t QUAN_LEVELS = 4096; 
		
	if ((l_adc_raw >= 0) && (l_adc_raw < QUAN_LEVELS))
	{
		return 1;
	}
	else
	{
		return 0;
	}
		
}


float getVoltageAdc(uint16_t l_adc_raw)
{
	const uint16_t QUAN_LEVELS = 4096;
	const float MAX_VOLTAGE = 3.3;
	
	return (MAX_VOLTAGE/(float)QUAN_LEVELS)*l_adc_raw;
}


float getRotationAngle(float l_voltage_adc)
{
	const float MAX_ANGLE = 90.0;
	const float MAX_VOLTAGE = 3.3;
	
	return (MAX_ANGLE/MAX_VOLTAGE)*l_voltage_adc;
}
