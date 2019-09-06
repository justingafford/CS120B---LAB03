/*	Name & E-mail: Justin Gafford jgaff001@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab #3 Exercise #5
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
int main(void)
{
	DDRA = 0xFE; PORTA = 0x01; //outputs, but 1 bit for button
	DDRD = 0x00; PORTD = 0xFF; //inputs
	
	unsigned short airbag = 0x0000;
	unsigned char temp = 0x00;
	while (1) {
		airbag = (PIND | (PINB & 0x01));
		if (airbag >= 70) {
			temp = 0x02;
		}
		else if (airbag > 5 && airbag < 70) {
			temp = 0x04;
		}
		else {
			temp = 0x00;
		}
		PORTB = temp;
	}
}
	
	
	

