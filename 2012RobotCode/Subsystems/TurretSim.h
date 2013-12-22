#ifndef TURRETSIM_H
#define TURRETSIM_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "TurretBase.h"

/**
 *
 *
 * @author Jarrett
 */
class TurretSim: public TurretBase {
private:
	double angleSimBase;
//	double angleSim;
	Servo servoSim;
	
public:
	TurretSim(double Kp = 0.1, double Ki = 0, double Kd = 0);
	void UsePIDOutput(double output);
//	void InitDefaultCommand();
//	void TurnRelative(double angle);
//	void TurnAbsolute(double angle);
	
	
};

#endif
