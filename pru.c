#include "pru_cfg.h"

#define PRU_SHARED_MEM_ADDR 0x00012000

void write_int(int index, int value)
{
	(*(volatile unsigned int *) (PRU_SHARED_MEM_ADDR + 4 * index)) = value;	
}

int read_int(int index)
{	
 	return (*(volatile unsigned int *) (PRU_SHARED_MEM_ADDR + 4 * index));	
}

int main(void)
{
	// enable OCP
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;
	
	while(read_int(0)!=0xCAFEBABE) {}
	
	write_int(1,0xDEADBEEF);

	while(1) {}

	__halt();

	return 0;
}
