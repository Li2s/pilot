/**********************************************************************/
/*(C) Copyright 2021                                                  */
/* File: SensorProc.c                                                 */
/* Library for analog sensor processing                               */
/*--------------------------------------------------------------------*/
/* Change history                                                     */
/* Num   |   Date   |     Author     |    PR     |    Description     */
/*  0    |24.06.2021|  Lituev N.A.   |    NA     |  Initial commit    */
/*  1    |09.07.2021|  Lituev N.A.   |    NA     |  Comments added    */
/*  2    |15.07.2021|  Lituev N.A.   |    NA     | Architecture reorg */
/*--------------------------------------------------------------------*/


/*--------------------------------------------------------------------*/
/*Includes                                                            */
/*--------------------------------------------------------------------*/
#include "SensorProc.h"
#include "math.h"
/*--------------------------------------------------------------------*/


/*--------------------------------------------------------------------*/
/*Functions                                                           */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*Function: getAdcRaw                                                 */
/*Description: returns the raw ADC conversion result                  */
/*Requirements: BRUD_SDD_SW_REQ_1                                     */
/*Parameters:                                                         */
/*    hadc  (input) - pointer to the ADC hardware handler             */
/*Return value:                                                       */
/*     uint16_t - the raw result of the ADC conversion                */
/*--------------------------------------------------------------------*/
uint16_t getAdcRaw(ADC_HandleTypeDef* hadc)
{
	return HAL_ADC_GetValue(hadc);
}



/*--------------------------------------------------------------------*/
/*Function: checkValueAdc                                             */
/*Description: checks that the conversion result is correct           */
/*Requirements: BRUD_SDD_SW_REQ_6                                     */
/*Parameters:                                                         */
/*    l_adc_raw  (input) - result of the ADC conversion               */
/*Return value:                                                       */
/*     uint8_t - 1 if the value is correct, 0 if it is not correct    */
/*--------------------------------------------------------------------*/
uint8_t checkValueAdc(uint16_t l_adc_raw)
{
	const uint16_t QUAN_LEVELS = 4096;

	if (l_adc_raw < QUAN_LEVELS)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}



/*--------------------------------------------------------------------*/
/*Function: getVoltageAdc                                             */
/*Description: converts the ADC result into the voltage               */
/*Requirements: BRUD_SDD_SW_REQ_2,BRUD_SDD_SW_REQ_3,BRUD_SDD_SW_REQ_6 */
/*Parameters:                                                         */
/*    l_adc_raw  (input) - result of the ADC conversion               */
/*Return value:                                                       */
/*     float - voltage of the sensor                                  */
/*--------------------------------------------------------------------*/
float getVoltageAdc(uint16_t l_adc_raw)
{
	const uint16_t QUAN_LEVELS = 4096;
	const float MAX_VOLTAGE = 3.3;

	if (checkValueAdc(l_adc_raw) == 1)
	{
		return (MAX_VOLTAGE/(float)QUAN_LEVELS)*l_adc_raw;
	}
	else
	{
		return 0.0;
	}
}

/*--------------------------------------------------------------------*/
/*Function: checkVoltageAdc                                           */
/*Description: checks that the voltage calculation is correct         */
/*Requirements: BRUD_SDD_SW_REQ_8                                     */
/*Parameters:                                                         */
/*    l_voltage_adc  (input) - voltage from the sensor                */
/*Return value:                                                       */
/*     uint8_t - 1 if the value is correct, 0 if it is not correct    */
/*--------------------------------------------------------------------*/
uint8_t checkVoltageAdc(float l_voltage_adc)
{
	const float MAX_VOLTAGE = 3.3;
  const float MIN_VOLTAGE = 0.0;

	if ((l_voltage_adc >= MIN_VOLTAGE) && (l_voltage_adc <= MAX_VOLTAGE))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}


/*--------------------------------------------------------------------*/
/*Function: getRotationAngle                                          */
/*Description: converts the voltage into the angle value              */
/*Requirements: BRUD_SDD_SW_REQ_4,BRUD_SDD_SW_REQ_5,BRUD_SDD_SW_REQ_10*/
/*              BRUD_SDD_SW_REQ_8,BRUD_SDD_SW_REQ_6,BRUD_SDD_SW_REQ_9 */
/*Parameters:                                                         */
/*    l_voltage_adc  (input) - voltage from the sensor                */
/*Return value:                                                       */
/*     float - rotattion angle of the sensor                          */
/*--------------------------------------------------------------------*/
float getRotationAngle(float l_voltage_adc)
{
	const float MAX_ANGLE = 90.0;
	const float MIN_ANGLE = 0.0;
	const float MAX_VOLTAGE = 3.3;

	float l_rotation_angle = 0.0;

	if (checkVoltageAdc(l_voltage_adc) == 1)
	{
		l_rotation_angle = (MAX_ANGLE/MAX_VOLTAGE)*l_voltage_adc;
		if ((l_rotation_angle >= MIN_ANGLE) && (l_rotation_angle <= MAX_ANGLE))
		{
			return l_rotation_angle;
		}
		else
		{
			return 0.0;
		}
	}
	else
	{
		return 0.0
	}
}

/*--------------------------------------------------------------------*/
