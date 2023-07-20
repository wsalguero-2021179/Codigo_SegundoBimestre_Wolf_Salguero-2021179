/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Wolf Renato Giovanni Salguero Barrios
 * Carnet: 2021179
 * Proyecto: Práctica No. 6
*/

//Librerías
#include <Wire.h>
#include <SparkFun_ADXL345.h>
#include <LedControl.h>

//Directivas de preprocesador
#define dataPin 7
#define dataClock 6
#define dataLoad 5

//Constructores
ADXL345 adxl = ADXL345();
LedControl matriz = LedControl(dataPin, dataClock, dataLoad, 1);

//Variables
int pos_x, pos_y;

//Animaciones
byte base[8] 
  {
  0b00000000,
  0b00000000,
  0b01111110,
  0b10000001,
  0b10000001,
  0b10000001,
  0b01111110,
  0b00000000
};



void setup() {
  Serial.begin(9600);

  //Acelerometro
  adxl.powerOn();
  adxl.setRangeSetting(8);

  //Matriz 8x8
  matriz.shutdown(0, false);
  matriz.setIntensity(0, 4);
  matriz.clearDisplay(0);
}

void loop() {

leer_datos();
nivel();
  
}




void leer_datos(){
int x, y, z;
adxl.readAccel(&x, &y, &z);
/*
Serial.print(x);
Serial.print(", ");
Serial.print(y);
Serial.print(", ");
Serial.println(z);
delay(1000);
*/
pos_x = map(x, 30, -20, 1, 6);
pos_y = map(y, -40, 20, 3, 5);
}

void nivel(){

  for(int i = 0; i < 8; i++){
    matriz.setRow(0,i,base[i]);
  }
  matriz.setLed(0,pos_y,pos_x,HIGH);
  delay(200);
}
