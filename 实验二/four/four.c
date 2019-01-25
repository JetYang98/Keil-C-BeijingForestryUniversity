#include"stc15.h"
#include<intrins.h>

unsigned char code LedTab[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
unsigned char code LED[4] = {0x20,0x10,0x04,0x02};

void Delay2ms()     //@11.0592MHz
{
    unsigned char i, j;

    _nop_();
    _nop_();
    i = 22;
    j = 128;
    do
    {
        while (--j);
    } while (--i);
}

void main(void)
{
    while(1){
        P4=LED[2];        
        P0=LedTab[8]; 
        Delay2ms();   
        P4=LED[3];        
        P0=LedTab[1];  
        Delay2ms();
    }
    
}