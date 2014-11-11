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
    Warehouse_FOREACHPP(PinoutSchedule, Core::schedules, element)
      USlave::statusLine(element);
    Warehouse_ENDFOREACHPP
    // pulses
    Core::copyToBuffer_P(PSTR("\n=== PULSES ===\n"));
    Warehouse_FOREACHPP(PinoutPulse, Core::pulses, element)
      USlave::statusLine(element);
    Warehouse_ENDFOREACHPP
    // digitals
    Core::copyToBuffer_P(PSTR("\n=== DIGITALS ===\n"));
    Warehouse_FOREACHPP(PinoutDigital, Core::digitals, element)
      USlave::statusLine(element);
    Warehouse_ENDFOREACHPP
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

