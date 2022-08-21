#include "cpu/mmu.h"
#include "cpu/register.h"
#include "disk/elf.h"
#include "memory/dram.h"
#include "memory/instruction.h"

int main()
{
	init_handler_table();

	// init reg
	reg.rax = 0x12340000;
	reg.rbx = 0x555555555190;
	reg.rcx = 0x555555555190;
	reg.rdx = 0xabcd;
	reg.rsi = 0x7fffffffdee8;
	reg.rdi = 0x1;

	reg.rbp = 0x7fffffffddf0;// 
	reg.rsp = 0x7fffffffddd0;// stack top

	reg.rip = (uint64_t)&program[11];// pc

	// init memery
	// write memory with cache
	write64bits_dram(va2pa(0x7fffffffddf0), 0x0);// rbp  stack bottom 
	write64bits_dram(va2pa(0x7fffffffdde8), 0x0);
	write64bits_dram(va2pa(0x7fffffffdde0), 0xabcd);
	write64bits_dram(va2pa(0x7fffffffddd8), 0x12340000);
	write64bits_dram(va2pa(0x7fffffffddd0), 0x0);// rsp stack top

	uint64_t pa = va2pa(0x7fffffffdde0);

	printf("%16lx\n", *((uint64_t *)(&mm[pa])));
	printf("%16lx\n", read64bits_dram(pa));

	// run inst

	for (int i = 0; i < 1; i++)
	{
		instruction_cycle();
	}
	

	// verify register

	int match = 1;

	match = match && (reg.rax == 0x1234abcd);
	match = match && (reg.rbx == 0x555555555190);
	match = match && (reg.rcx == 0x555555555190);
	match = match && (reg.rdx == 0x12340000);
	match = match && (reg.rsi == 0xabcd);
	match = match && (reg.rdi == 0x12340000);

	match = match && (reg.rbp == 0x7fffffffddf0);
	match = match && (reg.rsp == 0x7fffffffddd0);

	if(match == 1) 
	{
		printf("register match\n");
	} 
	else 
	{
		printf("register not match\n");
	}

	// verify memory
	// read with cache
	match = match && ( read64bits_dram(va2pa(0x7fffffffddf0)) == 0x0 ); // rbp  stack bottom 
	match = match && ( read64bits_dram(va2pa(0x7fffffffdde8)) == 0x1234abcd );
	match = match && ( read64bits_dram(va2pa(0x7fffffffdde0)) == 0xabcd );
	match = match && ( read64bits_dram(va2pa(0x7fffffffddd8)) == 0x12340000 );
	match = match && ( read64bits_dram(va2pa(0x7fffffffddd0)) == 0x0 ); // rsp stack top

	if(match == 1) 
	{
		printf("memory match\n");
	} 
	else 
	{
		printf("memory not match\n");
	}
	
	return 0;
}







