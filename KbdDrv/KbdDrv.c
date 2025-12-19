/*
 * KbdDrv.c
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "Typedef.h"
#include "KbdDrv.h"
#include "KbdDrv_cfg.h"
#include "KbdDrv_integration.h"

/*********************************************************************************************************************/
/* Definitions of local variables (static ...)                                                                       */
/*********************************************************************************************************************/

typedef enum{
	Line_Memory = 0,
	Line_Tilt_UpDwn,
	Line_Height_UpDwn,
	Line_BackRest_FwBw,
	Line_Lenght_FwBw,
	Line_Heat,
	Line_Pneumatic_Ver,
	Line_Pneumatic_Hor,
	Line_cnt
}TSwitchPackLines; /*Enum for every AI. Input voltage will be stored for every switch pack line*/

typedef struct{
	uint8 lineId;
	uint16 pressThrsLow;
	uint16 pressThrsHigh;
}TSwithcCfg; /*Configuration for the lower and higher voltage thresholds*/

static TSwithcCfg swithcCfg[KbdDrv_swCnt]= KBDDRV_SWITCHES_CFG;
uint16 switchesState;
static uint16 switchesStateP;

/*********************************************************************************************************************/
/* Declarations of prototypes for local functions                                                                    */
/*********************************************************************************************************************/
static boolean IsVoltageInRange(uint16 voltage, uint16 thrsLow, uint16 thrsHigh); /*Function will check if a button has been pressed.*/

/*********************************************************************************************************************/
/* Definitions of global functions                                                                                   */
/*********************************************************************************************************************/

Std_Return_Type KbdDrv_GetAutReq(uint16 *switchesStateP){
	Std_Return_Type retL = E_NOT_OK;
/*copies the button state to a pointer. AutoMovementLocal will read out the bit mask*/
	if(NULL != switchesStateP){
		*switchesStateP = (switchesState & KBDDRV_AUTO_REQ_SW_MASK);
		retL = E_OK;
	}else{
		/*do nothing*/
	}
	return retL;
}

Std_Return_Type KbdDrv_GetManReq(uint16 *switchesStateP){
	Std_Return_Type retL = E_NOT_OK;
	/*copies the button state to a pointer. ManAdj will read out the bit mask*/
	if(NULL != switchesStateP){
			*switchesStateP =(switchesState & KBDDRV_MANUAL_REQ_SW_MASK);
			retL = E_OK;
	}else{
			/*do nothing*/
	}

	return retL;
}

/*********************************************************************************************************************/
/* Definitions of local functions																					 */
/*********************************************************************************************************************/

void KbdDrv_Init(){
	switchesState = 0;
}
 static uint16 lineVoltage[Line_cnt];
void KbdDrv_Task(void){
	uint8 i;
	//uint16 lineVoltage[Line_cnt];
	//uint16 btnSts[KbdDrv_swCnt];
	pToIOHWABFunc arrayOfHWABfuncs[Line_cnt] = KBDRV_INT_GET_LINE_VOLTAGE;

	for(i = 0; i < Line_cnt; i++){
		lineVoltage[i] = arrayOfHWABfuncs[i]();
	}

	for(i = 0; i < KbdDrv_swCnt; i++){
		if (TRUE == IsVoltageInRange(lineVoltage[swithcCfg[i].lineId], swithcCfg[i].pressThrsLow, swithcCfg[i].pressThrsHigh)){
			/*button is pressed*/
			switchesState|= (1u<< i);
		}else{
			//button is released
			switchesState&= ~(1u<< i);
		}
	}
}
/*Checks voltage thresholds for the selected swithcpack line*/
static boolean IsVoltageInRange(uint16 voltage, uint16 thrsLow, uint16 thrsHigh){
	boolean res = FALSE;

	if((voltage >= thrsLow) && (voltage <= thrsHigh)){
		res = TRUE;
	}
	return res;
}
