#include "cpu/register.h"
#include "memory/instruction.h"

int main()
{
	reg_t reg;

	reg.rax = 0x1234abcd5678ffff;

	printf("eax: %08x\n", reg.eax);

	printf("&al: %p\n", &reg.al);
	printf("&ah: %p\n", &reg.ah);
	printf("&ax: %p\n", &reg.ax);
	printf("&eax: %p\n", &reg.eax);
	
	instruction_cycle();
	return 0;
}


