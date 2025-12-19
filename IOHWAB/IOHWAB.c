/*
 * IOHWAB.c
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "Typedef.h"
//#include "IOHWAB.h"
#include "IOHWAB_cfg.h"
#include "stm32f103xe.h"
#include "main.h"
/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/
#define SPMEMORYADC		0u
#define SPTILTADC		1u
#define SPHEIGHTADC		2u
#define SPBACKRESTADC	3u
#define SPSLIDEADC		4u
#define SPHEATADC 		5u
#define SPPNEUMHORADC 	6u
#define SPPNEUVERADC 	7u

volatile uint16 ADC_Val[ADC_CHANELS];
extern ADC_HandleTypeDef hadc1;
/*********************************************************************************************************************/
/* Definitions of local variables (static ...)                                                                       */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Declarations of prototypes for local functions                                                                    */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Definitions of global functions                                                                                   */
/*********************************************************************************************************************/
void IOHWAB_Task(void){}

void IOHWAB_Init(void){

	HAL_GPIO_WritePin(GPIOC, do_spPwr_Pin, GPIO_PIN_SET);
	HAL_ADC_Start_DMA(&hadc1, (uint32 *)ADC_Val, ADC_CHANELS);
}

void IOHWAB_SetAO(){

}

void IOHWAB_SetDO(){

}
void IOHWAB_SetAI(){

}

void IOHWAB_SetDI(){

}


uint16 IOHWAB_GetSpHeatADCVolatage(void){

	return  ADC_Val[SPHEATADC];
}

uint16 IOHWAB_GetSpPneuHorADCVolatage(void){

	return  ADC_Val[SPPNEUMHORADC];
}

uint16 IOHWAB_GetSpPneuVerADCVolatage(void){

	return  ADC_Val[SPPNEUVERADC];
}

uint16 IOHWAB_GetSpMemoryADCVolatage(void){

	return  ADC_Val[SPMEMORYADC];
}

uint16 IOHWAB_GetSpTiltADCVolatage(){

	return  ADC_Val[SPTILTADC];
}

uint16 IOHWAB_GetSpBackRestADCVolatage(){

	return  ADC_Val[SPBACKRESTADC];
}

uint16 IOHWAB_GetSpHeightADCVolatage(){

	return  ADC_Val[SPHEIGHTADC];
}

uint16 IOHWAB_GetSpSlideADCVolatage(){

	return  ADC_Val[SPSLIDEADC];
}
/*********************************************************************************************************************/
/* @brief  		Initializes the component's internal variables and work data.         								 */
/*********************************************************************************************************************/
/* @param[in]    none																								 */
/* @return       none																								 */
/*********************************************************************************************************************/



/*********************************************************************************************************************/
/* Definitions of local functions																					 */
/*********************************************************************************************************************/
