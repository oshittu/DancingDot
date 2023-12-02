// This simple program  places a pixel in the center of the 0.96" oled display module, and
// then allows the user to move the pixel around using the joystick module. :)
// if u want the pixel to have a cute tail that shows where its been, comment line 37 :D
// - Tomi :)

// SETUP FOR DISPLAY
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  
Adafruit_SSD1306 display(128, 32, &Wire, OLED_RESET);


// SETUP FOR JOYSTICK
#define VRX_PIN A0  // Arduino pin connected to VRX pin
#define VRY_PIN A1  // Arduino pin connected to VRY pin

int xValue = 0;  // To store value of the X axis
int yValue = 0;  // To store value of the Y axis

int px = 128 / 2;
int py = 32 / 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  display.clearDisplay();
  
  //read x and y vals
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

    if (xValue == 0)
      if(px>1)
      px--;

    if (xValue == 1023)
     if(px<1020)
      px++;

    if (yValue == 0)
      if(py<30)
      py++;

    if (yValue == 1023)
      if(py>1)
      py--;

    display.drawPixel(px, py, SSD1306_WHITE);
    display.display();
}
