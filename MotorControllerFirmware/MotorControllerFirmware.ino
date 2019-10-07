#include "MotorDriver.h"
#include <Wire.h>

const uint8_t DEVICE_ADDRESS = 0x50;

enum COMMAND
{
	STOP = 0,
	SET_RAW = 'R',
	SET_SETPOINT = 'S',
	SET_P = 'P',
	SET_I = 'I',
	SET_D = 'D',
};

void setup()
{
	Wire.begin(DEVICE_ADDRESS); // todo: select address from harware
	Wire.onReceive(receiveEvent);
}

void loop()
{

}

void emergencyStop()
{
	// todo: assert e-stop line low
	driverStop();
	Wire.beginTransmission(0);
	Wire.write('E');
	Wire.write(DEVICE_ADDRESS);
	Wire.endTransmission();
}

void receiveEvent(int bytesCount)
{
	uint8_t command = Wire.read();
	switch (command)
	{
		case SET_RAW: // set point
				auto direction = Wire.read();
				auto speed = Wire.read();
				driverSet(direction, speed);
		case STOP:
		default: // stop
				emergencyStop();
				break;
	}

	if (Wire.available()) // too many data bytes
	{
		emergencyStop();
	}
}
