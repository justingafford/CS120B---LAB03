/*	Name & E-mail: Justin Gafford jgaff001@ucr.edu
*	Lab Section: 022
*	Assignment: Lab #3 Exercise #2
*
*	I acknowledge all content contained herein, excluding template or example
*	code, is my own original work.
*/
#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; //inputs
	DDRC = 0xFF; PORTC = 0x00; //outputs
	unsigned char temp = 0x00;
	unsigned char temp2 = 0x00;

	while(1) {
		temp = PINA & 0x0F; //only reads 4 right most bits
		temp2 = 0x00;
		
		if (temp == 1 || temp == 2) {
			temp2 = 0x20;
		}
		else if (temp == 3 || temp == 4) {
			temp2 = 0x30;
		}
		else if (temp == 5 || temp == 6) {
			temp2 = 0x38;
		}
		else if (temp >=  7 && temp <= 9) {
			temp2 = 0x1C;
		}
		else if (temp >= 10 && temp <= 12) {
			temp2 = 0x3E;
		}
		else if (temp >= 13 && temp <= 15) {
			temp2 = 0x3F;
		}
		else {
			temp2 = 0x00;
		}
		if (temp <= 4) {
			temp2 = (temp2 | 0x40);
		}
		PORTC = temp2;
	}
}




