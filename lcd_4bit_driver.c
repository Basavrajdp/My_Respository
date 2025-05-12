#include <lpc21xx.h>
//#include "header.h"
#define RS 1<<17
#define RW 1<<18
#define EN 1<<19
void lcd_data(unsigned char data)
{
	IOCLR1=0xfe<<16;
	unsigned int temp;
	temp=(data&0xf0)<<16;
	IOSET1=temp;
	IOSET1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;
/////////////////	
	IOCLR1=0Xfe<<16;
	temp=(data&0x0f)<<20;
	IOSET1=temp;
	IOSET1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
  IOCLR1=EN;
}
void lcd_cmd(unsigned char cmd)
{
	IOCLR1=0xFE<<16;
	unsigned int temp;
	temp=(cmd&0xf0)<<16;
	IOSET1=temp;
	IOCLR1=RS;
	IOSET1=EN;
  delay_ms(2);
	IOCLR1=EN;
/////////////////	
	IOCLR1=0XFE<<16;
	temp=(cmd&0x0f)<<20;
	IOSET1=temp;
	IOCLR1=RS;
	IOSET1=EN;
  delay_ms(2);
  IOCLR1=EN;
}

void lcd_init(void)
{
	IODIR1=0XFE<<16;
	IOCLR1=EN;
	PINSEL2=0x0;
	lcd_cmd(0x02);
	lcd_cmd(0x03);
	lcd_cmd(0x28);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
}
void lcd_string(unsigned char *p)
{
	while(*p)
	{
		lcd_data(*p);
		p++;
	}
}
