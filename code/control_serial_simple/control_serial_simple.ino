/**
 * CONTROLAR COCHE ARDUINO CON EL TECLADO POR SERIAL
 * 
 * Author: Jonathan Sada
 * Version: 1.0.0
 */
#include <SoftwareSerial.h>

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
 * recibiremos los datos que nos envian y decidiremos que acción debemos hacer
 */
char accion; // Recibe las acciones y las pone en cola.

void setup() {
  // SET PINS FOR MOTOR RIGHT
  pinMode(velocidadMotorDerecho,OUTPUT);
  pinMode(p1MotorDerecho,OUTPUT);
  pinMode(p2MotorDerecho,OUTPUT);
  
  // SET PINS FOR MOTOR LEFT
  pinMode(velocidadMotorIzquierdo,OUTPUT);
  pinMode(p1MotorIzquierdo,OUTPUT);
  pinMode(p2MotorIzquierdo,OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {   
    // Obtenemos datos del Serial
    accion ='a';
    Serial.println(Serial.read());
    if(accion=='W'){ // ABANZAR
      // MOTOR DERECHO
      analogWrite(velocidadMotorDerecho, 255);
      digitalWrite(p1MotorDerecho, HIGH);
      digitalWrite(p2MotorDerecho, LOW);
      
      // MOTOR IZQUIERDO
      analogWrite(velocidadMotorIzquierdo, 255);
      digitalWrite(p1MotorIzquierdo, HIGH);
      digitalWrite(p2MotorIzquierdo, LOW);
      
    }else if(accion=='A'){ // GIRAR A LA IZQUIERDA
      // MOTOR DERECHO
      analogWrite(velocidadMotorDerecho, 255);
      digitalWrite(p1MotorDerecho, HIGH);
      digitalWrite(p2MotorDerecho, LOW);
      
      // MOTOR IZQUIERDO
      analogWrite(velocidadMotorIzquierdo, 0);
      digitalWrite(p1MotorIzquierdo, LOW);
      digitalWrite(p2MotorIzquierdo, LOW);
      
    }else if(accion=='D'){ // GIRAR A LA DERECHA
  	  // MOTOR DERECHO
      analogWrite(velocidadMotorDerecho, 0);
      digitalWrite(p1MotorDerecho, LOW);
      digitalWrite(p2MotorDerecho, LOW);
      
      // MOTOR IZQUIERDO
      analogWrite(velocidadMotorIzquierdo, 255);
      digitalWrite(p1MotorIzquierdo, HIGH);
      digitalWrite(p2MotorIzquierdo, LOW);
    }else if(accion=='S'){ // RETROCEDER
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

