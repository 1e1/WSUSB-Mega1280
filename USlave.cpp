#include "USlave.h"




/***********************************************************
 *                         PUBLIC                          *
 **********************************************************/




USlave::USlave(const unsigned long baud)
{
  this->_serial = &Serial;
  this->_serial->begin(baud);
}


USlave::USlave(const unsigned long baud, const uint8_t interface)
{
  switch(interface) {
    case 0:
      #if defined(UBRRH) || defined(UBRR0H)
        this->_serial = &Serial;
      #elif defined(USBCON)
        this->_serial = &Serial_;
      #endif
      break;

    case 1:
      #if defined(UBRR1H)
        this->_serial = &Serial1;
      #endif
      break;

    case 2:
      #if defined(UBRR2H)
        this->_serial = &Serial2;
      #endif
      break;

    case 3:
      #if defined(UBRR3H)
        this->_serial = &Serial3;
      #endif
      break;
  }

  this->_serial->begin(baud);
}


void USlave::check()
{
  if (this->_serial->available()) {
    Core::setStream(this->_serial);
    Core::processLine();

    Core::unbuffer();
    Core::stateToBuffer();
    Core::copyToBuffer('\n');
    Core::sendBuffer();
  }
}


void USlave::clean()
{
  this->_serial->flush();
}