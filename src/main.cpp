#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

static int RGB_PIN = 48;
static int RGB_NUM = 1;

Adafruit_NeoPixel pixels(RGB_NUM, RGB_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
	pixels.begin();
	pixels.setBrightness(30);
}

void loop()
{
	pixels.setPixelColor(0, 0, 0, 255);
	pixels.show();
}