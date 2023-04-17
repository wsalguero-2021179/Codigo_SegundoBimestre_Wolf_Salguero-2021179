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

#define in 12
#define rele 11
#define red 10
#define blue 9


void setup() {
pinMode(12, INPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);

}

void loop() {

  digitalRead(in);

if(digitalRead(in) == HIGH){
  digitalWrite(rele, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(red, LOW);
}

if(digitalRead(in) == LOW){
  digitalWrite(rele, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
}

}
