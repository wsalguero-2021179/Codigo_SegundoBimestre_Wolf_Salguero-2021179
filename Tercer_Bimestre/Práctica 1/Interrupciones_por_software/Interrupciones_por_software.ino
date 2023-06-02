/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Wolf Salguero
 * Carnet: 2021179
 * Proyecto: Interrupciones por software
*/

//librerias
#include <Ticker.h>
#include <DallasTemperature.h>
#include <Wire.h>

//Directivas de preprocesador
#define boton 3


//Funciones ISR
void ISR_Temp();
void ISR_Sensor();

//Variables
 float T_status;
volatile static bool S_status;

//Constructores
Ticker leer_temp(ISR_Temp, 3000);
Ticker leer_sensor(ISR_Sensor, 6000);
OneWire ourWire(2);
DallasTemperature sensor_temp(&ourWire);

void setup() {
sensor_temp.begin();
Serial.begin(9600);
pinMode(2, INPUT);
pinMode(3, INPUT);
leer_temp.start();
leer_sensor.start();
}

void loop() {

leer_temp.update();
leer_sensor.update();

}

void ISR_Temp(){
  sensor_temp.requestTemperatures();
T_status = sensor_temp.getTempCByIndex(0);
Serial.print("La temperatura es: ");
Serial.println(T_status);
}

void ISR_Sensor(){
S_status = digitalRead(boton);

if(S_status == HIGH){
  Serial.println("El sensor esta activo");
}

  if(S_status == LOW){
  Serial.println("El sensor esta inactivo");
}

}
