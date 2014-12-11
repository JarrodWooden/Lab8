#include <msp430.h>
#include "ATD.h"

/*
 * ATDI.c
 *
 *  Created on: Dec 3, 2014
 *      Author: C16Jarrod.Wooden
 */

	unsigned int readLeftSensor() {

		ADC10CTL0 = ADC10SHT_3 + ADC10ON; // ADC10ON, interrupt enabled
		ADC10CTL1 = INCH_2;                       // input A2 (left sensor)
		ADC10AE0 |= BIT2;                         // PA.1 ADC option select
		ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK

		ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start

		while(ADC10CTL1 & ADC10BUSY);

		return ADC10MEM;

	}

	unsigned int readRightSensor() {

		ADC10CTL0 = ADC10SHT_3 + ADC10ON; // ADC10ON, interrupt enabled
		ADC10CTL1 = INCH_4;                       // input A2 (left sensor)
		ADC10AE0 |= BIT4;                         // PA.1 ADC option select
		ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK

		ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start

		while(ADC10CTL1 & ADC10BUSY);
		return ADC10MEM;
	}

	unsigned int readMiddleSensor() {

		ADC10CTL0 = ADC10SHT_3 + ADC10ON; // ADC10ON, interrupt enabled
		ADC10CTL1 = INCH_3;                       // input A2 (left sensor)
		ADC10AE0 |= BIT3;                         // PA.1 ADC option select
		ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK

		ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start

		while(ADC10CTL1 & ADC10BUSY);

		return ADC10MEM;

	}
