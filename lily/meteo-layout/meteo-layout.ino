// https://tomeko.net/online_tools/file_to_hex.php?lang=en
//NEPOUZIVAT SMOOTH

#include <SPI.h>
#include <SD.h>

#include "config.h"

//fonty
#include "ubuntu_fonts.h"


TTGOClass* ttgo;

int w = 0;
int h = 0;

#define drawPixel(a, b, c) \
  ttgo->tft->setAddrWindow(a, b, a, b); \
  ttgo->tft->pushColor(c)

void drawPic(int x, int y, int h, int w, String pic) {
  File picFile = SD.open("/layout/sunset.raw", FILE_READ);

  if (picFile) {
    for (int i = x; i < x + w; i++) {
      for (int j = y; j < y + h; j++) {

        char rgb1 = picFile.read();
        char rgb2 = picFile.read();

        drawPixel(j, i, 256 * rgb1 + rgb2);
      }
    }
    close(picFile);
  } else {
    Serial.print("cant read ");
    Serial.println(pic);
  }
}

void setup() {
  Serial.begin(115200);

  //SD karta
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1)
      ;  // bacha - tohle je nekonecna smycka
  }
  Serial.println("initialization done.");

  ttgo = TTGOClass::getWatch();
  ttgo->begin();
  ttgo->openBL();
  ttgo->tft->setRotation(3);

  ttgo->tft->fillScreen(TFT_WHITE);

  ttgo->tft->loadFont(ubuntu_regular_18);
  ttgo->tft->setTextColor(TFT_BLACK);
  ttgo->tft->setCursor(15, 15);
  ttgo->tft->print("6:00");

  //printText()
  drawPic(15, 15, 35, 28, "/layout/sunset.raw");


  //cas
  /*
  ttgo->tft->loadFont(ubuntu_reg_25);
  ttgo->tft->setTextColor(TFT_BLACK);
  ttgo->tft->setCursor(300, 10);
  ttgo->tft->print("Aug 29, 18:58");

  ttgo->tft->loadFont(ubuntu_bold_45);
  ttgo->tft->setTextColor(TFT_BLACK);
  ttgo->tft->setCursor(10, 170);
  ttgo->tft->print("15°C");

  ttgo->tft->loadFont(ubuntu_reg_30);
  ttgo->tft->setTextColor(TFT_BLACK);
  ttgo->tft->setCursor(120, 180);
  ttgo->tft->print("25°C");
  */
}



void loop() {}