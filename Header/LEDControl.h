//======================================================
// File Name : LEDControl.h
// Device name : A31G226
// Made by P.W.K
//======================================================

#include "main_conf.h"
#include "typedefine.h"


void LEDControl(UINT8 ucLED, UINT8 ucstate);
void SegmentLED_Control(UINT8 ucLoc, UINT8 ucNum, UINT8 ucState);
void LEDCOMControl(void);
