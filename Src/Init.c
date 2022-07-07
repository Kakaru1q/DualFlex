/**********************************************************************
* @file		Init.c
* @brief	DualFlex Display MCU Initial
* @version	1.00
* @date		28 MARCH 2022
* @author	P.W.K
*
**********************************************************************/

#include <string.h>
#include "Init.h"
#include "GlobalValue.h"

void	SystemClock_Config(void)
{
	__IO uint32_t cnt = 0, status;
	
	SCU->CMR &= ~(1<<7);	// disable MCLK monitoring
	HAL_SCU_HSI_ClockConfig(HSI_EN);	// enable HSI
	SCU->CSCR = 0xA5070000 | (SCU->CSCR & (~(0x7 << 4))) | (0x1 << 4);
	SCU->SCCR = 0x570A0000 | (SCU->SCCR & (~(0x1 << 2))) | (0x0 << 2);
	SCU->PLLCON = 0x00C71700;	// enable PLL
	do {	// wait PLL locking
		status = (SCU->PLLCON & (1UL<<31));
		cnt++;
	} while((cnt != PLL_STARTUP_TIMEOUT) && (status != (1UL<<31)));
	
	if (cnt < PLL_STARTUP_TIMEOUT) {
		SCU->PLLCON = 0x00E71700;	// PLL bypass disable
	}
	SCU->SCCR = 0x570A0000 | (SCU->SCCR & (~0x3)) | 0x3;
	SystemCoreClock = 48000000uL;
	SystemPeriClock = 48000000uL;
	
	SCU->MCCR1 = 0x02010301;
	SCU->MCCR2 = 0x02010201;
	SCU->MCCR3 = 0x00010001;
	SCU->MCCR4 = 0x02010201;
	SCU->MCCR5 = 0x00010001;


	
}

//------------------------------------------------------
void Init_GPIO(void)
{
	SCU->PER1 |= 0x3F00;	// Enable ports
	SCU->PCER1 |= 0x3F00;	// Enable port clocks
	PORT_ACCESS_EN();
	
	// GPIO-A --------------
	SCU->PER1 |= (1 << 8);
	SCU->PCER1 |= (1 << 8);
	PA->MOD = 0x00155000;
	PA->TYP = 0x00000000;
	PA->AFSR1 = 0x00000000;
	PA->AFSR2 = 0x00000000;
	PA->PUPD = 0x00000000;
	PA->DBCR = 0x00000000;
	
	// GPIO-B --------------
	SCU->PER1 |= (1 << 9);
	SCU->PCER1 |= (1 << 9);
	PB->MOD = 0x5555AA95;
	PB->TYP = 0x00000000;
	PB->AFSR1 = 0x11221000;
	PB->AFSR2 = 0x00000000;
	PB->PUPD = 0x00000000;
	PB->DBCR = 0x00000000;
	
	// GPIO-C --------------
	SCU->PER1 |= (1 << 10);
	SCU->PCER1 |= (1 << 10);
	PC->MOD = 0x00155555;
	PC->TYP = 0x00000000;
	PC->AFSR1 = 0x00000000;
	PC->AFSR2 = 0x00000000;
	PC->PUPD = 0x00000000;
	PC->DBCR = 0x00000000;
	
	// GPIO-D --------------
	SCU->PER1 |= (1 << 11);
	SCU->PCER1 |= (1 << 11);
	PD->MOD = 0x0000000A;
	PD->TYP = 0x00000003;
	PD->AFSR1 = 0x00000011;
	PD->AFSR2 = 0x00000000;
	PD->PUPD = 0x00000005;
	PD->DBCR = 0x00000000;
	
	// GPIO-E --------------
	SCU->PER1 |= (1 << 12);
	SCU->PCER1 |= (1 << 12);
	PE->MOD = 0x00005555;
	PE->TYP = 0x00000000;
	PE->AFSR1 = 0x00000000;
	PE->AFSR2 = 0x00000000;
	PE->PUPD = 0x00000000;
	PE->DBCR = 0x00000000;
	
	// GPIO-F --------------
	SCU->PER1 |= (1 << 13);
	SCU->PCER1 |= (1 << 13);
	PF->MOD = 0x00004000;
	PF->TYP = 0x00000000;
	PF->AFSR1 = 0x00000000;
	PF->AFSR2 = 0x00000000;
	PF->PUPD = 0x00000000;
	PF->DBCR = 0x00000000;
	//PF->PLSR = 0x??;	// TODO : Port F level
	PORT_ACCESS_DIS();
}

