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

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD_W(0x27,16,2);

#define TRIG 6
#define ECO 5
#define Out(pin) pinMode(pin, OUTPUT)
#define In(pin) pinMode(pin, INPUT)
#define sph(pin) digitalWrite(pin, HIGH)
#define spl(pin) digitalWrite(pin, LOW)
int caso;
int distancia;
int duracion;

byte block[] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};


void setup() {

 Serial.begin(9600);
 Out(TRIG);
 In(ECO);
 LCD_W.init();
 LCD_W.backlight();
 LCD_W.createChar(0, block);

}

void loop() {

distancia =  Sensor_ultrasonico();
Serial.println(distancia);


if(distancia <= 50 && distancia >= 29){
  caso = 1;
}

if(distancia <= 30 && distancia >= 11){
  caso = 2;
}

if(distancia <= 10 && distancia >= 4){
  caso = 3;
}

if(distancia > 50){
  caso=4;
}
alarma();
}

int Sensor_ultrasonico(void){
  int _distancia;
  sph(TRIG);                               
delayMicroseconds(10);
spl(TRIG);
duracion = pulseIn(ECO, HIGH);           
_distancia = duracion/58;                
delay(250);
return _distancia;
}

void alarma(){
  switch(caso){

  case(1):
  LCD_W.setCursor(0, 0);
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.print("    ");
  LCD_W.setCursor(7, 0);
  LCD_W.print("50  ");
  LCD_W.setCursor(11, 0);
  LCD_W.print("  ");
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.print("    ");
  LCD_W.setCursor(4, 1);
  LCD_W.print("  Libre  ");
  break;

  case(2):
  LCD_W.setCursor(0, 0);
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.print("      ");
  LCD_W.setCursor(7, 0);
  LCD_W.print("30");
  LCD_W.setCursor(11, 0);
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.print("      ");
  LCD_W.setCursor(5, 1);
  LCD_W.print("Cuidado");
  break;
  
  case(3):
  LCD_W.setCursor(0, 0);
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.setCursor(7, 0);
  LCD_W.print("10");
  LCD_W.setCursor(9, 0);
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.write(byte(0));
  LCD_W.setCursor(3, 1);
  LCD_W.print("   Alto    ");
  break;

  case(4):
  LCD_W.clear();
}
}
