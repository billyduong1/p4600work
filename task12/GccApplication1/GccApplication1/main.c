
#include <avr/io.h>
#include <util/delay.h>


void setup()
{
	SPCR|=(1<<SPE);
	SPCR |= (1<<MSTR)|(1<<CPOL);
	SPCR &=~(1<<SPIE);
	SPCR &=~(1<<DORD);
	SPCR &=~(1<<CPHA);
	
	DDRB |= (1<<PB3)|(1<<PB5)|(1<<PB6)|(1<<PB2); //sets pin 1 to 3 as output 
	
	
}


int main(void)
{
	uint8_t i;
	uint8_t datarecieved=0;
	
	setup();

while(1)
{
	for(i=0;i<255;i++)
	{
		PORTB &=~ (1<<PB6);
		SPDR = i;
		
		while(!(SPSR & (1<<SPIF)));
		
		datarecieved = SPDR;
		
		PORTB |= (1<<PB6);
		_delay_ms(100);
	}
}

}