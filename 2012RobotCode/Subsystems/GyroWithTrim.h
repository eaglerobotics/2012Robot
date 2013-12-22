#ifndef GYRO_WITH_TRIM_H
#define GYRO_WITH_TRIM_H

#include "Gyro.h"

class GyroWithTrim : public Gyro {
private:
	float trim;
	
public:
	GyroWithTrim(UINT32 channel);
	GyroWithTrim(UINT8 moduleNumber, UINT32 channel);
	virtual float GetAngle();
	virtual void ZeroGyro();
	virtual double PIDGet();
	void SetTrim(float trim);
	float GetTrim();
};

#endif
