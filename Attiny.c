#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#define BAUD_RATE 9600
#define F_CPU 8000000UL

volatile uint8_t ObjectID;

void init_UART() {
	
	UBRR0L = 0x33; //9600 BAUDRATE
	UCSR0B = (1<<TXEN0);
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
}

ISR(USART_UDRE_vect) 
{
	UDR0 = ObjectID; 
}

ISR(USART_RX_vect) 
{
	
}

int main(void) 
{
	init_UART();
	sei();

	while (1) 
	{
		
		_delay_ms(1000); 
	}

	return 0;
}
