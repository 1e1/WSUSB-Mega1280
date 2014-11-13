/** 
  * READ: <pinNumber> '=' <value> ('&' <pinNumber> '=' <value>)*
  * 
  */

#ifndef USLAVE_H_
#define USLAVE_H_

#include <Arduino.h>
#include <CoreSlave.h>
#include "config.h"



class USlave {

  public:
  __attribute__((always_inline)) static inline void begin()                 { Serial.begin(USB_SPEED); LOGLN("listen USB"); };
  static void check();
  __attribute__((always_inline)) static inline void uncheck()               { Serial.flush(); };

};




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


#endif
