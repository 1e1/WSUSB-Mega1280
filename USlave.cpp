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
    // schedules
    Core::copyToBuffer_P(PSTR("\n=== SCHEDULES ===\n"));
    // add IP info
    Warehouse_FOREACH(PinoutSchedule, Core::schedules, element)
      USlave::statusLine(element);
    Warehouse_ENDFOREACH
    // pulses
    Core::copyToBuffer_P(PSTR("\n=== PULSES ===\n"));
    Warehouse_FOREACH(PinoutPulse, Core::pulses, element)
      USlave::statusLine(element);
    Warehouse_ENDFOREACH
    // digitals
    Core::copyToBuffer_P(PSTR("\n=== DIGITALS ===\n"));
    Warehouse_FOREACH(PinoutDigital, Core::digitals, element)
      USlave::statusLine(element);
    Warehouse_ENDFOREACH
    // messages
    /*
    Core::copyToBuffer_P(PSTR("\n=== MESSAGES ===\n"));
    // add IP info
    for (uint8_t i=0; i < Core::messages_len; i++) {
      USlave::statusLine(Core::messages[i], Core::messages[i].getValue());
    }
    */
    Core::copyToBuffer('\n');
    Core::sendBuffer();
    
    LOGLN("<<< USB");
  }
}




/***********************************************************
 *                        PROTECTED                        *
 **********************************************************/




void USlave::statusLine(Pinout* pinout)
{
  Core::copyToBuffer(pinout->getPin());
  Core::copyToBuffer('\t');
  Core::copyToBuffer(pinout->getValue());
  Core::copyToBuffer('\t');
  Core::copyToBuffer_P(pinout->getLabel());
  Core::copyToBuffer('\n');
}

