/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Wolf Salguero
 * Carnet: 2021179
 * Proyecto: Ejercicio 1 - Práctica 2
*/

//Variables
int ledPin = 10;
int dt = 300;
int potPin = A2;
int potVal;
int light;

void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(potPin, INPUT);

}

void loop() {

potVal = analogRead(potPin);
Serial.println(potVal);
Serial.println(light);
light = map(potVal, 0, 1023, 0, 255);
analogWrite(ledPin, light );
delay(dt);
}
