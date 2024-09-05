#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#define INCLUDE_NOTIFICATION_MODULE
#include <Adafruit_GFX.h>
// #include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>
#include <DabbleESP32.h>
#include <SPI.h>

// MCU Main Controll

#define TFT_CS        4
#define TFT_RST       22 
#define TFT_DC        23

const int motorA1 = 32;
const int motorA2 = 33;
const int motorB1 = 27;
const int motorB2 = 26;
const int motorC1 = 15;
const int motorC2 = 21;
const int motorD1 = 16;
const int motorD2 = 17;

#define TFT_MOSI 13
#define TFT_SCLK 12

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup(void) {
  Dabble.begin("Fire Robot v1 - GCA8830");
  Serial.begin(9600);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorC1, OUTPUT);
  pinMode(motorC2, OUTPUT);
  pinMode(motorD1, OUTPUT);
  pinMode(motorD2, OUTPUT);

  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);

  tft.init(240, 320);
  tft.setSPISpeed(40000000);

  tft.invertDisplay(false);

  tft.fillScreen(ST77XX_BLACK);
  drawtext(20, 0, "_____________________________", ST77XX_WHITE, 1);
  drawtext(20, 20, "Fire Robot v1", ST77XX_RED, 2);
  drawtext(20, 40, "_____________________________", ST77XX_WHITE, 1);
  drawtext(20, 50, "Controll via Dabble", ST77XX_WHITE, 1);

  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);
  
  Dabble.waitForAppConnection();
  conected();

}

void loop() {
  Dabble.processInput();

  if (GamePad.isUpPressed()) {
    moveForward();
  } else if (GamePad.isDownPressed()) {
    moveBackward();
  } else if (GamePad.isLeftPressed()) {
    turnLeft();
  } else if (GamePad.isRightPressed()) {
    turnRight();
  } else {
    stopMotors();
  }

  if (GamePad.isTrianglePressed()) {
    activateBumpers();
  } else if (GamePad.isCrossPressed()) {
    stopBumpers();
  } else if (GamePad.isSquarePressed()) {
    refillBotle();
  } else if (GamePad.isCirclePressed()) {
    stopRefill();
  }
}

void drawtext(uint16_t x, uint16_t y, char *text, uint16_t color, uint8_t size) {
  tft.setCursor(x, y);
  tft.setTextSize(size);
  tft.setTextColor(color, ST77XX_BLACK);
  tft.setTextWrap(true);
  tft.print(text);
}


void moveForward() {
  // Motor Driver 1
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void moveBackward() {
  // Motor Driver 1
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void turnLeft() {
  // Motor Driver 1
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void turnRight() {
  // Motor Driver 1
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void stopMotors() {
  // Motor Driver 1
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

void activateBumpers() {
  // Motor Driver 2
  // digitalWrite(motorC1, HIGH);
  // digitalWrite(motorC2, LOW);
  digitalWrite(motorD1, HIGH);
  digitalWrite(motorD2, LOW);
}

void refillBotle() {
  // Motor Driver 2
  digitalWrite(motorC1, HIGH);
  digitalWrite(motorC2, LOW);
  // digitalWrite(motorD1, LOW);
  // digitalWrite(motorD2, HIGH);
}

void stopRefill() {
  digitalWrite(motorC1, LOW);
  digitalWrite(motorC2, LOW);
}

void conected() {
  drawtext(20, 0, "_____________________________", ST77XX_WHITE, 1);
  drawtext(20, 20, "Fire Robot v1", ST77XX_RED, 2);
  drawtext(20, 40, "_____________________________", ST77XX_WHITE, 1);
  drawtext(10, 50, "Controller Connected!", ST77XX_GREEN, 1);
  drawtext(10, 60, "", ST77XX_GREEN, 1);
  drawtext(10, 70, "Conect to 'Fire Robot - Camera'", ST77XX_WHITE, 1);
  drawtext(10, 80, "Password: 12345678", ST77XX_WHITE, 1);
  drawtext(10, 80, "Connect to view camera", ST77XX_WHITE, 1);
}

void lowlevel() {
  drawtext(10, 60, "Water level: LOW ", ST77XX_RED, 1);
  digitalWrite(14, HIGH);
}

void highlevel() {
  drawtext(10, 60, "Water level: HIGH", ST77XX_GREEN, 1);
  digitalWrite(14, LOW);
}

void stopBumpers() {
  // Motor Driver 2
  // digitalWrite(motorC1, LOW);
  // digitalWrite(motorC2, LOW);
  digitalWrite(motorD1, LOW);
  digitalWrite(motorD2, LOW);
}
