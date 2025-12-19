/*
 * CommTp.c
 *
 *  Created on: Jun 26, 2025
 *      Author: Teo
 */

/*********************************************************************************************************************/
/* Include section                                                                                                   */
/*********************************************************************************************************************/
#include "Typedef.h"
#include "main.h"
#include "CommTp.h"
#include "CommTp_cfg.h"
#include "CommTp_int.h"
//#include "ServiceHandler.h"
/*********************************************************************************************************************/
/* Define agreements/data types                                                                            			 */
/*********************************************************************************************************************/
extern UART_HandleTypeDef huart3;
/*********************************************************************************************************************/
/* Definitions of local variables (static ...)                                                                       */
/*********************************************************************************************************************/
static uint8 bufferTX[MAX_SIZE_TX] = {0,};
static uint8 bufferRX[MAX_SIZE_RX] = {0,};
static uint8 index;
static uint8 indexRX;
static uint8 index_TX;
static uint8 startIndex;
static uint8 endIndex;
static uint8 dataFrame[DATA_SIZE];
static uint8 uart_rx_buff;
/*TBD, it shall be set to atleast 5 ms, time enough for reading atleast 10 bytes */
static uint32 timeoutWaitingRxOfEOF = 10000;
/*********************************************************************************************************************/
/* Declarations of prototypes for local functions                                                                    */
/*********************************************************************************************************************/
static void CommTp_GetByteRx(uint8 byte);
/*********************************************************************************************************************/
/* Definitions of global functions                                                                                   */
/*********************************************************************************************************************/
void CommTp_Task(void){
	/* Reading the received value from UART */
	uint8 lengthOfFrame;
	uint8 lengthId;
	uint8 currentInd = 0u;


	while(currentInd <= indexRX){
		if(bufferRX[currentInd] == SOF){
			lengthId = currentInd + 1;
			lengthOfFrame = bufferRX[lengthId];

			while(bufferRX[currentInd + lengthId] != EOF && timeoutWaitingRxOfEOF > 0){
				timeoutWaitingRxOfEOF--;
			}
			if(bufferRX[currentInd + lengthId] == EOF){
				/* valid frame transmit data to Service handler */
				for(uint8 i = 0; i < DATA_SIZE; i++){
					dataFrame[i] = bufferRX[currentInd + 2 + i];
					/*Calling service callback func*/
				}
				ServiceHandler_SendDataFrame(dataFrame);
			}
			currentInd = currentInd + lengthId;
		}
	}

	/* set the RX index to start position of the buffer RX */
	indexRX = 0u;

	/* Writing the value to be transmitted via UART */
	CommTp_HAL_UART_Transmit(bufferTX, MAX_SIZE_TX, 1000);
	index_TX = 0;
}

void CommTp_Init(void){
	CommTp_HAL_UART_Rx_IT(&uart_rx_buff, 1);
}

/*********************************************************************************************************************/
/* @brief  		Definition of the callback which is invoked on each received byte via interrupt        								 */
/*********************************************************************************************************************/
/* @param[in]    UART_HandleTypeDef *huart																								 */
/* @return       none																								 */
/*********************************************************************************************************************/

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	if(*huart == huart3){
	CommTp_HAL_UART_Rx_IT(&uart_rx_buff, 1);
	CommTp_GetByteRx(uart_rx_buff);
	}else{
		/* no correct conf */
	}
}

void CommTp_SendDataFrame(uint8* input){
//adds SOF and EOF to complete the frame to be transmitted
	bufferTX[index_TX++] =  SOF; // first byte is Start of frame
	bufferTX[index_TX++] = 0; // dummy second byte(length of data frame)
	for(; index_TX < DATA_SIZE; index_TX++){
		bufferTX[index_TX] = input;
	}
	bufferTX[index_TX++] = 0; //dummy byte(parity byte)
	bufferTX[index_TX++] = EOF; // last byte is end of frame


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
static void CommTp_GetByteRx(uint8 byte){
//gets every byte that has been received and adds it to a buffer
	if(indexRX < MAX_SIZE_RX){
		bufferRX[indexRX++] = byte;
	}else{
		indexRX = 0;
	}
}
