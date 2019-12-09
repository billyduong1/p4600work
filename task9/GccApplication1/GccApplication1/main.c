
#include <avr/io.h>
#include <avr/interrupt.h>


ISR(TIMER0_OVF_vect)
{
	PORTD &=(1<<PD1);		//turn off
	
}

ISR(TIMER0_COMPA_vect)
{
	PORTD |=(1<<PD1);		//turn on
}

void loop()
{
	
}



void setup()
{
	DDRD |=(1<<PD1);		 //data direction making pin 3 an output pin
	PORTD &=~ (1<<PD1); 	 //start pin as 0 (off)

	TCCR0B = 0x11; 			 //timer control register initial set to hexadeci
	TIMSK0 =3; 				 //enables timer 0 overflow interrupt 
	
	OCR0A=200;				//triggers an interrupt at 200
	//OCIE0A=256;
	
	sei(); 					//start interrupt
}



int main()
{
	setup();
	while(1) loop();
}