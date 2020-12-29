#include <WebSocketEvents.h>

WebSocketsServer webSocket = WebSocketsServer(WEBSOCKET_PORT);

void WebSocketEventsBegin(){
    webSocket.onEvent(WebSocketEvent);
    webSocket.begin();
}

void WebSocketEventsLoop(){
    webSocket.loop();
}

void WebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

    switch(type) {
        case WStype_DISCONNECTED:
            USE_SERIAL.printf("[%u] Disconnected!\n", num);
            break;
        case WStype_CONNECTED:
            {
                IPAddress ip = webSocket.remoteIP(num);
                USE_SERIAL.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
				
				// send message to client
				webSocket.sendTXT(num, "Connected to ESP8266");
            }
            break;
        case WStype_TEXT:
            {
            USE_SERIAL.printf("[%u] get Text: %s\n", num, payload);

            // send message to 
            // webSocket.sendTXT(num, payload);

            // send data to all connected clients
            webSocket.broadcastTXT(payload);
            }
            break;
        case WStype_BIN:
            {
            USE_SERIAL.printf("[%u] get binary length: %u\n", num, length);
            hexdump(payload, length);

            // send message to client
            // webSocket.sendBIN(num, payload, length);
            }
            break;
    }

}