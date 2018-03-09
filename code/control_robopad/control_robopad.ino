/**
 * CONTROL ARDUINO REMOTE CAR WITH ROBOPAD APP
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

/* PINES DE LOS MOTORES
 * Asignamos a que pines hemos conectado los motores izquierdo y derecho.
 * La asignación esta hecha mirando el robot desde atras.
 */
const int velocidadMotorDerecho = 3;
const int p1MotorDerecho = 2;
const int p2MotorDerecho = 4;
const int velocidadMotorIzquierdo = 6;
const int p1MotorIzquierdo = 5;
const int p2MotorIzquierdo = 7;

/* VARIBLES PARA DETERMINAR LA ACCIÓN
 * recibiremos los datos que nos envian por Bluetooth y decidiremos que acción debemos hacer
 */
char accion = 0; // Recibe las acciones y las pone en cola.
String colaDeAcciones = ""; // Guardamos la lista de acciones que vamos a realizar

void setup() {
  // SET PINS FOR MOTOR RIGHT
  pinMode(velocidadMotorDerecho,OUTPUT);
  pinMode(p1MotorDerecho,OUTPUT);
  pinMode(p2MotorDerecho,OUTPUT);
  
  // SET PINS FOR MOTOR LEFT
  pinMode(velocidadMotorIzquierdo,OUTPUT);
  pinMode(p1MotorIzquierdo,OUTPUT);
  pinMode(p2MotorIzquierdo,OUTPUT);
  
  // La app RoboPad esta configurada para transmitir a 19200 baudios
  BT.begin(19200); 
  Serial.begin(9600);
}

void loop() {
  if(BT && BT.available()) {   
    // Recibimos los datos del Bluetooth y los guardamos en una cola o los borramos si es 'S'
    accion = BT.read();
    // S = STOP | M = CONECTED
    if(accion!='S' && accion!='M'){
      if(colaDeAcciones.lastIndexOf(accion) == -1){
        //colaDeAcciones[i++] = BT.read();
        colaDeAcciones.concat(accion); 
      }
    }else{
      colaDeAcciones.remove(colaDeAcciones.length()-1); 
    }

    Serial.print(accion);
    Serial.print('\t');
    Serial.print(colaDeAcciones);
    Serial.print('\t');
    Serial.print(colaDeAcciones.length());
    Serial.print('\t');
    Serial.print(colaDeAcciones.lastIndexOf(accion));
    Serial.print('\n');

    if(colaDeAcciones=="U"){ // AVANZAR
      // MOTOR DERECHO
      analogWrite(velocidadMotorDerecho, 255);
      digitalWrite(p1MotorDerecho, HIGH);
      digitalWrite(p2MotorDerecho, LOW);
      
      // MOTOR IZQUIERDO
      analogWrite(velocidadMotorIzquierdo, 255);
      digitalWrite(p1MotorIzquierdo, HIGH);
      digitalWrite(p2MotorIzquierdo, LOW);
      
    }else if(colaDeAcciones=="L"){ // GIRAR A LA IZQUIERDA
      // MOTOR DERECHO
      analogWrite(velocidadMotorDerecho, 255);
      digitalWrite(p1MotorDerecho, HIGH);
      digitalWrite(p2MotorDerecho, LOW);
      
      // MOTOR IZQUIERDO
      analogWrite(velocidadMotorIzquierdo, 0);
      digitalWrite(p1MotorIzquierdo, LOW);
      digitalWrite(p2MotorIzquierdo, LOW);
    }else if(colaDeAcciones=="R"){ // GIRAR A LA DERECHA
      // MOTOR DERECHO
      analogWrite(velocidadMotorDerecho, 0);
      digitalWrite(p1MotorDerecho, LOW);
      digitalWrite(p2MotorDerecho, LOW);
      
      // MOTOR IZQUIERDO
      analogWrite(velocidadMotorIzquierdo, 255);
      digitalWrite(p1MotorIzquierdo, HIGH);
      digitalWrite(p2MotorIzquierdo, LOW);
    }else if(colaDeAcciones=="D"){ // RETROCEDER
      // MOTOR DERECHO
      analogWrite(velocidadMotorDerecho, 255);
      digitalWrite(p1MotorDerecho, LOW);
      digitalWrite(p2MotorDerecho, HIGH);
      
      // MOTOR IZQUIERDO
      analogWrite(velocidadMotorIzquierdo, 255);
      digitalWrite(p1MotorIzquierdo, LOW);
      digitalWrite(p2MotorIzquierdo, HIGH);
    }else{ // PARAR
      // MOTOR DERECHO
      analogWrite(velocidadMotorDerecho, 0);
      digitalWrite(p1MotorDerecho, LOW);
      digitalWrite(p2MotorDerecho, LOW);
      
      // MOTOR IZQUIERDO
      analogWrite(velocidadMotorIzquierdo, 0);
      digitalWrite(p1MotorIzquierdo, LOW);
      digitalWrite(p2MotorIzquierdo, LOW);
    }
  }
}

