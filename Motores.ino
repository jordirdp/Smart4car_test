
/* Project: Smart4car */
/* Author: Jordi Rodriguez */

void Motores_init(){
  pinMode (IN1,OUTPUT);
  pinMode (IN2,OUTPUT);
  pinMode (IN3,OUTPUT);
  pinMode (IN4,OUTPUT);
  pinMode (ENA,OUTPUT);
  pinMode (ENB,OUTPUT);
}

void Avanza(){
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, Velocidad);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, Velocidad);
  lcd.setCursor (0,1);
  lcd.print("-----Avanza-----");
}

void Retrocede(){
  digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW);
  analogWrite (ENA, Velocidad);
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW);
  analogWrite (ENB, Velocidad);
  lcd.setCursor (0,1);
  lcd.print("---Retrocede----");
}

void Gira(){
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, Velocidad);
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW);
  analogWrite (ENB, Velocidad);
  lcd.setCursor (0,1);
  lcd.print("------Gira-------");
}

void Para(){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 0);
  lcd.setCursor (0,1);
  lcd.print("-----Parado-----");
}