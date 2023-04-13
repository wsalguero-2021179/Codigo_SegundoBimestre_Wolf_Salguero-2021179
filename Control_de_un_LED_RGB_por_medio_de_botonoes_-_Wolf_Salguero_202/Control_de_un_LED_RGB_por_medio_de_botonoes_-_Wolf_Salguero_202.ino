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

#define Led_R 12
#define Led_B 11
#define Led_G 10
#define push1 9
#define push2 8


void setup() {

pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, INPUT);
pinMode(8, INPUT);
}

void loop() {

if(digitalRead(push1) == HIGH && digitalRead(push2)==LOW){
  digitalWrite(Led_R, HIGH);
  digitalWrite(Led_G, HIGH);
  digitalWrite(Led_B, LOW);
    delay(500);
  digitalWrite(Led_R, LOW);
  digitalWrite(Led_G, LOW);
}
else{
if(digitalRead(push1) == LOW && digitalRead(push2)==HIGH){
  digitalWrite(Led_R, LOW);
  digitalWrite(Led_G, HIGH);
  digitalWrite(Led_B, HIGH);
    delay(500);
  digitalWrite(Led_G, LOW);
  digitalWrite(Led_B, LOW);
}

if(digitalRead(push1) && digitalRead(push2)){
  digitalWrite(Led_R, HIGH);
  digitalWrite(Led_B, HIGH);
  digitalWrite(Led_G, LOW);
    delay(500);
  digitalWrite(Led_R, LOW);
  digitalWrite(Led_B, LOW);

}
else{
if(digitalRead(push1)== LOW && digitalRead(push2) == LOW){
  digitalWrite(Led_R, HIGH);
  delay(500);
  digitalWrite(Led_R, LOW);
  digitalWrite(Led_G, HIGH);
  delay(500);
  digitalWrite(Led_G, LOW);
  digitalWrite(Led_B, HIGH);
  delay(500);
  digitalWrite(Led_B, LOW);
}
}
}
}
