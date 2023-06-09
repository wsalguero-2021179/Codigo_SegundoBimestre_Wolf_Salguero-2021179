/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Wolf Salguero
 * Carnet: 2021179
 * Proyecto: Ejercicio 3 - Práctica 2
*/

//libreria
#include <LiquidCrystal_I2C.h>

//Directivas de preprocesador
#define entrada A0

//Variables
float den;
float num;
float Vout;
int Vcc=5;
int R2 = 10000;
int R1;

//constructor
LiquidCrystal_I2C LCD_W(0x27, 16, 2);

void setup() {
Serial.begin(9600);
LCD_W.init();
LCD_W.backlight();
LCD_W.setCursor(3,0);
LCD_W.print("Ohmimetro:");
pinMode(A0, INPUT);

}

void loop() {

Vout = analogRead(entrada);
Vout = ((5 * Vout)/1023);
if(Vout)
{
num= Vcc - Vout;
den = Vout;
R1 = (num/den) * R2;
LCD_W.setCursor(4,1);
LCD_W.print(R1);
LCD_W.print(" ohms    ");
delay(500);
}
}
