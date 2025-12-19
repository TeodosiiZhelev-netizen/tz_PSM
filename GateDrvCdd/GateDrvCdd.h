/*
 * GateDrvCdd.h
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

#ifndef GATEDRVCDD_H_
#define GATEDRVCDD_H_

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "GateDrvCdd_cfg.h"
/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/
typedef enum{

	HB_State_HZ=0,
	HB_State_LS_On,
	HB_State_HS_On,
	HB_State_Cnt

}GateDrvCdd_THB_State;

typedef enum{
	HB_Id_MG1_Common = 0,
	HB_Id_MG1_Lenght,
	HB_Id_MG1_Tilt,
	HB_Id_MG1_Res,
	HB_Id_MG2_Comm,
	HB_Id_MG2_Backrest,
	HB_Id_MG2_Height,
	HB_Id_MG2_Res,
	HB_Id_cnt
}GateDrvCdd_THB_Id;


/*********************************************************************************************************************/
/* Declarations of prototypes for exported functions                                                            	 */
/*********************************************************************************************************************/
extern void GateDrvCdd_Init(void);
extern void GateDrvCdd_Task(void);
extern void GateDrvCdd_Set(GateDrvCdd_THB_Id HB_Id, GateDrvCdd_THB_State state);
#endif /* GATEDRVCDD_H_ */
