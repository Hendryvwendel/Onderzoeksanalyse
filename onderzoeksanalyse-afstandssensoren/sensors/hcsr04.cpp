/** 
 * This file is for the HC-SR04 ultrasonic sensor.
 * The trigger pin is connected to pin 2.
 * The echo pin is connected to pin 3.
 * The sensor works by sending a 10us pulse to the trigger pin.
 * For now the code is written in Arduino Cpp.
 * For actual implementation, use low level programming.
 * The output is the distance measured by the sensor.
**/

#include <Arduino.h>

float voltage; // Variable to store the voltage value

void outputSensorValue(int value) {
    Serial.print("Distance: ");
    Serial.print(value);
    Serial.println(" cm");
}

void setup() {
    Serial.begin(9600); // Start the serial communication at 9600 baud rate
    pinMode(2, OUTPUT); // Set pin 2 as an output pin (trigger)
    pinMode(3, INPUT);  // Set pin 3 as an input pin (echo)
}

void loop() {
    digitalWrite(2, HIGH); // Send a 10us pulse to the trigger pin
    delayMicroseconds(10);
    digitalWrite(2, LOW);

    long duration = pulseIn(3, HIGH); // Read the echo pin
    float distance = (duration * 0.0343) / 2; // Calculate the distance

    outputSensorValue(distance);

    delay(1000);
    delay(1000); // Wait for 1 second before the next reading
}
