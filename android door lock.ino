#include<Servo.h>
#include <SoftwareSerial.h> // TX RX software library for bluetooth
int bluetoothTx = 11; // bluetooth tx to 10 pin
int bluetoothRx = 10; // bluetooth rx to 11 pin
int s=9; //servo pin
Servo servo;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
void setup() {
  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
  //servo
  servo.attach(s);
}

void loop() {
    //Read from bluetooth and write to usb serial
  if(bluetooth.available()> 0 ) // receive number from bluetooth
  {
    int a = bluetooth.read(); // save the received number to servopos
      if(a==245)//unlock
    {
      servo.write(0);
    }
    if(a==225)//lock
    {
      servo.write(90);
    }
    delay(50);
  }
}
