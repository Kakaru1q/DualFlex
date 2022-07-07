/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include "cortexm/ExceptionHandlers.h"

// ----------------------------------------------------------------------------

void __attribute__((weak))	Default_IRQHandler(void);

// Forward declaration of the specific IRQ handlers. These are aliased
// to the Default_IRQHandler, which is a 'forever' loop. When the application
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//
// TODO: Rename this and add the actual routines here.

void __attribute__ ((weak, alias ("Default_IRQHandler")))	LVI_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	SYSCLKFAIL_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	WDT_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	GPIOAB_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	GPIOCD_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	GPIOE_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	GPIOF_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	TIMER10_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	TIMER11_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	TIMER12_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	I2C0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	USART10_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	WT_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	TIMER30_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	I2C1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	TIMER20_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	TIMER21_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	USART11_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	ADC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	UART0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	UART1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	TIMER13_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	TIMER14_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	TIMER15_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	TIMER16_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	I2C2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	USART12_13_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	DAC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	TEMP_SENSOR_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_IRQHandler")))	CMP_CRC_IRQHandler(void);

// ----------------------------------------------------------------------------

extern unsigned int _estack;

typedef void
(* const pHandler)(void);

// ----------------------------------------------------------------------------

// The vector table.
// This relies on the linker script to place at correct location in memory.

__attribute__ ((section(".isr_vector"),used))
pHandler __isr_vectors[] =
  { //
    (pHandler) &_estack,                          // The initial stack pointer
        Reset_Handler,                            // The reset handler

        NMI_Handler,                              // The NMI handler
        HardFault_Handler,                        // The hard fault handler

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
        MemManage_Handler,                        // The MPU fault handler
        BusFault_Handler,// The bus fault handler
        UsageFault_Handler,// The usage fault handler
#else
        0, 0, 0,				  // Reserved
#endif
        0,                                        // Reserved
        0,                                        // Reserved
        0,                                        // Reserved
        0,                                        // Reserved
        SVC_Handler,                              // SVCall handler
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
        DebugMon_Handler,                         // Debug monitor handler
#else
        0,					  // Reserved
#endif
        0,                                        // Reserved
        PendSV_Handler,                           // The PendSV handler
        SysTick_Handler,                          // The SysTick handler

        // ----------------------------------------------------------------------
        // A31G22x vectors
		LVI_IRQHandler,     		//         /*!<  0: LVI						*/
		SYSCLKFAIL_IRQHandler,  	//         /*!<  1: SYSCLKFAIL				*/
		WDT_IRQHandler,   			//         /*!<  2: WDT						*/
		GPIOAB_IRQHandler,      	//         /*!<  3: GPIOAB					*/
		GPIOCD_IRQHandler,      	//         /*!<  4: GPIOCD					*/
		GPIOE_IRQHandler,      		//         /*!<  5: GPIOE					*/
		GPIOF_IRQHandler,      		//         /*!<  6: GPIOF					*/
		TIMER10_IRQHandler,      	//         /*!<  7: TIMER10					*/
		TIMER11_IRQHandler,      	//         /*!<  8: TIMER11					*/
		TIMER12_IRQHandler,      	//         /*!<  9: TIMER12					*/
		I2C0_IRQHandler,      		//         /*!< 10: I2C0					*/
		USART10_IRQHandler,      	//         /*!< 11: USART10					*/
		WT_IRQHandler,      		//         /*!< 12: WT						*/
		TIMER30_IRQHandler,      	//         /*!< 13: TIMER30					*/
		I2C1_IRQHandler,      		//         /*!< 14: I2C1					*/
		TIMER20_IRQHandler,     	//         /*!< 15: TIMER20					*/
		TIMER21_IRQHandler,       	//         /*!< 16: TIMER21					*/
		USART11_IRQHandler,       	//         /*!< 17: USART11					*/
		ADC_IRQHandler,       		//         /*!< 18: ADC						*/
		UART0_IRQHandler,       	//         /*!< 19: UART0					*/
		UART1_IRQHandler,       	//         /*!< 20: UART1					*/
		TIMER13_IRQHandler,       	//         /*!< 21: TIMER13					*/
		TIMER14_IRQHandler,     	//         /*!< 22: TIMER14					*/
		TIMER15_IRQHandler,     	//         /*!< 23: TIMER15					*/
		TIMER16_IRQHandler,        	//         /*!< 24: TIMER16					*/
		I2C2_IRQHandler,        	//         /*!< 25: I2C2					*/
		USART12_13_IRQHandler,     	//         /*!< 26: USART12/13				*/
		DAC_IRQHandler,        		//         /*!< 27: DAC						*/
		TEMP_SENSOR_IRQHandler,		//         /*!< 28: TEMP_SENSOR				*/
		Default_IRQHandler,     	//         /*!< 29:							*/
		Default_IRQHandler,     	//         /*!< 30:							*/
		CMP_CRC_IRQHandler,     	//         /*!< 31: CMP_CRC					*/
    };

// ----------------------------------------------------------------------------

// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.

void __attribute__ ((section(".after_vectors"))) Default_IRQHandler(void)
{
  while (1)
    {
    }
}

// ----------------------------------------------------------------------------
