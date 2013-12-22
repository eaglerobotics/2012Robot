#include "AutoRange.h"
#include "../SubSystems/ShooterBase.h"
#include "../SubSystems/VisionBase.h"

AutoRange::AutoRange()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(shooter);
}

// Called just before this Command runs the first time
void AutoRange::Initialize()
{
	
}

// Called repeatedly when this Command is scheduled to run
void AutoRange::Execute()
{
	float distance;
	distance = vision->getDistance();
	// the AutoRange command will set the motors controlling the top and bottom
	// shooter axels to desired speed
	shooter->SetRange(distance);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRange::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoRange::End()
{
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRange::Interrupted()
{
	
}
