/*
 * my slave.c
 *
 * Created: 1/5/2021 10:36:23 AM
 * Author : Fatima Tayyab
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include "LCD.h"
#define MISO 4


int main(void)
{
	
	
	LCD_Init();
	
	DDRB = (1<<MISO);
	SPCR = (1<<SPE);
	
	while (1)
	{
		//SPDR = 'G';
		while(!(SPSR &(1<<SPIF)));
		LCD_Data(SPDR);
	}
	
}


