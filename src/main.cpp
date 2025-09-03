#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <vector3.h>

const static int RGB_PIN = 48;
const static int RGB_NUM = 1;

Adafruit_NeoPixel pixels(RGB_NUM, RGB_PIN, NEO_GRB + NEO_KHZ800);

typedef Vector3<uint8_t> RGBColor;

void setup()
{
	pixels.begin();
	pixels.setBrightness(30);
}

RGBColor Zero(0, 0, 0);
RGBColor RGBMax(255, 255, 255);

const static int SWITCH_DELAY = 1000;
static int lastSwitchDestinationTime = -SWITCH_DELAY;
static RGBColor originColor = Zero;
static RGBColor targetColor = Zero;

RGBColor generateRGBColor()
{
	return RGBColor(random(0, 255), random(0, 255), random(0, 255));
}

void loop()
{
	if (millis() - lastSwitchDestinationTime > SWITCH_DELAY)
	{
		lastSwitchDestinationTime = millis();
		originColor = targetColor;
		targetColor = generateRGBColor();
	}

	// calculate time ratio
	float timeRatio = (millis() - lastSwitchDestinationTime) / (float)SWITCH_DELAY;
	// calculate current color
	RGBColor currentColor = originColor.lerp(targetColor, timeRatio);
	// set current color
	pixels.setPixelColor(0, currentColor.x, currentColor.y, currentColor.z);
	pixels.show();
}