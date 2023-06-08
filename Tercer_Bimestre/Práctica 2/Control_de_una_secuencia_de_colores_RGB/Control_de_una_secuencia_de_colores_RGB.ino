/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Wolf Salguero
 * Carnet: 2021179
 * Proyecto: Ejercicio 2 - Práctica 2
*/

//Librerias
#include <Ticker.h>

//Variables
int red = 9;
int blue = 10;
int green = 11;
int pot = A0;
int potValue;
int t;

//Funciones
void Secuencia(void);
void tiempo(void);

//Constructores
Ticker cambio(tiempo, 1);

void setup()
{
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
  cambio.start();
}

void loop()
{
 cambio.update();
  Secuencia();
  
}

void tiempo(void)
{
  potValue = analogRead(pot);
  t = map(potValue, 0, 1023, 100, 1000);
  Serial.println(t);
}


void Secuencia(void)
{
  analogWrite(red, 174);    //primera secuencia
  analogWrite(green, 92);
  analogWrite(blue, 230);
  delay(t);
  
  analogWrite(red, 255);    //Segunda secuencia
  analogWrite(green, 255);
  analogWrite(blue, 255);
  delay(t);
  
  analogWrite(red, 0);    //Tercera secuencia
  analogWrite(green, 255);
  analogWrite(blue, 255);
  delay(t);
  
  analogWrite(red, 189);    //Cuarta secuencia
  analogWrite(green, 174);
  analogWrite(blue, 20);
  delay(t);
  
  analogWrite(red, 225);    //Quinta secuencia
  analogWrite(green, 87);
  analogWrite(blue, 35);
  delay(t);
  
}
