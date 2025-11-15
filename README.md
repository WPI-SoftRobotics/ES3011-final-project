# ES3011 Final Project

## CAD
Includes STL files for the vehicle chassis and wheels.

## src
 - config_dump -- prints all configuration variables for the smartmotor with the address entered into the Arduino IDE Serial Monitor
 - i2c_scanner -- scans for any I2C devices connected to the microcontroller and prints the address of any devices found (note: this could be useful if you don't know the address of a smartmotor)
 - pid_tuning_demo -- sets both the position and velocity pid gains before printing the new values to the Serial Monitor
 - position_control_demo -- rotates a smartmotor 360 deg in the positive direction (CCW) every 2 seconds and prints the current motor position to the Serial Monitor
  - SMClib -- a library containing all of the code necessary to operate the smartmotors including a wrapper class (i.e., Smartmotor) which handles all of the low-level communication between the microcontroller and the SMC
  - velocity_control_demo -- sets the motor velocity to 60 RPM and prints the current motor velocity to the Serial Monitor every 2 seconds. 