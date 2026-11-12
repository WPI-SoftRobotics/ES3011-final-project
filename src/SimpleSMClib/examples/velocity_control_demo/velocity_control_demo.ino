#include <Arduino.h>
#include <Wire.h>
#include <simplesmartmotor.h>

SimpleSmartMotor motor(Wire,0x0A); // Declare motor object

float target_speed= 60.0f; // Set target speed [rpm]

void setup() {
    Serial.begin(9600);
    while(!Serial);

    Wire.begin(); // Init master i2c device
    motor.begin(); // Init smartmotor

    motor.write_rpm(0.0f); // Stop motor

    motor.tune_vel_pid(1.0f,0.0f,0.0f); //  Set velocity controller gains

    delay(5000); // Wait for 5 seconds

    motor.write_rpm(target_speed); // Set target speed
}

void loop() {
    Serial.print(target_speed); // Print target speed
    Serial.print(",");
    Serial.print(0.98*target_speed);
    Serial.print(",");
    Serial.print(1.02*target_speed);
    Serial.print(",");
    Serial.println(motor.read_feedback()); // Print current speed
    
    delay(20); // Wait 20 ms before next loop
} 