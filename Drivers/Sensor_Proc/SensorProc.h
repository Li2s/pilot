/**********************************************************************/
/*(C) Copyright 2021                                                  */
/* File: SensorProc.c                                                 */
/* Library for analog sensor processing                               */
/*--------------------------------------------------------------------*/
/* Change history                                                     */
/* Num   |   Date   |     Author     |    PR     |    Description     */ 
/*  0    |24.06.2021|  Lituev N.A.   |    NA     |  Initial commit    */
/*  1    |15.07.2021|  Lituev N.A.   |    NA     |  Comments added    */
/*--------------------------------------------------------------------*/

#ifndef _SENSORPROC_
#define _SENSORPROC_


/*--------------------------------------------------------------------*/
/*Includes                                                            */
/*--------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
/*--------------------------------------------------------------------*/


/*--------------------------------------------------------------------*/
/*Functions                                                           */
/*--------------------------------------------------------------------*/
uint16_t getAdcRaw(ADC_HandleTypeDef* hadc);
uint8_t checkValueAdc(uint16_t l_adc_raw);
float getVoltageAdc(uint16_t l_adc_raw);
float getRotationAngle(float l_voltage_adc);
/*--------------------------------------------------------------------*/

#endif /*_SENSORPROC_*/
