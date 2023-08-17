#include <Arduino.h>

#ifndef ULTRASONIC_LIB
#define ULTRASONIC_LIB

class UltrasonicSensor{
	private:
		int trig;
		int echo;
		float distance;
	public:
		/**
		 * @param _trig Trigger pin of the sensor
		 * @param _echo Echo pin of the sensor
		 */
		UltrasonicSensor(int _trig, int _echo);
		/**
		 * Initializes the pins
		 */
		void begin();
		/**
		 * Reads the distance from sensor
		 */
		void request();
		/**
		 * Reads the distance more times, computes the average value and returns that
		 *
		 * @param iterations Set how many iterations of measure will be processed
		 * @return Average value from more measures
		 */
		float readAverageDistance(byte iterations = 4);
		/**
		 * Returns the distance measured by request(), readDistanceCm() or averageDistance()
		 * When you want to get current distance, call readDistanceCm
		 *
		 * @return distance in centimeters from last measure
		 */
		float getDistanceCm();
		/**
		 * Measures the distance and returns that
		 *
		 * @return distance in centimeters measured now
		 */
		float readDistanceCm();
		/**
		 * DEPRECATED
		 * Returns the measured distance
		 * When you want to get current distance, call readDistanceCm or readVal
		 *
		 * @return distance in centimeters from last measure
		 */
		float getVal(){return getDistanceCm();}
		/**
		 * DEPRECATED
		 * Measures the distance and returns that
		 *
		 * @return distance in centimeters measured now
		 */
		float readVal(){return readDistanceCm();}
};

#endif