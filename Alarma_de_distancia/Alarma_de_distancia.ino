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

#define direccion_lcd 0x27
#define filas 2
#define columnas 16

LiquidCrystal_I2C LCD_W(direccion_lcd, columnas, filas);

#define TRIG 6
#define ECO 5
#define buzz 4
#define L1 12
#define L2 11
#define L3 10
#define L4 9
#define L5 8
#define L6 7
#define L7 A0
#define L8 A1
#define L9 A2
#define L10 A3
#define Out(pin) pinMode(pin, OUTPUT)
#define In(pin) pinMode(pin, INPUT)
#define sph(pin) digitalWrite(pin, HIGH)
#define spl(pin) digitalWrite(pin, LOW)
int duracion;
int distancia;
int caso;

void setup() {
Out(TRIG);
In(ECO);
Out(buzz);
Out(L1);
Out(L2);
Out(L3);
Out(L4);
Out(L5);
Out(L6);
Out(L7);
Out(L8);
Out(L9);
Out(L10);
LCD_W.init(); 
LCD_W.backlight(); 
}

void loop() {
distancia =  Sensor_ultrasonico();

luces();

if(distancia >= 45){
caso = 1;
Distancia();
}

if(distancia <= 45 && distancia > 30){
caso = 2;
Distancia();
}

if(distancia <= 30 && distancia > 15){
caso = 3;
Distancia();
buzzer_5();
}

if(distancia <= 15 && distancia > 5){
caso = 4;
Distancia();
buzzer_10();
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

void buzzer_5(){
  tone(buzz, 250);
  delay(5000);
  noTone(buzz);
  delay(500);
}

void buzzer_10(){
  tone(buzz, 250);
  delay(10000);
  noTone(buzz);
  delay(500);
}

void Distancia(){
  switch (caso){
    case(1):
    LCD_W.setCursor(1,0);
    LCD_W.print("Fuera de        ");
    LCD_W.setCursor(1,1);
    LCD_W.print("alcance         ");
    break;

    case(2):
    LCD_W.setCursor(1,0);
    LCD_W.print("Persona/objeto   ");
    LCD_W.setCursor(1,1);
    LCD_W.print("Acercandose      ");
    break;

    case(3):
    LCD_W.setCursor(1,0);
    LCD_W.print("Cuidado,         ");
    LCD_W.setCursor(1,1);
    LCD_W.print("Espacio privado  ");
    break;

    case(4):
    LCD_W.setCursor(1,0);
    LCD_W.print("Invadiendo       ");
    LCD_W.setCursor(1,1);
    LCD_W.print("Espacio privado  ");
    break;
  }
}

void luces(){

  
  if(distancia >= 5 && distancia < 10){
    sph(L1);
    sph(L2);
    sph(L3);
    sph(L4);
    sph(L5);
    sph(L6);
    sph(L7);
    sph(L8);
    sph(L9);
    sph(L10);
  }

  if(distancia >= 10 && distancia < 15){
    sph(L1);
    sph(L2);
    sph(L3);
    sph(L4);
    sph(L5);
    sph(L6);
    sph(L7);
    sph(L8);
    spl(L9);
    spl(L10);
  }
  
   if(distancia >= 15 && distancia < 20){
    sph(L1);
    sph(L2);
    sph(L3);
    sph(L4);
    sph(L5);
    sph(L6);
    sph(L7);
    spl(L8);
    spl(L9);
    spl(L10);
  }

   if(distancia >= 20 && distancia < 25){
    sph(L1);
    sph(L2);
    sph(L3);
    sph(L4);
    sph(L5);
    sph(L6);
    spl(L7);
    spl(L8);
    spl(L9);
    spl(L10);
  }

   if(distancia >= 25 && distancia < 30){
    sph(L1);
    sph(L2);
    sph(L3);
    sph(L4);
    sph(L5);
    spl(L6);
    spl(L7);
    spl(L8);
    spl(L9);
    spl(L10);
  }

   if(distancia >= 30 && distancia < 35 ){
    sph(L1);
    sph(L2);
    sph(L3);
    sph(L4);
    spl(L5);
    spl(L6);
    spl(L7);
    spl(L8);
    spl(L9);
    spl(L10);
  }

   if(distancia >= 35 && distancia < 40){
    sph(L1);
    sph(L2);
    sph(L3);
    spl(L4);
    spl(L5);
    spl(L6);
    spl(L7);
    spl(L8);
    spl(L9);
    spl(L10);
  }

   if(distancia >= 40 && distancia < 45){
    sph(L1);
    sph(L2);
    spl(L3);
    spl(L4);
    spl(L5);
    spl(L6);
    spl(L7);
    spl(L8);
    spl(L9);
    spl(L10);
  }

  if(distancia >= 45){
    sph(L1);
    spl(L2);
    spl(L3);
    spl(L4);
    spl(L5);
    spl(L6);
    spl(L7);
    spl(L8);
    spl(L9);
    spl(L10);
  }
}
