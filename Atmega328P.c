#define F_CPU 8000000UL
#define BAUD_RATE 9600
#include <avr/io.h>
#include <util/dalay.h>
#include <string.h>
#include <stdio.h>
#include <xc.h>
#include <avr/interrupt.h>


//serial communication function
void init_serial()
void init_Atmega328P_PORTS()
unsigned DataIn; 

ISR(UART_RX_vect) //ver 2
{
	DataIn = UDR0; 
}

int main void 
{	
	void init_Atmega328P_PORTS; 
	void init_serial; 
	
		while(1)
		{
		
		}
	
}

void init_Atmega328P_PORTS()
{
	//PB0 in
	//PB1-5 out
}

void init_serial()
{
	UCSR0B = (1<<RXEN0) | (1<<RXCIE0);
	UCSROC = (1<<UCSZ01) | (1<<UCSZ00);
	UBR0L = 0x67;
	sei;
}

