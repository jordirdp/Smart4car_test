# Smart4car_test 
🔗Creado por [Jordi Rodriguez](https://github.com/jordirdp)  

👨🏻‍💻Práctica de **programación modular** utilizando pestañas en Arduino  
    
### Software  
- Programado con [Arduino](https://www.arduino.cc/en/software)
- Se han incluido las siguientes librerías:  
-- [NewPing](https://bitbucket.org/teckel12/arduino-new-ping/src/master/)  
-- [LiquidCrystal I2C](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library)  
-- [Servo](https://github.com/arduino-libraries/Servo)  
- Este código realiza las siguientes funciones simples:  
-- Medición de ángulo de giro del servo  
-- Medición de 1 sensores de distancia  
-- Lectura de 4 sensores de línea  
-- Lectura de 2 encoders en motores traseros  
-- Prueba de motores  Lectura de sensores de línea  

### Hardware  
- 1 x HC-SR04 = Sensor ultrasonido de distancia  
- 1 x SG90 = MicroServo 9g  
- 4 x TCRT5000 = Sensor infrarrojo de proximidad  
- LCD I2C = Pantalla lcd  
- L298N = Controlador de motores  
- 4 x Motores Arduino  
- 2 x Encoders motores Arduino (alimentados a 3'3v)  
- Protoboard  
- Arduino UNO  

### Montaje  
![Imagen Smart4car](/Images/Smart4car.jpeg)  
Conexiones a pines Arduino UNO:  
- A00 = Servo frontal  
- A01 = Sensor ultrasonido-Echo (HC-SR04)  
- A02 = Sensor ultrasonido-Trigger (HC-SR04)  
- A03 =   
- A04 = I2C LCD (SDA)  
- A05 = I2C LCD (SCL)  
- D00 = (RX)  
- D01 = (TX)  
- D02 = (INT0) Encoder izquierdo  
- D03-= (INT1) Encoder derecho  
- D04 = Sensor línea izquierda extremo     
- D05-= ENB motor izquierdo  
- D06-= ENA motor derecho  
- D07 = IN1 motor derecho  
- D08 = IN2 motor derecho  
- D09-= IN3 motor izquierdo  
- D10-= IN4 motor izquierdo  
- D11-= Sensor línea izquierda  
- D12 = Sensor línea derecha   
- D13 = Sensor línea derecha extremo  

### Licencia  
⚖️Todo el contenido distribuido bajo [licencia GPL-3.0](https://www.gnu.org/licenses/gpl-3.0), salvo indicación expresa.  
Las referencias y librerías empleadas, estarán sujetas a sus propia licencia, y no se incluyen en este repositorio.  
