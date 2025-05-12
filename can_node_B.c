#include<lpc21xx.h>
#include "header.h"
 #define FHL (1<<17)
 #define RHL (1<<17)	
 #define FLI (1<<18)
 #define RLI (1<<18)
 #define FRI (1<<19)
 #define RRI (1<<19)
 #define bzr (1<<21)
 #define ALL (7<<17)
CAN1 v1;
extern u32 flag;
char temp;
main()
{
can_init();
uart_init(9600);
en_can1();
config();
IODIR0=ALL|bzr;
IOSET0=ALL;
lcd_init();
uart_string_TX("IN node B :\r\n");
while(1)
{
 if(flag==1)
 {
  if(v1.rtr==0)
  {
     if(v1.byteA==0x11)// head light on
 	{
	   IOCLR0=FHL;
	   IOCLR0=RHL;
	   lcd_cmd(0x01);
	   lcd_string("HEAD_LIGHT_ON");
	   uart_string_TX("BYTE_A 0X11\r\n");
	   	flag=0;
	}
	if(v1.byteA==0x12) // head light off
	{
	    IOSET0=FHL;
		IOSET0=RHL;
		lcd_cmd(0x01);
		lcd_string("HEAD_LIGHT_OFF");
	    uart_string_TX("BYTE_A 0X12\r\n");
	   	flag=0;
	}
//////////////////////////////////////////////////
l4:	if(v1.byteA==0x13)	  //left indicator on
	{	
	  
	  while(1)
	  {
          IOCLR0=FLI;
	        IOCLR0=RLI;
		      IOSET0=bzr;
	   	    delay_ms(500);
          IOSET0=FLI;
	       IOSET0=RLI;
		     IOCLR0=bzr;
	       delay_ms(500);
		    lcd_cmd(0x01);
		    lcd_string("LEFT_I_ON");
	      uart_string_TX("BYTE_A 0X13\r\n");
	   if(flag==1)              
	   {				  		    
	      if(v1.byteA==0x14)
		           goto l1;
		  if(v1.byteA==0x15)
		  {
		        IOSET0=FLI;
	          IOSET0=RLI;
		   	  IOCLR0=bzr;
			    if(flag==1)
			        goto l3;
		  }
		 if(v1.byteA==0x11)// head light on
	 	{
		   IOCLR0=FHL;
		   IOCLR0=RHL;
		   lcd_cmd(0xc0);
		   lcd_string("HEAD_LIGHT_ON");
		   uart_string_TX("BYTE_A 0X11\r\n");
		   	flag=0;
		}
		if(v1.byteA==0x12) // head light off
		{
		    IOSET0=FHL;
			IOSET0=RHL;
			lcd_cmd(0xc0);
			lcd_string("HEAD_LIGHT_OFF");
		    uart_string_TX("BYTE_A 0X12\r\n");
		   	flag=0;
		}
	   }
	  }
	  	flag=0;
   }
l1:    if(v1.byteA==0x14)	//left indicator off
   {
      IOSET0=FLI;
	  IOSET0=RLI;
	  IOCLR0=bzr;
	  lcd_cmd(0x01);
	  lcd_string("LEFT_I_OFF");
	  uart_string_TX("BYTE_A 0X14\r\n");
	  	flag=0;
   }
  ////////////////////////////////////////
l3:	if(v1.byteA==0x15)				 // right indicator on
	{
	 while(1)
	 {
	   IOCLR0=FRI;	
	   IOCLR0=RRI;
	   IOSET0=bzr;
	   delay_ms(500);
	   IOSET0=FRI;
	   IOSET0=RRI; 
	   IOCLR0=bzr; 
	   delay_ms(500); 
	   lcd_cmd(0x01);
	   lcd_string("RIGHT_I_ON");
	   uart_string_TX("BYTE_A 0X15\r\n");
	   if(flag==1)
	   {
	     if(v1.byteA==0x16)
	        goto l2;
		  if(v1.byteA==0x13)
		  {
		     IOSET0=FRI;
	         IOSET0=RRI;
			 IOCLR0=bzr; 
			  if(flag==1)
			   goto l4;
		  }
		  if(v1.byteA==0x11)// head light on
	 	{
		   IOCLR0=FHL;
		   IOCLR0=RHL;
		   	lcd_cmd(0xc0);
		   lcd_string("HEAD_LIGHT_ON");
		   uart_string_TX("BYTE_A 0X11\r\n");
		   	flag=0;
		}
		if(v1.byteA==0x12) // head light off
		{
		    IOSET0=FHL;
			  IOSET0=RHL;
			  lcd_cmd(0xc0);
			  lcd_string("HEAD_LIGHT_OFF");
		    uart_string_TX("BYTE_A 0X12\r\n");
		   	flag=0;
		}
	   }
	 }
	   	flag=0;
	}
l2:	if(v1.byteA==0x16)					  //right indicator off 
	{
	   IOSET0=FRI;
	   IOSET0=RRI;
	   IOCLR0=bzr; 
	   lcd_cmd(0x01);
	   lcd_string("RIGHT_I_OFF");
	   uart_string_TX("BYTE_A 0X16\r\n");
	   	flag=0;
	}
}
 else
 {
    uart_string_TX("remote frame\r\n");
 }
 }
}
}		

