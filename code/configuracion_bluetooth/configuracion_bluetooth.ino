#include <SoftwareSerial.h> //Librería que permite establecer comunicación serie en otros pins
 
//Aquí conectamos los pins RXD,TDX del módulo Bluetooth.
SoftwareSerial BT(11,10); //10 RX, 11 TX.
 
void setup()
{
  // KEY TO WRITE (pin 9)
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);

  Serial.begin(9600); //Abrimos la comunicación serie con el PC y establecemos velocidad
  
  long baudios = 1200;
  while(!BT.available()){
    Serial.print("Trying to connect baudios: ");
    Serial.println(baudios);
    if(BT){
      BT.end();
    }
    BT.begin(baudios);
    delay(1000);
    BT.write("AT");
    delay(1000);
    
    if(baudios < 38400 || (baudios >= 57600 && baudios < 921600)){
      baudios = baudios * 2;
    }else if(baudios == 38400){
      baudios = 57600;
    }else if(baudios == 921600){
      baudios = 1382400;
    }else{
      baudios = 1200;
    }
    Serial.println("Conected");
  }
}
 
void loop()
{
  if(BT.available())
  {
    Serial.write(BT.read());
  }
 
  if(Serial.available())
  {
     BT.write(Serial.read());
  }
}
