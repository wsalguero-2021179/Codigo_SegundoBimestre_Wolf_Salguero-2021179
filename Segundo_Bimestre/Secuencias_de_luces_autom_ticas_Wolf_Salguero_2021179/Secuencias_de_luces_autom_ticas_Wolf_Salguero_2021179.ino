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

#define  PinOut(pin)pinMode(pin, OUTPUT)
int pin;

void setup() {
PinOut(12);
PinOut(11);
PinOut(10);
PinOut(9);
PinOut(8);
PinOut(7);
PinOut(6);
PinOut(5);
PinOut(4);
PinOut(3);
}

void loop() {
for(pin=12; pin>=3; pin--)
 {
  digitalWrite(pin,HIGH);
  delay(50);
  digitalWrite(pin,LOW);
 }

for(pin=4; pin<=11; pin++)
 {
  digitalWrite(pin,HIGH);
  delay(50);
  digitalWrite(pin,LOW);

}
}
