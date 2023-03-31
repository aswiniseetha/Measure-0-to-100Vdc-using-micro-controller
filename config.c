/*
 * File:   config.c
 * Author: Aswini Karthik
 *
 * Created on 31 March, 2023, 1:28 PM
 */


#include "config.h"

static uint32_t millisecond = 0;

uint32_t millis( void )
{
  uint32_t time = 0;
  GIE = 0;
  time = millisecond;
  GIE = 1;
  return time;
}

//Timer0
//Prescaler 1:4; TMR0 Preload = 6; Actual Interrupt Time : 1 ms
void InitTimer0()
{
  OPTION_REG = 0x81;
  TMR0		 = 6;
  INTCON	 = 0xA0;
}

void interrupt ISR_ROUTINE( )
{
  if( TMR0IF )
  {
    TMR0IF = 0;
    TMR0 = 6;
    millisecond++;
  }
}
