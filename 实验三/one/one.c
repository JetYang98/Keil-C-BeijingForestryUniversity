#include<stc15.h>
#include<intrins.h>

unsigned char code LedTab[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
unsigned char code LED[4] = {0x20,0x10,0x04,0x02};
sbit key_1=P3^5;
sbit key_2=P3^4;
sbit key_3=P3^3;
bit key = 1;
int i = 0, j = 0;

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

int main(){
	ES=0; 
	EX0=0;
	EX1=1;
	ET0=0;
	ET1=0;
	EA=1;
	IT1 = 1;
	
	while(1){
		if(key){
			P4=LED[0];
			P0=LedTab[i];
			Delay500ms();
			i++;
			if(i == 10){
				i = 0;
			}
		}
		else{
			P4=LED[3];
			P0=LedTab[j];
			Delay500ms();
			j++;
			if(j == 10){
				j = 0;
			}
		}
		if(key_2 == 0){
			Delay10ms();
			if(key_2 == 0){
				key = 0;
				while(!key_2);
			}
		}
		if(key_1 == 0){
			Delay10ms();
			if(key_1 == 0){
				IE1 = 1;
				while(!key_1);
			}
		}
	}
	
	return 0;
}

void in() interrupt 2{
	int x = 0;
	int i;
	for(i=0; i<500; i++){
		P4=LED[x];
		P0=LedTab[6];
		Delay1ms();
		x++;
		if(x == 4){
			x = 0;
		}
	}
	IE1 = 0;
}
