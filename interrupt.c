#include <lpc21xx.h>
typedef unsigned int u32;
int flag=0;
void handler() __irq
{
	if(flag==0)
	{
		flag=1;
	}
	else
	{
		flag=0;
	}
	EXTINT=1;
	VICVectAddr=0;
}
void config()
{
	VICIntEnable=0;
	VICVectAddr0=(u32)handler;
	VICVectCntl0=14|(1<<5);
	VICIntEnable=1<<14;
}
void enable()
{
	PINSEL1=1;
	EXTMODE=1;
	EXTPOLAR=0;
}