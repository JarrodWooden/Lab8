#include "start5.h"
#include <msp430.h>

/*
 * start5.c
 *
 *  Created on: Dec 5, 2014
 *      Author: C16Jarrod.Wooden
 */


void bothForward() {
	//_disable_interrupt();

	P2DIR |= BIT2 | BIT5;		//set port 2 pins 2 and 5 to the PWM outputs
	P2SEL |= BIT2 | BIT5;

	P2DIR |= BIT3 | BIT4;
	P2OUT &= ~(BIT3 | BIT4);	//cleared to zero since we are wanting to move forward

	TA1CTL &= ~MC1 | MC0;       // stop timer A0

	TA1CTL |= TACLR;


	TA1CTL |= TASSEL1;			//clock we are using


	TA1CCR0 = 100;
	TA1CCR1 = 50;
	TA1CCR2 = 50;

	TA1CCTL1 |= OUTMOD_3;		//set/reset mode for the clock
	TA1CCTL2 |= OUTMOD_3;


	TA1CTL |= MC_1;				//clock will count up

	//_enable_interrupt();
	//_delay_cycles(10000);


}

// ------------------------------------------------------------------------
//	Function for bothBackward();
//	moves the both wheels backward with a specific duty cycle (aka. power)
//
//	This takes some debugging and testing to make sure the right wheel is moving
//	as much as the left wheel (etc) - I left a duty cycle of 50%.
//
//	Use GPIOs to make the wheels move backward when set to one.
//
//--------------------------------------------------------------------------

void bothBackward() {

//	_disable_interrupt();
	P2DIR |= BIT2 | BIT5;
	P2SEL |= BIT2 | BIT5;

	P2DIR |= BIT3 | BIT4;
	P2OUT |= BIT3 | BIT4;		//set to one when moving backwards.

	TA1CTL &= ~MC1 | MC0;       // stop timer A0

	TA1CTL |= TACLR;


	TA1CTL |= TASSEL1;			//clock


	TA1CCR0 = 100;
	TA1CCR1 = 50;
	TA1CCR2 = 45;

	TA1CCTL1 |= OUTMOD_7;		//need to be reset/set for moving backwards or won't function
								//properly
	TA1CCTL2 |= OUTMOD_7;


	TA1CTL |= MC_1;

//	_delay_cycles(1000000);


}


// ------------------------------------------------------------------------
//	Function for tankRightForty();
//	make a forty five degree right turn moving the right wheel backward and left wheel
//	forward for a certain amount of time
//
//	This takes some debugging and testing to make sure the right wheel is moving
//	as much as the left wheel (etc) - I left a duty cycle of 50%.
//
//--------------------------------------------------------------------------

void tankRightForty() {
//	_disable_interrupt();
		P2DIR |= BIT2 | BIT5;
		P2SEL |= BIT2 | BIT5;

		P2DIR |= BIT3 | BIT4;
		P2OUT &= ~(BIT4);
		P2OUT |= BIT3;

		TA1CTL &= ~MC1 | MC0;       // stop timer A0

		TA1CTL |= TACLR;


		TA1CTL |= TASSEL1;			//


		TA1CCR0 = 100;
		TA1CCR1 = 50;
		TA1CCR2 = 50;

		TA1CCTL1 |= OUTMOD_3;
		TA1CCTL2 |= OUTMOD_7;


		TA1CTL |= MC_1;

//		_delay_cycles(300000);


}

// ------------------------------------------------------------------------
//	Function for tankLeftForty();
//	make a forty five degree right turn moving the right wheel forward and left wheel
//	backward for a certain amount of time
//
//	This takes some debugging and testing to make sure the right wheel is moving
//	as much as the left wheel (etc) - I left a duty cycle of 50%.
//
//--------------------------------------------------------------------------

void tankLeftForty(){

//	_disable_interrupt();
	P2DIR |= BIT2 | BIT5;
	P2SEL |= BIT2 | BIT5;

	P2DIR |= BIT3 | BIT4;
	P2OUT |= BIT4;
	P2OUT &= ~BIT3;

	TA1CTL &= ~MC1 | MC0;       // stop timer A0

	TA1CTL |= TACLR;


	TA1CTL |= TASSEL1;			//


	TA1CCR0 = 100;
	TA1CCR1 = 50;
	TA1CCR2 = 50;

	TA1CCTL1 |= OUTMOD_7;
	TA1CCTL2 |= OUTMOD_3;


	TA1CTL |= MC_1;

//	_delay_cycles(370000);

}

// ------------------------------------------------------------------------
//	Function for tankRightNinety();
//	make a ninety degree right turn moving the right wheel backward and left wheel
//	forward for a certain amount of time
//
//	This takes some debugging and testing to make sure the right wheel is moving
//	as much as the left wheel (etc) - I left a duty cycle of 50%.
//
//--------------------------------------------------------------------------
void tankRightNinety(){
//
//	_disable_interrupt();
	P2DIR |= BIT2 | BIT5;
			P2SEL |= BIT2 | BIT5;

			P2DIR |= BIT3 | BIT4;
			P2OUT &= ~(BIT4);
			P2OUT |= BIT3;

			TA1CTL &= ~MC1 | MC0;       // stop timer A0

			TA1CTL |= TACLR;


			TA1CTL |= TASSEL1;			//


			TA1CCR0 = 100;
			TA1CCR1 = 50;
			TA1CCR2 = 50;

			TA1CCTL1 |= OUTMOD_3;
			TA1CCTL2 |= OUTMOD_7;


			TA1CTL |= MC_1;
//
//			_delay_cycles(580000);
}

// ------------------------------------------------------------------------
//	Function for tankLeftNinety();
//	make a ninety degree left turn moving the right wheel forward and left wheel
//	backward for a certain amount of time
//
//	This takes some debugging and testing to make sure the right wheel is moving
//	as much as the left wheel (etc) - I left a duty cycle of 50%.
//
//--------------------------------------------------------------------------
void tankLeftNinety(){

//	_disable_interrupt();
	P2DIR |= BIT2 | BIT5;
	P2SEL |= BIT2 | BIT5;

	P2DIR |= BIT3 | BIT4;
	P2OUT |= BIT4;
	P2OUT &= ~BIT3;

	TA1CTL &= ~MC1 | MC0;       // stop timer A0

	TA1CTL |= TACLR;


	TA1CTL |= TASSEL1;			//


	TA1CCR0 = 100;
	TA1CCR1 = 50;
	TA1CCR2 = 50;

	TA1CCTL1 |= OUTMOD_7;
	TA1CCTL2 |= OUTMOD_3;


	TA1CTL |= MC_1;
//
//	_delay_cycles(650000);
}
// ------------------------------------------------------------------------
//	Function for stopRobot();
//
//	stop everything on the robot and make it not move for an extended amount of time
//	in this case 1000 counts
//
//
//--------------------------------------------------------------------------
void stopRobot(){

	P2DIR &= ~(BIT2 | BIT5);

	P2DIR &= ~(BIT3 | BIT4);
	P2OUT &= ~(BIT3 | BIT4);

	TA1CTL &= ~MC1 | MC0;       // stop timer A0

	TA1CTL |= TACLR;

}
