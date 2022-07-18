/**********************************************************************
* @file		LEDControl.c
* @brief	DualFlex Display Main
* @version	1.00
* @date		28 MARCH 2022
* @author	P.W.K
*
**********************************************************************/

#include "GlobalValue.h"
#include "LEDControl.h"

UINT16 gaunSegment[10] = {
	0x003F, 	//	0
	0x0006,		//	1
	0x005B,		//	2
	0x004F,		//	3
	0x0066,		//	4
	0x006D,		//	5
	0x007D,		//	6
	0x0027,		//	7
	0x007F,		//	8
	0x006F,		//	9
};


void LED_BAR_Control(UINT8 ucLED, UINT8 ucState, UINT16 unComReg)
{
	switch(ucLED)
	{
		case LRBNR_BAR_LED0 :	
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					//if(unComReg & 0x01)		//PC5
					//{
						PC->BSR |= 0x0020;
					//}
					//else
					//{
					//		;
					//}
			}
			else	//OFF
			{
						PC->BCR |= 0x0020;
			}
			break;
		case LRBNR_BAR_LED1 :	
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					//if(unComReg & 0x01)		//PC4
					//{
						PC->BSR |= 0x0010;
					//}
					//else
					//{
					//		;
					//}
			}
			else	//OFF
			{
						PC->BCR |= 0x0010;
			}
			break;
		case LFBNR_BAR_LED0 :	
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
			//		if(unComReg & 0x02)		//PC3
			//		{
						PC->BSR |= 0x0008;
			//		}
			//		else
			//		{
			//				;
			//		}
			}
			else	//OFF
			{
						PC->BCR |= 0x0008;
			}
			break;
		case LFBNR_BAR_LED1 :	
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
			//		if(unComReg & 0x02)		//PC2
			//		{
						PC->BSR |= 0x0004;
			//		}
			//		else
			//		{
			//				;
			//		}
			}
			else	//OFF
			{
						PC->BCR |= 0x0004;
			}
			break;			
		case RRBNR_BAR_LED0 :	
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
			//		if(unComReg & 0x04)		//PC9
			//		{
						PC->BSR |= 0x0200;
			//		}
			//		else
			//		{
			//				;
			//		}
			}
			else	//OFF
			{
						PC->BCR |= 0x0200;
			}
			break;	
		case RRBNR_BAR_LED1 :	
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
			//		if(unComReg & 0x04)		//PC8
			//		{
						PC->BSR |= 0x0100;
			//		}
			//		else
			//		{
			//				;
			//		}
			}
			else	//OFF
			{
						PC->BCR |= 0x0100;
			}
			break;	
		case RFBNR_BAR_LED0 :	
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
			//		if(unComReg & 0x08)		//PC7
			//		{
						PC->BSR |= 0x0080;
			//		}
			//		else
			//		{
			//				;
			//		}
			}
			else	//OFF
			{
						PC->BCR |= 0x0080;
			}
			break;
		case RFBNR_BAR_LED1 :	
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
			//		if(unComReg & 0x08)		//PC6
			//		{
						PC->BSR |= 0x0040;
			//		}
			//		else
			//		{
			//				;
			//		}
			}
			else	//OFF
			{
						PC->BCR |= 0x0040;
			}
			break;			
			
		default :
			//LED_BAR_Control(ucLED,ucState,unComReg);
			break;
	}
}

