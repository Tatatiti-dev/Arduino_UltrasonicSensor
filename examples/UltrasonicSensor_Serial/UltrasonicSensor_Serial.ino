#include <UltrasonicSensor.h>

UltrasonicSensor uss(2,3);

void setup(){
  Serial.begin(9600);
  uss.begin();
}
void loop(){
  Serial.print("Distance: ");
  Serial.print(uss.readVal());
  Serial.println(" cm");
  Serial.print("Average(5): ");
  Serial.print(uss.median(5));
  Serial.println(" cm");
  Serial.println();
  delay(1000);
}
