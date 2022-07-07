/**********************************************************************
* @file		Uart.c
* @brief	DualFlex Display Main
* @version	1.00
* @date		3 MAY 2022
* @author	P.W.K
*
**********************************************************************/
#include "GlobalValue.h"
#include "Uart.h"

UINT8 gaucTestBuffer[10] = {0,};
UINT8 gucTestFlag = 0;
void UARTComm(UINT8 ucInverter)
{
	static UINT8 ucIndex = 0;
	
	UARTConfigStruct.RxTxBuffer = gaucTestBuffer;
	UARTConfigStruct.RxBufferSize = 10;
	UARTConfigStruct.TxBufferSize = 10;

	gaucTestBuffer[0] = 0xAA;
	gaucTestBuffer[1] = 0;//0x11;
	gaucTestBuffer[8] = 0;//0xAA;
	gaucTestBuffer[9] = 0xBB;//0xBB;
	
	gaucInvTXBuffer[0] = 0xAA;
	gaucInvTXBuffer[1] = 0;//0x11;
	gaucInvTXBuffer[8] = 0;//0xAA;
	gaucInvTXBuffer[9] = 0xBB;//0xBB;
	
	
	if(ucInverter == INVERTER_LEFT)
	{
		 // uart_set_buffer(UART1, gaucTestBuffer, UARTConfigStruct.RxBufferSize, UARTConfigStruct.TxBufferSize);
		if(gucTestFlag == 0)
		{
			UART1->THR = gaucInvTXBuffer[0];
			gucTestFlag = 1;
		}
		/*for(ucIndex = 0; ucIndex <= 9; ucIndex++)
		{
			uputc(UART1, gaucTestBuffer[ucIndex]);
		//if(ucIndex <= 9) UART1->THR = gaucTestBuffer[ucIndex++];
		}*/
	}
	else
	{
	//	UART1->THR = 0xDD;
		gucTestFlag = 0;
	}
	
}
