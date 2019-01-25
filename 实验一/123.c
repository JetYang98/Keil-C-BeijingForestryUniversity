#include "stc15.h"
//sfr P5          =   0xC8;   //xxxx,1111 ??5

void main(void) {
		unsigned int delay=0;
		while (1) {
				while(--delay);
				P5^=0xff;
		}
}