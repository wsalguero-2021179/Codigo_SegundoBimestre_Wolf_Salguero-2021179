/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Wolf Salguero
 * Carnet: 2021179
 * Proyecto: Proyecto Final - Multimetro
*/

//libreria

//Directivas de preprocesador
#define entrada A0

//Variables
float den;
float num;
float Vout;
int Vcc=5;
int R2 = 10000;
int R1;
float sensorPin = A1;   // seleccionar la entrada para el sensor
float sensorValue;      // variable que almacena el valor raw (0 a 1023)
float voltage, amp;
float Sensibilidad=0.185;
char v[8];
char a[8];
char buffer[23];
char y[1] = ",";



void setup() {
Serial.begin(9600);
Serial.println("Multimetro:");
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);

}

void loop() {

int x;
int res = resistencia_value();
float volt = voltaje_value();
float mA = amp_value();

sprintf(buffer, "%d, %d", res,x);
dtostrf(volt, 5, 2, v);
dtostrf(mA, 5, 2, a);
strcat(buffer, y);
strcat(buffer, v);
strcat(buffer, y);
strcat(buffer, a);
Serial.println(buffer);
delay(1000);
}




int resistencia_value (){
  Vout = analogRead(entrada);
Vout = ((5 * Vout)/1023);
if(Vout)
{
num= Vcc - Vout;
den = Vout;
R1 = (num/den) * R2;
}
return R1;
}

float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float voltaje_value(){
sensorValue = analogRead(sensorPin);        // realizar la lectura
  voltage = fmap(sensorValue, 0, 1023, 0.0, 25.0);   // cambiar escala a 0.0 - 25.0
  return voltage;
}

float amp_value(){
  float voltajeSensor;
  for(int i=0; i<200;i++){
    voltajeSensor = analogRead(A2) * (5.0 / 1023.0);
    amp = amp + (voltajeSensor - 2.5)/Sensibilidad;
  }
amp = amp/200;

  return amp;
}
