#ifndef smc_gains_h
    #define smc_gains_h

    #include <Arduino.h>

    struct Gains {
        float kv, kp, ki, kd;
    } __attribute__((packed));
#endif