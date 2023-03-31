/*
 * File:   main.c
 * Author: Aswini Karthik
 *
 * Created on 31 March, 2023, 12:22 PM
 */

void main()
{
  CMCON = 0x07;
  ANSEL = 0x08;
  TRISA |= 0x10;  // RA4/AN3 as Input
  ADCON0 = 0x8D;  // Right Justified, VDD, AN3 Selected, A/D Power-Up
  ADCON1 = 0x10;
  InitTimer0 ();
  Initialize_Display ();
  while(1)
  {
    uint16_t adc_data = 0;
    ADCON0 = 0x8D;
    ADCON0bits.GO_DONE = 1;   // Start Conversion
    while( ADCON0bits.GO_DONE );  // Wait Here
    adc_data = ADRESH<<8;
    adc_data |= ADRESL;
    adc_data = adc_data & 0x3FF;
    adc_data = adc_data/10;
    uint8_t d1, d2, d3;
    d1 = adc_data % 10;
    d2 = (adc_data/10) % 10;
    d3 = (adc_data/100) % 10;
    
    PORTA &= 0xF8;
    PORTA |= 0x04;
    Display_Value (SevenSegment[d1]);
    __delay_ms(10);
    PORTA &= 0xF8;
    PORTA |= 0x02;
    Display_Value (SevenSegment[d2]);
    __delay_ms(10);
    PORTA &= 0xF8;
    PORTA |= 0x01;
    Display_Value (SevenSegment[d3]);
    __delay_ms(10);
  }
}

void Initialize_Display( void )
{
  TRISA &= 0xD8;  // RA0,RA1,RA2, RA5 as Output
  TRISC = 0x00;
  PORTA &= 0xD8;
  PORTC = 0x00;
}

void Display_Value( uint8_t code )
{
  /*
   * a -> RC0 (bit-0)
   * b -> RC3 (bit-1)
   * c -> RC5 (bit-2)
   * d -> RC4 (bit-3)
   * e -> RC2 (bit-4)
   * f -> RC1 (bit-5)
   * g -> RA5 (bit-6)
   */
  PORTC = 0;
  PORTA &= 0xDF;
  if ( code == BLANK_Indx )
  {
    PORTC = 0xFF;
    PORTA |= 0x20;
  }
  else
  {
    // RC0
    if( code & 0x01 )
      PORTC |= 0x01;
    // RC3
    if( code & 0x02 )
      PORTC |= 0x08;
    // RC5
    if( code & 0x04 )
      PORTC |= 0x20;
    // RC4
    if( code & 0x08 )
      PORTC |= 0x10;
    // RC2
    if( code & 0x10 )
      PORTC |= 0x04;
    // RC1
    if( code & 0x20 )
      PORTC |= 0x02;
    // RA5
    if( code & 0x40 )
      PORTA |= 0x20;
  }
}