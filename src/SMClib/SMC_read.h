#ifndef smc_read_h
    #define smc_read_h
    
    #include <Arduino.h>
    #include <Wire.h>

    inline void smc_read(uint8_t addr, void* dest, uint8_t pckt_sz) {
        Wire.requestFrom(addr,pckt_sz); // REQUEST DATA FROM ADDRESS
        for (int i=0; i < pckt_sz; i++) { *(((uint8_t*)dest)+i)= uint8_t(Wire.read()); }
    }
#endif