/**********************************************************************
* @file		main.c
* @brief	DualFlex Display Main
* @version	1.00
* @date		28 MARCH 2022
* @author	P.W.K
*
* Copyright(C) 2020, ABOV Semiconductor
* All rights reserved.
**********************************************************************/
#include "main_conf.h"
#include "GlobalValue.h"
#include "Init.h"
#include "LEDControl.h"
#include "Touch.h"
#include "Uart.h"
#include "Display.h"

int main(void);

/**********************************************************************
 * @brief		Main program
 * @param[in]	None
 * @return	None
 * @DisCrip ALL LED ON & Beep In 5Sec
 **********************************************************************/
 
void DEFAULT_LEDControl(UINT8 ucState, UINT8 ucLEDState)
{
	if(ucState == STATE_IDLE)
	{
		LEDControl(AUTOPOT_LED,OFF);
		LEDControl(LOCK_LED,OFF);
		LEDControl(PAUSE_LED,OFF);
		LEDControl(LRBNR_LEFT_LED0,OFF);
		LEDControl(LRBNR_LEFT_LED1,OFF);
		LEDControl(LRBNR_RIGHT_LED0,OFF);
		LEDControl(LRBNR_RIGHT_LED1,OFF);
		LEDControl(LFBNR_LEFT_LED0,OFF);
		LEDControl(LFBNR_LEFT_LED1,OFF);
		LEDControl(LFBNR_RIGHT_LED0,OFF);
		LEDControl(LFBNR_RIGHT_LED1,OFF);
		LEDControl(RRBNR_LEFT_LED0,OFF);
		LEDControl(RRBNR_LEFT_LED1,OFF);
		LEDControl(RRBNR_RIGHT_LED0,OFF);
		LEDControl(RRBNR_RIGHT_LED1,OFF);
		LEDControl(RFBNR_LEFT_LED0,OFF);
		LEDControl(RFBNR_LEFT_LED1,OFF);
		LEDControl(RFBNR_RIGHT_LED0,OFF);
		LEDControl(RFBNR_RIGHT_LED1,OFF);
		LEDControl(FLEX_LEFT_LED,OFF);
		LEDControl(FLEX_RIGHT_LED,OFF);
		LEDControl(TIMER_LED,OFF);
		LEDControl(BOOST_LED,OFF);
	}
	else if(ucState == STATE_RUN)
	{
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
			
	}
	else
	{
		;
	}
}
 
 
void PF_STATE(void)
{
	static UINT8 suc100msCnt = 0;
	static UINT8 suc200msFlag = 0;
	static UINT8 suc3SecFlag = 0;

	
	while(1)
	{
		if(gucState > STATE_PF)
		{
			break;
		}
		else
		{
			LEDControl(ALL_LED,ON);
			if(guc100ms_PF_Flag == SET)
			{
				suc100msCnt++;
				
				if(suc100msCnt == 2)
				{
					suc200msFlag = SET;		
				}
				if(suc100msCnt >= 30)
				{
					suc3SecFlag = SET;
					suc100msCnt = 0;
				}

				guc100ms_PF_Flag = CLR;
			}
			if(suc200msFlag == SET)
			{
				InitTQ12(TQ12_ID_GND);//0xD0 IC2
				InitTQ12(TQ12_ID_VDD);//0xF0 IC1
				suc200msFlag = CLR;
			}
			if(suc3SecFlag == SET)
			{
				LEDControl(ALL_LED,OFF);
				suc3SecFlag = CLR;
				gucState = STATE_IDLE;
				break;
			}
			else
			{
			//	LEDControl(ALL_LED,OFF);
			}
		}
	}
}

