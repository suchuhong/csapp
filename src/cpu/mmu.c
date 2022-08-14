
#include "cpu/mmu.h"
#include "memory/dram.h"

uint64_t va2pa(uint64_t vaddr)
{
    return (uint64_t)(vaddr % MM_LEN);
}
