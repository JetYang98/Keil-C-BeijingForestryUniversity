#include<stc15.h>
#include<intrins.h>

sbit key_1=P3^5;
sbit key_2=P3^4;
sbit key_3=P3^3;
int num = 0;

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

void Timer0Init(void)
{
	AUXR &= 0x7F;
	TMOD &= 0xF0;
	TL0 = 0x00;
	TH0 = 0x4C;
	TF0 = 0;
	TR0 = 1;
}

void main(){
	Timer0Init();
	ES=0; 
	EX0=0;
	EX1=1;
	ET0=1;
	ET1=0;
	EA=1;
	IT1 = 1;
	P55=0;
	
	while(1){
		if(num == 1){
			P5M1 = 0x00;
			P5M0 = 0x20;
		}else{
			P5M1 = 0x00;
			P5M0 = 0x00;
		}
		if(key_1 == 0){
			Delay10ms();
			if(key_1 == 0){
				IE1 = 1;
				while(!key_1);
			}
		}
	}
}

void Timer0(void) interrupt 1
{
	static counter = 0;
	if(counter==10)
	{
		P55 = ~P55;
		counter = 0;
	}	
	counter++;
}

void in() interrupt 2{
	num++;
}

