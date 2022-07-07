/**********************************************************************
* @file		GlobalValue.c
* @brief	DualFlex Display Main
* @version	1.00
* @date		28 MARCH 2022
* @author	P.W.K
*
**********************************************************************/

#include "GlobalValue.h"

UINT8 gucState = 0;

UINT8 guc100ms_PF_Flag = 0;
UINT8 guc100ms_LEDCOM_Flag = 0;
UINT8 guc100msFlag = 0;
UINT8 guc1msFlag = 0;

UINT8 guc100msCnt = 0;
UINT8 guc1msCnt = 0;

UINT16 gunTestCnt = 0;

UINT8 gucI2CData1[I2CDATA] = {0,};
UINT8 gucI2CData2[I2CDATA] = {0,};
UINT8 gucTouchData[I2CDATA] = {0,};
UINT8 gucTouchKey = 0;

UINT8 gucKeyProcessingFlag = 0;

UINT8 gaucInvTXBuffer[10] = {0,};
UINT8 gucTxCnt = 0;

UINT8 gaucBNRSelectFlag[4] = {0,};
UINT8 gucLockFlag = 0;
UINT8 gucAutoPotSetFlag = 0;
UINT8 gucPauseFlag = 0;
UINT8 gaucFlexFlag[2] = {0,};
UINT8 gucBoostFlag = 0;

UINT8 gaucPowerLevel[4] = {0,};

UART_CFG_Type UARTConfigStruct;
