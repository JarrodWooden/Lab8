#include <msp430.h> 
#include "ATD.h"
#include "start5.h"


/*
 * main.c
 */

	unsigned int compare;
	unsigned int compareR;
	unsigned int compareL;
	unsigned char stop;


	void initMSP430();

int main(void) {
	WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled

	P1DIR |= BIT0 | BIT6;                    // Set P1.0 to output direction
	P1OUT &= ~(BIT0 | BIT6);                    // Set P1.0 to output direction
	initMSP430();

	bothForward();
	stop = 0;

	while (1) {
//		bothForward();
	}
}


void initMSP430() {

	IFG1=0; 					// clear interrupt flag1
	WDTCTL=WDTPW+WDTHOLD; 		// stop WD

	BCSCTL1 = CALBC1_8MHZ;
	DCOCTL = CALDCO_8MHZ;

	P1DIR |= BIT0 | BIT6;				// Enable updates to the LED
	P1OUT &= ~(BIT0 | BIT6);			// An turn the LED off

	TA0CCR0 = 0x3000;					// create a 16mS roll-over period
	TACTL &= ~TAIFG;					// clear flag before enabling interrupts = good practice
	TACTL = ID_3 | TASSEL_2 | MC_1 | TAIE;		// Use 1:1 presclar off MCLK and enable interrupts

	_enable_interrupt();
}

#pragma vector = TIMER0_A1_VECTOR			// This is from the MSP430G2553.h file
__interrupt void timerOverflow (void) {


	compare = readMiddleSensor();
	compareL = readLeftSensor();
	compareR = readRightSensor();

	if (compare < 0x0200) {
		bothForward();

		if (compareL > 0x0230) {
			tankRightNinety();
		}

		if (compareL < 0x0195) {
			tankLeftNinety();
		}


	} else

	if (compareR < 0x0100) {
	tankRightNinety();
	int i = 0xFFFF;
	while (i > 0) {
		i--;
	}
	int j = 0x003F;
	while (j>0) {
		j--;
	}
	}

	TACTL &= ~TAIFG;
}


