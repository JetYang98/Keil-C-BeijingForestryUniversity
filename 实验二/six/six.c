#include"stc15.h"
#include<intrins.h>

unsigned char code LedTab[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
unsigned char code LED[4] = {0x20,0x10,0x04,0x02};
sbit key_1 = P3^3;
sbit key_2 = P3^4;
int i = 0;
int temp1 = 1;
int temp2 = 1;

void Delay20ms()        //@11.0592MHz
{
    unsigned char i, j, k;

    _nop_();
    _nop_();
    i = 1;
    j = 216;
    k = 35;
    do
    {
        do
        {
            while (--k);
        } while (--j);
    } while (--i);
}

void main(void)
{
    while(1){
        P4=LED[0];        
        P0=LedTab[i]; 
		if(key_1 == 0){
            Delay20ms();
            if(key_1 == 0){
                if(temp1){
                    if(i == 9){
                        i = 0;
                    }
                    else{
                        i++;
                    }
                    temp1 = 0;
                }
            }
        }
        else if(key_1 == 1){
            Delay20ms();
            if (key_1 == 1)
            {
                temp1 = 1;
            }
        }
        if(key_2 == 0){
            Delay20ms();
            if(key_2 == 0){
                if(temp2){
                    if(i == 0){
                        i = 9;
                    }
                    else{
                        i--;
                    }
                    temp2 = 0;
                }
            }
        }
        else if(key_2 == 1){
            Delay20ms();
            if (key_2 == 1)
            {
                temp2 = 1;
            }
        }
    } 
}