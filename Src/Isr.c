/**********************************************************************
* @file		ISR.c
* @brief	DualFlex Display Main
* @version	1.00
* @date		28 MARCH 2022
* @author	P.W.K
*
**********************************************************************/

#include "GlobalValue.h"

UINT8 testflag1 = 0;
UINT8 testflag2 = 0;

void UART1_IRQHandler_INV(void)
{
	UINT8 ucIIR = 0;
	UINT8 ucIID = 0;
	
	ucIIR = UART1->IIR;
	ucIID = (ucIIR & UART_IIR_BITMASK);                  /*!< Get UART Interrupt status */
	
	// Transmit Holding Empty
	if(ucIID == UART_IIR_INTID_THRE)
	{
			if(gucTxCnt < INVTX_LENGTH - 1)
			{
				gucTxCnt++;
				UART1->THR = gaucInvTXBuffer[gucTxCnt];
				
			}
			else
			{
				gucTxCnt = 0;
			}
			
	}
	
	// Receive Data
	if (ucIID == UART_IIR_INTID_RDA)
	{
		
	}
}


//100ms
void TIMER10_IRQHandler(void)
{
	TIMER1n_Type *p = TIMER10;	
	if (HAL_TIMER1n_GetStatus(p) & TIMER1n_STATUS_MATCH_INT)
	{
		
		guc100msFlag = SET;
		guc100ms_PF_Flag = SET;
		
		testflag1 ^= 1;
		if(testflag1 == SET)
		{
			PA->BSR |= 0x0200;
		//	PA->OUTDR |= 0x0200;
		}
		else
		{
			PA->BCR |= 0x0200; 
		//	PA->OUTDR |= 0x0200;
		}
		HAL_TIMER1n_ClearStatus(p, TIMER1n_STATUS_MATCH_INT);
	}
	if (HAL_TIMER1n_GetStatus(p) & TIMER1n_STATUS_CAPTURE_INT)
	{
		//TO DO: Add your code from here.
		
		HAL_TIMER1n_ClearStatus(p, TIMER1n_STATUS_CAPTURE_INT);
	}
}

//1ms ... 2ms?
void TIMER11_IRQHandler(void)
{
	TIMER1n_Type *p = TIMER11;	
	if (HAL_TIMER1n_GetStatus(p) & TIMER1n_STATUS_MATCH_INT)
	{
		//Match Int.
		
		guc1msFlag = SET;
		
	
		
		guc1msCnt++;
		if(guc1msCnt >= 100)
		{
			
			guc1msCnt = 0;
		}
		
		HAL_TIMER1n_ClearStatus(p, TIMER1n_STATUS_MATCH_INT);
	}
	if (HAL_TIMER1n_GetStatus(p) & TIMER1n_STATUS_CAPTURE_INT)
	{
		
		HAL_TIMER1n_ClearStatus(p, TIMER1n_STATUS_CAPTURE_INT);
	}
}



//UART
void UART1_IRQHandler(void)
{
//	UART_Type	*p = (UART_Type*)UART1;
//	UART_Handler(p);
	UART1_IRQHandler_INV();
	
	testflag2 ^= 1;
		if(testflag2 == SET)
		{
			PA->BSR |= 0x0400;
		//	PA->OUTDR |= 0x0400;
		}
		else
		{
			PA->BCR |= 0x0400;
		//	PA->OUTDR |= 0x0400;
		}
}


/******************************************************************************/
/*            Cortex M3 Processor Exceptions Handlers                         */
/******************************************************************************/
void NMI_Handler(void) {

}

void HardFault_Handler(void) {

  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

void SVC_Handler(void) {

}

void PendSV_Handler(void) {

}

void SysTick_Handler(void) {

}

/* SYSTEM */
void LVI_IRQHandler(void) {

}

void SYSCLKFAIL_IRQHandler(void) {

}

/* GPIO */
void GPIOAB_IRQHandler(void) {

}

void GPIOCD_IRQHandler(void) {

}

void GPIOE_IRQHandler(void) {

}

void GPIOF_IRQHandler(void) {

}

/* TIMERS */

void TIMER12_IRQHandler(void) {

}

void TIMER13_IRQHandler(void) {

}

void TIMER14_IRQHandler(void) {

}

void TIMER15_IRQHandler(void) {

}

void TIMER16_IRQHandler(void) {

}

void TIMER20_IRQHandler(void) {

}

void TIMER21_IRQHandler(void) {

}

void TIMER30_IRQHandler(void) {

}

void WDT_IRQHandler(void) {

}

void WT_IRQHandler(void) {

}

/* SERIAL INTERFACES */
void I2C0_IRQHandler(void) {

}

void I2C1_IRQHandler(void) {

}

void I2C2_SPI20_IRQHandler(void) {

}

void USART10_IRQHandler(void) {
//    USART_Handler(USART10);
}

void USART11_IRQHandler(void) {
 //   USART_Handler(USART11);
}

#if defined(USART12) || defined(UART13)
void USART12_13_SPI21_IRQHandler(void) {
#ifdef USART12
//	USART_Handler(USART12);
#endif
#ifdef USART13
//	USART_Handler(USART13);
#endif    
}
#endif

void UART0_IRQHandler(void) {
//	HAL_UART_Handler(UART0);
//    UART0_IRQHandler_Interrupt();
}



/* ANALOG FUNCTIONS */
void ADC_IRQHandler(void) {

}

void DAC_IRQHandler(void) {

}

void TEMP_SENSOR_IRQHandler(void) {

}

void CMP_CRC_IRQHandler(void) {

}

