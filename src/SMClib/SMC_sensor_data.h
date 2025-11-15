#ifndef smc_sensor_data_h
    #define smc_sensor_data_h

    # include <Arduino.h>

    struct SensorData {
        int32_t angle;
        int32_t rpm;
        int16_t cur;
    } __attribute__((packed));
#endif