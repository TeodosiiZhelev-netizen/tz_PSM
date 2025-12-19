/*
 * SeatPositionControl.c
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "Typedef.h"
#include "SeatPositionControl.h"
#include "SeatPositionControl_cfg.h"
#include "SeatPositionControl_integration.h"


/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Definitions of local variables (static ...)                                                                       */
/*********************************************************************************************************************/
typedef enum{
	axisState_idle = 0,
	axisState_fw,
	axisState_bw,
	axisState_cnt
}PosCtrl_TEState;

typedef struct{
	PosCtrl_TEState state;
	uint8 			error;
	uint16 			position;
	uint16			targetPostion;
}PosCtrl_TSAxis;

static PosCtrl_TSAxis axis[POSCTRL_AXIS_CNT];
static uint16 axisId;
static uint16 motDir[MotDirCnt];
SeatPosCtrl_TEAxis PosCtrlTAxis;
SeatPosCtrl_TEDir PosCtrl_TDir;
/*********************************************************************************************************************/
/* Declarations of prototypes for local functions                                                                    */
/*********************************************************************************************************************/

void SeatPosCtrl_Init(void){

}

void SeatPosCtrl_Task(void){
	uint8 i;
	for(i = 0; i < POSCTRL_AXIS_CNT; i++){
		if(axis[axisId].state == axisState_fw){
			axis[axisId].position = MotDirFw;
		}else if(axis[axisId].state == axisState_bw){
			axis[axisId].position = MotDirBw;
		}else{

		}

		/* call IOHWAB interface for actuating axis */

	}

	//MotDrv_Command(axisId, axis[axisId].state);
}

/*********************************************************************************************************************/
/* Definitions of global functions                                                                                   */
/*********************************************************************************************************************/
Std_Return_Type SeatPosCtrl_Move(SeatPosCtrl_TEAxis axisReq, SeatPosCtrl_TEDir dir){

	Std_Return_Type res = E_NOT_OK;

	uint16 axisId = axisReq;

	if((axisId < POSCTRL_AXIS_CNT)&&(dir < MotDirCnt)){
		if(axis[axisId].error == 0){
			res = E_OK;
			if(dir == motDir[MotDirCnt]){
				axis[axisId].state = axisState_fw;
			}else{
				axis[axisId].state = axisState_bw;
			}
		}else{
			//Error for that axis, request could not be accepted
			res = E_NOT_OK;
		}
	}else{
		//Invalid argument passed, request could not be accepted
		res = E_NOT_OK;
	}

	return res;
}

Std_Return_Type SeatPosCtrl_Position(SeatPosCtrl_TEAxis axisId, uint16 targetPosition){

	Std_Return_Type res = E_NOT_OK;

	if((axisId < Axis_cnt)&&(targetPosition > 0u)){
		if(axis[axisId].error == 0){
			res = E_OK;
			if(targetPosition > axis[axisId].position){
				axis[axisId].state = axisState_fw;
			}else{
				axis[axisId].state = axisState_bw;
			}
		}else{
			res = E_NOT_OK;
		}
	}else{
		res = E_NOT_OK;
	}
	return res;
}

void PosCtlr_StopAll(){


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
