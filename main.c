// TI example code

#include "robotsensor.h"

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  initializeSensorSubsystem();
  initializeLights();



  for (;;)
  {
	  initializeLeftSensor();
		if (ADC10MEM < 0x299)
			turnLeftLightOff();
		else
			turnLeftLightOn();


		initializeRightSensor();
		if (ADC10MEM < 0x2FF)
			turnRightLightOff();
		else
			turnRightLightOn();

  }

    return 0;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}
