#include <Wire.h>               // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"        // legacy: #include "SSD1306.h"
SSD1306Wire display(0x3c, 21, 22);
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
pinMode(13,INPUT);
ledcSetup(0,5000,8);
ledcAttachPin(14,0);

  // Initialising the UI will init the display too.
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

}

void loop() {
  int input=analogRead(13);
   Serial.println(input);
  display.clear();
  display.setFont(ArialMT_Plain_24);
  String stringOne = String(input, DEC);
  display.drawString(0,12 , stringOne);
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "Value");
    display.display();
  
}
