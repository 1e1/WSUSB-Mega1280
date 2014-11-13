#include "USlave.h"




/***********************************************************
 *                         PUBLIC                          *
 **********************************************************/




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