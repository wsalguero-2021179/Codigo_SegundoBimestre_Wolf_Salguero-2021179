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
#define rele 10
#define a 8
#define b 7
#define c 6
#define d 5
#define e 4
#define f 3
#define g 2
#define Out(pin) pinMode(pin, OUTPUT)
#define In(pin) pinMode(pin, INPUT)
#define sph(pin) digitalWrite(pin, HIGH)
#define spl(pin) digitalWrite(pin, LOW)
int duracion;
int distancia;
int cuenta = 0;

void setup() {
  Serial.begin(9600);
Out(TRIG);
In(ECO);
Out(rele);
Out(a);
Out(b);
Out(c);
Out(d);
Out(e);
Out(f);
Out(g);
spl(rele);
}

void loop() {
  
Sensor_ultrasonico();

if(distancia > 5 && distancia < 11){
  cuenta = cuenta + 1;
  
}

numero_display();

Secuencia_rele();
}


void Sensor_ultrasonico(){
  sph(TRIG);                               //El trigger manda una señal
delayMicroseconds(10);
spl(TRIG);
duracion = pulseIn(ECO, HIGH);           //El eco recibe la señal
distancia = duracion/58;                //distancia en cm
Serial.println(distancia);
delay(375);
}

void Secuencia_rele(){
if(cuenta >= 0 && cuenta <9){
  sph(rele);
}
else{
  if(cuenta > 8 ){
  spl(rele);
}
}
}

void numero_display(){
  switch(cuenta){
  {
  case(0):
  sph(a);
  sph(b);
  sph(c);
  sph(d);
  sph(e);
  sph(f);
  spl(g);
  break;
}
{
  case(1):
  spl(a);
  sph(b);
  sph(c);
  spl(d);
  spl(e);
  spl(f);
  spl(g);
  break;
}
{
  case(2):
  sph(a);
  sph(b);
  spl(c);
  sph(d);
  sph(e);
  spl(f);
  sph(g);
  break;
}
{
  case(3):
  sph(a);
  sph(b);
  sph(c);
  sph(d);
  spl(e);
  spl(f);
  sph(g);
  break;
}
{
  case(4):
   spl(a);
  sph(b);
  sph(c);
  spl(d);
  spl(e);
  sph(f);
  sph(g);
  break;
}
{
case(5):         
  sph(a);
  spl(b);
  sph(c);
  sph(d);
  spl(e);
  sph(f);
  sph(g);
  break;
}
{
case(6):          
  sph(a);
  spl(b);
  sph(c);
  sph(d);
  sph(e);
  sph(f);
  sph(g);
  break;
}
{
case(7):
sph(a);
  sph(b);
  sph(c);
  spl(d);
  spl(e);
  spl(f);
  spl(g);
  break;
}
{
  case(8):
  sph(a);
  sph(b);
  sph(c);
  sph(d);
  sph(e);
  sph(f);
  sph(g);
  break;
}
{
  case(9):
  sph(a);
  sph(b);
  sph(c);
  spl(d);
  spl(e);
  sph(f);
  sph(g);
  break;
}
}

}
