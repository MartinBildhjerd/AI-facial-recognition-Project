#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#define BAUD_RATE 9600
#define F_CPU 8000000UL

unsigned char ObjectID;

void init_serial() 
{
	UCSR0B = (1 << RXEN0) | (1 << RXCIE0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	UBRR0L = 0x33; //9600 BAUDRATE
	sei();
}

void init_Ports() 
{
	DDRB &= ~(1 << PB0); //PB0 in
	DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5); //PB1-5 out
	PORTB = (1 << PB0); //328p latch 
	DDRC |= (1<<PC0)|(1 << PC6); //PC0, PC6 out
	
}

ISR(USART_RX_vect) 
{
	ObjectID = UDR0;
	if (ObjectID >= 0 && ObjectID <= 255) 
	{
		switch (ObjectID) 
		{
			case 1: //Detection
			PORTB |= (1 << PB1); 
			break;
			case 2: 
			PORTB |= (1 << PB2); 
			break;
			default:
			break;
		}
		} else {
	}
}

int main(void) 
{
	init_serial();
	init_Ports();

	for (;;) {
		
		//_delay_ms(1000); 
	}
	return 0;
}

