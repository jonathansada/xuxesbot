/**
 * CONTROL ARDUINO REMOTE CAR WITH ROBOPAD APP
 * 
 * Author: Jonathan Sada
 * Version: 1.0.0
 */
#include <SoftwareSerial.h> // Serial Comunication with other pins

/* Bluethoth vars
 * Connect RXD and TXD to Bluetooh module
 */
const int bt_rx = 10;
const int bt_tx = 11;
SoftwareSerial BT(bt_tx,bt_rx);

/** Buffer control vars, gets data from Bluetoth and saves it for execute actions **/
char action = 0; // Stores last recived action while are interpreted
String dataBuffer = ""; // Stores actions for execution


/* Motors vars
 * Right and Left is looked from robot's back.
 */
const int enableMotorRight = 3;
const int controlPin1MR = 2;
const int controlPin2MR = 4;
const int enableMotorLeft = 6;
const int controlPin1ML = 5;
const int controlPin2ML = 7;

void setup() {
  // SET PINS FOR MOTOR RIGHT
  pinMode(enableMotorRight,OUTPUT);
  pinMode(controlPin1MR,OUTPUT);
  pinMode(controlPin2MR,OUTPUT);
  
  // SET PINS FOR MOTOR LEFT
  pinMode(enableMotorLeft,OUTPUT);
  pinMode(controlPin1ML,OUTPUT);
  pinMode(controlPin2ML,OUTPUT);
  
  // Robopad program app is configured to use bluetooth at 19200 baudios
  BT.begin(19200); 
  Serial.begin(9600);
}

void loop() {
  if(BT && BT.available()) {   
    // Read the Bluetooth Serial and store it in the buffer or delete from buffer if is 'S'
    action = BT.read();
    // S = STOP | M = CONECTED
    if(action!='S' && action!='M'){
      if(dataBuffer.lastIndexOf(action) == -1){
        //dataBuffer[i++] = BT.read();
        dataBuffer.concat(action); 
      }
    }else{
      dataBuffer.remove(dataBuffer.length()-1); 
    }

    Serial.print(action);
    Serial.print('\t');
    Serial.print(dataBuffer);
    Serial.print('\t');
    Serial.print(dataBuffer.length());
    Serial.print('\t');
    Serial.print(dataBuffer.lastIndexOf(action));
    Serial.print('\n');

    if(dataBuffer=="U"){ // GO STRAIGHT
      _wheel_action(255, HIGH, LOW, 255, HIGH, LOW);
    }else if(dataBuffer=="L"){ // TURN LEFT
      _wheel_action(255, HIGH, LOW, LOW, LOW, LOW);
    }else if(dataBuffer=="R"){ // TURN RIGHT
      _wheel_action(LOW, LOW, LOW, 255, HIGH, LOW);
    }else if(dataBuffer=="D"){ // GO BACK
      _wheel_action(255, LOW, HIGH, 255, LOW, HIGH);
    }else if(dataBuffer=="UL" || dataBuffer=="LU"){ // GO STRAIGHT TURNING LEFT
      _wheel_action(255, HIGH, LOW, 200, HIGH, LOW);
    }else if(dataBuffer=="UR" || dataBuffer=="RU"){ // GO STRAIGHT TURNING RIGHT
      _wheel_action(200, HIGH, LOW, 255, HIGH, LOW);
    }else if(dataBuffer=="DL" || dataBuffer=="LD"){ // GO BACK TURNING LEFT
      _wheel_action(255, LOW, HIGH, 200, LOW, HIGH);
    }else if(dataBuffer=="DR" || dataBuffer=="RD"){ // GO BACK TURNING RIGHT
      _wheel_action(200, LOW, HIGH, 255, LOW, HIGH);
    }else{ // STOP
      _wheel_action(LOW, LOW, LOW, LOW, LOW, LOW);
    }
  }
}

/* Sets values to wheels for write less code in similar functions.
 * int MR_speed - Speed for right motor (0 - 255)
 * int MR_P1 - Motor right pin 1 value (LOW|HIGH)
 * int MR_P2 - Motor right pin 2 value (LOW|HIGH)
 * int ML_speed - Speed for left motor (0 - 255)
 * int ML_P1 - Motor left pin 1 value (LOW|HIGH)
 * int ML_P2 - Motor left pin 2 value (LOW|HIGH)
 */
void _wheel_action(int MR_speed, int MR_P1, int MR_P2, int ML_speed, int ML_P1, int ML_P2){
  // MOTOR RIGHT
  analogWrite(enableMotorRight,MR_speed);
  digitalWrite(controlPin1MR, MR_P1);
  digitalWrite(controlPin2MR, MR_P2);
  
  // MOTOR LEFT
  analogWrite(enableMotorLeft,ML_speed);
  digitalWrite(controlPin1ML, ML_P1);
  digitalWrite(controlPin2ML, ML_P2);
}

