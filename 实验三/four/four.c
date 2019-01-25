#include<stc15.h>
#include<intrins.h>
#include<stdio.h>

sbit key_3=P3^5;
sbit key_2=P3^4;
sbit key_1=P3^3;
sbit led = P5^5;

unsigned char code LedTab[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
unsigned char code LED[4] = {0x20,0x10,0x04,0x02};

unsigned char code str[]="这是 盛磊 的程序";
int jia = 0, yi = 0;
int jia0, jia1, yi0, yi1;
bit addMinus = 0;

void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}

void Delay10ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 108;
	j = 145;
	do
	{
		while (--j);
	} while (--i);
}

void UART_init(void)		
{
	TMOD=0X20;//0010 0000
	TH1=0XFD;//9600
	TL1=0XFD;
	TR1=1;
	SCON=0X50;//0101 0000
	AUXR=0X00;//?????T1
	ES=1;
	EA=1;
}
void main()
{
	UART_init();     
	led = ~addMinus;
	
	while(1){
		if(key_1 == 0){
			Delay10ms();
			if(key_1 == 0){
				addMinus = ~addMinus;
				led = ~addMinus;
				while(!key_1);
			}
		}
		if(key_2 == 0){
			Delay10ms();
			if(key_2 == 0){
				if(addMinus == 0)
					jia += 1;
				if(addMinus == 1){
					if(jia >0)
						jia -= 1;
				}
				while(!key_2);
			}
		}
		if(key_3 == 0){
			Delay10ms();
			if(key_3 == 0){
				if(addMinus == 0)
					yi += 1;
				if(addMinus == 1){
					if(yi > 0)
						yi -= 1;
				}
				while(!key_3);
			}
		}
		jia1 = jia/10;
		jia0 = jia%10;
		yi1 = yi/10;
		yi0 = yi%10;
		
		P4=LED[0];
		P0=LedTab[yi0];
		Delay1ms();
		
		P4=LED[1];
		P0=LedTab[yi1];
		Delay1ms();
		
		P4=LED[2];
		P0=LedTab[jia0];
		Delay1ms();
		
		P4=LED[3];
		P0=LedTab[jia1];
		Delay1ms();
		
	}
}

unsigned char num=0;

void UART(void) interrupt 4
{
	if(TI)
		TI=0;
	if(RI)
	{
		RI=0;
		num=SBUF;
		if(num == 1){
			TI=1;
			printf("%s\n",str);
		}
		if(num == 2){
			TI=1;
			printf("%d: %d\n", jia, yi);
		}
	}
}