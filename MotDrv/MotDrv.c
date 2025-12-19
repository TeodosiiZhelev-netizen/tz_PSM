/*
 * MotDrv.c
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "Typedef.h"
#include "MotDrv.h"
#include "MotDrv_cfg.h"
#include "MotDrv_integration.h"
#include "GateDrvCdd.h"
/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/
typedef struct{
	uint8 state;/*actual state*/
	uint8 command;/*Fw or Bw or Brake*/
}MotDrv_TMotorData;

typedef struct{
	GateDrvCdd_THB_Id Half_Bridge_Comm;
	GateDrvCdd_THB_State state_Id1;

	GateDrvCdd_THB_Id indivdual;
	GateDrvCdd_THB_State state_Id2;

}MotDrv_THB_Data;

const MotDrv_THB_Data HalfBridge[MOTORCNT][TMotCommand] =
{
																						/* Motor Command */
	/* MOT ID */				/*  IDLE */																	/*FORWARD  */												/*BACKWARD */ 														/* BREAK */
	/* MOT 1 */ { {HB_Id_MG2_Height, HB_State_HZ, HB_Id_MG2_Comm, HB_State_HZ}, 	{HB_Id_MG2_Height, HB_State_LS_On, HB_Id_MG2_Comm, HB_State_HZ}, 	{HB_Id_MG2_Height, HB_State_HZ, HB_Id_MG2_Comm, HB_State_HS_On}, 	{HB_Id_MG2_Height, HB_State_LS_On, HB_Id_MG2_Comm, HB_State_HS_On}},
	/* MOT 2 */ { {HB_Id_MG2_Backrest, HB_State_HZ, HB_Id_MG2_Comm, HB_State_HZ}, 	{HB_Id_MG2_Backrest, HB_State_LS_On, HB_Id_MG2_Comm, HB_State_HZ}, 	{HB_Id_MG2_Backrest, HB_State_HZ, HB_Id_MG2_Comm, HB_State_HS_On},	{HB_Id_MG2_Backrest, HB_State_LS_On, HB_Id_MG2_Comm, HB_State_HS_On}},
	/* MOT 3 */ { {HB_Id_MG1_Lenght, HB_State_HZ, HB_Id_MG1_Common, HB_State_HZ}, 	{HB_Id_MG1_Lenght, HB_State_LS_On, HB_Id_MG1_Common, HB_State_HZ},	{HB_Id_MG1_Lenght, HB_State_HZ, HB_Id_MG1_Common, HB_State_HS_On},	{HB_Id_MG1_Lenght, HB_State_LS_On, HB_Id_MG1_Common, HB_State_HS_On}},
	/* MOT 4 */ { {HB_Id_MG1_Tilt, HB_State_HZ, HB_Id_MG1_Common, HB_State_HZ}, 	{HB_Id_MG1_Tilt, HB_State_LS_On, HB_Id_MG1_Common, HB_State_HZ},	{HB_Id_MG1_Tilt, HB_State_HZ, HB_Id_MG1_Common, HB_State_HS_On},	{HB_Id_MG1_Tilt, HB_State_LS_On, HB_Id_MG1_Common, HB_State_HS_On}},

};

/*********************************************************************************************************************/
/* Definitions of local variables (static ...)                                                                       */
/*********************************************************************************************************************/

MotDrv_TMotorData motor[MOTORCNT];
/*********************************************************************************************************************/
/* Declarations of prototypes for local functions                                                                    */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Definitions of global functions                                                                                   */
/*********************************************************************************************************************/

void MotDrv_GetStat(void){

}

void MotDrv_Command(uint8 motorId, TMotCommand command){
	//validate arguments
	if((motorId < MOTORCNT) && (command != Mot_cnt)){

		motor[motorId].command = command;
	}
	else{


	}
}

void MotDrv_Init(void){
	uint8 index;
	for(index  = 0; index < MOTORCNT; index++)
	{
		//init command and state
		motor[index].state = Mot_Idle;
		motor[index].command = Mot_Idle;
	}
}

void MotDrv_Task(void){
	uint8 i;
	GateDrvCdd_THB_Data hb_info;
	for(i = 0; i < motor; i++){
		if((motor[i].command) != (motor[i].state)){//check if the current state is different from the command coming from position control
			hb_info = HalfBridge[i][motor[i].command];
			/* Set first HB */
			GateDrvCdd_Set(hb_info.Half_Bridge_Id1,hb_info.state_Id1 );
			/* Set second HB */
			GateDrvCdd_Set(hb_info.Half_Bridge_Id2,hb_info.state_Id2 );
		}
		else{

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
