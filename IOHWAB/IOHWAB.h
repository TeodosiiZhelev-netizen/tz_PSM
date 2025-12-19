/*
 * IOHWAB.h
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

#ifndef IOHWAB_H_
#define IOHWAB_H_

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "Typedef.h"

/*********************************************************************************************************************/
/* Type definitions                                                                           			 */
/*********************************************************************************************************************/
typedef uint16 (*pToIOHWABFunc) (void);

/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Declarations of prototypes for exported functions                                                            	 */
/*********************************************************************************************************************/
extern void IOHWAB_Init(void);
extern void IOHWAB_Task(void);
extern void IOHWAB_SetAO(void);
extern void IOHWAB_SetDO(void);
extern void IOHWAB_SetAI(void);
extern void IOHWAB_SetDI(void);
extern void IOHWAB_SetDI(void);

extern uint16 IOHWAB_GetSpPneuVerADCVolatage(void);
extern uint16 IOHWAB_GetSpPneuHorADCVolatage(void);
extern uint16 IOHWAB_GetSpHeatADCVolatage(void);
extern uint16 IOHWAB_GetSpSlideADCVolatage(void);
extern uint16 IOHWAB_GetSpHeightADCVolatage(void);
extern uint16 IOHWAB_GetSpBackRestADCVolatage(void);
extern uint16 IOHWAB_GetSpTiltADCVolatage(void);
extern uint16 IOHWAB_GetSpMemoryADCVolatage(void);
#endif /* IOHWAB_H_ */
