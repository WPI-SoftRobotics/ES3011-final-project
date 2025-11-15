#ifndef smc_op_codes_h
    #define smc_op_codes_h

    #include <Arduino.h>

    #define OPS 15

    enum class SMCOP: uint8_t {
        SET_ADDRESS,
        SET_GEAR_RATIO,
        SET_TICKS_PER_REV,
        TUNE_POS,
        TUNE_VEL,
        SET_DIRECTION,
        WRITE_ANGLE,
        WRITE_RPM,
        HOME,
        CLEAR_CONFIGS,
        GET_DIRECTION,
        GET_GEAR_RATIO,
        GET_TICKS_PER_REV,
        GET_POS_GAINS,
        GET_VEL_GAINS
    };
#endif