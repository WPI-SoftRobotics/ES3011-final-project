#include "smartmotor.h"
#include "SMC_header.h"
#include "SMC_read.h"
#include "SMC_write.h"
#include "SMC_control_modes.h"
#include "SMC_sensor_data.h"
#include "SMC_cfg.h"

uint8_t SmartMotor::set_address(uint8_t new_addr) {
    SMCHeader h{SMCOP::SET_ADDRESS,sizeof(new_addr)}; // SET HEADER
    uint8_t status= smc_write(_addr,&h,&new_addr); // SEND PACKET
    _addr=new_addr;
    return status;
}

uint8_t SmartMotor::set_gear_ratio(uint16_t gear_ratio) {
    SMCHeader h{SMCOP::SET_GEAR_RATIO,sizeof(gear_ratio)}; // SET HEADER
    return smc_write(_addr,&h,&gear_ratio); // SEND PACKET
}

uint8_t SmartMotor::set_ticks_per_rev(uint8_t ticks_per_rev) {
    SMCHeader h{SMCOP::SET_TICKS_PER_REV,sizeof(ticks_per_rev)}; // SET HEADER
    return smc_write(_addr,&h,&ticks_per_rev); // SEND PACKET
}

uint8_t SmartMotor::tune_pos_pid(float kp, float ki, float kd) {
    Gains gains{0.0,kp,ki,kd}; // SET PID GAINS
    SMCHeader h{SMCOP::TUNE_POS,sizeof(gains)}; // SET HEADER
    return smc_write(_addr,&h,&gains); // SEND PACKET
}

uint8_t SmartMotor::tune_vel_pid(float kv, float kp, float ki, float kd) {
    Gains gains{kv,kp,ki,kd}; // SET PID GAINS
    SMCHeader h{SMCOP::TUNE_VEL,sizeof(gains)}; // SET HEADER
    return smc_write(_addr,&h,&gains); // SEND PACKET
}

uint8_t SmartMotor::set_direction(PIDDirection dir) {
    SMCHeader h{SMCOP::SET_DIRECTION,sizeof(dir)}; // SET HEADER
    return smc_write(_addr,&h,&dir); // SEND PACKET
}

uint8_t SmartMotor::_write(SMCOP op, void* target_ptr, uint8_t target_sz) {
    SMCHeader h{op,target_sz}; // SET HEADER
    return smc_write(_addr,&h,target_ptr); // SEND PACKET
}

uint8_t SmartMotor::write_angle(int32_t angle) {
    return _write(SMCOP::WRITE_ANGLE,&angle,sizeof(angle));
}

uint8_t SmartMotor::write_rpm(int32_t rpm) {
    return _write(SMCOP::WRITE_RPM,&rpm,sizeof(rpm));
}

uint8_t SmartMotor::home() {
    SMCHeader h{SMCOP::HOME,0}; // SET HEADER
    return smc_write(_addr,&h,nullptr); // SEND PACKET
}

uint8_t SmartMotor::clear_configs() {
    SMCHeader h{SMCOP::CLEAR_CONFIGS,0};
    return smc_write(_addr,&h,nullptr);
}

PIDDirection SmartMotor::get_direction() {
    SMCHeader h{SMCOP::GET_DIRECTION,0};
    smc_write(_addr,&h,nullptr);
    Cfg cfg;
    smc_read(_addr,&(cfg.direction),sizeof(cfg.direction)); 
    return cfg.direction;
}

uint16_t SmartMotor::get_gear_ratio() {
    SMCHeader h{SMCOP::GET_GEAR_RATIO,0};
    smc_write(_addr,&h,nullptr);
    Cfg cfg;
    smc_read(_addr,&(cfg.gear_ratio),sizeof(cfg.gear_ratio)); 
    return cfg.gear_ratio; 
}

uint8_t SmartMotor::get_ticks_per_rev() {
    SMCHeader h{SMCOP::GET_TICKS_PER_REV,0};
    smc_write(_addr,&h,nullptr);
    Cfg cfg;
    smc_read(_addr,&(cfg.ticks_per_rev),sizeof(cfg.ticks_per_rev)); 
    return cfg.ticks_per_rev; 
}

Gains SmartMotor::get_pid_gains() {
    Gains gains;
    smc_read(_addr,&gains,sizeof(gains));
    return gains; 
}

Gains SmartMotor::get_pos_gains() {
    SMCHeader h{SMCOP::GET_POS_GAINS,0};
    smc_write(_addr,&h,nullptr);
    Gains gains=get_pid_gains();
    return gains;
}

Gains SmartMotor::get_vel_gains() {
    SMCHeader h{SMCOP::GET_VEL_GAINS,0};
    smc_write(_addr,&h,nullptr);
    Gains gains=get_pid_gains();
    return gains;
}

int32_t SmartMotor::read_angle() {
    SensorData sd;
    smc_read(_addr,&sd,sizeof(sd)); 
    return sd.angle; 
}

int16_t SmartMotor::read_rpm() { 
    SensorData sd;
    smc_read(_addr,&sd,sizeof(sd)); 
    return sd.rpm;
}

int16_t SmartMotor::read_current() { 
    SensorData sd;
    smc_read(_addr,&sd,sizeof(sd)); 
    return sd.cur; 
}