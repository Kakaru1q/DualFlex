//======================================================
// File Name : LEDControl.h
// Device name : A31G226
// Made by P.W.K
//======================================================
#include "main_conf.h"
#include "typedefine.h"

#define LF        0x0A //New Line
#define CR        0x0D //Carriage  return
#define SPC       0x20 //Space

// Sensitivity level (threshold, Register Value X 0.1% = (1 Step=0.1%)              
#define Sensitivity1    0x02 //ch1,Default: 0x07 X 0.1% = 0.70% (threshold)
#define Sensitivity2    0x03 //ch2
#define Sensitivity3    0x04 //ch3
#define Sensitivity4    0x05 //ch4
#define Sensitivity5    0x06 //ch5
#define Sensitivity6    0x07 //ch6
#define Sensitivity7    0x08 //ch7
#define Sensitivity8    0x09 //ch8
#define Sensitivity9    0x0A //ch9
#define Sensitivity10   0x0B //ch10
#define Sensitivity11   0x0C //ch11
#define Sensitivity12   0x0D //ch12

#define CTRL1  0x0E //System Control Register 1 (BF Mode, FTC, SingleMode, RTC)
#define CTRL2  0x0F //CDisTimeOpt, CSImpSel, SW Reset, Sleep, FastRespMode, FastRespEn)
#define Output1	0x10 //Touch Output Data Register 1Byte (OUT8~OUT1)
#define Output2	0x11 //Touch Output Data Register 1Byte (OUT8~OUT1)

#define Channel_Reset1	0x12 // Channel Reset Register(ch8~ch1),
//0: Enable Operation(Sensing + Calibration), 
//1: Reset Operation (No Sensing + Reset  Calibration)

#define Channel_Reset2	0x13 // Channel Reset Register(ch12~ch9),
//0: Enable Operation(Sensing + Calibration), 
//1: Reset Operation (No Sensing + Reset  Calibration)

#define Calibration_Hold1	0x14 // Calibration Holde Register(ch8~ch1),
//0: Enable Reference Calibration (Sensing + Calibration), 
//1: Disable Reference Calibration ( Sensing + No Calibration)

#define Calibration_Hold2	0x15 // Calibration Holde Register(ch12~ch9),
//0: Enable Reference Calibration (Sensing + Calibration), 
//1: Disable Reference Calibration ( Sensing + No Calibration)

#define Error_Percnet	0x29 //Error Percent Register
//ErrModeOpt, ErrMode_Diable, ErrPcntOpt

#define CR_Cal_Speed	0x2A //CR Channel Calibration Speed Control Register
#define CS_Cal_Speed	0x2B //CS Channel Calibration Speed Control Register

#define Sleep_Time_Control	0x2C //Sleep Time Control Register

#define CR_Cap_Control	0x30 //CR Channel Internal Capacitaice Register
#define CS1_Cap_Control	0x31 //CS1 Channel Internal Capacitaice Register
#define CS2_Cap_Control	0x32 //CS2 Channel Internal Capacitaice Register
#define CS3_Cap_Control	0x33 //CS3 Channel Internal Capacitaice Register
#define CS4_Cap_Control	0x34 //CS4 Channel Internal Capacitaice Register
#define CS5_Cap_Control	0x35 //CS4 Channel Internal Capacitaice Register
#define CS6_Cap_Control	0x36 //CS6 Channel Internal Capacitaice Register
#define CS7_Cap_Control	0x37 //CS7 Channel Internal Capacitaice Register
#define CS8_Cap_Control	0x38 //CS8 Channel Internal Capacitaice Register
#define CS9_Cap_Control	0x39 //CS9 Channel Internal Capacitaice Register
#define CS10_Cap_Control	0x3A //CS10 Channel Internal Capacitaice Register
#define CS11_Cap_Control	0x3B //CS11 Channel Internal Capacitaice Register
#define CS12_Cap_Control	0x3C //CS12 Channel Internal Capacitaice Register

#define Voltage_Threshold_Control1	0x3D //Voltage_Threshold_Control1 Register
#define Voltage_Threshold_Control2	0x3E //Voltage_Threshold_Control2 Register

#define Lock_OP_Enable	0x59 //I2C Write Lock Operation Control Register
#define Lock_Byte	0x5A 	//I2C Write Lock Operation Control Register

#define CTRL3	0x5B 	//System Control Register 3

// =============== TQ12 I2C Chip Slave Address ================================================
#define TQ12_ID_GND  0x68 //7bit address: 8bit address 0xD0>>1, 0b1101000(7bit) + 0/1(W/R bit)
// ID_SEL Pin = GND (Default)
#define TQ12_ID_VDD  0x78 //7bit address: 8bit address 0xF0>>1 //ID_SEL Pin = VDD
// =============== TQ12 I2C Chip Slave Address ================================================

#define RESET_PIN 7 //Reset pin
#define EN_PIN    6 //I2C Enable Pin

void InitTQ12(UINT8 ucSlaveID); //Initialize TQ12
void ReadTouch(UINT8 ucDeviceID);
void TouchJob(void);

