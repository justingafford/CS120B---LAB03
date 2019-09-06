/*	Name & E-mail: Justin Gafford jgaff001@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab #3 Exercise #4
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; //inputs
	DDRB = 0x00; PORTB = 0xFF; //inputs
	DDRC = 0xFF; PORTC = 0x00; //outputs
	
	unsigned char temp = 0x00;
	unsigned char temp2 = 0x00;
	
	while (1) {
		temp = 0x00;
		temp2 = 0x00;
		temp = (PINA & 0xF0) >> 4;
		temp2 = (PINA & 0X0F) << 4;
		
		PORTB = temp;
		PORTC = temp2;
	}
}




