/*
 * KbdDrv.h
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

#ifndef KBDDRV_H_
#define KBDDRV_H_
/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "Typedef.h"


/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/

extern Std_Return_Type KbdDrv_GetAutReq(uint16* switchesStateP);
extern Std_Return_Type KbdDrv_GetManReq(uint16* switchesStateP);
extern void KbdDrv_Init(void);
extern void KbdDrv_Task(void);


typedef enum{
	KbdDrv_Lenght_Fw = 0,
	KbdDrv_Lenght_Bw,
	KbdDrv_BackRest_Fw,
	KbdDrv_BackRest_Bw,
	KbdDrv_Height_Up,
	KbdDrv_Height_Down,
	KbdDrv_Tilt_Up,
	KbdDrv_Tilt_Down,
	KbdDrv_Memory_Set,
	KbdDrv_Memory_One,
	KbdDrv_Memory_Two,
	KbdDrv_Pneumatic_Inflate,
	KbdDrv_Pneumatic_Deflate,
	KbdDrv_Pneumatic_Up,
	KbdDrv_Pneumatic_Down,
	KbdDrv_Heat,
	KbdDrv_swCnt
}Kd_TSwitchPackButton;

/*********************************************************************************************************************/
/* Declarations of prototypes for exported functions                                                            	 */
/*********************************************************************************************************************/

#endif /* KBDDRV_H_ */
