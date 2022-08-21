#ifndef __DRAM_H__
#define __DRAM_H__

#include <stdlib.h>
#include <stdint.h>

#define MM_LEN 1000

uint8_t mm[MM_LEN];// every 8 byte

uint64_t read64bits_dram(uint64_t paddr);
void write64bits_dram(uint64_t paddr, uint64_t data);

#endif
