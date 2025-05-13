#include <lpc21xx.h>
#include "RTL.h" 
#define R1 0x1
#define Y1 0x1<<1
#define G1 0x1<<2
#define R2 0x1<<3
#define Y2 0x1<<4
#define G2 0x1<<5
#define port1 0x3F
/////////////////////////////////
#define R3 0x1<<6
#define Y3 0x1<<7
#define G3 0x1<<8
#define R4 0x1<<9
#define Y4 0x1<<10
#define G4 0x1<<11
#define port2 0x3F<<6
#define led 1<<17
extern int flag;
int c1;
OS_MUT m1;
__task void task6()
{
	while(1)
	{
		IOCLR0=R1;
		IOCLR0=R2;
		IOCLR0=R3;
		IOCLR0=R4;
		if(flag==1)
			os_tsk_delete_self();
	}
}
__task void task5()
{
	for(;;)
	{
			IOCLR0=R3;
			os_dly_wait(200);
			IOSET0=R3;
				///////////////////
			IOCLR0=Y3;
			os_dly_wait(200);
			IOSET0=Y3;
				/////////////////////
			IOCLR0=G3;
			os_dly_wait(200);
			IOSET0=G3;
		 if(flag==0)
			 os_tsk_delete_self();
  }
}
__task void task4()
{
	for(;;)
	{
		IOCLR0=R2;
		os_dly_wait(200);
		IOSET0=R2;
			////////////////
		IOCLR0=Y2;
		os_dly_wait(200);
		IOSET0=Y2;
			/////////////////////
		IOCLR0=G2;
		os_dly_wait(200);
		IOSET0=G2;
		if(flag==0)
			 os_tsk_delete_self();
   }
}
__task void task3()
{
	for(;;)
	{
		IOCLR0=G4;
		os_dly_wait(200);
		IOSET0=G4;
		///////////////////////
		IOCLR0=Y4;
		os_dly_wait(200);
		IOSET0=Y4;
		///////////////////
		IOCLR0=R4;
		os_dly_wait(200);
		IOSET0=R4;
		if(flag==0)
			 os_tsk_delete_self();
	}
}
__task void task2()
{
	for(;;)
	{

		IOCLR0=G1;
		os_dly_wait(200);
		IOSET0=G1;
		//////////////////////
		IOCLR0=Y1;
		os_dly_wait(200);
		IOSET0=Y1;
		///////////////////////
		IOCLR0=R1;
		os_dly_wait(200);
		IOSET0=R1;
		if(flag==0)
			 os_tsk_delete_self();
	}
}
__task void task1()
{
	if(flag==1)
	{
	    os_tsk_create(task2,2);
			os_tsk_create(task3,2);
  		os_tsk_create(task4,2);
			os_tsk_create(task5,2);
	}
	if(flag==0)
	{
		  os_tsk_create(task6,1);
	}
	while(1);
}

int main()
{
	IODIR0=port1|port2;
	IOSET0=port1|port2;
	config();
	enable();
	os_sys_init(task1);
}