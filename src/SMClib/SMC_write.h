#ifndef smc_write_h
    #define smc_write_h
    
    #include <Arduino.h>
    #include <Wire.h>
    #include "SMC_header.h"

    inline uint8_t smc_write(uint8_t addr, const SMCHeader* h_ptr, const void* body_ptr) {
        Wire.beginTransmission(addr);
        Wire.write((uint8_t*)h_ptr,sizeof(SMCHeader));
        Wire.write((uint8_t*)body_ptr,h_ptr -> body_size);
        return Wire.endTransmission();
    }

    inline uint8_t smc_write(uint8_t addr, const uint8_t* packet_ptr, int packet_sz) {
        Wire.beginTransmission(addr);
        Wire.write(packet_ptr,packet_sz);
        return Wire.endTransmission();
    }
#endif