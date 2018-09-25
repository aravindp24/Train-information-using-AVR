/*
 * CFile1.c
 *
 * Created: 25-09-2018 11:25:25
 *  Author: DESD
 */ 
/*-------Function Definitions---------*/
#include "header.h"
void uart_init()
{
	UBRR1H=(BAUD)>>8;
	UBRR1L=BAUD;
	UCSR1B=(1<<TXEN1) | (1<<RXEN1);
	UCSR1C=(1<<UCSZ10) | (1<<UCSZ11);
	
}
void uart_input_read(char input[])          //Function to read input
{
	unsigned int i=0;
	do{
		input[i]=uart_rx();
		uart_tx(input[i]);
		i++;
	}while(input[i-1]!='\r');
	input[i-1]='\0';
	
}


void uart_input_write(char input[])         //Function tow write
{
	unsigned int i=0;
	while(input[i]!='\0')
	{
		uart_tx(input[i]);
		i++;
	}
	
}

unsigned char uart_rx()                     //uart character receive
{
	char character;
	while(!(UCSR1A & (1<<RXC1)));
	character=UDR1;
	return character;
}

void uart_tx(char character)                //uart character receive
{
	
	while(!(UCSR1A & (1<<UDRE1)));
	UDR1=character;
}

void led_init()                            //led initialize
{
	DDRC=0xff;
	PORTC=0xff;
}

void lcd_init()                             //lcd initialize
{
	lcd_cmd(0x28);
	clear_bit(0);
	enable();
}

void lcd_cmd(unsigned char ch)
{
	PORTA= (ch&0xf0);			// sending Higher nibble first
	clear_bit(0);				//Command Rsgister select
	enable();				//Enable pulse
	ch = ch<<4;
	PORTA= (ch&0xf0);			//Sending lower nibble afterwards
	clear_bit(0);
	enable();
}

void lcd_data(unsigned char ch)
{
	PORTA= (ch&0xf0);
	set_bit(0);
	enable();
	ch = ch<<4;
	PORTA= (ch&0xf0);
	set_bit(0);
	enable();
}

void clear_bit(unsigned int bit)
{
	PORTA= PORTA&(~(1<<bit));
}


void set_bit(unsigned int bit)
{
	PORTA= PORTA|(1<<bit);
}


void enable(void)
{
	set_bit(2);
	_delay_ms(20);
	clear_bit(2);
	_delay_ms(20);
}

void lcd_string(char a[])
{
	char *str=a;
	while(*str!='\0')
	{
		lcd_data(*str++);
	}
}


void lcd_goto(unsigned int x, unsigned int y)
{
	if(x==0)
	lcd_cmd(0x80|y);
	if(x==1)
	lcd_cmd(0xc0|y);
}
void port_init()
{
	DDRE=0x00;
	PORTE=0xFF;
	DDRC=0xff;
	PORTC=0xff;
}
void interrupt_init()
{
	EICRB=0x00;
	EIMSK=0xc0;
	
}

ISR(INT7_vect)
{


	DDRA=0xff;
	DDRC=0xff;
	char e[25]="Booking confirmed!";
	PORTC=0x00;
	lcd_cmd(0x01);
	
	lcd_string(e);

sei();}