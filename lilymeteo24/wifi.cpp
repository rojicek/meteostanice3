#include <WiFi.h>
#include "secrets.h"  // hesla: viz secrets.h.example

const char* wifi_ap = WIFI_SSID;
const char* wifi_pd = WIFI_PASSWORD;

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
      Serial.println(" failed, giving up");
      return 1;
    }
  }
  Serial.println(".ok!");
  return 0;
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