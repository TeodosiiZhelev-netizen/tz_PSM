/*
 * Seat_StateMngr.c
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */
/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "Typedef.h"
#include "Seat_StateMngr.h"
#include "Seat_StateMngr_cfg.h"
#include "Seat_StateMngr_int.h"

/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/
typedef void(*Stm_FstmHandlerFunc)(void);

typedef struct{
	Stm_FstmHandlerFunc onEnterFunc; /*One time executed function, before entering new state*/ /*unknown type name 'Stm_FStmHandlerFunc'*/
	Stm_FstmHandlerFunc doFunc;		 /*Cyclic executed function*/ /*unknown type name 'Stm_FStmHandlerFunc'*/
	Stm_FstmHandlerFunc onExitFunc;	 /*One time executed function, before entering new state*/
}Stm_TSStmStateHandlerFuncs;

/*********************************************************************************************************************/
/* Definitions of local variables (static ...)                                                                       */
/*********************************************************************************************************************/
static Stm_TStates stm_state;

/*********************************************************************************************************************/
/* Declarations of prototypes for local functions                                                                    */
/*********************************************************************************************************************/
static void Stm_Do_Idle(void);
static void Stm_Enter_AutoLocal(void);
static void Stm_Do_AutoLocal(void);
static void Stm_Exit_AutoLocal(void);
static void Stm_Enter_AutoRemote(void);
static void Stm_Do_AutoRemote(void);
static void Stm_Enter_AutoRemote(void);
static void Stm_Exit_AutoRemote(void);
static void Stm_Enter_Manual(void);
static void Stm_Do_Manual(void);
static void Stm_Exit_Manual(void);
static void Stm_Enter_EmrgyStop(void);
static void Stm_Do_EmrgyStop(void);
static void Stm_Exit_EmrgyStop(void);
static void Stm_Enter_Diag(void);
static void Stm_Do_Diag(void);
static void Stm_Exit_Diag(void);

/*********************************************************************************************************************/
/* Definitions of global functions                                                                                   */
/*********************************************************************************************************************/

uint16 Tout = 0;

/*********************************************************************************************************************/
/* @brief  		Initializes the component's internal variables and work data.         								 */
/*********************************************************************************************************************/
/* @param[in]    none																								 */
/* @return       none																								 */
/*********************************************************************************************************************/

void Stm_Init(void){
	stm_state = stm_idle;
}

/*********************************************************************************************************************/
/* @brief  		Drivers the state machine engine. Cyclic activities and enter, exit as well.						 */
/*********************************************************************************************************************/
/* @param[in]    none																								 */
/* @return       none																								 */
/*********************************************************************************************************************/

void Stm_Task(void){
	static const Stm_TSStmStateHandlerFuncs stm_stm[stm_cnt] ={\
			/*							onEnterFunc				doFunc						onExitFunc		  */
			/*stm_idle		*/		{		NULL, 				Stm_Do_Idle, 				 NULL				    },\
			/*stm_autoLocal */		{	Stm_Enter_AutoLocal, 	Stm_Do_AutoLocal, 			 Stm_Exit_AutoLocal		},\
			/*stm_autoRemote*/		{ 	Stm_Enter_AutoRemote, 	Stm_Do_AutoRemote, 		     Stm_Exit_AutoRemote	},\
			/*stm_manual	*/		{ 	Stm_Enter_Manual, 		Stm_Do_Manual, 				 Stm_Exit_Manual		},\
			/*stm_emrgyStop */		{	Stm_Enter_EmrgyStop, 	Stm_Do_EmrgyStop,			 Stm_Exit_EmrgyStop		},\
			/*stm_diag		*/		{	Stm_Enter_Diag, 		Stm_Do_Diag, 				 Stm_Exit_Diag			},\
			/*stm_sleep		*/		{	NULL, 					NULL, 						 NULL					}};/*expected '}' before ';' token*/
	static uint8 stmOldState = stm_idle;


	/* State change? */
	if(stm_state != stmOldState){
		if (stm_stm[stmOldState].onExitFunc!= NULL) {
					stm_stm[stmOldState].onExitFunc();
		}
				/* new state enter... */
		if (stm_stm[stm_state].onEnterFunc!= NULL) {
			stm_stm[stm_state].onEnterFunc();
		}
		/* update the old state */
		stmOldState= stm_state;
	}

	if(stm_stm[stm_state].doFunc != NULL){
		stm_stm[stm_state].doFunc();
	}
}

/*********************************************************************************************************************/
/* Definitions of local functions																					 */
/*********************************************************************************************************************/

static void Stm_Do_Idle(void){

	uint16 result;
	//CommMngr_TCommReq remoteReq;

	KbdDrv_GetManReq(&result);
	if(result != 0){
		//there is a request for manual movement
		stm_state = stm_manual;
	}else{
		KbdDrv_GetAutReq(&result);
		if(result != 0){
			stm_state = stm_autoLocal;
		}else{/*
			ComMng_GetRequest(&remoteReq);
			if(remoteReq == CommReq_MemorySet){
				stm_state = stm_autoRemote;
			}*/
		}
	}
}

static void Stm_Enter_AutoLocal(void){
	PosCtlr_StopAll();
	Tout = CFG_AUTOLOCAL_TOUT;
}

static void Stm_Do_AutoLocal(void){
	uint8 result;
	uint16 manReq;

	result = KbdDrv_GetManReq(&manReq);
	if(result !=0){
		stm_state = stm_emrgyStop;
	}else{
		Tout--;
	}
}

static void Stm_Exit_AutoLocal(void){
	PosCtlr_StopAll();
	stm_state = stm_idle;
}

static void Stm_Enter_AutoRemote(void){
	PosCtlr_StopAll();
	Tout = CFG_AUTOREMOTE_TOUT;
}

static void Stm_Do_AutoRemote(void){
	uint8 result;
	uint16 manReq;
	result = KbdDrv_GetManReq(&manReq);
	if(result != 0){
		stm_state = stm_emrgyStop;
	}else{
		Tout--;
	}
}
static void Stm_Exit_AutoRemote(void){
	PosCtlr_StopAll();
	if(Tout == 0){
		stm_state = stm_idle;
		Tout = 0;
	}

}
static void Stm_Enter_Manual(void){
	PosCtlr_StopAll();
	Tout = CFG_MANMODE_TOUT;
}
static void Stm_Do_Manual(void){

	uint8 result;
	uint16 manReq;

	result = KbdDrv_GetManReq(&manReq);
	if(result != 0){
		stm_state = stm_manual;
		ManAdj_Do();
	}else{
		Tout--;
	}
}
static void Stm_Exit_Manual(void){
	PosCtlr_StopAll();
	stm_state = stm_idle;
}
static void Stm_Enter_EmrgyStop(void){
	PosCtlr_StopAll();
	Tout = CFG_EMRG_TOUT;
}
static void Stm_Do_EmrgyStop(void){
	if(CFG_EMRG_TOUT == 0){
		stm_state = stm_idle;
	}else{
		Tout--;
	}
}
static void Stm_Exit_EmrgyStop(void){

}
static void Stm_Enter_Diag(void){

}
static void Stm_Do_Diag(void){

}
static void Stm_Exit_Diag(void){

}
