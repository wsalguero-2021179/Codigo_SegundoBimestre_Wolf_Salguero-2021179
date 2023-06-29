/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Wolf Salguero
 * Carnet: 2021179
 * Proyecto: Diseño - Aplicación Bluetooth 
*/

//Librerias
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Ticker.h>

//Funciones
void ISR_Cel_grad();

//Directivas de preprocesador
#define Led A5

//Variables
float Celsius;

//Constructores
//Sensor de temperatura
OneWire ourWire(2);                
DallasTemperature sensor(&ourWire);

//Ticker
Ticker leer_temp(ISR_Cel_grad, 10000);

void setup(){

Serial.begin(9600);
pinMode(A5, OUTPUT);
digitalWrite(Led, LOW);
sensor.begin();
leer_temp.start();
}

void loop() 
{
leer_temp.update();
  
  //Mientras tenga caracteres disponibles para leer en los pines de comunicacion serial
  if(Serial.available()>0)
  {
    //Guardo el caracter recibido por medio de la comunicacion serial
    char var_led = Serial.read();
    
    if(var_led == 'O')
    {
      digitalWrite(Led, HIGH); //enciendo el led
    }
    
    else if(var_led == 'F')
    {
     digitalWrite(Led, LOW); 
    }
  }

}

void ISR_Cel_grad(){
  float _Celsius;
  sensor.requestTemperatures();
 _Celsius = sensor.getTempCByIndex(0);
 Serial.print(_Celsius);
}
