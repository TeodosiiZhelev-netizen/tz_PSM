/*
 * ServiceHandler.c
 *
 *  Created on: Jun 27, 2025
 *      Author: Teo
 */

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "Typedef.h"
#include "ServiceHandler.h"
#include "ServiceHandler_cfg.h"
#include "ServiceHandler_int.h"
#include "Appl_Type.h"
/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Definitions of local variables (static ...)                                                                       */
/*********************************************************************************************************************/
static uint8 output[DATA_SIZE];
static uint8 input[DATA_SIZE];
/*********************************************************************************************************************/
/* Declarations of prototypes for local functions                                                                    */
/*********************************************************************************************************************/
uint8 Read_DID_HANDLER(uint16 id, uint8 *, uint8 *error_response, uint8 *data_lenght);
uint8 Write_DID_HANDLER(uint16 id, uint8 *, uint8 *error_response, uint8 data_lenght);
uint8 Routine_Control(uint16 id, uint8 subRoutine, uint8 *, uint8 *error_response, uint8 data_lenght);
uint8 Did_FFFF(uint8 *output, uint8 *error_code, uint8 *data_lenght);
/*********************************************************************************************************************/
/* Definitions of global functions                                                                                   */
/*********************************************************************************************************************/
void ServiceHandler_Init(void){

}

void ServiceHandler_Task(void){
	uint16 reqDID;
	uint8 subRoutine;
	Error_Code error_code;
	uint8 i;
	uint8 lenght;
	Std_Return_Type retL = E_NOT_OK;

	switch(input[SERVICE_BYTE]){
		case SERVICE_READ:
			reqDID = input[SERVICE_DID_LSB] | (input[SERVICE_DID_MSB] << 8); //joins LSB and MSB to create a copy of the DID
					retL = Read_DID_HANDLER(reqDID, &output[4], &error_code, &lenght); // Calls Did handler with requested DID, output buffer for response, error code for response result and lenght of data to return
					if(retL == E_OK){
						//check the error code message
						if (error_code != NO_ERROR_CODE){
							output[0] = 0x40 + SERVICE_READ; //negative response
							output[1] = error_code; //error ID
							output[2] = input[SERVICE_DID_LSB];
							output[3] = input[SERVICE_DID_MSB];
							for(i = 4; i < DATA_SIZE; i++){
								output[DATA_SIZE] = 0; // returns NULL
							}
						}else{
							/*positive response*/
							output[0] = 0x80 + SERVICE_READ; //positive response code
							output[1] = input[SERVICE_DID_LSB];
							output[2] = input[SERVICE_DID_MSB];
							output[3] = lenght;// lenght of data to be send
						}
						CommTp_SendDataFrame(output); // calls CommTp with data packaged data frame

					}else{
						// DID handler returned negative response
					}
			break;
		case SERVICE_WRITE:
			reqDID = input[SERVICE_DID_LSB] | (input[SERVICE_DID_MSB] << 8); //joins LSB and MSB to create a copy of the DID
			lenght = input[3]; // lenght of data to write
				retL = Write_DID_HANDLER(reqDID, &input[4], &error_code, lenght); // Calls Did handler with requested DID, output buffer for response, error code for response result and lenght of data to write
				if(retL == E_OK){
					//check the error code message
					if(error_code != NO_ERROR_CODE){
						output[0] = 0x40 + SERVICE_WRITE; //negative response
						output[1] = error_code; //error ID
						output[2] = input[SERVICE_DID_LSB];
						output[3] = input[SERVICE_DID_MSB];

					}else{
						output[0] = 0x80 + SERVICE_READ; //positive response code
						output[1] = input[SERVICE_DID_LSB];
						output[2] = input[SERVICE_DID_MSB];
						output[3] = 0;
					}
					for(i = 4; i < DATA_SIZE; i++){
							output[DATA_SIZE] = 0; // write NULL to the remaining bytes
					}
					CommTp_SendDataFrame(output);

				}else{
					// DID handler returned negative response
				}
			break;
		case SERVICE_ROUTINE_CONTROL:
			reqDID = input[SERVICE_DID_LSB]; // routine ID
			subRoutine = input[SERVICE_DID_MSB]; //sub routine ID
			retL = Routine_Control(reqDID, subRoutine, &input[4], &error_code, lenght); // Calls Did handler with requested RID and sub RID, output buffer for response, error code for response result and lenght of data to write
				if(retL == E_OK){
					if(error_code != 0){
						output[0] = 0x40 + SERVICE_WRITE; //negative response
						output[1] = error_code; //error ID
						output[2] = input[SERVICE_DID_LSB]; // routine ID
						output[3] = input[SERVICE_DID_MSB]; //sub routine ID
						for(i = 4; i < DATA_SIZE; i++){
							input[DATA_SIZE] = 0;
						}
					}else{
						output[0] = 0x80 + SERVICE_READ;
						output[1] = input[SERVICE_DID_LSB]; // routine ID
						output[2] = input[SERVICE_DID_MSB]; //sub routine ID
						output[3] = error_code;
					}
					CommTp_SendDataFrame(output);
				}
			break;
		case SERVICE_IS_ALIVE:
			break;
		default:
			break;
	}
}

void ServiceHandler_SendDataFrame(uint8 *data){

	uint8 i;

	for(i = 0; i < DATA_SIZE; i++){
		input[DATA_SIZE] = data[i];
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
uint8 Read_DID_HANDLER(uint16 id, uint8 * output, Error_Code *error_response, uint8 *data_lenght){

	Std_Return_Type result = E_NOT_OK;

	switch(id){
		case SERVICE_DID_READ_FFFF:
			result = Did_FFFF(output, error_response, data_lenght);
			break;
		case SERVICE_DID_READ_EEEE:
			result = Did_EEEE(output, error_response, data_lenght);
			break;
		default:
			break;
	}
	return result;
}

uint8 Write_DID_HANDLER(uint16 id, uint8 *input, uint8 *error_response, uint8 data_lenght){

	Std_Return_Type result = E_NOT_OK;

		switch(id){
			case SERVICE_DID_WRITE_EEFF:
				result = Did_FFEE(input,*error_response, data_lenght);
				break;
			case SERVICE_DID_WRITE_FFEE:
				result = Did_EEFF(input,*error_response, data_lenght);
				break;
			default:
				break;
		}
		return result;
}

uint8 Routine_Control(uint16 id, uint8 subRoutine, uint8 *, uint8 *error_response, uint8 data_lenght){

	Std_Return_Type result = E_NOT_OK;

	switch(id){
		case SERVICE_RID_CALIB_FEFE:
			result = Rid_FEFE(subRoutine);
			break;
		default:
			break;
		}
			return result;
}

uint8 Did_FFFF(uint8 *output, Error_Code *error_code, uint8 *data_lenght){

	Std_Return_Type result = E_OK;
	uint8 major = 0x01;
	uint8 minor = 0x00;
	uint8 patch = 0x00;

	output[0] = major;
	output[1] = minor;
	output[2] = patch;

	*data_lenght = 3;

	*error_code = NO_ERROR_CODE;

	return result;
}
