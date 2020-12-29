#include <config.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <Hash.h>
#include <ESP8266mDNS.h>

#ifndef USE_SERIAL
#define USE_SERIAL Serial
#endif /* Serial */

#ifndef WIFI_SSID1
#define WIFI_SSID1 "AP-1"
#endif /* SSID */
#ifndef WIFI_SSID2
#define WIFI_SSID2 "AP-2"
#endif /* SSID */
#ifndef WIFI_SSID3
#define WIFI_SSID3 "AP-3"
#endif /* SSID */
#ifndef WIFI_SSID4
#define WIFI_SSID4 "AP-4"
#endif /* SSID */

#ifndef ESP_STA_SSID
#define ESP_STA_SSID "espchat"
#endif /* SSID */

#ifndef WIFI_PASSWORD1
#define WIFI_PASSWORD1 ""
#endif /* WIFI_PASSWORD */
#ifndef WIFI_PASSWORD2
#define WIFI_PASSWORD2 ""
#endif /* WIFI_PASSWORD */
#ifndef WIFI_PASSWORD3
#define WIFI_PASSWORD3 ""
#endif /* WIFI_PASSWORD */
#ifndef WIFI_PASSWORD4
#define WIFI_PASSWORD4 ""
#endif /* WIFI_PASSWORD */

#ifndef ESP_STA_PASSWORD
#define ESP_STA_PASSWORD ""
#endif /* SSID */

#ifndef HOSTNAME
#define HOSTNAME "espchat"
#endif /* WIFI_PASSWORD */


void WiFiBegin();
void MDNSLoop();
void CheckWiFi();