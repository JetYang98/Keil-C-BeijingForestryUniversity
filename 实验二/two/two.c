#include"stc15.h"
#include<intrins.h>
sbit key_1 = P3^3;
sbit key_2 = P3^4;
sbit key_3 = P3^5;
sbit led = P5^5;

void Delay500ms()       //@11.0592MHz
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

void Delay10ms()        //@11.0592MHz
{
    unsigned char i, j;

    i = 108;
    j = 145;
    do
    {
        while (--j);
    } while (--i);
}

void main(){
	while(1){
		if(key_1 == 0){
            Delay10ms();
            if(key_1 == 0){
                P5M1 = 0x00;
                P5M0 = 0x20;
                while(!key_1);
            }
        }
        if(key_2 == 0){
            Delay10ms();
            if(key_2 == 0){
                P5M1 = 0x00;
                P5M0 = 0x00;
                while(!key_2);
            }
        }
        if(key_3 == 0){
            Delay10ms();
            if(key_3 == 0){
                led = !led;
                Delay500ms();
            }
        }
        else{
            led = 0;
        }
	}
}