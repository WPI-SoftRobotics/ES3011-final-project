#include <Arduino.h>
#include <Wire.h>
#include <smartmotor.h>

SmartMotor motor(0x0A); // INIT SMARTMOTOR

void setup() {
    // INIT SERIAL
    Serial.begin(115200);
    while(!Serial);

    Wire.begin(); // INIT ARDUINO UNO AS I2C CONTROLLER
}

int32_t target_angle=0;
void loop() {
    target_angle+=360; // INCREMENT SETPOINT
    uint8_t status= motor.write_angle(target_angle); // SET POSITION TARGET
    
    // READ MOTOR POSITION
    delay(1000); // WAIT FOR MOTOR TO REACH ITS SETPOINT
    int32_t pos = motor.read_angle();
    Serial.print("Pos: ");
    Serial.print(pos);
    Serial.println(" deg");

    // WAIT FOR 2 SECONDS
    delay(2000);
} 