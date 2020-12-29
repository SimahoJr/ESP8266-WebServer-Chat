#include <connections.h>

MDNSResponder mdns;
ESP8266WiFiMulti WiFiMulti;


const uint32_t connectTimeoutMs = 5000;
int wifi_flag = 0;
int no_wifi_flag = 0;

void WiFiBegin(){

     // Set WiFi to accesspoing mode
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ESP_STA_SSID, ESP_STA_PASSWORD);

    // Register multi WiFi networks
    WiFiMulti.addAP(WIFI_SSID1, WIFI_PASSWORD1);
    // WiFiMulti.addAP(WIFI_SSID2, WIFI_PASSWORD2);
    // WiFiMulti.addAP(WIFI_SSID3, WIFI_PASSWORD3);
    // WiFiMulti.addAP(WIFI_SSID4, WIFI_PASSWORD4);
    // More is possible

    if (mdns.begin(HOSTNAME, WiFi.softAPIP())) {
        USE_SERIAL.println("MDNS responder started");
        mdns.addService("http", "tcp", SERVER_PORT);
        mdns.addService("ws", "tcp", WEBSOCKET_PORT);

        USE_SERIAL.println("Connect to:");
        USE_SERIAL.print("http://");
        USE_SERIAL.print(HOSTNAME);
        USE_SERIAL.println(".local");
        USE_SERIAL.print("http://");
        USE_SERIAL.print(WiFi.softAPIP());
        USE_SERIAL.print(":");
        USE_SERIAL.println(SERVER_PORT);

    }
    else {
        USE_SERIAL.println("MDNS.begin failed");
    }
}

void MDNSLoop(){
    MDNS.update();
}

void CheckWiFi(){
    // SeeSaw Thingy
    // TODO:More to be done here for multiple SSID
    if (WiFiMulti.run(connectTimeoutMs) == WL_CONNECTED) {
        no_wifi_flag=0;
        if(wifi_flag==0){
            USE_SERIAL.println("");
            USE_SERIAL.print("Connected to ");
            USE_SERIAL.print("IP address: ");
            USE_SERIAL.println(WiFi.localIP());

            wifi_flag = 1;
        }
    }
    else{
        wifi_flag = 0;
        if(no_wifi_flag==0){
            USE_SERIAL.println("");
            USE_SERIAL.print("Disconnected");
            // USE_SERIAL.print("IP address: ");
            // USE_SERIAL.println(WiFi.localIP());

            no_wifi_flag=1;
        }
    }

}