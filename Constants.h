
/* Project: Smart4car */
/* Author: Jordi Rodriguez */

#pragma once

const unsigned int TiempoEspera = 2000; // espera entre fases

// Motores
const byte Vmin = 100;                  // velocidad mínima
const byte Vmax = 250;                  // velocidad máxima
int Velocidad = 175;                    // velocidad inicial

// Sensor HC-SR04 con librería NewPing
#define MAX_DISTANCE 100                // distancia máxima para ping

// Servo SG90 con librería Servo (Arduino)
byte pos = 0;                            // posicions del servo

// Sensores de línea TCRT5000
boolean Sensor_LL;
boolean Sensor_L;
boolean Sensor_R;
boolean Sensor_RR;

// Encoders rotativos
volatile int Counter_L = 0;
volatile int Counter_R = 0;
