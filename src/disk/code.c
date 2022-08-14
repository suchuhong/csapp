#include <stdlib.h>

#include "memory/instruction.h"
#include "disk/elf.h"
#include "cpu/register.h"

/**
 * unit64_t add(unit64_t, unit64_t)
 * 
 */
inst_t program[INST_LEN] = 
{
    // 0
    {
        push_reg,
        { REG, 0, 0, (uint64_t *)&reg.rbp, NULL },
        { EMPTY, 0, 0, NULL, NULL },
        "push   \%rbp"
    },
    // 1
    {
        mov_reg_reg,
        { REG, 0, 0, (uint64_t *)&reg.rsp, NULL },
        { REG, 0, 0, (uint64_t *)&reg.rbp, NULL },
        "mov    \%rsp,\%rbp"
    },
    // 2
    {
        mov_reg_mem,
        { REG, 0, 0, (uint64_t *)&reg.rdi, NULL },
        { MM_IMM_REG, -0x18, 0,  (uint64_t *)&reg.rbp, NULL },
        "mov    \%rdi,-0x18(\%rbp)"
    },
    // 3
    {
        mov_reg_mem,
        { REG, 0, 0, (uint64_t *)&reg.rsi, NULL },
        { MM_IMM_REG, -0x20, 0,  (uint64_t *)&reg.rbp, NULL },
        "mov    \%rsi,-0x20(\%rbp)"
    },
    // 4
    {
        mov_mem_reg,
        { MM_IMM_REG, -0x18, 0, (uint64_t *)&reg.rbp, NULL },
        { REG, 0, 0, (uint64_t *)&reg.rdx, NULL },
        "mov    -0x18(\%rbp),\%rdx"
    },
    // 5
    {
        mov_mem_reg,
        { MM_IMM_REG, -0x20, 0, (uint64_t *)&reg.rbp, NULL },
        { REG, 0, 0, (uint64_t *)&reg.rax, NULL },
        "mov    -0x20(\%rbp),\%rax"
    },
    // 6
    {
        add_reg_reg,
        { REG, 0, 0, (uint64_t *)&reg.rdx, NULL },
        { REG, 0, 0, (uint64_t *)&reg.rax, NULL },
        "add    \%rdx,\%rax"
    },
    // 7
    {
        mov_reg_mem,
        { REG, 0, 0, (uint64_t *)&reg.rax, NULL },
        { MM_IMM_REG, -0x8, 0, (uint64_t *)&reg.rbp, NULL },
        "mov    \%rax,-0x8(\%rbp)"
    },
    // 8
    {
        mov_mem_reg,
        { MM_IMM_REG, -0x8, 0, (uint64_t *)&reg.rbp, NULL },
        { REG, 0, 0, (uint64_t *)&reg.rax, NULL },
        "mov    -0x8(\%rbp),\%rax"
    },
    // 9
    {
        pop_reg,
        { REG, 0, 0, (uint64_t *)&reg.rbp, NULL },
        { EMPTY, 0, 0, NULL, NULL },
        "pop    \%rbp"
    },
    // 10
    {
        ret,
        { EMPTY, 0, 0, NULL, NULL },
        { EMPTY, 0, 0, NULL, NULL },
        "retq"
    },
    // 11 main entry 
    {
        mov_reg_reg,
        { REG, 0, 0, (uint64_t *)&reg.rdx, NULL },
        { REG, 0, 0, (uint64_t *)&reg.rsi, NULL },
        "mov    \%rdx,\%rsi"
    },
    // 12
    {
        mov_reg_reg,
        { REG, 0, 0, (uint64_t *)&reg.rax, NULL },
        { REG, 0, 0, (uint64_t *)&reg.rdi, NULL },
        "mov    %rax,%rdi"
    },
    // 13 call IMM
    {
        call,
        { IMM, (uint64_t)&(program[0]), 0, NULL, NULL },//todo
        { EMPTY, 0, 0, NULL, NULL },
        "callq  1129 <add>"
    },
    // 14 
    {
        mov_reg_mem,
        { REG, 0, 0, (uint64_t *)&reg.rax, NULL },
        { MM_IMM_REG, -0x8, 0, (uint64_t *)&reg.rbp, NULL },
        "mov    \%rax,-0x8(\%rbp)"
    }
};

