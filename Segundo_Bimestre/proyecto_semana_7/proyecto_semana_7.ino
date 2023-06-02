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

#include <OneWire.h>
#include <LiquidCrystal_I2C.h>
#include <DallasTemperature.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

#define pin_servo 11
Servo servo_W;

Adafruit_NeoPixel led(7, 10, NEO_GRB + NEO_KHZ800);

LiquidCrystal_I2C LCD_W(0x27, 16, 2);

OneWire ourWire(2);                
DallasTemperature sensor(&ourWire);

#define buzz 9
#define rele 8
#define rele2 7
#define radar 6
#define R 5
#define G 4
#define B 3
#define L1 A0
#define L2 A1
#define door A2
#define sph(pin) digitalWrite(pin, HIGH)
#define spl(pin) digitalWrite(pin, LOW)
#define readPin(pin) digitalRead(pin)
int caso;
int value;
int value2;
int value3;
float Celsius;


enum colores{
  red,
  green,
  blue,
  orange,
  cian,
  geld
};

//*****************************************Animaciones*********************************************************

byte copo_1[8] = {
  0b00100,
  0b10101,
  0b01110,
  0b11111,
  0b01110,
  0b10101,
  0b00100,
  0b00000
};


byte face[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b01010,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};


byte fire[8] = {
  0b00000,
  0b00010,
  0b00110,
  0b01011,
  0b10111,
  0b11111,
  0b01110,
  0b00000
};

byte angry[8] = {
  0b11111,
  0b00000,
  0b10001,
  0b11011,
  0b00000,
  0b01110,
  0b10001,
  0b00000
};

byte light[8] = {
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b01010,
  0b01110,
  0b01110,
  0b00000
};

byte light_on[8] = {
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b01110,
  0b01110,
  0b00000
};

void setup() {
  
servo_W.attach(pin_servo);
led.begin();
led.clear();
sensor.begin();
LCD_W.init();
LCD_W.backlight();
LCD_W.createChar(1, copo_1);
LCD_W.createChar(2, face);
LCD_W.createChar(3, fire);
LCD_W.createChar(4, angry);
LCD_W.createChar(5, light);
LCD_W.createChar(6, light_on);
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, INPUT);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(3, OUTPUT);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
sph(rele);
sph(rele2);
LCD();
  LCD_W.setCursor(3,1);
  LCD_W.write(byte(5));
  LCD_W.setCursor(7,1);
  LCD_W.write(byte(5));
  LCD_W.setCursor(11,1);
  LCD_W.print("Close");
}



void loop() {
  Switches();
Celsius=Cel_grad();
Switches();
LCD();
Switches();
caso=parametro();
Switches();
leds();
Switches();
Radar();
Switches();

}


void Switches(){
  
  if(readPin(L1) && value == 0){
    
    spl(rele);
    LCD_W.setCursor(3,1);
    LCD_W.write(byte(6));
    delay(500);
    value = 1;
  }
  
  if(value == 1 && readPin(L1)){
  
  sph(rele);
    LCD_W.setCursor(3,1);
    LCD_W.write(byte(5));
    delay(500);
    value=0;
}

  
  if(readPin(L2) && value2 == 0){
    
    spl(rele2);
    LCD_W.setCursor(7,1);
    LCD_W.write(byte(6));
    delay(500);
    value2 = 1;
  }

if(value2 == 1 && readPin(L2)){
  
  sph(rele2);
    LCD_W.setCursor(7,1);
    LCD_W.write(byte(5));
    delay(500);
    value2=0;
}

  if(readPin(door) && value3 == 0){
    
    servo_W.write(0);
    LCD_W.setCursor(11,1);
    LCD_W.print("Open ");
    delay(500);
    value3 = 1;
}
    if(value3 == 1 && readPin(door)==HIGH){
  
  servo_W.write(90);
    LCD_W.setCursor(11,1);
    LCD_W.print("Close");
    delay(500);
    value3 = 0;
}
  
  }

void Radar(){
  if(readPin(radar) == HIGH){
  LCD_W.setCursor(7,0);
  LCD_W.print("Detected");
  LCD_W.write(byte(4));
  delay(250);
Neopixel();
}
else{
  LCD_W.setCursor(7,0);
  LCD_W.print("NoDetect");
  LCD_W.write(byte(2));
  delay(250);
}
}

void color(int colores){
  switch(colores){

     case(red):
     for(int i = 0; i < 8; i++){
      led.setPixelColor(i,led.Color(255,0,0));           //red
      led.show();
     }
     break;

    case(green):
     for(int i = 0; i < 8; i++){
      led.setPixelColor(i,led.Color(0,255,0));           //green
      led.show();
     }
     break;

     case(blue):
     for(int i = 0; i < 8; i++){
      led.setPixelColor(i,led.Color(0,0,255));           //blue
      led.show();
     }
     break;

     case(orange):
     for(int i = 0; i < 8; i++){
      led.setPixelColor(i,led.Color(255,140,0));           //orange
      led.show();
     }
     break;

     case(cian):
     for(int i = 0; i < 8; i++){
      led.setPixelColor(i,led.Color(0,255,255));           //cian
      led.show();
     }
     break;

     case(geld):
     for(int i = 0; i < 8; i++){
      led.setPixelColor(i,led.Color(255,255,0));           //geld
      led.show();
     }
     break;
  }
}


void Neopixel(){
  
    color(red);
    delay(250);
    Buzzer();
    color(green);
    delay(250);
    Buzzer();
    color(blue);
    delay(250);
    Buzzer();
    color(orange);
    delay(250);
    Buzzer();
    color(cian);
    delay(250);
    Buzzer();
    color(geld);
    delay(250);
    Buzzer();
    for(int i = 7; i>=0; i--){
     led.setPixelColor(i,led.Color(0,0,0));                //off
      led.show();
      delay(100);
     }
  
}

void Buzzer(){

  tone(buzz, 350);
  delay(500);
  noTone(buzz);
  tone(buzz, 250);
  delay(250);
  noTone(buzz);
}



void LCD(){
  LCD_W.setCursor(0,0);
  LCD_W.print("Temp:");
  LCD_W.setCursor(1,1);
  LCD_W.print("L1");
  LCD_W.setCursor(5,1);
  LCD_W.print("L2");
  LCD_W.setCursor(9,1);
  LCD_W.print("D:");
}



float Cel_grad(void){
  float _Celsius;
  sensor.requestTemperatures();
 _Celsius = sensor.getTempCByIndex(0);
 return _Celsius;
}



int parametro(void){
  int parametro;
  
if(Celsius >=15 && Celsius < 21){
  parametro=1;
}

if(Celsius >= 21 && Celsius < 25){
    parametro=2;
}

if(Celsius >= 25 && Celsius < 45){
    parametro=3;
}
 return parametro; 
}



void leds(){
  switch (caso){

    case(1):
    sph(R);
    spl(G);
    sph(B);
    LCD_W.setCursor(5,0);
    LCD_W.write(byte(1));
   break; 

    case(2):
    spl(R);
    sph(G);
    spl(B);
    LCD_W.setCursor(5,0);
    LCD_W.write(byte(2));
   break;

    case(3):
    sph(R);
    spl(G);
    spl(B);
    LCD_W.setCursor(5,0);
    LCD_W.write(byte(3));
   break;
  }
}
