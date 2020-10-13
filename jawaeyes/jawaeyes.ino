#include <Adafruit_CircuitPlayground.h>


#define PIN_LEFT_EYE  12
#define PIN_RIGHT_EYE  6
#define NUM_PIXELS     6 

Adafruit_CPlay_NeoPixel leftEye (NUM_PIXELS, PIN_LEFT_EYE, NEO_GRBW + NEO_KHZ800);
Adafruit_CPlay_NeoPixel rightEye (NUM_PIXELS, PIN_RIGHT_EYE, NEO_GRBW + NEO_KHZ800);

static uint32_t const RED_ORANGE = 0xFF33m00;

void blink(Adafruit_CPlay_NeoPixel& eye)
{
  eye.clear();
  eye.show();
  delay(100);
  eye.setPixelColor(0, RED_ORANGE);
  eye.show();
  delay(300);
  for (int i = 1; i < NUM_PIXELS; ++i) {
    eye.setPixelColor(i, RED_ORANGE);
  }
  eye.show();
}

void setup() {
  CircuitPlayground.begin();

  leftEye.begin();
  leftEye.show(); // all off
  leftEye.setBrightness(64);
  rightEye.begin();
  rightEye.show(); // all off
  rightEye.setBrightness(64);

  delay(1000);
  blink(leftEye);
  delay(1000);
  blink(rightEye);
}

void loop() {
  delay(random(100,2000));
  if (random(255) > 127) {
    blink(leftEye);
  } else {
    blink(rightEye);
  }
}
