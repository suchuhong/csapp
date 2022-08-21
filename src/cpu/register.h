
#ifndef __register_H__
#define __register_H__

#include<stdio.h>
#include<stdint.h>

typedef struct REG_STRUCT
{
	union
	{
		struct
		{
			uint8_t al;
			uint8_t ah;
		};
		uint16_t ax;
		uint32_t eax;
		uint64_t rax;
	};
	union
	{
		struct
		{
			uint8_t bl;
			uint8_t bh;
		};
		uint16_t bx;
		uint32_t ebx;
		uint64_t rbx;
	};
	union
	{
		struct
		{
			uint8_t cl;
			uint8_t ch;
		};
		uint16_t cx;
		uint32_t ecx;
		uint64_t rcx;
	};
	union
	{
		struct
		{
			uint8_t dl;
			uint8_t dh;
		};
		uint16_t dx;
		uint32_t edx;
		uint64_t rdx;
	};union
	{
		struct
		{
			uint8_t sil;
			uint8_t sih;
		};
		uint16_t si;
		uint32_t esi;
		uint64_t rsi;
	};
	union
	{
		struct
		{
			uint8_t dil;
			uint8_t dih;
		};
		uint16_t di;
		uint32_t edi;
		uint64_t rdi;
	};
	union
	{
		struct
		{
			uint8_t bpl;
			uint8_t bph;
		};
		uint16_t bp;
		uint32_t ebp;
		uint64_t rbp;
	};
	union
	{
		struct
		{
			uint8_t spl;
			uint8_t sph;
		};
		uint16_t sp;
		uint32_t esp;
		uint64_t rsp;
	};

	// uint64_t rbx;
	// uint64_t rcx;
	// uint64_t rdx;
	// uint64_t rsi;
	// uint64_t rdi;
	// uint64_t rbp;
	// uint64_t rsp;// stack pointer

	uint64_t rip;// pc
} reg_t;

reg_t reg;


#endif



















