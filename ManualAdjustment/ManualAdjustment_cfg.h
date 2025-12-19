/*
 * ManualAdjustment_cfg.h
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

#ifndef MANUALADJUSTMENT_CFG_H_
#define MANUALADJUSTMENT_CFG_H_

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/
#define MANADJUST_FW_COMMAND {\
	(1u<< ManAdj_Lenght_Fw)|\
	(1u<< ManAdj_BackRest_Fw)|\
	(1u<< ManAdj_Height_Up)|\
	(1u<< ManAdj_Tilt_Up)|\}

#define MANADJUST_BW_COMMAND {\
	(1u<< ManAdj_Lenght_Bw)|\
	(1u<< ManAdj_BackRest_Bw)|\
	(1u<< ManAdj_Height_Down)|\
	(1u<< ManAdj_Tilt_Down)|\}
/*********************************************************************************************************************/
/* Declarations of prototypes for exported functions                                                            	 */
/*********************************************************************************************************************/

#endif /* MANUALADJUSTMENT_CFG_H_ */
