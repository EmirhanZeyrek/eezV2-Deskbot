#include <Arduino.h>
#include <U8g2lib.h>
#include "eyes.h"

#define LDR_PIN A0
#define MIC_PIN A1
#define TOUCH_PIN 7 
#define BUZZER_PIN 6
#define SERVO_PIN 3 

// Display setup (Page buffer mode)
U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// Initialize robot object
robotEyes eyes(u8g2, LDR_PIN, TOUCH_PIN, BUZZER_PIN, MIC_PIN, SERVO_PIN);

void setup() {
  Serial.begin(9600); 
  Serial.println("eezv2 MiniBot started...");
  
  // Wait for power to stabilize
  delay(2000);

  // Initialize display
  u8g2.begin();
  
  // Initialize robot hardware
  eyes.begin(); 
}

void loop() {
  // Update logic
  eyes.update();
  
  // Render loop
  u8g2.firstPage();
  do {
    eyes.draw();
  } while (u8g2.nextPage());
}