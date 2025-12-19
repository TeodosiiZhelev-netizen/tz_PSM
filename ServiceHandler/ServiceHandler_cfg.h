/*
 * ServiceHandler_cfg.h
 *
 *  Created on: Jun 27, 2025
 *      Author: Teo
 */

#ifndef SERVICEHANDLER_CFG_H_
#define SERVICEHANDLER_CFG_H_

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/
#define SERVICE_BYTE 0u
#define SERVICE_DID_LSB 1u
#define SERVICE_DID_MSB 2u

#define SERVICE_DID_READ_FFFF 0u
#define SERVICE_DID_READ_EEEE 1u

#define SERVICE_DID_WRITE_EEFF 0u
#define SERVICE_DID_WRITE_FFEE 1u

#define SERVICE_READ 1u
#define SERVICE_WRITE 2u
#define SERVICE_ROUTINE_CONTROL 3u
#define SERVICE_IS_ALIVE 4u

#define SERVICE_RID_CALIB_FEFE 0u

#define DATA_SIZE 8u
/*********************************************************************************************************************/
/* Declarations of prototypes for exported functions                                                            	 */
/*********************************************************************************************************************/

#endif /* SERVICEHANDLER_CFG_H_ */
