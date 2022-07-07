/**********************************************************************
* @file		Touch.c
* @brief	DualFlex Display Main
* @version	1.00
* @date		26 APRIL 2022
* @author	P.W.K
*
**********************************************************************/
#include "string.h"
#include "GlobalValue.h"
#include "Touch.h"
#include "LEDControl.h"


void PLSelect(UINT8 ucTouchKey)
{
	UINT8 ucBNR = 0;
	UINT8 ucPLFlag = SET;

	if(gaucBNRSelectFlag[LR_BNR] == SET)
	{
		ucBNR = LR_BNR;
	}
	else if(gaucBNRSelectFlag[LF_BNR] == SET)
	{
		ucBNR = LF_BNR;
	}
	else if(gaucBNRSelectFlag[RR_BNR] == SET)
	{
		ucBNR = RR_BNR;
	}
	else if(gaucBNRSelectFlag[RF_BNR] == SET)
	{
		ucBNR = RF_BNR;
	}
	else
	{
		ucPLFlag = CLR;
	}
	
	if(ucPLFlag == SET)
	{
		switch(ucTouchKey)
		{
			case PL_0_KEY :
				gaucPowerLevel[ucBNR] = PL_0;
				gaucBNRSelectFlag[ucBNR] = CLR;
				break;
			case PL_1_KEY :
				gaucPowerLevel[ucBNR] = PL_1;
				gaucBNRSelectFlag[ucBNR] = CLR;
				break;
			case PL_2_KEY :
				gaucPowerLevel[ucBNR] = PL_2;
				gaucBNRSelectFlag[ucBNR] = CLR;
				break;
			case PL_3_KEY :
				gaucPowerLevel[ucBNR] = PL_3;
				gaucBNRSelectFlag[ucBNR] = CLR;
				break;
			case PL_4_KEY :
				gaucPowerLevel[ucBNR] = PL_4;
				gaucBNRSelectFlag[ucBNR] = CLR;
				break;
			case PL_5_KEY :
				gaucPowerLevel[ucBNR] = PL_5;
				gaucBNRSelectFlag[ucBNR] = CLR;
				break;
			case PL_6_KEY :
				gaucPowerLevel[ucBNR] = PL_6;
				gaucBNRSelectFlag[ucBNR] = CLR;
				break;
			case PL_7_KEY :
				gaucPowerLevel[ucBNR] = PL_7;
				gaucBNRSelectFlag[ucBNR] = CLR;
				break;
			case PL_8_KEY :
				gaucPowerLevel[ucBNR] = PL_8;
				gaucBNRSelectFlag[ucBNR] = CLR;
				break;
			case PL_9_KEY :
				gaucPowerLevel[ucBNR] = PL_9;
				gaucBNRSelectFlag[ucBNR] = CLR;
				break;
			
			default :
				break;			
		}

	}
	else
	{
		ucPLFlag = CLR;
		//Timer+-KeyJob
	}
}


void TouchJob(void)
{
	if(gucKeyProcessingFlag == CLR)
	{
		switch(gucTouchKey)
		{
			case LOCK_KEY :	//LongKey
				gucLockFlag ^= SET;
				gucKeyProcessingFlag = SET;
				break;
			case AUTOPOT_KEY :
				gucAutoPotSetFlag ^= SET;
				gucKeyProcessingFlag = SET;
				break;
			case PAUSE_KEY :
				gucPauseFlag ^= SET;
				gucKeyProcessingFlag = SET;
				break;
			case BOOST_KEY :
				gucBoostFlag ^= SET;
				gucKeyProcessingFlag = SET;
				break;
			case TIMER_KEY :
				gucKeyProcessingFlag = SET;
				break;
			case FLEX_LEFT_KEY :
				gaucFlexFlag[LEFT] ^= SET;
				gucKeyProcessingFlag = SET;
				break;
			case FLEX_RIGHT_KEY :
				gaucFlexFlag[RIGHT] ^= SET;
				gucKeyProcessingFlag = SET;
				break;
			case LRBNR_KEY :
				memset(gaucBNRSelectFlag,0,sizeof(gaucBNRSelectFlag));
				gaucBNRSelectFlag[LR_BNR] = SET;
				gucKeyProcessingFlag = SET;
				break;
			case LFBNR_KEY :
				memset(gaucBNRSelectFlag,0,sizeof(gaucBNRSelectFlag));
				gaucBNRSelectFlag[LF_BNR] = SET;
				gucKeyProcessingFlag = SET;
				break;
			case RFBNR_KEY :
				memset(gaucBNRSelectFlag,0,sizeof(gaucBNRSelectFlag));
				gaucBNRSelectFlag[RF_BNR] = SET;
				gucKeyProcessingFlag = SET;
				break;
			case RRBNR_KEY :
				memset(gaucBNRSelectFlag,0,sizeof(gaucBNRSelectFlag));
				gaucBNRSelectFlag[RR_BNR] = SET;
				gucKeyProcessingFlag = SET;
				break;

			default :
				PLSelect(gucTouchKey);
				break;
		}
		
	}
}

