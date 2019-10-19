/*
MicroArduino.h: 

Created by David M. Holtz
June 2018

*/

#include "Arduino.h"
#include "MicroArduino.h"

MicroArduino micro;

MicroArduino::MicroArduino()
{
}

void MicroArduino::init()
{	
	pinMode(RGB_RED, OUTPUT);
	pinMode(RGB_GREEN, OUTPUT);
	digitalWrite(RGB_RED, LOW);
	digitalWrite(RGB_GREEN, LOW);
}

DCMotor *MicroArduino::getDCMotor(uint8_t motorID)
{
	if (motorID < 1 || motorID > 4)
		return NULL;
	if (motorID == 1 || motorID == 2)
	{
		motorID--;
		dcMotors[motorID].setDRV(dcMotorPins1[motorID][0], dcMotorPins1[motorID][1], dcMotorPins1[motorID][2]);
		return &dcMotors[motorID];
	}
	else
	{
		motorID -= 3;
		dcMotors[motorID + 2].setDRV(dcMotorPins2[motorID][0], dcMotorPins2[motorID][1]);
		return &dcMotors[motorID + 2];
	}
}