void LED_Control_PL(UINT8 ucLED, UINT8 ucState, UINT16 unComReg)
{
	switch(ucLED)
	{
		case PL_0_LED :	//PL1
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x01)		//PC10
					{
						PC->BSR |= 0x0400;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PC->BCR |= 0x0400;
			}
			break;
		case PL_1_LED :	//PL0
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x01)		//PC10
					{
						PC->BSR |= 0x0400;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PC->BCR |= 0x0400;
			}
			break;
		case PL_2_LED :	//PL3
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x02)		//PC10
					{
						PC->BSR |= 0x0400;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PC->BCR |= 0x0400;
			}
			break;
		case PL_3_LED :	//PL2
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x02)		//PC10
					{
						PC->BSR |= 0x0400;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PC->BCR |= 0x0400;
			}
			break;			
		case PL_4_LED :	//PL5
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x04)		//PC10
					{
						PC->BSR |= 0x0400;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PC->BCR |= 0x0400;
			}
			break;	
		case PL_5_LED :	//PL4
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x04)		//PC10
					{
						PC->BSR |= 0x0400;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PC->BCR |= 0x0400;
			}
			break;	
		case PL_6_LED :	//PL7
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x08)		//PC10
					{
						PC->BSR |= 0x0400;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PC->BCR |= 0x0400;
			}
			break;
		case PL_7_LED :	//PL6
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x08)		//PC10
					{
						PC->BSR |= 0x0400;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PC->BCR |= 0x0400;
			}
			break;			
		case PL_8_LED :	//PL9
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x10)		//PC10
					{
						PC->BSR |= 0x0400;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PC->BCR |= 0x0400;
			}
			break;
		case PL_9_LED :	//PL8
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x10)		//PC10
					{
						PC->BSR |= 0x0400;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PC->BCR |= 0x0400;
			}
			break;				
		default :
			LED_BAR_Control(ucLED,ucState,unComReg);
			break;
	}
}


void LED_TIMER_SET_Control(UINT8 ucLED, UINT8 ucState, UINT16 unComReg)
{
	switch(ucLED)
	{
		case LRBNR_DOT_LED :
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x80)		//PB12
					{
						PB->BSR |= 0x1000;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PB->BCR |= 0x1000;
			}
			break;
		case LFBNR_DOT_LED :
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x80)		//PB13
					{
						PB->BSR |= 0x2000;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PB->BCR |= 0x2000;
			}
			break;
		case RRBNR_DOT_LED :
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x80)		//PB14
					{
						PB->BSR |= 0x4000;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PB->BCR |= 0x4000;
			}
			break;
		case RFBNR_DOT_LED :
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x80)		//PB15
					{
						PB->BSR |= 0x8000;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PB->BCR |= 0x8000;
			}
			break;
		case TIMER_MINUS_LED :
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x80)		//PC0
					{
						PC->BSR |= 0x0001;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PC->BCR |= 0x0001;
			}
			break;
		case TIMER_PLUS_LED :
			if(ucState == ON || ucState == BLUE_ON || ucState == WHITE_ON)	
			{
					if(unComReg & 0x80)		//PC1
					{
						PC->BSR |= 0x0002;
					}
					else
					{
							;
					}
			}
			else	//OFF
			{
						PC->BCR |= 0x0002;
			}
			break;
	
		default :
			LED_Control_PL(ucLED,ucState,unComReg);
			break;
	}
}

