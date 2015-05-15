// Motor ESC actually work as servos
// The motor power is an integer between [0,180]
// Do not power ESC's Vcc input from Arduino

String readString;

#include <Servo.h> 
Servo m1;
Servo m2;
Servo m3;
Servo m4;

void setup() {
	Serial.begin(9600);
	m1.writeMicroseconds(1500);
	m2.writeMicroseconds(1500);
	m3.writeMicroseconds(1500);
	m4.writeMicroseconds(1500);
	 
	m1.attach(2);
	m2.attach(3);
	m3.attach(4);
	m4.attach(5);
	Serial.println("Droneuino ready to rock'n'roll"); // so I can keep track of what is loaded
}

void loop() {
	while (Serial.available()) {
		char c = Serial.read(); //gets one byte from serial buffer
		readString += c; //makes the string readString
		delay(2); //slow looping to allow buffer to fill with next character
	}

		if (readString.length() >0) {
		Serial.println(readString); //so you can see the captured string 
		int n = readString.toInt(); //convert readString into a number

		Serial.print("Sending motor speed [0,180]: ");
		Serial.println(n);
		m1.write(n);
		m2.write(n);
		m3.write(n);
		m4.write(n);

		readString=""; // empty for next input
	} 
}