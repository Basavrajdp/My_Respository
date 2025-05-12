#include<lpc21xx.h>
#include "header.h"
#define TCS ((C2GSR>>3)&1)
#define RBS (C2GSR&1)
u32 *p=(unsigned int *)0xE0038000;
void can_init(void)
{
VPBDIV=1;
PINSEL1|=0X14000;
C2MOD=1;
C2BTR=0X001c001D;
AFMR=2;///disable message acceptance
C2MOD=0;
}
void can_td(CAN1 v)
{
	C2TID1=v.id;
	C2TFI1=v.dlc<<16;
	if(v.rtr==0)
	{
		C2TDA1=v.byteA;
		C2TDB1=v.byteB;
	}
	else
		C2TFI1|=(1<<30);
	C2CMR=1|(1<<5);
	while(TCS==0);
}
void can_rd(CAN1 *p)				          
{
	while(RBS==0);
	p->id=C2RID;
	p->dlc=(C2RFS>>16)&0XF;
	p->rtr=(C2RFS>>30)&1;
	if((p->rtr)==0)
	{
		p->byteA=C2RDA;
		p->byteB=C2RDB;
	}
	C2CMR=(1<<2);
}

///////* afmr */
//void can_init(void)
//{
//	VPBDIV=1;
//	PINSEL1|=0X14000;
//	C2BTR=0X001c001D;
//	C2MOD=1;
//	 /*ecp*/
//	p[0]=0x20502100;
//	p[1]=0x21502200; 
//	p[2]=0x22502300;
//	///////////////////////////////////
//	SFF_sa=0x0;						  
//	SFF_GRP_sa=0xc;
//	EFF_sa=0xc;
//	EFF_GRP_sa= 0xc;
//	ENDofTable=0xc;
//	/////////////////////////////////
//	AFMR=0;
//	C2MOD=0;    
//}

