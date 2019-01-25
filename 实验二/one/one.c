#include"stc15.h"
sbit LED=P5^5;
sbit KEY_1=P3^3;
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

void main()
{
	P5M1=0x00;
	P5M0=0x00;
	while(1)
	{
		if(KEY_1==0)
		{
			Delay10ms();
			if(KEY_1==0)
			{
				LED=1;
				while(!KEY_1);
			}
		}
		else
			{
			LED=0;
			while(KEY_1);
	   }
  }	 
}