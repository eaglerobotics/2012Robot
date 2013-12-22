#include "TurretBase.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"

TurretBase::TurretBase(double iKp, double iKi, double iKd) 
	: PIDSubsystem("TurretBase", iKp, iKi, iKd)
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	Kp = iKp;
	Ki = iKi;
	Kd = iKd; 
	errorTerm = 0;
}

double TurretBase::ReturnPIDInput() 
{
	return errorTerm;
}

void TurretBase::UsePIDOutput(double output) 
{
	
}

void TurretBase::InitDefaultCommand() 
{
	
}


void TurretBase::SetErrorTerm(double error)
{
	errorTerm = error;
}
