/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Wolf Salguero
 * Carnet: 2021179
 * Proyecto: Diseño de sistmea embebido
*/

//librerias
#include <LedControl.h>
#include <Ticker.h>

//Directivas de preprocesador
#define pin_gas A0
#define dataPin 7
#define dataClock 6
#define dataLoad 5 

//Funciones
void ISR_medicion();

//Constructores
LedControl matriz_w = LedControl(dataPin, dataClock, dataLoad, 1);
Ticker leer_medicion(ISR_medicion, 5000);

//Variables
int gas, conver, prom;

//Animaciones

byte fire1[8] = {
  0b00001000,
  0b00010000,
  0b00110001,
  0b10111010,
  0b10111100,
  0b01111101,
  0b01111110,
  0b00111100
};
byte fire2[8] = {
  0b00010000,
  0b00001000,
  0b00001100,
  0b10011101,
  0b11011101,
  0b11111111,
  0b01111110,
  0b00111100
};

byte snow1[8] = {
  
  0b00001000,
  0b01001001,
  0b00101010,
  0b00011100,
  0b00011100,
  0b00101010,
  0b01001001,
  0b00001000
};

byte snow2[8] ={
  0b00000000,
  0b00001000,
  0b00101010,
  0b00011100,
  0b00011100,
  0b00101010,
  0b00001000,
  0b00000000
};



void setup() {
Serial.begin(9600);
pinMode(pin_gas, INPUT);
matriz_w.shutdown(0,false);
matriz_w.setIntensity(0,15);
matriz_w.clearDisplay(0);
leer_medicion.start();
}

void loop() {

leer_medicion.update();

if(prom < 50)
{
  Serial.println("El cuarto está libre de gases");
  nieve();
}
else
{
  Serial.println("Se ha detectado un gas");
  Fuego();
}

}

void ISR_medicion(){
  int x, y=0;

  gas = analogRead(pin_gas);
conver = map(gas, 0, 1024, 0, 100);

for(int i= 0; i<5; i++){
  x = conver;
  y = x + y;
  delay(100);
}
prom = y/5;
  
Serial.print("Porcentaje de gas: ");
Serial.println(prom);
}


void Fuego(){
  for(int i=0; i<8; i++){
    matriz_w.setRow(0,i,fire1[i]);
  }
  delay(850);

  for(int i=0; i<8; i++){
    matriz_w.setRow(0,i,fire2[i]);
  }
  delay(850);
}

void nieve()
{

for(int i=0; i<8; i++){
    matriz_w.setRow(0,i,snow1[i]);
  }
  delay(850);

  for(int i=0; i<8; i++){
    matriz_w.setRow(0,i,snow2[i]);
  }
  delay(850);

  
}
