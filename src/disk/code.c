#include <stdlib.h>

#include "memory/instruction.h"
#include "disk/elf.h"
#include "cpu/register.h"

inst_t program[INST_LEN] = {

    {
        MOV,
        { REG, 0, 0, (uint64_t *)&reg.rax, NULL },
        { REG, 0, 0, (uint64_t *)&reg.rbx, NULL },
        "mov rax rbx"
    },

};

