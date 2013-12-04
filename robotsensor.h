/*
 * robotsensor.h
 *
 *  Created on: Dec 4, 2013
 *      Author: c15ryan.hub
 */

#include <msp430g2553.h>

void initializeSensorSubsystem();

void initializeLeftSensor();

void initializeRightSensor();

unsigned int voltageReading();

