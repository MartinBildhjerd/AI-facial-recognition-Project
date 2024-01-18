
#define F_CPU 8000000UL
#define BAUD_RATE 9600
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <xc.h>
#include <avr/interrupt.h>

unsigned char DataOut = 0;

void init_serial()
{
	UCSR0B = (1 << TXEN0) | (1 << UDRIE0); // EN transmitter data register empty interrupt.
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Select 8-bit size.
	UBRR0L = 0x67; // Config baud rate
	sei(); // Activate global interrupt system
}

void init_Attiny85_PORTS()
{
	PORTB = (1 << PB0) | (1 << PB2); // input pins
	DDRB |= (1 << DDB1) | (1 << DDB5); // output pins
}

ISR(USART_UDRE_vect) // Execute when data register is empty.
{
	UDR0 = DataOut; // Sending the data out
}

int main(void)
{
	init_Attiny85_PORTS();
	init_serial();

	for(;;)
	{
		
	}
}