void IDLE_STATE(void)
{
	static UINT8 suc1mscnt = 0;
	static UINT8 sucLongKeycnt = 0;
	
	while(1)
	{
		//Display Job : if sensor hot
		//Key Job : if PowerOnKey On, break;
		if(guc1msFlag == SET)
		{
			guc1msFlag = CLR;
			suc1mscnt++;
			
			LEDCOMControl();
			//if Not HotSurface
		/*	SegmentLED_Control(LRBNR_SEG_LED,8,ON);
			SegmentLED_Control(LFBNR_SEG_LED,8,ON);
			SegmentLED_Control(RRBNR_SEG_LED,8,ON);
			SegmentLED_Control(RFBNR_SEG_LED,8,ON);
			SegmentLED_Control(TIMER10_LED,6,ON);
			SegmentLED_Control(TIMER1_LED,0,ON);
			LEDControl(BOOST_LED,WHITE_ON);
			LEDControl(LOCK_LED,WHITE_ON);
			LEDControl(PAUSE_LED,WHITE_ON);
			LEDControl(AUTOPOT_LED,WHITE_ON);
			LEDControl(TIMER_LED,WHITE_ON);
			LEDControl(TIMER_PLUS_LED,WHITE_ON);
			LEDControl(TIMER_MINUS_LED,WHITE_ON);
			LEDControl(FLEX_LEFT_LED,WHITE_ON);
			LEDControl(FLEX_RIGHT_LED,WHITE_ON);
			LEDControl(PL_0_LED,WHITE_ON);
			LEDControl(PL_1_LED,WHITE_ON);
			LEDControl(PL_2_LED,WHITE_ON);
			LEDControl(PL_3_LED,WHITE_ON);
			LEDControl(PL_4_LED,WHITE_ON);
			LEDControl(PL_5_LED,WHITE_ON);
			LEDControl(PL_6_LED,WHITE_ON);
			LEDControl(PL_7_LED,WHITE_ON);
			LEDControl(PL_8_LED,WHITE_ON);
			LEDControl(PL_9_LED,WHITE_ON);
			LEDControl(LRBNR_BAR_LED0,ON);
			LEDControl(LRBNR_BAR_LED1,ON);
			LEDControl(LFBNR_BAR_LED0,ON);
			LEDControl(LFBNR_BAR_LED1,ON);
			LEDControl(RRBNR_BAR_LED1,ON);
			LEDControl(RFBNR_BAR_LED0,ON);*/
		}
		if(suc1mscnt >= 5)//5ms?10ms?
		{
			suc1mscnt = 0;
			ReadTouch(TQ12_ID_VDD);
		}
		

		if(gucTouchKey == POWER_LONG_KEY) 
		{
					gucState = STATE_RUN;
					break;
		}


	}
}


void RUN_STATE(void)
{
	static UINT8 suc1mscnt = 0;
	static UINT8 suc100mscnt = 0;
	
	while(1)
	{
		//2msJob
		if(guc1msFlag == SET)
		{
			guc1msFlag = CLR;
			suc1mscnt++;
			
			LEDCOMControl();
			
			//Display
			DisplayJob();
			//Test
		//	DEFAULT_LEDControl(STATE_RUN,WHITE_ON);

			
			//Test
		/*	SegmentLED_Control(LRBNR_SEG_LED,1,ON);
			SegmentLED_Control(LFBNR_SEG_LED,2,ON);
			SegmentLED_Control(RRBNR_SEG_LED,3,ON);
			SegmentLED_Control(RFBNR_SEG_LED,4,ON);
			SegmentLED_Control(TIMER10_LED,9,ON);
			SegmentLED_Control(TIMER1_LED,0,ON);*/
			
			//LEDCOMControl();
			
		}
		if(suc1mscnt >= 5)//5ms?10ms?
		{
			suc1mscnt = 0;
			ReadTouch(TQ12_ID_VDD);
			ReadTouch(TQ12_ID_GND);
			
			//if(gucTouchKey == POWER_KEY) break;
			//TouchJob();
		}
		
		//100msJob
		if(guc100msFlag == SET)
		{
			guc100msFlag = CLR;
			suc100mscnt++;
			
			if(gucTouchKey == POWER_KEY)
			{
			//	gucTouchKey = NO_KEY;
				gucState = STATE_IDLE;
				break;
			}
			TouchJob();
		}
		if(suc100mscnt == 1) 
		{
			UARTComm(INVERTER_LEFT);		
		}
		else if(suc100mscnt == 2)
		{
			UARTComm(INVERTER_RIGHT);		
		}
		else
		{
			suc100mscnt = 0;
		}
	}
}
/**********************************************************************
 * @brief		Main program
 * @param[in]	None
 * @return	None
 **********************************************************************/
int main (void)
{
	 /* Initialize all port */
	Init();
//	Port_Init();

	/* Configure the system clock to HSE 8 MHz */
//	SystemClock_Config();

	
	while(1)
	{
		//PF STATE
		PF_STATE();
		//IDLE STATE
		IDLE_STATE();
		//RUN STATE
		RUN_STATE();
	}
	/* Infinite loop */
//	mainloop();


}

/* --------------------------------- End Of File ------------------------------ */
