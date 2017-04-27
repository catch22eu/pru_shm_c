#include "pru_cfg.h"

void write_int(int index, int value)
{
	(*(volatile unsigned int *) (0x00012000 + 4 * index)) = value;	
}

int read_int(int index)
{	
  return (*(volatile unsigned int *) (0x00012000 + 4 * index));	
}

int main(void)
{
	// enable OCP
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;
	
/*	volatile int a,b,c;

	a = read_int(0);
	b = read_int(1);
	c = a + b;
	write_int(2,c);

	while(1) {};*/

	while(read_int(0)!=0xCAFEBABE)
	{
	};
	
	write_int(1,0xDEADBEEF);

	while(1);
	{};

	__halt();

	return 0;
}
