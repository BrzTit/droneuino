void setup() {
  // initialize digital pin 13 as an output.
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(30);              // wait for a second
  digitalWrite(10, LOW);
  delay(65); 
  digitalWrite(10, HIGH);
  delay(30);              // wait for a second
  digitalWrite(10, LOW);
  delay(100);
  digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(30);              // wait for a second
  digitalWrite(11, LOW);
  delay(65); 
  digitalWrite(11, HIGH);
  delay(30);              // wait for a second
  digitalWrite(11, LOW);
 
  
  delay(1000);
  
  
  
            // wait for a second
}