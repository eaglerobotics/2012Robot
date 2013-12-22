#include "TurretSim.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"

TurretSim::TurretSim(double Kp, double Ki, double Kd)
	: TurretBase(Kp, Ki, Kd)
	, servoSim(1, 10)
{
//	angleSim = 90;
	angleSimBase = 90;
	SetSetpoint(0);
//	Enable();
}

void TurretSim::UsePIDOutput(double output) 
{
	output *= 90;
	printf("Angle = %.1lf\n", angleSimBase + output);
	servoSim.SetAngle(angleSimBase + output);
}

//void TurretSim::InitDefaultCommand() 
//{
//	
//}

//void TurretSim::TurnRelative(double angle)
//{
////	angleSim += angle;
////	SetSetpoint(angleSim);
////	printf("Angle = %.1lf \n", angleSim);
////	servoSim.SetAngle(angleSim);
//}
//
//void TurretSim::TurnAbsolute(double angle)
//{
////	angleSim = angle;
////	SetSetpoint(angleSim);
////	printf("Angle = %.1lf \n", angleSim);
////	servoSim.SetAngle(angleSim);
//}
