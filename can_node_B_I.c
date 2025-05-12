#include<lpc21xx.h>
#include "header.h"
extern CAN1 v1;
u32 flag;
void can1_isr(void) __irq
{
   v1.id=C2RID;
   v1.dlc=(C2RFS>>16)&0x0f;
   v1.rtr=(C2RFS>>30)&1;
   if(v1.rtr==0)
   {
    v1.byteA=C2RDA;
  	v1.byteB=C2RDB;
   }
   C2CMR=1<<2;
   flag=1;
   VICVectAddr=0;
}
void config(void)
{
  VICIntSelect=0;
  VICVectAddr0=(u32)can1_isr;
  VICVectCntl0=27|(1<<5);
  VICIntEnable=1<<27;	   
}
void en_can1(void)
{ 
  C2IER=1;
}

