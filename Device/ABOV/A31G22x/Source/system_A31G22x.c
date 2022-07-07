/**************************************************************************//**
 * @file     system_A31G22x.c
 * @brief    CMSIS Cortex-M0+ Device Peripheral Access Layer Source File for
 *           Device A31G22x
 * @version  V1.00
 * @date     22 July 2020
 * @author   ABOV AE Team
 ******************************************************************************/
/* Copyright (c) 2012 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/


#include <stdint.h>
#include "A31G22x.h"
#include "system_A31G22x.h"


/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
   System Core Clock Variable
 *----------------------------------------------------------------------------*/
uint32_t    SystemCoreClock;     /**<  System Core Clock Frequency (Core Clock & HCLK) */
uint32_t    SystemPeriClock;     /**<  System Peripheral Clock Frequency (PCLK) */

/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------*//**
 * @brief         Update SystemCoreClock variable.
 * @return        None
 * @details       Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
 * @note          This function should be executed whenever the clock is changed.
 *//*-------------------------------------------------------------------------*/
void SystemCoreClockUpdate( void )      /* Get Core Clock Frequency */
{
	SystemCoreClock = LSI_CLOCK;  // System Code clock is set LSI clock
    SystemPeriClock = LSI_CLOCK;  // System Peripheral clock is set LSI clock
}

/*-------------------------------------------------------------------------*//**
 * @brief         Setup the microcontroller system.
 * @return        None
 * @details       Initialize the System and update the SystemCoreClock variable.
 *//*-------------------------------------------------------------------------*/
void SystemInit( void )
{
    __disable_irq();

    // disable WDT - default ON so you must turn off
    WDT->CR = 0
        |(0x5A69 << 16)
        |(0x25 << 10)
        |(0x1A << 4);

    SCU->CSCR = (SCU->CSCR & 0x000F0FF) | 0xA5070800U;  // Enables LSI oscillator and disables HSI, HSE, LSE
    SCU->SCCR = 0x570A0000U;  // Select LSI (500kHz)

    // flash memory controller
	CFMC->MR = 0x81;       // after changing 0x81 -> 0x28 in MR reg, flash access timing will be able to be set.
	CFMC->MR = 0x28;       // enter flash access timing changing mode
	CFMC->CFG = (0x7858 << CFMC_CFG_WTIDKY_Pos) | (3 << CFMC_CFG_WAIT_Pos);
	CFMC->MR = 0;	      // exit flash access timing --> normal mode       
}
