/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Wolf Salguero
 * Carnet: 2021179
 * Proyecto: Ejercicio 1 - Práctica 1
*/


//Directivas de preprocesador
#define sph(pin) digitalWrite(pin, HIGH)
#define spl(pin) digitalWrite(pin, LOW)
#define a 12
#define b 11
#define c 10
#define d 9
#define a2 8
#define b2 7
#define c2 6
#define d2 5
#define btn_asc  2     
#define btn_des 3     

//Funciones ISR 
void contador_asc(void);
void contador_des(void);

//Variables
volatile static bool var_status=false; // variable para mostrar en texto en el loop
volatile static unsigned char i=0; // variable que cuenta de 0 - 255;


void setup() {
  
  Serial.begin(19200); //Inicio la comunicación serial
  pinMode(btn_asc, INPUT);  //pin 2 como entrada
  pinMode(btn_des, INPUT); //pin 3 como entrada
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(d2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(btn_asc),contador_asc,RISING);   //Anclar la interrupción del pin 2 a una funcion de ISR, disparada por el flanco ascendente
  attachInterrupt(digitalPinToInterrupt(btn_des),contador_des,FALLING); //Anclar la interrupción del pin 3 a una funcion de ISR, disparada por el flanco descendente
  Serial.println(i);
}

void loop() {
  
if(var_status == HIGH && i <= 50 && i >= 0)
{
  var_status = false; //limpio la variable
  Display();
}
if(i>50 && i<55){
  i=0;
}

if(i>254){
  i=50;
  
}
}


//Funciones de ISR
void contador_asc(void)
{
  var_status = true;
  //aumentar el valor de la variable
  i++; 
}

void contador_des(void)
{
  var_status = true;
  //disminuir el valor de una variable
  i--;
}

