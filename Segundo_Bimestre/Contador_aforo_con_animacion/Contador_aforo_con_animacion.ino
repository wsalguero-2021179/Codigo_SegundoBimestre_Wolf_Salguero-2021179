/*
Fundacion kinal
Centro tecnico educativo laboral Kinal
Electronica
Grado: Quinto
Seccion: A
Curso: Taller en electronica digital y reparacion de computadoras I
Nombre: Wolf Renato Giovanni Salguero Barrios
Carne: 2021179
*/

#include <LiquidCrystal.h>

LiquidCrystal LCD_W(12, 11, 10, 9, 8, 7);

#define TRIG 6
#define ECO 5
#define buzz 4
#define Out(pin) pinMode(pin, OUTPUT)
#define In(pin) pinMode(pin, INPUT)
#define sph(pin) digitalWrite(pin, HIGH)
#define spl(pin) digitalWrite(pin, LOW)
int duracion;
int distancia;
int cuenta;
int total;


byte quiet[] = {
  0b01110,
  0b01110,
  0b01110,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte jump[] = {
  0b01110,
  0b01110,
  0b01110,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

byte bomb[] = {
  0b00000,
  0b00011,
  0b00100,
  0b01110,
  0b10011,
  0b10111,
  0b11111,
  0b01110
};

byte boom[] = {
  0b00000,
  0b00100,
  0b10101,
  0b01110,
  0b11111,
  0b01110,
  0b10101,
  0b00100
};

void setup() {
Serial.begin(9600);
LCD_W.begin(16, 2);
LCD_W.createChar(0, quiet);
LCD_W.createChar(1, jump);
LCD_W.createChar(2, bomb);
LCD_W.createChar(3, boom);
Out(TRIG);
In(ECO);
Out(buzz);
}

void loop() {

distancia =  Sensor_ultrasonico();
Serial.println(distancia);

LCD();

if(distancia > 5 && distancia < 11){
  cuenta = _cuenta();
  
}

while(cuenta > 15){
LCD_W.setCursor(1,0);
LCD_W.print("Aforo lleno!!!");
quieto();
salto();
bomba();
explotion();
buzzer();
}
}

int Sensor_ultrasonico(void){
  int _distancia;
  sph(TRIG);                               
delayMicroseconds(10);
spl(TRIG);
duracion = pulseIn(ECO, HIGH);           
_distancia = duracion/58;                
delay(375);
return _distancia;
}

void buzzer(){
  tone(buzz, 250, 500);
  delay(500);
  noTone(buzz);
  delay(500);
}

void quieto(){
LCD_W.setCursor(7,1);
LCD_W.write(byte(0));
delay(250);
}

void salto(){
LCD_W.setCursor(7,1);
LCD_W.write(byte(1));
delay(250); 
}

void bomba(){
 LCD_W.setCursor(6,1);
LCD_W.write(byte(2));
LCD_W.setCursor(8,1);
LCD_W.write(byte(2));
delay(250);
}

void explotion(){
LCD_W.setCursor(6,1);
LCD_W.write(byte(3));
LCD_W.setCursor(8, 1);
LCD_W.write(byte(3));
delay(250);
}


int _cuenta(void){
  total = total + 1;
  return total;
}

void LCD(){
    LCD_W.setCursor(1,0);
  LCD_W.print("Aforo: ");
  LCD_W.print(cuenta);
  LCD_W.setCursor(11,0);
  LCD_W.write(byte(0));
  delay(500);
}
