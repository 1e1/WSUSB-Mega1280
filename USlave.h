/** 
  * READ: <pinNumber> '=' <value> ('&' <pinNumber> '=' <value>)*
  * 
  */

#ifndef USLAVE_H_
#define USLAVE_H_

#include <Arduino.h>
#include <CoreSlave.h>
#include "config.h"



class USlave : public Circuit {

  public:
  static void check();
  __attribute__((always_inline)) static inline void clean()               { Serial.flush(); };

};


#endif
