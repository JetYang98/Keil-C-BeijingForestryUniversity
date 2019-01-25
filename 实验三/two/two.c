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

void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 22;
	j = 3;
	k = 227;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

int main(){
	EX1=1;
	EA=1;
	IT1 = 1;
	
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
		P55 = ~P55;
		Delay500ms();
	}
	
	return 0;
}

void in() interrupt 2{
	num++;
}