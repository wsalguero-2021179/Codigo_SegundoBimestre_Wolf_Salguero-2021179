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
//struct
struct  item{
char    nombre_del_producto[8];
float   precio_u;
int     stock;
char    reserva[25];
float   precio_por_lote; 
};

#define asc_button 13
#define des_button 12
#define cancelar 11
#define PinIn(pin) pinMode(pin, INPUT)
#define readPin(pin) digitalRead(pin)
int posicion = 1;
int x = 1;
int t = 250;

//productos
item item1 = {"Lays", 5.00, 25, "No hay en existencias", 50.00};
item item2 = {"Coke", 5.00, 30, "Si hay en existencias", 25.00};
item item3 = {"Cheetos", 5.00, 27, "No hay en existencias", 50.00};
item item4 = {"Tortrix", 1.00, 24, "Si hay en existencias", 35.00};

void setup() {
Serial.begin(9600);
Serial.println("Elija lo que desea");
Serial.println(" ");
PinIn(13);
PinIn(12);
PinIn(11);
}
void loop() {
  
if(readPin(asc_button)== HIGH){
  x=1;
}
if(readPin(des_button)== HIGH){
x=1;
}

if(readPin(cancelar) == HIGH){
  Serial.println("Usted ha cancelado...");
  Serial.println("Que tenga un Buen dia :)");
  delay(t);
  abort();
}

while(x==1){                                //while
 
  if(readPin(asc_button)== HIGH){
posicion++;
}
if(posicion>4){
  posicion=1;
}

if(readPin(des_button)== HIGH){
  posicion--;
  }
if(posicion< 1){
  posicion=4;
}



switch(posicion){
  //producto 1
  case(1):
  Serial.println("Opcion 1");
Serial.print("Producto seleccionado:");
Serial.println(item1.nombre_del_producto);
Serial.print("Precio unitario:Q.");
Serial.println(item1.precio_u);
Serial.print("Cantidad en stock: ");
Serial.println(item1.stock);
Serial.print("Cantidad en reserva: ");
Serial.println(item1.reserva);
Serial.print("Precio por lote(10):Q.");
Serial.println(item1.precio_por_lote);
Serial.println(" ");
delay(t);
x=2;
break;
//producto 2
  case(2):
  Serial.println("Opcion 2");
Serial.print("Producto seleccionado:");
Serial.println(item2.nombre_del_producto);
Serial.print("Precio unitario:Q.");
Serial.println(item2.precio_u);
Serial.print("Cantidad en stock: ");
Serial.println(item2.stock);
Serial.print("Cantidad en reserva: ");
Serial.println(item2.reserva);
Serial.print("Precio por lote(5):Q.");
Serial.println(item2.precio_por_lote);
Serial.println(" ");
delay(t);
x=2;
break;
//producto 3
  case(3):
  Serial.println("Opcion 3");
Serial.print("Producto seleccionado:");
Serial.println(item3.nombre_del_producto);
Serial.print("Precio unitario:Q.");
Serial.println(item3.precio_u);
Serial.print("Cantidad en stock: ");
Serial.println(item3.stock);
Serial.print("Cantidad en reserva: ");
Serial.println(item3.reserva);
Serial.print("Precio por lote(10):Q.");
Serial.println(item3.precio_por_lote);
Serial.println(" ");
delay(t);
x=2;
break;
//producto 4
  case(4):
  Serial.println("Opcion 4");
Serial.print("Producto seleccionado:");
Serial.println(item4.nombre_del_producto);
Serial.print("Precio unitario:Q.");
Serial.println(item4.precio_u);
Serial.print("Cantidad en stock: ");
Serial.println(item4.stock);
Serial.print("Cantidad en reserva: ");
Serial.println(item4.reserva);
Serial.print("Precio por lote(35):Q.");
Serial.println(item4.precio_por_lote);
Serial.println(" ");
delay(t);
x=2;
break;
}
}
}
