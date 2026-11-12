#include <Arduino.h>
#include <Wire.h>
#include <simplesmartmotor.h>

SimpleSmartMotor motor(Wire,0x0A); // Declare motor object

float target_angle=360.0f * 5; // Set target angle [deg]

void setup() {
    Serial.begin(9600);
    while(!Serial);

    Wire.begin(); // Init master i2c device
    motor.begin(); // Init smartmotor
    
    motor.tune_pos_pid(1.0f,0.0f,0.0f); //  Set position controller gains
    
    delay(5000); // Wait for 5 seconds

    motor.write_angle(target_angle); // Set target angle
}

void loop() {
    Serial.print(target_angle); // Print target angle
    Serial.print(",");
    Serial.print(0.98*target_angle);
    Serial.print(",");
    Serial.print(1.02*target_angle);
    Serial.print(",");
    Serial.println(motor.read_feedback()); // Print current angle 

    delay(20); // Wait 20 ms before next loop
} 