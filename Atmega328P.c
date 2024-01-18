#define F_CPU 8000000UL
#define BAUD_RATE 9600
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <xc.h>
#include <avr/interrupt.h>

unsigned DataIn;

void init_serial()
{
	UCSR0B = (1 << RXEN0) | (1 << RXCIE0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	UBRR0L = 0x67;
	sei();
}

void init_Atmega328P_PORTS()
{
	DDRB &= ~(1 << PB0); // PB0 in
	DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5); // PB1-5 out
	PORTB = (1 << PB0);
}

ISR(USART_RX_vect)
{
	DataIn = UDR0;
}

int main(void)
{
	init_Atmega328P_PORTS();
	init_serial();

	for(;;)
	{
		// Your main loop code here
	}
}
