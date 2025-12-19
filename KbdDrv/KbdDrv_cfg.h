/*
 * KbdDrv_cfg.h
 *
 *  Created on: Feb 5, 2025
 *      Author: Teo
 */

#ifndef KBDDRV_CFG_H_
#define KBDDRV_CFG_H_

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/

#define KBDDRV_SWITCHES_CFG {\
	/* 									lineId				pressThrsLow	pressThrsHigh	*/\
	/* KbdDrv_Lenght_Fw				*/{	Line_Lenght_FwBw,			900,			1099},\
	/* KbdDrv_Lenght_Bw				*/{	Line_Lenght_FwBw,			1100,			1299},\
	/* KbdDrv_BackRest_Fw			*/{	Line_BackRest_FwBw,			900,			1099},\
	/* KbdDrv_BackRest_Bw			*/{	Line_BackRest_FwBw,			1100,			1299},\
	/* KbdDrv_Height_Up,			*/{	Line_Height_UpDwn,			900,			1099},\
	/* KbdDrv_Height_Down,			*/{	Line_Height_UpDwn,			1100,			1299},\
	/* KbdDrv_Tilt_Up,				*/{	Line_Tilt_UpDwn,			900,			1099},\
	/* KbdDrv_Tilt_Down,			*/{	Line_Tilt_UpDwn,			1100,			1299},\
	/* KbdDrv_Memory_Set,			*/{	Line_Memory,				900,			1099},\
	/* KbdDrv_Memory_One,			*/{	Line_Memory,				1100,			1299},\
	/* KbdDrv_Memory_Two,			*/{	Line_Memory,				900,			1099},\
	/* KbdDrv_Pneumatic_Inflate,	*/{	Line_Pneumatic_Hor,			1100,			1299},\
	/* KbdDrv_Pneumatic_Deflate,	*/{	Line_Pneumatic_Hor,			900,			1099},\
	/* KbdDrv_Pneumatic_Up,			*/{	Line_Pneumatic_Ver,			1100,			1299},\
	/* KbdDrv_Pneumatic_Down,		*/{	Line_Pneumatic_Ver,			900,			1099},\
	/* KbdDrv_Heat,					*/{	Line_Heat,					1100,			1299}};



#define KBDDRV_MANUAL_REQ_SW_MASK	(\
		(1u<< KbdDrv_Lenght_Fw)|\
		(1u<< KbdDrv_Lenght_Bw)|\
		(1u<< KbdDrv_BackRest_Fw)|\
		(1u<< KbdDrv_BackRest_Bw)|\
		(1u<< KbdDrv_Height_Up)|\
		(1u<< KbdDrv_Height_Down)|\
		(1u<< KbdDrv_Tilt_Up)|\
		(1u<< KbdDrv_Tilt_Down)|\
		(1u<< KbdDrv_Pneumatic_Inflate)|\
		(1u<< KbdDrv_Pneumatic_Deflate)|\
		(1u<< KbdDrv_Pneumatic_Up)|\
		(1u<< KbdDrv_Pneumatic_Down))

#define KBDDRV_AUTO_REQ_SW_MASK	(\
		(1u<< KbdDrv_Memory_Set)|\
		(1u<< KbdDrv_Memory_One)|\
		(1u<< KbdDrv_Memory_Two)|\
		(1u<< KbdDrv_Heat))

/*********************************************************************************************************************/
/* Declarations of prototypes for exported functions                                                            	 */
/*********************************************************************************************************************/

#endif /* KBDDRV_CFG_H_ */
