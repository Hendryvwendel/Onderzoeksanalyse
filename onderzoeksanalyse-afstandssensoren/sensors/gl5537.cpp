/** 
 * This file is for the GL5537 light sensor.
 * the sensor is connected to A5 on the Arduino Uno.
 * For now the code is written in Arduino Cpp.
 * For actual implementation, use low level programming.
 * The output is printed to serial monitor.
 * 
 * During testing, the weather was cloudy.
 * 5 cm gave the value of 65.
 * 60 cm gave the value of 185.
**/

#include <Arduino.h>

float voltage; // Variable to store the voltage value
float distance; // Variable to store the calculated distance

float calculateDistance(int sensorValue) {
    // Linear interpolation based on calibration data:
    // 65 analog value = 5 cm
    // 185 analog value = 60 cm
    // Formula: distance = slope * sensorValue + offset
    float slope = (60.0 - 5.0) / (185.0 - 65.0); // 55/120 = 0.458
    float offset = 5.0 - (slope * 65.0);
    return slope * sensorValue + offset;
}

void outputSensorValue(int value) {
    voltage = (value / 1023.0) * 5.0; // Convert the analog reading to voltage
    distance = calculateDistance(value); // Calculate distance
    
    Serial.print("Analog value: ");
    Serial.print(value);
    Serial.print(" | Voltage: ");
    Serial.print(voltage);
    Serial.print(" V | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
}

void setup() {
    Serial.begin(9600); // Start the serial communication at 9600 baud rate
    pinMode(A5, INPUT); // Set A5 as an input pin
}

void loop() {
    int sensorValue = analogRead(A5); // Read the value from the GL5537 sensor
    outputSensorValue(sensorValue);
    delay(1000); // Wait for 1 second before the next reading
}