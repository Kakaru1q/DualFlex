/**********************************************************************
* @file		Display.c
* @brief	DualFlex Display Main
* @version	1.00
* @date		25 MAY 2022
* @author	P.W.K
*
**********************************************************************/
#include "string.h"
#include "GlobalValue.h"
#include "Display.h"
#include "LEDControl.h"

/*
		LEDControl(AUTOPOT_LED,WHITE_ON);
		LEDControl(LOCK_LED,WHITE_ON);
		LEDControl(PAUSE_LED,WHITE_ON);
		LEDControl(LRBNR_LEFT_LED0,WHITE_ON);
		LEDControl(LRBNR_LEFT_LED1,WHITE_ON);
		LEDControl(LRBNR_RIGHT_LED0,WHITE_ON);
		LEDControl(LRBNR_RIGHT_LED1,WHITE_ON);
		LEDControl(LFBNR_LEFT_LED0,WHITE_ON);
		LEDControl(LFBNR_LEFT_LED1,WHITE_ON);
		LEDControl(LFBNR_RIGHT_LED0,WHITE_ON);
		LEDControl(LFBNR_RIGHT_LED1,WHITE_ON);
		LEDControl(RRBNR_LEFT_LED0,WHITE_ON);
		LEDControl(RRBNR_LEFT_LED1,WHITE_ON);
		LEDControl(RRBNR_RIGHT_LED0,WHITE_ON);
		LEDControl(RRBNR_RIGHT_LED1,WHITE_ON);
		LEDControl(RFBNR_LEFT_LED0,WHITE_ON);
		LEDControl(RFBNR_LEFT_LED1,WHITE_ON);
		LEDControl(RFBNR_RIGHT_LED0,WHITE_ON);
		LEDControl(RFBNR_RIGHT_LED1,WHITE_ON);
		LEDControl(FLEX_LEFT_LED,WHITE_ON);
		LEDControl(FLEX_RIGHT_LED,WHITE_ON);
		LEDControl(TIMER_LED,WHITE_ON);
		LEDControl(BOOST_LED,WHITE_ON);
*/

void AutoPotDisplay(void)
{
	if(gucAutoPotSetFlag == SET)
	{
		LEDControl(AUTOPOT_LED,BLUE_ON);
	}
	else
	{
		LEDControl(AUTOPOT_LED,WHITE_ON);
	}
}

void LockDisplay(void)
{
	if(gucLockFlag == SET)
	{
			LEDControl(LOCK_LED,BLUE_ON);
	}
	else
	{
			LEDControl(LOCK_LED,WHITE_ON);
	}
}

void PauseDisplay(void)
{
	if(gucPauseFlag == SET)
	{
		LEDControl(PAUSE_LED,BLUE_ON);
	}
	else
	{
		LEDControl(PAUSE_LED,WHITE_ON);
	}
	//Segment Display
}

void FlexDisplay(void)
{
	//Left
	if(gaucFlexFlag[LEFT] == SET)
	{
		LEDControl(FLEX_LEFT_LED,BLUE_ON);
		LEDControl(LRBNR_LEFT_LED0,BLUE_ON);
		LEDControl(LRBNR_LEFT_LED1,BLUE_ON);
		LEDControl(LFBNR_LEFT_LED0,BLUE_ON);
		LEDControl(LFBNR_LEFT_LED1,BLUE_ON);
	}
	else if(gaucFlexFlag[LEFT] == CLR)
	{
		LEDControl(FLEX_LEFT_LED,WHITE_ON);
		LEDControl(LRBNR_LEFT_LED0,WHITE_ON);
		LEDControl(LRBNR_LEFT_LED1,WHITE_ON);
		LEDControl(LFBNR_LEFT_LED0,WHITE_ON);
		LEDControl(LFBNR_LEFT_LED1,WHITE_ON);
	}
	else
	{
		;
	}
	
	//Right
	if(gaucFlexFlag[RIGHT] == SET)
	{
		LEDControl(FLEX_RIGHT_LED,BLUE_ON);
		LEDControl(RRBNR_RIGHT_LED0,BLUE_ON);
		LEDControl(RRBNR_RIGHT_LED1,BLUE_ON);
		LEDControl(RFBNR_RIGHT_LED0,BLUE_ON);
		LEDControl(RFBNR_RIGHT_LED1,BLUE_ON);
	}
	else if(gaucFlexFlag[RIGHT] == CLR)
	{
		LEDControl(FLEX_RIGHT_LED,WHITE_ON);
		LEDControl(RRBNR_RIGHT_LED0,WHITE_ON);
		LEDControl(RRBNR_RIGHT_LED1,WHITE_ON);
		LEDControl(RFBNR_RIGHT_LED0,WHITE_ON);
		LEDControl(RFBNR_RIGHT_LED1,WHITE_ON);
	}
	else
	{
		;
	}
}