UINT8 KeyDefine(UINT8 ucDeviceID, UINT8 ucTouchData[2], UINT8 ucState, UINT8 ucKey)
{
//	UINT8 ucKey = 0;
	
	if(ucDeviceID == TQ12_ID_VDD)	//IC1
	{
		if(ucTouchData[1] == 0)
		{
			switch(ucTouchData[0])
			{
				case 0x00 : //ucKey = NO_KEY;
					break;
				case 0x01 : ucKey = FLEX_RIGHT_KEY;
					break;
				case 0x02 : ucKey = TIMER_KEY;
					break;
				case 0x04 : ucKey = BOOST_KEY;
					break;
				case 0x08 : ucKey = FLEX_LEFT_KEY;
					break;
				case 0x10 : ucKey = PAUSE_KEY;
					break;
				case 0x20 : ucKey = LFBNR_KEY;
					break;
				case 0x40 : ucKey = AUTOPOT_KEY;
					break;
				case 0x80 : ucKey = LOCK_KEY;
					break;
				default : //ucKey = NO_KEY;//MultiKey
					break;
			}
		}
		else ; //Multikey
		if(ucTouchData[0] == 0)
		{
			switch(ucTouchData[1])	
			{
				case 0x00 : //ucKey = NO_KEY;
					break;
				case 0x01 : ucKey = LRBNR_KEY;
					break;
				case 0x02 : 
					if(ucState == LONG)
					{
						ucKey = POWER_LONG_KEY;
					}
					else
					{
						ucKey = POWER_KEY;
					}
					break;
				case 0x04 : ucKey = RRBNR_KEY;
					break;
				case 0x08 : ucKey = RFBNR_KEY;
					break;
				default : //ucKey = NO_KEY;//MultiKey
					break;
			}
		}
		else ;//MultiKey;
	}
	else	//IC2
	{
		if(ucTouchData[1] == 0)
		{
			switch(ucTouchData[0])
			{
				case 0x00 : //ucKey = NO_KEY;
					break;
				case 0x01 : ucKey = PL_9_KEY;
					break;
				case 0x02 : ucKey = PL_8_KEY;
					break;
				case 0x04 : ucKey = PL_7_KEY;
					break;
				case 0x08 : ucKey = PL_6_KEY;
					break;
				case 0x10 : ucKey = PL_5_KEY;
					break;
				case 0x20 : ucKey = PL_4_KEY;
					break;
				case 0x40 : ucKey = PL_3_KEY;
					break;
				case 0x80 : ucKey = PL_2_KEY;
					break;
				default : //ucKey = NO_KEY;//MultiKey
					break;
			}
		}
		else ; //MultiKey
		if(ucTouchData[0] == 0)
		{
			switch(ucTouchData[1])	
			{
				case 0x00 : //ucKey = NO_KEY;
					break;
				case 0x01 : ucKey = PL_1_KEY;
					break;
				case 0x02 : ucKey = PL_0_KEY;
					break;
				case 0x04 : ucKey = TIMER_PLUS_KEY;
					break;
				case 0x08 : ucKey = TIMER_MINUS_KEY;
					break;
				default : //ucKey = NO_KEY;//MultiKey
					break;
			}
		}
		else ;//MultiKey
	}
	
	return ucKey;
}

UINT8 gucTest0 = 0;
UINT8 gucTest1 = 0;

