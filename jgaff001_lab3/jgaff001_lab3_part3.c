/*	Name & E-mail: Justin Gafford jgaff001@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab #3 Exercise #3
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
//setbit and getbit functions from the lab manual
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; //inputs
	DDRC = 0xFF; PORTC = 0x00; //outputs
	unsigned char temp = 0x00;
	unsigned char temp2 = 0x00;
	unsigned char check = 0x00; //check if seatbelt not on, while key is in ignition and driver is seated.

	while(1) {
		temp = PINA & 0x0F;
		temp2 = 0x00;
		check = PINA & 0X70;
		
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
			PORTC = 0x3F;
		}
		else {
			PORTC = 0x00;
		}
		if(temp <= 4) {
			temp2 = temp2 | 0x40;
		}
		check = check >> 4;
		if (check == 3) {
			temp2 = temp2 | 0x80;
		}
		
		PORTC = temp2;
	}
}




