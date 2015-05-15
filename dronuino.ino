/*  Dronuino by @javi-rmrz & @gcc32 thanks to @mateoalvarez
	SEyTR Universidad Rey Juan Carlos 2015 (c)
	https://github.com/javi-rmrz/droneuino
*/


#include <VirtualWire.h> // so that the RF transmitter works
#include <ServoTimer2.h> // library no manage drone motors


String readString;
byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages 
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message


ServoTimer2 m1;
ServoTimer2 m2;
ServoTimer2 m3;
ServoTimer2 m4;
int powerValue; // the base power level given to the 4 motors

void setup() {
	// Starting serial monitor
	Serial.begin(9600);
	// Initialize the IO and ISR 
 	vw_setup(2000); // Bits per sec 
 	vw_rx_start(); // Start the receiver 

	// m1.writeMicroseconds(1500);
	// m2.writeMicroseconds(1500);
	// m3.writeMicroseconds(1500);
	// m4.writeMicroseconds(1500);
	 
	// m1.attach(2);
	// m2.attach(3);
	// m3.attach(4);
	// m4.attach(5);
	Serial.println("Droneuino ready to rock'n'roll"); // so I can keep track of what is loaded
	Serial.println("I can receive data wire o wireless!");


    
}

void loop() {
	if (vw_get_message(message, &messageLength)) // Non-blocking 
    { 
        Serial.print("Received: ");

        for (int i = 0; i < messageLength; i++) 
        { 
        Serial.write(message[i]); 
        }

        Serial.println(); 
    }  


	
	// while (Serial.available()) {
	// 	char c = Serial.read(); //gets one byte from serial buffer
	// 	readString += c; //makes the string readString
	// 	delay(2); //slow looping to allow buffer to fill with next character
	// }

	// 	if (readString.length() >0) {
	// 	Serial.println(readString); //so you can see the captured string 
	// 	int n = readString.toInt(); //convert readString into a number

	// 	Serial.print("Sending motor speed [0,180]: ");
	// 	Serial.println(n);
	// 	m1.write(n);
	// 	m2.write(n);
	// 	m3.write(n);
	// 	m4.write(n);

	// 	readString=""; // empty for next input
	// } 
}