void ReadTouch(UINT8 ucDeviceID)
{
	static UINT8 sucOldData[2][2] = {0,};
	static UINT8 sucKeyInCnt[2] = {0,};
	static UINT8 sucNoKeyFlag = 0;
	static UINT8 sucKeyChangeFlag = 0;
	UINT8 ucTxData[I2CDATA]={0,};
	UINT8 ucIDIndex = 0;
	UINT8 ucTouchICData[2] = {0,};

	I2C_M_SETUP_Type MasterCfg;
	
	if(ucDeviceID == TQ12_ID_VDD)
	{
		ucIDIndex = 1;
	}
	else
	{
		ucIDIndex = 0;
	}
	
	MasterCfg.sl_addr7bit = ucDeviceID;//0xD0;	//ADDR
	ucTxData[0] = Output1;	//REG
	ucTxData[1] = 0x00;
	//ucTxData[2] = 0x39;		//DATA	//Impedance Low, Fast Response Enable, Disable Sleep
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 1;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
	memset(gucI2CData1,0,I2CDATA-2);
	MasterCfg.sl_addr7bit = ucDeviceID;//0xD1;
  MasterCfg.rx_data = gucI2CData1;
  MasterCfg.rx_length = 1;//I2CDATA-2;
	
	HAL_I2C_MasterReceiveData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	

	MasterCfg.sl_addr7bit = ucDeviceID;//0xD0;	//ADDR
	ucTxData[0] = Output2;	//REG
	ucTxData[1] = 0x00;
	//ucTxData[2] = 0x39;		//DATA	//Impedance Low, Fast Response Enable, Disable Sleep
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 1;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
	memset(gucI2CData2,0,I2CDATA-2);
	MasterCfg.sl_addr7bit = ucDeviceID;//0xD1;
  MasterCfg.rx_data = gucI2CData2;
  MasterCfg.rx_length = 1;//I2CDATA-2;
	
	HAL_I2C_MasterReceiveData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	

	gucTouchData[0] = gucI2CData1[0];
	gucTouchData[1] = gucI2CData2[0];//gucI2CData[1];
	
	ucTouchICData[0] = gucI2CData1[0];
	ucTouchICData[1] = gucI2CData2[0];//gucI2CData[1];
	
	
	gucTest0 = gucI2CData1[0];
	gucTest1 = gucI2CData2[0];//gucI2CData[1];
	

	
	if(gucI2CData1[0] == 0 && gucI2CData2[0] == 0)
	{	
		if(sucOldData[0][0] == 0 && sucOldData[0][1] == 0 && sucOldData[1][0] == 0 && sucOldData[1][1] == 0)
		{
			gucTouchKey = NO_KEY;
		//	sucKeyInCnt[ucIDIndex] = 0;
		}
		else
		{
			//Skip
		}
		if(sucOldData[ucIDIndex][0] == 0 && sucOldData[ucIDIndex][1] == 0) sucKeyInCnt[ucIDIndex] = 0;
		//sucKeyInCnt[ucIDIndex] = 0;
	}
	else if(gucI2CData1[0] != 0 && gucI2CData2[0] != 0)
	{// Multi Key
		if(sucOldData[ucIDIndex][0] == gucI2CData1[0] && sucOldData[ucIDIndex][1] == gucI2CData2[0])
		{
			sucKeyInCnt[ucIDIndex]++;
			if(sucKeyInCnt[ucIDIndex] >= 50) gucTouchKey = KeyDefine(ucDeviceID, ucTouchICData, LONG, gucTouchKey);
		}
	}
	else
	{// Key In
		if(sucOldData[ucIDIndex][0] == gucI2CData1[0] && sucOldData[ucIDIndex][1] == gucI2CData2[0])
		{

				sucKeyInCnt[ucIDIndex]++;
				if(sucKeyInCnt[ucIDIndex] >= 5 && sucKeyInCnt[ucIDIndex] < 50)
				{
					gucTouchKey = KeyDefine(ucDeviceID, ucTouchICData, NORMAL, gucTouchKey);
				}
				else if(sucKeyInCnt[ucIDIndex] >= 50)
				{
					gucTouchKey = KeyDefine(ucDeviceID, ucTouchICData, LONG, gucTouchKey);
				}
				else if(sucKeyInCnt[ucIDIndex] >= 250) 
				{
					sucKeyInCnt[ucIDIndex] = 0;
				}
				else
				{
					;
				}

		}
		else
		{
			;	//Filter
		}

	}
	sucOldData[ucIDIndex][0] = gucI2CData1[0];
	sucOldData[ucIDIndex][1] = gucI2CData2[0];

	
	if(gucTouchKey == NO_KEY) gucKeyProcessingFlag = CLR;
	
	
	//Retrun
}


