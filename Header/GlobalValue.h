//======================================================
// File Name : GlobalValue.h
// Device name : A31G22x
// Made by P.W.K
//======================================================

#include "main_conf.h"
#include "typedefine.h"


#define STATE_PF			0
#define STATE_IDLE		1
#define STATE_RUN		2

#define ON		1
#define OFF		0
#define SET		1
#define CLR		0

#define LEFT	0
#define RIGHT	1

#define LR_BNR 0
#define LF_BNR 1
#define RR_BNR 2
#define RF_BNR 3

#define WHITE_ON	2
#define	BLUE_ON		3

#define IDLE		0
#define NORMAL	1
#define LONG		2

#define ALL_LED		0xFF
#define BLINK			0XFF

#define I2CDATA		63

#define INVERTER_LEFT		0
#define INVERTER_RIGHT 	1

#define INVTX_LENGTH			10

typedef enum {
	NON_LED = 0,
	POWER_LED,
	LOCK_LED,	
	PAUSE_LED,
	BOOST_LED,
	AUTOPOT_LED,
	TIMER_LED,
	TIMER_PLUS_LED,
	TIMER_MINUS_LED,
	LRBNR_DOT_LED,
	LFBNR_DOT_LED,
	RRBNR_DOT_LED,
	RFBNR_DOT_LED,
	LRBNR_SEG_LED,
	LFBNR_SEG_LED,
	RRBNR_SEG_LED,
	RFBNR_SEG_LED,
	PL_0_LED,
	PL_1_LED,
	PL_2_LED,
	PL_3_LED,
	PL_4_LED,
	PL_5_LED,
	PL_6_LED,
	PL_7_LED,
	PL_8_LED,
	PL_9_LED,
	FLEX_LEFT_LED,
	FLEX_RIGHT_LED,
	LRBNR_LEFT_LED0,
	LRBNR_LEFT_LED1,
	LRBNR_RIGHT_LED0,
	LRBNR_RIGHT_LED1,
	LFBNR_LEFT_LED0,
	LFBNR_LEFT_LED1,
	LFBNR_RIGHT_LED0,
	LFBNR_RIGHT_LED1,
	RRBNR_LEFT_LED0,
	RRBNR_LEFT_LED1,
	RRBNR_RIGHT_LED0,
	RRBNR_RIGHT_LED1,
	RFBNR_LEFT_LED0,
	RFBNR_LEFT_LED1,
	RFBNR_RIGHT_LED0,
	RFBNR_RIGHT_LED1,
	TIMER10_LED,
	TIMER1_LED,
	LRBNR_BAR_LED0,
	LRBNR_BAR_LED1,
	LFBNR_BAR_LED0,
	LFBNR_BAR_LED1,
	RRBNR_BAR_LED0,
	RRBNR_BAR_LED1,
	RFBNR_BAR_LED0,
	RFBNR_BAR_LED1
}LED;

typedef enum {
	NO_KEY = 0,
	POWER_KEY,
	LOCK_KEY,
	PAUSE_KEY,
	BOOST_KEY,
	AUTOPOT_KEY,
	TIMER_KEY,
	TIMER_PLUS_KEY,
	TIMER_MINUS_KEY,
	PL_0_KEY,
	PL_1_KEY,
	PL_2_KEY,
	PL_3_KEY,
	PL_4_KEY,
	PL_5_KEY,
	PL_6_KEY,
	PL_7_KEY,
	PL_8_KEY,
	PL_9_KEY,
	FLEX_LEFT_KEY,
	FLEX_RIGHT_KEY,
	LRBNR_KEY,
	LFBNR_KEY,
	RRBNR_KEY,
	RFBNR_KEY,
	POWER_LONG_KEY
}KEY;

typedef enum {
	PL_0 = 0,
	PL_1,
	PL_2,
	PL_3,
	PL_4,
	PL_5,
	PL_6,
	PL_7,
	PL_8,
	PL_9,
	BOOST
}PL;

extern UINT8 gucState;

extern UINT8 guc100ms_PF_Flag;
extern UINT8 guc100ms_LEDCOM_Flag;
extern UINT8 guc100msFlag;
extern UINT8 guc1msFlag;

extern UINT8 guc100msCnt;
extern UINT8 guc1msCnt;

extern UINT16 gunTestCnt;

extern UINT8 gucI2CData1[I2CDATA];
extern UINT8 gucI2CData2[I2CDATA];
extern UINT8 gucTouchData[I2CDATA];
extern UINT8 gucTouchKey;

extern UINT8 gucKeyProcessingFlag;

extern UINT8 gaucInvTXBuffer[10];
extern UINT8 gucTxCnt;

extern UINT8 gaucBNRSelectFlag[4];
extern UINT8 gucLockFlag;
extern UINT8 gucAutoPotSetFlag;
extern UINT8 gucPauseFlag;
extern UINT8 gaucFlexFlag[2];
extern UINT8 gucBoostFlag;

extern UINT8 gaucPowerLevel[4];

extern UART_CFG_Type UARTConfigStruct;