void LED17_23_Control(UINT8 ucLED, UINT8 ucState, UINT16 unComReg)
{
	switch(ucLED)
	{
		case FLEX_RIGHT_LED :
				if(ucState == ON)	
				{
					if(unComReg & 0x01)
					{
						PB->BSR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == BLUE_ON)	//PB10
				{			
					if(unComReg & 0x01)
					{
						PB->BSR |= 0x0400;
						PB->BCR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == WHITE_ON)		//PB11
				{
					if(unComReg & 0x01)
					{
						PB->BCR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else	//OFF
				{
						PB->BCR |= 0x0400;
						PB->BCR |= 0x0800;
				}
			break;
		case RRBNR_RIGHT_LED0 :
				if(ucState == ON)	
				{
					if(unComReg & 0x02)
					{
						PB->BSR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == BLUE_ON)	//PB10
				{			
					if(unComReg & 0x02)
					{
						PB->BSR |= 0x0400;
						PB->BCR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == WHITE_ON)		//PB11
				{
					if(unComReg & 0x02)
					{
						PB->BCR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else	//OFF
				{
						PB->BCR |= 0x0400;
						PB->BCR |= 0x0800;
				}
			break;
		case RRBNR_RIGHT_LED1 :
				if(ucState == ON)	
				{
					if(unComReg & 0x04)
					{
						PB->BSR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == BLUE_ON)	//PB10
				{			
					if(unComReg & 0x04)
					{
						PB->BSR |= 0x0400;
						PB->BCR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == WHITE_ON)		//PB11
				{
					if(unComReg & 0x04)
					{
						PB->BCR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else	//OFF
				{
				//		PB->BSR |= 0x0400;
				//		PB->BCR |= 0x0800;
				}
			break;
		case RFBNR_RIGHT_LED0 :
				if(ucState == ON)	
				{
					if(unComReg & 0x08)
					{
						PB->BSR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == BLUE_ON)	//PB10
				{			
					if(unComReg & 0x08)
					{
						PB->BSR |= 0x0400;
						PB->BCR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == WHITE_ON)		//PB11
				{
					if(unComReg & 0x08)
					{
						PB->BCR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else	//OFF
				{
						PB->BCR |= 0x0400;
						PB->BCR |= 0x0800;
				}
			break;
		case RFBNR_RIGHT_LED1 :
				if(ucState == ON)	
				{
					if(unComReg & 0x10)
					{
						PB->BSR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == BLUE_ON)	//PB10
				{			
					if(unComReg & 0x10)
					{
						PB->BSR |= 0x0400;
						PB->BCR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == WHITE_ON)		//PB11
				{
					if(unComReg & 0x10)
					{
						PB->BCR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else	//OFF
				{
						PB->BCR |= 0x0400;
						PB->BCR |= 0x0800;
				}
			break;
		case TIMER_LED :
				if(ucState == ON)	
				{
					if(unComReg & 0x20)
					{
						PB->BSR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == BLUE_ON)	//PB10
				{			
					if(unComReg & 0x20)
					{
						PB->BSR |= 0x0400;
						PB->BCR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == WHITE_ON)		//PB11
				{
					if(unComReg & 0x20)
					{
						PB->BCR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else	//OFF
				{
						PB->BCR |= 0x0400;
						PB->BCR |= 0x0800;
				}
			break;
		case BOOST_LED :
				if(ucState == ON)	
				{
					if(unComReg & 0x40)
					{
						PB->BSR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == BLUE_ON)	//PB10
				{			
					if(unComReg & 0x40)
					{
						PB->BSR |= 0x0400;
						PB->BCR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else if(ucState == WHITE_ON)		//PB11
				{
					if(unComReg & 0x40)
					{
						PB->BCR |= 0x0400;
						PB->BSR |= 0x0800;
					}
					else
					{
					//	PB->BCR |= 0x0400;
					//	PB->BCR |= 0x0800;
					}
				}
				else	//OFF
				{
						PB->BCR |= 0x0400;
						PB->BCR |= 0x0800;
				}
			break;

		default :
			LED_TIMER_SET_Control(ucLED,ucState,unComReg);
			break;
	}
}

void LED9_16_Control(UINT8 ucLED, UINT8 ucState, UINT16 unComReg)
{
	switch(ucLED)
	{
		case LRBNR_RIGHT_LED0 :
				if(ucState == ON)	
				{
					if(unComReg & 0x01)
					{
						PB->BSR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == BLUE_ON)	//PB8
				{			
					if(unComReg & 0x01)
					{
						PB->BCR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == WHITE_ON)		//PB2
				{
					if(unComReg & 0x01)
					{
						PB->BSR |= 0x0100;
						PB->BCR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else	//OFF
				{
						PB->BCR |= 0x0100;
						PB->BCR |= 0x0004;
				}
			break;
		case LRBNR_RIGHT_LED1 :
				if(ucState == ON)	
				{
					if(unComReg & 0x02)
					{
						PB->BSR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == BLUE_ON)	//PB8
				{			
					if(unComReg & 0x02)
					{
						PB->BCR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == WHITE_ON)		//PB2
				{
					if(unComReg & 0x02)
					{
						PB->BSR |= 0x0100;
						PB->BCR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else	//OFF
				{
						PB->BCR |= 0x0100;
						PB->BCR |= 0x0004;
				}
			break;
		case LFBNR_RIGHT_LED0 :
				if(ucState == ON)	
				{
					if(unComReg & 0x04)
					{
						PB->BSR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == BLUE_ON)	//PB8
				{			
					if(unComReg & 0x04)
					{
						PB->BCR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == WHITE_ON)		//PB2
				{
					if(unComReg & 0x04)
					{
						PB->BSR |= 0x0100;
						PB->BCR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else	//OFF
				{
					PB->BCR |= 0x0100;
					PB->BCR |= 0x0004;
				}
			break;
		case LFBNR_RIGHT_LED1 :
				if(ucState == ON)	
				{
					if(unComReg & 0x08)
					{
						PB->BSR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == BLUE_ON)	//PB8
				{			
					if(unComReg & 0x08)
					{
						PB->BCR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == WHITE_ON)		//PB2
				{
					if(unComReg & 0x08)
					{
						PB->BSR |= 0x0100;
						PB->BCR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else	//OFF
				{
						PB->BCR |= 0x0100;
						PB->BCR |= 0x0004;
				}
			break;
		case RRBNR_LEFT_LED0 :
				if(ucState == ON)	
				{
					if(unComReg & 0x10)
					{
						PB->BSR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == BLUE_ON)	//PB8
				{			
					if(unComReg & 0x10)
					{
						PB->BCR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == WHITE_ON)		//PB2
				{
					if(unComReg & 0x10)
					{
						PB->BSR |= 0x0100;
						PB->BCR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else	//OFF
				{
						PB->BCR |= 0x0100;
						PB->BCR |= 0x0004;
				}
			break;
		case RRBNR_LEFT_LED1 :
				if(ucState == ON)	
				{
					if(unComReg & 0x20)
					{
						PB->BSR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == BLUE_ON)	//PB8
				{			
					if(unComReg & 0x20)
					{
						PB->BCR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == WHITE_ON)		//PB2
				{
					if(unComReg & 0x20)
					{
						PB->BSR |= 0x0100;
						PB->BCR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else	//OFF
				{
						PB->BCR |= 0x0100;
						PB->BCR |= 0x0004;
				}
			break;
		case RFBNR_LEFT_LED0 :
				if(ucState == ON)	
				{
					if(unComReg & 0x40)
					{
						PB->BSR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == BLUE_ON)	//PB8
				{			
					if(unComReg & 0x40)
					{
						PB->BCR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == WHITE_ON)		//PB2
				{
					if(unComReg & 0x40)
					{
						PB->BSR |= 0x0100;
						PB->BCR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else	//OFF
				{
						PB->BCR |= 0x0100;
						PB->BCR |= 0x0004;
				}
			break;
		case RFBNR_LEFT_LED1 :
				if(ucState == ON)	
				{
					if(unComReg & 0x80)
					{
						PB->BSR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == BLUE_ON)	//PB8
				{			
					if(unComReg & 0x80)
					{
						PB->BCR |= 0x0100;
						PB->BSR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else if(ucState == WHITE_ON)		//PB2
				{
					if(unComReg & 0x80)
					{
						PB->BSR |= 0x0100;
						PB->BCR |= 0x0004;
					}
					else
					{
					//	PB->BCR |= 0x0100;
					//	PB->BCR |= 0x0004;
					}
				}
				else	//OFF
				{
					PB->BCR |= 0x0100;
					PB->BCR |= 0x0004;
				}
			break;
		default :
			LED17_23_Control(ucLED,ucState,unComReg);
			break;
	}
}		

void LED1_8_Control(UINT8 ucLED, UINT8 ucState, UINT16 unComReg)
{
	switch(ucLED)
	{
		case AUTOPOT_LED :
				if(ucState == ON)	
				{
					if(unComReg & 0x01)
					{
						PA->BSR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == BLUE_ON)	//PA7
				{			
					if(unComReg & 0x01)
					{
						PA->BSR |= 0x0080;
						PB->BCR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == WHITE_ON)		//PB0
				{
					if(unComReg & 0x01)
					{
						PA->BCR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else	//OFF
				{
					PA->BCR |= 0x0080;
					PB->BCR |= 0x0001;
				}
			break;
		case LOCK_LED :
				if(ucState == ON)	
				{
					if(unComReg & 0x02)
					{
						PA->BSR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == BLUE_ON)	//PA7
				{			
					if(unComReg & 0x02)
					{
						PA->BSR |= 0x0080;
						PB->BCR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == WHITE_ON)		//PB0
				{
					if(unComReg & 0x02)
					{
						PA->BCR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else	//OFF
				{
					PA->BCR |= 0x0080;
					PB->BCR |= 0x0001;
				}
			break;
		case PAUSE_LED :
				if(ucState == ON)	
				{
					if(unComReg & 0x04)
					{
						PA->BSR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == BLUE_ON)	//PA7
				{			
					if(unComReg & 0x04)
					{
						PA->BSR |= 0x0080;
						PB->BCR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == WHITE_ON)		//PB0
				{
					if(unComReg & 0x04)
					{
						PA->BCR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else	//OFF
				{
					PA->BCR |= 0x0080;
					PB->BCR |= 0x0001;
				}
			break;
		case LRBNR_LEFT_LED0 :
				if(ucState == ON)	
				{
					if(unComReg & 0x08)
					{
						PA->BSR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == BLUE_ON)	//PA7
				{			
					if(unComReg & 0x08)
					{
						PA->BSR |= 0x0080;
						PB->BCR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == WHITE_ON)		//PB0
				{
					if(unComReg & 0x08)
					{
						PA->BCR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else	//OFF
				{
					PA->BCR |= 0x0080;
					PB->BCR |= 0x0001;
				}
			break;
		case LRBNR_LEFT_LED1 :
				if(ucState == ON)	
				{
					if(unComReg & 0x10)
					{
						PA->BSR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == BLUE_ON)	//PA7
				{			
					if(unComReg & 0x10)
					{
						PA->BSR |= 0x0080;
						PB->BCR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == WHITE_ON)		//PB0
				{
					if(unComReg & 0x10)
					{
						PA->BCR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else	//OFF
				{
					PA->BCR |= 0x0080;
					PB->BCR |= 0x0001;
				}
			break;
		case LFBNR_LEFT_LED0 :
				if(ucState == ON)	
				{
					if(unComReg & 0x20)
					{
						PA->BSR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == BLUE_ON)	//PA7
				{			
					if(unComReg & 0x20)
					{
						PA->BSR |= 0x0080;
						PB->BCR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == WHITE_ON)		//PB0
				{
					if(unComReg & 0x20)
					{
						PA->BCR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else	//OFF
				{
					PA->BCR |= 0x0080;
					PB->BCR |= 0x0001;
				}
			break;
		case LFBNR_LEFT_LED1 :
				if(ucState == ON)	
				{
					if(unComReg & 0x40)
					{
						PA->BSR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == BLUE_ON)	//PA7
				{			
					if(unComReg & 0x40)
					{
						PA->BSR |= 0x0080;
						PB->BCR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == WHITE_ON)		//PB0
				{
					if(unComReg & 0x40)
					{
						PA->BCR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else	//OFF
				{
					PA->BCR |= 0x0080;
					PB->BCR |= 0x0001;
				}
			break;
		case FLEX_LEFT_LED :
				if(ucState == ON)	
				{
					if(unComReg & 0x80)
					{
						PA->BSR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == BLUE_ON)	//PA7
				{			
					if(unComReg & 0x80)
					{
						PA->BSR |= 0x0080;
						PB->BCR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else if(ucState == WHITE_ON)		//PB0
				{
					if(unComReg & 0x80)
					{
						PA->BCR |= 0x0080;
						PB->BSR |= 0x0001;
					}
					else
					{
					//	PA->BCR |= 0x0080;
					//	PB->BCR |= 0x0001;
					}
				}
				else	//OFF
				{
					PA->BCR |= 0x0080;
					PB->BCR |= 0x0001;
				}
			break;
		default :
			LED9_16_Control(ucLED,ucState,unComReg);
			break;
	}
}

void LEDControl(UINT8 ucLED, UINT8 ucState)	//ON,White,Blue,OFF
{
	UINT16 unComReg = 0;
	
	unComReg = PE->OUTDR;
	
	LED1_8_Control(ucLED,ucState,unComReg);
	
	
	if(ucLED == ALL_LED && ucState == ON)
	{
		//PA6, PA7
		PA->BSR |= 0x00C0;
		
		//PB0 ~ PB2, PB8 ~ PB15
		PB->BSR |= 0xFF07;
		
		//PC0 ~ PC10
		PC->BSR |= 0x07FF;
		
		//PE0 ~ PE7 (COM Port)
		PE->BSR |= 0x00FF;
	}
	else if(ucLED == ALL_LED && ucState == OFF)
	{
		//PA6, PA7
		PA->BCR |= 0x00C0;
		
		//PB0 ~ PB2, PB8 ~ PB15
		PB->BCR |= 0xFF07;
		
		//PC0 ~ PC10
		PC->BCR |= 0x07FF;
		
		//PE0 ~ PE7 (COM Port)
		PE->BCR |= 0x00FF;
	}

}

void SegLEDRegister_Control(UINT8 ucLoc, UINT8 ucState)
{
	if(ucState == ON)
	{
		switch(ucLoc)
		{
			case LRBNR_SEG_LED : //PB12		
				PB->BSR |= 0x1000;
				break;
			case LFBNR_SEG_LED : //PB13
				PB->BSR |= 0x2000;
				break;
			case RRBNR_SEG_LED : //PB14	
				PB->BSR |= 0x4000;
				break;
			case RFBNR_SEG_LED : //PB15
				PB->BSR |= 0x8000;
				break;
			case TIMER10_LED : //PC0
				PC->BSR |= 0x0001;
				break;
			case TIMER1_LED : //PC1
				PC->BSR |= 0x0002;
				break;
		}
	}
	else if(ucState == OFF)
	{
		switch(ucLoc)
		{
			case LRBNR_SEG_LED : //PB12		
				PB->BCR |= 0x1000;
				break;
			case LFBNR_SEG_LED : //PB13			
				PB->BCR |= 0x2000;
				break;
			case RRBNR_SEG_LED : //PB14			
				PB->BCR |= 0x4000;
				break;
			case RFBNR_SEG_LED : //PB15		
				PB->BCR |= 0x8000;
				break;
			case TIMER10_LED : //PC0		
				PC->BCR |= 0x0001;
				break;
			case TIMER1_LED : //PC1		
				PC->BCR |= 0x0002;
				break;
		}
	}
}

void SegmentLED_Control(UINT8 ucLoc, UINT8 ucNum, UINT8 ucState)
{
	UINT16 unComReg = 0;
	
	unComReg = PE->OUTDR;
	
	if(ucState == ON)
	{
		if((gaunSegment[ucNum] & unComReg))	//type
		{
			SegLEDRegister_Control(ucLoc,ON);		
		}
		else
		{
			SegLEDRegister_Control(ucLoc,OFF);
		}
	}
	else if(ucState == OFF)
	{
		SegLEDRegister_Control(ucLoc,OFF);
	}
}
void ALLSEGPinOFF(void)
{
	PA->BCR |= 0x0080; //PA7
	PB->BCR |= 0xFD05; //PB0 ~ PB15
	PC->BCR |= 0x07FF; //PC0 ~ PC10
}
void LEDCOMControl(void)		//1msJob
{
	static UINT8 sucCnt = 0;
	static UINT16 sunComReg = 0;
	
	
	PE->BCR |= sunComReg;	//COMOff
	ALLSEGPinOFF();				//SEGOff

	sunComReg = (UINT16)(1 << sucCnt); //type
	PE->BSR |= sunComReg;	//COMOn
	sucCnt++;
	if(sucCnt > 7) sucCnt = 0;
	
}
