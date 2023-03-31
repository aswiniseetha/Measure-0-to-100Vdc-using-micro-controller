/*
 * File:   main.h
 * Author: Aswini Karthik
 *
 * Created on 31 March, 2023, 2:19 PM
 */


#include "config.h"

#define REFRESH_INTERVAL  50ul

#define DIGIT_0_Indx      0x40
#define DIGIT_1_Indx      0x79
#define DIGIT_2_Indx      0x24
#define DIGIT_3_Indx      0x30
#define DIGIT_4_Indx      0x19
#define DIGIT_5_Indx      0x12
#define DIGIT_6_Indx      0x02
#define DIGIT_7_Indx      0x78
#define DIGIT_8_Indx      0x00
#define DIGIT_9_Indx      0x10
#define BLANK_Indx        0x7F


uint8_t SevenSegment[] = {  DIGIT_0_Indx, DIGIT_1_Indx, DIGIT_2_Indx, 
                            DIGIT_3_Indx, DIGIT_4_Indx, DIGIT_5_Indx, 
                            DIGIT_6_Indx, DIGIT_7_Indx, DIGIT_8_Indx, 
                            DIGIT_9_Indx };
uint16_t SevenSegment[] = {  DIGIT_0_Indx, DIGIT_1_Indx, DIGIT_2_Indx, 
                            DIGIT_3_Indx, DIGIT_4_Indx, DIGIT_5_Indx, 
                            DIGIT_6_Indx, DIGIT_7_Indx, DIGIT_8_Indx, 
                            DIGIT_9_Indx };

void Initialize_Display( void );
void Display_Value( uint8_t code );