void TimerLEDDisplay(void)
{
	if(gaucPowerLevel[LF_BNR] > 0 || gaucPowerLevel[LR_BNR] > 0 || gaucPowerLevel[RR_BNR] > 0 || gaucPowerLevel[RF_BNR] > 0)
	{
		LEDControl(TIMER_LED,BLUE_ON);
	}
	else
	{
		LEDControl(TIMER_LED,WHITE_ON);
	}
	LEDControl(TIMER_PLUS_LED,ON);
	LEDControl(TIMER_MINUS_LED,ON);
}

void TimerSegmentDisplay(void)
{
}

void BNRPanDetectDisplay(void)
{
	//if Pandetected to Inv : BLUE LED ON & BAR LED ON , else : WHITE LED ON & BAR LED OFF
}

void PLDisplay(void)
{
			LEDControl(PL_0_LED,ON);
			LEDControl(PL_1_LED,ON);
			LEDControl(PL_2_LED,ON);
			LEDControl(PL_3_LED,ON);
			LEDControl(PL_4_LED,ON);
			LEDControl(PL_5_LED,ON);
			LEDControl(PL_6_LED,ON);
			LEDControl(PL_7_LED,ON);
			LEDControl(PL_8_LED,ON);
			LEDControl(PL_9_LED,ON);
}
void BNRSelectDisplay(void)
{
	static UINT16 sunBlinkCnt[4] = {0,};
	static UINT8 sucBlinkFlag[4] = {0,};
	static UINT8 sucConfirmCnt[4] = {0,};
	static UINT8 sucConfirmFlag[4] = {0,};

	//Blink Seg
	

	if(gaucBNRSelectFlag[LR_BNR] == SET)
	{
		sunBlinkCnt[LR_BNR]++;
		if(sunBlinkCnt[LR_BNR] >= 250)
		{
			sucBlinkFlag[LR_BNR] ^= SET;
			sunBlinkCnt[LR_BNR] = 0;
			sucConfirmCnt[LR_BNR]++;
		}
		else ;
		
		if(sucConfirmCnt[LR_BNR] >= 6)
		{
			sucConfirmFlag[LR_BNR] = SET;
			sucConfirmCnt[LR_BNR] = 0;
		}
		else
		{
			sucConfirmFlag[LR_BNR] = CLR;
		}
		
		//Test
		if(sucBlinkFlag[LR_BNR] == SET)
		{
			SegmentLED_Control(LRBNR_SEG_LED,gaucPowerLevel[LR_BNR],ON);
			LEDControl(LRBNR_RIGHT_LED0,BLUE_ON);
			LEDControl(LRBNR_RIGHT_LED1,BLUE_ON);
			LEDControl(LRBNR_BAR_LED0,ON);
			LEDControl(LRBNR_BAR_LED1,ON);
			if(gaucFlexFlag[LEFT] == SET)
			{
				LEDControl(LFBNR_RIGHT_LED0,BLUE_ON);
				LEDControl(LFBNR_RIGHT_LED1,BLUE_ON);
				LEDControl(LFBNR_BAR_LED0,ON);
				LEDControl(LFBNR_BAR_LED1,ON);
			}
		}
		else
		{
			SegmentLED_Control(LRBNR_SEG_LED,gaucPowerLevel[LR_BNR],OFF);
			LEDControl(LRBNR_RIGHT_LED0,WHITE_ON);
			LEDControl(LRBNR_RIGHT_LED1,WHITE_ON);
			LEDControl(LRBNR_BAR_LED0,OFF);
			LEDControl(LRBNR_BAR_LED1,OFF);
			if(gaucFlexFlag[LEFT] == SET)
			{
				LEDControl(LFBNR_RIGHT_LED0,WHITE_ON);
				LEDControl(LFBNR_RIGHT_LED1,WHITE_ON);
				LEDControl(LFBNR_BAR_LED0,OFF);
				LEDControl(LFBNR_BAR_LED1,OFF);
			}
		}
		if(sucConfirmFlag[LR_BNR] == SET)
		{
			gaucBNRSelectFlag[LR_BNR] = CLR;
			SegmentLED_Control(LRBNR_SEG_LED,gaucPowerLevel[LR_BNR],ON);
		}
		else
		{
			;
		}
	}
	else if(gaucBNRSelectFlag[LF_BNR] == SET)
	{
		
		sunBlinkCnt[LF_BNR]++;
		if(sunBlinkCnt[LF_BNR] >= 250)
		{
			sucBlinkFlag[LF_BNR] ^= SET;
			sunBlinkCnt[LF_BNR] = 0;
			sucConfirmCnt[LF_BNR]++;
		}
		else ;
		
		if(sucConfirmCnt[LF_BNR] >= 6)
		{
			sucConfirmFlag[LF_BNR] = SET;
			sucConfirmCnt[LF_BNR] = 0;
		}
		else
		{
			sucConfirmFlag[LF_BNR] = CLR;
		}
		
		
		if(sucBlinkFlag[LF_BNR] == SET)
		{
			SegmentLED_Control(LFBNR_SEG_LED,gaucPowerLevel[LF_BNR],ON);
			LEDControl(LFBNR_RIGHT_LED0,BLUE_ON);
			LEDControl(LFBNR_RIGHT_LED1,BLUE_ON);
			LEDControl(LFBNR_BAR_LED0,ON);
			LEDControl(LFBNR_BAR_LED1,ON);
			if(gaucFlexFlag[LEFT] == SET)
			{
				LEDControl(LRBNR_RIGHT_LED0,BLUE_ON);
				LEDControl(LRBNR_RIGHT_LED1,BLUE_ON);
				LEDControl(LRBNR_BAR_LED0,ON);
				LEDControl(LRBNR_BAR_LED1,ON);
			}
		}
		else
		{
			SegmentLED_Control(LFBNR_SEG_LED,gaucPowerLevel[LF_BNR],OFF);
			LEDControl(LFBNR_RIGHT_LED0,WHITE_ON);
			LEDControl(LFBNR_RIGHT_LED1,WHITE_ON);
			LEDControl(LFBNR_BAR_LED0,OFF);
			LEDControl(LFBNR_BAR_LED1,OFF);
			if(gaucFlexFlag[LEFT] == SET)
			{
				LEDControl(LRBNR_RIGHT_LED0,WHITE_ON);
				LEDControl(LRBNR_RIGHT_LED1,WHITE_ON);
				LEDControl(LRBNR_BAR_LED0,OFF);
				LEDControl(LRBNR_BAR_LED1,OFF);
			}
		}
		if(sucConfirmFlag[LF_BNR] == SET)
		{
			gaucBNRSelectFlag[LF_BNR] = CLR;
			SegmentLED_Control(LFBNR_SEG_LED,gaucPowerLevel[LF_BNR],ON);
		}
		else
		{
			;
		}
	}
	else if(gaucBNRSelectFlag[RR_BNR] == SET)
	{
		
		sunBlinkCnt[RR_BNR]++;
		if(sunBlinkCnt[RR_BNR] >= 250)
		{
			sucBlinkFlag[RR_BNR] ^= SET;
			sunBlinkCnt[RR_BNR] = 0;
			sucConfirmCnt[RR_BNR]++;
		}
		else ;
		
		if(sucConfirmCnt[RR_BNR] >= 6)
		{
			sucConfirmFlag[RR_BNR] = SET;
			sucConfirmCnt[RR_BNR] = 0;
		}
		else
		{
			sucConfirmFlag[RR_BNR] = CLR;
		}
		
		if(sucBlinkFlag[RR_BNR] == SET)
		{
			SegmentLED_Control(RRBNR_SEG_LED,gaucPowerLevel[RR_BNR],ON);
			LEDControl(RRBNR_LEFT_LED0,BLUE_ON);
			LEDControl(RRBNR_LEFT_LED1,BLUE_ON);
			LEDControl(RRBNR_BAR_LED0,ON);
			LEDControl(RRBNR_BAR_LED1,ON);
			if(gaucFlexFlag[RIGHT] == SET)
			{
				LEDControl(RFBNR_RIGHT_LED0,BLUE_ON);
				LEDControl(RFBNR_RIGHT_LED1,BLUE_ON);
				LEDControl(RFBNR_BAR_LED0,ON);
				LEDControl(RFBNR_BAR_LED1,ON);
			}
		}
		else
		{
			SegmentLED_Control(RRBNR_SEG_LED,gaucPowerLevel[RR_BNR],OFF);
			LEDControl(RRBNR_LEFT_LED0,WHITE_ON);
			LEDControl(RRBNR_LEFT_LED1,WHITE_ON);
			LEDControl(RRBNR_BAR_LED0,OFF);
			LEDControl(RRBNR_BAR_LED1,OFF);
			if(gaucFlexFlag[RIGHT] == SET)
			{
				LEDControl(RFBNR_RIGHT_LED0,WHITE_ON);
				LEDControl(RFBNR_RIGHT_LED1,WHITE_ON);
				LEDControl(RFBNR_BAR_LED0,OFF);
				LEDControl(RFBNR_BAR_LED1,OFF);
			}
		}
		if(sucConfirmFlag[RR_BNR] == SET)
		{
			gaucBNRSelectFlag[RR_BNR] = CLR;
			SegmentLED_Control(RRBNR_SEG_LED,gaucPowerLevel[RR_BNR],ON);
		}
		else
		{
			;
		}
	}
	else if(gaucBNRSelectFlag[RF_BNR] == SET)
	{
		
		sunBlinkCnt[RF_BNR]++;
		if(sunBlinkCnt[RF_BNR] >= 250)
		{
			sucBlinkFlag[RF_BNR] ^= SET;
			sunBlinkCnt[RF_BNR] = 0;
			sucConfirmCnt[RF_BNR]++;
		}
		else ;
		
		if(sucConfirmCnt[RF_BNR] >= 6)
		{
			sucConfirmFlag[RF_BNR] = SET;
			sucConfirmCnt[RF_BNR] = 0;
		}
		else
		{
			sucConfirmFlag[RF_BNR] = CLR;
		}
		
		
		if(sucBlinkFlag[RF_BNR] == SET)
		{
			SegmentLED_Control(RFBNR_SEG_LED,gaucPowerLevel[RF_BNR],ON);
			LEDControl(RFBNR_LEFT_LED0,BLUE_ON);
			LEDControl(RFBNR_LEFT_LED1,BLUE_ON);
			LEDControl(RFBNR_BAR_LED0,ON);
			LEDControl(RFBNR_BAR_LED1,ON);
			if(gaucFlexFlag[RIGHT] == SET)
			{
				LEDControl(RRBNR_RIGHT_LED0,BLUE_ON);
				LEDControl(RRBNR_RIGHT_LED1,BLUE_ON);
				LEDControl(RRBNR_BAR_LED0,ON);
				LEDControl(RRBNR_BAR_LED1,ON);
			}
		}
		else
		{
			SegmentLED_Control(RFBNR_SEG_LED,gaucPowerLevel[RF_BNR],OFF);
			LEDControl(RFBNR_LEFT_LED0,WHITE_ON);
			LEDControl(RFBNR_LEFT_LED1,WHITE_ON);
			LEDControl(RFBNR_BAR_LED0,OFF);
			LEDControl(RFBNR_BAR_LED1,OFF);
			if(gaucFlexFlag[RIGHT] == SET)
			{
				LEDControl(RRBNR_RIGHT_LED0,WHITE_ON);
				LEDControl(RRBNR_RIGHT_LED1,WHITE_ON);
				LEDControl(RRBNR_BAR_LED0,OFF);
				LEDControl(RRBNR_BAR_LED1,OFF);
			}
		}
		if(sucConfirmFlag[RF_BNR] == SET)
		{
			gaucBNRSelectFlag[RF_BNR] = CLR;
			SegmentLED_Control(RFBNR_SEG_LED,gaucPowerLevel[RF_BNR],ON);
		}
		else
		{
			;
		}
	}
	else
	{
		memset(sunBlinkCnt,0,sizeof(sunBlinkCnt));
		memset(sucBlinkFlag,0,sizeof(sunBlinkCnt));
		memset(sucConfirmCnt,0,sizeof(sunBlinkCnt));
		memset(sucConfirmFlag,0,sizeof(sunBlinkCnt));
	}
	
		if(gaucBNRSelectFlag[LF_BNR] == SET)
		{
			;
		}
		else if(gaucPowerLevel[LF_BNR] > 0)
		{
			SegmentLED_Control(LFBNR_SEG_LED,gaucPowerLevel[LF_BNR],ON);
			LEDControl(LFBNR_RIGHT_LED0,BLUE_ON);
			LEDControl(LFBNR_RIGHT_LED1,BLUE_ON);
			LEDControl(LFBNR_BAR_LED0,ON);
			LEDControl(LFBNR_BAR_LED1,ON);
		}
		else
		{
			SegmentLED_Control(LFBNR_SEG_LED,gaucPowerLevel[LF_BNR],OFF);
			LEDControl(LFBNR_RIGHT_LED0,WHITE_ON);
			LEDControl(LFBNR_RIGHT_LED1,WHITE_ON);
			LEDControl(LFBNR_BAR_LED0,OFF);
			LEDControl(LFBNR_BAR_LED1,OFF);
		}
		if(gaucBNRSelectFlag[LR_BNR] == SET)		
		{
			;
		}
		else if(gaucPowerLevel[LR_BNR] > 0)
		{
			SegmentLED_Control(LRBNR_SEG_LED,gaucPowerLevel[LR_BNR],ON);
			LEDControl(LRBNR_RIGHT_LED0,BLUE_ON);
			LEDControl(LRBNR_RIGHT_LED1,BLUE_ON);
			LEDControl(LRBNR_BAR_LED0,ON);
			LEDControl(LRBNR_BAR_LED1,ON);
		}
		else
		{
			SegmentLED_Control(LRBNR_SEG_LED,gaucPowerLevel[LR_BNR],OFF);
			LEDControl(LRBNR_RIGHT_LED0,WHITE_ON);
			LEDControl(LRBNR_RIGHT_LED1,WHITE_ON);
			LEDControl(LRBNR_BAR_LED0,OFF);
			LEDControl(LRBNR_BAR_LED1,OFF);
		}
		if(gaucBNRSelectFlag[RF_BNR] == SET)		
		{
			;
		}
		else if(gaucPowerLevel[RF_BNR] > 0)
		{
			SegmentLED_Control(RFBNR_SEG_LED,gaucPowerLevel[RF_BNR],ON);
			LEDControl(RFBNR_LEFT_LED0,BLUE_ON);
			LEDControl(RFBNR_LEFT_LED1,BLUE_ON);
			LEDControl(RFBNR_BAR_LED0,ON);
			LEDControl(RFBNR_BAR_LED1,ON);
		}
		else
		{
			SegmentLED_Control(RFBNR_SEG_LED,gaucPowerLevel[RF_BNR],OFF);
			LEDControl(RFBNR_LEFT_LED0,WHITE_ON);
			LEDControl(RFBNR_LEFT_LED1,WHITE_ON);
			LEDControl(RFBNR_BAR_LED0,OFF);
			LEDControl(RFBNR_BAR_LED1,OFF);
		}
	  if(gaucBNRSelectFlag[RR_BNR] == SET)		
		{
			;
		}
		else if(gaucPowerLevel[RR_BNR] > 0)
		{
			SegmentLED_Control(RRBNR_SEG_LED,gaucPowerLevel[RR_BNR],ON);
			LEDControl(RRBNR_LEFT_LED0,BLUE_ON);
			LEDControl(RRBNR_LEFT_LED1,BLUE_ON);
			LEDControl(RRBNR_BAR_LED0,ON);
			LEDControl(RRBNR_BAR_LED1,ON);
		}
		else
		{
			SegmentLED_Control(RRBNR_SEG_LED,gaucPowerLevel[RR_BNR],OFF);
			LEDControl(RRBNR_LEFT_LED0,WHITE_ON);
			LEDControl(RRBNR_LEFT_LED1,WHITE_ON);
			LEDControl(RRBNR_BAR_LED0,OFF);
			LEDControl(RRBNR_BAR_LED1,OFF);
		}
		

	
}

void BoostDisplay(void)
{
	if(gucBoostFlag == SET)
	{
		LEDControl(BOOST_LED,BLUE_ON);
	}
	else
	{
		LEDControl(BOOST_LED,WHITE_ON);
	}
	//Segment Display
}

void DisplayJob(void)
{
	AutoPotDisplay();
	LockDisplay();
	PauseDisplay();
	FlexDisplay();
	BNRSelectDisplay();
	TimerLEDDisplay();
	TimerSegmentDisplay();
	BNRPanDetectDisplay();
	PLDisplay();
	BoostDisplay();
}