void InitTQ12(UINT8 ucSlaveID)
{
	UINT8 ucTxData[I2CDATA]={0,};
	I2C_M_SETUP_Type MasterCfg;
	
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = CTRL2;	//REG		//0x0F
	ucTxData[1] = 0x39;		//DATA	//Impedance Low, Fast Response Enable, Disable Sleep
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = I2CDATA;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
		
// --------------- Hidden Register---------------------
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = 0x16;	//Start Address 0x16h
	ucTxData[1] = 0x00;		//Data  ,0x16h
	ucTxData[2] = 0x33;		//Data  ,0x17h
	ucTxData[3] = 0x33;		//Data  ,0x18h
	ucTxData[4] = 0x33;		//Data  ,0x19h
	ucTxData[5] = 0x33;		//Data  ,0x1Ah
	ucTxData[6] = 0x33;		//Data  ,0x1Bh
	ucTxData[7] = 0x33;		//Data  ,0x1Ch
	ucTxData[8] = 0x03;		//Data  ,0x1Dh
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 9;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
//------------ Sensitivity control  -----------------------------------

	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Sensitivity1;	//0x02h
	ucTxData[1] = 0x10;					//HEX Value x 0.1% = 1.6%
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Sensitivity2;	//0x03h
	ucTxData[1] = 0x10;					//HEX Value x 0.1% = 1.6%
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Sensitivity3;	//0x04h
	ucTxData[1] = 0x10;					//HEX Value x 0.1% = 1.6%
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
		
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Sensitivity4;	//0x05h
	ucTxData[1] = 0x10;					//HEX Value x 0.1% = 1.6%
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Sensitivity5;	//0x06h
	ucTxData[1] = 0x10;					//HEX Value x 0.1% = 1.6%
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Sensitivity6;	//0x07h
	ucTxData[1] = 0x10;					//HEX Value x 0.1% = 1.6%
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Sensitivity7;	//0x08h
	ucTxData[1] = 0x10;					//HEX Value x 0.1% = 1.6%
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Sensitivity8;	//0x09h
	ucTxData[1] = 0x10;					//HEX Value x 0.1% = 1.6%
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Sensitivity9;	//0x0Ah
	ucTxData[1] = 0x10;					//HEX Value x 0.1% = 1.6%
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Sensitivity10;	//0x0Bh
	ucTxData[1] = 0x10;					//HEX Value x 0.1% = 1.6%
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Sensitivity11;	//0x0Ch
	ucTxData[1] = 0x10;					//HEX Value x 0.1% = 1.6%
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Sensitivity12;	//0x0Dh
	ucTxData[1] = 0x10;					//HEX Value x 0.1% = 1.6%
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
//------------ Sensitivity control  -----------------------------------

	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = CTRL1;	//0x0Eh
	ucTxData[1] = 0x05;					//Burst Fast Mode, FTC 5sec, Multi-Output, Response 5+1
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
// ----------- Channel_Reset Register1 (Sensing Channel On/Off)---------------
// The unused CS Channel must be disabled.

	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Channel_Reset1;	//0x12h
	ucTxData[1] = 0x00;					// 0: Sensing, 1: No Sensing
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
// ----------- Channel_Reset Register2 (Sensing Channel On/Off)---------------
// The unused CS Channel must be disabled.

	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Channel_Reset2;	//0x13h
	ucTxData[1] = 0x00;					// 0: Sensing, 1: No Sensing
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
// ----------- Calibration Hold Register1 (Calibration on/off) --------------
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Calibration_Hold1;	//0x14h
	ucTxData[1] = 0x00;					// 0: Sensing + Calibration, 1: Sensing + No Calibration
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
// ----------- Calibration Hold Register1 (Calibration on/off) --------------
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Calibration_Hold2;	//0x15h
	ucTxData[1] = 0x00;					// 0: Sensing + Calibration, 1: Sensing + No Calibration
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
// ------------ Error Percent Register --------------------------------------

	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Error_Percnet;	//0x29h
	ucTxData[1] = 0x20;					// 
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);

// ------------ Calibration Speed Control Register -----------------------------

	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = CR_Cal_Speed;	//0x2Ah
	ucTxData[1] = 0x43;					// 
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
// ------------ Calibration Speed Control Register -----------------------------

	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = CS_Cal_Speed;	//0x2Bh
	ucTxData[1] = 0x43;					// 
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);


// ------------ Sleep Time Control Register -----------------------------------
	
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = Sleep_Time_Control;	//0x2Ch
	ucTxData[1] = 0x09;					// 
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
// ------------ System Control Register 3 -------------------------------------
	 
	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = CTRL3;	//0x5Bh
	ucTxData[1] = 0xB0;					// 
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
	
//------------------ Software Reset Disable (Clear) ---------------------

	MasterCfg.sl_addr7bit = ucSlaveID;	//ADDR
	ucTxData[0] = CTRL2;	//
	ucTxData[1] = 0x31;					// CS Impedance Low, Fast Response Enable,Disable Sleep
	MasterCfg.tx_data = ucTxData;
	MasterCfg.tx_length = 2;
	
	HAL_I2C_MasterTransmitData(I2C0, &MasterCfg, I2C_TRANSFER_POLLING);
	
	memset(ucTxData,0,I2CDATA-1);
}
