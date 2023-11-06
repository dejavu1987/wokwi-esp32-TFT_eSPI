#include <TFT_eSPI.h>
#include <SPI.h>

// #define TFT_MISO 33
// #define TFT_MOSI 27
// #define TFT_SCLK 12
// #define TFT_CS 22
// #define TFT_RST 32
// #define TFT_DC 25
// #define TFT_BL 13

// #define TOUCH_CS 26

#define TFT_ROTATION 1

TFT_eSPI tft = TFT_eSPI(); 

void drawButton(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color, uint32_t outline, String label) 
{
  uint8_t r = min(w, h) / 4; // border radius

  tft.fillRoundRect(x, y, w, h, r, color);
  tft.drawRoundRect(x, y, w, h, r, outline);

  //Print the label
  tft.setTextColor(TFT_WHITE,color);
  tft.setTextSize(2);  
  uint8_t tempdatum = tft.getTextDatum();
  tft.setTextDatum(MC_DATUM);
  uint16_t tempPadding = tft.getTextPadding();
  tft.setTextPadding(0);

  tft.drawString(label, x + (w/2), y + (h/2));
  tft.setTextDatum(tempdatum);
  tft.setTextPadding(tempPadding);

}

void setup(void) {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(TFT_ROTATION);
}

void loop() {
  drawButton((tft.width()-200)/2, (tft.height()-80)/2, 200, 80, TFT_BLUE,
                     TFT_WHITE, "My Button");
  delay(10000);
}