/*
 * AutomovementLocal.c
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "Typedef.h"
#include "AutomovementLocal.h"
#include "AutomovementLocal_integration.h"
#include "AutomovementLocal_cfg.h"
/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Definitions of local variables (static ...)                                                                       */
/*********************************************************************************************************************/
typedef struct{
	uint8 axisId;/*backrest or height*/
	uint8 req;/*Fw or Bw*/
}AutoLocal_TRequest;

static const AutoLocal_TRequest req[AutoReq]= {
	/*					axisId,			req		*/
	/* fw sw */ 		{	AXIS_SLIDE,		MOVE_FW		},
	/* bw sw*/			{	AXIS_SLIDE,		MOVE_BW		},
	/* recl fw sw*/		{	AXIS_RECL,		MOVE_FW		},
	/* recl bw sw*/ 	{	AXIS_RECL,		MOVE_BW		},
	/* height fw sw*/ 	{	AXIS_HGHT,		MOVE_FW		},
	/* height bw sw*/	{	AXIS_HGHT, 		MOVE_BW		},
	/* tilt fw sw*/		{	AXIS_TILT,		MOVE_FW		},
	/* tilt bw sw*/		{	AXIS_TILT,		MOVE_BW		}
};
/*********************************************************************************************************************/
/* Declarations of prototypes for local functions                                                                    */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Definitions of global functions                                                                                   */
/*********************************************************************************************************************/

void AutoMoveLoc_Start(void){

}
void AutoMoveLoc_Stop(void){

}
void AutoMoveLoc_Do(void){
	uint16 memButtonRequest;
	static uint8 previousReq;
	uint8 i;

		KbdDrv_GetAutReq(&memButtonRequest);

		for (i = 0; i< KbdDrv_swCnt; i++){
				if (memButtonRequest& (1<< i)) {
					/*Load stored positions*/

					/*execute command*/
					SeatPosCtrl_Move(/*axis*/req[i].axisId, /*dir*/req[i].req);
				} else if(previousReq != 0 && memButtonRequest == 0){
					SeatPosCtlr_Stop();
				} else{
					/* Do nothing*/
				}
			}
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
