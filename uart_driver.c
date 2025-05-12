#include <lpc21xx.h>
#include "header.h"
#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR &1)
void uart_init(unsigned int baud)
{
	unsigned int a[]={15,60,30,15,15};
	PINSEL0=5;
	unsigned int pclk,res;
	pclk=a[VPBDIV]*1000000;
	res=pclk/(16*baud);
	U0LCR=0X83;
	U0DLL=res&0xff;
	U0DLM=(res>>8)&0xff;
	U0LCR=0X03;
}
void uart_TX(unsigned char data)
{
	U0THR=data;
	while(THRE==0);
}
unsigned char uart_RX(void)
{
	while(RDR==0);
	return U0RBR;
}

void uart_string_TX(unsigned char *p)
{
	while(*p)
	{
		U0THR=*p;
		while(THRE==0);
		p++;
	}

}
void uart_string_RX(unsigned char *p,unsigned int len)
{
	int i;
	for(i=0;i<len;i++)
{
	while(RDR==0);
		p[i]=U0RBR;
	if(p[i]=='\r')
		break;
}
p[i]='\0';
}
