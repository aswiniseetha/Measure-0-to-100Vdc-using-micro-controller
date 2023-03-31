# Measure-0-to-100Vdc-using-micro-controller
In this project we will measure the DC voltage (0-100V) using PIC Analog to Digital Converter.


Digital Voltmeters are most common devices for Embedded and Hardware Engineers and are used on daily purpose for measuring voltage values in their circuits. In this project i will show you how to make digital voltmeter using Microchip PIC micro-controller and then display voltage values on multiplexed seven segment display.

Algorithm for measurement

1) We get digital value of the analog signal and let's say it is stored in ADC_DATA variable.

2)Next step is to convert this digital value in voltage.

3)Analog Value Sensed by PIC,
ANALOG_VALUE_PIC = (Reference Voltage*ADC_DATA)/(2^10)
ANALOG_VALUE_PIC = (5*ADC_DATA)/(1024)

4)Reference Voltage in our case is 5V and we are using 10-bit ADC of PIC micro-controller, that's why 2^10 = 1024 is used. ANALOG_VALUE = ANALOG_VALUE_PIC * 20 We multiplied by 20 because, we scale down the voltage by 20 as explained above. ANALOG_VALUE = (5*20/1024)*ADC_DATA

5)We have (5*10/1024) as constant value, which is equivalent to = 0.098 and i rounded off this to 0.01 or (1/10), to make the calculation simple, with some error in the system.
 
Final Expression, ANALOG_VALUE = ADC_DATA/10

Flowchart

![The-flow-chart-of-voltage-calculation](https://user-images.githubusercontent.com/129486990/229060052-6a635361-a07a-4a84-a1bd-2c3bda4906df.png)

