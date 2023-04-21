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

#define TRIG 12
#define ECO 11
#define Buzz 10
#define sph(pin) digitalWrite(pin, HIGH)
#define spl(pin) digitalWrite(pin, LOW)
int f=349;
int gS=415;
int a=440;
int cH=523;
int eH=659;
int fH=698;
int duracion;
int distancia;

void setup() {
Serial.begin(9600);
pinMode(12, OUTPUT);
pinMode(11, INPUT);
pinMode(10, OUTPUT);
}

void loop() {

distancia = Sensor_ultrasonico();

Notas();
}

int Sensor_ultrasonico(void){
  int distance;
  sph(TRIG);                              
delayMicroseconds(10);
spl(TRIG);
duracion = pulseIn(ECO, HIGH);           
distance = duracion/58;              
delay(150);
return distance;
}

void Notas(){
if(distancia >= 4 && distancia <= 9){       //a
  tone(Buzz, a, 500);
  delay(500);
  noTone(Buzz);
}

if(distancia >= 10 && distancia <= 14){       //f
  tone(Buzz, f, 350);
  delay(350);
  noTone(Buzz);
}

if(distancia >= 15 && distancia <=19){       //cH
  tone(Buzz, cH, 150);
  delay(150);
  noTone(Buzz);
}

if(distancia >= 20 && distancia <= 24){       //a
  tone(Buzz, a, 1000);
  delay(1000);
  noTone(Buzz);
}

if(distancia >= 25 && distancia <= 29){       //eH
  tone(Buzz, eH, 500);
  delay(500);
  noTone(Buzz);
}

if(distancia >= 30 && distancia <= 34){       //fH
  tone(Buzz, fH, 350);
  delay(350);
  noTone(Buzz);
}

if(distancia >= 35 && distancia <= 39){       //gS
  tone(Buzz, gS, 500);
  delay(500);
  noTone(Buzz);
}

}