void Display(){

switch(i)
{
  //0
  case(0):
  spl(a);
  spl(b);
  spl(c);
  spl(d);
  spl(a2);
  spl(b2);
  spl(c2);
  spl(d2);
  break;

  //1
  case(1):
  spl(a);
  spl(b);
  spl(c);
  sph(d);
  break;

  //2
  case(2):
  spl(a);
  spl(b);
  sph(c);
  spl(d);
  break;

  //3
  case(3):
  spl(a);
  spl(b);
  sph(c);
  sph(d);
  break;

  //4
  case(4):
  spl(a);
  sph(b);
  spl(c);
  spl(d);
  break;

  //5
  case(5):
  spl(a);
  sph(b);
  spl(c);
  sph(d);
  break;

  //6
  case(6):
  spl(a);
  sph(b);
  sph(c);
  spl(d);
  break;

  //7
  case(7):
  spl(a);
  sph(b);
  sph(c);
  sph(d);
  break;

  //8
  case(8):
  sph(a);
  spl(b);
  spl(c);
  spl(d);
  break;

  //9
  case(9):
  sph(a);
  spl(b);
  spl(c);
  sph(d);
  spl(a2);
  spl(b2);
  spl(c2);
  spl(d2);
  break;

  //10
  case(10):
  spl(a);
  spl(b);
  spl(c);
  spl(d);
  spl(a2);
  spl(b2);
  spl(c2);
  sph(d2);
  break;

  //11
  case(11):
  spl(a);
  spl(b);
  spl(c);
  sph(d);
  break;

  //12
  case(12):
  spl(a);
  spl(b);
  sph(c);
  spl(d);
  break;

  //13
  case(13):
  spl(a);
  spl(b);
  sph(c);
  sph(d);
  break;

  //14
  case(14):
  spl(a);
  sph(b);
  spl(c);
  spl(d);
  break;

  //15
  case(15):
  spl(a);
  sph(b);
  spl(c);
  sph(d);
  break;

  //16
  case(16):
  spl(a);
  sph(b);
  sph(c);
  spl(d);
  break;

  //17
  case(17):
  spl(a);
  sph(b);
  sph(c);
  sph(d);
  break;

  //18
  case(18):
  sph(a);
  spl(b);
  spl(c);
  spl(d);
  break;

  //19
  case(19):
  sph(a);
  spl(b);
  spl(c);
  sph(d);
  spl(a2);
  spl(b2);
  spl(c2);
  sph(d2);
  break;

  //20
  case(20):
  spl(a);
  spl(b);
  spl(c);
  spl(d);
  spl(a2);
  spl(b2);
  sph(c2);
  spl(d2);
  break;

  //21
  case(21):
  spl(a);
  spl(b);
  spl(c);
  sph(d);
  break;

  //22
  case(22):
  spl(a);
  spl(b);
  sph(c);
  spl(d);
  break;

  //23
  case(23):
  spl(a);
  spl(b);
  sph(c);
  sph(d);
  break;

  //24
  case(24):
  spl(a);
  sph(b);
  spl(c);
  spl(d);
  break;

  //25
  case(25):
  spl(a);
  sph(b);
  spl(c);
  sph(d);
  break;

  //26
  case(26):
  spl(a);
  sph(b);
  sph(c);
  spl(d);
  break;

  //27
  case(27):
  spl(a);
  sph(b);
  sph(c);
  sph(d);
  break;

  //28
  case(28):
  sph(a);
  spl(b);
  spl(c);
  spl(d);
  break;

  //29
  case(29):
  sph(a);
  spl(b);
  spl(c);
  sph(d);
  spl(a2);
  spl(b2);
  sph(c2);
  spl(d2);
  break;

  //30
  case(30):
  spl(a);
  spl(b);
  spl(c);
  spl(d);
  spl(a2);
  spl(b2);
  sph(c2);
  sph(d2);
  break;

  //31
  case(31):
  spl(a);
  spl(b);
  spl(c);
  sph(d);
  break;

  //32
  case(32):
  spl(a);
  spl(b);
  sph(c);
  spl(d);
  break;

  //33
  case(33):
  spl(a);
  spl(b);
  sph(c);
  sph(d);
  break;

  //34
  case(34):
  spl(a);
  sph(b);
  spl(c);
  spl(d);
  break;

  //35
  case(35):
  spl(a);
  sph(b);
  spl(c);
  sph(d);
  break;

  //36
  case(36):
  spl(a);
  sph(b);
  sph(c);
  spl(d);
  break;

  //37
  case(37):
  spl(a);
  sph(b);
  sph(c);
  sph(d);
  break;

  //38
  case(38):
  sph(a);
  spl(b);
  spl(c);
  spl(d);
  break;

  //39
  case(39):
  sph(a);
  spl(b);
  spl(c);
  sph(d);
  spl(a2);
  spl(b2);
  sph(c2);
  sph(d2);
  break;

  //40
  case(40):
  spl(a);
  spl(b);
  spl(c);
  spl(d);
  spl(a2);
  sph(b2);
  spl(c2);
  spl(d2);
  break;

  //41
  case(41):
  spl(a);
  spl(b);
  spl(c);
  sph(d);
  break;

  //42
  case(42):
  spl(a);
  spl(b);
  sph(c);
  spl(d);
  break;

  //43
  case(43):
  spl(a);
  spl(b);
  sph(c);
  sph(d);
  break;

  //44
  case(44):
  spl(a);
  sph(b);
  spl(c);
  spl(d);
  break;

  //45
  case(45):
  spl(a);
  sph(b);
  spl(c);
  sph(d);
  break;

  //46
  case(46):
  spl(a);
  sph(b);
  sph(c);
  spl(d);
  break;

  //47
  case(47):
  spl(a);
  sph(b);
  sph(c);
  sph(d);
  break;

  //48
  case(48):
  sph(a);
  spl(b);
  spl(c);
  spl(d);
  break;

  //49
  case(49):
  sph(a);
  spl(b);
  spl(c);
  sph(d);
  spl(a2);
  sph(b2);
  spl(c2);
  spl(d2);
  break;

  //50
  case(50):
  spl(a);
  spl(b);
  spl(c);
  spl(d);
  spl(a2);
  sph(b2);
  spl(c2);
  sph(d2);
  break;
  
}
  
}
