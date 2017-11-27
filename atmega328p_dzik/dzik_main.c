/*
 * dzik_main.c
 *
 *  Created on: 26 lis 2017
 *      Author: Juzek
 */
#include <avr/io.h>

/*****************\
*                 *
*  ###        ### *
*  #1#=@@@@@@=#3# *
*  ### @@@@@@ ### *
*      @@@@@@     *
*  ### @@@@@@ ### *
*  #2#=@@@@@@=#4# *
*  ###        ### *
*                 *
\*****************/

int main(void)
{
	DDRD |= (1<<PD5)|(1<<PD6)|(1<<PD3);
	DDRB |= (1<<PB1);

	// TIMER0 -- FAST PWM
	TCCR0A |= (1<<WGM01)|(1<<WGM00);	// -- fast PWM
	TCCR0A |= (1<<COM0A1)|(1<<COM0B1);	// -- non-inverting mode
	TCCR0B |= (1<<CS01);				// -- prescaler == 8

	// TIMER1 -- FAST PWM
	TCCR1A |= (1<<WGM10);				// -- fast PWM
	TCCR1B |= (1<<WGM12);				// -- fast PWM
	TCCR1A |= (1<<COM1A1);				// -- non-invertng mode
	TCCR1B |= (1<<CS11);				// -- prescaler == 8

	// TIMER2 -- FAST PWM
	TCCR2A |= (1<<WGM20)|(1<<WGM21);	// -- fast PWM
	TCCR2A |= (1<<COM2B1);				// -- non-inverting mode
	TCCR2B |= (1<<CS21);				// prescaler == 8

	OCR0A = 100;
	OCR0B = 100;
	OCR1A = 100;
	OCR2B = 100;

	while(1);
}
