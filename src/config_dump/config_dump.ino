#include <Arduino.h>
#include <Wire.h>
#include <smartmotor.h>
#include <smc_gains.h>

void setup() {
    Serial.begin(115200);
    while(!Serial);

    // READ CURRENT ADDRESS
    Serial.println("ENTER SMC ADDRESS (1-127)...");
    while(Serial.available() == 0) { delay(500); } // BLOCK UNTIL WE HAVE A NEW VALUE TO READ
    String addr_str= Serial.readString();
    uint8_t addr= (uint8_t)addr_str.toInt();

    Wire.begin(); // INIT DEVICE AS I2C CONTROLLER
    SmartMotor motor(addr); // INIT MOTOR W/ DEFAULT ADDRESS
    
    
    Serial.println();
    Serial.println("SMC Configuration");
    Serial.println("--------------------------------------");
    Serial.print("Gear Ratio: ");
    Serial.println(motor.get_gear_ratio());
    Serial.print("Direction: ");
    Serial.println(static_cast<uint8_t>(motor.get_direction()));
    Serial.print("Ticks Per Revolution: ");
    Serial.println(motor.get_ticks_per_rev());
    Serial.println();
    
    Gains pos_gains=motor.get_pos_gains();
    Serial.println("Position PID Gains: ");
    Serial.println("------------------");
    Serial.print("Kp: ");
    Serial.println(pos_gains.kp);
    Serial.print("Ki: ");
    Serial.println(pos_gains.ki);
    Serial.print("Kd: ");
    Serial.println(pos_gains.kd);
    Serial.println();

    Gains vel_gains=motor.get_vel_gains();
    Serial.println("Velocity PID Gains: ");
    Serial.println("------------------");
    Serial.print("Kv: ");
    Serial.println(vel_gains.kv);
    Serial.print("Kp: ");
    Serial.println(vel_gains.kp);
    Serial.print("Ki: ");
    Serial.println(vel_gains.ki);
    Serial.print("Kd: ");
    Serial.println(vel_gains.kd);
}

void loop() { }