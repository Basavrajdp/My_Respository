#include<lpc21xx.h>
#include "header.h"
#define sw1 ((IOPIN0>>14)&1)
#define sw2 ((IOPIN0>>15)&1)
#define sw3 ((IOPIN0>>16)&1)
CAN1 v1,v2;
int flag1,flag2,flag3;
main()
{
can_init();
v1.rtr=0;
v1.dlc=8;		
while(1)
{
	if(sw1==0)
	{
		while(sw1==0);
		if(flag1==0)
		{
		  v1.id=0x50;
			v1.byteA=0x11; //hl on
			can_td(v1);
			flag1=1;
		}
		else
		{
		    v1.id=0x50;
			v1.byteA=0x12; //hl off
			can_td(v1);
			flag1=0;
		}
	}
	if(sw2==0)
	{
		while(sw2==0);
		if(flag2==0)
		{
		  v1.id=0x100;
			v1.byteA=0x13; //li on
			can_td(v1);
			flag2=1;
		}
		else
		{
		    v1.id=0x100;
			v1.byteA=0x14;	//li off
			can_td(v1);
			flag2=0;
		}
	}
	if(sw3==0)
	{
		while(sw3==0);
		if(flag3==0)
		{
		  v1.id=0x150;
			v1.byteA=0x15;
			can_td(v1);	  //ri on
			flag3=1;
		}
		else
		{
		    v1.id=0x150;
			v1.byteA=0x16;	//ri off
			can_td(v1);
			flag3=0;
		}
	}
}
//////////////////////////
v2.id=0xAB;
v2.rtr=1;
v2.dlc=8;
can_td(v2);
}

