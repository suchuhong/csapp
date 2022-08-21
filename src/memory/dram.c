
#include "memory/dram.h"

#define SRAM_CACHE_SETTING 0

uint64_t read64bits_dram(uint64_t paddr)
{
    // don't direct assess memory
    // assess cache
    if (SRAM_CACHE_SETTING == 1) 
    {
        return 0x0;
    }
    // assess memory
    
    uint64_t val = 0x0;

    val += (((uint64_t)mm[paddr + 0]) << 0);
    val += (((uint64_t)mm[paddr + 1]) << 8);
    val += (((uint64_t)mm[paddr + 2]) << 16);
    val += (((uint64_t)mm[paddr + 3]) << 24);
    val += (((uint64_t)mm[paddr + 4]) << 32);
    val += (((uint64_t)mm[paddr + 5]) << 40);
    val += (((uint64_t)mm[paddr + 6]) << 48);
    val += (((uint64_t)mm[paddr + 7]) << 56);

    return val;
}

void write64bits_dram(uint64_t paddr, uint64_t data)
{
    // don't direct assess memory
    
    // assess cache
    if (SRAM_CACHE_SETTING == 1) 
    {
        return;
    }
    // assess memory  64 bit
    mm[paddr + 0] = (data >> 0) & 0xff;
    mm[paddr + 1] = (data >> 8) & 0xff;
    mm[paddr + 2] = (data >> 16) & 0xff;
    mm[paddr + 3] = (data >> 24) & 0xff;
    mm[paddr + 4] = (data >> 32) & 0xff;
    mm[paddr + 5] = (data >> 40) & 0xff;
    mm[paddr + 6] = (data >> 48) & 0xff;
    mm[paddr + 7] = (data >> 56) & 0xff;
}

