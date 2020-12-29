#include <WebSocketsServer.h>
#include <config.h>


#ifndef USE_SERIAL
#define USE_SERIAL Serial
#endif /* Serial */

#ifndef WEBSOCKET_PORT
#define WEBSOCKET_PORT 81
#endif /* WEBSOCKET_PORT */

void WebSocketEventsBegin();
void WebSocketEventsLoop();
void WebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length);