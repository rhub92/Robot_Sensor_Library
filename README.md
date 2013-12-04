Robot_Sensor_Library
====================

## Functions

- `void initializeSensorSubsystem()`
    - Initializes the subsystem for the sensors on the robot

- `void initializeLeftSensor()`
    - Initializes the left sensor on the robot

- `void initializeRightSensor()`
   - Initializes the right sensor on the robot

- `void voltageReading()`
    - returns the voltage reading from the sensor on the robot


## Sample code

```c
void initializeLeftSensor() {
    
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_4;                       
	ADC10AE0 |= BIT4;
	ADC10CTL0 |= ENC + ADC10SC;  
	__bis_SR_register(CPUOFF + GIE);
    
}
```
This code initializes the left sensor on the robot by disabling the ADC10 then selecting and setting the appropriate 
input channel. It then enables the ADC10 and starts sampling and finally puts the CPU in low power mode.

## Threshold Values

- The sensor will emit a voltage of 0.55 V when it is a foot away from the wall in the maze

- The sensor will emit a voltage of 0.65 V when it is 6 inches away from the wall in the maze

- The sensor will emit a voltage of 4.55 V when it is about half an inch away from the wall in the maze
