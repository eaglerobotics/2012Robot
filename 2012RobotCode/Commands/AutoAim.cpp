#include "AutoAim.h"
#include "../Subsystems/TurretBase.h"
#include "../Subsystems/VisionBase.h"
#include "../util.h"
#include <math.h>
AutoAim::AutoAim()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(turret);
//	Requires(vision)
	lastPosition = -99;
	nextRunTime = 0;
}

// Called just before this Command runs the first time
void AutoAim::Initialize()
{
	printf("AutoAim \n");
	turret->Enable();
}

// Called repeatedly when this Command is scheduled to run
void AutoAim::Execute()
{
	printf("AutoAim::Exec\n");
	
	float xAxis = deadband(oi->getOpStickXAxis(),0.3);
	if (xAxis)
	{
		turret->Disable();
		turret->setMotor(xAxis);
		return;
	}
	
//	if(nextRunTime > Timer::GetFPGATimestamp())
//		return;
	
	// the Axis Camera field of vierw is 47 degrees
//	double angle = 0;
	double xDistance = 0;
	vision->particleAnalysis();
	printf("Part ana complete\n");
	int targets = vision->getNumberOfTargets();
	printf("NumTargets=%d\n", targets);
	if (targets != 0)
	{
	//	int maxHeight = 0, maxIndex = 0; 
	//	for (int i = 0; i<targets; i++)
	//	{
	//		vision->setTargetParticle(i);
	//		if (vision->getYPosition()>maxHeight)
	//		{
	//			maxHeight = vision->getYPosition();
	//			maxIndex = i;
	//		}
	//	}
		
//		vision->setTargetParticle(0);
		
		xDistance = vision->getNormalizedXPosition();
		printf("xnorm = %.3lf\n", xDistance);
//	
//		angle = (23.5 * xDistance);
//		angle = -angle;
//		angle = max(-0.3, min(0.3, angle));
//		turret->TurnRelative(angle);
//		if(lastPosition < -1 || fabs(lastPosition - xDistance) < 0.005)
		{
			turret->Enable();
			turret->SetErrorTerm(xDistance);
//			nextRunTime = Timer::GetFPGATimestamp() + 0.05;
		}
//		else
//			nextRunTime = Timer::GetFPGATimestamp() + 0.05;
//		
		lastPosition = xDistance;
	}
	else
	{
		lastPosition = -99;
		turret->SetErrorTerm(0);
		turret->Disable();
//		nextRunTime = Timer::GetFPGATimestamp() + 0.05;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoAim::IsFinished()
{
	// when the robot lose the target the AutoAim Command will terminate so
	// the boolean that knows if the target is there will terminate the command
	// when it turns false (the target is lost)
	return false;
}

// Called once after isFinished returns true
void AutoAim::End()
{
	printf("AutoAim end\n");
	turret->SetErrorTerm(0);
	turret->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoAim::Interrupted()
{
//	Review: Research cancel function and possibly use it
	printf("AutoAim interrupted\n");
	turret->SetErrorTerm(0);
	turret->Disable();
}
