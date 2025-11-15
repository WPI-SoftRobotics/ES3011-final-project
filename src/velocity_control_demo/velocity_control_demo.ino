#include <Arduino.h>
#include <Wire.h>
#include <smartmotor.h>

SmartMotor motor(0x0A); // INIT SMARTMOTOR
int32_t target_speed=60; // SET TARGET VELOCITY TO 60 RPM (CCW)

void setup() {
    // INIT SERIAL
    Serial.begin(115200);
    while(!Serial);

    Wire.begin(); // INIT ARDUINO UNO AS I2C CONTROLLER
    uint8_t status= motor.write_rpm(target_speed); // SET VELOCITY TARGET
}

void loop() {    
    // READ MOTOR VELOCITY
    int32_t vel = motor.read_rpm();
    Serial.print("Vel: ");
    Serial.print(vel);
    Serial.println(" RPM");

    // WAIT FOR 2 SECONDS
    delay(2000);
} 