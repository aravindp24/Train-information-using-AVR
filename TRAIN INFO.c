/*
 * Program to implement Train Booking via usart,lcd and external interrupt in Atmel64A
 * Created: 17-09-2018 10:08:24 in Atmel Studio 6.2
 *  Author: Aravind P
 */ 



#include "header.h"
/*--------Main Function------*/
int main(void)
{  
	
	interrupt_init();          //interrupt initialization
	port_init();
	sei();
	led_init();
	DDRA=0xff;
	
	char welcome[]="\r\nWelcome to Train Database\r\n";
	char usrdisp[]="Enter train number\r\n";
	char train[]="12626";
   
	
	
	uart_init();
	lcd_init();
	lcd_cmd(0x14);              //Cursor or display shift command
	lcd_cmd(0x06);              //Entry mode set command
	lcd_cmd(0x0e);              //command to set cursor characteristics
	lcd_cmd(0x01);              //Clear display
	lcd_cmd(0x80);              //set address of DDRAM
	char tno[15];
	char a[]="Chennai express";
	char b[]="Kochi to Mumbai";
	char c[]="No trains exist!";
	char d[]="\r\nThank you for enquiry";
	
	_delay_ms(1000);                  //uart_input_read(test); 
	uart_input_write(welcome);
    _delay_ms(1000);                   //uart_input_read(test);
	uart_input_write(usrdisp);
	uart_input_read(tno);
    
	
	
    if(!(strcmp(tno,train) ))            //train no: check
	{
		lcd_string(a);
		lcd_goto(1,0);
		lcd_string(b);
		_delay_ms(2000);
		
	}
	else
	{
	lcd_string(c);
	exit(0);
	}
	
	uart_input_write(d);                    //write data to uart
	

}


