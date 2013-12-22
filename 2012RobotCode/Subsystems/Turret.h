#ifndef TURRET_H
#define TURRET_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "TurretBase.h"

/**
 *
 *
 * @author AG132127
 */
class TurretPIDChange;

class Turret: public TurretBase {
private:
	Victor *turretMotor;
	DigitalInput *turretSwitchL;
	DigitalInput *turretSwitchR;
	
public:
	Turret();
	void InitDefaultCommand();
	 void setMotor(float xAxis);
	 bool isLlimit ();
	 bool isRlimit ();
	 float getMotor ();
	 void UsePIDOutput(double output);
	 void DeltaPID(float dP, float dI, float dD);
};

#endif
