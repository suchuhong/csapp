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
	mm[va2pa(0x7fffffffddf0)] = 0x0; // rbp  stack bottom 
	mm[va2pa(0x7fffffffdde8)] = 0x0;
	mm[va2pa(0x7fffffffdde0)] = 0xabcd;
	mm[va2pa(0x7fffffffddd8)] = 0x12340000;
	mm[va2pa(0x7fffffffddd0)] = 0x00000000; // rsp stack top

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
	
	match = match && (mm[va2pa(0x7fffffffddf0)] = 0x0); // rbp  stack bottom 
	match = match && (mm[va2pa(0x7fffffffdde8)] = 0x1234abcd);
	match = match && (mm[va2pa(0x7fffffffdde0)] = 0xabcd );
	match = match && (mm[va2pa(0x7fffffffddd8)] = 0x12340000 );
	match = match && (mm[va2pa(0x7fffffffddd0)] = 0x0 ); // rsp stack top

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





/*

rax            0x12340000          305397760
rbx            0x555555555190      93824992235920
rcx            0x555555555190      93824992235920
rdx            0xabcd              43981
rsi            0x7fffffffdee8      140737488346856
rdi            0x1                 1
rbp            0x7fffffffddf0      0x7fffffffddf0
rsp            0x7fffffffddd0      0x7fffffffddd0
r8             0x0                 0
r9             0x7ffff7fe0d60      140737354009952
r10            0x1                 1
r11            0x0                 0
r12            0x555555555040      93824992235584
r13            0x7fffffffdee0      140737488346848
r14            0x0                 0
r15            0x0                 0
rip            0x555555555172      0x555555555172 <main+36>
eflags         0x202               [ IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0


rax            0x1234abcd          305441741
rbx            0x555555555190      93824992235920
rcx            0x555555555190      93824992235920
rdx            0x12340000          305397760
rsi            0xabcd              43981
rdi            0x12340000          305397760
rbp            0x7fffffffddf0      0x7fffffffddf0
rsp            0x7fffffffddd0      0x7fffffffddd0
r8             0x0                 0
r9             0x7ffff7fe0d60      140737354009952
r10            0x1                 1
r11            0x0                 0
r12            0x555555555040      93824992235584
r13            0x7fffffffdee0      140737488346848
r14            0x0                 0
r15            0x0                 0
rip            0x555555555181      0x555555555181 <main+51>
eflags         0x202               [ IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0

0x7fffffffddd0:	0x00000000	0x00000000	0x12340000	0x00000000
0x7fffffffdde0:	0x0000abcd	0x00000000	0x1234abcd	0x00000000
0x7fffffffddf0:	0x00000000	0x00000000

*/

/**
 

memory            data   64bit                   64bit
0x7fffffffddd0:	0x00000000	0x00000000	0x12340000	0x00000000
0x7fffffffdde0:	0x0000abcd	0x00000000	0x00000000	0x00000000
0x7fffffffddf0:	0x00000000	0x00000000

0x7fffffffdde0 - 0x7fffffffddd0 = 0x10 = 16
every memory 1 byte -> 16 byte

16 byte = 2 x 8 byte = 2 x 64 bit

**/

