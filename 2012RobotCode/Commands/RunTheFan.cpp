#include "RunTheFan.h"
#include "../SubSystems/FanBase.h"

RunTheFan::RunTheFan()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(fan);
}

// Called just before this Command runs the first time
void RunTheFan::Initialize()
{
//	fan->RunFan();
}

// Called repeatedly when this Command is scheduled to run
void RunTheFan::Execute()
{
	fan->RunFan();
}

// Make this return true when this Command no longer needs to run execute()
bool RunTheFan::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RunTheFan::End()
{
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunTheFan::Interrupted()
{
	
}
