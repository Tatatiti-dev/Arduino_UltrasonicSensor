#include <UltrasonicSensor.h> // Include the library

// Define the ultrasonic sensor with Trig on 2 and Echo on 3 pins
UltrasonicSensor uss(2,3); 

void setup(){
  Serial.begin(9600); // Initialize serial port
  uss.begin(); // Initialize sensor
}
float lastDistance = 0;// Variable for last distance
void loop(){
  uss.request(); // Read data from sensor
  // Is the difference between last distance \
  and current distance bigger than 5 cm?
  if(abs(uss.getDistanceCm()-lastDistance) > 5){ 
    Serial.println("Motion detected!");
    lastDistance = uss.getDistanceCm(); //Save current distance
    delay(2000); // Wait before next read
  }
}