//------------------------------------------------------
void Init_UART1(void)
{
	//UART_CFG_Type UARTConfigStruct;
	
	
	memset((void*)&UARTConfigStruct, 0, sizeof(UARTConfigStruct));
	UARTConfigStruct.Baud_rate = (int)9600.000;
	UARTConfigStruct.Databits = UART_DATABIT_8;
	UARTConfigStruct.Parity = UART_PARITY_NONE;
	UARTConfigStruct.Stopbits = UART_STOPBIT_1;
	UARTConfigStruct.RxTxBuffer = 0;//NULL;
	UARTConfigStruct.TxBufferSize = 10;
	UARTConfigStruct.RxBufferSize = 10;
	HAL_UART_Init((UART_Type *)UART1, &UARTConfigStruct);
	
	HAL_UART_ConfigInterrupt((UART_Type *)UART1, UART_INTCFG_THRE, ENABLE);
	//HAL_UART_ConfigInterrupt((UART_Type *)UART1, UART_INTCFG_DR, ENABLE);
	NVIC_SetPriority(UART1_IRQn, 3);
	NVIC_EnableIRQ(UART1_IRQn);
}

//------------------------------------------------------
void Init_I2C0(void)
{
	SCU->PER2 |= (1 << 4);
	SCU->PCER2 |= (1 << 4);
	HAL_I2C_Init(I2C0, 200000);	//200kHz?	//200000
	I2C0->CR |= 0x0C;
	//I2C0->SCHR |= 0x00000075;							//0x00000075;
	HAL_I2C_SetOwnSlaveAddr0(I2C0, 0x00, DISABLE);
	HAL_I2C_SetOwnSlaveAddr0(I2C0, 0x00, DISABLE);
}

void Init_TIMER10(void)
{
	TIMER1n_CFG_Type TIMER1n_Config;
	
	HAL_SCU_Timer1n_ClockConfig(T1NCLK_PCLK);
	memset((void*)&TIMER1n_Config, 0, sizeof(TIMER1n_Config));
	//TIMER1n_Config.ExtClock = ENABLE;
	TIMER1n_Config.MatchInterrupt = ENABLE;
	TIMER1n_Config.PrescalerData = 100;
	TIMER1n_Config.AData = 48000;
	TIMER1n_Config.OutputPolarity = TIMER1n_OUTPUT_POLARITY_LOW;
	HAL_TIMER1n_Init((TIMER1n_Type *)TIMER10, TIMER1n_PERIODIC_MODE, &TIMER1n_Config);
	
	HAL_TIMER1n_ConfigInterrupt((TIMER1n_Type *)TIMER10, TIMER1n_INTCFG_MIE, ENABLE);
	NVIC_SetPriority(TIMER10_IRQn, 3);
	NVIC_EnableIRQ(TIMER10_IRQn);
	HAL_TIMER1n_ClearCounter(TIMER10);
	HAL_TIMER1n_Cmd((TIMER1n_Type *)TIMER10, ENABLE);
	HAL_TIMER1n_Start(TIMER10);
}

void Init_TIMER11(void)
{
	TIMER1n_CFG_Type TIMER1n_Config;
	
	HAL_SCU_Timer1n_ClockConfig(T1NCLK_PCLK);
	memset((void*)&TIMER1n_Config, 0, sizeof(TIMER1n_Config));
	//TIMER1n_Config.ExtClock = ENABLE;
	TIMER1n_Config.MatchInterrupt = ENABLE;
	TIMER1n_Config.PrescalerData = 1;
	TIMER1n_Config.AData = 48000;
	TIMER1n_Config.OutputPolarity = TIMER1n_OUTPUT_POLARITY_HIGH;
	HAL_TIMER1n_Init((TIMER1n_Type *)TIMER11, TIMER1n_PERIODIC_MODE, &TIMER1n_Config);
	
	HAL_TIMER1n_ConfigInterrupt((TIMER1n_Type *)TIMER11, TIMER1n_INTCFG_MIE, ENABLE);
	NVIC_SetPriority(TIMER11_IRQn, 3);
	NVIC_EnableIRQ(TIMER11_IRQn);
	HAL_TIMER1n_ClearCounter(TIMER11);
	HAL_TIMER1n_Cmd((TIMER1n_Type *)TIMER11, ENABLE);
	HAL_TIMER1n_Start(TIMER11);
}

void Init(void)
{
	
	/* Initialize System Clock */
	SystemClock_Config();
	
	Init_GPIO();
	Init_TIMER10();
	Init_TIMER11();
	Init_UART1();
	Init_I2C0();
	
	__enable_irq();
	
}
