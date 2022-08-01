# Smart4car_test

Autor: Jordi Rodríguez  
Práctica de programación ordenada en Arduino utilizando pestañas   
Crearemos un vehículo de 4 ruedas con el material especificado  
Para la programación usaremos la plataforma Arduino IDE:  

https://www.arduino.cc/en/software

Este código realiza las siguientes funciones simples:  
- Lectura de 4 sensores de línea  
- Medición de 3 sensores de distancia  
- Lectura de 2 encoders en motores traseros
  
![Imagen Smart4car acabado](Smart4car.jpeg)  


## Material utilizado

- 3 x HC-SR04 = Sensor ultrasonido de distancia
- 4 x TCRT5000 = Sensor infrarrojo de proximidad
- LCD I2C = Pantalla lcd
- L298N = Controlador de motores
- 4 x Motores Arduino
- 2 x Encoders motores Arduino  
- Protoboard
  

## Pines de conexion

A0 = Sensor ultrasonido izquierdo (HC-SR04)  
A1 = Sensor ultrasonido frontal (HC-SR04)  
A2 = Sensor ultrasonido frontal (HC-SR04)   
A3 =   
A4 = I2C LCD (SDA)  
A5 = I2C LCD (SCL)  

D0 = (RX)  
D1 = (TX)  
D2 = (INT0) Encoder izquierdo  
D3-= (INT1) Encoder derecho  
D4 = Sensor línea izquierda extremo     
D5-= ENB motor izquierdo  
D6-= ENA motor derecho  
D7 = IN1 motor derecho  
D8 = IN2 motor derecho  
D9-= IN3 motor izquierdo  
D10-= IN4 motor izquierdo  
D11-= Sensor línea izquierda  
D12 = Sensor línea derecha   
D13 = Sensor línea derecha extremo  
