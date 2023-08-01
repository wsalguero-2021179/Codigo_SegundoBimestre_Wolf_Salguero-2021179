
//Librerias
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <RTClib.h>

//Directivas de preprocesador
#define RST_PIN 9
#define SS_PIN 10

/******************************Constructores*****************************/
//RFID
MFRC522 lector(SS_PIN, RST_PIN);

//LCD
LiquidCrystal_I2C LCD(0X27, 16, 2);

//Reloj
RTC_DS3231 rtc;

/****************************************************************************/
//Variables
byte LecturaUID[4];
byte Usuario1[4] = {0x33, 0x1C, 0x87, 0xA6};
String hora;
float voltage, amp, potencia;
float sensorPin = A0;   // seleccionar la entrada para el sensor
float sensorValue;      // variable que almacena el valor raw (0 a 1023) 
float Sensibilidad=0.185;



void setup() {
Serial.begin(9600);


//RFID
SPI.begin();
lector.PCD_Init();

//LCD
LCD.init();
LCD.backlight();

//Reloj
if (!rtc.begin()) {
    Serial.println("No hay un módulo RTC");  
    while (1);
}


Serial.println("listo");
}

void loop() {
DateTime now = rtc.now();
hora = String(now.hour()) + ":" + String(now.minute());;

LCD.setCursor(3,0);
LCD.print("EEGSA-KINAL");
LCD.setCursor(0,1);
LCD.print("datos de energia");

sensorValue = analogRead(sensorPin);        // realizar la lectura
  voltage = fmap(sensorValue, 0, 1023, 0.0, 25.0);   // cambiar escala a 0.0 - 25.0

  float voltajeSensor= analogRead(A1)*(5.0 / 1023.0);
  amp = (voltajeSensor - 2.5)/Sensibilidad;

  potencia = voltage * amp;
  
rfid();

}

void rfid(){

  
  if( ! lector.PICC_IsNewCardPresent())   //Si no hay una tarjeta presente
return;   //Retorna al loop esperando por una tarjeta

if( ! lector.PICC_ReadCardSerial())    //Si no puede obtener datos de la tarjeta
return;     // Retorna al loop esperando porr otra tarjeta


for(byte i = 0; i < lector.uid.size; i++) {
  if(lector.uid.uidByte[i] < 0x10)
  {
    Serial.print(" 0");
  }
  else{
    Serial.print(" ");    //imprime un espacio en blanco
  }
 // Serial.print(lector.uid.uidByte[i], HEX);
  LecturaUID[i] = lector.uid.uidByte[i];
}
Serial.print("\t");

if(comparaUID(LecturaUID, Usuario1)){
Serial.println("Bienvenido Usuario 1");
Serial.print("Hora de ingreso: ");
Serial.println(hora);
LCD.setCursor(0,1);
LCD.print(" ");
LCD.print(voltage, 1);
LCD.print("v ");
LCD.print(amp, 1);
LCD.print("mA ");
LCD.print(potencia, 1);
LCD.print("w   ");
delay(1300);
}
else{
Serial.println("Usuario invalido");
LCD.setCursor(0,1);
LCD.print("  Invalid user    ");
lector.PICC_HaltA();
delay(850);
}
}

boolean comparaUID(byte lectura[], byte usuario[]){
  for(byte i=0; i <lector.uid.size; i++){
    if(lectura[i] != usuario[i])
    return(false);
  }
  return(true);
}

float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
