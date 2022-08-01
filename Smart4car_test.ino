
/* Project: Smart2car */
/* Author: Jordi Rodriguez */

// Definir bibliotecas:

#include "Pinout.h"
#include "Constants.h"

#include <NewPing.h>
NewPing sonar (TRIGGER_PIN, ECHO_PIN);

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 20, 4);

// Definir Pinout:

const uint8_t ECHO_PIN = 14; // = A0
const uint8_t TRIGGER_PIN = 15; // =A1

const uint8_t SENSOR_L = 16; // = A2
const uint8_t SENSOR_R = 4;

const uint8_t FOTOSENSOR = 17; // = A3

// I2C_LCD_SCA = A4;
// I2C_LCD_SCL = A5;

const uint8_t WHITE_R = 2;
const uint8_t WHITE_L = 13;
const uint8_t RED_R = 3;
const uint8_t RED_L = 12;

const uint8_t ENB = 5;
const uint8_t IN3 = 9;
const uint8_t IN4 = 10;

const uint8_t ENA = 6;
const uint8_t IN1 = 7;
const uint8_t IN2 = 8;

const uint8_t BUZZER = 11;

// Definir Constants:

const int STOP_DISTANCE = 50; // Distancia de obstáculo para permanecer parado
const int ATRAS_DISTANCE = 25; // Distancia de obstáculo para retroceder

const int Velocidad = 150;    // Velocidad máxima para motores

int Sensor_left = 0;
int Sensor_right = 0;

int Sensor_front = 0;

int Sensor_luz = 0;


void setup() {
  lcd.init();
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("****Smart2car****");
  
  Buzzer_init();
  Buzzer(2,100,100);

  Led_init(WHITE_R);
  Led_init(WHITE_L);
  Led_init(RED_R);
  Led_init(RED_L);
  for (byte i=0; i<3; i++){
    Led_wheel();
  }

  pinMode(SENSOR_L, INPUT);
  pinMode(SENSOR_R, INPUT);

  Motores_init();

  lcd.clear();
  lcd.setCursor (0,0);
}


void loop() {
  Lectura_sensores();
  Luces();
  Distancia();
  Linea();
}


// Funciones para Buzzer:

void Buzzer_init(){
  pinMode (BUZZER, OUTPUT);
  digitalWrite (BUZZER, HIGH);
}

void Buzzer (uint8_t numero, unsigned int tiempo, unsigned int silencio){
  for (uint8_t i=0; i<numero; i++){
    digitalWrite (BUZZER, LOW);
    delay (tiempo);
    digitalWrite (BUZZER, HIGH);
    delay (silencio);
  }  
}

// Funciones para leds:

void Led_init (uint8_t LED_PIN){
  pinMode (LED_PIN, OUTPUT);
  digitalWrite (LED_PIN, LOW);
}

void LightOn (uint8_t LED_PIN){
  digitalWrite (LED_PIN, HIGH);
}

void LightOff (uint8_t LED_PIN){
  digitalWrite (LED_PIN, LOW);
}

void Parpadeo (uint8_t LED_PIN){
  LightOn (LED_PIN);
  delay(200);
  LightOff (LED_PIN);  
}

void Led_wheel (){
  Parpadeo (WHITE_R);
  Parpadeo (WHITE_L);
  Parpadeo (RED_R);
  Parpadeo (RED_L);
}

// Funciones para motores:

void Motores_init(){
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}

void Para (int tiempo){
  analogWrite (ENA, 0);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite (ENB, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  delay (tiempo);
}

void Stop (){
  analogWrite (ENA, 0);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite (ENB, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
}

void Avanza(){
  analogWrite (ENA, Velocidad);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENB, Velocidad);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void Retrocede(){
  analogWrite (ENA, Velocidad/2);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENB, Velocidad/2);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  Buzzer (1, 100, 100);
}

void Izquierda(){
  analogWrite (ENA, Velocidad);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENB, 0);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void Derecha(){
  analogWrite (ENA, Velocidad);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENB, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void Gira_izquierda(){
  analogWrite (ENA, Velocidad/2);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENB, Velocidad/2);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void Gira_derecha(){
  analogWrite (ENA, Velocidad/2);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENB, Velocidad/2);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

// Función para lectura de todos los sensores:

void Lectura_sensores() {
  Sensor_left = digitalRead(SENSOR_L);
  Sensor_right = digitalRead(SENSOR_R);

  Sensor_front = sonar.ping_cm();

  Sensor_luz = digitalRead(FOTOSENSOR);
}

// Enciende luces en la oscuridad

void Luces() {
  if (Sensor_luz == HIGH){
    LightOn(WHITE_R);
    LightOn(WHITE_L);
    LightOn(RED_R);
    LightOn(RED_L);
  }
  else {
    LightOff(WHITE_R);
    LightOff(WHITE_L);
    LightOff(RED_R);
    LightOff(RED_L);    
  }
}

// Para o retrocede según obstáculos

void Distancia() {

  while (Sensor_front<=STOP_DISTANCE){
    Para(100);
    Sensor_front = sonar.ping_cm();
    
    /* Retrocede si tiene un obstáculo cerca */
    if (Sensor_front<=ATRAS_DISTANCE) {
      lcd.print("******Atras******");
      Retrocede();
      Buzzer(1,500,500);
    }
  
    /* Se mantiene parado si tiene un obstáculo delante */
    else {
      
      lcd.print("******Stop*******");
      Stop();
      Buzzer(1,100,1000);
    }
  }
}

// Decisiones de movimiento en función de los sensores de suelo:
void Linea() {
  if (Sensor_left == 0 && Sensor_right == 0){
    Avanza();
    lcd.print("*****Avanza******");
    
  }
  if (Sensor_left == 0 && Sensor_right == 1){
    Para(100);
    Retrocede();
    Izquierda();
    lcd.print("****Izquierda****");
  }
  if (Sensor_left == 1 && Sensor_right == 0){
    Para(100);
    Retrocede();
    Derecha();
    lcd.print("****Derecha******");
  }

  if (Sensor_left == 1 && Sensor_right == 1){
    Para(100);
    Retrocede();
    Led_wheel();
    Gira_izquierda(); 
    lcd.print("******Atras******");  
  }
}
