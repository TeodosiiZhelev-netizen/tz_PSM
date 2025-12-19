/*
 * SeatPostionControl.h
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

#ifndef SEATPOSITIONCONTROL_H_
#define SEATPOSITIONCONTROL_H_
/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "Typedef.h"
/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/
typedef enum{
	AXIS_SLIDE = 0,
	AXIS_RECL,
	AXIS_HGHT,
	AXIS_TILT,
	AXIS_PNEUM,
	Axis_cnt
}SeatPosCtrl_TEAxis;

typedef enum{
	MotStop = 0,
	MotDirFw,
	MotDirBw,
	MotDirCnt
}SeatPosCtrl_TEDir;

/*********************************************************************************************************************/
/* Declarations of prototypes for exported functions                                                            	 */
/*********************************************************************************************************************/
//Std_ReturnType SeatPosCtrl_Move(uint8 axisId, uint8 dir);
//Std_ReturnType SeatPosCtrl_Postion(uint8 axis, uint8 target);
extern void SeatPosCtrl_Task(void);
extern void SeatPosCtrl_Init(void);
Std_Return_Type SeatPosCtrl_Move(SeatPosCtrl_TEAxis, SeatPosCtrl_TEDir);
Std_Return_Type SeatPosCtrl_Position(SeatPosCtrl_TEAxis , uint16);
extern void PosCtlr_StopAll(void);

#endif /* SEATPOSITIONCONTROL_H_ */
