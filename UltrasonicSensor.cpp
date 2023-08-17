#include <Arduino.h>
#include <UltrasonicSensor.h>

UltrasonicSensor::UltrasonicSensor(int _trig, int _echo){
	trig = _trig;
	echo = _echo;
}
void UltrasonicSensor::begin() {
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
}
void UltrasonicSensor::request(){
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);
	float duration = pulseIn(echo, HIGH);
	distance = (duration/2) / 29.1;   //vypočítání v cm
	if(distance > 1000)distance = -1;
}
float UltrasonicSensor::readAverageDistance(byte iterations){
	float buffer = 0;
	
	for(int i = 0; i < iterations; i++){
		request();
		if(distance != -1)buffer += distance;
	}
	if(buffer / (float)iterations == 0)distance = -1;
	else distance = (buffer/(float)iterations);
	return distance;
}
float UltrasonicSensor::getDistanceCm(){
	return distance;
}
float UltrasonicSensor::readDistanceCm(){
	request();
	return distance;
}