/*
 * Type.h
 *
 *  Created on: Mar 23, 2025
 *      Author: Teo
 */

#ifndef TYPEDEF_H_
#define TYPEDEF_H_

/*********************************************************************************************************************/
/* Define global data types                                                                            				 */
/*********************************************************************************************************************/

#define TRUE	1u
#define FALSE	0u

#define E_OK 		0u
#define E_NOT_OK 	1u

#ifndef NULL
#define NULL (void *)0
#endif

typedef unsigned char		boolean;	/* for use with TRUE/FALSE		*/
typedef signed char 		sint8;		/* -128 		.. 	+127 		*/
typedef unsigned char		uint8;		/* 0 			.. 	255 		*/
typedef signed short 		sint16;		/* -32768 		.. 	+32767 		*/
typedef unsigned short		uint16;		/* 0 			.. 	65535		*/
typedef signed long			sint32;		/* -2147483648 	..  2147483647	*/
typedef unsigned long 		uint32;		/* 0 			.. 	4294967295 	*/

typedef uint8 Std_Return_Type;


#endif /* TYPEDEF_H_ */
