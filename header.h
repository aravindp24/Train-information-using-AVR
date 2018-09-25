/*
 * header.h
 *
 * Created: 25-09-2018 11:24:19
 *  Author: DESD
 */ 


#ifndef HEADER_H_
#define HEADER_H_


/*---------Preamble------------*/
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define BAUDRATE 9600
#define BAUD (F_CPU/(16UL*BAUDRATE))-1

void uart_init();
void uart_input_read(char []);
void uart_input_write(char []);
void uart_tx(char);
void led_init();
unsigned char uart_rx();
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void clear_bit(unsigned int);
void set_bit(unsigned int);
void enable(void);
void lcd_string(char []);
void lcd_goto(unsigned int x, unsigned int y);
void uart_init(void);
unsigned char uart_rx(void);
void interrupt_init();
void port_init();


#endif /* HEADER_H_ */