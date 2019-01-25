#include<stc15.h>
unsigned char code str[]="STC MCU TESTm";
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
{ TMOD=0X20;//0010 0000
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
	SBUF=str[0];
	//while(1);
	Delay10ms();
	Delay10ms();
	Delay10ms();
	Delay10ms();
	Delay10ms();
	Delay10ms();
}
void UART(void) interrupt 4
{
	static unsigned char i=1;
	if(TI)
	{	
		if(str[i]=='\0'){	TI=0;}
		else{SBUF=str[i];i++;TI=0;
	}}

}