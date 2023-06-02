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

#include <LiquidCrystal.h>

LiquidCrystal LCD_W(12, 11, 10, 9, 8, 7);

void setup() {
LCD_W.begin(16, 2);

LCD_W.setCursor(1,0);
LCD_W.print("Wolf Salguero");
LCD_W.setCursor(1,1);
LCD_W.print("2021179");

}

void loop() {



}
