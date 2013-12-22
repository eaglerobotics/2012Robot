#include "GyroWithTrim.h"

GyroWithTrim::GyroWithTrim(UINT8 moduleNumber, UINT32 channel) : Gyro(moduleNumber, channel)
{	
}

GyroWithTrim::GyroWithTrim(UINT32 channel) : Gyro(channel)
{
}

float GyroWithTrim::GetAngle()
{
	return Gyro::GetAngle()+trim;
}

double GyroWithTrim::PIDGet()
{
	return GetAngle();
}

void GyroWithTrim::ZeroGyro()
{
	trim = -Gyro::GetAngle();
}

void GyroWithTrim::SetTrim(float trim)
{
	this->trim = trim;
}

float GyroWithTrim::GetTrim()
{
	return trim;
}
