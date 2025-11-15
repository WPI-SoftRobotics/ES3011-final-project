#ifndef SmartMotor_h
#define SmartMotor_h

#include <Arduino.h>
#include "SMC_pid_directions.h"
#include "SMC_gains.h"
#include "SMC_op_codes.h"

class SmartMotor {
  public:
    SmartMotor(uint8_t addr) : _addr(addr) {}
    uint8_t set_address(uint8_t);
    uint8_t set_gear_ratio(uint16_t);
    uint8_t set_ticks_per_rev(uint8_t);
    uint8_t tune_pos_pid(float, float, float);
    uint8_t tune_vel_pid(float, float, float, float);
    uint8_t set_direction(PIDDirection);
    uint8_t write_angle(int32_t);
    uint8_t write_rpm(int32_t);
    uint8_t home();
    uint8_t clear_configs();
    uint8_t get_address() { return _addr; }
    PIDDirection get_direction();
    uint16_t get_gear_ratio();
    uint8_t get_ticks_per_rev();
    Gains get_pos_gains();
    Gains get_vel_gains();
    int32_t read_angle();
    int16_t read_rpm();
    int16_t read_current();

  private:
    uint8_t _addr; // MOTOR ADDRESS

    uint8_t _write(SMCOP, void *, uint8_t);
    Gains get_pid_gains();
};
#endif