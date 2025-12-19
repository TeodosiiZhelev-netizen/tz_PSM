/*
 * Seat_StateMngr.h
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

#ifndef SEAT_STATEMNGR_H_
#define SEAT_STATEMNGR_H_

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/
typedef enum{
	stm_idle = 0,
	stm_autoLocal,
	stm_autoRemote,
	stm_manual,
	stm_emrgyStop,
	stm_diag,
	stm_sleep,
	stm_cnt

}Stm_TStates;
/*********************************************************************************************************************/
/* Declarations of prototypes for exported functions                                                            	 */
/*********************************************************************************************************************/
extern void Stm_Init(void);
extern void Stm_Task(void);
extern void Stm_TStates_Stm_GetState(void);

#endif /* SEAT_STATEMNGR_H_ */
