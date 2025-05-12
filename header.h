#include<stdio.h>		   
typedef unsigned int u32 ;
#define CS0 (1<<7);
typedef unsigned short int u16 ;
typedef unsigned char u8;
typedef signed char s8;
////////////////////////////////////
extern void delay_ms(unsigned int);
extern void delay_s(unsigned int);
extern void lcd_data(unsigned char);
extern void lcd_cmd(unsigned int );
extern void lcd_init(void );
extern void lcd_string(unsigned char *);
extern void uart0_init(unsigned int);
extern void uart0_tx(unsigned char);
extern char uart0_rx(void);
extern void uart0_string_tx(unsigned char *);
extern u8 uart0_string_rx(unsigned char *,char length);
//extern void EINT0_HANDLER(void)__irq;
extern void config(void);
extern void  en_eint0(void);
extern u8 spi0(u8);
extern void spi0_init(void);
extern void uart0_float_tx(float);
extern u16 adc_read(u8);
extern void I2C_bwdf(u8 sa,u8 mr,u8 data);
extern  u8 I2C_brdf(u8,u8);
extern void I2C_init(void);
/////////////////////////////////////////
typedef struct CAN1_MSG
 {
    u32 id;
	  u32 byteA;
	  u32 byteB;
	  u8 rtr;
	  u8 dlc;
 }CAN1;
extern void can1_init(void);
extern void can1_td(CAN1);
extern void can1_rd(CAN1 *);	
//extern void can1_rd(CAN1 *p);

