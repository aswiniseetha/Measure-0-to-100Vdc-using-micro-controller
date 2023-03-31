# Measure-0-to-100Vdc-using-micro-controller
In this project we will measure the DC voltage (0-100V) using PIC Analog to Digital Converter.


Digital Voltmeters are most common devices for Embedded and Hardware Engineers and are used on daily purpose for measuring voltage values in their circuits. In this project i will show you how to make digital voltmeter using Microchip PIC micro-controller and then display voltage values on multiplexed seven segment display.

Algorithm for measurement

Read the ADC value from the PORT2.
#define dat P2
val=dat*0.02;

After multiplying by 100, you get a positive interger value of three digits.
val1=val*100;

Separate individual numbers and print them on LCD including the decimal point.
temp=(((val1/100)%10)+48);

display(temp);

display(‘.’);

temp=(((val1/10)%10)+48);

display(temp);

temp=((val1%10)+48);

display(temp);

Flowchart

![The-flow-chart-of-voltage-calculation](https://user-images.githubusercontent.com/129486990/229060052-6a635361-a07a-4a84-a1bd-2c3bda4906df.png)

