/*
 * GccApplication1.c
 *
 * Created: 11/07/19 12:37:42
 * Author : Billy Duong
 */ 

#include <avr/io.h>


int main(void)
{
 TCNT0 = 0;								//SETS TIMER TO ZERO
 TCCR0B = (1<< C500) | (1<<C502);		//START TIMER
 
 while(1)
 {
	 while((TIFR0 & 1)==0);		//DELAYS PROGRAM
	 PORTD ^=(1<<PD1);
	 
 }
}

