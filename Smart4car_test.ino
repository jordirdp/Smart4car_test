
/* Project: Smart4car */
/* Author: Jordi Rodriguez */

// Incluye Headers
#include "Pinout.h"
#include "Constants.h"

// Define LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);

// Define ultrasonidos HC-SR04
#include <NewPing.h>
NewPing sonar (TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Define servo SG90
#include <Servo.h>
Servo myservo;



void setup() {

  // Inicia LCD
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("****Smart4car****");
  lcd.setCursor (0,1);
  lcd.print("---Modo Test----");
  delay (TiempoEspera);

  // Inicia motores
  Motores_init();

  // Inicia servo
  myservo.attach(SERVO_PIN);

  // Inicia sensores de línea
  pinMode (SENSOR_LL_PIN, INPUT);
  pinMode (SENSOR_L_PIN, INPUT);
  pinMode (SENSOR_R_PIN, INPUT);
  pinMode (SENSOR_RR_PIN, INPUT);

  // Inicia encoders
  interrupts();
  pinMode (ENCODER_L_PIN,INPUT_PULLUP);
  pinMode (ENCODER_R_PIN,INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt (ENCODER_L_PIN), Encoder_L, FALLING);
  attachInterrupt (digitalPinToInterrupt (ENCODER_R_PIN), Encoder_R, FALLING);
}



void loop() {

  // Prueba servo
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("***Test Servo***");
  lcd.setCursor (0,1);
  lcd.print("Angulo = ");
  for (pos = 0; pos < 180; pos++) {
    myservo.write(pos);
    lcd.setCursor(12, 1);
    lcd.print(pos);
    delay(30);
  }
  delay (100);
  for (byte i = 0; i < 2; i++) {
    myservo.write(0);
    delay(500);
    myservo.write(180);
    delay(500);
  }
  myservo.write(90);

  // Prueba sonar
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("***Test Sonar***");
  lcd.setCursor (0,1);
  lcd.print("Distancia = ");
  for (byte i = 0; i < 200; i++) {
    delay (100);
    lcd.setCursor(12, 1);
    lcd.print(sonar.ping_cm());
  }
  delay (TiempoEspera);

  // Prueba sensores de línea
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("***Test Linea***");
  for (byte i = 0; i <200; i++) {
    Sensor_LL= digitalRead (SENSOR_LL_PIN);
    lcd.setCursor (0,1);
    lcd.print(Sensor_LL);
    Sensor_L= digitalRead (SENSOR_L_PIN);
    lcd.setCursor (5,1);
    lcd.print(Sensor_L);
    Sensor_R= digitalRead (SENSOR_R_PIN);
    lcd.setCursor (10,1);
    lcd.print(Sensor_R);
    Sensor_RR= digitalRead (SENSOR_RR_PIN);
    lcd.setCursor (15,1);
    lcd.print(Sensor_RR);
  }
  delay (TiempoEspera);

  // Prueba motores
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("**Test Motores**");
  Avanza();
  delay (TiempoEspera);
  Retrocede();
  delay (TiempoEspera);
  Gira();
  delay (TiempoEspera);
  Para();

  // Prueba encoders
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("**Test Encoder**");
  for (byte i = 0; i <400; i++) {
    lcd.setCursor (0,1);
    lcd.print(Counter_L);
    lcd.setCursor (10,1);
    lcd.print(Counter_R);
  }
}


void Encoder_L() {
  Counter_L ++;
}

void Encoder_R() {
  Counter_R ++;
}


   

