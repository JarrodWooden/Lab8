Lab8
====

Robot Maze Picture: 

https://cloud.githubusercontent.com/assets/6405923/5403019/6fd28c74-8146-11e4-9ca6-14329b531ccf.png

Required Functionaltiy Objective: program robot to use its sensors to navigate through door one of robot maze located in the link above
B Functionality: use robots sensors to let robot to navigate through door two
A Functionality: use robot's sensors to allow robot to navigate through door three. "If you get A Functionality, you get credit for Required and B Functionality."

A Functionality:

For this lab I didn't attempt to go through door 1 or door 2. I just went ahead and set up a program that would allow my robot to use its sensors to navigate to door 3 for A functionaltiy and then to be able to do the maze backwards as well.

I used my code from Lab 6 to make the robot move. All of the move operations for lab 6 were stored in a library called start5.c and start5.h. This allowed me to copy and paste the libraries to my Lab8 folder to use their move operations. The way I was going to implement my code was to keep on checking whether or not the robot should move forward, left, or right made there be no need for delay cylces at the end of each robot move. The robot will simply move to the range of distances from the wall it needs to be in.

I wanted to use a timer overflow that would jump to the Interrupt Service Routine to check the sensors after a designated time interval. The reason for this is that I didn't want the program to be checking the sensors so fast that the robot barely makes any progress and I didn't want to check them so slow that the robot was running into all the walls. The timer overflow method allowed me to set a time interval that was appropriate so that the robot didn't run into walls and it also finished the maze in a timely manner.

Here is the method I used to set the parameters for the timer overflow:

```
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

```

I made the interrupt service routine always check the middle sensor first. If there wasn't anything in front of the robot I always set the robot to move forward first because I want it to make as much progress forward, so most of the time the robot would be moving forward. If there is nothing in front of the robot it will first set the robot to move forward and then check if the robot was approaching the left or right boundaries. If it was approaching one of the boundaries it set the robot to move left or right accordingly. If there was something directly in front of the robot, the robot would move 90 degrees right and then continue moving forward. ISR method can be seen below:

```
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
```

#Have a Great Air Force Day!!
