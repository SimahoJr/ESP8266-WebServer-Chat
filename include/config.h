// SOME CONFIG HERE

/*
The Websocket is just for transport,
The server is an HTTP server
The websocket is used to receive data from various connections
The data(HTML/CSS/Javascript/Images) are stored in the File System
using littleFS
The File System is used in the ServerEvents.cpp to retrive the files and 
send to the browser.
The main.cpp also used the "Small.FS" to test the working of the FS
*/

#define USE_SERIAL Serial
#define BAUD 115200

// WiFi Station Mode
#define ESP_STA_PASSWORD ""
#define ESP_STA_SSID "espchat"

// mdns host name
#define HOSTNAME "espchat"

// WiFi ConnectMode
#define WIFI_SSID1 "Crazy Engineer's"
#define WIFI_PASSWORD1 "Alita:Battle Angel1"
// #define WIFI_SSID2 "xxx"
// #define WIFI_PASSWORD2 "xxxx"
// #define WIFI_SSID3 ""
// #define WIFI_PASSWORD3 "xxxxx"
// #define WIFI_SSID4 "xxxxxx"
// #define WIFI_PASSWORD4 "xx"

// change the port on the web(websocket) also on the data folder
// The script js.js and the index.html
#define SERVER_PORT 5000
#define WEBSOCKET_PORT 8080
