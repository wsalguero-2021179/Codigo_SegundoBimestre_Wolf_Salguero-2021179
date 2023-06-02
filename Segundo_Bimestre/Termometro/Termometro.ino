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

#include <OneWire.h>
#include <LiquidCrystal_I2C.h>
#include <DallasTemperature.h>

LiquidCrystal_I2C LCD_W(0x27, 16, 2);

OneWire ourWire(2);                
DallasTemperature sensor(&ourWire);

#define blue 12
#define yellow 11
#define red 10
int t = 500;
int caso;
float Celsius;
float Fahrenheit;

byte Termometro[8] = {
  0b00100,
  0b01010,
  0b01010,
  0b01010,
  0b01010,
  0b10001,
  0b10001,
  0b01110
};

byte Grad[8] = {
  0b01110,
  0b01010,
  0b01110,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte cold[8] = {
  0b00100,
  0b01010,
  0b01010,
  0b01010,
  0b01010,
  0b10001,
  0b11111,
  0b01110
};

byte normal[8] = {
  0b00100,
  0b01010,
  0b01010,
  0b01010,
  0b01110,
  0b11111,
  0b11111,
  0b01110
};

byte warm[8] = {
  0b00100,
  0b01110,
  0b01110,
  0b01110,
  0b01110,
  0b11111,
  0b11111,
  0b01110
};

void setup() {
Serial.begin(9600);   
sensor.begin();
LCD_W.init();
LCD_W.backlight();
LCD_W.createChar(0, Termometro);
LCD_W.createChar(1, Grad);
LCD_W.createChar(2, cold);
LCD_W.createChar(3, normal);
LCD_W.createChar(4, warm);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
}

void loop() {
  
Celsius=Cel_grad();
Fahrenheit=Fahren_grad();
LCD();
caso=parametro();
leds();

}

float Cel_grad(void){
  float _Celsius;
  sensor.requestTemperatures();
 _Celsius = sensor.getTempCByIndex(0);
 return _Celsius;
}

float Fahren_grad(void){
  float _Fahrenheit;
  sensor.requestTemperatures();
  _Fahrenheit = sensor.getTempFByIndex(0);
  return _Fahrenheit;
}


void LCD(){
  LCD_W.setCursor(0,0);
  LCD_W.print("Termometro ");
  LCD_W.write(byte(0));
  LCD_W.setCursor(0,1);
  LCD_W.print(Celsius);
  LCD_W.write(byte(1));
  LCD_W.print("C ");
  LCD_W.setCursor(8,1);
  LCD_W.print(Fahrenheit);
  LCD_W.write(byte(1));
  LCD_W.print("F");
  delay(t);
}

int parametro(void){
  int parametro;
if(Celsius >=30){
  parametro=1;
}

if(Celsius <30 && Celsius > 15){
    parametro=2;
}

if(Celsius <=15){
    parametro=3;
}
 return parametro; 
}

void leds(){
  switch(caso){
    case(1):
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(yellow, LOW);
    LCD_W.setCursor(15,1);
    LCD_W.write(byte(4));
    break;

    case(2):
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(yellow, HIGH);
    LCD_W.setCursor(15,1);
    LCD_W.write(byte(3));
    break;

    case(3):
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(yellow, LOW);
    LCD_W.setCursor(15,1);
    LCD_W.write(byte(2));
    break;
  }
}
