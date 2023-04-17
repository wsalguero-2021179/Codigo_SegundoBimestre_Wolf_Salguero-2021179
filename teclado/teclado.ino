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


#include <Key.h>
#include <Keypad.h>

//macros o directivas de preprocesador
#define filas 4 //Cantidad de filas del teclado
#define columnas 4//Cantidad de columnas del teclado

char keys [filas][columnas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pines_filas[filas] = {2, 3, 4, 5};
byte pines_columnas[columnas] = {6, 7, 8, 9};

Keypad teclado = Keypad(makeKeymap(keys), pines_filas, pines_columnas, filas, columnas);


#define a A0
#define b A1
#define c A2
#define d A3
#define e A4
#define f A5
#define g 10

#define Out(pin) pinMode(pin, OUTPUT)
#define sph(pin) digitalWrite(pin, HIGH)
#define spl(pin) digitalWrite(pin, LOW)
#define read(pin) digitalRead(pin)


void setup() {
Serial.begin(9600);
Serial.println("preuba del teclado matricial");
  Out(A0);
  Out(A1);
  Out(A2);
  Out(A3);
  Out(A4);
  Out(A5);
  Out(10);
}

void loop() {

char tecla = teclado.getKey();
if( teclado.getState() == NO_KEY){
   sph(a);
  sph(b);
  sph(c);
  sph(d);
  sph(e);
  sph(f);
  spl(g);
}
else{
switch (tecla){

case('1'):          // 1
{
  spl(a);
  sph(b);
  sph(c);
  spl(d);
  spl(e);
  spl(f);
  spl(g);
  break;
}

case('2'):          //2
{
  sph(a);
  sph(b);
  spl(c);
  sph(d);
  sph(e);
  spl(f);
  sph(g);
  break;
}

case('3'):          //3
{
  sph(a);
  sph(b);
  sph(c);
  sph(d);
  spl(e);
  spl(f);
  sph(g);
  break;
}

case('A'):         //A
{
  sph(a);
  sph(b);
  sph(c);
  spl(d);
  sph(e);
  sph(f);
  sph(g);
  break;
}

case('4'):          //4
{
  spl(a);
  sph(b);
  sph(c);
  spl(d);
  spl(e);
  sph(f);
  sph(g);
  break;
}

case('5'):          //5
{
  sph(a);
  spl(b);
  sph(c);
  sph(d);
  spl(e);
  sph(f);
  sph(g);
  break;
}

case('6'):          //6
{
  sph(a);
  spl(b);
  sph(c);
  sph(d);
  sph(e);
  sph(f);
  sph(g);
  break;
}

case('B'):          //b
{
  spl(a);
  spl(b);
  sph(c);
  sph(d);
  sph(e);
  sph(f);
  sph(g);
  break;
}

case('7'):          //7
{
  sph(a);
  sph(b);
  sph(c);
  spl(d);
  spl(e);
  spl(f);
  spl(g);
  break;
}

case('8'):          //8
{
  sph(a);
  sph(b);
  sph(c);
  sph(d);
  sph(e);
  sph(f);
  sph(g);
  break;
}

case('9'):          //9
{
  sph(a);
  sph(b);
  sph(c);
  spl(d);
  spl(e);
  sph(f);
  sph(g);
  break;
}

case('C'):          //C
{
  spl(a);
  spl(b);
  spl(c);
  sph(d);
  sph(e);
  spl(f);
  sph(g);
  break;
}

case('*'):          //*
{
  sph(a);
  spl(b);
  spl(c);
  spl(d);
  sph(e);
  sph(f);
  sph(g);
  break;
}

case('0'):          //0
{
  sph(a);
  sph(b);
  sph(c);
  sph(d);
  sph(e);
  sph(f);
  spl(g);
  break;
}

case('#'):          //#
{
  sph(a);
  spl(b);
  spl(c);
  sph(d);
  sph(e);
  sph(f);
  sph(g);
  break;
}

case('D'):          //D
{
  spl(a);
  sph(b);
  sph(c);
  sph(d);
  sph(e);
  spl(f);
  sph(g);
  break;
}

}
  }
}
