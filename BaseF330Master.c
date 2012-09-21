//-----------------------------------------------------------------------------
// F33x_SMBus_Master_Multibyte.c
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "I2CLib.h"
#include "UARTLIB.h"
#include "BaseLib.h"

//-----------------------------------------------------------------------------
// Global VARIABLES
//-----------------------------------------------------------------------------

sbit LED = P1^3;                       // LED on port P1.3
// Buffers for data from the slave module
char Date[SIZE_GETDATE];
char Latitude[SIZE_GETLAT];
char Longitude[SIZE_GETLONG];
int AccX,AccY,AccZ;

//-----------------------------------------------------------------------------
// MAIN Routine
//-----------------------------------------------------------------------------
//
// Main routine performs all configuration tasks, then loops forever sending
// and receiving SMBus data to the slave.
//

void main (void)
{
  int id;
  
  SysInit();     
  
  // Reset Error Counter
  NUM_ERRORS = 0;
  LED = 1;
  StartACC();
  id = GetAccID();
  
  while (1) {
    SendWord("Attente d'une consigne de position\n",35);
    LED = 1;
    SendWord("R�cup�ration de l'ID\n",21);
    id = getID();
    if (id == 42) {
      SendWord("Id Ok\n",6);
      LED = 0;
      T0_Waitms(50000);
    }
    if (id == -1) {
      LED = 0;
      T0_Waitms (100);
      SendWord("Id Error\n",9);
    }
    
    GetDate();
    GetLatitude();
    GetLongitude();
    SendCoords();
    GetAccX();
    SendChar((AccX/256));
    SendChar((AccY/256));
    SendChar((AccZ/256));
    
    T0_Waitms (10000);
  }
  
  
  
}

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------