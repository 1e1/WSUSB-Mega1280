/** 
  * READ: <pinNumber> '=' <value> ('&' <pinNumber> '=' <value>)*
  * 
  */

#ifndef USLAVE_H_
#define USLAVE_H_

#include <Arduino.h>
#include <CoreSlave.h>



//#define USB_SPEED     115200
//#define USB_SPEED     9600



class USlave : public Circuit {

  public:
  USlave(const unsigned long baud);
  USlave(const unsigned long baud, const uint8_t interface);

  void check();
  inline void clean();

  protected:
  HardwareSerial* _serial;

};


#endif
