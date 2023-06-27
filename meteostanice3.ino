#include "config.h"

#include <SPI.h>
#include <SD.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include <ESP32Time.h>
#include <ArduinoJson.h>
#include "time.h"



TTGOClass* ttgo;
const char *wifi_ap = "R_host";
const char *wifi_pd = "badenka5";
ESP32Time board_time(0); 


///////////////////////
int wifi_connect() {

  Serial.print("wifi");

  int max_tries = 30;

  WiFi.begin(wifi_ap, wifi_pd);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
    max_tries--;
    if (max_tries < 0) {
      Serial.println("failed, giving up");
      return 0;
    }
  }
  Serial.println("ok");
  return 1;
}

void wifi_disconnect() {
  WiFi.disconnect();
  int max_tries = 30;

  while ((WiFi.status() != WL_DISCONNECTED) && (max_tries > 0)) {
    delay(500);
    max_tries--;
    Serial.print("+");
  }

  Serial.println(" wifi disconnected (or not:)");
}


#define drawPixel(a, b, c) \
  ttgo->tft->setAddrWindow(a, b, a, b); \
  ttgo->tft->pushColor(c)



void setup() {
  Serial.begin(115200);
}

void loop() {
  //main
}