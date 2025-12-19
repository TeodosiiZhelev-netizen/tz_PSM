/*
 * KbdDrv_integration.h
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

#ifndef KBDDRV_INTEGRATION_H_
#define KBDDRV_INTEGRATION_H_
/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "IOHWAB.h"
/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/
#define KBDRV_INT_GET_LINE_VOLTAGE {IOHWAB_GetSpMemoryADCVolatage, 		\
									IOHWAB_GetSpTiltADCVolatage, 		\
									IOHWAB_GetSpHeightADCVolatage,		\
									IOHWAB_GetSpBackRestADCVolatage, 	\
									IOHWAB_GetSpSlideADCVolatage,   	\
									IOHWAB_GetSpHeatADCVolatage,     	\
									IOHWAB_GetSpPneuHorADCVolatage,  	\
									IOHWAB_GetSpPneuVerADCVolatage		\
}
/*********************************************************************************************************************/
/* Declarations of prototypes for exported functions                                                            	 */
/*********************************************************************************************************************/

#endif /* KBDDRV_INTEGRATION_H_ */
