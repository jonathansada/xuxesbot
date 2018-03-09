/**
 * RECIBIR ACCIONES DE LA APLICACIÓN ROBOPAD POR BLUETOOTH
 * 
 * Author: Jonathan Sada
 * Version: 1.0.0
 */
// Importamos la libreria SoftwareSerial que necesitamos para realizar la comunicación con el Bluetooth
#include <SoftwareSerial.h>

/* PINES BLUETOOTH
 * Definimos los pines RXD y TXD para preparar la conexión
 */
const int bt_rx = 10;
const int bt_tx = 11;
SoftwareSerial BT(bt_tx,bt_rx);

/* VARIBLES PARA DETERMINAR LA ACCIÓN
 * recibiremos los datos que nos envian por Bluetooth y decidiremos que acción debemos hacer
 */
char accion = 0; // Recibe las acciones y las pone en cola.

void setup() { 
  // La app RoboPad esta configurada para transmitir a 19200 baudios
  BT.begin(19200); 
  Serial.begin(9600);
}

void loop() {
  if(BT && BT.available()) {   
    // Recibimos los datos del Bluetooth 
    accion = BT.read();
    Serial.println(accion);
  }
}

