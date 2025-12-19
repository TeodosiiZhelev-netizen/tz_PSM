/*
 * ManualAdjustment.c
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "Typedef.h"
#include "ManualAdjustment.h"
#include "ManualAdjustment_cfg.h"
#include "ManualAdjustment_integration.h"
/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Definitions of local variables (static ...)                                                                       */
/*********************************************************************************************************************/
typedef struct{
	uint8 axisId;/*backrest or height*/
	uint8 req;/*Fw or Bw*/
}ManAdj_TRequest;

static const ManAdj_TRequest req[KbdDrv_swCnt]= {
	/*							axisId,			req			*/
	/* fw sw 			*/ 	{	AXIS_SLIDE,		MotDirFw	},
	/* bw sw			*/	{	AXIS_SLIDE,		MotDirBw		},
	/* recl fw sw		*/	{	AXIS_RECL,		MotDirFw		},
	/* recl bw sw		*/ 	{	AXIS_RECL,		MotDirBw		},
	/* height fw sw		*/ 	{	AXIS_HGHT,		MotDirFw		},
	/* height bw sw		*/	{	AXIS_HGHT, 		MotDirBw		},
	/* tilt fw sw		*/	{	AXIS_TILT,		MotDirFw		},
	/* tilt bw sw		*/	{	AXIS_TILT,		MotDirBw		},
	/* Pneumatic ver sw	*/	{	AXIS_PNEUM,		MotDirFw		},
	/* Pneumatic ver sw	*/	{	AXIS_PNEUM,		MotDirBw		}
};
/*********************************************************************************************************************/
/* Declarations of prototypes for local functions                                                                    */
/*********************************************************************************************************************/
void ManAdj_Init();

/*********************************************************************************************************************/
/* Definitions of global functions                                                                                   */
/*********************************************************************************************************************/

void ManAdj_Start(){

}

void ManAdj_Do(){

	uint16 buttonRequest;
	static uint8 previousReq;

	KbdDrv_GetManReq(&buttonRequest);

	for (uint8 i= 0; i< KbdDrv_swCnt; i++){
			if (buttonRequest& (1<< i)) {
				SeatPosCtrl_Move(/*axis*/req[i].axisId, /*dir*/req[i].req);
			} else if(previousReq != 0 && buttonRequest == 0){
				PosCtlr_StopAll();
			} else{
				/* Do nothing*/
			}
		}
	previousReq = buttonRequest;

}

void ManAdj_Stop(){

}

/*********************************************************************************************************************/
/* @brief  		Initializes the component's internal variables and work data.         								 */
/*********************************************************************************************************************/
/* @param[in]    none																								 */
/* @return       none																								 */
/*********************************************************************************************************************/
void ManAdj_Init(){

}


/*********************************************************************************************************************/
/* Definitions of local functions																					 */
/*********************************************************************************************************************/
