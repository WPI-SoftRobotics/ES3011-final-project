#ifndef smc_cfg_h
    #define smc_cfg_h

    #include "SMC_pid_directions.h"
    #include "SMC_gains.h"
    #include "SMC_control_modes.h"
      
        struct Cfg{
            uint8_t address;
            PIDDirection direction;
            uint16_t gear_ratio;
            uint8_t ticks_per_rev;
            Gains gains[CONTROL_MODES];
        } __attribute__((packed));
#endif