/*
 * GateDrvCdd_cfg.h
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

#ifndef GATEDRVCDD_CFG_H_
#define GATEDRVCDD_CFG_H_

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "MotDrv_cfg.h"
/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/
#define HB_PER_MOTOR 2u
#define HBCOUNT 8u
static const uint8 HB_TO_MOTOR_MAPPING[MOTORCNT][HB_PER_MOTOR] ={
        /* HB1 GPIO  HB2 GPIO */
/* M1 */    //{GPIO_PIN, GPIO_PIN},
         /* HB1 GPIO  HB2 GPIO */
/* M2 */    //{GPIO_PIN, GPIO_PIN},
         /* HB1 GPIO  HB2 GPIO */
/* M3 */    //{GPIO_PIN, GPIO_PIN},
         /* HB1 GPIO  HB2 GPIO */
/* M4 */    //{GPIO_PIN, GPIO_PIN}
};
/*********************************************************************************************************************/
/* Declarations of prototypes for exported functions                                                            	 */
/*********************************************************************************************************************/

#endif /* GATEDRVCDD_CFG_H_ */
