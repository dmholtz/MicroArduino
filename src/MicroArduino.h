/*
MicroArduino.h:

Created by David M. Holtz
June 2018

*/

// I/O definition

#define I1 A0
#define I2 A1
#define I3 A2
#define I4 A3
#define I5 A4
#define I6 A5

#define C1 7
#define C2 1 // TX
#define C3 0 // RX

#define RGB_RED 11
#define RGB_GREEN 13

#ifndef MicroArduino_h
#define MicroArduino_h

#include "Arduino.h"
#include "DCMotor.h"

class MicroArduino
{
  public:
	MicroArduino();
	void init();

	DCMotor *getDCMotor(uint8_t motorID);

  private:
	// {enable, direction, mode}
	const uint8_t dcMotorPins1[2][3] = {{10, 8, MISO}, {9, 12, MISO}};
	const uint8_t dcMotorPins2[2][2] = {{5, 4}, {6, MOSI}};

	DCMotor dcMotors[4];
};

extern MicroArduino micro;

#endif


