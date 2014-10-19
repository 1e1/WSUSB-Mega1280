#ifndef DEBUG_H_
#define DEBUG_H_


#define DEBUG         1

/** DEBUGGING TOOLS **/
#if DEBUG
  #define LOG(...)    Serial.print  (__VA_ARGS__)
  #define LOGLN(...)  Serial.println(__VA_ARGS__)
  #define WAIT(ms)    delay(ms)
#endif
/** === **/


#endif