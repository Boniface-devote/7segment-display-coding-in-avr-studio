#include <asf.h>
#include <util/delay.h>

void Animate(int num){
	char numbers[10]={0b00111111,0b00000110,0b11011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	char led[9]={0b00000000,0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000};
	for (int i = num; i >= 0; i --){
		
		PORTH = numbers[i];
		if(i == 9){
			PORTB = 0b00000001;
		}
		else{	
			PORTA= led[i];
		}
		_delay_ms(500);
		PORTB = 0b00000000;
	}
}


int main (void)
{
	DDRA=0b11111111;
	DDRH=0b11111111;
	DDRB=0b00000001;
	DDRK=0b00000111;
	
	
	while(1){
		PORTK = 0b11111011;
		
		//check 1
		if ((PINK & 0b00001000) == 0){
			Animate(1);
		}
		
		//check 4
		if ((PINK & 0b00010000) == 0){
			Animate(4);
		}
		
		//check 7
		if ((PINK & 0b00100000) == 0){
			Animate(7);
		}
		
		
		PORTK = 0b00000101;
		//check 2
		if ((PINK & 0b00001000) == 0){
			Animate(2);
		}
		
		//check 5
		if ((PINK & 0b00010000) == 0){
			Animate(5);
		}
		
		//check 8
		if ((PINK & 0b00100000) == 0){
			Animate(8);
		}
		
		PORTK = 0b00000110;
		//check 3
		if ((PINK & 0b00001000) == 0){
			Animate(3);
		}
		
		//check 6
		if ((PINK & 0b00010000) == 0){
			Animate(6);
		}
		
		//check 9
		if ((PINK & 0b00100000) == 0){
			Animate(9);
		}
		
		PORTB = 0b00000000;
		PORTA = 0b00000000;
	}
}
