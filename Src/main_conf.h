/***************************************************************************//**
* @file     main_conf.h
* @brief    Contains all macro definitions and function prototypes
*           support for Example Code on A31G22x
*
*
* @version  1.00
* @date     2020-12-28
* @author   MDS Team
*
* Copyright(C) 2020, ABOV Semiconductor
* All rights reserved.
*
*//****************************************************************************/

#ifndef __A31G22x_CONF_H
#define __A31G22x_CONF_H

/* Includes ----------------------------------------------------------------- */
/* Uncomment the line below to enable peripheral header file inclusion */

#include "A31G22x.h"
#include "A31G22x_hal_aa_types.h"
#include "debug_frmwrk.h"
#include "A31G22x_libcfg.h"
#include "A31G22x_hal_adc.h"
#include "A31G22x_hal_crc.h"
#include "A31G22x_hal_i2c.h"
#include "A31G22x_hal_pcu.h"
#include "A31G22x_hal_pwr.h"
#include "A31G22x_hal_scu.h"
#include "A31G22x_hal_timer1n.h"
#include "A31G22x_hal_timer2n.h"
#include "A31G22x_hal_timer3n.h"
#include "A31G22x_hal_uartn.h"
#include "A31G22x_hal_usart1n.h"
#include "A31G22x_hal_spi.h"
#include "A31G22x_hal_wdt.h"
#include "A31G22x_hal_wt.h"
#include "A31G22x_hal_cmp.h"
#include "A31G22x_hal_dac.h"
#include "A31G22x_hal_ts.h"
#include "A31G22x_hal_lcd.h"

//#include "A31G22x_it.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Private typedef ---------------------------------------------------------- */
/* Private define ----------------------------------------------------------- */
/* Private macro ------------------------------------------------------------ */
/* Private variables -------------------------------------------------------- */
/* Private define ----------------------------------------------------------- */


/* Private function prototypes ---------------------------------------------- */

/* Initialize all port */
void Init( void );

/* Configure the system clock to 40MHz */
void SystemClock_Config( void );

/* SysTick_ExceptionHandler_IT */
void SysTick_ExceptionHandler_IT( void );

#ifdef __cplusplus
}
#endif

#endif   /* __A31G22x_CONF_H */

