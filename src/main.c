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
	

	return 0;
}

uint64_t decode_od(od_t od)
{
	if (od.type == IMM)
	{
		return od.imm;
	}
	else if (od.type == REG) 
	{
		return *(uint64_t *)od.reg1;
	}
	else 
	{
		uint64_t addr = MM_LEN + 0xff;
		//
		//
		return mm[addr % MM_LEN];
	}


}
