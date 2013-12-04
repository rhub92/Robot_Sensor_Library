/*
 * robotsensor.c
 *
 *  Created on: Dec 4, 2013
 *      Author: c15ryan.hub
 */

#include "robotsensor.h"

void initializeSensorSubsystem() {
	  ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
}

void initializeLeftSensor() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_4;                       // input A5
	ADC10AE0 |= BIT4;
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);
}

void initializeRightSensor() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_5;                       // input A5
	ADC10AE0 |= BIT5;                         // PA.1 ADC option select
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);
}

unsigned int voltageReading(){
	return ADC10MEM;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}
