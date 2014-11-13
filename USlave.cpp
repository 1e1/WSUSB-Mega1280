#include "USlave.h"




/***********************************************************
 *                         PUBLIC                          *
 **********************************************************/




USlave::USlave()
{
  Serial.begin(USB_SPEED);
  LOGLN("listen USB");
}


USlave::~USlave()
{
}


void USlave::check()
{
  if (Serial.available()) {
    LOGLN(">>> USB");
    
    Core::setStream(&Serial);
    Core::processLine();
    
    Core::unbuffer();
    Core::stateToBuffer();
    Core::copyToBuffer('\n');
    Core::sendBuffer();
    
    LOGLN("<<< USB");
  }
}