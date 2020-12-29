#include "WebSocketEvents.h"
#include "ServerEvents.h"
#include "connections.h"
#include "config.h"

#ifndef BAUD
#define BAUD 115200
#endif /* BAUD */

void setup()
{
    USE_SERIAL.begin(BAUD);
    WiFiBegin();
    ServerEventsBegin();
    WebSocketEventsBegin();
    // the following piece of line is it neccsary
    LittleFS_testing();
}

void loop()
{ 
  CheckWiFi();
  WebSocketEventsLoop();
  ServerEventsLoop();
  // update mdns per connection
  MDNSLoop();
}