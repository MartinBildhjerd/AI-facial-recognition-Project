#define F_CPU 8000000UL
#define BAUD_RATE 9600
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <xc.h>
#include <avr/interrupt.h>

void init_serial()
void init_Attiny85_PORTS()
unsigned char DataOut = 0;


ISR(USART_UDRE_vect) 
{
	UDR0 = DataOut; 
}

int main(void)
{
	init_Attiny85_PORTS(); 
	init_serial();
	
    while (1) 
    {
		
    }
}

void init_serial()
{
		UCSR0B = (1<<TXEN0) | (1<<UDRIE0); //EN transmitter data register empty interrupt. 
		UCSROC = (1<<UCSZ01) | (1<<UCSZ00); //Select 8bit size. 
		UBR0L = 0x67; //Config baud rate
		sei //Activate global interrupt system
}

void init_Attiny85_PORTS()
{
	PORTB = (1<<PB0)|(1<<PB2); //input pins
	DDRB = (1<<DDB1)|(1<<DDB5); //outputpins
}
