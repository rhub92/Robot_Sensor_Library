Robot_Sensor_Library
====================

## Functions

- `void initializeSensorSubsystem()`
    - Initializes the subsystem for the sensors on the robot

- `void leftSensorReading()`
    - returns the value from the left sensor

- `unsigned int rightSensorReading()`
   - returns the value from the right sensor




## Sample code

```c
unsigned int leftSensorReading() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_4;                       
	ADC10AE0 |= BIT4;
	ADC10CTL0 |= ENC + ADC10SC;         
	__bis_SR_register(CPUOFF + GIE);
	return ADC10MEM;
}
```
This code initializes the left sensor on the robot by disabling the ADC10 then selecting and setting the appropriate 
input channel. It then enables the ADC10 and starts sampling, puts the CPU in low power mode, and finally returns 

the reading from the left sensor

## Threshold Values

- The sensor will emit a voltage of 0.55 V when it is a foot away from the wall in the maze

- The sensor will emit a voltage of 0.65 V when it is 6 inches away from the wall in the maze

- The sensor will emit a voltage of 4.55 V when it is about half an inch away from the wall in the maze
