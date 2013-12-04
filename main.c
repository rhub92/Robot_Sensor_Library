// TI example code

#include "robotsensor.h"

void initializeLights() {
	P1DIR |= BIT0;
	P1DIR |= BIT6;
}

void turnLeftLightOn(){
	P1OUT |= BIT0;
}

void turnRightLightOn(){
	P1OUT |= BIT6;
}

void turnLeftLightOff(){
	P1OUT &= ~BIT0;
}

void turnRightLightOff(){
	P1OUT &= ~BIT6;
}


int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  initializeSensorSubsystem();
  initializeLights();



  for (;;)
  {
	  initializeLeftSensor();
		if (voltageReading() < 0x299)
			turnLeftLightOff();
		else
			turnLeftLightOn();


		initializeRightSensor();
		if (voltageReading() < 0x2FF)
			turnRightLightOff();
		else
			turnRightLightOn();

  }

    return 0;
}
