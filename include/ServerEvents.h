#include <Arduino.h>
#include <ESP8266WebServer.h>
#include "SmallFS.h"
#include "templates.h"
#include "config.h"


#ifndef USE_SERIAL
#define USE_SERIAL Serial
#endif /* Serial */

#ifndef SERVER_PORT
#define SERVER_PORT 80
#endif /* SERVER_PORT */


void ServerEventsBegin();
void LittleFS_testing();
void ServerEventsLoop();
void handleNotFound();
void handleIndex();
void handleChat();
void handleCSS();
void handleJS();
void handleLOGO();
void handleAPI();
void handleESP();
void handleMinJS();