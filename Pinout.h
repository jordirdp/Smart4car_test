
/* Project: Smart4car */
/* Author: Jordi Rodriguez */

#pragma once

// I2C_LCD_SDA = A4;
// I2C_LCD_SCL = A5;

// Driver Motores L298N
const byte ENB = 5;
const byte IN3 = 9;
const byte IN4 = 10;
const byte ENA = 6;
const byte IN1 = 7;
const byte IN2 = 8;

// Ultrasonidos
const byte ECHO_PIN = 15; // = A1
const byte TRIGGER_PIN = 16; // =A2

// Servo
const byte SERVO_PIN = 14; // = A0

// Sensores de línea
const byte SENSOR_LL_PIN = 4;
const byte SENSOR_L_PIN = 11;
const byte SENSOR_RR_PIN = 13;
const byte SENSOR_R_PIN = 12;

// Encoders
const byte ENCODER_L_PIN = 2;
const byte ENCODER_R_PIN = 3;
