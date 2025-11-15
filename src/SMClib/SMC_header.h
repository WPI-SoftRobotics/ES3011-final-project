#ifndef smc_header_h
    #define smc_header_h

    #include <Arduino.h>
    #include "SMC_op_codes.h"

    struct SMCHeader {
        SMCOP op;
        uint8_t body_size;
    } __attribute__((packed));
#endif