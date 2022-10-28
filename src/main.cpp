#include <Arduino.h>
#include <USB.h>
#include <USBHIDKeyboard.h>

#define FIRST_CLICK_MS      20000
#define SECOND_CLICK_MS     25000

USBHIDKeyboard Keyboard;

bool waitHigh = true;
unsigned long now = 0;

bool
  firstClick = false,
  secondClick = false;

void setup() {
  Keyboard.begin();
  USB.begin();
}

void clickEnter() {
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}

void loop() {
  now = millis();

  if (!firstClick && now >= FIRST_CLICK_MS) {
    firstClick = true;
    clickEnter();
  }
  if (!secondClick && now >= SECOND_CLICK_MS) {
    secondClick = true;
    clickEnter();
  }

  if (firstClick && secondClick) {
    // do nothing
    while (true) delay(100000);
  }
}
