#ifndef __BASELIB__H_
#define __BASELIB__H_


//-----------------------------------------------------------------------------
// Libs
//-----------------------------------------------------------------------------
#include <C8051F330.h>
#include "Protocole.h"
#include <string.h>


//-----------------------------------------------------------------------------
// Global CONSTANTS
//-----------------------------------------------------------------------------

#define  SYSCLK         24500000       // System clock frequency in Hz
#define  BAUDRATE          19200       // Baud rate of UART in bps


// 16-bit SFR declarations
sfr16    TMR3RL   = 0x92;              // Timer3 reload registers
sfr16    TMR3     = 0x94;              // Timer3 counter registers


//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------

void SysInit(void);
void Timer0_Init (void);
void Timer3_Init (void);
void Port_Init (void);
void T0_Waitms (unsigned char ms);

extern char Date[SIZE_GETDATE];
extern char Latitude[SIZE_GETLAT];
extern char Longitude[SIZE_GETLONG];
extern int AccX,AccY,AccZ;


#endif //BASELIB