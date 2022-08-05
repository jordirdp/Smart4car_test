
/* Project: Smart4car */
/* Author: Jordi Rodriguez */

// Incluye Headers:

#include "Pinout.h"
#include "Constants.h"

// Define LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 20, 4);


void setup() {

  // Inicia LCD
  lcd.init();
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("****Smart4car****");

  // Inicia motores


}


void loop() {
  
}

