/* 
Transmit a short text message using the VirtualWire library 
connect the Transmitter data pin to Arduino pin 12 
*/

#include <VirtualWire.h> // so that the RF transmitter works

String powerValueAsString = "";
int powerValue; // the base power level given to the 4 motors

void setup() 
{ 
 // Initialize the IO and ISR 
 vw_setup(2000); // Bits per sec 
 Serial.begin(9600);
}

void loop() 
{  
 while (Serial.available()) {
   char c = Serial.read(); //gets one byte from serial buffer
   powerValueAsString += c; //makes the string readString
   delay(2); //slow looping to allow buffer to fill with next character
 }
 
 if (powerValueAsString.length() >0) {
   powerValue = powerValueAsString.toInt(); //convert it into a number
 } 
 const char *charMsg = powerValueAsString.c_str();
 
 vw_send((uint8_t *)charMsg, strlen(charMsg));
 vw_wait_tx(); // Wait until the whole message is gone 
 
 Serial.print("Message sent: ");
 Serial.println(charMsg);
 Serial.println(strlen(charMsg));
 
 powerValueAsString = ""; //empty for the next iteration
 delay(1000);
}

void send (char *message) 
{ 
 vw_send((uint8_t *)message, strlen(message)); 
 vw_wait_tx(); // Wait until the whole message is gone 
}
