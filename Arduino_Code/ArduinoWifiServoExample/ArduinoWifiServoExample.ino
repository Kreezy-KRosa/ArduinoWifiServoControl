//Wifi Arduino Servo Control with NodeMCU Example Code
//by Kreezy(KRosa) 1.12.2018

//Example Video can be found @ https://youtu.be/q4Ya8fxmjBw

//Upload this to your Arduino Board

#include <Servo.h>  // includes the Servo library

Servo myservo;  // create servo object to control a servo

const int comm = 2;  // Nodemcu connected to pin 2 on this arduino board
int commState = 0;   // variable to hold comm state

void setup() {
 
 pinMode(comm,INPUT); // sets pin 2 as an input pin
 
 myservo.attach(15);  // attaches the servo on pin 15 to the servo object
 
 Serial.begin(9600);  // starts serial comm for debugging @ 9600baud
}

void loop() {

  commState = digitalRead(comm); // checking the state of pin 2 for high or low

  if (commState == HIGH) {       // if pin 2 is high move the servo to 180 degrees
    myservo.write(180);
  } else {
    myservo.write(15);          // if pin 2 is low move the servo to 15 degrees
  }
  Serial.println(comm);     // prints commState in serial monitor
  
  delay(15);                // waits for the servo to get there

}
  

